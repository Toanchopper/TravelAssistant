#include <fstream.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <iomanip.h>
using namespace std;
void gotoXY(int x, int y)  
  {  
   COORD coord;  
   coord.X = x;  
   coord.Y = y;  
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
  }  
   void Color(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
   WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  const int saved_colors = GetConsoleTextAttribute(hConsole);
  void loadtitle()
{
	ifstream fi("Display/tieude.txt",ios::in);
	if(!fi)
	{
		cout<<"Nope";
		exit(1);
	}
	string a;
    while(!fi.eof())
    {
    	getline(fi,a);
    	Sleep(80);
    	cout<<a<<endl;
    }
}
void loadend()
{
    ifstream fi("Display/end.txt",ios::in);
	if(!fi)
	{
		cout<<"Nope";
		exit(1);
	}
	string a;
    while(!fi.eof())
    {
    	getline(fi,a);
    	cout<<a<<endl;
    }
}
void loadbg()
{
	ifstream fi("Display/bg.txt",ios::in);
	if(!fi)
	{
		cout<<"Nope";
		exit(1);
	}
	string a;
    while(!fi.eof())
    {
    	getline(fi,a);
    	cout<<a<<endl;
    }
}
 void introduction()
{   
    system("cls");
    system("Color f0");
    PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	ifstream fi30("Display/intro.txt",ios::in);
	if(!fi30)
	{
		cout<<"Nope";
		exit(1);
	}   	
	string a;
    while(!fi30.eof())
    {
    	getline(fi30,a);
    	cout<<a<<endl;
    }
    gotoXY(48,26);
    cout<<"Press ESC or Enter to back";
	ShowConsoleCursor(false);   
}


