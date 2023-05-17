#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
#include "Header.h"
#include "Container.h"
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

void TReceiptLine::setProducts(string name, unsigned long code, double cost, int index) 
{ 
	product[index].setName(name);
	product[index].setCode(code);
	product[index].setCost(cost); 
}


void scanProducts(TContainer < pair < TProduct, int > > _product, int& n)
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
	TProduct tmp;
	for (int i = 0; i < n; i++)
	{
		infile >> name >> code >> cost >> count;
		tmp.setName(name);
		tmp.setCode(code);
		tmp.setCost(cost);
		pair<TProduct, int> tmp1;
		tmp1.first = tmp;
		tmp1.second = count;
		_product.Add(tmp1);
	}
}

void TReceiptLine::printProducts(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << getProductS(i) << "   " <<
			getProductCde(i) << "     " <<
			getProductCst(i) << "     " << endl;
	}
}



void TReceipt::Add(TProduct _elm)
{
	;
}