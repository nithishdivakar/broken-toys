#include "Blob.h"
#include "Utils.h"
#include <stdlib.h>


Blob::Blob():
DATA(NULL),LEN(0)
{
	INFO[0] = 'N';
	INFO[1] = 'U';
	INFO[2] = 'L';
	INFO[3] = 'L';
}

Blob::Blob(void * data, const char* info,uint32_t len):
LEN(len)
{
	int i;
	for(i=0;i<4;i++)
		INFO[i]=info[i];

	DATA = new uint8_t[len];
	//Deep copy
	for( i=0;i<len;i++)
		DATA[i] = ((uint8_t *)data)[i];
}

Blob::Blob(const Blob &B){
	int i;
	for(i=0;i<4;i++)
		INFO[i]=B.INFO[i];

	LEN  = B.LEN;
	DATA = new uint8_t [LEN];
	//Deep copy
	for( i=0;i<LEN;i++)
		DATA[i] = B.DATA[i];
}



bool            Blob::operator!=(const Blob & B){
	return ~(this->operator==(B));
}

bool            Blob::operator==(const Blob & B){
	int i;
	if(LEN != B.LEN) return false;
	for(i = 0;i<LEN;i++){
		if(DATA[i]!= B.DATA[i])
			return false;
	}
	return true;
}

uint8_t * Blob::getData(){
	return DATA;
}

uint32_t    Blob::getLen(){
	return LEN;
}

const char *    Blob::getInfo(){
	return INFO;
}

#include<stdio.h>
bool Blob::print(){
	for(int i=0;i<LEN;i++){
		printf("%c",DATA[i]);
	}
	return true;
}
