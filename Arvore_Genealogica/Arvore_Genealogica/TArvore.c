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
TArvore arvore_file;

//constantes que identificam o tipo de registro
const TTipo PAI = 0;
const TTipo MAE = 1;   
/////////////////////////////////////////////////////////////////
///    Funções usadas para a criação da estrutura de dados   ///
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

/// teste gravar arvore arquivo 

void TPessoaWrite(TPessoa pessoa)
{
	if(!TPessoaVazia(pessoa))
	{
		TPessoaWrite(pessoa->pai);
		
		int r;
		FILE *fp;
		fp = fopen("E:\\arvore.bin","ab");
		
		if(fp){
			
			r= fwrite(pessoa,sizeof(TPessoa),1,fp);
			
			if(r == 1){	
				
			puts ("gravou arquivo");
							
			}else{
					puts ("Erro ao gravar estrutura");
				}
				
			}
			else{
				puts("Erro ao abrir o arquivo para gravacao");
			}
			fclose(fp);
			
			TPessoaWrite(pessoa->mae);
			
	}
}

/// teste ler arvore arquivo 

void TPessoaRead()
{
	int r,i=0;
	FILE *fp;
	TPessoa leitura;
	arvore_file = TArvoreCreate();
	fp = fopen("E:\\arvore.bin","rb");
	// tenta abrir o arquivo
	if(fp){	
	
	    leitura = malloc (sizeof(TPessoa));
		while(!feof(fp)){
	    
		fseek(fp,sizeof(TPessoa)*i,SEEK_SET);
		
		if(fread(leitura,sizeof(TPessoa),1,fp) ==1){
			
				if(!TPessoaVazia(leitura)){
					printf("%s\n",leitura->nome);
					
				/*
					// se a arvore for vazia
					if(i==0){
						//puts("Pessoa vazia");
						arvore_file->pessoa = TPessoaCreate(leitura->nome);
						TPessoaInOrdem(arvore_file->pessoa);
					}
				*/	
					
				//	TPessoaInsert(arvore_file->pessoa,pai,PAI);
					
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




