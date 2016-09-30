#include <iostream>
#include "shorts.h"
using namespace std;

int main(){
	int *A,n;
	cin >>n;
	A = new int[n*n];
	FOR(i,0,n*n){
		A[i] = i;
	}
	return 0;
}
