
#include <iostream>
#include "smartpointer.h"
class SomeClass {
public:
	SomeClass() { 
		std::cout << "SomeClass default constructor !" << std::endl; 
	}
	~SomeClass() { 
		std::cout << "SomeClass deconstructor !" << std::endl; 
	}
};

void testcase1(){
	SmartPointer<char> spunkown;
	SmartPointer<char> spnull = NULL;
	SmartPointer<SomeClass> spclass = new SomeClass;
	SmartPointer<const char> spstr = "Hello world!";
}


void testcase2(){
	SmartPointer<SomeClass> spclass1 = new SomeClass;
	std::cout << std::endl;

	spclass1 = spclass1;
	std::cout << std::endl;

	// 创建另一个智能指针，与先前的指针指向同一块内存资源
	SmartPointer<SomeClass> spclassother = spclass1;
	std::cout << std::endl;

	// 先创建智能指针,再用另一个智能指针给已创建好的智能指针赋值
	SmartPointer<SomeClass> spclass2 = new SomeClass;
	std::cout << std::endl;
	spclass2 = spclass1;
	std::cout << std::endl;
}

int main(void){
	testcase2();
	while (1);
	return 0;
}
