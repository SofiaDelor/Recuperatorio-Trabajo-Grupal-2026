
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
	char opcion_excursion; //Elige A B o C según la excursión que desea realizar.
	float presupuesto;  // Presupuesto del usuario para las excursiones.
	int cant_personas;  // Cantidad de personas para realizar un calculo de presupuesto.
	bool disponibilidad;  // Disponibilidad para las fechas, va de la mano de la fecha actual.
} Excursion;

void mostrar_excursiones (Excursion datos);
void disponibilidad (Excursion *datos);
void presupuestoSafari (Excursion datos);
#endif
