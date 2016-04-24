/*
// COMP2012 2016S Lab08
// Function object: Average
// Header file of the Average class: Average.h
 */


#ifndef AVERAGE_H_
#define AVERAGE_H_

#include "StudentTestScore.h"

class Average
{
	public:
		Average(); //constructor, you has to initialize sum and count with 0

        // function object, update the sum and count for each stu
		void operator() (const StudentTestScore& s);
		float result() const; // return the average score

	private:
		float sum; // the sum of the score
		int count; // the count of the students
};



#endif /* AVERAGE_H_ */
