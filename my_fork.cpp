#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

using namespace std;
int main()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork error");
	}
	if (pid == 0)
	{
		//child
		cout << "child:" << pid << endl;
	}
	if (pid > 0)
	{
		//parent
		if (wait(0) == -1)
		{
			perror("wait");
		}
		cout << "parent:" << pid << endl;
		//while(1);
	}
	return 0;
}
