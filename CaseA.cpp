#ifndef CASEA
#define CASEA

#include "Inicio_Estructura.h"

void mostrar_excursiones(void) {
    FILE* archivo = fopen("excursiones1.txt", "r");

    if (archivo == NULL) {
        printf("[ERROR] No se pudo abrir el archivo excursiones1.txt\n");
        return;
    }

    Excursion reg;
    int disp;

    printf("\n--- REGISTROS DE EXCURSIONES ---\n");
    // Lectura registro por registro del archivo de datos
    while (fscanf(archivo, "%6s %c %f %d %d", reg.fecha_actual, &reg.opcion_excursion, &reg.presupuesto, &reg.cant_personas, &disp) == 5) {
        reg.disponibilidad = (bool)disp;
        printf("Fecha: %s | Excursión: %c | Presupuesto: $%.2f | Personas: %d | Disponible: %s\n",
            reg.fecha_actual,
            reg.opcion_excursion,
            reg.presupuesto,
            reg.cant_personas,
            reg.disponibilidad ? "SI" : "NO");
    }

    fclose(archivo);
}

#endif
