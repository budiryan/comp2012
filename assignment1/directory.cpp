/*
 * Submit this file.
 *
 * Add the missing implementations of all member functions to this file according to directory.h.
 */

#include "directory.h"
#include <iostream>

using namespace std;

Directory :: Directory(string name, Directory * parent){
	this->number_of_children = 0;
	this->children = new Directory * [0];
	this->name = name;
	this->parent = parent;
}

Directory :: ~Directory(){
	for(int i = 0 ; i < this->number_of_children; i++){
		delete this->children[i];
		this->children[i] = NULL;
	}
	delete [] this->children;
	this->children = NULL;
}

void Directory :: set_name(string new_name){
	this->name = new_name;
}

Directory * Directory :: get_parent()const{
	return this->parent;
}


int Directory:: get_number_of_children()const{
	return this->number_of_children;
}

string Directory:: get_full_path()const{
	string target_string = "";
	const Directory * temp = this;
	while(temp != NULL){
		if(temp->parent != NULL){
			if(temp->parent->parent == NULL) target_string = temp->name + target_string;
			else target_string = "\\" + temp->name + target_string;
		}
		else{
			target_string = temp->name + target_string;
		}
		temp = temp->parent;
	}
	return target_string;
}


void Directory :: add_child(string child_name){
	//Incrase the number of children
	this->number_of_children++;

	//Allocate a new dynamic memory
	Directory ** temp_children = new Directory * [this->number_of_children];
	//Fill in the temp array
	for(int i = 0; i < this->number_of_children - 1; i++)temp_children[i] = this->children[i];
	temp_children[this->number_of_children-1] = new Directory(child_name,this);

	//Delete the old memory
	delete [] this->children;
	this->children = NULL;

	//Initialize new memory
	this->children = new Directory * [this->number_of_children];

	//Transfer from temp array to main array
	for(int i = 0; i < this->number_of_children; i++)this->children[i] = temp_children[i];

	//Make the temp_children pointer point to NULL
	delete [] temp_children;
	temp_children = NULL;
}


void Directory:: remove_child(string child_name){

	//Reduce the number of children by 1
	this->number_of_children--;
	for(int i = 0; i < this->number_of_children ; i++){
		if(this->children[i]->name == child_name){
			//Release the allocated memory
			delete this->children[i];
			this->children[i] = NULL;

			//Shift elements of the array to the left
			for(int j = i ; j < this->number_of_children; j++)this->children[j] = this->children[j+1];
			break;
		}
	}
}

void Directory:: list_children()const{
	for(int i = 0; i < this->number_of_children ; i++){
		cout<<this->children[i]->name<<endl;
	}
}

Directory * Directory :: find_child_by_name(string child_name)const{
	for(int i = 0; i < this->number_of_children ; i++){
		if(this->children[i]->name == child_name)return this->children[i];
	}
	return NULL;
}


