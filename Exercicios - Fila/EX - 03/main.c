#include "lib.h"

int main()
{
    Queue fila;

    init(&fila);

    Element aux;

    while (!is_full(fila)){
        aux = malloc(sizeof(char[20]));

        fgets(aux, 20, stdin);

        enqueue(fila,aux);    
    }

    int contador = 1;
    Element aux_2;
    while (!is_empty(fila)){
       aux_2 = dequeue(fila);

       if (contador < 3){
         enqueue(fila,aux_2);
         printf("%s VOLTOU PARA A FILA\n",aux_2);
       }else{
            contador = 1;
            printf("%s SAIU DA FILA :X\n");
       }
       contador++;
    }
    
    printf("O SOBREVIVENTE FOI : %s\n",aux_2);
    

    return 0;
}
