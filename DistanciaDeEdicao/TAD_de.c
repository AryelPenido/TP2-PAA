#include "TAD_de.h"
#include <stdio.h>

int minimo(int a, int b, int c){
    //printf("\nA= %d\nB= %d\nC= %d",a,b,c);
    int Min = a;
    if (a>=b){
        if (b<c)
            Min = b;
        else
            Min = c;
    }
    else if (a>=c){
        Min = c;
    }
    printf("\nMin = %d",Min);
    return Min;
}

//int de(char p1[], char p2[], int i, int j){
//    printf("\np1[i] = %c\np2[j] = %c\n",p1[i],p2[j]);
//    int ret;
//    if (j==0)
//        return i;
//    if (i==0)
//        return j;
//
//    if (p1[i] == p2[j]){
//        printf("\nEntrou no if de");
//        ret = minimo(de(p1,p2,i-1,j-1), //Substituir
//                     de(p1,p2,i-1,j)+1, //Deletar
//                     de(p1,p2,i,j-1)+1);//Inserir
//
//    }
//    else{
//        printf("\nEntrou no else de");
//        ret = minimo(de(p1,p2,i-1,j-1)+1, //Substituir
//                     de(p1,p2,i-1,j)+1,   //Deletar
//                     de(p1,p2,i,j-1)+1);  //Inserir
//    }
//    return ret;
//}

void imprimeop (int t1, int t2, unsigned int mat[t1+1][t2+1]){
    for (int x = 0; x <= t1; x++){
        for (int y = 0; y <= t2; y++){
            printf("%d ",mat[x][y]);
        }
        printf("\n");
    }
    int i=t2;
    int j=t1;
    int cima, diag, lado, min;
    while (i!=0 || j!=0){
        if (i!=0 && j!=0){
            cima = mat[i-1][j];
            diag = mat[i-1][j-1];
            lado = mat[i][j-1];
            printf("\nmat[%d][%d]\n%d  %d\n%d  %d*",i,j,diag, cima, lado, mat[i][j]);
            min = minimo(cima, diag, lado);
            if (min == cima){
                    printf("\nApagou letra!");
                    i--;
            }
            else if(min == diag){
                    if (diag == mat[i][j]) printf("\nManteve letra!");
                    else printf("\nSubistituiu letra!");
                    i--;
                    j--;
            }
            else if (min == lado){
                    printf("\nInseriu letra!");
                    j--;
            }
        }
        else if (i==0){
            printf("\nmat[%d][%d]\n%d  %d*",i,j, lado, mat[i][j]);
            printf("\nInseriu letra!");
            j--;
        }
        else if (j==0){
            printf("\nmat[%d][%d]\n%d\n%d*",i,j, cima, mat[i][j]);
            printf("\nApagou letra!");
            i--;
        }

    }


}

int de(char *s1, char *s2) {
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    printf("\n");
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= s1len; x++){
        for (y = 1; y <= s2len; y++){
            matrix[x][y] = minimo(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));
            //printf("%d ",matrix[x][y]);
        }
    printf("\n");
    }
    imprimeop(s1len, s2len, matrix);
    return(matrix[s2len][s1len]);
}
