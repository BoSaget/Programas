#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fecha[20];
    char hora[20];
    char tarea[100];
} RegistroAgenda;

int main() {
    int opcion, numRegistros = 0, i;
    RegistroAgenda *agenda = NULL;
    FILE *archivo;

    do {
        printf("\n\tAGENDA\n");
        printf("1. Agregar registro\n");
        printf("2. Mostrar registros\n");
        printf("3. Guardar registros en archivo\n");
        printf("4. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                numRegistros++;
                agenda = (RegistroAgenda*) realloc(agenda, numRegistros * sizeof(RegistroAgenda));

                printf("Fecha (dd/mm/aaaa): ");
                scanf("%s", agenda[numRegistros-1].fecha);
                printf("Hora (hh:mm): ");
                scanf("%s", agenda[numRegistros-1].hora);
                printf("Tarea: ");
                scanf(" %[^\n]s", agenda[numRegistros-1].tarea);

                printf("Registro agregado correctamente.\n");
                break;
            case 2:
                if(numRegistros == 0) {
                    printf("No hay registros en la agenda.\n");
                } else {
                    printf("\nRegistros en la agenda:\n");
                    for(i = 0; i < numRegistros; i++) {
                        printf("%d. %s - %s - %s\n", i+1, agenda[i].fecha, agenda[i].hora, agenda[i].tarea);
                    }
                }
                break;
            case 3:
                if(numRegistros == 0) {
                    printf("No hay registros en la agenda.\n");
                } else {
                    archivo = fopen("agenda.csv", "w");
                    if(archivo == NULL) {
                        printf("Error al abrir el archivo.\n");
                    } else {
                        for(i = 0; i < numRegistros; i++) {
                            fprintf(archivo, "%s,%s,%s\n", agenda[i].fecha, agenda[i].hora, agenda[i].tarea);
                        }
                        printf("Registros guardados correctamente en el archivo.\n");
                        fclose(archivo);
                    }
                }
                break;
            case 4:
                printf("Saliendo de la agenda.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while(opcion != 4);

    free(agenda);
    return 0;
}

