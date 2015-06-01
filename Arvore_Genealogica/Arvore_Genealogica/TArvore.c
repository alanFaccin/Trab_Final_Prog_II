#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TArvore.h"
#include "TString.c"

typedef struct Pessoa {
	char* nome;
	TPessoa* pai;
	TPessoa* mae;
} TPessoa;

typedef int TTipo;

typedef struct Arvore {
	TPessoa* pessoa;
} TArvore;

TArvore* arv;
TArvore* arvore_file;
TArvore* arvore_test;


//constantes que identificam o tipo de registro
const TTipo PAI = 0;
const TTipo MAE = 1;   
/////////////////////////////////////////////////////////////////
///    Fun��es usadas para a cria��o da estrutura de dados   ///
///////////////////////////////////////////////////////////////

TArvore* TArvoreCreate()
{
	TArvore* novo = (TArvore*) malloc(sizeof(TArvore));
	return novo;	
}

TPessoa* TPessoaCreate(char* nome)
{
	TPessoa* pessoa = (TPessoa*) malloc(sizeof(TPessoa));
	pessoa->nome = malloc(sizeof(char*)); 
	strcpy(pessoa->nome,nome);
	pessoa->mae = NULL;
	pessoa->pai = NULL;
	return pessoa;	
}

TPessoa* TPessoaInsert(TPessoa* raiz, TPessoa* novo,TTipo tipo)
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

void TPessoaPreOrdem(TPessoa* pessoa)
{
	if(!TPessoaVazia(pessoa))
	{
		printf(" -> Nome: %s\n",pessoa->nome);
		TPessoaPreOrdem(pessoa->pai);
		TPessoaPreOrdem(pessoa->mae);
	}
}

void TPessoaPosOrdem(TPessoa* pessoa)
{
	if(!TPessoaVazia(pessoa))
	{
		TPessoaPosOrdem(pessoa->pai);
		TPessoaPosOrdem(pessoa->mae);
		printf(" -> Nome: %s\n",pessoa->nome);
	}
}

void TPessoaInOrdem(TPessoa* pessoa)
{
	if(!TPessoaVazia(pessoa))
	{
		TPessoaInOrdem(pessoa->pai);
		printf(" -> Nome: %s\n",pessoa->nome);
		TPessoaInOrdem(pessoa->mae);
	}
}

int TPessoaVazia(TPessoa* pessoa)
{
	return (pessoa == NULL);
}

/// teste gravar arvore arquivo 

void TPessoaWrite(TPessoa* pessoa)
{
	if(!TPessoaVazia(pessoa))
	{
		
		
		int r;
		FILE *fp;
		fp = fopen("F:\\arvore.bin","ab");
		
		if(fp){
			
			r= fwrite(pessoa,sizeof(TPessoa),1,fp);
			
			if(r == 1){	
				
			//puts ("gravou arquivo");
							
			}else{
					puts ("Erro ao gravar estrutura");
				}
				
			}
			else{
				puts("Erro ao abrir o arquivo para gravacao");
			}
			fclose(fp);
			
			
			TPessoaWrite(pessoa->pai);
			TPessoaWrite(pessoa->mae);
			
	}
}

/// teste ler arvore arquivo 

void TPessoaRead()
{
	int r,i=0;
	FILE *fp;
	TPessoa* leitura;
	arvore_file = TArvoreCreate();
	fp = fopen("F:\\arvore.bin","rb");
	// tenta abrir o arquivo
	if(fp){	
	
	    leitura = malloc (sizeof(TPessoa*));
		while(!feof(fp)){
	    
		fseek(fp,sizeof(TPessoa)*i,SEEK_SET);
		
		if(fread(leitura,sizeof(TPessoa),1,fp) ==1){
			
				if(!TPessoaVazia(leitura)){
					//printf("%s\n",leitura->nome);
					
				
					// se a arvore for vazia
					if(i==0){
						//puts("Pessoa vazia");
						//arvore_file->pessoa = TPessoaCreate(leitura->nome);
						arvore_file->pessoa = leitura;
						//TPessoaInOrdem(arvore_file->pessoa);
						
					}
					/*
					if(i==1){
						TPessoaInsert(arvore_file->pessoa,leitura,PAI);
						puts("inseriu o pai");
					
					}
					*/
					TPessoaPreOrdem(arvore_file->pessoa);
					
					
				}else{
					puts("pessoa com fome");
				}				
						
		}else{
			puts("Problema ao ler do arquivo ");
		}
		i++;	
			
		}
							
	}else{
		puts ("Erro ao abrir o arquivo leitura");
	}
	
}

void TArvoreRead()
{
	int r,i=0;
	FILE *fp;
	arvore_test = TArvoreCreate();
	fp = fopen("F:\\arvore.bin","rb");
	// tenta abrir o arquivo
	if(fp){	
		
		if(fread(arvore_test,sizeof(TArvore),1,fp) ==1){
			
					TPessoaPreOrdem(arvore_test->pessoa);			
						
		}else{
			puts("Problema ao ler do arquivo ");
		}
		i++;	
			
		}else{
		puts ("Erro ao abrir o arquivo leitura");
		}
	
}





