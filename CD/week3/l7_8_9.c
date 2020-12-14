#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "l3.h"
void program();
void declarations();
void dataType();
void identifierList();
void statementList();
void statement();
void assignStat();
void expn();
void eprime();
void simpleExp();
void seprime();
void term();
void tprime();
void factor();
void decisionStat();
void dprime();
void loopingStat();
void relop();
void addop();
void mulop();


//int curr = 0; char str[100]; 
FILE *f1;
 struct token tkn;

void error(char *tokn) 
{ 
	 	printf("---ERROR!--- %s expected\n",tokn); 
	 	exit(0); 
} 
void valid() 
{ 
	 	printf("---SUCCESS!----\n"); 	 
	 	exit(0); 
}
void program(){
	if (strcmp((tkn=getNextToken(f1)).lexeme,"main")==0)	
	{
		if (strcmp((tkn=getNextToken(f1)).lexeme,"(")==0)
		{
			if (strcmp((tkn=getNextToken(f1)).lexeme,")")==0)
			{
				if (strcmp((tkn=getNextToken(f1)).lexeme,"{")==0)
				{
					declarations();
					if (strcmp((tkn=getNextToken(f1)).lexeme," ")==0)
					{
						assignStat();
						if (strcmp((tkn=getNextToken(f1)).lexeme,"}")==0)
						{
							if ((tkn = getNextToken(f1)).row != -1)
							{
								valid();
							}
							else
								{ error("end of file"); }
						}
						else
								{ error("}"); }
					}
					else
								{ error(" "); }
				}
				else
								{ error("{");}

			}
				else
								{ error(")");}
			
		}else
			{ error("(");}
		
	}
	else
			{ error("main");}
		

}
void declarations(){
	dataType();
	if (strcmp((tkn=getNextToken(f1)).lexeme," ")==0)
	{
		identifierList();
		if (strcmp((tkn=getNextToken(f1)).lexeme,";")==0)
		{
			declarations();
		}
		else
		{
			error(";");
		}
	}
	else
	{
		error(" ");
	}


}
void dataType(){
	if (strcmp((tkn=getNextToken(f1)).lexeme,"int")==0||strcmp(tkn.lexeme,"char")==0)
	{
		return;
	}
	else
		error("data type int or char");
}
void identifierList(){
	if (strcmp((tkn=getNextToken(f1)).type,"IDENTIFIER")==0)
		{
			if (strcmp((tkn=getNextToken(f1)).lexeme,",")==0)
			{
				identifierList();
			}
			else
			{
				error(",");
			}
		}
		else{
			error("IDENTIFIER");
		}

}
void assignStat(){
	if (strcmp((tkn=getNextToken(f1)).type,"IDENTIFIER")==0)
		{
			if (strcmp((tkn=getNextToken(f1)).lexeme,"=")==0)
			{
				if (strcmp((tkn=getNextToken(f1)).type,"IDENTIFIER")==0||stcmp(tkn.type,"NUMBER")==0)
				{
					if (strcmp((tkn=getNextToken(f1)).lexeme,";")==0)
						return;
					else
						error(";");
				}
				else
						error("IDENTIFIER OR NUMBER");
			}
			else
						error("=");
		}
		else
						error("IDENTIFIER");


}
int main(){
	f1= fopen("Input.c", "r");
	program();


}