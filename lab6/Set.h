//**********************************************************/
// COMP2012 2016S Lab06
// Templates, Operator Overloading and Friend Function: Set
// Header file of the Set class: Set.h
/***********************************************************/

#ifndef SET_H
#define SET_H

#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

// Forward declaration to make the declaration of operator<< possible
template <typename T>
class Set;

// Declaration of operator<< function
template <typename T>
ostream& operator<<(ostream& os, const Set<T>& s);

template <typename T>
class Set
{
  public:
    // Default constructor: Construct an empty set
    Set();

    // Other constructor: Initialize the data members with the given parameters
    Set(const T elements[], int size);

    // Copy constructor: Perform deep copying
    // Hint: Make use of assignment operator function
    Set(const Set<T>& s);

    // Destructor: De-allocate dynamic memory
    virtual ~Set();

    // Return the cardinality of the set, i.e., the size
    int cardinality() const;

    // Return the element's index if it exists. Otherwise return -1
    int findElement(const T& element) const;

    // Return true if the element exists, otherwise return false
    bool isExist(const T& element) const;

    // Allocate a new array of size "size+1", copy all the existing elements over and
    // add the new element to the last position of the new array
    void addElement(const T& element);

    // Check if the element is in the set. 
    // If it is in the set, allocate a new array and copy all the existing elements over except
    // the element to be deleted.
    // Return true if the element is found and deleted. Otherwise return false
    bool removeElement(const T& element);

    // Overload operator+ to support union operation of two set objects
    // Note: Resulting set of A + B = { x : x in A or x in B }
    // ------------------------------------------
    //  Add the operator function prototype here
    Set<T> operator+(const Set<T> & b)const;

    // ------------------------------------------

    // Overload operator^ to support intersection operation of two set objects
    // Note: Resulting set of A ^ B = { x : x in A and x in B }
    // ------------------------------------------
    //  Add the operator function prototype here
    // ------------------------------------------
    Set<T> operator^(const Set<T> & b)const;
    
    // Overload operator- to support difference operation of two set objects
    // Note: Resulting set of A - B = { x : x in A and x not in B }
    // ------------------------------------------
    //  Add the operator function prototype here
    // ------------------------------------------
    Set<T> operator-(const Set<T> & b)const;

    // Overload assignment operator function
    // Note: Deep copying is required
    // ------------------------------------------
    //  Add the operator function prototype here
    // ------------------------------------------
    const Set<T>& operator=(const Set<T> & b);

    /*
      Note: 
      The <T> after operator<< means opeartor<< is a function template.
    */
    friend ostream& operator<< <T>(ostream& os, const Set<T>& a);

  private:
    T* elements;	// A pointer to an array of objects in type T storing all elements of the set
    int size;		// The number of the elements in the array, i.e. the size of the set
};

// Recall, it is not possible to write a class template in separate files.
// One way to get around this is to include the source file that implements the 
// class template into the header file that defines the class template.
// The source file that implements the class template normally with extension .tpp

#include "Set.tpp"

#endif
