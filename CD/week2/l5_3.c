/*s->aAcBe
A->bAprime
aprime->baprime|eps
b->d*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int curr = 0; char str[100]; 
void s();
void a(); 
void aprime(); 
void b(); 
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
	if (str[curr]=='a')
	{
		curr++;
		a();
		if (str[curr]=='c')
			{
				curr++;
				b();
				if (str[curr]=='e')
				{
					curr++;
					return;
				}
				else invalid();
			}
			else invalid();

	}
	else invalid();
}
void a(){
	if (str[curr]=='b'){
		curr++;
		aprime();
	}

}
void aprime(){
	if (str[curr]=='b'){
		curr++;
		aprime();
	}

} 
void b(){
	if (str[curr]=='d'){
		curr++;
		return;
	}
	else invalid();
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