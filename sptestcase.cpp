
#include <iostream>
#include "smartpointer.h"
class SomeClass {
public:
	SomeClass() {std::cout << "SomeClass default constructor !" << std::endl; }
	~SomeClass() {std::cout << "SomeClass deconstructor !" << std::endl; }
	void func() { std::cout << "SomeClass func()" << std::endl; }
};
class OtherClass{
public:
	OtherClass() { std::cout << "OtherClass default constructor !" << std::endl; };
	~OtherClass() { std::cout << "OtherClass deconstructor !" << std::endl; };
	void foo() { std::cout << "OtherClass foo()" << std::endl; }
};

void testcase1(){
	std::cout << "######### testcase_1 #########" << std::endl;
	SmartPointer<char> spunkown;
	SmartPointer<char> spnull = nullptr;
	SmartPointer<SomeClass> spclass = new SomeClass;
	SmartPointer<int> spstr=new int(66666);
	std::cout << "==========================\n";
}


void testcase2(){
	std::cout << "\n\n######### testcase_2 #########" << std::endl;
	SmartPointer<SomeClass> spclass1 = new SomeClass;//調用SmartPointer(T *p) :mPointer(p)
	std::cout << std::endl;

	spclass1 = spclass1;
	std::cout << std::endl;

	// 创建另一个智能指针，与先前的指针指向同一块内存资源
	SmartPointer<SomeClass> spclassother = spclass1;//调用SmartPointer(const SmartPointer &other) :mPointer(other.mPointer)
	std::cout << std::endl;

	// 先创建智能指针,再用另一个智能指针给已创建好的智能指针赋值
	SmartPointer<SomeClass> spclass2 = new SomeClass;
	std::cout << std::endl;
	std::cout << "==========================\n";
}

void testcase3(){
	std::cout << "\n\n######### testcase_3 #########" << std::endl;
	SomeClass *pSomeClass = new SomeClass(); //1
	SmartPointer<SomeClass> spOuter = pSomeClass;
	std::cout << "SomeClass Ref Count (" << spOuter.getRefCount() << ") outer 1." << std::endl;
	{ // inner 语句块
		SmartPointer<SomeClass> spInner = spOuter;
		std::cout << "SomeClass Ref Count (" << spOuter.getRefCount() << ") inner." << std::endl;
	}
	std::cout << "SomeClass Ref Count (" << spOuter.getRefCount() << ") outer 2." << std::endl;
	// delete pSomeClass ; 不需要也不能执行delete操作!

	std::cout << "new another SomeClass class for spOuter." << std::endl;
	SmartPointer<SomeClass> spOuter2 = new SomeClass();
	spOuter = spOuter2;// 1处new出来的SomeClass将会被自动释放  
	std::cout << "==========================\n";
}
// 解引用测试
void testcase4_1(void){
	std::cout << "\n\n######### testcase_4_1 #########" << std::endl;
	SmartPointer<SomeClass> spsomeclass = new SomeClass();
	(*spsomeclass).func();
	spsomeclass->func();
	std::cout << "==========================\n" ;
}

// 判空与比较测试
void testcase4_2(void){
	std::cout << "\n\n######### testcase_4_2 #########" << std::endl;
	SomeClass *psomeclass = new SomeClass();
	SmartPointer<SomeClass> spsomeclass = psomeclass;

	SmartPointer<OtherClass> spotherclass = new OtherClass();
	SmartPointer<OtherClass> spotherclass2 = spotherclass;

	if (spsomeclass == nullptr) std::cout << "spsomeclass is NULL pointer" << std::endl;
	if (spotherclass != nullptr) std::cout << "spotherclass is not NULL pointer" << std::endl;
	if (spsomeclass == psomeclass)
		std::cout << "spsomeclass and psomeclass are same pointer" << std::endl;
	if (spsomeclass != psomeclass)
		std::cout << "spsomeclass and psomeclass are not same pointer" << std::endl;
	//     if (spsomeclass != spotherclass) // ERROR !
	//        std::cout<< "spsomeclass and spotherclass are not same pointer" << std::endl;
	//     if (spsomeclass == spotherclass) // ERROR !
	//        std::cout<< "spsomeclass and spotherclass are same pointer" << std::endl;
	if (spotherclass == spotherclass2) std::cout << "spotherclass and spotherclass2 are same pointer" << std::endl;
	if (spotherclass != spotherclass2) std::cout << "spotherclass and spotherclass2 are not same pointer" << std::endl;
	std::cout << "==========================" << std::endl;

}
int main(){
	testcase1();
	testcase2();
	testcase3();
	testcase4_1();
	testcase4_2();
	return 0;
}
