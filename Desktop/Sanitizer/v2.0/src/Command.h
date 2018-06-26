#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include "Terminal.h"

//Abstract command class for Command pattern
class Command {
	public:
		Command() { }
		
		//Do this to enact the command
		virtual void execute() = 0;

};

//Lists software version and information
class AboutCommand : public Command {
	public:
		void exectue();
};

//Resets client so that it is in a default configuration
class ResetCommand : public Command {
	public:
		void exectute();
};

//Clear the command history
class ClearHistoryCommand : public Command {
	public:
		void execute();
};

class ExitCommand : public Command {
	public:
		void execute();
};

//Smart pointer definition for Commands.
typedef std::shared_ptr<Command> CommandPtr;
#endif
