#ifndef FORMULA_H
#define FORMULA_H

#define MAX 64

typedef struct clausula Clausula;
typedef struct formula Formula;

Formula* criaFormula(int n, int m);
void destroiFormula(Formula **f);
void adicionaClausula(Formula *f, int i, int a, int b, int c);
void imprimeFormula(Formula *f);
void solucaoFormula(); // deve usar recursion

#endif
