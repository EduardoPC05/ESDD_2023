#include <stdio.h>
#include <time.h>

#define TAM 1000000
#define COST (TAM / D)
#define D 9999
#define KEY 5148

struct Index
{
    int chave;
    int pos;
};
struct retorno
{
    int inicio;
    int fim;
};




void gera_banco(int vetor[]);
void gera_index(int vetor[],struct Index retorno[]);
int busca_sequencial(int file[],int init, int fim, int key);
struct retorno busca_index(struct Index table[],int key);

int main()
{
    int array[TAM];
    int r;
    struct Index retorno[COST+1];
    struct retorno range;

    gera_banco(array);
    gera_index(array, retorno);

    range = busca_index(retorno,KEY);
    
    r = busca_sequencial(array,range.inicio,range.fim,KEY);

    if (r != (-1))
    {
        printf("\n%d | %d\n",r,array[r]);
    }else{
        printf("\nCHAVE NAO EXISTE!\n");
    }
    
   
        
    return 0;
}
void gera_banco(int vetor[]){
    for (int i = 0; i < TAM; i++)
    {
       vetor[i] = (i+25*i);
    //    printf("%d\n",vetor[i]);
    }    
}
void gera_index(int vetor[],struct Index retorno[]){
    int j = 0;
    int i;
    
    for (i = 0; i < TAM; i += D)
    {
        retorno[j].chave = vetor[i];
        retorno[j].pos = i;
        printf("%d | %d\n",retorno[j].chave,retorno[j].pos);        
         j++;
    }  
    printf("\n");
    if (retorno[(j - 1)].pos != (TAM - 1))
    {
        i = (TAM - 1);
        retorno[j].chave = vetor[i];
        retorno[j].pos = i;
        printf("%d | %d\n",retorno[j].chave,retorno[j].pos); 
    }
    
      
    
}
int busca_sequencial(int file[],int init, int fim, int key){
   int founded = 0;
   int i;
    for(i = init; i <= fim && file[i] <= key && (!founded);i++){
        if(file[i] == key){
            founded = 1;
        }
    }
    return founded ? (i - 1 ):(-1);
}
struct retorno busca_index(struct Index table[],int key){
    int flag = 0;
    struct retorno resposta;
    for (int i = 0; (i < COST) && (!flag) ; i++)
    {
        if (key <= table[i].chave)
        {
            flag = 1;
            resposta.inicio = table[i - 1].pos;
            resposta.fim =  table[i].pos;
        }        
    }
    return resposta;    
}