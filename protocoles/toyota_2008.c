#include "toyota_2008.h"
#include <lib/subghz/blocks/generic.h>

/**
 * Analyse des timings RAW pour Toyota 2008
 * Bit 0: ~440µs High, ~800µs Low
 * Bit 1: ~1200µs High, ~400µs Low
 */
bool subghz_protocol_toyota_2008_decode(SubGhzBlockGeneric* instance, SubGhzStream* stream) {
    uint8_t bit_count = 0;
    uint64_t data_high = 0; // 64 premiers bits
    uint16_t data_low = 0;  // 16 derniers bits

    size_t duration;
    bool level;

    // Reset du flux pour lecture
    subghz_stream_reset(stream);

    while(subghz_stream_get_next_level(stream, &level, &duration)) {
        if(!level) continue; // On cherche les fronts montants

        uint8_t bit = 0;
        if(duration > 300 && duration < 600) {
            bit = 0; // Timing court
        } else if(duration > 1100 && duration < 1600) {
            bit = 1; // Timing long
        } else {
            bit_count = 0; // Timing invalide, on reset
            continue;
        }

        // Remplissage du buffer de bits
        if(bit_count < 64) {
            data_high = (data_high << 1) | bit;
        } else if(bit_count < 80) {
            data_low = (data_low << 1) | bit;
        }
        
        bit_count++;

        if(bit_count == TOYOTA_2008_BIT_COUNT) {
            // Extraction des champs (Structure standard Toyota 2008)
            // Note: Les offsets peuvent varier de +/- 2 bits selon le préambule
            instance->serial = (uint32_t)(data_high >> 32); 
            instance->cnt = (uint32_t)(data_high & 0xFFFFFFFF); // Rolling
            instance->btn = (uint8_t)(data_low >> 8);
            
            return true; 
        }
    }
    return false;
}
