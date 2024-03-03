#pragma warning(disable : 4996)  
#include<iostream>  
#include<iomanip>
#include <stdio.h>        
#include <time.h>     
#include <cctype>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

bool isValidDecimal(const string& input) {
	stringstream ss(input);
	double value;
	return (ss >> value) && (ss.eof());
}
int main() {


    // Get the current time
    time_t currentTime = time(NULL);

    // Convert the current time to a string
    stringstream ss;
    ss << put_time(localtime(&currentTime), "%d/%m/%Y %H:%M:%S");
    string dateString = ss.str();

    // Print the current date
    cout << "Current Date: " << dateString << endl;



}	