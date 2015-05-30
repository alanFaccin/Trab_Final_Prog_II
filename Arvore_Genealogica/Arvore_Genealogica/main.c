#include <stdio.h>
#include <stdlib.h>
#include "TArvore.c"
#include "TString.h"


//
//  main.c
//  Arvore_Genealogica
//
//  Created by Alan Jhones Faccin  Diovani B. da Motta e Rafael Pablo Massocato on 5/25/15.
//  Copyright (c) 2015 Alan Jhones Faccin Diovani B. da Motta e Rafael Pablo Massocato. All rights reserved.
//

TPessoa ultimo;

struct Pessoa *primeiro;
struct Pessoa *ultimo;

int* opcao;




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
/*
void add(struct Pessoa* pessoa,const tipo)
{
	switch(tipo)
	{
        case PAI :
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
*/
void pesquisar(const char* valor)
{
	
}




void visualizarArvore(struct Pessoa* pessoa)
{
	//Massinha
}


int main(int argc, const char * argv[]) {
    
    int opcao=0;
    
    arvore = TArvoreCreate();
 	arvore->pessoa = TPessoaCreate("DIOVANI");
 	TPessoa pai = TPessoaCreate("ADENIR");
	TPessoa mae = TPessoaCreate("ROSINA");
    TPessoaInsert(arvore->pessoa,pai,PAI);
	TPessoaInsert(arvore->pessoa,mae,MAE);
	TPessoaInOrdem(arvore->pessoa);
	printf("\n");
	TPessoaPosOrdem(arvore->pessoa);
	printf("\n");
	TPessoaPreOrdem(arvore->pessoa);
    
    /*
    *opcao = 0;
    
    menu();
    
    while (*opcao <= 5) {
        switch (*opcao) {
            case 1:
                puts("opcao 1");
                break;
            case 2:
                puts("opcao 2");
                break;
            case 3:
                puts("opcao 3");
                break;
            case 4:
                puts("opcao 4");
                break;
            case 5:
                puts("opcao 5");
                break;
            default:
                puts("Opcao invalida !! Selecione uma opcao do menu");
                menu();
                break;
        }
        
    }
    
    */
    return 0;

			    
}

void menu (){


    puts("========== ##### Arvore Genealogica ##### ==========");
    puts("=#---------- Escolha uma opcao do menu: -----------#= \n");
    puts("|#  1 - Construir Arvore Genealogica               #|");
    puts("|#  2 - Salvar em Arquivo                          #|");
    puts("|#  3 - Carregar do Arquivo                        #|");
    puts("|#  4 - Visualizar Arvore                          #|");
    puts("|#  5 - Pesquisar Pessoa                           #|");
    puts("========== ############################### ==========");
    scanf("%d",opcao);

}


