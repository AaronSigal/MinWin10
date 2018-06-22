#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>


//split a string into indivudal words based on a delimiter character. 
//See: https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
std::vector<std::string> split(const std::string& s, char delimiter) {
	//vector to store tokens
    std::vector<std::string> tokens;
	
	//variable to temporarily store the current token
	std::string token;
    
	//in-string-stream to iterate through the input string
	std::istringstream tokenStream(s);
	
	//iterate through the iss by delimiter, and store iterated tokens in 'string token'
    while (std::getline(tokenStream, token, delimiter)) {
       tokens.push_back(token); //add the current token to the vector
    }
   
   //return the vector
   return tokens;
}

#endif