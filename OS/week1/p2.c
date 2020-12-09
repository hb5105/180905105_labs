#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
	
	int i=2;
	char c;
	int a1=atoi(argv[1]);
	
	printf("%d files entered\n",a1);
	a1=a1+2;
	int z=0;
	printf("enter any key\n");

	char c2;
	int o=read(0,&c2,1);
	printf("enter no of lines");
	int b;
	scanf("%d",&b);
	printf("%s\n",argv[i] );
	while(i<=a1){
		
		int out=open(argv[i++],O_RDONLY);

		
	while((read(out,&c,sizeof(c))==1))
	{
		/* code */
	int co=0;
		char ca[100000];
		int k=0;
		
		while((c!='\n')&&(c!=EOF))
		{
			ca[k++]=c;
			read(out,&c,sizeof(c));
		}
		ca[k]='\0';

		printf("%s\n",ca);
		z+=1;
		if (z%b==0)
		{
			printf("enter any key\n");

			o=read(0,&c2,1);
			/* code */
		}

	
}
	
}}