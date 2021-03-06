/*
 * Do NOT submit this file.
 * Your program should compile and run properly with this main.cpp file without any modification.
 */

#include "Dictionary.h"
#include "SortedLinkedList.h"
#include "Word.h"
#include "Inventor.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	//Hint: be reminded that template functions are only instantiated when you use them
	//so you may comment out the lines that contain functions which you haven't implemented to test the other parts
	//however, when you submit your work, all your functions should work and compile
	//this main.cpp should compile without any modification

	//while the following test cases test a lot of things, they do not test everything that you should implement
	//you should design your own test cases to verify that your program has fulfilled all the requirements

	{
		cout << "*** SortedLinkedList tests ***" << endl << endl;
		SortedLinkedList<int> linkedList1;
		linkedList1.add("10", new int(10));
		cout << "After adding 10:" << endl;
		cout << linkedList1 << endl;
		linkedList1.add("13", new int(13));
		cout << "After adding 13:" << endl;
		cout << linkedList1 << endl;
		linkedList1.add("8", new int(8));
		cout << "After adding 8:" << endl;
		cout << linkedList1 << endl;
		linkedList1.add("11", new int(11));
		cout << "After adding 11:" << endl;
		cout << linkedList1 << endl;
		linkedList1.remove("10");
		cout << "After removing 10:" << endl;
		cout << linkedList1 << endl;
		linkedList1.remove("8");
		cout << "After removing 8:" << endl;
		cout << linkedList1 << endl;
		cout << "After linkedList2 += linkedList1 where linkedList2 only has \"12\" in it" << endl;
		SortedLinkedList<int> linkedList2;
		linkedList2.add("12", new int(12));
		linkedList2+=linkedList1;
		cout << "linkedList1:" << endl;
		cout << linkedList1;
		cout << "linkedList2:" << endl;
		cout << linkedList2 << endl;
		linkedList2.popHead();
		cout << "linkedList2 after calling popHead():" << endl;
		cout << linkedList2 << endl;
		cout << "Trying to get \"13\" in linkedList2... ";
		cout << (linkedList2.get("13")!=NULL?"Found.":"NOT found.") << endl;
		cout << "Trying to get \"12\" in linkedList2... ";
		cout << (linkedList2.get("12")!=NULL?"Found.":"NOT found.") << endl;
		cout << "Trying to get \"11\" in linkedList2... ";
		cout << (linkedList2.get("11")!=NULL?"Found.":"Not found.") << endl;
		cout << endl << endl;
	} //by using this pair of brackets, a scope is created
	//it forces the destruction of the non-dynamic objects inside (for testing purpose)
	//note also that the dynamic objects should be destructed when the linked list destructor is called

	{
		cout << "*** Word tests ***" << endl << endl;
		Word word("spelling", "definition");
		cout << "overloaded operator<< should print:" << endl;
		cout << "<" << word << ">"  << endl;
		cout << "follow the exact format and wording inside the brackets <>." << endl;
		//the following checks if the output is exactly the same as required
		//you must use the general "os" object instead of "cout" object in your operator<< implementation
		ostringstream oss; //see http://www.cplusplus.com/reference/sstream/ostringstream/ if you are interested
		oss << word;
		if(oss.str() == "\"spelling\" means \"definition\"") cout << "OK." << endl;
		else cout << "NOT OK." << endl;
		cout << endl << endl;
	}

	{
		cout << "*** Inventor tests ***" << endl << endl;
		Inventor inventor("firstName", "lastName", "invention");
		cout << "overloaded operator<< should print:" << endl;
		cout << "<" << inventor << ">"  << endl;
		cout << "follow the exact spacing and wording inside the brackets <>." << endl;
		//the following checks if the output is exactly the same as required
		//you must use the general "os" object instead of "cout" object in your operator<< implementation
		ostringstream oss; //see http://www.cplusplus.com/reference/sstream/ostringstream/ if you are interested
		oss << inventor;
		if(oss.str() == "firstName lastName invented invention!") cout << "OK." << endl;
		else cout << "NOT OK." << endl;
		cout << endl << endl;
	}

	{
		cout << "*** Dictionary<Word> tests ***" << endl << endl;
		Dictionary<Word> wordDict1(4, Word::hashFunction1);

		wordDict1.add("cat", new Word("cat", "meow"));
		cout << "After adding \"cat\":" << endl;
		wordDict1.print();
		wordDict1.add("dog", new Word("dog", "the best friend"));
		cout << "After adding \"dog\":" << endl;
		wordDict1.print();
		wordDict1.add("real", new Word("real", "not illusory"));
		cout << "After adding \"real\":" << endl;
		wordDict1.print();
		wordDict1.add("C++", new Word("C++", "something you need to master in COMP2012"));
		cout << "After adding \"C++\":" << endl;
		wordDict1.print();
		wordDict1.add("Java", new Word("Java", "a beverage consisting of an infusion of ground coffee beans"));
		cout << "After adding \"Java\":" << endl;
		wordDict1.print();
		wordDict1.add("pear", new Word("pear", "a sweet juicy gritty-textured fruit available in many varieties"));
		cout << "After adding \"pear\":" << endl;
		wordDict1.print();
		wordDict1.add("hope", new Word("hope", "the general feeling that some desire will be fulfilled"));
		cout << "After adding \"hope\":" << endl;
		wordDict1.print();

		Word* result = wordDict1.lookup("dog");
		cout << "Looking up for \"dog\"..." << endl;
		if(result!=NULL) cout << "result: " << *result << endl;
		else cout << "Not found in the dictionary." << endl;
		result = wordDict1.lookup("pig");
		cout << "Looking up for \"pig\"..." << endl;
		if(result!=NULL) cout << "result: " << *result << endl;
		else cout << "Not found in the dictionary." << endl;
		result = wordDict1.lookup("cat");
		cout << "Looking up for \"cat\"..." << endl;
		if(result!=NULL) cout << "result: " << *result << endl;
		else cout << "Not found in the dictionary." << endl;
		cout << endl;

		wordDict1.changeHashFunction(Word::hashFunction2);
		cout << "After changing the hash function to Word::hashFunction2:" << endl;
		wordDict1.print();
		wordDict1.changeHashFunction(Word::hashFunction3);
		cout << "After changing the hash function to Word::hashFunction3:" << endl;
		wordDict1.print();
		wordDict1.changeHashFunction(Word::hashFunction1);
		cout << "After changing the hash function to Word::hashFunction1:" << endl;
		wordDict1.print();

		wordDict1.resize(2);
		cout << "After resize(2):" << endl;
		wordDict1.print();
		wordDict1.resize(6);
		cout << "After resize(6):" << endl;
		wordDict1.print();
		cout << endl;

		wordDict1.remove("cat");
		cout << "After removing \"cat\":" << endl;
		wordDict1.print();
		wordDict1.remove("C++");
		cout << "After removing \"C++\":" << endl;
		wordDict1.print();
		cout << endl;

		Dictionary<Word> wordDict2(4, Word::hashFunction1);
		wordDict2.add("C++", new Word("C++", "something you need to master in COMP2012"));
		wordDict2.add("cat", new Word("cat", "meow"));
		wordDict1 += wordDict2;
		cout << "After wordDict1 += wordDict2 where wordDict2 only has \"C++\" and \"cat\"" << endl;
		cout << "wordDict1:" << endl;
		wordDict1.print();
		cout << "wordDict2:" << endl;
		wordDict2.print();

		cout << endl << endl;

	}

	{
		cout << "*** Dictionary<Inventor> tests ***" << endl << endl;Dictionary<Inventor> inventorDict(5, Inventor::hashFunction);
		inventorDict.add("Stroustrup", new Inventor("Bjarne", "Stroustrup", "C++"));
		inventorDict.add("Teller", new Inventor("Edward", "Teller", "hydrogen bomb"));
		inventorDict.add("Dolgoff", new Inventor("Gene", "Dolgoff", "LCD projectors"));
		inventorDict.add("Born", new Inventor("Sam", "Born", "lollipop-making machines"));;
		inventorDict.add("Engelbart", new Inventor("Douglas", "Engelbart", "computer mice"));
		inventorDict.add("Fry", new Inventor("Arthur", "Fry", "post-it notes"));
		inventorDict.add("Winchell", new Inventor("Paul", "Winchell", "artificial hearts"));
		inventorDict.add("Yokoi", new Inventor("Gunpei", "Yokoi", "gameboys"));
		inventorDict.print();

		Inventor* result = inventorDict.lookup("Winchell");
		cout << "Looking up for \"Winchell\"..." << endl;
		if(result!=NULL) cout << "result: " << *result << endl;
		else cout << "Not found in the dictionary." << endl;
		result = inventorDict.lookup("Paul");
		cout << "Looking up for \"Paul\"..." << endl;
		if(result!=NULL) cout << "result: " << *result << endl;
		else cout << "Not found in the dictionary." << endl;
		result = inventorDict.lookup("Stroustrup");
		cout << "Looking up for \"Stroustrup\"..." << endl;
		if(result!=NULL) cout << "result: " << *result << endl;
		else cout << "Not found in the dictionary." << endl;
		result = inventorDict.lookup("Doraemon");
		cout << "Looking up for \"Doraemon\"..." << endl;
		if(result!=NULL) cout << "result: " << *result << endl;
		else cout << "Not found in the dictionary." << endl;
		cout << endl;
	}

	return 0;
}
