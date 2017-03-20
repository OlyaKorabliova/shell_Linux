#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;
int main()
{
	char* args[3];

	string ls = "ls";
	string dash_l = "-l";	
	
	args[0] = (char*)ls.c_str();
	args[1] = (char*)dash_l.c_str();
	args[2] = NULL;
	
	if ( execvp(args[0], args) == -1)
	{
		perror("exec");
	}
	return 0;
}
