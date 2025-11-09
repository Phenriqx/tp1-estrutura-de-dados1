#include <stdio.h>
#include<stdlib.h>
#include "formula.h"

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    Formula *formula = criaFormula(n, m);

    int *vet = malloc(n * sizeof(int));
    int *vetAdd = malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++){

        vet[i] = 1;

    }
    
    for (int i = 0; i < m; i++) {
        
        for(int j = 0; j < n; j++){

            scanf(" %d", &vetAdd[j]); 
        }

        adicionaClausula(formula, i, vetAdd);
        //limpaAdd(vetAdd, n);
        

    }

    //imprimirClausulas(formula);

    solucaoFormula(formula, 0, vet);

    imprimeFormula(formula);
    destroiFormula(formula);
    free(vet);
    free(vetAdd);
    return 0;
}