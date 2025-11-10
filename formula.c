#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "formula.h"

char intToChar(int v);

struct clausula {
    int val[3];
    int valorLogico[3]; // 
};  

struct formula {
    Clausula* clausulas;
    int n, m;
};  

Formula* criaFormula(int n, int m) {
    Formula* formula = (Formula*) malloc(sizeof(Formula));
    if (!formula) {
        printf("Erro de alocação\n");
        return NULL;
    }

    formula->clausulas = malloc(m * sizeof(Clausula));
    if (!formula->clausulas) 
        return NULL;

    formula->n = n;
    formula->m = m;

    return formula;
}

void destroiFormula(Formula* f) {
    if (f->clausulas) {
        free(f->clausulas);
        f->clausulas = NULL;
    }

    free (f);
    f = NULL;
}

void adicionaClausula(Formula *f) {
    for (int i = 0; i < f->m; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &f->clausulas[i].val[j]);
        }
    }
}

void imprimeFormula(Formula *f) {
    for (int i = 0; i < f->m; i++) {
        printf("( ");
        for (int j = 0; j < 3; j++) {
            if (f->clausulas[i].val[j] > 0)
                printf("%c ", intToChar(f->clausulas[i].val[j]));
            else 
                printf("~%c ", intToChar(f->clausulas[i].val[j] * -1));
            if (j < f->n - 1)
                printf(" V ");
        }
        printf(" )");
        if (i < f->m - 1)
            printf(" ∧ ");
    }

    printf("\n");
}

// CERTO ATE AQUI

int solucaoFormula(Formula *f, int n, int *vet, int *vetAux){

    for(int i = 0; i < pow(2, f->n); i++){
        int saida = verificaCada(f, n, vet, vetAux);

        if(saida == 1){
            printf("\nDeu certo ");

            for(int i = 0; i < f->n; i++){
                printf("%d", vet[i]);

            }
            return 1;
            i = 8;

        }else{

            proxVeri(f, vet);

        }


    }
     
    return 0;


}

int verificaCada(Formula *f, int n, int *vet, int *vetAux){
    if((f->m -1) == n){

        return verificaClausula(f, vet, n, vetAux);


    }

    int saida = verificaCada(f, n +1, vet, vetAux);

    if(saida == 0){
        return 0;
    }else{
        return verificaClausula(f, vet, n, vetAux);
    }


}

int verificaClausula(Formula *f, int *vet, int n, int *vetAux) {
    
    int *vetClone = malloc(3 * sizeof(int));

    // 111, 110

    for(int i = 0; i < 3; i++){


        for(int j = 0; j < f->n; j++){
//Alterar, talvez fazer um outro for dentro
            if(vetAux[j] == f->clausulas[n].val[i]){
                vetClone[j] = vet[j];

            }

        }


        if(f->clausulas[n].valorLogico[i] == 0){
            vetClone[i] = !vetClone[i];
        }


    }
    int result = vetClone[0] | vetClone[1] | vetClone[2];

    free(vetClone);

    return result;

}

//  111
//  110

void proxVeri(Formula *f, int *vet){

        for(int j = (f->n -1); j >=0; j--){

            vet[j] = !vet[j];

            if(vet[j] == 0){
                break;
            }


        }
}


void limpaAdd(int *vet, int n){

    for(int i = 0; i < n; i++){
        vet[i] = 0;
    }

}

void imprimirClausulas(Formula *formula){


    for(int i = 0; i < formula->m; i++){

        for(int j = 0; j < formula->n; j++){

            printf("Clausula %d %d %d\n", i, formula->clausulas[i].val[j], formula->clausulas[i].valorLogico[j]);

        }


    }
}

char intToChar(int v) {
    return v + 'a' - 1;
}     

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}