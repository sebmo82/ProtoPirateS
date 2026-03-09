#pragma once

#include <lib/subghz/protocols/base.h>
#include <lib/subghz/blocks/generic.h>

/**
 * Forward declaration pour le compilateur
 * Evite l'erreur 'unknown type name SubGhzReceiver'
 */
struct SubGhzReceiver;
typedef struct SubGhzReceiver SubGhzReceiver;

extern const SubGhzProtocol subghz_protocol_toyota_2008;

bool subghz_protocol_toyota_2008_decode(SubGhzBlockGeneric* instance, SubGhzReceiver* receiver);
