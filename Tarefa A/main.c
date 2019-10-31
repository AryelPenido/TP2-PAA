#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *arq = NULL;
    char arquivo[30];
    int aux[100];
    int pos = -1;
    //int linha = 0;
    int x;

    printf("\nentre com o nome do arquivo: ");
    scanf("%s",arquivo);
    arq = fopen(arquivo,"r");
    if(arq == NULL)
        printf("ERRO ao abrir o arquivo\n");
  
//lendo arquivo
    while(!feof(arq)){
        fscanf(arq,"%d",&x);
         pos++;
         printf("pos: %d\n",pos);
        aux[pos] = x;
    }

    int linha = 1;
   // printf(" pos apos o while: %d",pos);
// contando linhas do arquivo;
    while (pos > 0){
        pos = pos-linha;
        printf("\nprogresso do pos: %d\n", pos);
        linha++;
    }
    linha = linha -1;


   
    printf("linhas: %d\n",linha);
   

    fclose(arq);

    return 0;
}
