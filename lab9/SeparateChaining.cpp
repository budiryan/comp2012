#include <iostream>
#include "SeparateChaining.h"
using namespace std;

SeparateChaining::SeparateChaining(int size) :
		Hashing(size), data(NULL) {
	reset(size);
}

SeparateChaining::~SeparateChaining() {
	clearData();
}

void SeparateChaining::reset(int newSize) {
	if (data != NULL)
		clearData();

	//create the hash table
	data = new ChainingElem[newSize];
	for (int i = 0; i < newSize; i++) {
		data[i].value = EMPTY;	//NOTE: please do not store any other data here
		data[i].next = NULL;	 	//the pointer pointing to the linked list
	}
}

void SeparateChaining::print() {
	cout << "[";
	for (int i = 0; i < bucketSize; i++) {
		if (data[i].next == NULL) {
			cout << "_";
			if (i != bucketSize - 1) {
				cout << ",";
			}
		} else {
			ChainingElem *tmp = data[i].next;
			while (tmp != NULL) {
				if (tmp != data[i].next) { //the value is not the first element of the linked list
					cout << "->";
				}
				cout << tmp->value;
				tmp = tmp->next;
			}
			cout << ",";
		}
	}
	cout << "]" << endl;
}

//TODO: Implement the hash function and return the location in which new value will be inserted
int SeparateChaining::getIndexByhashing(int keyValue) {
	return keyValue % bucketSize;
}

//TODO: Implement the function that will insert the new value into the hash table
bool SeparateChaining::insert(int newValue) {
	ChainingElem * temp = data + getIndexByhashing(newValue);
	while (temp->next != NULL) {
		temp = temp->next;
	}
	ChainingElem * newNode = new ChainingElem;
	newNode->value = newValue;
	newNode->next = NULL;
	temp->next = newNode;
	return true;
}

//TODO: Implement the function that clear the hash table
bool SeparateChaining::clearData() {
	ChainingElem * prev;
	ChainingElem * curr;
	for (int i = 0; i < bucketSize; i++) {
		if (data[i].next == NULL) {
			continue;
		} else {
			prev = NULL;
			curr = data[i].next;
			while (curr != NULL) {
				prev = curr;
				curr = curr->next;
				delete prev;
				prev = NULL;
			}
		}
	}
	prev = curr = NULL;
	delete[] data;
	data = NULL;
	return true;
}

