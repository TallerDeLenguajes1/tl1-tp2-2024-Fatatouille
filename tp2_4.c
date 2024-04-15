#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct compu{
    int velocidad;
    int anio;
    char *tipo_cpu;
    int nucleos;
} typedef PC;

void listar(PC *pici);
PC viejita(PC pc[5]);
PC mejorcita(PC pc[5]);

int main(){
    PC pichis[5], vieja, mejor, *pici=&pichis[0];

    listar(pici);
    vieja = viejita(pichis);
    mejor = mejorcita(pichis);
    
    printf("----------\n");

    printf("La PC mas vieja es de %d\n", vieja.anio);
    printf("La PC mas vieja tiene un procesador %s\n", vieja.tipo_cpu);
    printf("La PC mas vieja tiene %d nucleos\n", vieja.nucleos);

    printf("----------\n");

    printf("La PC mas rapida tiene %d GHz\n", mejor.velocidad);
    printf("La PC mas rapida es de %d\n", mejor.anio);
    printf("La PC mas rapida tiene %d\n", mejor.nucleos);
    
    for (int i = 0; i < 5; i++) {
        free(pichis[i].tipo_cpu);
    }

    return 0;
}

void listar(PC *pici){
    srand(time(NULL));
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int r;

    for (int i=0; i<5; i++){
        r= rand() % 5;

        pici->tipo_cpu = malloc(strlen(tipos[r]) + 1);

        printf("Anio de pc: ");
        scanf("%d", &(pici->anio));

        printf("Velocidad: ");
        scanf("%d", &(pici->velocidad));
        
        printf("Cantidad de nucleos: ");
        scanf("%d", &(pici->nucleos));

        strcpy((*pici).tipo_cpu, tipos[r]);

        pici++;
    }
}

PC viejita(PC pc[5]){
    PC menor;
    int m=2025;
    for (int i=0; i<5; i++){
        if (pc[i].anio<m){
            m=pc[i].anio;
            menor = pc[i];
        }
    }
    return menor;
}

PC mejorcita(PC pc[5]){
    PC mejor;
    int m=0;
    for (int i=0; i<5; i++){
        if (pc[i].velocidad>m){
            m=pc[i].velocidad;
            mejor = pc[i];
        }
    }
    return mejor;
}