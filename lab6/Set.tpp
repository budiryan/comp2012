/**********************************************************/
// COMP2012 2016S Lab06
// Templates, Operator Overloading and Friend Function: Set
// Source file of the Set class: Set.tpp
/**********************************************************/

#include "Set.h"
using namespace std;

// Default constructor: Construct an empty set

template<typename T>
Set<T>::Set() :
		elements(NULL), size(0) {
}

// Other constructor: Initialize the data members with the given parameters */

template<typename T>
Set<T>::Set(const T elements[], int size) {
	this->elements = new T[size];
	for (int i = 0; i < size; i++)
		this->elements[i] = elements[i];
	this->size = size;
}

// Copy constructor: Perform deep copying
// Hint: Make use of assignment operator function

template<typename T>
Set<T>::Set(const Set<T>& s) {
	(*this) = s; //Deep copying will be performed by the overloaded assignment operator
}

// Destructor: De-allocate dynamic memory

template<typename T>
Set<T>::~Set() {
	delete[] this->elements;
	this->elements = NULL;
}

// Return the cardinality of the set, i.e., the size

template<typename T>
int Set<T>::cardinality() const {
	//finding a duplicate
	set<T> dummy;
	for (int i = 0; i < this->size; i++)
		dummy.insert(this->elements[i]);
	return dummy.size();
}

// Return the element's index if it exists. Otherwise return -1
// Notice: you has to process the data type: int, string ...
// You has to also consider how to process the datatype: float and double
// Hint: You can consider doing template specialization for float and double

template<typename T>
int Set<T>::findElement(const T& element) const {
	for (int i = 0; i < this->size; i++)
		if (this->elements[i] == element)
			return i;
	return -1;
}

template<> int Set<float>::findElement(const float& element) const {
	for (int i = 0; i < this->size; i++){
		if (fabs(this->elements[i] - element)
				< numeric_limits<double>::epsilon())
			return i;
	}
	return -1;
}

template<> int Set<double>::findElement(const double& element) const {
	for (int i = 0; i < this->size; i++){
		if (fabs(this->elements[i] - element)
				< numeric_limits<double>::epsilon())
			return i;
	}
	return -1;
}

// Return true if the element exists, otherwise return false

template<typename T>
bool Set<T>::isExist(const T& element) const {
	for (int i = 0; i < this->size; i++)
		if (this->elements[i] == element)
			return true;
	return false;
}

// Allocate a new array of size "size+1", copy all the existing elements over and
// add the new element to the last position of the new array

template<typename T>
void Set<T>::addElement(const T& element) {
	T * temp = new T[this->size + 1];
	for (int i = 0; i < this->size; i++)
		temp[i] = this->elements[i];
	temp[this->size] = element;
	this->size++;
	delete[] this->elements;
	this->elements = temp;
	temp = NULL;
}

// Check if the element is in the set.
// If it is in the set, allocate a new array and copy all the existing elements over except
// the element to be deleted.
// Return true if the element is found and deleted. Otherwise return false

template<typename T>
bool Set<T>::removeElement(const T& element) {
	if (isExist(element)) {
		T * temp = new T[this->size - 1];
		for (int i = 0; i < this->size - 1; i++) {
			temp[i] = this->elements[i];
			if (i == findElement(element)) {
				for (int j = i; j < this->size - 1; j++) {
					temp[j] = this->elements[j + 1];
				}
				break;
			}
		}
		this->size--;
		delete[] this->elements;
		this->elements = temp;
		temp = NULL;
		return true;
	}
	return false;
}

// Overload operator+ to support union operation of two set objects
// Note: Resulting set of A + B = { x : x in A or x in B }
template<typename T>
Set<T> Set<T>::operator+(const Set<T> & b) const {
	Set<T> Haha = *(this);
	for (int i = 0; i < b.size; i++) {
		if (!Haha.isExist(b.elements[i])) {
			Haha.addElement(b.elements[i]);
		} else
			continue;
	}
	return Haha;
}

// Overload operator^ to support intersect operation of two set objects
// Note: Resulting set of A ^ B = { x : x in A and x in B }
template<typename T>
Set<T> Set<T>::operator^(const Set<T> & b) const {
	Set<T> Haha = *(this);
	for (int i = 0; i < Haha.size; i++) {
		for (int j = 0; j < b.size; j++) {
			if (!b.isExist(Haha.elements[i]))
				Haha.removeElement(Haha.elements[i]);
		}
	}
	return Haha;
}

// Overload operator- to support difference operation of two set objects
// Note: Resulting set of A - B = { x : x in A and x not in B }
template<typename T>
Set<T> Set<T>::operator-(const Set<T> & b) const {
	Set<T> Haha = *(this);
	for (int i = 0; i < b.size; i++) {
		if (Haha.isExist(b.elements[i]))
			Haha.removeElement(b.elements[i]);
		else
			continue;
	}
	return Haha;
}

// Overload assignment operator function
// Note: Deep copying is required
template<typename T>
const Set<T>& Set<T>::operator=(const Set<T> & b) {
	if (this != &b) {
		this->elements = new T[b.size];
		for (int i = 0; i < b.size; i++)
			this->elements[i] = b.elements[i];
		this->size = b.size;
	}
	return *this;
}

//Overload operator<< to allow output of objects in Set<T> type
template<typename T>
ostream& operator <<(ostream& os, const Set<T> & a) {
	os << '{';
	for (int i = 0; i < a.size; i++) {
		os << a.elements[i];
		if (i != a.size - 1)
			os << ", ";
	}
	os << '}';
	return os;
}

