//Tomara que agora funcione
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TArvore.h"
#include "TString.c"

#define MAX 15

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

int count = -1;
//constantes que identificam o tipo de registro
const TTipo PAI = 0;
const TTipo MAE = 1;   
/////////////////////////////////////////////////////////////////
///    Funções usadas para a criação da estrutura de dados   ///
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
		fp = fopen("D:\\arvore.bin","ab");
		
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

TArvore* TPessoaRead()
{
	int r,i=0;
	FILE *fp;
	TPessoa* leitura;// utilizado para ler cada uma das pessoas que estão gravados no arquivo
	arvore_file = TArvoreCreate(); //crinado e alocandao memoria para a arvore que será lida do arquivo
	fp = fopen("D:\\arvore.bin","rb"); // abre o arquivo binario que contém a arvore salva 
	// tenta abrir o arquivo
	if(fp){	
	    leitura = malloc (sizeof(TPessoa));// aloca memoria para uma estrutura Tpessoa
		while(!feof(fp)){ // enquanto não chegar no final do arquivo
	    
		fseek(fp,sizeof(TPessoa)*i,SEEK_SET); // a cada iteração do while faz um salto do tamannho de uma sctruct pessoa no arquivo
		
		if(fread(leitura,sizeof(TPessoa),1,fp) ==1){
			
				if(!TPessoaVazia(leitura)){
					//printf("%s\n",leitura->nome);
				
					// se a arvore for vazia
					if(i==0){
						
						arvore_file->pessoa = TPessoaCreate(leitura->nome);
						//puts("inseriu a pessoa");
					}
					
					if(i==1){
						TPessoa* pai = TPessoaCreate(leitura->nome);
						TPessoaInsert(arvore_file->pessoa,pai,PAI);
						//puts("inseriu o pai");
					}
					if(i==2){
						TPessoa* avoP = TPessoaCreate(leitura->nome);
						TPessoaInsert(arvore_file->pessoa->pai,avoP,PAI);
						//puts("inseriu o avopaterno");
					}
					if(i==3){
						TPessoa* avoPP = TPessoaCreate(leitura->nome);
						TPessoaInsert(arvore_file->pessoa->pai->pai,avoPP,MAE);
						//puts("inseriu o maeavopaterno");
					}
					if(i==4){
						TPessoa* avoPM = TPessoaCreate(leitura->nome);
						TPessoaInsert(arvore_file->pessoa->pai->pai,avoPM,PAI);
						//puts("inseriu o paiavopaterno");
					}
					
					
				}else{
					puts("pessoa com fome");
				}				
						
		}else{
			puts("Problema ao ler do arquivo ");
		}
		i++;
		//printf("%i",i);	
			
		}
							
	}else{
		puts ("Erro ao abrir o arquivo leitura");
	}
	//TPessoaPreOrdem(arvore_file->pessoa);
	return arvore_file;
}

void TPessoaPesquisar(TPessoa* pessoa,char* nome)
{
	if(!TPessoaVazia(pessoa))
	{
		if(!strcmp(pessoa->nome,nome)){
			count++;
			TPessoaPesquisar(pessoa->pai,nome);
			count++;
			TPessoaPesquisar(pessoa->mae,nome);
			return;	
		}
		TPessoaParentesco(nome);
	}
	else 
	{
		printf("Pessoa nao encontrada com o parâmetro informado.\n");
		count = 0;
	}
}


void TPessoaParentesco(char* pessoa){
	if(count == 0)
	{
		printf("FILHO\n");
	}
	if(count == 1)
	{
		printf("PAI\n");
	}
	if(count == 2)
	{
		printf("AVO PATERNO\n");
	}
	if(count == 3)
	{
		printf("PAI DO AVO PATERNO\n");
	}
	if(count == 4)
	{
		printf("MAE DO AVO PATERNO\n");
	}
	if(count == 5)
	{
		printf("AVÓ PATERNA\n");
	}
	if(count == 6)
	{
		printf("PAI DA AVÓ PATERNA\n");
	}
	if(count == 7)
	{
		printf("MAE DA AVÓ PATERNA\n");
	}
	if(count == 8)
	{
		printf("MAE\n");
	}
	if(count == 9)
	{
		printf("AVO MATERNO\n");
	}
	if(count == 10)
	{
		printf("PAI DA AVO MATERNA\n");
	}
	if(count == 11)
	{
		printf("MAE DA AVO MATERNA\n");
	}
	if(count == 12)
	{
		printf("AVÓ MATERNA\n");
	}
	if(count == 13)
	{
		printf("PAI DA AVÓ MATERNA\n");
	}
	if(count == 14)
	{
		printf("MAE DA AVÓ MATERNA\n");
	}
	count = 0;
}
/*
void TArvoreRead()
{
	int r,i=0;
	FILE *fp;
	arvore_test = TArvoreCreate();
	TPessoa* test;
	fp = fopen("D:\\arvore.bin","rb");
	// tenta abrir o arquivo
	if(fp){	
		test = malloc (sizeof(TPessoa));
		
		if(fread(test,sizeof(TPessoa),1,fp) ==1){
			
					arvore_test->pessoa = TPessoaCreate(test->nome);			
						
		}else{
			puts("Problema ao ler do arquivo ");
		}
		i++;	
			
		}else{
		puts ("Erro ao abrir o arquivo leitura");
		}
	fclose(fp);
	puts("impressao do arquivo");
	TPessoaPreOrdem(arvore_test->pessoa);
	puts("fim impressao arquivo");
}

*/



