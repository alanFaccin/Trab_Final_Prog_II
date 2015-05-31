#include <stdio.h>
#include "TArvore.h"
#include "TIOFile.h"
#include "TString.h"

void write(){
	int r;
	FILE *fp;
	//TArvore arv = TArvoreCreate();
	TPessoa p = TPessoaCreate("Banana");
	TPessoa pes = (TPessoa) malloc (sizeof(TPessoa));
	fp = fopen("E:\\arvore.txt","w");
		if(fp){
			r= fwrite(*(p->nome),sizeof(char),1,fp);
			//printf("%i",r);
			
			if(r == 1){	
				fclose(fp);
				fp = fopen("E:\\arvore.txt","r");
				if(fp){
					if(fread(pes,sizeof(TPessoa),1,fp) ==1){
						TPessoaInOrdem(pes);
						
					}else{
						puts("Problema ao ler do arquivo ");
					}	
							
				}else{
					puts ("Erro ao abrir o arquivo leitura");
				}
				
			}
			else{
				puts("Problema ao escrever em arquivo leitura");
			}
			
		}
		else{
			puts ("Erro ao abrir o arquivo");
		}
	
	} 
	
