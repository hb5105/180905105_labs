#include<stdio.h>
#include<stdlib.h>
void printkey(FILE *f){

	 const char *key[]={"int","char"};
	int c=getc(f);
	
	while (c!=EOF)
	{
		char buff[30];
		int j=-1;
		if (isalpha(c))
		{
			
			/* code */
		
			while(c!=EOF && isalpha(c))
			{
				buff[++j]=c;
				c=getc(f);
				//printf("%d\n",c);

			}
			buff[++j]='\0';
			//printf("%s\n",buff );
			for(int i=0;i<sizeof(key)/sizeof(char *);i++)
			{
				//printf("%s\n",buff );
				//printf("check\n");
				if ((strcmp(key[i],buff))==0)
				{
					for (j = 0; buff[j]!='\0'; j++)
					 {
   					if(buff[j] >= 'a' && buff[j] <= 'z') 
   					{
      					buff[j] = buff[j] -32;
   }
}
printf("%s\n",buff);
					/* code */
				}
			}

		
	}
	c=getc(f);
}
}
int main(){
	FILE *f1;


	f1=fopen("x.c","r");
	if (f1==NULL)
	{
		printf("cannot open file");
		exit(0);

		/* code */
	}
	printkey(f1);


}