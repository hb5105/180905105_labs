#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f1,*f2;
	char ca,cb;


	f1=fopen("x.c","r");
	if (f1==NULL)
	{
		printf("cannot open file");
		exit(0);

		/* code */
	}
	f2=fopen("outputs1.c","w");
	ca=getc(f1);
	
	while(ca!=EOF)
	{
		if (ca==' '||ca=='	')
		{
			putc(' ',f2);

			while(ca==' '||ca=='	')
				ca=getc(f1);
			/* code */
		}
		if (ca=='/')
		{
			
			cb=getc(f1);
			if (cb=='/')
				{
				while(ca!='\n')
					ca=getc(f1);

				/* code */
				}
			else if (cb=='*')
				{
					do{
						while(ca!='*')
							ca=getc(f1);
						ca=getc(f1);
					}while(ca!='/');
				/* code */
				}
			else
			{
				putc(ca,f2);
				putc(cb,f2);
			}
			/* code */
		}
		else putc(ca,f2);
	ca=getc(f1);
	}
	fclose(f1);
	fclose(f2);
	return 0;


}

