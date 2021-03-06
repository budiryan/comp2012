/*
 * Submit this file.
 * Implement all functions according to Word.h in this file.
 */
#include "Word.h"

Word::Word(string _spelling, string _definition) :
		spelling(_spelling), definition(_definition) {

}

Word::Word(const Word & another) {
	//No dynamic memory, no need for deep-copying
	this->definition = another.definition;
	this->spelling = another.spelling;
}

ostream& operator<<(ostream& os, const Word& word) {
	os << "\"" << word.spelling << "\"" << " means " << "\"" << word.definition
			<< "\"";
	return os;
}

int Word::hashFunction1(string& key) {
	if (!key.length())
		return 0;
	int result = 0;
	for (string::iterator it = key.begin(); it != key.end(); it++) {
		result += *it;
	}
	return result;
}

int Word::hashFunction2(string& key) {
	if (!key.length())
		return 0;
	int result = 0, temp, i = 0, const_multiplier = 1;
	const int hash_const = 27;
	const int limit = 3;
	for (string::iterator it = key.begin(); i < limit; it++, i++) {
		for (int k = 0; k < i; k++)
			const_multiplier *= hash_const;
		temp = const_multiplier * (*it);
		result += temp;
		const_multiplier = 1;
	}
	return result;
}

int Word::hashFunction3(string& key) {
	int temp, i = 0, const_multiplier = 1, result = 0;
	const int hash_const = 37;
	if (!key.length())
		return 0;
	for (string::iterator it = key.begin(); it != key.end(); it++, i++) {
		for (int k = key.length() - 1; k > i; k--)
			const_multiplier *= hash_const;
		temp = const_multiplier * (*it);
		result += temp;
		const_multiplier = 1;
	}
	return result;
}

