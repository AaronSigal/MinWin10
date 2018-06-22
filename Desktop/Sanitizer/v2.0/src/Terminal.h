#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

#include "Command.h"
#include "Utils.h"

//Singleton class. 
class Terminal {
	public:
		//return an instance of Terminal.
		static Terminal* instanceOf() {	
			
			//create a new instance if one doesn't exist
			if (instance) {
				instance = new Terminal();
			}
		}
		
		//read in a line of user input and break it into a vector of tokens
		void readCommand() {
			std::string userInput;
			
			std::getline(std::cin, userInput);
			
			std::vector<std::string> tokens = split(userInput, ' ');
		}
		
		void printPrompt() {
			
			//user-prompt
			std::cout << "| Welcome to Windows Sanitizer    |" << std::endl;
			std::cout << "| Developed by Aaron Sigal, 2018  |" << std::endl;
			std::cout << "| By using this program you       |" << std::endl;
			std::cout << "| hereby agree that any and all   |" << std::endl;
			std::cout << "| damage that may result from     |" << std::endl;
			std::cout << "| the use of this program is      |" << std::endl;
			std::cout << "| solely your resonsibility and   |" << std::endl;
			std::cout << "| that I am not liable in any way.|" << std::endl;

			std::cout << std::endl << "Use 'help' for assistance" << std::endl;
		}
		
		bool isDone() {
			return done;
		}
		
		void setDone(bool done) {
			this->done = done;
		}
		
	protected:
	
		//protected constructors only
		Terminal() {
			
		}
		
	private:
		//all the commands used in the past
		std::stack<Command*> commandHistory;
		
		//the pointer to the actual instance of the single terminal
		static Terminal* instance;
		
		//if true, program terminates
		bool done = false;

};

//Initialize the pointer to nothing
Terminal* Terminal::instance = 0;
#endif