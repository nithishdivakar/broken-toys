#ifndef __EXTENDABLEHASHTABLE__
#define __EXTENDABLEHASHTABLE__

#include"Directory.h"

class ExtendableHashTable{
private:
	Directory  D;

public:
	     ExtendableHashTable();
	bool insert(Blob & Key, Blob & Value);
	bool remove(const Blob & Key);
	bool find(const Blob & Key);

	bool print();
};

#endif
