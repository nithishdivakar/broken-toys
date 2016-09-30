#include "Bucket.h"

#include "Utils.h"


Bucket::Bucket():
local_depth(1),
next(0)
{
	int i;
	for ( i=0;i<Bucket_SIZE;i++)
		occupied[i]=false;
	return ;
}

Bucket::Bucket(uint32_t depth):
local_depth(depth),
next(0)
{

}
bool Bucket::insert(Record & Rec, uint32_t hash){
	/*uint32_t position=0;
	position   = getRecordPosition(hash);
	if(occupied[position] == true){
		if(R[position].getKey() != Rec.getKey()){
			return false;
		}
	}

	R[position] = Rec; //calls copy constructor;

	occupied[position] = true;
	return true;
	*/
	if(next == Bucket_SIZE)
		return false;
	R[next] = Rec;
	next = next+1;
	return true;
}
bool Bucket::remove(Record & Rec, uint32_t hash){
/*	uint32_t position=0;
	position   = getRecordPosition(hash);
	
	if(occupied[position] == true){
		if(R[position].getKey() != Rec.getKey()){
			return false;
		}
		occupied[position] = false;
		return true;
	}
	return false;
*/
	int k = -1;
	for(int i=0;i<next;i++){
		if(R[i].getKey() == Rec.getKey()){
			k = i;
			break;
		}
	}
	if( k == -1) return false;
	for(int i=k;i<next-1;i++)
		R[i] = R[i+1];
	next = next - 1;
	return true;
}
bool Bucket::isFull(){
	for(int i =0;i<Bucket_SIZE;i++){
		if(occupied[i]==false)
			return false;
	}
	return true;
}
uint32_t Bucket::getLocalDepth(){
	return local_depth;
}
bool  Bucket::getRecord(uint32_t index, Record & Rr){
	if(index >=next)
		return false;
	Rr = R[index];
	return true;
}

bool Bucket::print(){
	for(int i =0;i<next;i++){
		R[i].print();
	}
	return true;
}
uint32_t Bucket::getRecordPosition(uint32_t hash){
	return MID(hash,local_depth,local_depth+SIZE);
}
