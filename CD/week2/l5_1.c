/* s-> a|>|(t)
t->stprime
tprime->,stprime|eps
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int curr = 0; 
char str[100]; 
void s();
void t(); 
void tprime();

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
	if(str[curr]=='a')
		{curr++;return;}
	else if(str[curr]=='>')
		{curr++; return;}
	else if(str[curr]=='('){
		curr++;
		t();
		
		if (str[curr]==')')
		{
			curr++;
			return;
			/* code */
		}
		else{invalid();}
	}
	else{invalid();}
} 
void t(){
	s();
	tprime();

}
void tprime(){
	if(str[curr]==',')
		{curr++;
			s();
			tprime();}

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
