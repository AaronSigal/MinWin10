#include <iostream>
#include <string>
#include <io.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <fstream>

#include "Terminal.h"
#include "Utils.h"

int main() {
	//redirect logging and err streams to a log file
	/*
	std::ofstream ofs("log.log");		
	std::clog.rdbuf(ofs.rdbuf());
	std::cerr.rdbuf(ofs.rdbuf());
	*/
	//false if the user is still using the terminal, true if they are done using it
	
	
	Terminal::instanceOf()->printPrompt();
	//((Terminal::instanceOf())->done) = false;
	
	while (!Terminal::instanceOf()->done) {
			Terminal::instanceOf()->readCommand();
	}
	
	
	return 0;
};