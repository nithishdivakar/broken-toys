#include<stdlib.h>

#include "Directory.h"
#include "Utils.h"

Directory::Directory():
	global_depth(1)
{
	B     = new Bucket*[2];
	B[0]  = new Bucket();
	B[1]  = new Bucket();
	return ;
}

bool Directory::insertRecord(Record & record){
	uint32_t hash = hashFunction(record);
	while(true){
		int bucketNo = hash >>(32-global_depth);//MID(hash,0,global_depth);
		LOG(" [%d ] ",bucketNo); 
		if(B[bucketNo]->insert(record,hash)==true){
			break;
		}else{
			//if(B[bucketNo].isFull() == true){
			if(splitBucket(bucketNo)==true){
				LOG("D");
				continue;
			}else{
				return false;
				//only possible failed insertion.
			}
		}
	}
	return true;
}
bool Directory::removeRecord(const Blob & Key){

	return true;
}

bool Directory::findRecord(const Blob & Key){

	return true;
}

uint32_t Directory::hashFunction( Record &R){
	unsigned char hash[20];
	Blob  B = R.getKey();
	sha1::calc(B.getData(),B.getLen() ,hash);

	/* sha1 has is 20*8 bytes long. But our hash values are only 32 bits
	 * So xoring all the bits of sha1 to get final answer
	 */
	uint32_t * P = (uint32_t *)&hash[0];
	uint32_t X = *P;
	for(int i=1;i<5;i++)
		X = X ^ P[i];
	return X;
}

bool        Directory::splitBucket(uint32_t bucketNo){
	if(B[bucketNo]->getLocalDepth()==global_depth){
		if(directoryGrow()==false){
			return false;
		}
		bucketNo = bucketNo*2;
	}
	Bucket *B0,*B1,*BOrig;
	BOrig = B[bucketNo];
	B0 = new Bucket(B[bucketNo]->getLocalDepth()+1);
	B1 = new Bucket(B[bucketNo]->getLocalDepth()+1);
	uint32_t diff = global_depth-B[bucketNo]->getLocalDepth();
	uint32_t b0indexstart = bucketNo &( ~((0x01<<diff)-1));
	LOG("%x",( ~((0x01<<diff)-1)));
	//UNSET_K_LSB(bucketNo,diff-1);
	uint32_t b1indexend   = b0indexstart+ ((0x01<<diff)-1);
	LOG("--%d %d",bucketNo,diff);
	LOG("--%d",b0indexstart);
	LOG("--%d",b1indexend);
	while(b0indexstart < b1indexend){
		B[b0indexstart] = B0;
		B[b1indexend  ] = B1;
		b0indexstart = b0indexstart+1;
		b1indexend   = b1indexend  -1;
	}
	for(int i=0;i<Bucket_SIZE;i++){
		Record R;
		if(BOrig->getRecord(i,R)){
			insertRecord(R);
		}
	}
	delete BOrig;
	return true;
}

bool       Directory::directoryGrow(){
	Bucket **BTemp = NULL;
	if(global_depth == 30) return false;

	global_depth = global_depth + 1;
	BTemp = new Bucket*[POW2(global_depth)];
	for(int i=POW2(global_depth)-1;i>=0;i--){
		BTemp[i] = B[i/2];
	}
	delete[] B;
	B = BTemp;
	return true;
}


#include<stdio.h>
bool Directory::print(){
	printf("\nGlobal Depth %d",global_depth);
	for(int i = 0;i<POW2(global_depth);i++){
		printf("\nBucket %d Address %p",i,B[i]);
		B[i]->print();
	}
	printf("\n");
	return true;
}
