/*
 * Do NOT modify this file.
 * Do NOT submit this file.
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "directory.h"
#include <string>

using namespace std;

/*
 * This is the class that simulates the DOS system.
 * For any comments or instructions that are unclear to you, refer to the FAQ and examples given in the assignment description.
 */
class System
{
public:
	/*
	 * It is the constructor that initializes the two private member variables.
	 * Create the root directory with the provided name.
	 * Make the root directory the current directory.
	 */
	System(string root_name);

	/*
	 * It is the destructor.
	 * Delete the root.
	 * Hint: as the root is deleted, all the children shall be deleted automatically by the Directory destructor if that is implemented correctly.
	 */
	~System();

	/*
	 * Show the current path in the prompt format like "C:\abc>" and "C:\>".
	 * Retrieve and execute the command input by the user.
	 * IMPORTANT NOTE: It is already completed. Do NOT modify any of its code.
	 */
	bool prompt();

	/*
	 * Change the current directory to the directory according to directory_name.
	 * If ".." is given as directory_name, and that the current directory is the root directory, do nothing and return false.
	 * if ".." is given as directory_name, and that the current directory is not the root directory, change the current directory to its parent (i.e. moving up one level), and return true.
	 * If no sub-directory (direct child of the current directory) has the name directory_name, do nothing and return false.
	 * In any other case, change the current directory to the sub-directory that has the name directory_name, and return true.
	 */
	bool cd(string directory_name);

	/*
	 * Create a new sub-directory under the current directory with the name directory_name.
	 * If there is a sub-directory that has the same name, do nothing and return false.
	 * Otherwise, create the new sub-directory and return true.
	 */
	bool md(string directory_name) const;

	/*
	 * Remove a sub-directory (direct child of the current directory) that has the name directory_name.
	 * Do nothing and return false if the sub-directory is not found with the provided name.
	 * Otherwise, remove the sub-directory and return true.
	 */
	bool rd(string directory_name) const;

	/*
	 * List all the sub-directories (direct children of the current directory) that are located under the current directory.
	 * IMPORTANT NOTE: It is already completed. Do NOT modify any of its code.
	 */
	void dir() const;

	/*
	 * Rename a sub-directory that has the name old_directory_name to new_directory_name.
	 * Do nothing and return false if the sub-directory is not found with the provided old_directory_name.
	 * Do nothing and return false if there is a sub-directory's name being new_directory_name already.
	 * Otherwise, perform the renaming and return true.
	 */
	bool ren(string old_directory_name, string new_directory_name) const;

private:
	Directory* root; //The pointer that points to the root directory
	Directory* current_directory; //The pointer that points to the current directory
};


#endif /* SYSTEM_H_ */
