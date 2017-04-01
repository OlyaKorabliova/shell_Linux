#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sstream>  //std::istringstream
#include <string>   //std::string

using namespace std;
int launch(string command)
{
    int status;
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        //child process
        cout << "Child:" << pid << endl;
        vector<string> list_of_commands = {"ls", "cd", "pwd", "rm", "mv", "cp", "mkdir"};
        istringstream args (list_of_commands);
        vector<string> tokens{istream_iterator<string>{args},
                              istream_iterator<string>{}};
        if (std::find(tokens[0]) == list_of_commands.end())
        {
            std::cout << "Invalid command!" << std::endl;
        }
        else if (std::find(" ") == command.end)
                command = command.substr(0, find(" "));

    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
        //parent process
//        if (wait(0) == -1)
//        {
//            perror("Wait");
//        }
//        cout << "parent:" << pid << endl;

    }
    return 1;   //EXIT_SUCCESS;
}

int main()
{
    string command = "";
    cout << "\tOlya system shell\n\n";

    while ( command != "exit" )
    {
        cout << "#shell--->>";
        cin >> command;
        launch(command);
    }
    return 0;
}
