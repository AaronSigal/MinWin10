#include <iostream>
#include <string>
#include <io.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <fstream>

#include "Terminal.h"

int main() {
	//redirect logging and err streams to a log file
	
	std::ofstream ofs("log.log");		
	std::clog.rdbuf(ofs.rdbuf());
	std::cerr.rdbuf(ofs.rdbuf());
	
	
	Terminal::getReference()->printPrompt();
	//((Terminal::instanceOf())->done) = false;
	
	while (!Terminal::getReference()->isDone()) {
			Terminal::getReference()->readCommand();
	}
	
	
	return 0;
};