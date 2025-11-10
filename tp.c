#include <stdio.h>
#include <stdlib.h>
#include "formula.h"

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    limpar_buffer();
    Formula *formula = criaFormula(n, m);

    int *vet = malloc(n * sizeof(int));
    int *vetAux = malloc(n * sizeof(int));


    for(int i = 0; i < n; i++){
        vet[i] = 1;
        vetAux[i] = i + 1;
    }

    adicionaClausula(formula);
    //limpaAdd(vetAdd, n);        

    //imprimirClausulas(formula);

    solucaoFormula(formula, 0, vet, vetAux);

    imprimeFormula(formula);
    destroiFormula(formula);
    free(vet);
    free(vetAux);
    return 0;
}