#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *f1, *f2;
int main(int argc, char const *argv[])
{
	f1=fopen("input.c","r");
	f2=fopen("myfile.c","w+");
	char c;
	char d;
	c=fgetc(f1);
	while(c!=EOF)
	{
		if (c!='/')
			{
				int a=fputc(c,f2);
				printf("%c",c);
			}
		if (c=='/')
		{		
			d=fgetc(f1);
			if (isalpha(d))
			{
			int x=fputc('/',f2);
			int y=fputc(d,f2);

				/* code */
			}
			if (d=='/')
			{
				while(d!='\n')
					{d=fgetc(f1);}
				
				/* code */
			}
			else if (d=='*')
			{
				char a[2]="*/";
				char cc[3];
				int i=0;
				while(1)
				{
					fgets(cc,3,f1);
					//printf("%s\n",cc );
					if (strcmp(a,cc)==0)
					{	break;
						/* code */
					}
				}
				/* code */
			}
			
			
			/* code */
		}

		c=fgetc(f1);
	}
	return 0;
}