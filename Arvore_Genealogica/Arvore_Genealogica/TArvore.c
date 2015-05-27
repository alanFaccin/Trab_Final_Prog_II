#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TArvore.h"
#include "TString.c"

struct Pessoa {
	char* nome;
	struct Pessoa* pai;
	struct Pessoa* mae;
};

typedef struct Pessoa* TPessoa;
typedef int TTipo;

struct Arvore {
	TPessoa pessoa;
};

typedef struct Arvore* TArvore;

TArvore arvore;

//constantes que identificam o tipo de registro
const TTipo PAI = 0;
const TTipo MAE = 1;   
/////////////////////////////////////////////////////////////////
///    Fun��es usadas para a cria��o da estrutura de dados   ///
///////////////////////////////////////////////////////////////

TArvore TArvoreCreate()
{
	TArvore novo = (TArvore) malloc(sizeof(TArvore));
	return novo;	
}

TPessoa TPessoaCreate(char* nome)
{
	TPessoa pessoa = (TPessoa) malloc(sizeof(TPessoa));
	pessoa->nome = TStringCreate();
	TStringSet(pessoa->nome,nome);
	pessoa->mae = NULL;
	pessoa->pai = NULL;
	return pessoa;	
}

TPessoa TPessoaInsert(TPessoa raiz, TPessoa novo,TTipo tipo)
{
	if(raiz == NULL)
	{
		raiz = novo;
		return raiz;
	}
	
	if(tipo == PAI)
	{
		raiz->pai = TPessoaInsert(raiz->pai,novo,PAI);
		return raiz;
	}
	
	if(tipo == MAE)
	{
		raiz->mae = TPessoaInsert(raiz->mae,novo,MAE);
		return raiz;
	}
	return raiz;
}

void TPessoaPreOrdem(TPessoa pessoa)
{
	if(!TPessoaVazia(pessoa))
	{
		printf(" -> Nome: %s\n",pessoa->nome);
		TPessoaPreOrdem(pessoa->pai);
		TPessoaPreOrdem(pessoa->mae);
	}
}

void TPessoaPosOrdem(TPessoa pessoa)
{
	if(!TPessoaVazia(pessoa))
	{
		TPessoaPosOrdem(pessoa->pai);
		TPessoaPosOrdem(pessoa->mae);
		printf(" -> Nome: %s\n",pessoa->nome);
	}
}

void TPessoaInOrdem(TPessoa pessoa)
{
	if(!TPessoaVazia(pessoa))
	{
		TPessoaInOrdem(pessoa->pai);
		printf(" -> Nome: %s\n",pessoa->nome);
		TPessoaInOrdem(pessoa->mae);
	}
}

TPessoa TPessoaLiberar(TPessoa pessoa)
{
	if(!TPessoaVazia(pessoa))
	{
		TPessoaLiberar(pessoa->pai);
		TPessoaLiberar(pessoa->mae);
		free(pessoa);
	}
	return NULL;
}

int TPessoaVazia(TPessoa pessoa)
{
	return (pessoa == NULL);
}
