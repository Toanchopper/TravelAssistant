#include <iostream.h>
#include <conio.h>
#include <string>
#include <fstream.h>
#include <iomanip>
#include "hotel2.cpp"
#include "rest2.cpp"
using namespace std;

class city2
{
    private:
	string name;
	string bus;
	int sun;
	string ss;
	int rain;
	int index;
	string price;
	string cuisine;
	
    public:
	hotel2 ho2;
	rest2 re2;
	city2(string name = " ", string bus = " ", int sun = 0, string ss = " ", int rain = 0,int index = 0, string price= " ",string cuisine=" ",hotel2 ho2=" ",rest2 re2=" ")
	{
		this->name = name;
		this->bus = bus;
		this->ss = ss;
		this->price = price;
		this->sun = sun;
		this->rain =rain;
		this->index = index;
		this->cuisine = cuisine;
		this->ho2 = ho2;
		this->re2 = re2;
	}
	void setnamect(string a)
	{
		this->name = a;
	}
	string getnamect()
	{
		return name;
	}
	void setbusct(string a)
	{
		this->bus = a;
	}
	string getbusct()
	{
		return bus;
	}
	void setssct(string a)
	{
		this->ss = a;
	}
	string getssct()
	{
		return ss;
	}
	void setprct(string a)
	{
		this->price = a;
	}
	string getprct()
	{
		return price;
	}
	void setfct(string a)
	{
		this->cuisine = a;
	}
	string getfct()
	{
		return cuisine;
	}
	void setsun(int a)
	{
		this->sun = a;
	}
	int getsun()
	{
		return sun;
	}
	void setrain(int a)
	{
		this->rain = a;
	}
	int getrain()
	{
		return rain;
	}
	void setindex(int a)
	{
		this->index = a;
	}
	int getindex()
	{
		return index;
	}
};