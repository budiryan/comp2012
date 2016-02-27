/*
 * Submit this file.
 *
 * System::prompt() and System::dir() are already completed. Do NOT modify them.
 * Add the missing implementations of other member functions to this file according to system.h.
 */

#include "system.h"
#include <iostream>

using namespace std;

bool System::prompt()
{
	//IMPORTANT NOTE: It is already completed. Do NOT modify any of its code.

	//show the prompt text
	cout << current_directory->get_full_path() << ">";

	//get the whole line of command
	string command;
	getline(cin, command);

	//perform the command action accordingly
	if(command == "exit") //exit the prompt
	{
		return false; //this will stop the prompt loop
	}
	if(command.substr(0, 2) == "cd") //change directory
	{
		//execute the command with the provided argument if the syntax is correct
		if(command.length() > 3)
		{
			if(!cd(command.substr(3)))
				cout << "The specified sub-directory " << command.substr(3) << " is not found or you are trying to move beyond the root level." << endl;
		}
		else
			cout << "Invalid syntax." << endl; //warn if the syntax is invalid (but it shouldn't happen according to our assumption)
	}
	else if(command.substr(0, 2) == "md") //make directory
	{
		//execute the command with the provided argument if the syntax is correct
		if(command.length() > 3)
		{
			if(!md(command.substr(3)))
				cout << "There already exists a sub-directory which has the same name." << endl;

		}
		else
			cout << "Invalid syntax." << endl; //warn if the syntax is invalid (but it shouldn't happen according to our assumption)
	}
	else if(command.substr(0, 2) == "rd") //remove directory
	{
		//execute the command with the provided argument if the syntax is correct
		if(command.length() > 3)
		{
			if(!rd(command.substr(3)))
				cout << "The specified sub-directory " << command.substr(3) << " is not found." << endl;
		}
		else
			cout << "Invalid syntax." << endl; //warn if the syntax is invalid (but it shouldn't happen according to our assumption)
	}
	else if(command == "dir") //list sub-directories
	{
		//execute the command
		dir();
	}
	else if(command.substr(0, 3) == "ren") //rename directory
	{
		//execute the command with the provided argument if the syntax is correct
		if(command.length() > 4)
		{
			string arguments = command.substr(4);
			unsigned int space_location = arguments.find(" ", 0);
			if(space_location != string::npos) //if a space is found, use substr to separate the arguments with it
			{
				if(!ren(arguments.substr(0, space_location), arguments.substr(space_location+1)))
					cout << "The specified sub-directory " << arguments.substr(0, space_location) << " is not found or the new name could not be used due to a name conflict." << endl;
			}
			else //if a space is not found, warn the user
				cout << "Invalid syntax." << endl; //warn as the syntax is invalid (but it shouldn't happen according to our assumption)
		}
		else
			cout << "Invalid syntax." << endl; //warn if the syntax is invalid (but it shouldn't happen according to our assumption)
	}
	else
	{
		//this case shouldn't happen as we assume the user always inputs valid commands in correct formats
		cout << "Invalid syntax." << endl;
	}

	return true; //this will make the prompt loop continue
}

void System::dir() const
{
	//IMPORTANT NOTE: It is already completed. Do NOT modify any of its code.

	//show an appropriate message according to the number of sub-directories
	switch(current_directory->get_number_of_children())
	{
	case 0:
		cout << "There is no sub-directory." << endl;
		break;
	case 1:
		cout << "There is 1 sub-directory:" << endl;
		current_directory->list_children(); //list all the sub-directories
		break;
	default: //2 or more
		cout << "There are " << current_directory->get_number_of_children() << " sub-directories:" << endl;
		current_directory->list_children(); //list all the sub-directories
		break;
	}
}

