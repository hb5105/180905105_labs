#include<stdlib.h>
#include<stdio.h>
#include<string.h>

FILE *fp;
int main(int argc, char const *argv[])
{
	fp=fopen(argv[1],"r");
	FILE* f2= fopen("myfile.c","w+");
	int c;
	c=fgetc(fp);
	int count =0;
	while(c!=EOF)
	{
		count++;
		c=fgetc(fp);
	}
	printf("%d\n",count );
	fseek(fp,-1,SEEK_END);
	int counted=0;
	// while(count>counted)
	// {
	// 	c=fgetc(fp);
	// 	fputc(c,f2);
	// 	counted++;
	// 	fseek(fp,-2,SEEK_CUR);
	// }
	// while((c=fgetc(f2))!=EOF)
	// {
	// 	printf("%c\n",c);;
	// }
	return 0;
}