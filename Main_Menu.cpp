#include "Inicio_Estructura.h"

int main() {


	Excursion datos;
	do {
		printf("\nMENU PRINCIPAL - EXCURSIONES EN SUDAFRICA.\n");
		printf("(A) Información de excursiones.\n");
		printf("(B) Disponibilidad de fechas.\n");
		printf("(C) Sacar presupuesto.\n");
		printf("(D) Salir del menu.\n");

		printf("\nIngresar una opción:");
		scanf(" %c", &datos.opcion_excursion);
		datos.opcion_excursion = toupper(datos.opcion_excursion);

		switch (datos.opcion_excursion) {

		case 'A': 
			mostrar_excursiones(datos);
			break;
		case 'B': 
			 disponibilidad (&datos);
			break;
		case 'C':
			presupuestoSafari (datos);
			break;
		case 'D': 
			 printf ("Finalizando programa...\n");
			break;

		}
	} while (datos.opcion_excursion != 'D');

	return 0;
}
