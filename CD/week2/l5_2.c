/*s->uvw
u->(s)|asb|d
v->av
w->cw

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int curr = 0; char str[100]; 
void s();
void u(); 
void v(); 
void w();

void invalid() 
{ 
	 	printf("---ERROR!---\n"); 
	 	exit(0); 
} 
void valid() 
{ 
	 	printf("---SUCCESS!----\n"); 	 
	 	exit(0); 
} 
void s(){
	u();
	v();
	w();

}
void u(){
	if (str[curr]=='(')
	{
		curr++;
		s();
		if (str[curr]==')')
		{curr++;return;;
			/* code */
		}
		else invalid();
		/* code */
	}
	else if (str[curr]=='a')
	{
		curr++;
		s();
		 if (str[curr]=='b')
	{ curr++;
		return;

		/* code */
	}
	else invalid();
}
else if (str[curr]=='d')
{
	curr++;
	return;
	/* code */
}
else invalid();
}
void v(){
	if (str[curr]=='a')
		{
			curr++;
			v();
			return;
		}

}
void w(){
	if (str[curr]=='c')
		{
			curr++;
			w();
			return;
		}
}
int main() 
{ 
	 	printf("Enter String: "); 
	 	scanf("%s", str); 
	 	s(); 
	 	if(str[curr] == '$') 
	 	 	valid(); 
	 	else 
	 	 	invalid(); 
} 