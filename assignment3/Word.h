/*
 * Do NOT submit this file.
 * Do NOT modify this file.
 */

#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iostream>
using namespace std;

/*
 * Word represents a data entry for an English word.
 * It can be used with the Dictionary class.
 */
class Word
{
public:
	/*
	 * Constructor. Initialize all private members.
	 */
	Word(string _spelling, string _definition);

	/*
	 * Copy constructor.
	 */
	Word(const Word& another);

	/*
	 * The hash functions for Inventor dictionary entries.
	 * See assignment description page for details.
	 */
	static int hashFunction1(string& key);
	static int hashFunction2(string& key);
	static int hashFunction3(string& key);

private:
	string spelling; //the spelling of the word
	string definition; //the definition of the word

	//friend declaration
    friend ostream& operator<<(ostream& os, const Word& word);
	/*
	 * Implement the operator<< in the Word.cpp file too.
	 * See assignment description for examples.
	 * Hint: you should use "os" instead of "cout".
	 */
};

#endif
