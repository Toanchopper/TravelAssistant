#include <fstream.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <iomanip.h>
#include "display.cpp"
using namespace std;
    int a[100][100],a2[100][100];
	float timeh[100][100],timeh2[100][100];
	int N,N2,m,s;
	city c[100],d[100];	
	string loadrow[50],loadrow2[50];
	string ten[100],bus[100],ss[100],price[100],food[100],ten2[100],bus2[100],ss2[100],price2[100],food2[100];
	int fee[100][100],sun[20],rain[20],fee2[100][100],sun2[20],rain2[20];
	hotel hot[100],hot2[100];
	rest res[100],res2[100];
	bool load = false;
	bool ex = false;
void generalinfo(string ten[],string bus[],string ss[])
{
	system("cls");
    system("Color f0");
    PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	ifstream fi30("Display/generalinfo.txt",ios::in);
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
    gotoXY(18,8);
    cout<<"STT";
    gotoXY(29,8);
    cout<<"TEN THANH PHO";
    gotoXY(51,8);
    cout<<"BUS";
    gotoXY(74,8);
    cout<<"DANH LAM THANG CANH";
    int y=12;
    for(int i=0;i<N;i++)
    {
    	gotoXY(19,y);
    	cout<<i+1;   	
    	gotoXY(30,y);
    	cout<<ten[i];
    	gotoXY(51,y);
        cout<<bus[i];
        gotoXY(74,y);
        cout<<ss[i];
		y+=1;
    }
    for(int i=0;i<N2;i++)
    {
    	gotoXY(19,y);
    	cout<<i+8;   	
    	gotoXY(30,y);
    	cout<<ten2[i];
    	gotoXY(51,y);
        cout<<bus2[i];
        gotoXY(74,y);
        cout<<ss2[i];
		y+=1;
    }
    ShowConsoleCursor(false);
}
void detailinfo()
{
	ShowConsoleCursor(true);
	system("cls");
    system("Color f0");
    PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	ifstream fi30("Display/nhapsl.txt",ios::in);
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
    gotoXY(49,10);
    cout<<"NHAP SO THANH PHO";
    gotoXY(49,11);
	cout<<"MUON XEM <TOI DA 2>";
	gotoXY(56,13);
	int c;
	cin>>c;
    system("cls");
    system("Color f0");
    PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	ifstream fi("Display/nhapsl.txt",ios::in);
	if(!fi)
	{
		cout<<"Nope";
		exit(1);
	}   	
	string a3;
    while(!fi.eof())
    {
    	getline(fi,a3);
    	cout<<a3<<endl;
    }
    gotoXY(49,10);
    cout<<"NHAP TEN THANH PHO";	
	string tn[c];
	int y=12;
    for(int i=0;i<c;i++)
    {
	    gotoXY(54,y);
	    cin>>tn[i];
	    PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	    y++;
    }
        ShowConsoleCursor(false);
        system("cls");
        system("Color f0");
        PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	    ifstream fi31("Display/detailinfo.txt",ios::in);
	    if(!fi31)
	   {
		  cout<<"Nope";
		  exit(1);
       }   	
    	string a2;
        while(!fi31.eof())
      {
    	 getline(fi31,a2);
    	 cout<<a2<<endl;
      } 
      int x=20;
      for(int i=0;i<c;i++)
      {
      	for(int j=0;j<N;j++)
      	{
	      	if(tn[i] == ten[j])
	      	{
      	      gotoXY(x,8);
      	      cout<<"THANH PHO THU "<<i+1;
      	      gotoXY(x,10);
      	      cout<<"+ Ten thanh pho: "<<ten[j];
      	      gotoXY(x,12);
      	      cout<<"+ Tuyen bus: "<<bus[j];
      	      gotoXY(x,14);
      	      cout<<"+ Danh lam thang canh: "<<ss[j];
      	      gotoXY(x,16);
      	      cout<<"+ Nhiet do TB: "<<sun[j]<<" do c";
      	      gotoXY(x,18);
      	      cout<<"+ Luong mua TB: "<<rain[j]<<" mm";
      	      gotoXY(x,20);
      	      cout<<"+ Muc song: "<<price[j];
      	      gotoXY(x,22);
      	      cout<<"+ Nha hang: "<<res[j].getnamenh();
      	      gotoXY(x,24);
      	      cout<<"+ Khach san: "<<hot[j].getnameks();
	      	}
	      	else 
	      	{
	      		for(int j=0;j<N2;j++)
	      		{
		      		if(tn[i] == ten2[j])
		      		{
		      			 gotoXY(x,8);
      	                 cout<<"THANH PHO THU "<<i+1;
                         gotoXY(x,10);
      	                 cout<<"+ Ten thanh pho: "<<ten2[j];
      	                 gotoXY(x,12);
      	                 cout<<"+ Tuyen bus: "<<bus2[j];
      	                 gotoXY(x,14);
      	                 cout<<"+ Danh lam thang canh: "<<ss2[j];
      	                 gotoXY(x,16);
      	                 cout<<"+ Nhiet do TB: "<<sun2[j]<<" do c";
      	                 gotoXY(x,18);
      	                 cout<<"+ Luong mua TB: "<<rain2[j]<<" mm";
      	                 gotoXY(x,20);
      	                 cout<<"+ Muc song: "<<price2[j];
      	                 gotoXY(x,22);
      	                 cout<<"+ Nha hang: "<<res2[j].getnamenh();
      	                 gotoXY(x,24);
      	                 cout<<"+ Khach san: "<<hot2[j].getnameks();
		      		}
		      	}
	      	}
	      } 
		  x+=50;    	
      }	
}
void setdata(city c[],int a[][100],hotel hot[],rest res[],float timeh[][100],string ten[],string bus[],int fee[][100],string ss[],string price[],int sun[],int rain[],string food[],int m,int N)
{
   for(int i=0;i<m;i++)
   {
        c[i].setnamect(ten[i]);
   }
   for(int i=0;i<m;i++)
   {
        c[i].setbusct(bus[i]);
   }
   for(int i=0;i<m;i++)
   {
        c[i].setindex(i);
   }
   for(int i=0;i<m;i++)
   {
   	    c[i].setssct(ss[i]);
   }
   for(int i=0;i<m;i++)
   {
   	    c[i].setsun(sun[i]);
   }
   for(int i=0;i<m;i++)
   {
   	    c[i].setrain(rain[i]);
   }
   for(int i=0;i<m;i++)
   {
   	    c[i].setprct(price[i]);
   }
   for(int i=0;i<m;i++)
   {
   	    c[i].setfct(food[i]);
   }
   for(int i=0;i<m;i++)
   {
   	    
   	    c[i].ho.setnameks(hot[i].getnameks());
   	    c[i].ho.setlocks(hot[i].getlocks());
   	    c[i].ho.setroomks(hot[i].getroomks());
   	    c[i].ho.setrlks(hot[i].getrlks());
   	    c[i].ho.setpriceks(hot[i].getpriceks());
   	    c[i].ho.setphoneks(hot[i].getphoneks());
   }
   for(int i=0;i<m;i++)
   {
   	    c[i].re.setnamenh(res[i].getnamenh());
   	    c[i].re.setlocnh(res[i].getlocnh());
   	    c[i].re.setroomnh(res[i].getroomnh());
   	    c[i].re.setrt(res[i].getrt());
   	    c[i].re.setpricenh(res[i].getpricenh());
   	    c[i].re.setphonenh(res[i].getphonenh());
   }
}
