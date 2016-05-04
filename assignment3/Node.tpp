/*
 * Submit this file.
 * Implement all functions according to Node.h in this file.
 */

#include "Node.h"
#include <string>

template<typename T>
Node<T>::Node(string _key, T* _data, Node<T>* _next) :
		key(_key), next(_next) {
	this->data = new T(*_data);
}

template<typename T>
Node<T>::~Node() {
	delete this->data;
	this->data = NULL;
	if (this->next != NULL)
		this->next = NULL;
}


