#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   char filename[100],c;
   int noline=0,count=0;
   printf("enter the filename");
   scanf("%s",filename);
   FILE *fp=fopen(filename,"r");
   if(fp==NULL)
   {
	   printf("doesn't exist");
   }
   c=fgetc(fp);
   while(c!=EOF)
   {
     if(c=='\n')
	 {
	   noline++;
	   }
	   count++;
	   c=fgetc(fp);
	}
	printf("number of lines=%d\n size=%d",noline,count);
	}