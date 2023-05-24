#ifndef _HEADER
#define _HEADER
#include "Container.h"
using namespace std;
class TProduct
{
private:
	string name;
	unsigned long code;
	double cost;  // �� 1 �����
public:
	TProduct();
	TProduct(long code_, std::string name_, double cost_);
	TProduct(const TProduct& obj);
	bool operator==(const TProduct& obj);
	friend ostream& operator<<(ostream& stream, const TProduct& product);
	void setName(string _name) { name = _name; };
	void setCode(unsigned long _code) { code = _code; };
	void setCost(double _cost) { cost = _cost; };
	const string getName()const { return name; };
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
	void setProducts(string name, unsigned long code, double cost,  int index);
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
	unsigned long index;     //����� ����?
	TDate date;
	TTime time;
	TContainer <pair<TProduct,int>> baza;
	TContainer <TReceiptLine> products;
public:
	TReceipt();
	void Add(TProduct _elm); // �������� �������
	void �hange(TProduct _elm); // �������� �������
	void Delete(TProduct _elm); // ������� ������� �� ��� ��������
	TProduct Search(int _code); // ����� ���������� � ������ �� ����
	void scanProducts(int& n);
	int Total(); // ������� ����� ����� ����
};


#endif
