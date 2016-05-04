/*
 * Do NOT submit this file.
 * Do NOT modify this file.
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "SortedLinkedList.h"

/*
 * Dictionary is a generic dictionary.
 * It uses separate chaining for hashing and supports custom hash functions.
 */
template <typename T>
class Dictionary
{
public:
	/*
	 * Constructor. Initialize all private members.
	 * You can assume the given parameters are always valid, e.g., _size is always positive.
	 */
	Dictionary(int _size, int(*_hashFunction)(string&));

	/*
	 * Copy constructor. Deep copy is required.
	 */
	Dictionary(const Dictionary<T>&);

	/*
	 * Destructor. Delete the table.
	 */
	~Dictionary();

	/*
	 * Add a new entry.
	 * You can assume all keys are unique.
	 */
	void add(string key, T* data);

	/*
	 * Remove an existing entry according to the given key. If the key is not found, do nothing.
	 */
	void remove(string key);

	/*
	 * Find and return an entry according to the given key. If the key is not found, return NULL.
	 */
	T* lookup(string key);

	/*
	 * Resize the table. Everything has to be re-hashed and reallocated properly.
	 * Hint: use "new T(data)" to clone data, where "data" is of type T, it is necessary for deep copying.
	 */
	void resize(int newSize);

	/*
	 * Change the hash function. If changed, everything has to be re-hashed and reallocated properly.
	 * Do nothing if the new hash function is the same as the existing one.
	 */
	void changeHashFunction(int(*_hashFunction)(string&));

	/*
	 * Add all entries from "another" dictionary. Do not change "another" dictionary in any way.
	 * Hint: It is possible. This is intended to be a bit tricky. Think what you can use.
	 * Also, remember that you cannot modify the .h files.
	 */
	void operator+=(const Dictionary<T>& another);

	/*
	 * Print all entries from the dictionary.
	 * It is given and completed.
	 * Do not modify it. Remember that you cannot change the .h files.
	 */
	void print()
	{
		cout << "Dictionary's hash table size is " << size << endl;
		cout << "==================================================" << endl;
		for(int i=0; i<size; i++)
		{
			cout << "table[" << i << "]:" << endl;
			cout << table[i];
			cout << endl;
		}
		cout << endl;
	}

private:
	int size; //the size of the hash table
	int(*hashFunction)(string&); //the function pointer of the hash function
	SortedLinkedList<T>* table; //the hash table, which is a dynamic array of sorted linked lists
};

#include "Dictionary.tpp"

#endif
