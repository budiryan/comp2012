/*
 * Submit this file.
 * Implement all functions according to Inventor.h in this file.
 */

#include "Inventor.h"

Inventor::Inventor(string _firstName, string _lastName, string _invention) :
		firstName(_firstName), lastName(_lastName), invention(_invention) {

}

Inventor::Inventor(const Inventor& another) :
		firstName(another.firstName), lastName(another.lastName), invention(
				another.invention) {
//No dynamic variables, no need for deep copying
}

int Inventor::hashFunction(string& key) {
	unsigned int i = 0;
	int result = 0, flag = 0;
	//search the nth prime number
	while (i <= key.length()) {
		result++;
		for (int k = 2; k <= result / 2; ++k) {
			if (result % k == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			i++;
		flag = 0;
	}
	return result;
}

ostream& operator<<(ostream& os, const Inventor& inventor) {
	os << inventor.firstName << " " << inventor.lastName << " invented "
			<< inventor.invention << "!";
	return os;
}

