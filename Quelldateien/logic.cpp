
#include "../Headerdateien/m_vector.h"
#include "../Headerdateien/logic.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

bool check_input(const std::string& inp) {
	std::string::const_reverse_iterator rit = inp.rbegin();
	std::string postfix = ".txt";
	int i = 3; 
	while (rit != inp.rend() && i >= 0) {
		if (*rit != postfix[i]) {
			return false;
		}
		--i;
		++rit;
	}
	if (i >= 0) {
		return false;
	}
	return true;
}