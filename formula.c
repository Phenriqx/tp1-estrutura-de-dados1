#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "formula.h"

char intToChar(int v);

struct clausula {
    int *val;
    int *valorLogico; // 
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

    for(int i = 0; i < m; i++){

        formula->clausulas[i].val = calloc((size_t)n, sizeof *formula->clausulas[i].val);
        formula->clausulas[i].valorLogico = calloc((size_t)n, sizeof *formula->clausulas[i].valorLogico);
        //formula->clausulas[i].val = malloc(n * sizeof(int));
        //formula->clausulas[i].valorLogico = malloc(n * sizeof(int));

    }

    /*for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            printf("Clausula %d, %d %d\n", i, formula->clausulas[j].val[n], formula->clausulas[j].valorLogico[n]);

        }


    }*/




    return formula;
}

void destroiFormula(Formula* f) {
    
    for(int i = 0; i < f->m; i++){
        if (f->clausulas[i].val) {
            free(f->clausulas[i].val);
            f->clausulas[i].val = NULL;
        }
        if (f->clausulas[i].valorLogico) {
            free(f->clausulas[i].valorLogico);
            f->clausulas[i].valorLogico = NULL;
        }


    }


    if (f->clausulas) {
        free(f->clausulas);
        f->clausulas = NULL;
    }

    free (f);
    f = NULL;
}

void adicionaClausula(Formula *f, int r, int *vetAdd) {
    if (!f)
        return;

    // n variaveis  (n v n+1 v n+2 ... v nx)
    for(int j = 0; j < f->n; j++){

        f->clausulas[r].val[j] = vetAdd[j];
    

    }

    for(int i = 0; i < f->n; i++){


        //printf("%d", f->clausulas[r].val[i]);
        if(f->clausulas[r].val[i] < 0){

            f->clausulas[r].valorLogico[i] = 0;


        }else{
                
            f->clausulas[r].valorLogico[i] = 1; 


        }

        //printf("%d", f->clausulas[r].valorLogico[i]);

    }

    
}

void imprimeFormula(Formula *f) {
    for (int i = 0; i < f->m; i++) {
        printf("( ");
        for (int j = 0; j < f->n; j++) {
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

char intToChar(int v) {
    return v + 'a' - 1;
}
// (a v ~b v ~c ) ^ (a v b v c)


//    -1 2 3
//     1 1 1       

int solucaoFormula(Formula *f, int n, int *vet){

    for(int i = 0; i < pow(2, f->n); i++){
        int saida = verificaCada(f, n, vet);

        if(saida == 1){
            printf("\nDeu certo %d %d %d\n", vet[0], vet[1], vet[2]);
            return 1;
            i = 8;

        }else{

            proxVeri(f, vet);

        }


    }
    
    return 0;


}

int verificaCada(Formula *f, int n, int *vet){
    if((f->m -1) == n){

        return verificaClausula(f, vet, n);


    }

    int saida = verificaCada(f, n +1, vet);

    if(saida == 0){
        return 0;
    }else{
        return verificaClausula(f, vet, n);
    }


}

int verificaClausula(Formula *f, int *vet, int n) {
    
    int *vetClone = malloc(f->n * sizeof(int));


    for(int i = 0; i < f->n; i++){

        vetClone[i] = vet[i];

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

            printf("Clausula %d, %d %d\n", i, formula->clausulas[i].val[j], formula->clausulas[i].valorLogico[j]);

        }


    }
}