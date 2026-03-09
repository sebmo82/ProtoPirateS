#include "protocol_items.h"
#include "protocoles/toyota_2008.h"
#include <string.h>

/* * NOTE: Les "extern const SubGhzProtocol" ont été supprimés d'ici 
 * car ils sont déjà inclus via "protocol_items.h" et "toyota_2008.h".
 */

const SubGhzProtocol* protopirate_protocol_registry_items[] = {
    &subghz_protocol_toyota_2008,
    &subghz_protocol_scher_khan,
    &kia_protocol_v0,
    &kia_protocol_v1,
    &kia_protocol_v2,
    &kia_protocol_v3_v4,
    &kia_protocol_v5,
    &kia_protocol_v6,
    &ford_protocol_v0,
    &fiat_protocol_v0,
    &subaru_protocol,
    &suzuki_protocol,
    &vag_protocol,
    &subghz_protocol_star_line,
    &psa_protocol,
};

const SubGhzProtocolRegistry protopirate_protocol_registry = {
    .items = protopirate_protocol_registry_items,
    .size = COUNT_OF(protopirate_protocol_registry_items),
};

static const ProtoPirateProtocolTiming protocol_timings[] = {
    {
        .name = "Toyota 2008",
        .te_short = 440,
        .te_long = 1200,
        .te_delta = 150,
        .min_count_bit = 64,
    },
    {
        .name = "Kia V0",
        .te_short = 250,
        .te_long = 500,
        .te_delta = 100,
        .min_count_bit = 61,
    },
    {
        .name = "Kia V1",
        .te_short = 800,
        .te_long = 1600,
        .te_delta = 200,
        .min_count_bit = 56,
    },
    {
        .name = "Kia V2",
        .te_short = 500,
        .te_long = 1000,
        .te_delta = 150,
        .min_count_bit = 51,
    },
    {
        .name = "Kia V3/V4",
        .te_short = 400,
        .te_long = 800,
        .te_delta = 150,
        .min_count_bit = 64,
    },
    {
        .name = "Kia V5",
        .te_short = 400,
        .te_long = 800,
        .te_delta = 150,
        .min_count_bit = 64,
    },
    {
        .name = "Kia V6",
        .te_short = 200,
        .te_long = 400,
        .te_delta = 100,
        .min_count_bit = 144,
    },
    {
        .name = "Ford V0",
        .te_short = 250,
        .te_long = 500,
        .te_delta = 100,
        .min_count_bit = 64,
    },
    {
        .name = "Fiat V0",
        .te_short = 200,
        .te_long = 400,
        .te_delta = 100,
        .min_count_bit = 64,
    },
    {
        .name = "Subaru",
        .te_short = 800,
        .te_long = 1600,
        .te_delta = 200,
        .min_count_bit = 64,
    },
    {
        .name = "Suzuki",
        .te_short = 250,
        .te_long = 500,
        .te_delta = 100,
        .min_count_bit = 64,
    },
    {
        .name = "VW",
        .te_short = 500,
        .te_long = 1000,
        .te_delta = 120,
        .min_count_bit = 80,
    },
    {
        .name = "Scher-Khan",
        .te_short = 750,
        .te_long = 1100,
        .te_delta = 180,
        .min_count_bit = 35,
    },
    {
        .name = "Star Line",
        .te_short = 250,
        .te_long = 500,
        .te_delta = 120,
        .min_count_bit = 64,
    },
    {
        .name = "PSA",
        .te_short = 250,
        .te_long = 500,
        .te_delta = 100,
        .min_count_bit = 128,
    },
};

static const size_t protocol_timings_count = COUNT_OF(protocol_timings);

const ProtoPirateProtocolTiming* protopirate_get_protocol_timing(const char* protocol_name) {
    if(!protocol_name) return NULL;

    for(size_t i = 0; i < protocol_timings_count; i++) {
        if(strcmp(protocol_name, protocol_timings[i].name) == 0 ||
           strstr(protocol_name, protocol_timings[i].name) != NULL) {
            return &protocol_timings[i];
        }
    }
    return NULL;
}

const ProtoPirateProtocolTiming* protopirate_get_protocol_timing_by_index(size_t index) {
    if(index >= protocol_timings_count) return NULL;
    return &protocol_timings[index];
}

size_t protopirate_get_protocol_timing_count(void) {
    return protocol_timings_count;
}
