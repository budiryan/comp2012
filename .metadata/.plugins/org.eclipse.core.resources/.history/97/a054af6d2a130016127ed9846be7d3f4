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

bool isPrime(int n) {
	//to determine whether it is a prime number or not
	int flag = 0;
	for (int i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return true;
	else
		return false;
}

int Inventor :: hashFunction(string& key) {
	unsigned int i = 0;
	int result = 0;
	//search the nth prime number
	while (i <= key.length()) {
		result++;
		if (isPrime(result))
			i++;
	}
	return result;
}

ostream& operator<<(ostream& os, const Inventor& inventor) {
	os << inventor.firstName << " " << inventor.lastName << " invented "
			<< inventor.invention << "!";
	return os;
}

