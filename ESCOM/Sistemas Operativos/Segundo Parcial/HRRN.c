#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESOS 5


//Se crea una estructura de datos para poder analizar el ID del proceso y sus unidades de timepo
typedef struct {
    int procesoID;
    int tiempoLlegada;
    int tiempoServicio;
} Proceso;

void HRRN(Proceso procesos[], int n);

int main() {
    
    //Se declara un arreglo de 5 procesos
	Proceso procesos[MAX_PROCESOS];
    int i;

	//Se solicitan e introducen tanto los tiempos de llegada como de servicio
    // Inicializar procesos
    for (i = 0; i < MAX_PROCESOS; i++) {
        procesos[i].procesoID = i + 1;
        printf("Introduce el tiempo de llegada para el proceso %d: ", i + 1);
        scanf("%d", &procesos[i].tiempoLlegada);
        printf("Introduce el tiempo de servicio para el proceso %d: ", i + 1);
        scanf("%d", &procesos[i].tiempoServicio);
    }

    // Llamar al algoritmo HRRN
    HRRN(procesos, MAX_PROCESOS);

    return 0;
}

void HRRN(Proceso procesos[], int n) {
    int tiempoActual = 0;
    int completados = 0;

    printf("\n----- Ejecución utilizando el algoritmo HRRN -----\n");

    while (completados < n) {
        int nextProceso = -1;
        float highestRatio = -1.0;

        for (int i = 0; i < n; i++) {
            if (procesos[i].tiempoLlegada <= tiempoActual && procesos[i].tiempoServicio > 0) {
                float ratio = (tiempoActual - procesos[i].tiempoLlegada + procesos[i].tiempoServicio) / procesos[i].tiempoServicio;
                if (ratio > highestRatio) {
                    highestRatio = ratio;
                    nextProceso = i;
                }
            }
        }

        if (nextProceso == -1) {
            tiempoActual++;
        } else {
            printf("Ejecutando proceso %d\n", procesos[nextProceso].procesoID);
            procesos[nextProceso].tiempoServicio = 0;
            tiempoActual++;
            completados++;
        }
    }
}
