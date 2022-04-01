#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* retourne_itoa(int chiffre){
	char *retourne=NULL;
	retourne=malloc(sizeof(char));
	if(chiffre==0)
		return "0\0";
	for(int i=0;chiffre!=0;i++){
		int rem=chiffre%10;
		retourne[i] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		chiffre/=10;
	}
	return retourne;
}
