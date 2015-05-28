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
