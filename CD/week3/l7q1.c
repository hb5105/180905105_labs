#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lex.c"
void program();
void declarations();
void datatype();
void idlist();
void idlistprime();
void assignstat();
void statprime();

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
					assignstat();
					if(strcmp(tkn.lexeme,"}")==0)
					{
						printf("Compiled successfully\n");
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
	datatype();
	idlist();
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
void datatype()
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
		printf("%s Missing datatype at row=%d col=%d\n",tkn.lexeme, tkn.row,tkn.col);
		exit(1);
	}
}
void idlist()
{
	if(strcmp(tkn.type,"IDENTIFIER")==0)
	{
		tkn=getNextToken(f1);
		idlistprime();
	}
	else
	{
		printf("Missing IDENTIFIER at row=%d col=%d\n",tkn.row,tkn.col);
	}
}
void idlistprime()
{
	if(strcmp(tkn.lexeme,",")==0)
	{
		tkn=getNextToken(f1);
		idlist();
	}
	else
	{
		return;
	}
}
void assignstat()
{
	if(strcmp(tkn.type,"IDENTIFIER")==0)
	{
		tkn=getNextToken(f1);
		if(strcmp(tkn.lexeme,"=")==0)
		{
			tkn=getNextToken(f1);
			statprime();
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
void statprime()
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