#include "lib.h"

void chamar_fila(Queue, Queue);
void mostrar_fila(Queue);

int main(int argc, char const *argv[])
{
    Queue fila;
    Queue prioridade;
    int leitura;
    int contador_fila = 1;

    init(&fila);
    init(&prioridade);

    do
    {
        printf("\n");
        printf("01 - PEGAR FICHA\n");
        printf("02 - PEGAR FICHA PRIORIDADE\n");
        printf("03 - CAIXA CHAMA CLIENTE\n");
        printf("04 - MOSTRA FILA PRIORIDADE\n");
        printf("05 - MOSTRA FILA COMUM\n");
        printf("0 - SAIR\n");
        
        printf("\n");
        scanf("%d", &leitura);
       

        switch (leitura)
        {
        case 1:

            printf("FICHA COMUM:\n");

            printf("FICHA[%d]\n", contador_fila);
            enqueue(fila, contador_fila);
            contador_fila++;

            break;
        case 2:
            printf("FICHA PRIORIDADE:\n");

            printf("FICHA[%d]\n", contador_fila);
            enqueue(prioridade, contador_fila);
            contador_fila++;
            break;
        case 3:
            int aux;
            printf("\n");
            printf("DIGITE O CAIXA\n");
            scanf("%d", &aux);
            printf("\n");

            switch (aux){
            case 1:
            case 2:
            case 3:
                if (!is_empty(prioridade))
                {
                    printf("OK");
                    printf("FICHA CHAMADA: %d PRIORIDADE\n", dequeue(prioridade));
                }
                else
                {
                    printf("FICHA CHAMADA:%d COMUM\n", dequeue(fila));
                }
                break;

            default:
                printf("FICHA CHAMADA:%d COMUM\n", dequeue(fila));
                break;
            }
            break;
        case 4:
            printf("FILA PRIORIDADE:\n");
            mostrar_fila(prioridade);
            break;
        case 5:
            printf("FILA COMUM:\n");
            mostrar_fila(fila);
            break;
        }

    } while (leitura != 0);

    return 0;
}

void mostrar_fila(Queue filas)
{
    Element aux;
    Queue teste;
    init(&teste);

    while (!is_empty(filas))
    {
        aux = dequeue(filas);
        printf("FILA: %d\n", aux);
        enqueue(teste, aux);
    }
    free(teste);
}