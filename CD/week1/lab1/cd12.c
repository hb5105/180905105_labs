#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fptr1,*fptr2;
char srcfn[100],destfn[100];
printf("enter src filename");
scanf("%s",srcfn);
printf("enter dest filename");
scanf("%s",destfn);
fptr1=fopen(srcfn,"r");
if(fptr1==NULL){printf("no");}
fptr2=fopen(destfn,"w+");
char c=fgetc(fptr1);
printf("%c\n",c);
int count=0;
while(c!=EOF)
{
  count++;
  c=fgetc(fptr1);
  
 }
 printf("%d\n ",count);
 int counted=0;
fseek(fptr1,-1,SEEK_CUR);


 while(counted<=count)
 {  
   c=fgetc(fptr1);
   fseek(fptr1,-2,SEEK_CUR);
   printf("%c\t",c);
   fputc(c,fptr2);
   counted++;
   
 }
 printf("done");
 }
