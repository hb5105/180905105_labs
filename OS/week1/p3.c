#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{
    char c = '@';
    double d = 8.44;
    int a = 32;
    int l=7;
    char str[6]="hritik";
    printf("%c\n",c);
    printf("%d\n", c);
    printf("%s\n",str);
    printf("%e\n", d);
    printf("%f\n", d);
    printf("%d \n",a);
    printf("%o\n",a );
    printf("%x\n",a);
    printf("%#x\n",a);
}