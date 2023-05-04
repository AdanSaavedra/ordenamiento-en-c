//
//  main.c
//  Lab5
//
//  Created by Adan Saavedra on 11/21/22.
//

#include <stdio.h>

void qs(int lista[],int limite_izq,int limite_der){
    int izq,der,temporal,pivote, cant;
 
    cant= limite_der+1;
    izq=limite_izq;
    der = limite_der;
    pivote = lista[(izq+der)/2];

    do{
        
        while(lista[izq]<pivote && izq<limite_der)izq++;
        while(pivote<lista[der] && der > limite_izq)der--;
        printf("\nlimite izq: %d\n", lista[izq]);
        printf("limite der: %d\n", lista[der]);
        printf("pivote: %d\n",pivote);
        printf("De esta ordenacion: ");
        for (int i=0; i<cant; i++) {
            printf("%d",lista[i]);
            if(i<cant-1)
                printf(",");
        }
        printf("\n");
        if(izq <=der){
            temporal= lista[izq];
            lista[izq]=lista[der];
            lista[der]=temporal;
            izq++;
            der--;
            printf("Pasa a esta ordenacion: ");
            for (int i=0; i<cant; i++) {
                printf("%d",lista[i]);
                if(i<cant-1)
                    printf(",");
            }
            printf("\n");
        }
    }while(izq<=der);

    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}
}

void quicksort(int lista[],int n){
    qs(lista,0,n-1);
}

int main(int argc, const char * argv[]) {
    
    int cant;
    printf("Ingrese la cantidad de numeros a ordernar: ");
    scanf("%d",&cant);
    int lista[cant];

    printf("\nIngrese los numeros\n");
    for(int j=0;j<cant;j++){
        printf("Numero %d: ",j+1);
        scanf("%d",&lista[j]);
        //printf("\n");
    }
    
    printf("\nLista Desordenada \n");

    for (int i=0; i<cant; i++) {
            printf("%d",lista[i]);
            if(i<cant-1)
                printf(",");
        }
     
        printf("\n");
    printf("\nProceso de arreglo:");
        quicksort(lista,cant);
    
        printf("\n\nLista Ordenada \n");
        for (int i=0; i<cant; i++) {
            printf("%d",lista[i]);
            if(i<cant-1)
                printf(",");
        }
    printf("\n");

    return 0;
}
