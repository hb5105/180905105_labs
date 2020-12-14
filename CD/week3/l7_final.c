#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lex.c"
void program();
void declarations();
void dataType();
void idList();
void idListprime();
void assignStat();
void statPrime();

struct token tkn;
FILE *f1;
int main()
{
	f1=preproccess("Input.c");
	if(f1==NULL)
	{
	  	printf("Error! File cannot be opened!\n");
	  	return 0;
	}
	
	while((tkn=getNextToken(f1)).row!=-1)
	{
		if(strcmp(tkn.lexeme,"main")==0)
		{
			program();
			break;
		}
	}
    fclose(f1);
}
void program()
{

	if(strcmp(tkn.lexeme,"main")==0)
	{
		tkn=getNextToken(f1);
		if(strcmp(tkn.lexeme,"(")==0)
		{
			tkn=getNextToken(f1);
			if(strcmp(tkn.lexeme,")")==0)
			{
				tkn=getNextToken(f1);
				if(strcmp(tkn.lexeme,"{")==0)
				{
					tkn=getNextToken(f1);
					declarations();
					assignStat();
					if(strcmp(tkn.lexeme,"}")==0)
					{
						printf("\nCompiled successfully\n");
						return;
					}
					else
					{
						printf("} missing at row=%d col=%d\n",tkn.row,tkn.col);
						exit(1);
					}
				}
				else
				{	
					printf("{ missing at row=%d col=%d\n",tkn.row,tkn.col);
					exit(1);
				}
			}
			else
			{
				printf(") missing at row=%d col=%d\n",tkn.row,tkn.col);
				exit(1);
			}
		}
		else
		{
			printf("( missing at row=%d col=%d\n",tkn.row,tkn.col);
			exit(1);
		}
	}
}
void declarations()
{
	if(isdtype(tkn.lexeme)==0)
	{
		return;
	}
	dataType();
	idList();
	if(strcmp(tkn.lexeme,";")==0)
	{
		tkn=getNextToken(f1);
		declarations();
	}
	else
	{
		printf("; missing at row=%d col=%d\n",tkn.row,tkn.col);
		exit(1);
	}
}
void dataType()
{
	if(strcmp(tkn.lexeme,"int")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	else if(strcmp(tkn.lexeme,"char")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	else
	{
		printf("%s Missing dataType at row=%d col=%d\n",tkn.lexeme, tkn.row,tkn.col);
		exit(1);
	}
}
void idList()
{
	if(strcmp(tkn.type,"IDENTIFIER")==0)
	{
		tkn=getNextToken(f1);
		idListprime();
	}
	else
	{
		printf("Missing IDENTIFIER at row=%d col=%d\n",tkn.row,tkn.col);
	}
}
void idListprime()
{
	if(strcmp(tkn.lexeme,",")==0)
	{
		tkn=getNextToken(f1);
		idList();
	}
	else
	{
		return;
	}
}
void assignStat()
{
	if(strcmp(tkn.type,"IDENTIFIER")==0)
	{
		tkn=getNextToken(f1);
		if(strcmp(tkn.lexeme,"=")==0)
		{
			tkn=getNextToken(f1);
			statPrime();
		}
		else
		{
			printf("= missing at row=%d col=%d\n",tkn.row,tkn.col);
			exit(1);
		}
	}
	else
	{
		return;
}}
void statPrime()
{
	if(strcmp(tkn.type,"IDENTIFIER")==0)
	{
		tkn=getNextToken(f1);
		if(strcmp(tkn.lexeme,";")==0)
		{
			tkn=getNextToken(f1);
			return;
		}
		else
		{
			printf("; missing at row=%d col=%d\n",tkn.row,tkn.col);
			exit(1);
		}
	}
	else if(strcmp(tkn.type,"NUMBER")==0)
	{
		tkn=getNextToken(f1);
		if(strcmp(tkn.lexeme,";")==0)
		{
			tkn=getNextToken(f1);
			return;
		}
		else
		{
			printf("= missing at row=%d col=%d\n",tkn.row,tkn.col);
			exit(1);
		}
	}
}