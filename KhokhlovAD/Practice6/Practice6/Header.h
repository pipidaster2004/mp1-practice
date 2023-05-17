#ifndef _HEADER
#define _HEADER
#include "Container.h"
class TProduct
{
private:
	std::string name;
	unsigned long code;
	double cost;  // за 1 товар
public:
	void setName(std::string _name) { name = _name; };
	void setCode(unsigned long _code) { code = _code; };
	void setCost(double _cost) { cost = _cost; };
	const std::string getName()const { return name; };
	const unsigned long getCode()const { return code; };
	const double getCost()const { return cost; };
};

class TReceiptLine
{
private:
	int k;
	double sum;
	TProduct* product;
public:
	void setProducts(std::string name, unsigned long code, double cost,  int index);
	void printProducts(int n);
	const std::string getProductS(int ind)const { return product[ind].getName(); };
	const unsigned long getProductCde(int ind)const { return product[ind].getCode(); };
	const double getProductCst(int ind)const { return product[ind].getCost(); };
};

struct TDate
{
	int year;
	int month;
	int day;
	void setDate();
};

struct TTime
{
	int hour;
	int minute;
	int second;
	void setTime();
};

class TReceipt
{
private:
	unsigned long index;     //номер чека?
	TDate date;
	TTime time;
	TContainer <TReceiptLine> products;
public:
	void Add(TProduct _elm); // добавить элемент
	void Сhange(TProduct _elm); // изменить элемент
	void Delete(TProduct _elm); // удалить элемент по его значению
	TProduct Search(int _code); // поиск информации о товаре по коду
	int Total(); // подсчет общей суммы чека
};

void scanProducts(TContainer < pair< TProduct, int> > _product, int& n);
#endif
