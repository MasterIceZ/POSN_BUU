#include<stdio.h>


int main (){
	char w;
	w = getchar();
	switch(w){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			printf("Vowel");
			break;
		default :
			printf("Alphabet");
	}
	return 0;
}
