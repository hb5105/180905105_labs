#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE* nocomment(FILE *f1)
{ FILE *f2=fopen("outputsl3a.c","w");
	int ca,cb;
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
	return f2;
}