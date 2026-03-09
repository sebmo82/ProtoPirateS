#include "toyota_2008.h"
#include <lib/subghz/receiver.h>
#include <furi.h>

// Définition de l'objet protocole
const SubGhzProtocol subghz_protocol_toyota_2008 = {
    .name = "Toyota 2008",
    .type = SubGhzProtocolTypeStatic,
    .flag = SubGhzProtocolFlag_433 | SubGhzProtocolFlag_AM | SubGhzProtocolFlag_Decodable,
};

/**
 * Décodeur Toyota 2008 (PWM)
 */
bool subghz_protocol_toyota_2008_decode(SubGhzBlockGeneric* instance, SubGhzReceiver* receiver) {
    furi_assert(instance);
    furi_assert(receiver);

    // On utilise UNUSED pour éviter les erreurs de build si on ne s'en sert pas encore
    UNUSED(instance);
    UNUSED(receiver);

    // Si tu as besoin de lire les timings réels, on passe généralement par
    // l'instance du décodeur de niveau associée au receiver.
    // Pour l'instant, on retourne false pour valider que le code COMPILE.
    
    return false;
}
