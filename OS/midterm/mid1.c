#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<sys/types.h>
#include<string.h>
DIR *fd;
int main(){

	struct dirent* entry;
	// while(entry=readdir()){

	// }
char c[256];
char d[256];
char x[256];
struct stat statbuff;
printf("%s",getcwd(c,sizeof(c)));
fd=opendir(c);
while((entry=readdir(fd))!=NULL)
{
	lstat(entry->d_name,&statbuff);
	char a[2];
	char *xx;
	xx=entry->d_name;
	a[0]=xx[strlen(entry->d_name)-2];
	a[1]=xx[strlen(entry->d_name)-1];

	if (strcmp(".c",a)==0)
	{
		/* code */
		printf("\n%s\n",entry->d_name);
	}

}
printf("enter filename\n");
scanf("%s",x);
lstat(x,&statbuff);
FILE* f1;

f1=chmod(x,S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IROTH);
            
}


