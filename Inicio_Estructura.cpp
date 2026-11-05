#ifndef INICIO_ESTRUCTURA_H
#define INICIO_ESTRUCTURA_H

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define FECHA 7
#define TODO 198
#define MEDIO 150
#define POCO 85

typedef struct {
    char fecha_actual[FECHA];
    char opcion_excursion; // Elige A, B o C
    float presupuesto;     // Presupuesto unitario del usuario
    int cant_personas;     // Cantidad de personas
    bool disponibilidad;   // Disponibilidad (true/false)
} Excursion;

void mostrar_excursiones(void);
void disponibilidad(Excursion* datos);
void presupuestoSafari(Excursion* datos);

#endif
