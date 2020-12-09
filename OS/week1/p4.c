#include<stdio.h>
int main(){
    FILE *fp1 = fopen("theory.c","r");
    FILE *fp2 = fopen("f2.txt","w");
    if(fp1 == NULL)
        return 0;
    do{
        char c = fgetc(fp1);
        if(feof(fp1))
            break;
        fputc(c,fp2);
    }while(1);
    fclose(fp1);
    fclose(fp2);
    return(0);
}