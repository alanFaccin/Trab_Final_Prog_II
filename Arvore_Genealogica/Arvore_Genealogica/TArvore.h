#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa* TPessoa;
typedef struct Arvore* TArvore;
typedef int TTipo;

extern TArvore arvore;
extern const TTipo MAE; 
extern const TTipo PAI; 


TArvore TArvoreCreate();

TPessoa TPessoaCreate(char* nome);

TPessoa TPessoaInsert(TPessoa raiz, TPessoa novo,TTipo tipo);

void TPessoaPreOrdem(TPessoa pessoa);

void TPessoaPosOrdem(TPessoa pessoa);

void TPessoaInOrdem(TPessoa pessoa);

TPessoa TPessoaLiberar(TPessoa pessoa);

int TPessoaVazia(TPessoa pessoa);
