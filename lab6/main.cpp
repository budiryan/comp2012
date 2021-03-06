#include <iostream>
#include <string>
#include "Set.h"
using namespace std;

int main() {
	cout << "Integer sets" << endl;
	cout << "------------" << endl;

	int intArray1[3] = { 1, 2, 3 };
	int intArray2[3] = { 2, 3, 4 };
	Set<int> A(intArray1, 3);
	Set<int> B(intArray2, 3);

	cout << "A = ";
	cout << A << endl;
	cout << "|A| = " << A.cardinality() << endl << endl;

	cout << "B = ";
	cout << B << endl;
	cout << "|B| = " << B.cardinality() << endl << endl;

	Set<int> C = A + B;
	cout << "C = A + B (A union B)" << endl;
	cout << "C = ";
	cout << C << endl;
	cout << "|C| = " << C.cardinality() << endl << endl;

	Set<int> D = A ^ B;
	cout << "D = A ^ B (A intersect B)" << endl;
	cout << "D = ";
	cout << D << endl;
	cout << "|D| = " << D.cardinality() << endl << endl;

	Set<int> E = A - B;
	cout << "E = A - B (Set difference of A and B)" << endl;
	cout << "E = ";
	cout << E << endl;
	cout << "|E| = " << E.cardinality() << endl << endl;

	cout << endl;

	cout << "String sets" << endl;
	cout << "-----------" << endl;

	string stringArr1[3] = { "Dog", "Cat", "Sheep" };
	string stringArr2[3] = { "Cat", "Sheep", "Lion" };
	Set<string> S1(stringArr1, 3);
	Set<string> S2(stringArr2, 3);

	cout << "S1 = ";
	cout << S1 << endl;
	cout << "|S1| = " << S1.cardinality() << endl << endl;

	cout << "S2 = ";
	cout << S2 << endl;
	cout << "|S2| = " << S2.cardinality() << endl << endl;

	Set<string> S3 = S1 + S2;
	cout << "S3 = S1 + S2 (S1 union S2)" << endl;
	cout << "S3 = ";
	cout << S3 << endl;
	cout << "|S3| = " << S3.cardinality() << endl << endl;

	Set<string> S4 = S1 ^ S2;
	cout << "S4 = S1 ^ S2 (S1 intersect S2)" << endl;
	cout << "S4 = ";
	cout << S4 << endl;
	cout << "|S4| = " << S4.cardinality() << endl << endl;

	Set<string> S5 = S1 - S2;
	cout << "S5 = S1 - S2 (Set difference of S1 and S2)" << endl;
	cout << "S5 = ";
	cout << S5 << endl;
	cout << "|S5| = " << S5.cardinality() << endl << endl;

	return 0;
}
