//#include<ext/rb_tree>
//

#include <set>
#include<bits/stl_tree.h>
#include "shorts.h"

int main(){
	int a = 10;
/*
typename _Compare = std::less<int>;
typename _Alloc = std::allocator<int>;
typedef typename _Alloc::value_type  _Alloc_value_type;
typedef int     key_type;
typedef int     value_type;
typedef _Compare key_compare;
typedef _Compare value_compare;
typedef _Alloc   allocator_type;
*/
typedef std::_Rb_tree<int, int, std::_Identity<int>,std::less<int> > rb_tree;

	rb_tree M;
	FOR(i,0,10){
		M._M_insert_unique(i);
	}
	PRINT(a);
	return 0;
	
}
