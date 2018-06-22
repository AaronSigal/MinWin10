#include <iostream>
#include <string>
#include <io.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <windows.h>
#include <ctime>

using namespace std;
/* KNOWN ISSUES:
	- When not run as admin, program fails
	- Log isn't named by date
*/

vector<tuple<string, string, bool>> packages;

inline bool isFileExists (const string& fileName) {
   ifstream ifs(fileName.c_str());
   return ifs.good();
}

//writes the package_list_save script to the local folder
void writePackageListSave() {
	ofstream fs;
	fs.open("package_list_save.ps1");
	fs << "Start-Transcript -Path ts.txt -Force" << endl;
	fs << "Get-AppxPackage" << endl;
	fs << "Stop-transcript" << endl;
	fs.close();
}

string toRemoveCommand(const string &packageName) {
	return ("Remove-AppxPackage " + packageName + "\n");
}



//write a txt file to the local dir. Read from this to save on memory.
void write3db() {
	ofstream fs;
	fs.open("3db.ps1");
	
	for(tuple<string, string, bool> tp: packages) {
		
		if (((get<1>(tp)).find("Windows") == string::npos) && 
		((get<1>(tp)).find("Microsoft") == string::npos) && 
		((get<1>(tp)).find("windows") == string::npos) && 
		((get<1>(tp)).find("printer") == string::npos) &&
		((get<1>(tp)).find("Printer") == string::npos) &&
		((get<1>(tp)).find("Driver") == string::npos)){
			clog << "Found a non-windows app installed:" << get<1>(tp) << endl;
			
			fs << toRemoveCommand(get<1>(tp)) << endl;
			clog << "	Set to remove succesfully" << endl;
		}
	}
	
	fs.close();
}

void writeMdb() {
	ofstream fs;
	fs.open("Mdb.ps1");
	
	for(tuple<string, string, bool> tp: packages) {
		
	}
	
	fs.close();
}

void writeMdbx() {
	ofstream fs;
	fs.open("Mdbx.ps1");
	
	for(tuple<string, string, bool> tp: packages) {
		
	}
	
	fs.close();
}

void writeFdb() {
	ofstream fs;
	fs.open("Fdb.ps1");
	
	for(tuple<string, string, bool> tp: packages) {
		
	}	
	
	fs.close();
}

void writeCdb() {
	ofstream fs;
	fs.open("Cdb.ps1");
	
	for(tuple<string, string, bool> tp: packages) {
		
	}	
	
	fs.close();
}

//loads a list of installed packages into an easy-to-traverse container.
 void loadPackageList(string PATH) {
	 
	string temp;//a string to be used for any temporary holding of values
	
	ifstream fs;//create an in-file-stream
	fs.open(PATH);
	
	//skip 17 lines (all the junk up front) 
	for (int i = 0; i < 17; ++i) {
		getline(fs, temp);
	}
	
	//clear out temp just in case.
	temp = "";
	
	string currentLine;
	string name;
	string packageName;
	bool isFramework;
	
	while (getline(fs, currentLine)) {
		
		//read: name
		if ((currentLine.length() > 4) && (currentLine.substr(0, 4) == "Name")) {
			
			//get the name
			name = currentLine.substr(20);
			
			//skip four more lines
			for (int i = 0; i < 4; ++i) {
				getline(fs, temp);
			}
			
			//grab the fullPackageName line
			getline(fs, currentLine);
			
			packageName = currentLine.substr(20);
			
			//skip a line
			getline(fs, temp);
			
			//get the isFramework line
			getline(fs, temp);
			
			if (temp.substr(20) == "False") {
				isFramework = false;
			} else {
				isFramework = true;
			}
			
			//store all the relevent details of the package as a tuple
			tuple<string, string, bool>packageData;
			get<0>(packageData) = name;
			get<1>(packageData) = packageName;
			get<2>(packageData) = isFramework;
			
			packages.push_back(packageData);
		}
	}

		//DEBUG:
		/*for (tuple<string, string, bool> tp: packages) {
			clog << "Name: "          << get<0>(tp) << endl;
			clog << "  PackageName: " << get<1>(tp) << endl;
			clog << "  IsFramework: " << get<2>(tp) << endl;
		}*/
 }


//checks if a packagename is on the whitelist
bool whiteListed(string packageName) {
}

