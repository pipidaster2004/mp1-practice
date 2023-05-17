#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "Header.h"
#include "Container.h"
using namespace std;
int main()
{
	/*TTime y;
	y.setTime();
	cout << y.hour << ":" << y.minute << ":" << y.second << endl;
	TDate z;
	z.setDate();
	cout << z.day << "." << z.month << "." << z.year << endl;
	cout << endl;

	TContainer<string> x(20);
	for (int i = 0; i < x.getSize(); i++)
	{
		int u = i;
		x.Add(to_string(u));
	}
	for (int i = 0; i < x.getSize(); i++)
	{
		cout << x[i] << endl;
	}
	cout << endl;

	cout << x.Ñount() << endl;
	cout << endl;

	cout << x.Sizestep() << endl;
	cout << endl;

	x.Del("12");
	x.Del(11);
	cout << x.Ñount() << endl;
	cout << endl;
	*/
	int p=0;
	TContainer < pair < TProduct, int > > zxc;
	scanProducts(zxc, p);
	return 0;
}

