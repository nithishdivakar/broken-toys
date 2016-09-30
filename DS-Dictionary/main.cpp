#include "ExtendableHashTable.h"
#include<stdlib.h>
#include<stdio.h>

#include"Utils.h"

int main(){
	ExtendableHashTable E;
	FILE *F=NULL;

	F = fopen("input.dat","r");
	char s1[30],s2[30];
	for(int i=0;i<20;i++){
		fscanf(F,"%s %s",s1,s2);
		LOG("%s %s\n",s1,s2);
		Blob K((unsigned char*)&s1[0],"STRN",4),V((unsigned char*)&s2[0],"STRN",4);
		E.insert(K,V);
		E.print();
	}
	return 0;
}