int main() {
	//redirect logging and err streams to a log file
	ofstream ofs("log.log");
	
	clog.rdbuf(ofs.rdbuf());
	cerr.rdbuf(ofs.rdbuf());
	
	//user-prompt
	cout << "| Welcome to Windows Sanitizer    |" << endl;
	cout << "| Developed by Aaron Sigal, 2017  |" << endl;
	cout << "| By using this program you       |" << endl;
	cout << "| hereby agree that any and all   |" << endl;
	cout << "| damage that may result from     |" << endl;
	cout << "| the use of this program is      |" << endl;
	cout << "| solely your resonsibility and   |" << endl;
	cout << "| that I am not liable in any way.|" << endl;

	cout << endl;
	cout << "Which script would you like to load?" << endl;
	cout << "| 3rd Party Debloat                      (3db) " << endl;//max part 1 length of 38
	cout << "| Microsoft app debloat, no XBox removal (Mdb) " << endl;
	cout << "| Microsoft app debloat, XBox removal    (Mdbx)" << endl;
	cout << "| Full app debloat                       (Fdb) " << endl;
	cout << "| Custom debloat                         (Cdb) " << endl;
	cout << "| Full app debloat + custom debloat      (Fcdb)" << endl;
	cout << "| Exit                                   (Exit)" << endl;	
	cout << endl;
	
	//stores user input for selecting a script
	string userInput;
	
	//bool for determining if the while loop for user input needs to run again.
	bool done = false;
	
	cout << "Please enter one of the above options by using the corresponding code on the right." << endl;
	while (!done) {
		getline(cin, userInput);
		
/******************************************************************************************************************************************************************
* These functions should not be used for anything other than pre-initialization methods. Only put things here that need to occur before the removal script is run *
*******************************************************************************************************************************************************************/
		
		//If the exit option is selected
		if (userInput == "Exit" || userInput == "exit") {
			
			//kill the program
			done = true;
			return 0;
		}
		
		if (userInput == "3db" || userInput == "3DB") {
			done = true;
			
			//sanitize the input
			userInput = "3db";
			
			write3db();
		}
		
		else if (userInput == "Mdb" || userInput == "MDB" || userInput == "mdb") {
			done = true;
			
			//sanitize user input for later use.
			userInput = "Mdb";
		}
		
		else if (userInput == "Mdbx" || userInput == "MDBX" || userInput == "mdbx") {
			done = true;
			
			//sanitize user input
			userInput = "Mdbx";
		}
		
		else if (userInput == "Fdb" || userInput == "FDB" || userInput == "fdb") {
			done = true;
			
			//sanitize user input
			userInput = "Fdb";
		}
		
		else if (userInput == "Cdb" || userInput == "CDB" || userInput == "cdb") {
			done = true;
			
			//sanitize user input
			userInput = "Cdb";
		}
		
		else if (userInput == "Fcdb" || userInput == "FCDB" || userInput == "fcdb") {
			done = true;
			
			//sanitize user input
			userInput = "Fcdb";
		}
		
	}
	
/******************************************************************************************************************************************************************
* End of the Pre-Intialization phase                                                                                                                              *
*******************************************************************************************************************************************************************/
	
	//At this point we can be sure the user wants to continue with the program, so executing these scripts isn't wasteful
	clog << "Extracting files..." << endl;
	writePackageListSave();
	clog << "Extracting files... <package_list_save.ps1>" << endl;
	system("powershell.exe -windowstyle hidden Set-ExecutionPolicy RemoteSigned \n");
	system("powershell.exe -windowstyle hidden .//package_list_save.ps1");
	
	loadPackageList("ts.txt");
	
/******************************************************************************************************************************************************************
* These functions should be used to call only the scripts that perform the removal of apps, or the auxialary methods required to launch them.                     *
*******************************************************************************************************************************************************************/
	
	if (userInput == "3db") {
		write3db();
		system("powershell.exe .//3db.ps1");
	}
		
	else if (userInput == "Mdb") {
		
	}
		
	else if (userInput == "Mdbx") {

	}
		
	else if (userInput == "Fdb") {

	}
		
	else if (userInput == "Cdb") {

	}
		
	else if (userInput == "Fcdb") {

	}
	
	//vector to hold the package IDs of all the installed programs.
	vector<string> packageIDs;
	
}