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
	//ջ����
	if (AStack.Fool()) {
		cerr << "������ʽ�����������������������˳���" << endl;
		abort();
	}
	//ջΪ��
	if (AStack.Empty()) {
		if (e.getType() == SYMBOL&&e.getSymbol() != '(') {
			cerr << "������ʽ���д������˳���" << endl;
			abort();
		}
		else {
			AStack.push(e);
			return;
		}
	}
	//eΪ����
	else if (e.getType() == NUMBER) {
		if (AStack.topValue().getType() == NUMBER) {
			cerr << "������ʽ���д������˳���" << endl;
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
	//eΪ��ĸ
	else {
		if (AStack.topValue().getType() == SYMBOL) {
			cerr << "������ʽ���д������˳���" << endl;
			abort();
		}
		else if (e.getSymbol() == ')') {
			Element e1 = AStack.topValue();
			AStack.pop();
			if (AStack.topValue().getSymbol() != '(' || !AStack.pop()) {
				cerr << "������ʽ���д������˳���" << endl;
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
		cerr << "������ʽ���д������˳���" << endl;
		abort();
	}
	else {
		return AStack.topValue().getNumber();
	}
}


