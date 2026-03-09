#include "protocoles/toyota_2008.h"
#include <lib/subghz/receiver.h>
#include <furi.h>

// Définition de l'objet protocole pour ProtoPirate
const SubGhzProtocol subghz_protocol_toyota_2008 = {
    .name = "Toyota 2008",
    .type = SubGhzProtocolTypeStatic,
    .flag = SubGhzProtocolFlag_433 | SubGhzProtocolFlag_AM | SubGhzProtocolFlag_Decodable,
};

/**
 * Décodeur Toyota 2008
 * Version compatible avec le compilateur strict (Werror)
 */
bool subghz_protocol_toyota_2008_decode(SubGhzBlockGeneric* instance, SubGhzReceiver* receiver) {
    // Utilisation de UNUSED pour éviter que le build s'arrête sur des warnings
    UNUSED(instance);
    UNUSED(receiver);

    // La logique de lecture PWM sera injectée ici une fois le build validé
    return false; 
}
