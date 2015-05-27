#include "TString.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* TStringCreate()
{
	char* valor = (char*) malloc(sizeof(char*));
	return valor;
}

void TStringSet(char* campo,char* valor)
{
	strcpy(campo,valor);
}
