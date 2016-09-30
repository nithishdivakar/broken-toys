#ifndef __BLOB__
#define __BLOB__

#include <cstdint>
class Blob{
private:
	uint8_t * DATA;
	char      INFO[4];
	uint32_t  LEN;

public:
	Blob();
	Blob(void * data, const char* info,uint32_t len);
	Blob(const Blob & B);
	bool            operator==(const Blob &B);
	bool            operator!=(const Blob &B);
	uint8_t       * getData();
	uint32_t        getLen();
	const char *    getInfo();

	bool            print();
};

#endif
