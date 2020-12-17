#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *f1, *f2;
int main(int argc, char const *argv[])
{char cc[2000];
	f1=fopen("input.c","r");
fgets(cc,3,f1);
printf("%s-",cc );
}