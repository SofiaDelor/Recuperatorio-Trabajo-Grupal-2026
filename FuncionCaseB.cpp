#ifndef CASEB
#define CASEB
#include "Inicio_Estructura.h"

void disponibilidad(Excursion *datos) {
  
	printf("\n");
    printf("**************************************************\n");
    printf("           CONSULTA DE DISPONIBILIDAD:\n");
    printf("**************************************************\n");
    printf("\nIngrese la fecha actual (dd/mm): ");
	scanf("%s", datos->fecha_actual);

	int dia, mes;
	if (sscanf(datos->fecha_actual, "%d/%d", &dia, &mes) != 2) {
		printf("[ERROR] Formato de fecha ingresada incorrecta. Debe ser dd/mm.\n");
		return;
	}

	FILE* archivo = fopen("excursiones1.txt", "r"); 
	FILE* archivo_disponible = fopen("fechas_disponibles.txt", "w"); 
	FILE* archivo_no_disponible = fopen("fechas_no_disponibles.txt", "w");

	if (archivo == NULL || archivo_disponible == NULL || archivo_no_disponible == NULL) { 
		printf("[ERROR] No se pudo abrir uno o varios archivos.\n");
		if (archivo) fclose(archivo);
		if (archivo_disponible) fclose(archivo_disponible);
		if (archivo_no_disponible) fclose(archivo_no_disponible);

		return;

	}

	int dia_archivo, mes_archivo; 
	char dm;  

		printf("-.-.-.- DISPONIBILIDAD DE FECHAS DE LAS EXCURSIONES: .-.-.-");

		while ((dm = fgetc(archivo)) != EOF) { 
			if (dm == '-') { 
				if (fscanf(archivo, "%d/%d", &dia_archivo, &mes_archivo) == 2) {
					printf("Fecha [%02d/%02d]\n ", dia_archivo, mes_archivo);

					if (mes < mes_archivo || (mes == mes_archivo && dia < dia_archivo)) { 
						printf("Disponible en esa fecha.\n");
						fprintf(archivo_disponible, "%02d/%02d\n", dia_archivo, mes_archivo);
						datos->disponibilidad = true;
					}
					else if (mes > mes_archivo || (mes == mes_archivo && dia > dia_archivo)) { 
						printf("NO Disponible en esa fecha, lo sentimos"\n");
						fprintf(archivo_no_disponible, "%02d/%02d\n", dia_archivo, mes_archivo);
						datos->disponibilidad = false; 
					}
					else {
						printf("Es hoy. ¡Reserve los últimos cupos para una experiencia inolvidable!\n");
						fprintf(archivo_disponible, "- %02d/%02d (HOY)\n", dia_archivo, mes_archivo);
						datos->disponibilidad = true; 
					}
				}
			}
		}

		fclose(archivo);
		fclose(archivo_disponible);
		fclose(archivo_no_disponible);
	}
#endif
