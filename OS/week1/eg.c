#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
char c;
int in,out;
in=open("theory.c",O_RDONLY);
while(read(in,&c,sizeof(c)))
{
	write(1,&c,sizeof(c));
}
}