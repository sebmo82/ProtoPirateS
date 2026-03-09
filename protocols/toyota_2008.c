#include "toyota_2008.h"
#include <lib/subghz/protocols/base.h>
#include <lib/subghz/blocks/const.h>
#include <lib/subghz/blocks/decoder.h>
#include <lib/subghz/blocks/encoder.h>

// 1. Déclarations des fonctions de base
void* subghz_protocol_decoder_toyota_2008_alloc(SubGhzEnvironment* environment) {
    UNUSED(environment);
    return malloc(sizeof(SubGhzProtocolDecoder));
}

void subghz_protocol_decoder_toyota_2008_free(void* context) {
    free(context);
}

void subghz_protocol_decoder_toyota_2008_reset(void* context) {
    UNUSED(context);
}

void subghz_protocol_decoder_toyota_2008_feed(void* context, bool level, uint32_t duration) {
    UNUSED(context);
    UNUSED(level);
    UNUSED(duration);
}

uint32_t subghz_protocol_decoder_toyota_2008_get_hash_data(void* context) {
    UNUSED(context);
    return 0;
}

// 2. La structure du Décodeur (Placée APRÈS les fonctions)
const SubGhzProtocolDecoder subghz_protocol_toyota_2008_decoder = {
    .alloc = subghz_protocol_decoder_toyota_2008_alloc,
    .free = subghz_protocol_decoder_toyota_2008_free,
    .feed = subghz_protocol_decoder_toyota_2008_feed,
    .reset = subghz_protocol_decoder_toyota_2008_reset,
    .get_hash_data = subghz_protocol_decoder_toyota_2008_get_hash_data,
    .serialize = NULL,
    .deserialize = NULL,
    .get_string = NULL,
};

// 3. La définition du Protocole
const SubGhzProtocol subghz_protocol_toyota_2008 = {
    .name = "Toyota 2008",
    .type = SubGhzProtocolTypeStatic,
    .flag = SubGhzProtocolFlag_None,
    .decoder = &subghz_protocol_toyota_2008_decoder,
    .encoder = NULL,
};
