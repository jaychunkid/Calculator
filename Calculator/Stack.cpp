#include"Stack.h"

extern unsigned NUMBER;
extern unsigned SYMBOL;

bool ElemStack::pop() {
	if (!Empty()) {
		--curSize;
		return true;
	}
	else return false;
}

bool ElemStack::push(const Element &e) {
	if (curSize == defaultSize)
		return false;
	else {
		elems[curSize++] = e;
		return true;
	}
}