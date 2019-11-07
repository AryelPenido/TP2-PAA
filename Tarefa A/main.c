#include<stdio.h>
#include<stdlib.h>
#include"Piramide.h"
#include<time.h>
#define DEBUG 1
int main(int argc, char const *argv[])
{
    //system("valgrind");
    FILE *arq = NULL;
    char arquivo[30];
    int aux[5024];
    int pos = -1;
    int cont = 0;
    int n,x,y,op,resp,op1;
    clock_t t;
    printf("1. entrar com arquivo 2. gerar arquivo: ");
    scanf("%d", &op1);
    //gerando arquivo aleatorio
    if (op1 == 2){
        FILE *aletorio;
        srand(time(NULL));
        aletorio = fopen("arqAleatorio.txt","w");
        printf("Entre com a quantidade de linhas desejadas: ");
        scanf("%d",&y);
        for(int i=0;i<y;i++){
            for(int j=0;j<i;j++){
                if(i == y-1 && j == y-1){
                    fprintf(aletorio,"%d",rand()%10);
                }
                else{
                     fprintf(aletorio,"%d ",rand()%10);
                }
               
            }
                fprintf(aletorio,"\n");
        }
            printf("Arquivo gerado com sucesso!\n");
        fclose(aletorio);
    }

    printf("entre com o nome do arquivo: ");
    scanf("%s",arquivo);
    arq = fopen(arquivo,"r");
    if(arq == NULL)
        printf("ERRO ao abrir o arquivo\n");
  
//lendo arquivo
    while(!feof(arq)){
        fscanf(arq,"%d",&x);
         pos++;
        aux[pos] = x;
    }
    n = pos;
    int linha = 1;
// contando linhas do arquivo;
    while (pos > 0){
        pos = pos-linha;
        linha++;
    }
      fclose(arq);

    linha = linha -1;
    int matriz[linha][linha];
    int tabela[linha][linha];
    


 //preenchendo a matriz;
 printf("Preenchando matriz\n");
      for(int i = 0; i< linha; i++){
        for (int j = 0; j<linha;j++){
           //quebrar o nivel 
            if(j > i){
               matriz[i][j] = -1;
            }
            else{
                matriz[i][j] = aux[cont];
                cont++;
            }
            tabela[i][j] = -1;
        }
    }

    //copia da matriz original;
    int matrizaux[linha][linha];
    for(int i = 0; i <linha; i++){
        for(int j = 0; j <linha; j++){
            matrizaux[i][j] = matriz[i][j];
        }
    }

    printf("\nEscolha o algoritmo a ser utilizado\n");
    printf("\n 1.Recursivo 2.Memoization 3.de tras pra frente: ");
    scanf("%d",&op );
    switch (op)
    {
    case 1:
        printf("\n###########################\n");
        t = clock();
        resp = Vrecursiva(linha,0,0,matriz);
        t = clock() - t;
        if(DEBUG == 1){
            printf("Tempo de execução: %lf\n",((double )t)/((CLOCKS_PER_SEC/1000)));
            printf("Maior soma:%d\n",resp);
            printf("Caminho: ");
            Caminho(linha,matrizaux,matriz,0,0);
            printf("\n###########################\n");
        }
        else{
            printf("Maior soma:%d\n",resp);
            printf("Caminho: ");
            Caminho(linha,matrizaux,matriz,0,0);
            printf("\n###########################\n");
        }
        break;
    case 2:
        printf("\n###########################\n");
        t = clock();
        resp = Vmemoization(linha,0,0,matriz,tabela);
        t = clock() -t;
        if(DEBUG == 1){
            printf("Tempo de execução: %lf\n",((double )t)/((CLOCKS_PER_SEC/1000)));
            printf("Maior soma:%d\n",resp);
            printf("Caminho: ");
            Caminho(linha,matriz,tabela,0,0);
        }
        else{
            printf("Maior soma:%d\n",resp);
            printf("Caminho: ");
            Caminho(linha,matriz,tabela,0,0);
        }
        printf("\n###########################\n");
        break;
    case 3:
        
        printf("\n###########################\n");
        t = clock();
        resp = Vbase(linha,matriz);
        t = clock() - t;
        if(DEBUG == 1){
            printf("Tempo de execução: %lf\n",((double )t)/((CLOCKS_PER_SEC/1000)));
            printf("Maior soma:%d\n",resp);
            printf("Caminho: ");
            Caminho(linha,matrizaux,matriz,0,0);
        }
        else{
            printf("\nMaior soma:%d\n",resp);
            printf("Caminho: ");
            Caminho(linha,matrizaux,matriz,0,0);
        }
        printf("\n###########################\n");
        break;

    default:
        break;
    }
    return 0;
}
