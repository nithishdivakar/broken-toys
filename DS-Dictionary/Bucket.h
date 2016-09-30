#ifndef __BUCKET__
#define __BUCKET__


#include "Record.h"
#include "Utils.h"



class Bucket{
private:
	uint32_t local_depth;
	Record       R[Bucket_SIZE];
	bool         occupied[Bucket_SIZE];
	uint32_t getRecordPosition(uint32_t hash);
	uint32_t next;
public:
	     Bucket();
	     Bucket(uint32_t depth);
	bool insert(Record & Rec, uint32_t hash);
	bool remove(Record & Rec, uint32_t hash);
	bool isFull();
	uint32_t getLocalDepth();
	bool getRecord(uint32_t i,Record & Rr);
	bool print();
};

#endif
