
#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__
#define COMPARE(_op_)                                           \
bool operator _op_ (const SmartPointer& o) const {              \
    return mPointer _op_ o.mPointer;                            \
}                                                               \
bool operator _op_ (const T* o) const {                         \
    return mPointer _op_ o;                                     \
} 


class RefBase {
public:
	RefBase() : mCount(0) { }

	void incRefCount() { mCount++; }
	int decRefCount() { return --mCount; }

	int getRefCount() { return mCount; }
private:
	int mCount;
};

template <typename T> 
class SmartPointer {
public:
	SmartPointer() :mPointer(nullptr),ref(nullptr) { 
		ref = new RefBase();
		if (mPointer) 
			ref->incRefCount();
		std::cout << "create unkown smart pointer." << std::endl; 
	}
	SmartPointer(T *p) :mPointer(p), ref(nullptr) {
		ref = new RefBase();
		if (mPointer)
			ref->incRefCount();
		std::cout << "create smart pointer at " << static_cast<const void*>(p) << std::endl;
	}
	SmartPointer(const SmartPointer &other) :mPointer(other.mPointer),ref(other.ref) {
		if (mPointer)
			ref->incRefCount();
		std::cout << "Copy smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
	}                
	SmartPointer &operator = (const SmartPointer &other) {		
		if (this == &other) 
			return *this;
		if (ref->decRefCount() == 0) {
			if (mPointer) {
				delete mPointer;
				mPointer = nullptr;
			}
			if (ref) {
				delete ref;
				ref = nullptr;
			}
		}
		mPointer = other.mPointer;
		ref = other.ref;
		ref->incRefCount();
		std::cout << "Assign smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
		return *this;
	}
	~SmartPointer() {		
		if (ref->decRefCount() == 0) {
			std::cout << "release smart pointer at " << static_cast<const void*>(mPointer) << std::endl;
			if (mPointer) {
				delete mPointer;
				mPointer = nullptr;
			}			
			if (ref) {
				delete ref;
				ref = nullptr;
			}			
		}
	}
	T&  operator* () const { return *mPointer; }
	T* operator-> () const { return mPointer; }
	COMPARE(== );
	COMPARE(!= );
	int getRefCount() {
		return ref->getRefCount();
	}
private:
	T *mPointer; 
	RefBase* ref;
};
#endif // __SMARTPOINTER_H__
