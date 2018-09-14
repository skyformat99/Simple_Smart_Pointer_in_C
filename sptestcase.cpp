
#include <iostream>
#include "smartpointer.h"
class SomeClass {
public:
	SomeClass() { 
		std::cout << "SomeClass default constructor !" << std::endl; 
	};
};

void testcase1(){
	SmartPointer<char> spunkown;
	SmartPointer<char> spnull = NULL;
	SmartPointer<SomeClass> spclass = new SomeClass;
	SmartPointer<const char> spstr = "Hello world!";
}

int main(void){
	testcase1();
	while (1);
	return 0;
}
