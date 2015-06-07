#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAIZ 0
#define _PAI 1
#define AVOP 2
#define BISAVOPPA 3
#define BISAVOPMA 4
#define AVOHP 5
#define BISAVOPPB 6
#define BISAVOPMB 7
#define _MAE 8
#define AVOM 9
#define BISAVOMPA 10
#define BISAVOMMA 11
#define AVOHM 12
#define BISAVOMPB 13
#define BISAVOMMB 14


typedef struct Pessoa TPessoa;
typedef struct Arvore TArvore;
typedef int TTipo;

extern TArvore* arv;
extern const TTipo MAE; 
extern const TTipo PAI; 


TArvore* TArvoreCreate();

TPessoa* TPessoaCreate(char* nome);

TPessoa* TPessoaInsert(TPessoa* raiz, TPessoa* novo,TTipo tipo);

void TPessoaPreOrdem(TPessoa* pessoa);

void TPessoaPosOrdem(TPessoa* pessoa);

void TPessoaInOrdem(TPessoa* pessoa);

int TPessoaVazia(TPessoa* pessoa);

int TPessoaPesquisar(TPessoa* pessoa,char* nome);

void TPessoaParentesco(char* pessoa);

