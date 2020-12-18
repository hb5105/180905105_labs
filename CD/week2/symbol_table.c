#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lex.c"

int main()
{
FILE *f1=preproccess("l4.c");
	if(f1==NULL)
	{
	  	printf("Error! File cannot be opened!\n");
	  	return 0;
	}


	struct token tkn;
	struct sttable st[10][100];
	int flag=0,i=0,j=0;
	int tabsz[10];
	char w[25];
	w[0]='\0';
	while((tkn=getNextToken(f1)).row!=-1)
	{
		printf("<%s, %d, %d, %s>\n",tkn.lexeme,tkn.row,tkn.col,tkn.type);
		if(strcmp(tkn.type,"KEYWORD")==0)
		{
		 	if(isdtype(tkn.lexeme)==1)
		 	{
		 		strcpy(dbuf,tkn.lexeme);
		 	}
		}
		else if(strcmp(tkn.type,"IDENTIFIER")==0)
		{
			strcpy(w,tkn.lexeme);
			tkn=getNextToken(f1);
			printf("<%s, %d, %d, %s>\n",tkn.lexeme,tkn.row,tkn.col,tkn.type);
			if((strcmp(tkn.type,"LB"))==0)
			{
				if(findTable(st[i],w,j)==0)
				{
					ind++;
					st[i][j++]=fillTable(ind,w,dbuf,"func",-1);
				}
			}
			if((strcmp(tkn.type,"LS"))==0)
			{
				if(findTable(st[i],w,j)==0)
				{
					tkn=getNextToken(f1);
					printf("<%s, %d, %d, %s>\n",tkn.lexeme,tkn.row,tkn.col,tkn.type);
					int s=0;
					if(strcmp(tkn.type,"NUMBER")==0)
					{
						s=atoi(tkn.lexeme);
					}
					ind++;
					st[i][j++]=fillTable(ind,w,dbuf,"id",sz(dbuf)*s);
				}
			}
			else
			{
				if(findTable(st[i],w,j)==0)
				{
					ind++;
					st[i][j++]=fillTable(ind,w,dbuf,"id",sz(dbuf));
				}
			}
		}
		else if(strcmp(tkn.type,"LC")==0)
		{
			flag++;
		}
		else if(strcmp(tkn.type,"RC")==0)
		{
			flag--;
			if(flag==0)
			{
				tabsz[i]=j;
				i++;
				j=0;
				ind=0;
			}
		}
	}
	int k=0;
printf("\n\n\nSYMBOL TABLEs  STARTS HERE\n\n");

	for(k=0;k<i;k++)
	{
		printTable(st[k],tabsz[k]);
		printf("______________________________________________\n\n");
	}
    fclose(f1);

}
