#include <stdio.h>
#include <stdlib.h>

// Paso 1: Definir la estructura para las actividades
typedef struct {
    int inicio;  // Hora de inicio de la actividad
    int fin;     // Hora de finalización de la actividad
} Actividad;

// Paso 2: Función para comparar actividades por su hora de finalización
int compararActividades(const void *a, const void *b) {
    Actividad *actividadA = (Actividad *)a;
    Actividad *actividadB = (Actividad *)b;
    return actividadA->fin - actividadB->fin;
}

// Paso 3: Función para seleccionar actividades no solapadas
void seleccionarActividades(Actividad actividades[], int numeroDeActividades) {
    // Ordenar actividades por hora de finalización
    qsort(actividades, numeroDeActividades, sizeof(Actividad), compararActividades);

    // Imprimir las actividades seleccionadas
    printf("Actividades seleccionadas:\n");

    // La primera actividad siempre se selecciona
    int ultimaHoraFin = -1;

    for (int i = 0; i < numeroDeActividades; i++) {
        if (actividades[i].inicio > ultimaHoraFin) {
            // La actividad no se solapa con la última actividad seleccionada
            printf("(%d, %d)\n", actividades[i].inicio, actividades[i].fin);
            ultimaHoraFin = actividades[i].fin; // Actualizar la última hora de finalización
        }
    }
}

int main() {
    // Paso 4: Definir la lista de actividades
    Actividad actividades[] = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7},
        {3, 8}, {5, 9}, {6, 10}, {8, 11},
        {8, 12}, {2, 13}, {12, 14}
    };

    int numeroDeActividades = sizeof(actividades) / sizeof(actividades[0]);

    // Paso 5: Llamar a la función para seleccionar actividades
    seleccionarActividades(actividades, numeroDeActividades);

    return 0;
}
