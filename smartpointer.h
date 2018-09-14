﻿
#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__

template <typename T> 
class SmartPointer {
public:
	SmartPointer() :mPointer(nullptr) { 
		std::cout << "create unkown smart pointer." << std::endl; 
	}
	SmartPointer(T *p) :mPointer(p) { 
		std::cout << "create smart pointer at " << static_cast<const void*>(p) << std::endl; 
	}
	~SmartPointer() {
		std::cout << "release smart pointer at " << static_cast<const void*>(mPointer) << std::endl;
		if (mPointer != nullptr) {
			delete mPointer;
			mPointer = nullptr;
		}
	}
private:
	T *mPointer; 
};
#endif // __SMARTPOINTER_H__