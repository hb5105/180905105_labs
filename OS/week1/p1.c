#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char **argv[])
{
	
	
	char c;
	int a=open(argv[1],O_RDONLY);
	
int line_number=0;
	while(read(a,&c,sizeof(c))==1){
		char ca[100000];
		int i=0;
		
		while((c!='\n')&&(c!=EOF))
		{
			ca[i++]=c;
			read(a,&c,sizeof(c));
		}
		ca[i]='\0';
		line_number++;
		
	
	if(strstr(ca,argv[2]))
	{
		printf("line no: %d \t %s\n",line_number ,ca);
	}
	
}
}