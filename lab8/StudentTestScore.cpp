/*
 * StudentTestScore.cpp
 *
 *  Created on: Apr 24, 2016
 *      Author: Budi Ryan
 */
#include "StudentTestScore.h"
#include "Average.h"
#include "PrintLessThan.h"
#include <iostream>

StudentTestScore::StudentTestScore(std::string n, float s) :
		name(n), score(s) {
}

float StudentTestScore::getScore() const {
	return score;
}

std::string StudentTestScore::getName() const {
	return name;
}

Average::Average() :
		sum(0), count(0) {
}

void Average::operator()(const StudentTestScore &s) {
	//TODO: implement
	this->sum += s.getScore();
	this->count++;
}

float Average::result() const {
	return this->sum / this->count;
}

PrintLessThan::PrintLessThan(float a) :
		limit(a), count(0) {
}

void PrintLessThan::operator()(const StudentTestScore & s) {
	//TODO: Implement
	if(s.getScore() < this->limit){
		cout << s.getName() <<": "<<s.getScore()<<endl;
	}
	count++;
}

bool PrintLessThan::isEmpty() {
	return count == 0 ? true : false;
}

