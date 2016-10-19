#include"Element.h"
#include<cctype>
using std::to_string;

unsigned NUMBER = 0;
unsigned SYMBOL = 1;

Element::Element(const string &str) {
	set(str);
}

Element::Element(const double &number) {
	type = NUMBER;
	this->number = number;
}

Element::Element(const char &symbol) {
	type = SYMBOL;
	this->symbol = symbol;
}

void Element::set(const string &str) {
	if (isdigit(str.front())) {
		type = NUMBER;
		number = stod(str);
	}
	else {
		type = SYMBOL;
		symbol = str.front();
	}
}