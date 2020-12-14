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

void error(char *tokn, int a, int b) 
{ 
	 	printf("---ERROR! in row: %d column: %d %s expected\n",tokn,a,b); 
	 	exit(0); 
} 
void valid() 
{ 
	 	printf("---SUCCESS!----\n"); 	 
	 	exit(0); 
}
void program(){
	if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,"main")==0)	
	{
		if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,"(")==0)
		{
			if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,")")==0)
			{
				if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,"{")==0)
				{
					declarations();
	
						assignStat();
						if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,"}")==0)
						{
							if ((tkn = getNextToken(f1)).row == -1)
							{
								valid();
							}
							else
								{ error("end of file",tkn.row,tkn.col); return;}
						}
						else
								{ error("}",tkn.row,tkn.col); }
	
				}
				else
								{ error("{",tkn.row,tkn.col);}

			}
				else
								{ error(")",tkn.row,tkn.col);}
			
		}else
			{ error("(",tkn.row,tkn.col);}
		
	}
	else
			{ error("main",tkn.row,tkn.col);}
		

}
void declarations(){
	dataType();
	
		identifierList();
		if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,";")==0)
		{
			declarations();
		}
		else
		{
			error(";",tkn.row,tkn.col);
		}
	}
	

void dataType(){
	if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,"int")==0||strcmp(tkn.lexeme,"char")==0)
	{
		return;
	}
	else
		error("data type int or char",tkn.row,tkn.col);
}
void identifierList(){
	if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.type,"IDENTIFIER")==0)
		{
			if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,",")==0)
			{
				identifierList();
			}
			else
			{
				error(",",tkn.row,tkn.col);
			}
		}
		else{
			error("IDENTIFIER",tkn.row,tkn.col);
		}

}
void assignStat(){
	if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.type,"IDENTIFIER")==0)
		{
			if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,"=")==0)
			{
				if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.type,"IDENTIFIER")==0||strcmp(tkn.type,"NUMBER")==0)
				{
					if (((tkn = getNextToken(f1)).row != -1)&&strcmp(tkn.lexeme,";")==0&&(tkn.row!=-1))
						return;
					else
						error(";",tkn.row,tkn.col);
				}
				else
						error("IDENTIFIER OR NUMBER",tkn.row,tkn.col);
			}
			else
						error("=",tkn.row,tkn.col);
		}
		else
						error("IDENTIFIER",tkn.row,tkn.col);


}
int main(){
	f1= fopen("Input.c", "r");
	program();


}
