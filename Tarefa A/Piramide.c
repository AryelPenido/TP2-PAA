#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Piramide.h"

int Vrecursiva(int linhas,int i,int j,int matriz[][linhas]){
    if(i == linhas-1){
        return(matriz[i][j]);
    }
    else{
        return matriz[i][j] + Maximo(Vrecursiva(linhas,i+1,j,matriz),Vrecursiva(linhas,i+1,j+1,matriz));
   }
}
   


int Vmemoization(int linhas,int i,int j,int matriz[][linhas],int tabela[][linhas]){
    int max;
   
     if(i == linhas-1){

        return(matriz[i][j]);
    }
    else{
       
        if(tabela[i][j] == -1){ 
             max = Maximo(Vmemoization(linhas,i+1,j,matriz,tabela),Vmemoization(linhas,i+1,j+1,matriz,tabela));
             tabela[i][j] =  matriz[i][j] + max;
        }
        return tabela[i][j];
        }
      

}

int  Vbase(int linhas,int matriz[][linhas]){
   int maximo;
  
    for(int i = linhas - 1; i >= 0; i--){
        for(int j = 0; j<=i;j++){
            //condição que garante que os limites da matriz serão respeitados
            if(i+1 > linhas-1 || j+1 > linhas -1){
                continue;
            }
            else
            { 
                maximo =  Maximo(matriz[i+1][j],matriz[i+1][j+1]);
                matriz[i][j] = matriz[i][j] + maximo;

            }
            
           
        }
       
    }
    return matriz[0][0];
}


int Maximo(int m1,int m2){
    if(m1> m2){
        return m1;
    }
    else{
        return m2;
    }
}


   
void Caminho(int linhas, int matriz[][linhas], int tabela[][linhas], int i, int j){
  
    printf("%d ",matriz[i][j]);
    if(i<linhas-1){
        if(tabela[i+1][j]>tabela[i+1][j+1]){
            Caminho(linhas,matriz, tabela, i+1, j);
        }
        // a ultima linha é sempre -1 para todos os elementos;
        else if(tabela[i+1][j] == tabela[i+1][j+1]){
            if(matriz[i+1][j] > matriz[i+1][j+1] ){
                Caminho(linhas,matriz, tabela, i+1, j);
            }
            else{
                  Caminho(linhas,matriz, tabela, i+1, j+1);
            }
        }
        else{
           Caminho(linhas,matriz, tabela, i+1, j+1);
        }
    }
    return;
}
