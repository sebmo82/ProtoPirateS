#include "protocol_items.h"
#include "toyota_2008.h" // Importation du nouveau header
#include <string.h>

const SubGhzProtocol* protopirate_protocol_registry_items[] = {
    &subghz_protocol_toyota_2008, // Ajout en haut de liste
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

static const ProtoPirateProtocolTiming protocol_timings[] = {
    // Ajout des timings pour l'analyseur Toyota
    {
        .name = "Toyota 2008",
        .te_short = 440,
        .te_long = 1200,
        .te_delta = 150,
        .min_count_bit = 64,
    },
    // ... garde tes autres timings ici sans rien supprimer
    {
        .name = "Kia V0",
        .te_short = 250,
        // ...
