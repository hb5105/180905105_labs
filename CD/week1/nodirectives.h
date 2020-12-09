#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *dir[] = {"#include","#define","#if"};
int is_directive(const char *str)
{
	for(int i = 0; i < sizeof(dir)/sizeof(char *); i++) 
	   {
		int len = strlen(dir[i]);
		if(strncmp(str, dir[i], len) == 0)
		  {
			return 1;
		  }
	   }
	return 0;
}
void cleared_directive(FILE *f1)
{
	char buff[30];
	FILE *f2;

    f2 = fopen("output3b.c", "w");
    if(f1 == NULL)
      {
        printf("coul;d not open \n");
      }
	while(fgets(buff, 30, f1) != NULL)
		 {
			if(!is_directive(buff))
			  { 
				fputs(buff, f2);
			  }
	     }
	fclose(f1);
    fclose(f2);
  
}
