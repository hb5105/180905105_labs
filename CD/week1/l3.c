#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nocomment.h" //removing comments
#include "nodirectives.h" //removing directives
int main()
{
	
	FILE *fi,*fj,*fa,*fb;
	fi=fopen("x.c","r");
	if (fi==NULL)
	{
		printf("cannot open file");
		exit(0);

		/* code */
	}
	fj =nocomment(fi);  //removing comments
	cleared_directive(fj); 
	fa=fopen("output3b.c", "w");//removing directives and now ready for token generation
    //fb = fopen("output_l3final.c", "w");
}