/*
 * Do NOT modify this file.
 * Do NOT submit this file.
 */

#include "system.h"

using namespace std;

/*
 * The entry point of the program.
 * It is already completed. Do NOT modify any of it.
 */
int main()
{
	//create a file system with the root name "C:\\"
	System system("C:\\");

	//keep prompting until the user inputs the "exit" command
	while(system.prompt());

	//exit the program
	return 0;
}
