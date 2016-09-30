
#include "Utils.h"

#include <stdarg.h>
#include <stdio.h>


void LOG(const char * format, ...){
	va_list args;
	if(DEBUG){
		fprintf(stderr, "LOG:  ");
		va_start(args, format);
		vfprintf(stderr, format, args);
		va_end( args);
		fprintf(stderr, "\n");
		fflush(stdout);
	}
}
