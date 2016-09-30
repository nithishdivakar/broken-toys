#ifndef __SHORTS__
#define __SHORTS__

#include <vector>
#include <algorithm>
#include<cstdint>

typedef std::vector< int > vi;
typedef std::vector< vi > vvi;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define trav(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end()).
#define cpresent(c,x) (find(all(c),x) != (c).end())


#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PRINT(a) printf("%d ",(a))
#endif
