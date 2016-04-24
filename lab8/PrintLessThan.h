/*
// COMP2012 2016S Lab08
// Function object: PrintLessThan
// Header file of the PrintLessThan class: PrintLessThan.h
 */

#ifndef PRINTLESSTHAN_H_
#define PRINTLESSTHAN_H_

#include "StudentTestScore.h"
using namespace std;


class PrintLessThan
{
	public:
		PrintLessThan(float a); // constructor

        // function object, print students whose scores are
        // less than the limit with the form of "name: score"
		void operator() (const StudentTestScore& s);
		bool isEmpty();

	private:
		float limit; // limit is the upper bound
		int count; // count how many students having scores < limit
};




#endif /* PRINTLESSTHAN_H_ */
