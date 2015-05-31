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

int opcao=0;

int main(int argc, const char * argv[]) {
    
    
    arvore = TArvoreCreate();
 	arvore->pessoa = TPessoaCreate("DIOVANI");
 	// pai e mae
 	TPessoa pai = TPessoaCreate("ADENIR");
	TPessoa mae = TPessoaCreate("ROSINA");
    TPessoaInsert(arvore->pessoa,pai,PAI);
	TPessoaInsert(arvore->pessoa,mae,MAE);
	// avo e avó paterna 
	TPessoa pai2p = TPessoaCreate("avo paterno");
	TPessoa mae2p = TPessoaCreate("avoh paterna");
    TPessoaInsert(arvore->pessoa->pai,pai2p,PAI);
	TPessoaInsert(arvore->pessoa->pai,mae2p,MAE);
	// avo e avó materna
	TPessoa pai2m = TPessoaCreate("avo mateno");
	TPessoa mae2m = TPessoaCreate("avoh materna");
    TPessoaInsert(arvore->pessoa->mae,pai2m,PAI);
	TPessoaInsert(arvore->pessoa->mae,mae2m,MAE);
	
	// pai e mae do avo paterno 
	TPessoa pai_avo_p = TPessoaCreate("pai avo p");
	TPessoa mae_avo_p = TPessoaCreate("mae avo p");
    TPessoaInsert(arvore->pessoa->pai->pai,pai_avo_p,PAI);
	TPessoaInsert(arvore->pessoa->pai->pai,mae_avo_p,MAE);
	// pai e mae da avoh paterno 
	TPessoa pai_avoh_p = TPessoaCreate("pai avoh p");
	TPessoa mae_avoh_p = TPessoaCreate("mae avoh p");
    TPessoaInsert(arvore->pessoa->pai->mae,pai_avoh_p,PAI);
	TPessoaInsert(arvore->pessoa->pai->mae,mae_avoh_p,MAE);
	
	
	// pai e mae do avo matrno 
	TPessoa pai_avo_m = TPessoaCreate("pai avo m");
	TPessoa mae_avo_m = TPessoaCreate("mae avo m");
    TPessoaInsert(arvore->pessoa->mae->pai,pai_avo_m,PAI);
	TPessoaInsert(arvore->pessoa->mae->pai,mae_avo_m,MAE);
	// pai e mae do avoh materna 
	TPessoa pai_avoh_m = TPessoaCreate("pai avoh m");
	TPessoa mae_avoh_m = TPessoaCreate("mae avoh m");
    TPessoaInsert(arvore->pessoa->mae->mae,pai_avoh_m,PAI);
	TPessoaInsert(arvore->pessoa->mae->mae,mae_avoh_m,MAE);

	
	
	TPessoaInOrdem(arvore->pessoa);
	printf("\n");

  //	TPessoaWrite(arvore->pessoa);
  //	TPessoaRead();
    
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

