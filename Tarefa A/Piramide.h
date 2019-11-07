//
// Created by aryels on 06/11/2019.
//

#ifndef TAREFA_A_PIRAMIDE_H
#define TAREFA_A_PIRAMIDE_H


int Vrecursiva(int linhas,int i,int j,int matriz[][linhas]);
int Maximo(int m1,int m2);
int Vmemoization(int linhas,int i,int j,int matriz[][linhas],int tabela[][linhas]);
int Vbase(int linhas,int matriz[][linhas]);
void Caminho(int linhas, int matriz[][linhas], int tabela[][linhas], int i, int j);

#endif //TAREFA_A_PIRAMIDE_H
