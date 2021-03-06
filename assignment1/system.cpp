/*
 * Submit this file.
 *
 * System::prompt() and System::dir() are already completed. Do NOT modify them.
 * Add the missing implementations of other member functions to this file according to system.h.
 */

#include "system.h"
#include <iostream>

using namespace std;

bool System::prompt() {
	//IMPORTANT NOTE: It is already completed. Do NOT modify any of its code.

	//show the prompt text
	cout << current_directory->get_full_path() << ">";

	//get the whole line of command
	string command;
	getline(cin, command);

	//perform the command action accordingly
	if (command == "exit") //exit the prompt
			{
		return false; //this will stop the prompt loop
	}
	if (command.substr(0, 2) == "cd") //change directory
			{
		//execute the command with the provided argument if the syntax is correct
		if (command.length() > 3) {
			if (!cd(command.substr(3)))
				cout << "The specified sub-directory " << command.substr(3)
						<< " is not found or you are trying to move beyond the root level."
						<< endl;
		} else

			cout << "Invalid syntax." << endl; //warn if the syntax is invalid (but it shouldn't happen according to our assumption)
	} else if (command.substr(0, 2) == "md") //make directory
			{
		//execute the command with the provided argument if the syntax is correct
		if (command.length() > 3) {
			if (!md(command.substr(3)))
				cout
						<< "There already exists a sub-directory which has the same name."
						<< endl;

		} else
			cout << "Invalid syntax." << endl; //warn if the syntax is invalid (but it shouldn't happen according to our assumption)
	} else if (command.substr(0, 2) == "rd") //remove directory
			{
		//execute the command with the provided argument if the syntax is correct
		if (command.length() > 3) {
			if (!rd(command.substr(3)))
				cout << "The specified sub-directory " << command.substr(3)
						<< " is not found." << endl;
		} else
			cout << "Invalid syntax." << endl; //warn if the syntax is invalid (but it shouldn't happen according to our assumption)
	} else if (command == "dir") //list sub-directories
			{
		//execute the command
		dir();
	} else if (command.substr(0, 3) == "ren") //rename directory
			{
		//execute the command with the provided argument if the syntax is correct
		if (command.length() > 4) {
			string arguments = command.substr(4);
			unsigned int space_location = arguments.find(" ", 0);
			if (space_location != string::npos) //if a space is found, use substr to separate the arguments with it
					{
				if (!ren(arguments.substr(0, space_location),
						arguments.substr(space_location + 1)))
					cout << "The specified sub-directory "
							<< arguments.substr(0, space_location)
							<< " is not found or the new name could not be used due to a name conflict."
							<< endl;
			} else
				//if a space is not found, warn the user
				cout << "Invalid syntax." << endl; //warn as the syntax is invalid (but it shouldn't happen according to our assumption)
		} else
			cout << "Invalid syntax." << endl; //warn if the syntax is invalid (but it shouldn't happen according to our assumption)
	} else {
		//this case shouldn't happen as we assume the user always inputs valid commands in correct formats
		cout << "Invalid syntax." << endl;
	}

	return true; //this will make the prompt loop continue
}

void System::dir() const {
	//IMPORTANT NOTE: It is already completed. Do NOT modify any of its code.

	//show an appropriate message according to the number of sub-directories
	switch (current_directory->get_number_of_children()) {
	case 0:
		cout << "There is no sub-directory." << endl;
		break;
	case 1:
		cout << "There is 1 sub-directory:" << endl;
		current_directory->list_children(); //list all the sub-directories
		break;
	default: //2 or more
		cout << "There are " << current_directory->get_number_of_children()
				<< " sub-directories:" << endl;
		current_directory->list_children(); //list all the sub-directories
		break;
	}
}

System::System(string root_name) {
	root = new Directory(root_name, NULL);
	current_directory = root;
}

System::~System() {
	delete root;
	root = NULL;
	current_directory = NULL;
}

bool System::cd(string directory_name) {
	if (directory_name == "..") {
		if (current_directory == root)
			return false;
		else {
			current_directory = current_directory->get_parent();
			return true;
		}
	} else if (current_directory->find_child_by_name(directory_name)) {
		current_directory = current_directory->find_child_by_name(
				directory_name);
		return true;
	} else
		return false;
}

bool System::md(string directory_name) const {
	if (current_directory->find_child_by_name(directory_name) != NULL)
		return false;
	else {
		current_directory->add_child(directory_name);
		return true;
	}
}

bool System::rd(string directory_name) const {
	if (current_directory->find_child_by_name(directory_name) == NULL)
		return false;
	else {
		current_directory->remove_child(directory_name);
		return true;
	}
}

bool System::ren(string old_directory_name, string new_directory_name) const {
	if (current_directory->find_child_by_name(old_directory_name) == NULL)
		return false;
	else if (current_directory->find_child_by_name(new_directory_name))
		return false;
	else {
		current_directory->find_child_by_name(old_directory_name)->set_name(
				new_directory_name);
		return true;
	}
}

