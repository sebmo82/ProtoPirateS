#ifndef TOYOTA_2008_H
#define TOYOTA_2008_H

#include <lib/subghz/protocols/base.h>
#include <lib/subghz/blocks/generic.h>
#include <lib/subghz/types.h>

struct SubGhzReceiver;
typedef struct SubGhzReceiver SubGhzReceiver;

extern const SubGhzProtocol subghz_protocol_toyota_2008;

bool subghz_protocol_toyota_2008_decode(SubGhzBlockGeneric* instance, SubGhzReceiver* receiver);

#endif
