#ifndef CASEC
#define CASEC
#include "Inicio_Estructura.h"

  void presupuestoSafari (Excursion datos){

printf("**************************************************\n");
printf("             ¿CUAL ES SU PRESUPUESTO?:\n");
printf("**************************************************\n");
printf("\nIngrese su presupuesto disponible en USD: ");
scanf("%f", &datos.presupuesto);

    printf("Ingrese la cantidad de personas que participan en la excursión: ");
    scanf("%d", &datos.cant_personas);

    printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("              RESUMEN DEL PRESUPUESTO:\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");

    printf("\nPresupuesto disponible: %.2f USD", datos.presupuesto);
    printf("\nCantidad de personas que participan: %d", datos.cant_personas);

    printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("          EXCURSIONES SEGÚN SU PRESUPUESTO:\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");;

    if ((datos.presupuesto* datos.cant_personas) >= TODO) {
        printf("\n- Safari de dia completo en vehiculo 4x4.\n");
        printf("\n- Inmersión a jaula con tiburines.\n");
        printf("\n- Avistamiento de ballenas en embarcación.\n");
    }

    else if ((datos.presupuesto* datos.cant_personas) >= MEDIO) {
        printf("\n- Inmersión en jaula con tiburones.\n");
        printf("\n- Avistamiento de ballenas en embarcación.\n");
    } 

     else if ((datos.presupuesto* datos.cant_personas) >= POCO) {
        printf("\n- Avistamiento de ballenas en embarcación.\n");
    }
	  else {
	  	 printf ("No puede realizar ninguna excursión.\n");
	  } }
#endif


