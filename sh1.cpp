#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
	string command;
	cout << "\tOlya system shell\n\n";

	while ( command != "exit" )
	{
		if ( command == "ls" )
			system("ls");
		else if ( command == "vim" )
			system("vim");
		else if ( command == "date")
			system("date");
		else if ( command == "help" )
			cout << "ls\tdate\tvim\tpwd\thelp\texit\n";		
		else if ( command == "pwd") 
			system("pwd");
		else if ( command != "\0" )
			cout << "ERROR\n";
		cout << "#shell--->>";
		cin >> command;
	}	

	return 0;
}
