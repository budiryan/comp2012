/*
 * Do NOT submit this file.
 * Do NOT modify this file.
 */

#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_

#include "Node.h"
#include <iostream>
using namespace std;

/*
 * SortedLinkedList is a sorted singly linked list.
 * Nodes are always sorted ascendingly according to their keys.
 * In other words, the head will always have the smallest key.
 * Keys are non-empty unique strings, and they are compared lexicographically.
 * Hint: just use the standard ">", "<", ">=", "<=", "==" operators for string comparisons.
 */
template<typename T>
class SortedLinkedList
{
public:
	/*
	 * Constructor. Initialize all private members.
	 * Construct an empty list.
	 */
	SortedLinkedList();

	/*
	 * Destructor. Delete all nodes.
	 */
	~SortedLinkedList();
	/*
	 * Add a new node to the list.
	 */
	void add(string key, T* data);

	/*
	 * Remove an exiting node from the list according to the given key. If the key is not found, do nothing.
	 */
	void remove(string key);

	/*
	 * Find and return the node that has the given key. Return NULL if not found.
	 */
	Node<T>* get(string key);

	/*
	 * Remove the current head from the linked list, and return that.
	 * Return NULL if the list is empty.
	 * NOTE: In this function, do NOT delete/deallocate the (old) head that has been popped; the caller would be responsible for deleting it after using it.
	 */
	Node<T>* popHead();

	/*
	 * Add all nodes from the "another" list to this list. Do not change "another" list in any way.
	 * The resulting list, naturally, should remain sorted.
	 * Hint: use "new T(data)" to clone data, where "data" is of type T, it is necessary for deep copying.
	 */
	void operator+=(const SortedLinkedList<T>& another);

private:
	Node<T>* head; //head pointer; it should point to NULL for an empty list

	//friend declaration
	template <typename S>
    friend ostream& operator<< (ostream& os, const SortedLinkedList<S>& list);
	/*
	 * Implement the operator<< in the .tpp file too.
	 * operator<< should output all the nodes' data in the list one by one.
	 * See assignment description for examples.
	 * Hint: you should use "os" instead of "cout".
	 */
};

#include "SortedLinkedList.tpp"

#endif /* SORTEDLINKEDLIST_H_ */
