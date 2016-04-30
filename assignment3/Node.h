/*
 * Do NOT submit this file.
 * Do NOT modify this file.
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

//forward declarations
template<typename T>
class SortedLinkedList;
template<typename T>
class Dictionary;

/*
 * Node represents a node in a sorted linked list.
 */
template<typename T>
class Node
{
public:
	/*
	 * Constructor. Initialize all private members.
	 * Create the hash table.
	 */
	Node(string _key, T* _data, Node<T>* _next);

	/*
	 * Destructor. Delete the data here.
	 */
	~Node();

private:
	string key; //the key (note: not the hash value)
	T* data; //the data
	Node<T>* next; //the pointer that points to the next node; it should point to NULL at the end of the linked list

	//friend declarations
	friend class SortedLinkedList<T>;
	friend class Dictionary<T>;
	template<typename S>
    friend ostream& operator<< (ostream& os, const SortedLinkedList<S>& list);
};

#include "Node.tpp"

#endif /* NODE_H_ */
