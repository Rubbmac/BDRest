#pragma once
#pragma warning(disable : 4996)  //necessario para permitir o uso da funcao "localtime" para converter a data atual
#include <iostream>
#include <time.h>	
#include <string>
#include <ctime>
#include <stdio.h> 
#include <sstream>
#include <cctype>
#include<iomanip>

using namespace std;

class criar {

private:

public:
	static void matStock(string** m);
	static void matCliente(string** m);
	static void matRecibo(string** m);
};

