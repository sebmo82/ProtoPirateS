#include "protocol_items.h"
#include "protocoles/toyota_2008.h" // Chemin complet vers le sous-dossier
#include <string.h>

const SubGhzProtocol* protopirate_protocol_registry_items[] = {
    &subghz_protocol_toyota_2008, // Enregistrement du nouveau décodeur
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

// ... garde le reste du fichier (protocol_timings, etc.) identique
