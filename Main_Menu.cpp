#include "Inicio_Estructura.h"

int main() {
    Excursion datos = { "", 'A', 0.0f, 0, false };

    do {
        printf("\nMENU PRINCIPAL - EXCURSIONES EN SUDAFRICA.\n");
        printf("(A) Información de excursiones (Lectura de registros).\n");
        printf("(B) Disponibilidad de fechas.\n");
        printf("(C) Sacar presupuesto y registrar (Alta de registro).\n");
        printf("(D) Salir del menu.\n");

        printf("\nIngresar una opción: ");
        scanf(" %c", &datos.opcion_excursion);
        datos.opcion_excursion = (char)toupper((unsigned char)datos.opcion_excursion);

        switch (datos.opcion_excursion) {
        case 'A':
            mostrar_excursiones();
            break;
        case 'B':
            disponibilidad(&datos);
            break;
        case 'C':
            presupuestoSafari(&datos);
            break;
        case 'D':
            printf("Finalizando programa...\n");
            break;
        default:
            printf("Opción no válida.\n");
            break;
        }
    } while (datos.opcion_excursion != 'D');

    return 0;
}
