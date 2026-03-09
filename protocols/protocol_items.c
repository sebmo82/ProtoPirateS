#include "protocol_items.h"
#include "protocoles/toyota_2008.h" // Inclusion de ton nouveau header
#include <string.h>

/* * Déclaration des protocoles externes 
 * Assure-toi que ces noms correspondent exactement aux "const SubGhzProtocol" 
 * définis dans chaque fichier .c respectif.
 */
extern const SubGhzProtocol subghz_protocol_scher_khan;
extern const SubGhzProtocol kia_protocol_v0;
extern const SubGhzProtocol kia_protocol_v1;
extern const SubGhzProtocol kia_protocol_v2;
extern const SubGhzProtocol kia_protocol_v3_v4;
extern const SubGhzProtocol kia_protocol_v5;
extern const SubGhzProtocol kia_protocol_v6;
extern const SubGhzProtocol ford_protocol_v0;
extern const SubGhzProtocol fiat_protocol_v0;
extern const SubGhzProtocol subaru_protocol;
extern const SubGhzProtocol suzuki_protocol;
extern const SubGhzProtocol vag_protocol;
extern const SubGhzProtocol subghz_protocol_star_line;
extern const SubGhzProtocol psa_protocol;

// Ton nouveau protocole Toyota
extern const SubGhzProtocol subghz_protocol_toyota_2008;

const SubGhzProtocol* protopirate_protocol_registry_items[] = {
    &subghz_protocol_toyota_2008, // Ajouté ici
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

// --- TIMINGS ---
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
        .te_short =
