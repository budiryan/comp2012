#include <set>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace std;

void printSetUsingIterator(const set<string>& s) {
	// TODO: Print a set of string using iterator
	unsigned int counter = 0;
	set<string>::iterator iter;
	cout << "{";
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter;
		if (counter != s.size() - 1)
			cout << ",";
		counter++;
	}
	cout << "}";
	cout << endl;
}
void printListUsingIterator(const list<string>& s) {
	// TODO: Print a list of string using iterator
	list<string>::const_iterator iter;
	unsigned int counter = 0;
	cout << "{";
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter;
		if (counter != s.size() - 1)
			cout << ",";
		counter++;
	}
	cout << "}";
	cout << endl;
}

void printMapUsingIterator(const map<string, int>& s) {
	// TODO: Print a map using iterator
	map<string, int>::const_iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++)
		cout << "key: " << iter->first <<"  "<< "Value: " << iter->second << endl;
}

int main() {
	cout << endl;
	cout << "************************** Part1: set **************************";
	cout << endl;

	set<string> Fictions, Movies;
	Fictions.insert("The Time Machine");
	Fictions.insert("The Catcher in the Rye");
	Fictions.insert("The Lord of the Rings");

	Movies.insert("The Shawshank Redemption");
	Movies.insert("City of God");
	Movies.insert("The Lord of the Rings");
	Movies.insert("Star Wars");

	cout << "Set Fictions Content =";
	printSetUsingIterator(Fictions);
	cout << "Set Movies Content =";
	printSetUsingIterator(Movies);

	// Part 1 TODO: Complete the set operations: union, intersection and difference.
	set<string> unionSet, interSet, diffSet;

	// ADD YOUR CODE HERE
	cout << "Fictions union Movies Content = ";
	for (set<string>::iterator i = Fictions.begin(); i != Fictions.end(); i++)
		unionSet.insert(*i);
	for (set<string>::iterator i = Movies.begin(); i != Movies.end(); i++)
		unionSet.insert(*i);
	printSetUsingIterator(unionSet);

	// ADD YOUR CODE HERE
	cout << "Fictions intersect Movies Content = ";
	set_intersection(Fictions.begin(), Fictions.end(), Movies.begin(),
			Movies.end(), inserter(interSet, interSet.begin()));
	printSetUsingIterator(interSet);

	// ADD YOUR CODE HERE
	cout << "Fictions difference Movies Content = ";
	set_difference(Fictions.begin(), Fictions.end(), Movies.begin(),
			Movies.end(), inserter(diffSet, diffSet.begin()));
	printSetUsingIterator(diffSet);

	cout << endl;
	cout << "************************** Part2: list **************************";
	cout << endl;

	list<string> listR;
	// Part 2 TODO: Merge Fictions and Movies to listR
	// ADD YOUR CODE HERE
	for (set<string>::iterator i = Movies.begin(); i != Movies.end(); i++)
		listR.push_front(*i);
	for (set<string>::iterator i = Fictions.begin(); i != Fictions.end(); i++)
		listR.push_front(*i);
	listR.sort();
	cout << "listR Content = ";
	printListUsingIterator(listR);

	// Part 2 TODO:
	//Add a new string "Forest Gump" at the end of the list
	//Add a new string "The Dark Knight" at the head of the list
	// ADD YOUR CODE HERE
	listR.push_back("Forest Gump");
	listR.push_front("The Dark Knight");
	cout << "New R Content = ";
	printListUsingIterator(listR);

	// Part 2 TODO: Compelete sort and unique of list here
	// Sort listR
	// ADD YOUR CODE HERE
	listR.sort();
	cout << "Sorted R Content = ";
	printListUsingIterator(listR);

	// unique listR
	// ADD YOUR CODE HERE
	listR.unique();

	cout << "Unique R Content = ";
	printListUsingIterator(listR);

	cout << endl;
	cout << "************************** Part3: map **************************";
	cout << endl;

	map<string, int> mapMovie;
	mapMovie.insert(make_pair("The Shawshank Redemption", 1994));
	mapMovie.insert(make_pair("City of God", 2002));
	mapMovie.insert(make_pair("The Lord of the Rings", 2002));
	mapMovie.insert(make_pair("Star Wars", 1977));
	mapMovie.insert(make_pair("Forest Gump", 1994));
	cout << "mapMovie Content: " << endl;
	printMapUsingIterator(mapMovie);

	//Part3 TODO : Compelete element search and deletion in mapMovie here
	// search "Star Wars" in map
	// ADD YOUR CODE HERE
	map<string, int>::const_iterator i;
	i = mapMovie.find("Star Wars");
	cout << "Key found, the value is " << i->second << endl;

	// delete "City of God" in map
	// ADD YOUR CODE HERE
	cout<<"mapMovie Content after deletion:"<<endl;
	mapMovie.erase("City of God");
	printMapUsingIterator(mapMovie);
	return 0;
}
