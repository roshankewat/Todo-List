#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

bool AddTask(std::string task) {
	std::ofstream writefile("todo.txt", std::ios::app);
	
	if (!writefile.is_open()) {
		std::cout << "Unable to open todo file" << std::endl;
		return false;
	}
	else {
		writefile<< task <<" - Not Completedl" "\n";
		writefile.close();
		return true;
	}
}

bool ListTask() {
	std::ifstream readfile("todo.txt");
	std::string line;

	if (!readfile.is_open()) {
		std::cout << "Unable to open todo.txt" << std::endl;
		return false;
	}
	else {
		while (getline(readfile, line)) {
			std::cout << line << std::endl;
		}
		return true;
	}
}

bool ClearAllTask() {
	std::ofstream writefile("todo.txt");
	if (!writefile.is_open()) {
		std::cout << "Unable to open todo file" << std::endl;
		return false;
	}
	else {
		writefile << "";
		return true;
	}
}

bool IsInArray(std::string valueToCompare,std::string* commands, int length) {
	for (int i = 0;i < length;i++) {
		if (commands[i] == valueToCompare) {
			return true;
		}
		else {
			continue;
		}
	}
	return false;
}

int main()
{
	std::cout << "Todo CLI App - Build by Roshan Kewat"<<std::endl;

	std::string commands[] = { "addtask", "listtask", "help", "exit", "clear", "deletetask", "clearalltask"};

	int commandLength = sizeof(commands) / sizeof(commands[0]);

	std::string userCommand;
	while (userCommand != "exit") {
		std::cout << ">> ";
		getline(std::cin, userCommand);

		if (!IsInArray(userCommand, commands, commandLength)) {
			std::cout << "No command related to - "<<userCommand<< std::endl;
			std::cout << "Type 'help' to know more." << std::endl;
		}

		else if (userCommand == "clear") {
			system("cls");
		}

		else if (userCommand == "addtask") {
			std::cout << "task>> ";
			getline(std::cin, userCommand);
			bool isAdded = AddTask(userCommand);
			if (!isAdded) {
				std::cout << "Unable to add task" << std::endl;
			}
			else {
				std::cout << "Task Added" << std::endl;
			}
		}

		else if (userCommand == "listtask") {
			bool isListed = ListTask();
			if (!isListed) {
				std::cout << "Unable to list tasks" << std::endl;
			}
		}

		else if (userCommand == "clearalltask") {
			if (!ClearAllTask()) {
				std::cout << "Unable to clear all task" << std::endl;
			}
			else {
				std::cout << "All tasks are cleared" << std::endl;
			}
		}
	}

	return 0;
}
