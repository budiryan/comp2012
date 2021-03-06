/*
 * Submit this file.
 * Implement all functions according to SortedLinkedList.h in this file.
 */
#include "SortedLinkedList.h"

template<typename T>
SortedLinkedList<T>::SortedLinkedList() :
		head(NULL) {
}

template<typename T>
SortedLinkedList<T>::~SortedLinkedList() {
	Node<T> * curr = this->head;
	Node<T> * prev = NULL;
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		delete prev;
		prev = NULL;
	}
	head = NULL;
}

template<typename T>
void SortedLinkedList<T>::add(string key, T* data) {
	Node<T> * newNode = new Node<T>(key, data, NULL);
	Node<T> * curr = this->head;
	//case 1 insert an empty list
	if (curr == NULL) {
		this->head = newNode;
		return;
	}

	//case 2 insert at the beginning
	if (newNode->key < curr->key) {
		newNode->next = head;
		head = newNode;
		return;
	}

	for (; curr->next != NULL && newNode->key > curr->next->key;
			curr = curr->next)
		;

	//case 3 insert at the middle or the end
	newNode->next = curr->next;
	curr->next = newNode;


}

template<typename T>
void SortedLinkedList<T>::remove(string key) {
	Node<T> * curr = this->head;
	Node<T> * prev = NULL;
	//find the item to be deleted
	while (curr != NULL && curr->key != key) {
		prev = curr;
		curr = curr->next;
	}
	if (curr != NULL) {
		if (curr == this->head)
			this->head = this->head->next;
		else
			prev->next = curr->next;
		delete curr;
		curr = NULL;
	} else
		return; //If the data is not found, do nothing
}

template<typename T>
Node<T>* SortedLinkedList<T>::get(string key) {
	Node<T> * curr = this->head;
	while (curr != NULL) {
		if (curr->key == key)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

template<typename T>
Node<T>* SortedLinkedList<T>::popHead() {
	if (this->head == NULL)
		return NULL;
	Node<T> * curr = this->head;
	this->head = this->head->next;
	return curr;
}

template<typename T>
void SortedLinkedList<T>::operator+=(const SortedLinkedList<T>& another) {
	Node<T> * another_curr = another.head;
	T * newData;
	while (another_curr != NULL) {
		//need dynamic memory allocation coz T is a pointer, string no need la
		newData = new T(*(another_curr->data));
		this->add(another_curr->key, newData);

		//advance the pointer
		another_curr = another_curr->next;
	}
}

template<typename S>
ostream& operator<<(ostream& os, const SortedLinkedList<S>& list) {
	Node<S> * another_curr = list.head;
	while (another_curr != NULL) {
		os << *(another_curr->data);
		os << endl;
		another_curr = another_curr->next;
	}
	return os;
}
