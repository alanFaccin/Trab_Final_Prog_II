//
//  main.c
//  Arvore_Genealogica
//
//  Created by Alan Jhones Faccin  Diovani B. da Motta e Rafael Pablo Massocato on 5/25/15.
//  Copyright (c) 2015 Alan Jhones Faccin Diovani B. da Motta e Rafael Pablo Massocato. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
	 struct Pessoa *aux = (struct Pessoa*)(malloc(sizeof(struct Pessoa));
	 primeiro = aux;
	 ultimo = primeiro;
	 primeiro->pai = NULL;
	 primeiro->mae = NULL;
}

void inserir(struct Pessoa* pessoa)
{
	ultimo->prox = endereco;
	endereco->ant = ultimo;
	ultimo = ultimo->prox;
	endereco->prox = NULL;		
}

void pesquisar(const char* valor)
{
	
}

int main(int argc, const char * argv[]) {
    
    // insert code here...
    printf("Hello, World!\n");
    return 0;
    
}
