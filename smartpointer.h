
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
		if (mPointer) 
			ref.incRefCount();
	}
	SmartPointer(const SmartPointer &other) :mPointer(other.mPointer) {
		std::cout << "Copy smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
		if (mPointer) 
			ref.incRefCount();
	}                
	SmartPointer &operator = (const SmartPointer &other) {		
		if (this == &other) 
			return *this;
		if (mPointer) {
			delete mPointer;
			mPointer = nullptr;
		}
		mPointer = other.mPointer;
		std::cout << "Assign smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
		return *this;
	}
	~SmartPointer() {		
		if (mPointer&& ref.decRefCount() == 0) {
			delete mPointer;
			mPointer = nullptr;
			std::cout << "release smart pointer at " << static_cast<const void*>(mPointer) << std::endl;
		}
	}
	int getRefCount() {
		return ref.getRefCount();
	}
private:
	T *mPointer; 
	class RefBase {
	public:
		RefBase() : mCount(0) { }

		void incRefCount() { mCount++; }
		int decRefCount() { return --mCount; }

		int getRefCount() { return mCount; }
		virtual ~RefBase() { }
	private:
		int mCount;
	};
	RefBase ref;
};
#endif // __SMARTPOINTER_H__
