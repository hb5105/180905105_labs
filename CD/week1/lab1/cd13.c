#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE* fptr1,*fptr2,*fptr3;
char src1[100],src2[100],dest[100];
printf("enter file name 1");
scanf("%s",src1);
printf("enter file name 2");
scanf("%s",src2);
fptr1=fopen(src1,"r");
fptr2=fopen(src2,"r");
printf("enter dest fn");
scanf("%s",dest);
fptr3=fopen(dest,"w+");
char c1,c2;
c1=fgetc(fptr1);
c2=fgetc(fptr2);
int alt=0;
while(c1 != EOF && c2!=EOF)
{
   if(alt==0)
   {
     while(c1 != '\n')
	 {
	   fputc(c1,fptr3);
	   }
	   fputc('\n',fptr3);
	   alt=1;
    }
	else
	{
	   while( c2 != '\n')
	   {
	     fputc(c2,fptr3);
	    }
		fputc('\n',fptr3);
	   alt=0;
	}
}
while(c1 != EOF)
{
	fputc(c1,fptr3);
	}
	while(c2!= EOF)
	{
		     fputc(c2,fptr3);
			 }
}
