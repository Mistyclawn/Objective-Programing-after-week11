#include <string>
#include <iostream>

#ifndef IOINTERFACE_H
#define IOINTERFACE_H

using namespace std;

class IOInterface;

class IOInterface {

protected:

	void InputValue(int& i) {
		cin >> i;
		cin.ignore();
	}

	void InputValue(std::string& A) {
		getline(cin, A);
	}
};
#endif