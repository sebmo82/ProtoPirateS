#include "protocol_items.h"
#include "toyota_2008.h" // Inclusion directe maintenant
#include <string.h>

/* Note: Les autres protocoles (kia, ford, etc.) sont déjà déclarés 
   dans leurs headers respectifs inclus via protocol_items.h */

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
    {"Toyota 2008", 440, 1200, 150, 64},
    {"Kia V0", 250, 500, 100, 61},
    {"Kia V1", 800, 1600, 200, 56},
    {"Kia V2", 500, 1000, 150, 51},
    {"Kia V3/V4", 400, 800, 150, 64},
    {"Kia V5", 400, 800, 150, 64},
    {"Kia V6", 200, 400, 100, 144},
    {"Ford V0", 250, 500, 100, 64},
    {"Fiat V0", 200, 400, 100, 64},
    {"Subaru", 800, 1600, 200, 64},
    {"Suzuki", 250, 500, 100, 64},
    {"VW", 500, 1000, 120, 80},
    {"Scher-Khan", 750, 1100, 180, 35},
    {"Star Line", 250, 500, 120, 64},
    {"PSA", 250, 500, 100, 128},
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
