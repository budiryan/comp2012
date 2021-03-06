/*
 * Submit this file.
 * Implement all functions according to Node.h in this file.
 */

#include "Node.h"
#include <string>

template<typename T>
Node<T>::Node(string _key, T* _data, Node<T>* _next) :
		key(_key), data(_data), next(_next) {
}

template<typename T>
Node<T>::~Node() {
	if(this->data != NULL){
		delete this->data;
		this->data = NULL;
	}
	if (this->next != NULL)
		this->next = NULL;
}

