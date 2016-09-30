#include "ExtendableHashTable.h"

ExtendableHashTable::ExtendableHashTable():
D()
{
	return ;
}
bool ExtendableHashTable::insert(Blob & Key, Blob & Value){
	Record R(Key,Value);
	return D.insertRecord(R);
}
bool ExtendableHashTable::remove(const Blob & Key){
	return D.removeRecord(Key);
}
bool ExtendableHashTable::find(const Blob & Key){
	return D.findRecord(Key);
}

bool ExtendableHashTable::print(){
	D.print();
	return true;
}
