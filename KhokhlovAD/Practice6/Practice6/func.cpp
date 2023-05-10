#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
#include "Header.h"
using namespace std;

void TTime::setTime()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	second = ltm->tm_sec;
	minute = ltm->tm_min;
	hour = ltm->tm_hour;
}

void TDate::setDate()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	day = ltm->tm_mday;
	month = ltm->tm_mon;
	year = 1900+ ltm->tm_year;
}

void TReceiptLine::setProducts(string name, unsigned long code, double cost, int count, int index) 
{ 
	product[index].setName(name);
	product[index].setCode(code);
	product[index].setCost(cost); 
	product[index].setCount(count);
}


void TReceiptLine::scanProducts(int& n)
{
	string name;
	unsigned long code;
	double cost;
	int count;
	string path;
	cout << "enter path" << endl;
	cin >> path;
	ifstream infile(path);
	if (!infile)
	{
		throw "file not finde";
	}
	infile >> n;
	for (int i = 0; i < n; i++)
	{
		infile >> name >> code >> cost >> count;
		setProducts(name, code, cost, count, i);
	}
}

void TReceiptLine::printProducts(int n)
{
	
		;
}