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

TPessoa* ultimo;

int opcao=0;

int main(int argc, const char * argv[]) {
    
    arv = TArvoreCreate();
 	arv->pessoa = TPessoaCreate("PESSOA");
 	//
	TPessoa* pai = TPessoaCreate("PAI");
	TPessoa* mae = TPessoaCreate("MAE");
    TPessoaInsert(arv->pessoa,pai,PAI);
	TPessoaInsert(arv->pessoa,mae,MAE);
	//
	TPessoa* avoP = TPessoaCreate("AVOPATERNO");
    TPessoa* avaP = TPessoaCreate("AVOHPATERNA");
	TPessoaInsert(arv->pessoa->pai,avoP,PAI);
	TPessoaInsert(arv->pessoa->pai,avaP,MAE);
	//
	TPessoa* avoPM = TPessoaCreate("PAIAVOPATERNO");
    TPessoa* avoPP = TPessoaCreate("MAEAVOPATERNO");
	TPessoaInsert(arv->pessoa->pai->pai,avoPP,PAI);
	TPessoaInsert(arv->pessoa->pai->pai,avoPM,MAE);
	//
	TPessoa* avoPMP = TPessoaCreate("PAIAVOHPATERNO");
    TPessoa* avoPPP = TPessoaCreate("MAEAVOHPATERNO");
	TPessoaInsert(arv->pessoa->pai->mae,avoPPP,PAI);
	TPessoaInsert(arv->pessoa->pai->mae,avoPMP,MAE);
	//
	
	TPessoa* avoM = TPessoaCreate("AVOMATERNO");
    TPessoa* avaM = TPessoaCreate("AVOHMATERNA");
	TPessoaInsert(arv->pessoa->mae,avoM,PAI);
	TPessoaInsert(arv->pessoa->mae,avaM,MAE);
	//
	TPessoa* avoMM = TPessoaCreate("PAIAVOMATERNO");
    TPessoa* avoMP = TPessoaCreate("MAEAVOMATERNO");
	TPessoaInsert(arv->pessoa->mae->pai,avoMP,PAI);
	TPessoaInsert(arv->pessoa->mae->pai,avoMM,MAE);
	//
	TPessoa* avoMMP = TPessoaCreate("PAIAVOHMATERNA");
    TPessoa* avoMPP = TPessoaCreate("MAEAVOHMATERNA");
	TPessoaInsert(arv->pessoa->mae->mae,avoMPP,PAI);
	TPessoaInsert(arv->pessoa->mae->mae,avoMMP,MAE);
		
	TPessoaPreOrdem(arv->pessoa);
	printf("\n");

  	TPessoaWrite(arv->pessoa);
  	TArvoreRead();
    
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
/*
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
*/

