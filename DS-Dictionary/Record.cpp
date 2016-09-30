#include "Record.h"

#include"Utils.h"

Record::Record():
Key(),Value()
{
	return ;
}


Record::Record(Blob key, Blob value):
Key(key),Value(value)
{
	return ;
}

Record::Record(const Record & Rec){
	Key   = Rec.Key; //Calls copy constructor
	Value = Rec.Value;
}
Blob Record::getKey(){
	return Key;
}
Blob Record::getValue(){
	return Value;
}

#include<stdio.h>
bool Record::print(){
	printf("\nKey:  ");
	Key.print();
	printf("   Value:   ");
	Value.print();
	return true;
}
