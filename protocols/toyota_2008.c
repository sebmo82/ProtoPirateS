#include "toyota_2008.h"
#include <lib/subghz/protocols/base.h>

// Ici, il ne doit y avoir QUE la logique Toyota
// Exemple :
const SubGhzProtocolDecoder subghz_protocol_toyota_2008_decoder = {
    .alloc = subghz_protocol_decoder_toyota_2008_alloc,
    .free = subghz_protocol_decoder_toyota_2008_free,
    // ... etc
};

const SubGhzProtocol subghz_protocol_toyota_2008 = {
    .name = "Toyota 2008",
    .type = SubGhzProtocolTypeStatic,
    .decoder = &subghz_protocol_toyota_2008_decoder,
    // ... etc
};

// --- ATTENTION ---
// SUPPRIME TOUT CE QUI SUIT S'IL EST PRÉSENT :
// Ne laisse PAS "const SubGhzProtocolRegistry protopirate_protocol_registry" ici.
// Ne laisse PAS "const ProtoPirateProtocolTiming* protopirate_get_protocol_timing" ici.
