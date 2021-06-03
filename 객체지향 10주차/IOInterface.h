#include <string>
#include <iostream>

#ifndef IOINTERFACE_H
#define IOINTERFACE_H

using namespace std;

class IOInterface {

protected:

	string _Name;

	void InputValue(int& i) {
		cin >> i;
		cin.ignore();
	}

	void InputValue(std::string& A) {
		getline(cin, A);
	}

	virtual string GetName() = 0;
};
#endif