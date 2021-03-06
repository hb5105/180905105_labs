#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lex.c"
void program();
void declarations();
void datatype();
void idList();
void idListprime();
void assignstat();
void statementlist();
void statement();
void expn();
void eprime();
void simpleexp();
void seprime();
void term();
void tprime();
void factor();
void relop();
void addop();
void mulop();
struct token tkn;
FILE *f1;
char *rel[]={"==","!=","<=",">=",">","<"};
char *add[]={"+","-"};
char *mul[]={"*","/","%"};

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

int isrel(char *w)
{
	int i;
	for(i=0;i<sizeof(rel)/sizeof(char*);i++)
	{
		if(strcmp(w,rel[i])==0)
		{
			return 1;
		}
	}
	return 0;
}
int isadd(char *w)
{
	int i;
	for(i=0;i<sizeof(add)/sizeof(char*);i++)
	{
		if(strcmp(w,add[i])==0)
		{
			return 1;
		}
	}
	return 0;
}
int ismul(char *w)
{
	int i;
	for(i=0;i<sizeof(mul)/sizeof(char*);i++)
	{
		if(strcmp(w,mul[i])==0)
		{
			return 1;
		}
	}
	return 0;
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
					statementlist();
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
	datatype();
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
	if(strcmp(tkn.lexeme,"[")==0)
	{
		tkn=getNextToken(f1);
		if(strcmp(tkn.type,"NUMBER")==0)
		{
			tkn=getNextToken(f1);
			if(strcmp(tkn.lexeme,"]")==0)
			{
				tkn=getNextToken(f1);
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
		}
	}
	else
	{
		return;
	}
}
void statementlist()
{
	if(strcmp(tkn.type,"IDENTIFIER")!=0)
	{
		return;
	}
	statement();
	statementlist();
}
void statement()
{
	assignstat();
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
void assignstat()
{
	if(strcmp(tkn.type,"IDENTIFIER")==0)
	{
		tkn=getNextToken(f1);
		if(strcmp(tkn.lexeme,"=")==0)
		{
			tkn=getNextToken(f1);
			expn();
		}
		else
		{
			printf("= missing at row=%d col=%d\n",tkn.row,tkn.col);
			exit(1);
		}
	}
	else
	{
		printf("Missing IDENTIFIER at row=%d col=%d\n",tkn.row,tkn.col);
		exit(1);
	}
}
void expn()
{
	simpleexp();
	eprime();
}
void eprime()
{
	if(isrel(tkn.lexeme)==0)
	{
		return;
	}
	relop();
	simpleexp();
}
void simpleexp()
{
	term();
	seprime();
}
void seprime()
{
	if(isadd(tkn.lexeme)==0)
	{
		return;
	}
	addop();
	term();
	seprime();
}
void term()
{
	factor();
	tprime();
}
void tprime()
{
	if(ismul(tkn.lexeme)==0)
	{
		return;
	}
	mulop();
	factor();
	tprime();
}
void factor()
{
	if(strcmp(tkn.type,"IDENTIFIER")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	else if(strcmp(tkn.type,"NUMBER")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
}
void relop()
{
	if(strcmp(tkn.lexeme,"==")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	if(strcmp(tkn.lexeme,"!=")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	if(strcmp(tkn.lexeme,"<=")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	if(strcmp(tkn.lexeme,">=")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	if(strcmp(tkn.lexeme,"<")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	if(strcmp(tkn.lexeme,">")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
}
void addop()
{
	if(strcmp(tkn.lexeme,"+")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	if(strcmp(tkn.lexeme,"-")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
}
void mulop()
{
	if(strcmp(tkn.lexeme,"*")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	if(strcmp(tkn.lexeme,"/")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
	if(strcmp(tkn.lexeme,"*")==0)
	{
		tkn=getNextToken(f1);
		return;
	}
}