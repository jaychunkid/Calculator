#include"Calculator.h"
#include<iostream>
#include<sstream>
#include<cmath>
using std::endl;
using std::cerr;
using std::istringstream;

extern unsigned NUMBER;
extern unsigned SYMBOL;

void Calculator::counthelp(const Element &e) {
	//栈已满
	if (AStack.Fool()) {
		cerr << "输入算式串超过程序处理能力，程序退出。" << endl;
		abort();
	}
	//栈为空
	if (AStack.Empty()) {
		if (e.getType() == SYMBOL&&e.getSymbol() != '(') {
			cerr << "输入算式串有错，程序退出。" << endl;
			abort();
		}
		else {
			AStack.push(e);
			return;
		}
	}
	//e为数字
	else if (e.getType() == NUMBER) {
		if (AStack.topValue().getType() == NUMBER) {
			cerr << "输入算式串有错，程序退出。" << endl;
			abort();
		}
		else if (AStack.topValue().getSymbol() == '(') {
				AStack.push(e);
				return;
			}
		else {
			Element e1 = AStack.topValue();
			AStack.pop();
			Element e2 = AStack.topValue();
			AStack.pop();
			double result = e2.getNumber();
			switch (e1.getSymbol()) {
			case '+':
				result += e.getNumber(); break;
			case '-':
				result -= e.getNumber(); break;
			case '*':
				result *= e.getNumber(); break;
			case '/':
				result /= e.getNumber(); break;
			case '^':
				result = pow(result, e.getNumber()); break;
			}
			AStack.push(Element(result));
			return;
		}
	}
	//e为字母
	else {
		if (AStack.topValue().getType() == SYMBOL) {
			cerr << "输入算式串有错，程序退出。" << endl;
			abort();
		}
		else if (e.getSymbol() == ')') {
			Element e1 = AStack.topValue();
			AStack.pop();
			if (AStack.topValue().getSymbol() != '(' || !AStack.pop()) {
				cerr << "输入算式串有错，程序退出。" << endl;
				abort();
			}
			counthelp(e1);
		}
		else {
			AStack.push(e);
			return;
		}
	}
}

double Calculator::count(string &str) {
	istringstream is(str);
	string elem;
	while (is >> elem) {
		Element e(elem);
		counthelp(elem);
	}
	if (AStack.getSize() != 1 || AStack.topValue().getType() != NUMBER) {
		cerr << "输入算式串有错，程序退出。" << endl;
		abort();
	}
	else {
		return AStack.topValue().getNumber();
	}
}


