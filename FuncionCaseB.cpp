#ifndef CASEB
#define CASEB

#include "Inicio_Estructura.h"

void disponibilidad(Excursion* datos) {
    printf("\n**************************************************\n");
    printf("           CONSULTA DE DISPONIBILIDAD:\n");
    printf("**************************************************\n");
    printf("\nIngrese la fecha a consultar (dd/mm): ");
    scanf("%6s", datos->fecha_actual);

    int dia, mes;
    if (sscanf(datos->fecha_actual, "%d/%d", &dia, &mes) != 2) {
        printf("[ERROR] Formato de fecha ingresada incorrecta. Debe ser dd/mm.\n");
        return;
    }

    FILE* archivo = fopen("excursiones1.txt", "r");
    if (archivo == NULL) {
        printf("[ERROR] No se pudo abrir el archivo excursiones1.txt\n");
        return;
    }

    Excursion reg;
    int disp;
    bool encontrada = false;

    printf("\n-.-.-.- DISPONIBILIDAD DE FECHAS DE LAS EXCURSIONES .-.-.-.-\n");

    // Lectura registro por registro de la estructura
    while (fscanf(archivo, "%6s %c %f %d %d", reg.fecha_actual, &reg.opcion_excursion, &reg.presupuesto, &reg.cant_personas, &disp) == 5) {
        reg.disponibilidad = (bool)disp;

        int dia_reg, mes_reg;
        if (sscanf(reg.fecha_actual, "%d/%d", &dia_reg, &mes_reg) == 2) {
            if (dia == dia_reg && mes == mes_reg) {
                encontrada = true;
                datos->disponibilidad = reg.disponibilidad;
                printf("Fecha [%s] - Excursión %c: %s\n",
                    reg.fecha_actual,
                    reg.opcion_excursion,
                    reg.disponibilidad ? "DISPONIBLE" : "NO DISPONIBLE");
            }
        }
    }

    if (!encontrada) {
        printf("No se encontraron registros para la fecha %s.\n", datos->fecha_actual);
    }

    fclose(archivo);
}

#endif
