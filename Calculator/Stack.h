#ifndef STACK_H
#define STACK_H
#include"Element.h"

class ElemStack {
	constexpr static size_t defaultSize = 100;
	Element elems[defaultSize];
	size_t curSize = 0;
public:
	ElemStack() = default;
	bool pop();
	bool push(const Element &e);

	size_t getSize()const {
		return curSize;
	}

	Element& topValue() {
		return elems[curSize-1];
	}

	void clear() {
		curSize = 0;
	}

	bool Empty() {
		return !curSize;
	}
	
	bool Fool() {
		return curSize == defaultSize;
	}
};
#endif STACK_H