#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TAD_de.h"
#include <time.h>
#define debug 1
int main(){
    clock_t tempo;
	tempo = clock();
    char p1[46], p2[46];
    printf("\nEntre com a palvra atual: ");
    scanf("%s",p1);
    //printf("%s E %d",p1, strlen(p1));
    printf("\nEntre com a palvra pretendida: ");
    scanf("%s",p2);
    //printf("%s E %d",p2, strlen(p2));
    int DE = de(p1,p2);
    printf("\nDE = %d",DE);
    if (debug) printf("\nTempo de execucao:%f segundos",(clock() - tempo) / ((double)CLOCKS_PER_SEC/1000));
    return 0;
}
