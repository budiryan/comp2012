/*
 * main.cpp
 *
 *  Created on: May 6, 2016
 *      Author: Budi Ryan
 */
#include <iostream>
#include <string>
using namespace std;

int f(int N){
	if(N <= 1)
		return 0;
	int a = (f(N - 1) + f(N - 1))/ 2;
	a += 2;
	return a;

}

int main() {
//	string key = "catisbae";
//	unsigned int i = 0;
//	int result = 0, flag = 0;
//	//search the nth prime number
//	while (i <= key.length()) {
//		result++;
//		for (int k = 2; k <= result / 2; ++k) {
//			if (result % k == 0) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//			i++;
//		flag = 0;
//	}
//	cout<<"result: "<< result;
//
//	cout<<"debug2: "<<endl;
//	cout<<f(3)<<endl;
	unsigned int a = (unsigned int) - 1;
	cout<<a<<endl;

	return 0;
}

