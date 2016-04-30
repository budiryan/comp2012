
#ifndef INVENTOR_H_
#define INVENTOR_H_

#include <string>
#include <iostream>
using namespace std;

/*
 * Inventor represents a data entry for an inventor.
 * It can be used with the Dictionary class.
 */
class Inventor
{
public:
	/*
	 * Constructor. Initialize all private members.
	 */
	Inventor(string _firstName, string _lastName, string _invention);

	/*
	 * Copy constructor.
	 */
	Inventor(const Inventor& another);

	/*
	 * The hash function for Inventor dictionary entries.
	 * See assignment description page for details.
	 */
	static int hashFunction(string& key);

private:
	string firstName; //the first name of the inventor
	string lastName; //the last name of the inventor
	string invention; //the major invention invented by the inventor

	//friend declaration
    friend ostream& operator<<(ostream& os, const Inventor& inventor);
	/*
	 * Implement the operator<< in the Inventor.cpp file too.
	 * See assignment description for examples.
	 * Hint: you should use "os" instead of "cout".
	 */
};

#endif
