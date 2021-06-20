#include <iostream.h>
#include <conio.h>
#include <string>
#include <fstream.h>
#include <iomanip>
using namespace std;
class rest2
{
    private:
	string name;
	string location;
	int room;
	string roomtype;
	int price;
	string phone;
    public:
	rest2(string name = " ", string location = " ", int room = 0, string roomtype = " ", int price = 0, string phone = " ")
	{
		this->name = name;
		this->location = location;
		this->room = room;
		this->roomtype = roomtype;
		this->price = price;
		this->phone = phone;
	}
	void setnamenh(string a)
	{
		this->name = a;
	}
	string getnamenh()
	{
		return name;
	}
	void setlocnh(string a)
	{
		this->location = a;
	}
	string getlocnh()
	{
		return location;
	}
	void setroomnh(int a)
	{
		this->room = a;
	}
	int getroomnh()
	{
		return room;
	}
	void setrt(string a)
	{
		this->roomtype = a;
	}
	string getrt()
	{
		return roomtype;
	}
	void setpricenh(int a)
	{
		this->price = a;
	}
	int getpricenh()
	{
		return price;
	}
	void setphonenh(string a)
	{
		this->phone = a;
	}
	string getphonenh()
	{
		return phone;
	}
	friend istream &operator >>(istream &is, rest2 &d)
	{
		is >> d.name;
		is >> d.location;
		is >> d.room;
		is >> d.roomtype;
		is >> d.price;
		is >> d.phone;
	}
};