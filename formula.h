#ifndef FORMULA_H
#define FORMULA_H

#define MAX 64

typedef struct clausula Clausula;
typedef struct formula Formula;

Formula* criaFormula(int n, int m);
void destroiFormula(Formula *f);
void adicionaClausula(Formula *f, int i, int *vetAdd);
void imprimeFormula(Formula *f);
int solucaoFormula(Formula *f, int n, int *vet); // deve usar recursion
int verificaCada(Formula *f, int n, int *vet);
int verificaClausula(Formula *f, int *vet, int n);
void proxVeri(Formula *f, int *vet);
void limpaAdd(int *vet, int n);
void imprimirClausulas(Formula *formula);


#endif