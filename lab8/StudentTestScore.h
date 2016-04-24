/*
// COMP2012 2016S Lab08
// Function object: StudentTestScore
// Header file of the StudentTestScore class: StudentTestScore.h
 */

#ifndef STUDENTTESTSCORE_H_
#define STUDENTTESTSCORE_H_

#include <string>

class StudentTestScore
{
	public:
		StudentTestScore(std::string n, float s);  //constructor
		float getScore() const; // return the data member of score
		std::string getName() const; // return the data member of name

	private:
		std::string name; // the name of the student
		float score; // the score of the student
};





#endif /* STUDENTTESTSCORE_H_ */
