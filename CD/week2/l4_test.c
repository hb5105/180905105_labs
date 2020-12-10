#include <string.h>
#define YY_DECL struct token *yylex(void)
#define TABLE_SIZE 2048


enum 
{ 
	LT, GT, LTEQ, GTEQ, NOTEQ, EQEQ,
	IDENTIFIER, KEYWORD, NUMBER, SPECIAL, ARITHMETIC,
	LB, RB, LC, RC, ASSIGNMENT, LOGICAL 
};

enum 
{
	LOCAL_SCOPE,
	GLOBAL_SCOPE,
	ID,
	FUNC
};

struct token
{
	char lexeme[64],return_type[30],data_type[30];
	int row,col,index,type,id_type,scope,size_occ;
};

struct Node
{
	struct token *tkn;
	struct Node *next;
};

struct Node *table[TABLE_SIZE];
int curlyBrackets=0;
char DTbuf[64]="";
int elementcount=1;

int DTsize(char *str)
{
	if(!strcmp(str, "int"))
	  {
		return sizeof(int);
	  }
	else if(!strcmp(str, "float"))
		   {
			return sizeof(float);
		   }
	else if(!strcmp(str, "char"))
		   {
			return sizeof(char);
		   }
	else if(!strcmp(str, "double"))
		  {
			return sizeof(double);
		  }
	return 0;
}

int hash(char *str)
{
	int sum=0;
	int x=10141;
	for(int i=0;str[i]!='\0';i++)
	   {
	   	sum=(sum+(str[i]*x)%TABLE_SIZE)%TABLE_SIZE;
	   	x=(x*10141)%TABLE_SIZE;
	   }
	return sum;
}

void display_table()
{
	printf("Name\tType\tSize\tScope\tType\tIndex\tReturnType\n");
	for(int i=0;i<TABLE_SIZE;i++)
	   {
	   	for(struct Node *ptr=table[i];ptr;ptr=ptr->next)
	   	   {
	   	   	printf("%s\t%s\t%d\t%s\t%s\t%d\t%s\n",ptr->tkn->lexeme
	   	   										 ,ptr->tkn->id_type!=FUNC ? ptr->tkn->data_type:""
	   	   										 ,ptr->tkn->id_type!=FUNC ? DTsize(ptr->tkn->data_type):0
	   	   										 ,ptr->tkn->scope==LOCAL_SCOPE ? "L":"G"
	   	   										 ,ptr->tkn->id_type==FUNC ? "FUNC":"ID"
	   	   										 ,ptr->tkn->index
	   	   										 ,ptr->tkn->id_type==FUNC ? ptr->tkn->data_type:"");
	   	   }
	   }
}

int search(char *str)
{
	int hashvalue=hash(str);
	struct Node *ptr;
	for(ptr=table[hashvalue];ptr;ptr=ptr->next)
	   {
	   	if(!strcmp(ptr->tkn->lexeme,str))
	   	  {
	   	  	return 1;
	   	  }
	   }
	return 0;
}

int insert(struct token *tkn)
{
	int hashvalue=hash(tkn->lexeme);
	if(search(tkn->lexeme))
	  {
	  	return hashvalue;
	  }
	tkn->scope=(curlyBrackets ? LOCAL_SCOPE:GLOBAL_SCOPE);
	strcpy(tkn->data_type,DTbuf);
	struct Node *temp=malloc(sizeof(struct Node));
	temp->tkn=tkn;
	temp->next=table[hashvalue];
	table[hashvalue]=temp;
	return hashvalue;
}