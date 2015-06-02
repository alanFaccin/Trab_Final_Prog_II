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
char * temp;

int main(int argc, const char * argv[]) {
    
    temp = (char*) malloc(sizeof(char*));
    
    while (opcao <= 5) {
		menu();
    	scanf("%d",&opcao);
    	    
			switch (opcao) {
            case 1:
                puts("Vamos comecar com a construcao da arvore !! /n/n Ela sera composta por 3 geracoes");
                arv = TArvoreCreate();
                puts("Digite o seu nome");
                scanf("%s",temp);
			 	arv->pessoa = TPessoaCreate(temp);
			 	//
			 	puts("Digite o nome do seu pai");
			 	scanf("%s",temp);
				TPessoa* pai = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa,pai,PAI);
				puts("Digite o nome da sua mae");
			 	scanf("%s",temp);
				TPessoa* mae = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa,mae,MAE);
				
				//
				puts("Digite o nome do seu avo Paterno");
			 	scanf("%s",temp);
				TPessoa* avoP = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->pai,avoP,PAI);
				puts("Digite o nome do sua avoh Paterna");
			 	scanf("%s",temp);
			    TPessoa* avaP = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->pai,avaP,MAE);
				//
				puts("Digite o nome do pai do seu avo Paterno");
			 	scanf("%s",temp);
				TPessoa* avoPM = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->pai->pai,avoPM,PAI);
				puts("Digite o nome da mae do seu avo Paterno");
			 	scanf("%s",temp);
			    TPessoa* avoPP = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->pai->pai,avoPP,MAE);
				
				//
				puts("Digite o nome do pai da sua avoh Paterna");
			 	scanf("%s",temp);
				TPessoa* avoPMP = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->pai->mae,avoPMP,PAI);
				puts("Digite o nome da mae da sua avoh Paterna");
			 	scanf("%s",temp);
			    TPessoa* avoPPP = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->pai->mae,avoPPP,MAE);
				
				//
				puts("Digite o nome do seu avo materno");
			 	scanf("%s",temp);
				TPessoa* avoM = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->mae,avoM,PAI);
				puts("Digite o nome da sua avoh materna");
			 	scanf("%s",temp);
			    TPessoa* avaM = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->mae,avaM,MAE);
				
				//
				puts("Digite o nome do pai do seu avo materno");
			 	scanf("%s",temp);
				TPessoa* avoMM = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->mae->pai,avoMM,PAI);
				puts("Digite o nome da mae do seu avo materno");
			 	scanf("%s",temp);
			    TPessoa* avoMP = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->mae->pai,avoMP,MAE);
				
				//
				puts("Digite o nome do pai da sua avoh materna");
			 	scanf("%s",temp);
				TPessoa* avoMMP = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->mae->mae,avoMMP,PAI);
				puts("Digite o nome da mae da sua avoh materna");
			 	scanf("%s",temp);
			    TPessoa* avoMPP = TPessoaCreate(temp);
				TPessoaInsert(arv->pessoa->mae->mae,avoMPP,MAE);
				puts("Muito bem Terminamos a construao da arvore !");
                
                break;
            case 2:
                TPessoaWrite(arv->pessoa);
                puts("Gravado com Sucesso!");
                break;
            case 3:
                  	arv = TPessoaRead();
  					puts("inicio impressao arvore arquivo");
  					TPessoaPreOrdem(arv->pessoa);
  					puts("inicio impressao arvore arquivo");
                break;
            case 4:
                TPessoaPreOrdem(arv->pessoa);
                break;
            case 5:
                printf("->Informe o nome do pessoa para a consulta");
               	scanf("%s",temp);
                TPessoaPesquisar(arv->pessoa,temp);
                break;
        	case 6:
                puts("Obrigado por usar Arvore Genealogica !!");
                break;
            default:
                puts("Opcao invalida !! Selecione uma opcao do menu");
                menu();
                scanf("%d",&opcao);
                break;
        }
		   
    }
    
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
    puts("|#  6 - Sair                                       #|\n");
    puts("========== ############################### ==========");
  

}


