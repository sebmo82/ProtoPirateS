#include "toyota_2008.h"
#include <lib/subghz/receiver.h>
#include <furi.h>

// Structure du protocole compatible ProtoPirate
const SubGhzProtocol subghz_protocol_toyota_2008 = {
    .name = "Toyota 2008",
    .type = SubGhzProtocolTypeStatic,
    .flag = SubGhzProtocolFlag_433 | SubGhzProtocolFlag_AM | SubGhzProtocolFlag_Decodable,
};

/**
 * Décodeur Toyota 2008 (PWM)
 * Signature conforme au SDK 1.4.3 (ufbt)
 */
bool subghz_protocol_toyota_2008_decode(SubGhzBlockGeneric* instance, SubGhzReceiver* receiver) {
    furi_assert(instance);
    furi_assert(receiver);

    // On récupère les timings du dernier bit reçu
    size_t duration = subghz_receiver_get_last_bit_duration(receiver);
    bool level = subghz_receiver_get_last_bit_level(receiver);

    // Logique de capture Toyota (PWM : impulsion haute variable)
    if(level) {
        if(duration > 300 && duration < 600) {
            // Bit 0 détecté (~440us)
            return true; 
        } else if(duration > 1100 && duration < 1600) {
            // Bit 1 détecté (~1200us)
            return true;
        }
    }

    return false;
}
