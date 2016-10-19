#ifndef CALCULATOR_H
#define CALCULATOR_H
#include"Stack.h"

class Calculator {
	ElemStack AStack;
	void counthelp(const Element &e);
public:
	Calculator() = default;
	double count(string &str);
	
	void clear() {
		AStack.clear();
	}
};
#endif



