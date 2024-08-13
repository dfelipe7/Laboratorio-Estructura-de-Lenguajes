#include <stdio.h>
#include <stdlib.h>

#define MAX_DESARROLLADORES 3

// Paso 1: Definir la estructura para las historias de usuario
typedef struct {
    int id;          // Identificador de la historia
    int tiempo;      // Tiempo estimado en horas
    int dependencia; // ID de la historia de la que depende (0 si no tiene dependencia)
    int prioridad;   // Prioridad (mayor valor, mayor prioridad)
} Historia;

// Paso 2: Función para comparar historias por prioridad (descendente)
int compararPorPrioridad(const void *a, const void *b) {
    Historia *historiaA = (Historia *)a;
    Historia *historiaB = (Historia *)b;
    return historiaB->prioridad - historiaA->prioridad;
}

// Paso 3: Función para asignar historias a desarrolladores
void asignarHistorias(Historia historias[], int numeroDeHistorias, int numDesarrolladores) {
    // Inicializar tiempos acumulados por desarrollador
    int tiempoDesarrollador[MAX_DESARROLLADORES] = {0};
    int asignaciones[MAX_DESARROLLADORES] = {0};

    // Ordenar historias por prioridad
    qsort(historias, numeroDeHistorias, sizeof(Historia), compararPorPrioridad);

    printf("Asignación de historias a desarrolladores:\n");

    for (int i = 0; i < numeroDeHistorias; i++) {
        int desarrolladorMinimo = 0;
        for (int j = 1; j < numDesarrolladores; j++) {
            if (tiempoDesarrollador[j] < tiempoDesarrollador[desarrolladorMinimo]) {
                desarrolladorMinimo = j;
            }
        }

        // Asignar historia al desarrollador con menor tiempo acumulado
        printf("Historia %d (Tiempo: %d, Prioridad: %d) asignada al Desarrollador %d\n",
            historias[i].id, historias[i].tiempo, historias[i].prioridad, desarrolladorMinimo + 1);

        tiempoDesarrollador[desarrolladorMinimo] += historias[i].tiempo;
        asignaciones[desarrolladorMinimo]++;
    }
}

int main() {
    // Paso 4: Definir la lista de historias de usuario
    Historia historias[] = {
        {1, 5, 0, 3},
        {2, 8, 1, 2},
        {3, 3, 0, 1},
        {4, 6, 2, 4},
        {5, 7, 3, 5}
    };

    int numeroDeHistorias = sizeof(historias) / sizeof(historias[0]);

    // Paso 5: Llamar a la función para asignar historias
    asignarHistorias(historias, numeroDeHistorias, MAX_DESARROLLADORES);

    return 0;
}
