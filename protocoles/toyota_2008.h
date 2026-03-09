#pragma once

#include <lib/subghz/protocols/base.h>
#include <lib/subghz/blocks/generic.h>

// Déclaration globale du protocole pour protocol_items.c
extern const SubGhzProtocol subghz_protocol_toyota_2008;

// Prototypes requis par le SDK
bool subghz_protocol_toyota_2008_decode(SubGhzBlockGeneric* instance, SubGhzReceiver* receiver);
