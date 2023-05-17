#ifndef NAMESPACE_UTILS_H 
#define NAMESPACE_UTILS_H

#include <cstdio>
#include <iostream>

namespace sdds {
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);	
	void flushkeys();
	bool ValidYesResponse(char ch);
}

#endif