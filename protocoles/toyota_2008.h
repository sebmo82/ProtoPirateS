#pragma once

#include <lib/subghz/protocols/base.h>
#include <lib/subghz/blocks/generic.h>

// Déclaration anticipée pour le compilateur
typedef struct SubGhzReceiver SubGhzReceiver;

extern const SubGhzProtocol subghz_protocol_toyota_2008;

bool subghz_protocol_toyota_2008_decode(SubGhzBlockGeneric* instance, SubGhzReceiver* receiver);
