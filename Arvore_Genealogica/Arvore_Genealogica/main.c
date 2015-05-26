#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

#define PAI 0;
#define MAE 1;

//
//  main.c
//  Arvore_Genealogica
//
//  Created by Alan Jhones Faccin  Diovani B. da Motta e Rafael Pablo Massocato on 5/25/15.
//  Copyright (c) 2015 Alan Jhones Faccin Diovani B. da Motta e Rafael Pablo Massocato. All rights reserved.
//

struct Pessoa {
	char* nome;
	struct Pessoa* pai;
	struct Pessoa* mae;
};

struct Pessoa *primeiro;
struct Pessoa *ultimo;

///////////////////////////////////////////////////////////////////
//   
//       FUNCOES USADAS PARA EFETUAR A ALOCAÇÃO DA LISTA  
//
///////////////////////////////////////////////////////////////////
void inicialize()
{
	 struct Pessoa *aux = (struct Pessoa*)(malloc(sizeof(struct Pessoa)));
	 primeiro = aux;
	 ultimo = primeiro;
	 primeiro->pai = NULL;
	 primeiro->mae = NULL;
}

void inserir(struct Pessoa* pessoa)
{
	ultimo = pessoa;
	pessoa->pai->mae = NULL;
	pessoa->pai->pai = NULL;
	pessoa->mae->pai = NULL;
	pessoa->mae->mae = NULL;		
}

void add(struct Pessoa* pessoa,const tipo)
{
	switch(tipo)
	{
		case PAI:
			ultimo->pai->pai = pessoa;
			break;
		case MAE:
			ultimo->mae->mae = pessoa;
			break;
	}
	ultimo = pessoa;
	pessoa->pai->mae = NULL;
	pessoa->pai->pai = NULL;
	pessoa->mae->pai = NULL;
	pessoa->mae->mae = NULL;		
}

void pesquisar(const char* valor)
{
	
}



void visualizarArvore(struct Pessoa* pessoa)
{
	//Massinha
}

int main(int argc, const char * argv[]) {
    
    int opcao=0;
    
    puts("========== ##### Arvore Genealogica ##### ==========");
    puts("=#---------- Escolha uma opcao do menu: -----------#= \n");
    puts("|#  1 - Construir Arvore Genealogica  ");
    puts("|#  2 - Salvar em Arquivo ");
    puts("|#  3 - Carregar do Arquivo  ");
    puts("|#  4 - Visualizar Arvore ");
    puts("|#  5 - Pesquisar Pessoa ");
    
    scanf("%d",&opcao);

    printf("%d",opcao);
    
    return 0;
    
}
