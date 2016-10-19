#ifndef ElEMENT_H
#define ELEMENT_H
#include<string>
using std::string;



class Element {
	char symbol = ' ';
	double number = 0.0;
	unsigned type = 0;
public:
	Element() = default;
	Element(const string &str);
	Element(const double &number);
	Element(const char &symbol);
	void set(const string &str);
	
	double getNumber()const {
		return number;
	}

	char getSymbol()const {
		return symbol;
	}

	int getType()const {
		return type;
	}
};
#endif