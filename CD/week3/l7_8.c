#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "l3.h"
void program();
void declarations();
void dataType();
void assignStat();
void identifierList();

//int curr = 0; char str[100]; 
FILE *f1;
 struct token tkn;

void error(char *tokn) 
{ 
	 	printf("---ERROR!--- %s %d %d expected\n",tokn,tkn.row,tkn.col); 
	 	exit(0); 
} 
void valid() 
{ 
	 	printf("---SUCCESS!----\n"); 	 
	 	exit(0); 
}
void program(){
	if ((strcmp((tkn).lexeme,"main")==0))	
	{
		tkn=getNextToken(f1);
		if (strcmp(tkn.lexeme,"(")==0)
		{tkn=getNextToken(f1);
			if (strcmp(tkn.lexeme,")")==0)
			{tkn=getNextToken(f1);
				if (strcmp(tkn.lexeme,"{")==0)
				{tkn=getNextToken(f1);
					declarations();
				
						assignStat();
						if (strcmp(tkn.lexeme,"}")==0)
						{tkn=getNextToken(f1);
							if (tkn.row == -1)
							{
								valid();
							}
							else
								{ error("end of file");}
						}
						else
								{ error("}"); }
				
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
	if (strcmp(tkn.lexeme,"int")!=0||strcmp(tkn.lexeme,"char")!=0)
	{
		return;
	}
	dataType();
	
		identifierList();
		if (strcmp(tkn.lexeme,";")==0)
		{tkn=getNextToken(f1);
			declarations();
		}
		else
		{
			error(";");
		}
	}
	


void dataType(){
	if (strcmp(tkn.lexeme,"int")==0||strcmp(tkn.lexeme,"char")==0)
	{tkn=getNextToken(f1);
		return;
	}
	else
		error("data type int or char");
}
void identifierList(){
	if (strcmp(tkn.type,"IDENTIFIER")==0)
		{tkn=getNextToken(f1);
			if (strcmp(tkn.lexeme,",")==0)
			{tkn=getNextToken(f1);
				identifierList();
			}
			else
			{
				return;
			}
		}
		else{
			error("IDENTIFIER");
		}

}
void assignStat(){
	if (strcmp(tkn.type,"IDENTIFIER")==0)
		{tkn=getNextToken(f1);
			if (strcmp(tkn.lexeme,"=")==0)
			{tkn=getNextToken(f1);
				if (strcmp(tkn.type,"IDENTIFIER")==0||strcmp(tkn.type,"NUMBER")==0)
				{tkn=getNextToken(f1);
					if (strcmp(tkn.lexeme,";")==0)
						{
							tkn=getNextToken(f1);
							return;}
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
	tkn=getNextToken(f1);
	program();


}