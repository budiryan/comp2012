/*
 * Do NOT modify this file.
 * Do NOT submit this file.
 */

#ifndef DIRECTORY_H_
#define DIRECTORY_H_

#include <string>

using namespace std;

/*
 * This is the class that represents a directory in the file system.
 */
class Directory
{
public:
	/*
	 * It is the constructor.
	 * Initialize all the member variables with the provided parameters.
	 * number_of_children should be 0.
	 * IMPORTANT NOTE: children should point to a dynamic array of Directory pointers of size 0, i.e., "new Directory*[0]".
	 */
	Directory(string name, Directory* parent);

	/*
	 * It is the destructor.
	 * Release all the memory that is held by children dynamic array and each individual child object.
	 * Hint: Use both delete and delete [] correctly.
	 */
	~Directory();

	/*
	 * Change the directory name to new_name.
	 */
	void set_name(string new_name);

	/*
	 * Return the parent pointer.
	 */
	Directory* get_parent() const;

	/*
	 * Return the number of children.
	 */
	int get_number_of_children() const;

	/*
	 * Return the full path of the directory.
	 * Be careful with the format.
	 * It should be in a format like "C:\", "C:\abc", or "C:\abc\def".
	 * Note that the ">" should not be included as it will be added later in the System::prompt function.
	 * Note that the "\" only appears at the end when the directory is the root.
	 */
	string get_full_path() const;

	/*
	 * Add a new child (i.e. sub-directory).
	 * IMPORTANT NOTE: the new child should always be added to the end of the children array so that when we list the children with list_children(), the new child would be at the bottom of the list.
	 * Hint: You will need to expand the children dynamic array.
	 * If the size of children array is N, then you need to create a new array that has the size of N+1 so that it can hold the existing children as well as the new child.
	 * Remember to have children point to the newly created array at the end.
	 */
	void add_child(string child_name);

	/*
	 * Remove the child which has the name child_name.
	 * You can assume that such child does exist. (the checking should actually already be done in the rd function of System)
	 * Remember to release the memory held by the child that has to be deleted.
	 */
	void remove_child(string child_name);

	/*
	 * Print the names of the children (sub-directories).
	 * There should be exactly N lines when there are N children.
	 * The children should be printed in the order of creation time with the oldest child printed at the top and newest child printed at the bottom.
	 * No extra space and extra newlines should be printed.
	 * Refer to the given examples in the assignment description.
	 */
	void list_children() const;

	/*
	 * Find and return the pointer that points to the child that has the name child_name.
	 * If the child is not found, return NULL.
	 */
	Directory* find_child_by_name(string child_name) const;

private:
	string name; //The name of the directory
	Directory* parent; //The pointer that points to the parent; it should be NULL when this directory is the root
	Directory** children; //The pointer that points to a dynamic array of Directory pointers (i.e. Directory*) which point to the direct children (i.e. the sub-directories)
	int number_of_children; //The number of direct children (i.e. the sub-directories)
};


#endif /* DIRECTORY_H_ */
