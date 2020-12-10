/*
s->(l)|a
l->slprime
lprime->,slprime()|eps
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int curr = 0; char str[100]; 
void s();
void l(); 
void lprime();

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
	if (str[curr]=='('){
		curr++;
		l();
		if (str[curr]==')'){
		curr++;
		return;
	}
	else invalid();
	}
	else if (str[curr]=='a'){
		curr++;
		return;}
	else invalid();
}
void l(){
	s();
	lprime();
}
void lprime(){
	if (str[curr]==','){
		curr++;
		s();
		lprime();
		return;}

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