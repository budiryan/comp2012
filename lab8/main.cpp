
#include <iostream>
#include "StudentTestScore.h"
#include "Average.h"
#include "PrintLessThan.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std::vector<StudentTestScore> v;

    v.push_back(StudentTestScore("Luis", 84));
    v.push_back(StudentTestScore("Bob", 61));
    v.push_back(StudentTestScore("Alice", 43));
    v.push_back(StudentTestScore("Jane", 52));
    v.push_back(StudentTestScore("Lauren", 15));

    // the range of the score is [0,100]
    cout << "All the students' scores:" << endl;
    PrintLessThan printAll(101);

    for_each(v.begin(), v.end(), printAll);
	Average average = for_each(v.begin(), v.end(), Average());

	cout << endl;
	cout << "Average score:" << endl;
	cout << average.result() << endl;

	cout << endl;
	cout << "Students with scores less than 60:" << endl;
	PrintLessThan printlt60(60);
	printlt60 = for_each(v.begin(), v.end(), printlt60);

	if (printlt60.isEmpty())
		cout << "no student is less than 60" << endl;

	return 0;
}
