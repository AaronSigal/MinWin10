#include "Command.h"
#include "Terminal.h"

void ExitCommand::execute() {
	Terminal::getReference()->setDone(true);
}