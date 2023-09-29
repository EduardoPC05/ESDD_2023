#include "lib.h"

int main(int argc, char const *argv[])
{
    int aux = 0;
    Queue fila;
    Queue f_aux;

    init(&fila);
    init(&f_aux);

    printf("DIGITE OS NUMEROS\n");

    while (!is_full(fila)){
        scanf("%d",&aux); 
        enqueue(fila,aux);       
    }
    int teste;
    while (!is_empty(fila)){
        teste = dequeue(fila);
        if ((teste % 2 != 0) || (teste == 0)){
            enqueue(f_aux, teste);
        }else{
            printf("%d RETIRADO DA FILA\n",teste);
        }   
    }
    int y;
    while (!is_empty(f_aux)){
        y = dequeue(f_aux);
        enqueue(fila,y);      
        printf("FILA: %d\n",y);
    }
    
    


    return 0;
}
