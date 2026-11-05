#ifndef CASEC
#define CASEC

#include "Inicio_Estructura.h"

void presupuestoSafari(Excursion* datos) {
    printf("**************************************************\n");
    printf("             ¿CUAL ES SU PRESUPUESTO?:\n");
    printf("**************************************************\n");

    printf("\nIngrese la fecha (dd/mm): ");
    scanf("%6s", datos->fecha_actual);

    printf("Ingrese el tipo de excursión deseada (A, B o C): ");
    scanf(" %c", &datos->opcion_excursion);
    datos->opcion_excursion = (char)toupper((unsigned char)datos->opcion_excursion);

    printf("Ingrese su presupuesto disponible por persona en USD: ");
    scanf("%f", &datos->presupuesto);

    printf("Ingrese la cantidad de personas que participan: ");
    scanf("%d", &datos->cant_personas);

    float total = datos->presupuesto * datos->cant_personas;

    printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("              RESUMEN DEL PRESUPUESTO:\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("Presupuesto disponible: %.2f USD\n", datos->presupuesto);
    printf("Cantidad de personas: %d\n", datos->cant_personas);
    printf("Monto acumulado total: %.2f USD\n", total);

    printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("          EXCURSIONES SEGÚN SU PRESUPUESTO:\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

    if (total >= TODO) {
        printf("\n- Safari de día completo en vehículo 4x4.\n");
        printf("- Inmersión en jaula con tiburones.\n");
        printf("- Avistamiento de ballenas en embarcación.\n");
        datos->disponibilidad = true;
    }
    else if (total >= MEDIO) {
        printf("\n- Inmersión en jaula con tiburones.\n");
        printf("- Avistamiento de ballenas en embarcación.\n");
        datos->disponibilidad = true;
    }
    else if (total >= POCO) {
        printf("\n- Avistamiento de ballenas en embarcación.\n");
        datos->disponibilidad = true;
    }
    else {
        printf("No puede realizar ninguna excursión con ese presupuesto.\n");
        datos->disponibilidad = false;
    }

    // ALTA DE REGISTRO EN EL ARCHIVO
    FILE* archivo = fopen("excursiones1.txt", "a");
    if (archivo != NULL) {
        fprintf(archivo, "%s %c %.2f %d %d\n",
            datos->fecha_actual,
            datos->opcion_excursion,
            datos->presupuesto,
            datos->cant_personas,
            datos->disponibilidad ? 1 : 0);
        fclose(archivo);
        printf("\n[ALTA DE REGISTRO] Datos guardados exitosamente en 'excursiones1.txt'.\n");
    }
    else {
        printf("\n[ERROR] No se pudo escribir en el archivo de datos.\n");
    }
}

#endif

