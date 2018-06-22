#ifndef COMMAND_H
#define COMMAND_H

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

#endif
