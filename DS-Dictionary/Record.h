#ifndef __RECORD__
#define __RECORD__
#include "Blob.h"

class Record{
private:
	Blob Key;
	Blob Value;

public:
	     Record();
	     Record(Blob key, Blob value);
	     Record(const Record & Rec);
	Blob getKey();
	Blob getValue();

	bool print();
};

#endif
