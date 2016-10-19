#include"Calculator.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main() {
	Calculator ACalculator;
	string str;
	cout << "ÊäÈëÊµÀý£º( 5 * 3 ) ^ 2 + 2" << endl;
	while (getline(cin, str)) {
		cout << ACalculator.count(str) << endl;
		ACalculator.clear();
	}
	return 0;
}