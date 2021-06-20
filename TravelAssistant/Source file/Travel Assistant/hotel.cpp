#include <iostream.h>
#include <conio.h>
#include <string>
#include <fstream.h>
#include <iomanip>
using namespace std;
class hotel
{
private:
	string name;
	string location;
	int room;
	int roomleft;
	int price;
	string phone;
public:
	hotel(string name=" ",string location=" ",int room = 0,int roomleft=0,int price=0,string phone=" ")
	{
		this->name = name;
		this->location = location;
		this->room = room;
		this->roomleft = room;
		this->price = price;
		this->phone = phone;
	}
	void setnameks(string a)
	{
		this->name = a;
	}
	string getnameks()
	{ 
		return name;
	}
	void setlocks(string a)
	{
		this->location = a;
	}
	string getlocks()
	{
		return location;
	}
	void setroomks(int a)
	{
		this->room = a;
	}
	int getroomks()
	{
		return room;
	}
	void setrlks(int a)
	{
		this->roomleft = a;
	}
	int getrlks()
	{
		return roomleft;
	}
	void setpriceks(int a)
	{
		this->price = a;
	}
	int getpriceks()
	{
		return price;
	}
	void setphoneks(string a)
	{
		this->phone = a;
	}
	string getphoneks()
	{
		return phone;
	}
	friend istream &operator >>(istream &is,hotel &d)
	{
		is>>d.name;
		is>>d.location;
		is>>d.room;
		is>>d.roomleft;
		is>>d.price;
		is>>d.phone;
	}
};