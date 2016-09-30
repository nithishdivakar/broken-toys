
#ifndef __UTILS__
#define __UTILS__

#define DEBUG false

#define SIZE 2
#define Bucket_SIZE POW2(SIZE)


#define POW2(k)                 (0x01<<(k))
#define LAST(k,n)               ((k) & ((1<<(n))-1))
#define MID(k,m,n)              LAST((k)>>(m),((n)-(m)))
#define UNSET_K_LSB(n,k)        ((n) & (~(0x01<<(k))-1))

#define MIN(x,y)                ((x)<(y)?(x):(y))
#define MAX(x,y)                ((x)>(y)?(x):(y))
#define CHECK_BIT(var, pos)	(!!((var) & (1 << (pos))))
#define TOGGLE_BIT(var, pos)	((var) ^= (1 << (pos)))
#define SET_BIT(var, pos)	((var) |= (1 << (pos)))
#define CLEAR_BIT(var, pos)	((var) &= (1 << (pos)))


void LOG(const char * format, ...);

#endif
