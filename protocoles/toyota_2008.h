#pragma once

#include <lib/subghz/protocols/base.h>

#define TOYOTA_2008_TE 440 // Durée de base en microsecondes
#define TOYOTA_2008_BIT_COUNT 80 // Nombre de bits total observé

typedef struct {
    uint32_t serial;    // ID fixe de la clé
    uint32_t rolling;   // Code tournant (chiffré)
    uint8_t btn;        // Code du bouton
} Toyota2008Data;
