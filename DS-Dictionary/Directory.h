#ifndef __DIRECTORY__
#define __DIRECTORY__

#include <cstdint>
#include "Bucket.h"
#include "sha1.h"

class Directory{
private:
	uint32_t   global_depth;
	Bucket **  B;
	uint32_t   hashFunction(Record &R);
	bool       directoryGrow();
	bool       splitBucket(uint32_t bucketNo);
public:
	     Directory();
	bool insertRecord(Record & record);
	bool removeRecord(const Blob & Key);
	bool findRecord(const Blob & Key);

	bool print();
};

#endif
