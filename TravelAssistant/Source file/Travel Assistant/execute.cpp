#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <iomanip.h>
#include <sstream>
//thu vien cua game
#include <vector>
#include <shellapi.h>
#define matx 30
#define maty 24
#define right 0
#define up 1
#define left 2
#define down 3
#include "funcs.h"
#include "inputs.h"
#include "menus.h"
//end 
#include "hotel.cpp"
#include "rest.cpp"
#include "city.cpp"
#include "city2.cpp"
#include "cityinfo.cpp"
using namespace std;
int shortestway(int dist[], bool Set[],int n)
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < n; v++)
   {
   if (Set[v] == false && dist[v] <= min)
   {
     min = dist[v];
     min_index = v;
   }
   }
   return min_index;
}
void preorder(city c[],int luu[],int m,int tong,int cost,int nang,int money,int sumtime,int hour)
{
	
    PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
    system("cls");
    system("Color f0");
    ifstream fi("Display/execute.txt",ios::in);
    if(!fi)
    {
       cout<<"Nope";
       exit(1);
    }
    string aa;
    while(!fi.eof())
    {
   	   getline(fi,aa);
   	   cout<<aa<<endl;
    }
    char key=0;
    int index =1; 
    gotoXY(68,11);
    cout<<"LOAI DAT TRUOC";
    while(key!=13){      
    gotoXY(70,13);
    Color(63);
    if(index==1){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
    cout<<"NHA HANG";
    gotoXY(70,14);
    Color(63);
    if(index==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
    cout<<"KHACH SAN";
    gotoXY(70,15);
    Color(63);
    if(index==3){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
    cout<<"CA HAI";
    /////////////UP=224/72 Down=224/80 Enter=13
    key=getch();
    if(key==80){index++;}
    else if(key==72){index--;}
    if(index==4){index=1;}
    if(index==0){index=3;}
	ShowConsoleCursor(false);  
    }
    //nhap nha hang
	if(index == 1)
	{
		PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
        system("cls");
        system("Color f0");
        ifstream fi("Display/execute.txt",ios::in);
        if(!fi)
       {
          cout<<"Nope";
          exit(1);
        }
        string aa2;
        while(!fi.eof())
       {
   	     getline(fi,aa2);
   	     cout<<aa2<<endl;
       }
       char key=0;
       int index2 =1; 
       gotoXY(71,11);
       cout<<"DAT THEO";
       while(key!=13){      
       gotoXY(70,13);
       Color(63);
       if(index2==1){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
       cout<<"GIA TIEN";
       gotoXY(70,14);
       Color(63);
       if(index2==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
       cout<<"LOAI PHONG";
       /////////////UP=224/72 Down=224/80 Enter=13
       key=getch();
       if(key==80){index2++;}
       else if(key==72){index2--;}
       if(index2==3){index2=1;}
       if(index2==0){index2=2;}
	   ShowConsoleCursor(false);  
       }
       //nhap nha hang theo gia
       if(index2 == 1)
       {
       	   int giatien;
       	   PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi("Display/execute.txt",ios::in);
           if(!fi)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa3;
           while(!fi.eof())
          {
   	        getline(fi,aa3);
   	        cout<<aa3<<endl;
          }
          gotoXY(68,11);
          cout<<"NHAP GIA TIEN";
          gotoXY(68,12);
		  cout<<"<CHO MOT BAN>";
          gotoXY(70,14);
          cin>>giatien;
       	   PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi2("Display/nhahang1.txt",ios::in);
           if(!fi)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa2;
           while(!fi2.eof())
          {
   	        getline(fi2,aa2);
   	        cout<<aa2<<endl;
          }
          int nhy=8;
           for(int i=0;i<m;i++)
	      {
               if(c[luu[i]].re.getpricenh() <= giatien)
		      {
				gotoXY(41,nhy);
                cout<<c[luu[i]].re.getnamenh();
                gotoXY(63,nhy);
                cout<<c[luu[i]].getnamect();
                gotoXY(82,nhy);
                cout<<c[luu[i]].re.getpricenh();
                gotoXY(102,nhy);
                cout<<c[luu[i]].re.getroomnh()<<endl;
				 nhy++; 
              }
			           
	      }
	      string tennh,thoigian,thanhtoan;
	      int slp,sl;
	      ShowConsoleCursor(true);
	      gotoXY(59,18);
	      cin>>tennh;
	      for(int i=0;i<m;i++)
         {
      	   if(c[luu[i]].re.getnamenh() == tennh)
      	   { 	
			   while(c[luu[i]].re.getpricenh() > giatien)   
   		       {
				  gotoXY(59,18);
	              cin>>tennh;
   		       }
           }
         }
	      gotoXY(90,18);
	      cin>>thoigian;
	      gotoXY(62,20);
	      cin>>thanhtoan;
	      gotoXY(60,22);
	      cin>>slp;
	      for(int i=0;i<m;i++)
          {
          	 if(c[luu[i]].re.getnamenh() == tennh)
      	     {
			   while(c[luu[i]].re.getroomnh() < slp)
      	       {
     		      gotoXY(60,22);
     		      cout<<"___";
     		      gotoXY(60,22);
	              cin>>slp;
               }
      	     }
          }
	      gotoXY(60,24);
	      cin>>sl;
	      system("cls");
   		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
     	system("Color f0");
       ifstream finh("Display/ketqua.txt",ios::in);
       if(!finh)
       {
     	  cout<<"Nope";
         exit(1);
       }
       string anh;
       while(!finh.eof())
       {
         getline(finh,anh);
        cout<<anh<<endl;
         }
	      gotoXY(40,5);
   cout<<" - Thu tu di ban xem cot ben trai tu duoi len nhe :D";
   gotoXY(40,6);
   cout<<" - Thoi gian bat dau di: "<<hour<<" gio.Ban se den noi sau "<<sumtime<<" gio";
   gotoXY(40,7);
   cout<<" - Tong khoang cach: "<<tong<<" km";
   string luubus[100];
   for(int i=0;i<m;i++)
   {
   	for(int j=0;j<N;j++)
   	{
	   	if(luu[i] == j)
	   	{
	   		if(c[j].getbusct() != "khongco")
	   	    {
		     luubus[i] = c[j].getbusct();
	   	    }
	   	}
    }
   }
   gotoXY(40,8);
   cout<<" - Cac tuyen bus phai di:";
   for(int i =0;i<m;i++)
   {
   	if(i == m-1)
   	{
	   	cout<<luubus[i];
	   }
	   else{
   		cout<<luubus[i]<<" - ";
   	} 	
   }
   int namey=24;
   for(int i =0;i<m;i++)
   {
   	 if(i == m-1)
   	   {
   	   	 gotoXY(8,namey);
   	   	 cout<<"End";
         gotoXY(18,namey);
 	     cout<<c[luu[i]].getnamect();
 	   }
       
	   else{
	   	 gotoXY(18,namey);
	     cout<<c[luu[i]].getnamect();
   	     namey-=3;
	   }
   }
   for(int i=0;i<m-1;i++)
   {
   	cost+=fee[luu[i]][luu[i+1]];
   }
   for(int i=0;i<m;i++)
   {
   	nang+=c[luu[i]].getsun();
   }	
   gotoXY(40,9);
   cout<<" - Cac thang canh tren lo trinh: ";
   gotoXY(38,10);
   for(int i=0;i<m;i++)
   {
   	  if(c[luu[i]].getssct()!="khongco")
   	  {
  	   	if(i == m-1)
       {
      	cout<<c[luu[i]].getssct();
       }
       else{
      	cout<<c[luu[i]].getssct()<<",";
       }
      }   
   }
   gotoXY(40,11);
   cout<<" - Cac mon an dac san: ";
   gotoXY(38,12);
   for(int i=0;i<m;i++)
   {
   	  if(i == m-1)
      {
      	cout<<c[luu[i]].getfct();
      }
      else{
      	cout<<c[luu[i]].getfct()<<",";
      }
   }
   gotoXY(40,13);
   cout<<" -  Tong chi phi cho chuyen di: "<<cost<<" trieu";
   gotoXY(41,14);
   if(cost<=money)
   {
     cout<<"Ban mang du tien roi nhe!";
   }else{
   	 cout<<"Ban mang thieu tien mat roi,mang them ti nua nhe!";
   }
   if(nang/m >= 33)
   {
   	  gotoXY(40,15);
      cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay "<<endl;
      gotoXY(38,16);
	  cout<<"rat nong,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu va kem";
	  gotoXY(38,17); 
	  cout<<" chong nang neu van quyet dinh di nhe :D";
   }
   else if(25 <= nang/m <33 )
   {
      gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay vua "<<endl;
   	  gotoXY(38,16);
	  cout<<"phai,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu de phong"; 
	  gotoXY(38,17); 
	  cout<<" co nang to nhe :D";
   }
   else if(15 <= nang/m <25)
   {
   	  gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat mat me,"<<endl;
   	  gotoXY(38,16);
	  cout<<" co the hoi lanh nua day,voi nhiet do trung binh la "<<nang/m<<" do.Ban"; 
	  gotoXY(38,17);
	  cout<<" nen mang theo ao khoac mong nhe :D";
   }
   else{
   	  gotoXY(40,15);
   	  cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat "<<endl;
   	  gotoXY(38,16);
	  cout<<"lanh,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang theo ao khoac";
	  gotoXY(38,17);
      cout<<" day de giu am co the nhe :D";
   }
   gotoXY(40,18);
   cout<<" - Nha hang dat truoc: "<<tennh<<",";
   for(int i=0;i<m;i++)
   {
   	if(c[luu[i]].re.getnamenh()==tennh)
   	{
	   	cout<<c[luu[i]].getnamect();
	   }
   }
   gotoXY(40,19);
   cout<<" - So luong phong: "<<slp;
   gotoXY(40,20);
   cout<<" - Thoi gian: "<<thoigian<<" gio";
   gotoXY(40,21);
   cout<<" * Ket qua da duoc luu lai file ketquatracuu.doc o o D";
   gotoXY(40,22);
   cout<<"Ban co the xem lai.";
        ofstream fo("D:/ketquatracuu.doc",ios::out);
	   	if(!fo)
	   	{
	   		cout<<"Khong the ghi tep";
	   		exit(1);
	   	}
	   	fo<<" + Cac thanh pho se di:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getnamect()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" + Tong quang duong: "<<tong<<" km"<<endl;
	   	fo<<" + Tong chi phi: "<<cost<<" trieu"<<endl;
	   	fo<<" + Tong thoi gian di: "<<sumtime<<" gio"<<endl;
	   	fo<<" + Dac san: "<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getfct()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" + Danh lam thang canh:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		if(c[luu[i]].getssct()!="khongco")
	   		{
		   		fo<<c[luu[i]].getssct()<<" ";
		   	}	
	   	}
	   	fo<<endl;
	   	fo<<endl;
	   	fo<<"======== DON DAT CHO NHA HANG ========"<<endl;
	   	fo<<" + Nha hang dat truoc: "<<tennh<<",";
	   	for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].re.getnamenh()==tennh)
   	     {
	   	    fo<<c[luu[i]].getnamect();
	      }
       }
        fo<<endl;
        fo<<" + Muc gia: ";
        for(int i=0;i<m;i++)
        {
       	   if(c[luu[i]].re.getnamenh() == tennh)
       	   {   	                            
     	     fo<<c[luu[i]].re.getpricenh()<<"/phong"<<endl;
            }
         }
        fo<<" + So luong phong: "<<slp<<endl;
        fo<<" + Thoi gian: "<<thoigian<<" gio"<<endl;
        fo<<" + SDT Nha hang: ";
        for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].re.getnamenh()==tennh)
   	     {
	   	    fo<<c[luu[i]].re.getphonenh();
	      }
       }
       fo<<endl;
       fo<<" + Tong tien: ";
       for(int i=0;i<m;i++)
       {
      	   if(c[luu[i]].re.getnamenh() == tennh)
      	   {
      	      fo<<c[luu[i]].re.getpricenh()*slp<<" VND"<<endl;
           }
       }
	   	fo.close();
        gotoXY(55,26);
        cout<<"PRESS ESC/ENTER TO BACK TO MAIN MENU";
        ShowConsoleCursor(false);
       }
       
       //nhap nha hang theo loai phong
       else if(index2 == 2)
       {
       	   string type;
       	   PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi("Display/execute.txt",ios::in);
           if(!fi)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa3;
           while(!fi.eof())
          {
   	        getline(fi,aa3);
   	        cout<<aa3<<endl;
          }
           gotoXY(67,11);
           cout<<"NHAP LOAI PHONG";
           gotoXY(67,12);
           cout<<"<Lon/Vua/Nho>";
           gotoXY(72,14);
           ShowConsoleCursor(true);
           cin>>type;
           ShowConsoleCursor(false);
       	   PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi2("Display/nhahang2.txt",ios::in);
           if(!fi)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa2;
           while(!fi2.eof())
          {
   	        getline(fi2,aa2);
   	        cout<<aa2<<endl;
          }
          int nhy=8;
           for(int i=0;i<m;i++)
	      {
               if(c[luu[i]].re.getrt() == type)
		      {
				gotoXY(41,nhy);
                cout<<c[luu[i]].re.getnamenh();
                gotoXY(63,nhy);
                cout<<c[luu[i]].getnamect();
                gotoXY(82,nhy);
                cout<<c[luu[i]].re.getrt();
                gotoXY(102,nhy);
                cout<<c[luu[i]].re.getroomnh()<<endl;
				 nhy++; 
              }			           
	      }
	      string tennh,thoigian,thanhtoan;
	      int slp,sl;
	      ShowConsoleCursor(true);
	      gotoXY(59,18);
	      cin>>tennh;
	      for(int i=0;i<m;i++)
         {
      	   if(c[luu[i]].re.getnamenh() == tennh)
      	   { 	
			   while(c[luu[i]].re.getrt() != type)   
   		       {
				  gotoXY(59,18);
				  cout<<"________";
				  gotoXY(59,18);
	              cin>>tennh;
   		       }
           }
         }
	      gotoXY(90,18);
	      cin>>thoigian;
	      gotoXY(62,20);
	      cin>>thanhtoan;
	      gotoXY(60,22);
	      cin>>slp;
	      for(int i=0;i<m;i++)
          {
          	 if(c[luu[i]].re.getnamenh() == tennh)
      	     {
			   while(c[luu[i]].re.getroomnh() < slp)
      	       {
     		      gotoXY(60,22);
     		      cout<<"____";
     		      gotoXY(60,22);
	              cin>>slp;
               }
      	     }
          }
	      gotoXY(60,24);
	      cin>>sl;
	      system("cls");
   		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
     	system("Color f0");
       ifstream finh("Display/ketqua.txt",ios::in);
       if(!finh)
       {
     	  cout<<"Nope";
         exit(1);
       }
       string anh;
       while(!finh.eof())
       {
         getline(finh,anh);
        cout<<anh<<endl;
         }
	      gotoXY(40,5);
   cout<<" - Thu tu di ban xem cot ben trai tu duoi len nhe :D";
   gotoXY(40,6);
   cout<<" - Thoi gian bat dau di: "<<hour<<" gio.Ban se den noi sau "<<sumtime<<" gio";
   gotoXY(40,7);
   cout<<" - Tong khoang cach: "<<tong<<" km";
   string luubus[100];
   for(int i=0;i<m;i++)
   {
   	for(int j=0;j<N;j++)
   	{
	   	if(luu[i] == j)
	   	{
	   		if(c[j].getbusct() != "khongco")
	   	    {
		     luubus[i] = c[j].getbusct();
	   	    }
	   	}
    }
   }
   gotoXY(40,8);
   cout<<" - Cac tuyen bus phai di:";
   for(int i =0;i<m;i++)
   {
   	if(i == m-1)
   	{
	   	cout<<luubus[i];
	   }
	   else{
   		cout<<luubus[i]<<" - ";
   	} 	
   }
   int namey=24;
   for(int i =0;i<m;i++)
   {
   	 if(i == m-1)
   	   {
   	   	 gotoXY(8,namey);
   	   	 cout<<"End";
         gotoXY(18,namey);
 	     cout<<c[luu[i]].getnamect();
 	   }
       
	   else{
	   	 gotoXY(18,namey);
	     cout<<c[luu[i]].getnamect();
   	     namey-=3;
	   }
   }
   for(int i=0;i<m-1;i++)
   {
   	cost+=fee[luu[i]][luu[i+1]];
   }
   for(int i=0;i<m;i++)
   {
   	nang+=c[luu[i]].getsun();
   }	
   gotoXY(40,9);
   cout<<" - Cac thang canh tren lo trinh: ";
   gotoXY(38,10);
   for(int i=0;i<m;i++)
   {
   	  if(c[luu[i]].getssct()!="khongco")
   	  {
  	   	if(i == m-1)
       {
      	cout<<c[luu[i]].getssct();
       }
       else{
      	cout<<c[luu[i]].getssct()<<",";
       }
      }   
   }
   gotoXY(40,11);
   cout<<" - Cac mon an dac san: ";
   gotoXY(38,12);
   for(int i=0;i<m;i++)
   {
   	  if(i == m-1)
      {
      	cout<<c[luu[i]].getfct();
      }
      else{
      	cout<<c[luu[i]].getfct()<<",";
      }
   }
   gotoXY(40,13);
   cout<<" -  Tong chi phi cho chuyen di: "<<cost<<" trieu";
   gotoXY(41,14);
   if(cost<=money)
   {
     cout<<"Ban mang du tien roi nhe!";
   }else{
   	 cout<<"Ban mang thieu tien mat roi,mang them ti nua nhe!";
   }
   if(nang/m >= 33)
   {
   	  gotoXY(40,15);
      cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay "<<endl;
      gotoXY(38,16);
	  cout<<"rat nong,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu va kem";
	  gotoXY(38,17); 
	  cout<<" chong nang neu van quyet dinh di nhe :D";
   }
   else if(25 <= nang/m <33 )
   {
      gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay vua "<<endl;
   	  gotoXY(38,16);
	  cout<<"phai,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu de phong"; 
	  gotoXY(38,17); 
	  cout<<" co nang to nhe :D";
   }
   else if(15 <= nang/m <25)
   {
   	  gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat mat me,"<<endl;
   	  gotoXY(38,16);
	  cout<<" co the hoi lanh nua day,voi nhiet do trung binh la "<<nang/m<<" do.Ban"; 
	  gotoXY(38,17);
	  cout<<" nen mang theo ao khoac mong nhe :D";
   }
   else{
   	  gotoXY(40,15);
   	  cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat "<<endl;
   	  gotoXY(38,16);
	  cout<<"lanh,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang theo ao khoac";
	  gotoXY(38,17);
      cout<<" day de giu am co the nhe :D";
   }
   gotoXY(40,18);
   cout<<" - Nha hang dat truoc: "<<tennh<<",";
   for(int i=0;i<m;i++)
   {
   	if(c[luu[i]].re.getnamenh()==tennh)
   	{
	   	cout<<c[luu[i]].getnamect();
	   }
   }
   gotoXY(40,19);
   cout<<" - So luong phong: "<<slp;
   gotoXY(40,20);
   cout<<" - Thoi gian: "<<thoigian<<" gio";
   gotoXY(40,21);
   cout<<" * Ket qua da duoc luu lai file ketquatracuu.doc o o D";
   gotoXY(40,22);
   cout<<"Ban co the xem lai.";
        ofstream fo("D:/ketquatracuu.doc",ios::out);
	   	if(!fo)
	   	{
	   		cout<<"Khong the ghi tep";
	   		exit(1);
	   	}
	   	fo<<" + Cac thanh pho se di:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getnamect()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" + Tong quang duong: "<<tong<<" km"<<endl;
	   	fo<<" + Tong chi phi: "<<cost<<" trieu"<<endl;
	   	fo<<" + Tong thoi gian di: "<<sumtime<<" gio"<<endl;
	   	fo<<" + Dac san: "<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getfct()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" + Danh lam thang canh:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		if(c[luu[i]].getssct()!="khongco")
	   		{
		   		fo<<c[luu[i]].getssct()<<" ";
		   	}	
	   	}
	   	fo<<endl;
	   	fo<<endl;
	   	fo<<"======== DON DAT CHO NHA HANG ========"<<endl;
	   	fo<<" + Nha hang dat truoc: "<<tennh<<",";
	   	for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].re.getnamenh()==tennh)
   	     {
	   	    fo<<c[luu[i]].getnamect();
	      }
       }
        fo<<endl;
        fo<<" + Muc gia: ";
        for(int i=0;i<m;i++)
        {
       	   if(c[luu[i]].re.getnamenh() == tennh)
       	   {   	                            
     	     fo<<c[luu[i]].re.getpricenh()<<"/phong"<<endl;
            }
         }
        fo<<" + So luong phong: "<<slp<<endl;
        fo<<" + Thoi gian: "<<thoigian<<" gio"<<endl;
        fo<<" + SDT Nha hang: ";
        for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].re.getnamenh()==tennh)
   	     {
	   	    fo<<c[luu[i]].re.getphonenh();
	      }
       }
       fo<<endl;
       fo<<" + Tong tien: ";
       for(int i=0;i<m;i++)
       {
      	   if(c[luu[i]].re.getnamenh() == tennh)
      	   {
      	      fo<<c[luu[i]].re.getpricenh()*slp<<" VND"<<endl;
           }
       }
	   	fo.close();
        gotoXY(55,26);
        cout<<"PRESS ESC/ENTER TO BACK TO MAIN MENU";
        ShowConsoleCursor(false);
       }
	}
	//ket thuc nhap nha hang
	//Nhap cho khach san	
	else if(index == 2)
	{
       	   int giatien;
       	   PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi("Display/execute.txt",ios::in);
           if(!fi)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa3;
           while(!fi.eof())
          {
   	        getline(fi,aa3);
   	        cout<<aa3<<endl;
          }
          
          gotoXY(68,11);
          cout<<"NHAP GIA TIEN";
          gotoXY(68,12);
          cout<<"<CHO MOT DEM>";
          gotoXY(71,14);
          ShowConsoleCursor(true);
          cin>>giatien;
          ShowConsoleCursor(false);
       	   PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi2("Display/khachsan.txt",ios::in);
           if(!fi)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa2;
           while(!fi2.eof())
          {
   	        getline(fi2,aa2);
   	        cout<<aa2<<endl;
          }
          int nhy=8;
           for(int i=0;i<m;i++)
	      {
               if(c[luu[i]].ho.getpriceks() <= giatien)
		      {
				gotoXY(41,nhy);
                cout<<c[luu[i]].ho.getnameks();
                gotoXY(63,nhy);
                cout<<c[luu[i]].getnamect();
                gotoXY(82,nhy);
                cout<<c[luu[i]].ho.getpriceks();
                gotoXY(102,nhy);
                cout<<c[luu[i]].ho.getrlks()<<endl;
				 nhy++; 
              }
			           
	      }
	      string tenks,thanhtoan;
		  string ngayden,ngaydi,thangden,thangdi;
	      int slp,sl;
	      ShowConsoleCursor(true);
	      gotoXY(60,18);
	      cin>>tenks;
	      for(int i=0;i<m;i++)
         {
      	   if(c[luu[i]].ho.getnameks() == tenks)
      	   { 	
			   while(c[luu[i]].ho.getpriceks() > giatien)   
   		       {
				  gotoXY(60,18);
				  cout<<"________";
				  gotoXY(60,18);
	              cin>>tenks;
   		       }
           }
         }
	      gotoXY(94,18);
	      cin>>ngayden;
	      gotoXY(99,18);
	      cin>>thangden;
	      gotoXY(62,20);
	      cin>>thanhtoan;
	      gotoXY(94,20);
	      cin>>ngaydi;
	      gotoXY(99,20);
	      cin>>thangdi;
	      gotoXY(60,22);
	      cin>>slp;
	      for(int i=0;i<m;i++)
          {
          	 if(c[luu[i]].ho.getnameks() == tenks)
      	     {
			   while(c[luu[i]].ho.getrlks() < slp)
      	       {
     		      gotoXY(60,22);
     		      cout<<"____";
     		      gotoXY(60,22);
	              cin>>slp;
               }
      	     }
          }
	      gotoXY(60,24);
	      cin>>sl;
	      system("cls");
   		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
     	system("Color f0");
       ifstream finh("Display/ketqua.txt",ios::in);
       if(!finh)
       {
     	  cout<<"Nope";
         exit(1);
       }
       string anh;
       while(!finh.eof())
       {
         getline(finh,anh);
        cout<<anh<<endl;
         }
	      gotoXY(40,5);
   cout<<" - Thu tu di ban xem cot ben trai tu duoi len nhe :D";
   gotoXY(40,6);
   cout<<" - Thoi gian bat dau di: "<<hour<<" gio.Ban se den noi sau "<<sumtime<<" gio";
   gotoXY(40,7);
   cout<<" - Tong khoang cach: "<<tong<<" km";
   string luubus[100];
   for(int i=0;i<m;i++)
   {
   	for(int j=0;j<N;j++)
   	{
	   	if(luu[i] == j)
	   	{
	   		if(c[j].getbusct() != "khongco")
	   	    {
		     luubus[i] = c[j].getbusct();
	   	    }
	   	}
    }
   }
   gotoXY(40,8);
   cout<<" - Cac tuyen bus phai di:";
   for(int i =0;i<m;i++)
   {
   	if(i == m-1)
   	{
	   	cout<<luubus[i];
	   }
	   else{
   		cout<<luubus[i]<<" - ";
   	} 	
   }
   int namey=24;
   for(int i =0;i<m;i++)
   {
   	 if(i == m-1)
   	   {
   	   	 gotoXY(8,namey);
   	   	 cout<<"End";
         gotoXY(18,namey);
 	     cout<<c[luu[i]].getnamect();
 	   }
       
	   else{
	   	 gotoXY(18,namey);
	     cout<<c[luu[i]].getnamect();
   	     namey-=3;
	   }
   }
   for(int i=0;i<m-1;i++)
   {
   	cost+=fee[luu[i]][luu[i+1]];
   }
   for(int i=0;i<m;i++)
   {
   	nang+=c[luu[i]].getsun();
   }	
   gotoXY(40,9);
   cout<<" - Cac thang canh tren lo trinh: ";
   gotoXY(38,10);
   for(int i=0;i<m;i++)
   {
   	  if(c[luu[i]].getssct()!="khongco")
   	  {
  	   	if(i == m-1)
       {
      	cout<<c[luu[i]].getssct();
       }
       else{
      	cout<<c[luu[i]].getssct()<<",";
       }
      }   
   }
   gotoXY(40,11);
   cout<<" - Cac mon an dac san: ";
   gotoXY(38,12);
   for(int i=0;i<m;i++)
   {
   	  if(i == m-1)
      {
      	cout<<c[luu[i]].getfct();
      }
      else{
      	cout<<c[luu[i]].getfct()<<",";
      }
   }
   gotoXY(40,13);
   cout<<" -  Tong chi phi cho chuyen di: "<<cost<<" trieu";
   gotoXY(41,14);
   if(cost<=money)
   {
     cout<<"Ban mang du tien roi nhe!";
   }else{
   	 cout<<"Ban mang thieu tien mat roi,mang them ti nua nhe!";
   }
   if(nang/m >= 33)
   {
   	  gotoXY(40,15);
      cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay "<<endl;
      gotoXY(38,16);
	  cout<<"rat nong,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu va kem";
	  gotoXY(38,17); 
	  cout<<" chong nang neu van quyet dinh di nhe :D";
   }
   else if(25 <= nang/m <33 )
   {
      gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay vua "<<endl;
   	  gotoXY(38,16);
	  cout<<"phai,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu de phong"; 
	  gotoXY(38,17); 
	  cout<<" co nang to nhe :D";
   }
   else if(15 <= nang/m <25)
   {
   	  gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat mat me,"<<endl;
   	  gotoXY(38,16);
	  cout<<" co the hoi lanh nua day,voi nhiet do trung binh la "<<nang/m<<" do.Ban"; 
	  gotoXY(38,17);
	  cout<<" nen mang theo ao khoac mong nhe :D";
   }
   else{
   	  gotoXY(40,15);
   	  cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat "<<endl;
   	  gotoXY(38,16);
	  cout<<"lanh,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang theo ao khoac";
	  gotoXY(38,17);
      cout<<" day de giu am co the nhe :D";
   }
   gotoXY(40,18);
   cout<<" - Khach san dat truoc: "<<tenks<<",";
   for(int i=0;i<m;i++)
   {
   	if(c[luu[i]].ho.getnameks()==tenks)
   	{
	   	cout<<c[luu[i]].getnamect();
	   }
   }
   gotoXY(40,19);
   cout<<" - So luong phong: "<<slp;
   gotoXY(40,20);
   cout<<" - Thoi gian nhan phong: "<<ngayden<<"/"<<thangden;
   gotoXY(40,21);
   cout<<" - Thoi gian tra phong: "<<ngaydi<<"/"<<thangdi;
   gotoXY(40,22);
   cout<<" * Ket qua da duoc luu lai file ketquatracuu.doc o o D";
   gotoXY(40,23);
   cout<<"Ban co the xem lai.";
        ofstream fo("D:/ketquatracuu.doc",ios::out);
	   	if(!fo)
	   	{
	   		cout<<"Khong the ghi tep";
	   		exit(1);
	   	}
	   	fo<<" + Cac thanh pho se di:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getnamect()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" + Tong quang duong: "<<tong<<" km"<<endl;
	   	fo<<" + Tong chi phi: "<<cost<<" trieu"<<endl;
	   	fo<<" + Tong thoi gian di: "<<sumtime<<" gio"<<endl;
	   	fo<<" + Dac san: "<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getfct()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" + Danh lam thang canh:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		if(c[luu[i]].getssct()!="khongco")
	   		{
		   		fo<<c[luu[i]].getssct()<<" ";
		   	}	
	   	}
	   	fo<<endl;
	   	fo<<endl;
	   	fo<<"==========DON DAT CHO KHACH SAN===========";
	   	fo<<endl;
	   	fo<<" + Khach san dat truoc: "<<tenks<<",";
	   	for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].ho.getnameks()==tenks)
   	     {
	   	    fo<<c[luu[i]].getnamect();
	      }
       }
        fo<<endl;
        fo<<" + Muc gia: ";
        for(int i=0;i<m;i++)
        {
       	   if(c[luu[i]].ho.getnameks() == tenks)
       	   {   	                            
     	     fo<<c[luu[i]].ho.getpriceks()<<"/dem"<<endl;
            }
         }
        fo<<" + So luong phong: "<<slp<<endl;
        fo<<" + Ngay nhan phong: "<<ngayden<<"/"<<thangden<<endl;
        fo<<" + Ngay tra phong: "<<ngaydi<<"/"<<thangdi<<endl;
        fo<<" + SDT Khach san: ";
        for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].ho.getnameks()==tenks)
   	     {
	   	    fo<<c[luu[i]].ho.getphoneks();
	      }
       }
       fo<<endl;
       fo<<" + Tong tien: ";
       for(int i=0;i<m;i++)
       {
           if(c[luu[i]].ho.getnameks() == tenks)
      	   {
      	     fo<<c[luu[i]].ho.getpriceks()*slp<<" VND"<<endl;
           }
       }
	   	fo.close();
        gotoXY(55,26);
        cout<<"PRESS ESC/ENTER TO BACK TO MAIN MENU";
        ShowConsoleCursor(false);
	}
	//ket thuc nhap khach san
	
	//nhap ca hai
	else if(index == 3)
	{
	       //nhap nha hang
		   int giatiennh;
       	   PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream finh("Display/execute.txt",ios::in);
           if(!finh)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa3;
           while(!finh.eof())
          {
   	        getline(finh,aa3);
   	        cout<<aa3<<endl;
          }
          gotoXY(68,11);
          cout<<"NHAP GIA TIEN";
          gotoXY(68,12);
		  cout<<"<CHO MOT BAN>";
          gotoXY(70,14);
          cin>>giatiennh;
          ShowConsoleCursor(false);
          PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi2nh("Display/nhahang1.txt",ios::in);
           if(!fi2nh)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa2;
           while(!fi2nh.eof())
          {
   	        getline(fi2nh,aa2);
   	        cout<<aa2<<endl;
          }
          int nhy=8;
           for(int i=0;i<m;i++)
	      {
               if(c[luu[i]].re.getpricenh() <= giatiennh)
		      {
				gotoXY(41,nhy);
                cout<<c[luu[i]].re.getnamenh();
                gotoXY(63,nhy);
                cout<<c[luu[i]].getnamect();
                gotoXY(82,nhy);
                cout<<c[luu[i]].re.getpricenh();
                gotoXY(102,nhy);
                cout<<c[luu[i]].re.getroomnh()<<endl;
				 nhy++; 
              }
			           
	      }
	      string tennh,thoigian1,thanhtoan1;
	      int slp11,sl11;
	      ShowConsoleCursor(true);
	      gotoXY(59,18);
	      cin>>tennh;
	      for(int i=0;i<m;i++)
         {
      	   if(c[luu[i]].re.getnamenh() == tennh)
      	   { 	
			   while(c[luu[i]].re.getpricenh() > giatiennh)   
   		       {
				  gotoXY(59,18);
	              cin>>tennh;
   		       }
           }
         }
	      gotoXY(90,18);
	      cin>>thoigian1;
	      gotoXY(62,20);
	      cin>>thanhtoan1;
	      gotoXY(60,22);
	      cin>>slp11;
	      for(int i=0;i<m;i++)
          {
          	 if(c[luu[i]].re.getnamenh() == tennh)
      	     {
			   while(c[luu[i]].re.getroomnh() < slp11)
      	       {
     		      gotoXY(60,22);
     		      cout<<"___";
     		      gotoXY(60,22);
	              cin>>slp11;
               }
      	     }
          }
	      gotoXY(60,24);
	      cin>>sl11;
		//nhap khach san
		   int giatienks;
       	   PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fiks("Display/execute.txt",ios::in);
           if(!fiks)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa33;
           while(!fiks.eof())
          {
   	        getline(fiks,aa33);
   	        cout<<aa33<<endl;
          }
          
          gotoXY(68,11);
          cout<<"NHAP GIA TIEN";
          gotoXY(68,12);
          cout<<"<CHO MOT DEM>";
          gotoXY(71,14);
          ShowConsoleCursor(true);
          cin>>giatienks;
		  ShowConsoleCursor(false);
       	   PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi2ks("Display/khachsan.txt",ios::in);
           if(!fi2ks)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa22;
           while(!fi2ks.eof())
          {
   	        getline(fi2ks,aa22);
   	        cout<<aa22<<endl;
          }
          int nhy2=8;
           for(int i=0;i<m;i++)
	      {
               if(c[luu[i]].ho.getpriceks() <= giatienks)
		      {
				gotoXY(41,nhy2);
                cout<<c[luu[i]].ho.getnameks();
                gotoXY(63,nhy2);
                cout<<c[luu[i]].getnamect();
                gotoXY(82,nhy2);
                cout<<c[luu[i]].ho.getpriceks();
                gotoXY(102,nhy2);
                cout<<c[luu[i]].ho.getrlks()<<endl;
				 nhy2++; 
              }
			           
	      }
	      string tenks,thanhtoan2;
		  string ngayden,ngaydi,thangden,thangdi;
	      int slp12,sl12;
	      ShowConsoleCursor(true);
	      gotoXY(60,18);
	      cin>>tenks;
	      for(int i=0;i<m;i++)
         {
      	   if(c[luu[i]].ho.getnameks() == tenks)
      	   { 	
			   while(c[luu[i]].ho.getpriceks() > giatienks)   
   		       {
				  gotoXY(60,18);
				  cout<<"________";
				  gotoXY(60,18);
	              cin>>tenks;
   		       }
           }
         }
	      gotoXY(94,18);
	      cin>>ngayden;
	      gotoXY(99,18);
	      cin>>thangden;
	      gotoXY(62,20);
	      cin>>thanhtoan2;
	      gotoXY(94,20);
	      cin>>ngaydi;
	      gotoXY(99,20);
	      cin>>thangdi;
	      gotoXY(60,22);
	      cin>>slp12;
	      for(int i=0;i<m;i++)
          {
          	 if(c[luu[i]].ho.getnameks() == tenks)
      	     {
			   while(c[luu[i]].ho.getrlks() < slp12)
      	       {
     		      gotoXY(60,22);
     		      cout<<"____";
     		      gotoXY(60,22);
	              cin>>slp12;
               }
      	     }
          }
	      gotoXY(60,24);
	      cin>>sl12;
	      
////////hien thi ket qua
		
		system("cls");
   		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
     	system("Color f0");
       ifstream fikq("Display/ketqua.txt",ios::in);
       if(!fikq)
       {
     	  cout<<"Nope";
         exit(1);
       }
       string anh;
       while(!fikq.eof())
       {
         getline(fikq,anh);
        cout<<anh<<endl;
         }
	      gotoXY(40,5);
   cout<<" - Thu tu di ban xem cot ben trai tu duoi len nhe :D";
   gotoXY(40,6);
   cout<<" - Thoi gian bat dau di: "<<hour<<" gio.Ban se den noi sau "<<sumtime<<" gio";
   gotoXY(40,7);
   cout<<" - Tong khoang cach: "<<tong<<" km";
   string luubus[100];
   for(int i=0;i<m;i++)
   {
   	for(int j=0;j<N;j++)
   	{
	   	if(luu[i] == j)
	   	{
	   		if(c[j].getbusct() != "khongco")
	   	    {
		     luubus[i] = c[j].getbusct();
	   	    }
	   	}
    }
   }
   gotoXY(40,8);
   cout<<" - Cac tuyen bus phai di:";
   for(int i =0;i<m;i++)
   {
   	if(i == m-1)
   	{
	   	cout<<luubus[i];
	   }
	   else{
   		cout<<luubus[i]<<" - ";
   	} 	
   }
   int namey=24;
   for(int i =0;i<m;i++)
   {
   	 if(i == m-1)
   	   {
   	   	 gotoXY(8,namey);
   	   	 cout<<"End";
         gotoXY(18,namey);
 	     cout<<c[luu[i]].getnamect();
 	   }
       
	   else{
	   	 gotoXY(18,namey);
	     cout<<c[luu[i]].getnamect();
   	     namey-=3;
	   }
   }
   for(int i=0;i<m-1;i++)
   {
   	cost+=fee[luu[i]][luu[i+1]];
   }
   for(int i=0;i<m;i++)
   {
   	nang+=c[luu[i]].getsun();
   }	
   gotoXY(40,9);
   cout<<" - Cac thang canh tren lo trinh: ";
   gotoXY(38,10);
   for(int i=0;i<m;i++)
   {
   	  if(c[luu[i]].getssct()!="khongco")
   	  {
  	   	if(i == m-1)
       {
      	cout<<c[luu[i]].getssct();
       }
       else{
      	cout<<c[luu[i]].getssct()<<",";
       }
      }   
   }
   gotoXY(40,11);
   cout<<" - Cac mon an dac san: ";
   gotoXY(38,12);
   for(int i=0;i<m;i++)
   {
   	  if(i == m-1)
      {
      	cout<<c[luu[i]].getfct();
      }
      else{
      	cout<<c[luu[i]].getfct()<<",";
      }
   }
   gotoXY(40,13);
   cout<<" -  Tong chi phi cho chuyen di: "<<cost<<" trieu";
   gotoXY(41,14);
   if(cost<=money)
   {
     cout<<"Ban mang du tien roi nhe!";
   }else{
   	 cout<<"Ban mang thieu tien mat roi,mang them ti nua nhe!";
   }
   if(nang/m >= 33)
   {
   	  gotoXY(40,15);
      cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay "<<endl;
      gotoXY(38,16);
	  cout<<"rat nong,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu va kem";
	  gotoXY(38,17); 
	  cout<<" chong nang neu van quyet dinh di nhe :D";
   }
   else if(25 <= nang/m <33 )
   {
      gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay vua "<<endl;
   	  gotoXY(38,16);
	  cout<<"phai,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu de phong"; 
	  gotoXY(38,17); 
	  cout<<" co nang to nhe :D";
   }
   else if(15 <= nang/m <25)
   {
   	  gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat mat me,"<<endl;
   	  gotoXY(38,16);
	  cout<<" co the hoi lanh nua day,voi nhiet do trung binh la "<<nang/m<<" do.Ban"; 
	  gotoXY(38,17);
	  cout<<" nen mang theo ao khoac mong nhe :D";
   }
   else{
   	  gotoXY(40,15);
   	  cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat "<<endl;
   	  gotoXY(38,16);
	  cout<<"lanh,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang theo ao khoac";
	  gotoXY(38,17);
      cout<<" day de giu am co the nhe :D";
   }
   gotoXY(40,18);
   cout<<" - Nha hang dat: "<<tennh<<",";
   for(int i=0;i<m;i++)
   {
   	if(c[luu[i]].re.getnamenh()==tennh)
   	{
	   	cout<<c[luu[i]].getnamect();
	   }
   }
   gotoXY(71,18);
   cout<<" - Khach san dat: "<<tenks<<",";
   for(int i=0;i<m;i++)
   {
   	if(c[luu[i]].ho.getnameks()==tenks)
   	{
	   	cout<<c[luu[i]].getnamect();
	   }
   }
   gotoXY(40,19);
   cout<<" - So luong phong: "<<slp11;
   gotoXY(40,20);
   cout<<" - Thoi gian: "<<thoigian1<<" gio";
   gotoXY(71,19);
   cout<<" - So luong phong: "<<slp12;
   gotoXY(71,20);
   cout<<" - Thoi gian nhan phong: "<<ngayden<<"/"<<thangden;
   gotoXY(71,21);
   cout<<" - Thoi gian tra phong: "<<ngaydi<<"/"<<thangdi;
   gotoXY(40,23);
   cout<<" * Ket qua da duoc luu lai file ketquatracuu.doc o o D";
   gotoXY(40,24);
   cout<<"Ban co the xem lai.";
        ofstream fo("D:/ketquatracuu.doc",ios::out);
	   	if(!fo)
	   	{
	   		cout<<"Khong the ghi tep";
	   		exit(1);
	   	}
	   	fo<<" + Cac thanh pho se di:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getnamect()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" + Tong quang duong: "<<tong<<" km"<<endl;
	   	fo<<" + Tong chi phi: "<<cost<<" trieu"<<endl;
	   	fo<<" + Tong thoi gian di: "<<sumtime<<" gio"<<endl;
	   	fo<<" + Dac san: "<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getfct()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" + Danh lam thang canh:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		if(c[luu[i]].getssct()!="khongco")
	   		{
		   		fo<<c[luu[i]].getssct()<<" ";
		   	}	
	   	}
	   	fo<<endl;
	   	fo<<endl;
	   	fo<<"======== DON DAT CHO NHA HANG ========"<<endl;
	   	fo<<" + Nha hang dat truoc: "<<tennh<<",";
	   	for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].re.getnamenh()==tennh)
   	     {
	   	    fo<<c[luu[i]].getnamect();
	      }
       }
        fo<<endl;
        fo<<" + Muc gia: ";
        for(int i=0;i<m;i++)
        {
       	   if(c[luu[i]].re.getnamenh() == tennh)
       	   {   	                            
     	     fo<<c[luu[i]].re.getpricenh()<<"/phong"<<endl;
            }
         }
        fo<<" + So luong phong: "<<slp11<<endl;
        fo<<" + Thoi gian: "<<thoigian1<<" gio"<<endl;
        fo<<" + SDT Nha hang: ";
        for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].re.getnamenh()==tennh)
   	     {
	   	    fo<<c[luu[i]].re.getphonenh();
	      }
       }
       fo<<endl;
       fo<<" + Tong tien: ";
       for(int i=0;i<m;i++)
       {
      	   if(c[luu[i]].re.getnamenh() == tennh)
      	   {
      	      fo<<c[luu[i]].re.getpricenh()*slp11<<" VND"<<endl;
           }
       }
        fo<<endl;
	   	fo<<endl;
	   	fo<<"==========DON DAT CHO KHACH SAN===========";
	   	fo<<endl;
	   	fo<<" + Khach san dat truoc: "<<tenks<<",";
	   	for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].ho.getnameks()==tenks)
   	     {
	   	    fo<<c[luu[i]].getnamect();
	      }
       }
        fo<<endl;
        fo<<" + Muc gia: ";
        for(int i=0;i<m;i++)
        {
       	   if(c[luu[i]].ho.getnameks() == tenks)
       	   {   	                            
     	     fo<<c[luu[i]].ho.getpriceks()<<"/dem"<<endl;
            }
         }
        fo<<" + So luong phong: "<<slp12<<endl;
        fo<<" + Ngay nhan phong: "<<ngayden<<"/"<<thangden<<endl;
        fo<<" + Ngay tra phong: "<<ngaydi<<"/"<<thangdi<<endl;
        fo<<" + SDT Khach san: ";
        for(int i=0;i<m;i++)
       {
   	     if(c[luu[i]].ho.getnameks()==tenks)
   	     {
	   	    fo<<c[luu[i]].ho.getphoneks();
	      }
       }
       fo<<endl;
       fo<<" + Tong tien: ";
       for(int i=0;i<m;i++)
       {
           if(c[luu[i]].ho.getnameks() == tenks)
      	   {
      	     fo<<c[luu[i]].ho.getpriceks()*slp12<<" VND"<<endl;
           }
       }
	   	fo.close();
        gotoXY(55,26);
        cout<<"PRESS ESC/ENTER TO BACK TO MAIN MENU";
        ShowConsoleCursor(false);
	}
}
void dijkstra(int a[][100],int fee[][100],float timeh[][100],int start,int N,int m,city c[],float money,float hour,int month)
{
   ShowConsoleCursor(false);
   int dist[m];
   bool Set[m];
   int luu[m];
   float sumtime=0;
   int tong = 0,cost = 0,nang = 0,res = 0;
   for (int i = 0; i < m; i++)
   {
    dist[i] = INT_MAX;
    Set[i] = false;
   }
   dist[start] = 0;
   for (int c = 0; c < m; c++)
   {
      int u = shortestway(dist, Set,m);
      luu[c] = u;
      Set[u] = true;
      for (int v = 0; v < m; v++)
      {
	    if (Set[v] == false && a[u][v] && dist[u] != INT_MAX && dist[u]+ a[u][v] < dist[v])
        {
		  dist[v] = dist[u] + a[u][v];
        }
      }    
   }
   for(int i=0;i<m-1;i++)
   {
   	tong+=a[luu[i]][luu[i+1]];   	
   }
   for(int i=0;i<m-1;i++)
   {
   	sumtime+=timeh[luu[i]][luu[i+1]];
   }
//if thang cao diem
   if(month == 6 || month == 7 || month == 8 || month == 12 || month == 2)
   {
   system("cls");
   system("Color f0");
   ifstream fi("Display/execute.txt",ios::in);
   if(!fi)
   {
   cout<<"Nope";
   exit(1);
   }
   string aa;
   while(!fi.eof())
   {
   getline(fi,aa);
   cout<<aa<<endl;
    }
    char key=0;
    int index =1; 
    gotoXY(62,10);
    cout<<"THANG "<<month<<" CAO DIEM,BAN CO";
    gotoXY(62,11);
    cout<<"MUON DAT TRUOC NHA HANG";
    gotoXY(62,12);
    cout<<"HOAC KHACH SAN KHONG?";
    while(key!=13){      
    gotoXY(70,14);
    Color(63);
    if(index==1){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
    cout<<"   CO  ";
    gotoXY(70,15);
    Color(63);
    if(index==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
    cout<<"  KHONG  ";
    key=getch();
    if(key==80){index++;}
    else if(key==72){index--;}
    if(index==3){index=1;}
    if(index==0){index=2;}
    ShowConsoleCursor(false);  
    }
    if(index==1)
    {
   	     preorder(c,luu,m,tong,cost,nang,money,sumtime,hour);
    }
    else{
       PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
       system("cls");
       system("Color f0");
       ifstream fi("Display/ketqua.txt",ios::in);
       if(!fi)
       {
       cout<<"Nope";
       exit(1);
       }
       string aa;
       while(!fi.eof())
       {
      	getline(fi,aa);
      	cout<<aa<<endl;
       }
       gotoXY(40,5);
   cout<<" - Thu tu di ban xem cot ben trai tu duoi len nhe :D";
   gotoXY(40,6);
   cout<<" - Thoi gian bat dau di: "<<hour<<" gio.Ban se den noi sau "<<sumtime<<" gio";
   gotoXY(40,7);
   cout<<" - Tong khoang cach: "<<tong<<" km";
   string luubus[100];
   for(int i=0;i<m;i++)
   {
   	for(int j=0;j<N;j++)
   	{
	   	if(luu[i] == j)
	   	{
	   		if(c[j].getbusct() != "khongco")
	   	    {
		     luubus[i] = c[j].getbusct();
	   	    }
	   	}
    }
   }
   gotoXY(40,8);
   cout<<" - Cac tuyen bus phai di:";
   for(int i =0;i<m;i++)
   {
   	if(i == m-1)
   	{
	   	cout<<luubus[i];
	   }
	   else{
   		cout<<luubus[i]<<" - ";
   	} 	
   }
   int namey=24;
   for(int i =0;i<m;i++)
   {
   	   if(i == m-1)
   	   {
   	   	 gotoXY(8,namey);
   	   	 cout<<"End";
         gotoXY(18,namey);
 	     cout<<c[luu[i]].getnamect();
 	   }
       
	   else{
	   	 gotoXY(18,namey);
	     cout<<c[luu[i]].getnamect();
   	     namey-=3;
	   }
   }
   for(int i=0;i<m-1;i++)
   {
   	cost+=fee[luu[i]][luu[i+1]];
   }
   for(int i=0;i<m;i++)
   {
   	nang+=c[luu[i]].getsun();
   }	
   gotoXY(40,9);
   cout<<" - Cac thang canh tren lo trinh: ";
   gotoXY(38,10);
   for(int i=0;i<m;i++)
   {
   	  if(c[luu[i]].getssct()!="khongco")
   	  {
  	   	if(i == m-1)
       {
      	cout<<c[luu[i]].getssct();
       }
       else{
      	cout<<c[luu[i]].getssct()<<",";
       }
      }   
   }
   gotoXY(40,11);
   cout<<" - Cac mon an dac san: ";
   gotoXY(38,12);
   for(int i=0;i<m;i++)
   {
   	  if(i == m-1)
      {
      	cout<<c[luu[i]].getfct();
      }
      else{
      	cout<<c[luu[i]].getfct()<<",";
      }
   }
   gotoXY(40,13);
   cout<<" -  Tong chi phi cho chuyen di: "<<cost<<" trieu";
   gotoXY(41,14);
   if(cost <= money)
   {
     cout<<"Ban mang du tien roi nhe!";
   }
   else
   {
   	 cout<<"Ban mang thieu tien mat roi,mang them ti nua nhe!";
   }
   if(nang/m >= 33)
   {
   	  gotoXY(40,15);
      cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay "<<endl;
      gotoXY(38,16);
	  cout<<"rat nong,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu va kem";
	  gotoXY(38,17); 
	  cout<<" chong nang neu van quyet dinh di nhe :D";
   }
   else if(25 <= nang/m <33 )
   {
      gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay vua "<<endl;
   	  gotoXY(38,16);
	  cout<<"phai,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu de phong"; 
	  gotoXY(38,17); 
	  cout<<" co nang to nhe :D";
   }
   else if(15 <= nang/m <25)
   {
   	  gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat mat me,"<<endl;
   	  gotoXY(38,16);
	  cout<<" co the hoi lanh nua day,voi nhiet do trung binh la "<<nang/m<<" do.Ban"; 
	  gotoXY(38,17);
	  cout<<" nen mang theo ao khoac mong nhe :D";
   }
   else{
   	  gotoXY(40,15);
   	  cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat "<<endl;
   	  gotoXY(38,16);
	  cout<<"lanh,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang theo ao khoac";
	  gotoXY(38,17);
      cout<<" day de giu am co the nhe :D";
   }
   gotoXY(40,21);
   cout<<" * Ket qua da duoc luu lai file ketquatracuu.doc o o D";
   gotoXY(40,22);
   cout<<"Ban co the xem lai.";
        ofstream fo("D:/ketquatracuu.doc",ios::out);
	   	if(!fo)
	   	{
	   		cout<<"Khong the ghi tep";
	   		exit(1);
	   	}
	   	fo<<" - Cac thanh pho se di:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getnamect()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" - Tong quang duong: "<<tong<<" km"<<endl;
	   	fo<<" - Tong chi phi: "<<cost<<" trieu"<<endl;
	   	fo<<" - Tong thoi gian di: "<<sumtime<<" gio"<<endl;
	   	fo<<" - Dac san: "<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getfct()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" - Danh lam thang canh:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		if(c[luu[i]].getssct()!="khongco")
	   		{
		   		fo<<c[luu[i]].getssct()<<" ";
		   	}	
	   	}
	   	fo.close();
        gotoXY(57,26);
        cout<<"PRESS ESC TO BACK TO MAIN MENU";	   	
        }
       }
// ket thuc if thang cao diem
 else{
 PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
 system("cls");
 system("Color f0");
 ifstream fi("Display/ketqua.txt",ios::in);
 if(!fi)
 {
 cout<<"Nope";
 exit(1);
 }
 string aa;
 while(!fi.eof())
 {
	getline(fi,aa);
	cout<<aa<<endl;
 }
   gotoXY(40,5);
   cout<<" - Thu tu di ban xem cot ben trai tu duoi len nhe :D";
   gotoXY(40,6);
   cout<<" - Thoi gian bat dau di: "<<hour<<" gio.Ban se den noi sau "<<sumtime<<" gio";
   gotoXY(40,7);
   cout<<" - Tong khoang cach: "<<tong<<" km";
   string luubus[100];
   for(int i=0;i<m;i++)
   {
   	for(int j=0;j<N;j++)
   	{
	   	if(luu[i] == j)
	   	{
	   		if(c[j].getbusct() != "khongco")
	   	    {
		     luubus[i] = c[j].getbusct();
	   	    }
	   	}
    }
   }
   gotoXY(40,8);
   cout<<" - Cac tuyen bus phai di:";
   for(int i =0;i<m;i++)
   {
   	if(i == m-1)
   	{
	   	cout<<luubus[i];
	   }
	   else{
   		cout<<luubus[i]<<" - ";
   	} 	
   }
   int namey=24;
   for(int i =0;i<m;i++)
   {
   	    if(i == m-1)
   	   {
   	   	 gotoXY(8,namey);
   	   	 cout<<"End";
         gotoXY(18,namey);
 	     cout<<c[luu[i]].getnamect();
 	   }      
	   else{
 	     gotoXY(18,namey);
	     cout<<c[luu[i]].getnamect();
   	     namey-=3;
	   }
   }
   for(int i=0;i<m-1;i++)
   {
   	cost+=fee[luu[i]][luu[i+1]];
   }
   for(int i=0;i<m;i++)
   {
   	nang+=c[luu[i]].getsun();
   }	
   gotoXY(40,9);
   cout<<" - Cac thang canh tren lo trinh: ";
   gotoXY(38,10);
   for(int i=0;i<m;i++)
   {
   	  if(c[luu[i]].getssct()!="khongco")
   	  {
  	   	if(i == m-1)
       {
      	cout<<c[luu[i]].getssct();
       }
       else{
      	cout<<c[luu[i]].getssct()<<",";
       }
      }   
   }
   gotoXY(40,11);
   cout<<" - Cac mon an dac san: ";
   gotoXY(38,12);
   for(int i=0;i<m;i++)
   {
   	  if(i == m-1)
      {
      	cout<<c[luu[i]].getfct();
      }
      else{
      	cout<<c[luu[i]].getfct()<<",";
      }
   }
   gotoXY(40,13);
   cout<<" -  Tong chi phi cho chuyen di: "<<cost<<" trieu";
   gotoXY(41,14);
   if(cost<=money)
   {
   	cout<<"Ban mang du tien roi nhe";
   	}
   	else{
	   	cout<<"Ban mang thieu tien mat roi,mang them ti nhe";
	   }
   if(nang/m >= 33)
   {
   	  gotoXY(40,15);
      cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay "<<endl;
      gotoXY(38,16);
	  cout<<"rat nong,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu va kem";
	  gotoXY(38,17); 
	  cout<<" chong nang neu van quyet dinh di nhe :D";
   }
   else if(25 <= nang/m <33 )
   {
      gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay vua "<<endl;
   	  gotoXY(38,16);
	  cout<<"phai,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang mu de phong"; 
	  gotoXY(38,17); 
	  cout<<" co nang to nhe :D";
   }
   else if(15 <= nang/m <25)
   {
   	  gotoXY(40,15);
   	  cout<<" - Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat mat me,"<<endl;
   	  gotoXY(38,16);
	  cout<<" co the hoi lanh nua day,voi nhiet do trung binh la "<<nang/m<<" do.Ban"; 
	  gotoXY(38,17);
	  cout<<" nen mang theo ao khoac mong nhe :D";
   }
   else{
   	  gotoXY(40,15);
   	  cout<<" - Chu y: Thoi tiet nhung ngay toi khi du lich qua cac thanh pho nay rat "<<endl;
   	  gotoXY(38,16);
	  cout<<"lanh,voi nhiet do trung binh la "<<nang/m<<" do.Ban nen mang theo ao khoac";
	  gotoXY(38,17);
      cout<<" day de giu am co the nhe :D";
   }
   gotoXY(40,19);
   cout<<" * Ket qua da duoc luu lai file ketquatracuu.doc o o D";
   gotoXY(40,20);
   cout<<"Ban co the xem lai.";
        ofstream fo("D:/ketquatracuu.doc",ios::out);
	   	if(!fo)
	   	{
	   		cout<<"Khong the ghi tep";
	   		exit(1);
	   	}
	   	fo<<" - Cac thanh pho se di:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getnamect()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" - Tong quang duong: "<<tong<<" km"<<endl;
	   	fo<<" - Tong chi phi: "<<cost<<" trieu"<<endl;
	   	fo<<" - Tong thoi gian di: "<<sumtime<<" gio"<<endl;
	   	fo<<" - Dac san: "<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		fo<<c[luu[i]].getfct()<<" ";
	   	}
	   	fo<<endl;
	   	fo<<" - Danh lam thang canh:"<<endl;
	   	for(int i=0;i<m;i++)
	   	{
	   		if(c[luu[i]].getssct()!="khongco")
	   		{
		   		fo<<c[luu[i]].getssct()<<" ";
		   	}	
	   	}
	   	fo.close();
        gotoXY(57,25);
        cout<<"PRESS ESC TO BACK TO MAIN MENU";	   	
  }
}
   
void doctep(int a[][100],int a2[][100],int fee[][100],int fee2[][100],hotel hot[],hotel hot2[],rest res[],rest res2[],float timeh[][100],float timeh2[][100],string ten[],string ten2[],string bus[],string bus2[],string ss[],string ss2[],int sun[],int sun2[],int rain[],int rain2[],string price[],string price2[],string food[],string food2[],int &N,int &N2)
{
	/*ifstream fi("D:/input.txt",ios::in);
	if(!fi)
	{
		cout<<setw(30)<<" ";
		cout<<"KHONG THE NAP DU LIEU!";
		cout<<endl;
		cout<<setw(30)<<" ";
		cout<<"FILE DU LIEU BON MINH DE CUNG FOLDER VOI FILE CHUONG TRINH DO :D"<<endl;
		exit(1);
	}
	fi>>N;
	fi>>N2;
    for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			fi>>a[i][j];
		}
	}
	for(int i=0;i<N2;i++)
	{
		for(int j=0;j<N2;j++)
		{
			fi>>a2[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			fi>>fee[i][j];
		}
	}
	for(int i=0;i<N2;i++)
	{
		for(int j=0;j<N2;j++)
		{
			fi>>fee2[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			fi>>timeh[i][j];
		}
	}
	for(int i=0;i<N2;i++)
	{
		for(int j=0;j<N2;j++)
		{
			fi>>timeh2[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		fi>>sun[i];
	}
	for(int i=0;i<N;i++)
	{
		fi>>rain[i];		
	}
	for(int i=0;i<N2;i++)
	{
		fi>>sun2[i];
	}
	for(int i=0;i<N2;i++)
	{
		fi>>rain2[i];		
	}
	for(int i=0;i<N;i++)
	{
		if(!fi.eof())
		{
			fi>>ss[i];
		}
	}
	for(int i=0;i<N;i++)
	{
		if(!fi.eof())
		{
			fi>>ten[i];
		}
	}
	for(int i=0;i<N;i++)
	{
		if(!fi.eof())
		{
			fi>>bus[i];
		}
	}
	for(int i=0;i<N;i++)
	{
		if(!fi.eof())
		{
			fi>>price[i];
		}
	}
	for(int i=0;i<N;i++)
	{
		if(!fi.eof())
		{
			fi>>food[i];
		}
	}
	for(int i=0;i<N;i++)
	{
		if(!fi.eof())
		{
            fi>>hot[i];
		}	   
	}
	for(int i=0;i<N;i++)
	{
		if(!fi.eof())
		{
		    fi>>res[i];
		}
		
	}
	for(int i=0;i<N2;i++)
	{
		if(!fi.eof())
		{
			fi>>ss2[i];
		}
	}
	for(int i=0;i<N2;i++)
	{
		if(!fi.eof())
		{
			fi>>ten2[i];
		}
	}
	for(int i=0;i<N2;i++)
	{
		if(!fi.eof())
		{
			fi>>bus2[i];
		}
	}
	for(int i=0;i<N2;i++)
	{
		if(!fi.eof())
		{
			fi>>price2[i];
		}
	}
	for(int i=0;i<N2;i++)
	{
		if(!fi.eof())
		{
			fi>>food2[i];
		}
	}
	for(int i=0;i<N2;i++)
	{
		if(!fi.eof())
		{
            fi>>hot2[i];
		}	   
	}
	for(int i=0;i<N2;i++)
	{
		if(!fi.eof())
		{
		    fi>>res2[i];
		}
		
	}*/
	ifstream fi("mienbac.csv",ios::in);
	int x=0;
	N=-1;
	while(!fi.eof())
	{
		fi>>loadrow[x];
		x++;
		N++;
	}
	vector<string> result[20];
	for(int i=0;i<N;i++)
	{	
	    stringstream s(loadrow[i]);
        while( s.good() )
       {
         string substr;
         getline( s, substr, ',' );
         result[i].push_back( substr );
       }
	}
	for(int i=0;i<N;i++)
	{
        ten[i]=result[i][0];
        bus[i]=result[i][1];
        ss[i]=result[i][2];
    	stringstream geek2(result[i][3]);
    	int x2=0;
    	geek2>>x2;
    	sun[i]=x2;
    	stringstream geek3(result[i][4]);
    	int x3=0;
    	geek3>>x3;
    	rain[i]=x3;
    	price[i]=result[i][5];
    	food[i]=result[i][6];
    	hot[i].setnameks(result[i][7]);
    	hot[i].setlocks(result[i][8]);
    	stringstream geek4(result[i][9]);
    	int x4=0;
    	geek4>>x4;
    	hot[i].setroomks(x4);
    	stringstream geek5(result[i][10]);
    	int x5=0;
    	geek5>>x5;
    	hot[i].setrlks(x5);
    	stringstream geek6(result[i][11]);
    	int x6=0;
    	geek6>>x6;
    	hot[i].setpriceks(x6);
    	hot[i].setphoneks(result[i][12]);
    	res[i].setnamenh(result[i][13]);
    	res[i].setlocnh(result[i][14]);
    	stringstream geek8(result[i][15]);
    	int x8=0;
    	geek8>>x8;
    	res[i].setroomnh(x8);
    	res[i].setrt(result[i][16]);
    	stringstream geek9(result[i][17]);
    	int x9=0;
    	geek9>>x9;
    	res[i].setpricenh(x9);
    	res[i].setphonenh(result[i][18]);
	}
	//mien nam
	ifstream fi2("miennam.csv",ios::in);
	int y=0;
	N2=-1;
	while(!fi2.eof())
	{
		fi2>>loadrow2[y];
		y++;
		N2++;
	}
	vector<string> result2[20];
	for(int i=0;i<N2;i++)
	{	
	    stringstream s(loadrow2[i]);
        while( s.good() )
       {
         string substr;
         getline( s, substr, ',' );
         result2[i].push_back( substr );
       }
	}
	for(int i=0;i<N2;i++)
	{
        ten2[i]=result2[i][0];
        bus2[i]=result2[i][1];
        ss2[i]=result2[i][2];
    	stringstream geek2(result2[i][3]);
    	int x2=0;
    	geek2>>x2;
    	sun2[i]=x2;
    	stringstream geek3(result2[i][4]);
    	int x3=0;
    	geek3>>x3;
    	rain2[i]=x3;
    	price2[i]=result2[i][5];
    	food2[i]=result2[i][6];
    	hot2[i].setnameks(result2[i][7]);
    	hot2[i].setlocks(result2[i][8]);
    	stringstream geek4(result2[i][9]);
    	int x4=0;
    	geek4>>x4;
    	hot2[i].setroomks(x4);
    	stringstream geek5(result2[i][10]);
    	int x5=0;
    	geek5>>x5;
    	hot2[i].setrlks(x5);
    	stringstream geek6(result2[i][11]);
    	int x6=0;
    	geek6>>x6;
    	hot2[i].setpriceks(x6);
    	hot2[i].setphoneks(result2[i][12]);
    	res2[i].setnamenh(result2[i][13]);
    	res2[i].setlocnh(result2[i][14]);
    	stringstream geek8(result2[i][15]);
    	int x8=0;
    	geek8>>x8;
    	res2[i].setroomnh(x8);
    	res2[i].setrt(result[i][16]);
    	stringstream geek9(result2[i][17]);
    	int x9=0;
    	geek9>>x9;
    	res2[i].setpricenh(x9);
    	res2[i].setphonenh(result2[i][18]);
	}
	//nap ma tran
	ifstream fi3("matran.txt",ios::in);
	if(!fi3)
	{
		exit(1);
	}		
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			fi3>>a[i][j];
		}
	}
	for(int i=0;i<N2;i++)
	{
		for(int j=0;j<N2;j++)
		{
			fi3>>a2[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			fi3>>fee[i][j];
		}
	}
	for(int i=0;i<N2;i++)
	{
		for(int j=0;j<N2;j++)
		{
			fi3>>fee2[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			fi3>>timeh[i][j];
		}
	}
	for(int i=0;i<N2;i++)
	{
		for(int j=0;j<N2;j++)
		{
			fi3>>timeh2[i][j];
		}
	}
	fi.close();
}
void game()
{
	 ShowConsoleCursor(false);
	 menu men;
     men.showgamemenu();
}
void admin()
{ 
	PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
	system("cls");
	system("Color f0");
	ifstream fi("Display/admin.txt",ios::in);
	if(!fi)
	{
		cout<<"Nope";
		exit(1);
	}
	string aa;
    while(!fi.eof())
    {
    	getline(fi,aa);
    	cout<<aa<<endl;
    }
    string oid="admin";
    char opass[10]="123456";
    string nhapid;
    char nhappass[10];
   	ShowConsoleCursor(true);
    goid:gotoXY(55,19);
    cin>>nhapid;
    while(nhapid != oid)
    {
      	gotoXY(55,19);
      	cout<<"__________";
        goto goid;
    }
    p:gotoXY(55,22);
    for(int i=0;i<6;i++)
    {
    	nhappass[i]=getch();
    	cout<<"*";
    }
    char key=getch();
    if(key == 13)
    {
    	for(int i=0;i<6;i++)
       {
    	if(nhappass[i]!=opass[i])
    	{
	    	gotoXY(55,22);
	    	cout<<"______";
	    	goto p;
	    }    		 
       } 
	   ShellExecute( NULL, NULL, TEXT( "mienbac.csv" ), NULL, NULL, SW_SHOW ); 
	   ShellExecute( NULL, NULL, TEXT( "miennam.csv" ), NULL, NULL, SW_SHOW ); 
	   ShellExecute( NULL, NULL, TEXT( "matran.txt" ), NULL, NULL, SW_SHOW );    
    }
    ShowConsoleCursor(false);
}
void execute()
{
    ShowConsoleCursor(false); 
	PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);
	system("cls");
	system("Color f0");
	ifstream fi("Display/execute.txt",ios::in);
	if(!fi)
	{
		cout<<"Nope";
		exit(1);
	}
	string aa;
    while(!fi.eof())
    {
    	getline(fi,aa);
    	cout<<aa<<endl;
    }
    char key=0;
    int index =1; 
    gotoXY(68,11);
    cout<<"CHON KHU VUC";
    while(key!=13){      
    gotoXY(70,13);
    Color(63);
    if(index==1){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
    cout<<"MIEN BAC";
    gotoXY(70,14);
    Color(63);
    if(index==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
    cout<<"MIEN NAM";
    /////////////UP=224/72 Down=224/80 Enter=13
    key=getch();
    if(key==80){index++;}
    else if(key==72){index--;}
    if(index==3){index=1;}
    if(index==0){index=2;}
 
    }
	//mien bac	
	if(index == 1)
    {
    	//bat dau mien bac
    	PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
 		char key=0;
        int index =1; 
        gotoXY(66,11);
        system("Color f0");
        cout<<"CHON KIEU TRA CUU";
        while(key!=13){      
        gotoXY(70,13);
        Color(63);
        if(index==1){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"MAC DINH";
        gotoXY(70,14);
        Color(63);
        if(index==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"TU CHON ";
        key=getch();
        if(key==80){index++;}
        else if(key==72){index--;}
        if(index==3){index=1;}
        if(index==0){index=2;}
	    ShowConsoleCursor(false);  
        }
        //tuy chon
		if(index == 2)
		{
			//start
		   int n;
       	   PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi("Display/execute.txt",ios::in);
           if(!fi)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa3;
           while(!fi.eof())
          {
   	        getline(fi,aa3);
   	        cout<<aa3<<endl;
          }
          ShowConsoleCursor(true);
          gotoXY(66,11);
          cout<<"NHAP SO LUONG TP";
          gotoXY(66,12);
		  cout<<"BAN MUON (3<n<"<<N<<")";
		  gotoXY(73,14);
		  cin>>n;
		  while(n<3 || n>N)
		  {
  			gotoXY(73,14);
  			cout<<"   ";
  			gotoXY(73,14);
		    cin>>n;
  		  }
          ShowConsoleCursor(false);
		  	PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
          system("cls");
         system("Color f0");
         ifstream fi3("Display/execute.txt",ios::in);
         if(!fi3)
        {
            cout<<"Nope";
           exit(1);
        }
        string aa;
        while(!fi3.eof())
       {
   	      getline(fi3,aa);
   	      cout<<aa<<endl;
       }
         char key=0;
        int index =1; 
        gotoXY(70,11);
        cout<<"LUA CHON";
        while(key!=13){      
        gotoXY(63,13);
        Color(62);
        if(index==1){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<n<<" THANH PHO BAT KY";
        gotoXY(63,14);
        Color(62);
        if(index==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<n<<" THANH PHO THEO THU TU";
        /////////////UP=224/72 Down=224/80 Enter=13
        key=getch();
        if(key==80){index++;}
        else if(key==72){index--;}
        if(index==3){index=1;}
        if(index==0){index=2;}  
        }
        if(index ==1)
        {
        	//tuy chon
        	ShowConsoleCursor(true);
			PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	        system("cls");
	        system("Color f0");
	        ifstream fi("Display/option.txt",ios::in);
         	if(!fi)
	        {
		        cout<<"Nope";
		        exit(1);
	        }
	        string in;
            while(!fi.eof())
            {
    	       getline(fi,in);
   	           cout<<in<<endl;
            }
            city c[n];
			float tien1,timed[100][100];
			int b[100][100],y=10;
            for(int i=0;i<n;i++)
            {
            	gotoXY(65,y);
			    cout<<i+1<<".";
			    y++;
            }  
            int y2=10;
			for(int i=0;i<n;i++)
			{
				gotoXY(67,y2);
				string b=" ";
				cin>>b;
				c[i].setnamect(b);
				y2++;
			}
			for(int i=0;i<n;i++)
			{
			  for(int j=0;j<N;j++)
			  {
					if(c[i].getnamect() == ten[j])
					{
					    c[i].setindex(j);
					}
			   }
			}
					
            for(int i=0;i<n;i++)
			{
			   for(int j=0;j<n;j++)
			   {
			     timed[i][j] = timeh[c[i].getindex()][c[j].getindex()];
			    }
			}
			for(int i=0;i<n;i++)
			{
  	           for(int j=0;j<N;j++)
  	           {
			       if(c[i].getindex() == j)
			      {
 		             c[i].setbusct(bus[j]);
  	              }
			   }
            }	
			for(int i=0;i<n;i++)
			{
               for(int j=0;j<N;j++)
  	           {
			       if(c[i].getindex() == j)
			      {
			    		c[i].setfct(food[j]);
  	              }
			   }
            }				
			for(int i=0;i<n;i++)
			{
			    for(int j=0;j<N;j++)
			    {
			       if(c[i].getindex() == j)
		           {
			         c[i].setssct(ss[j]);
			       }
			    }
			}
			for(int i=0;i<n;i++)
			{
			   for(int j=0;j<n;j++)
			   {
			       b[i][j] = a[c[i].getindex()][c[j].getindex()];
			   }
			}
			for(int i=0;i<n;i++)
			{
			   for(int j=0;j<N;j++)
			  {
			     if(c[i].getindex() == j)
			     {
			        c[i].setsun(sun[j]);
			     }
			  }
			}	
			for(int i=0;i<n;i++)
            {
  	           for(int j=0;j<N;j++)
  	           {
                  if(c[i].getindex() == j)
                 {
 		            c[i].ho.setnameks(hot[j].getnameks());
 	                c[i].ho.setlocks(hot[j].getlocks());
 		            c[i].ho.setroomks(hot[j].getroomks());
	                c[i].ho.setrlks(hot[j].getrlks());
 		            c[i].ho.setpriceks(hot[j].getpriceks());
 		            c[i].ho.setphoneks(hot[j].getphoneks());
  	             }
              } 	                        
            }
            for(int i=0;i<n;i++)
            {
  	            for(int j=0;j<N;j++)
  	           {
  	              if(c[i].getindex() == j)
  	              {
 		           c[i].re.setnamenh(res[j].getnamenh());
 		           c[i].re.setlocnh(res[j].getlocnh());
 		           c[i].re.setroomnh(res[j].getroomnh());
 		           c[i].re.setrt(res[j].getrt());
 		           c[i].re.setpricenh(res[j].getpricenh());
 		           c[i].re.setphonenh(res[j].getphonenh());
  	              }
               }  	                        
            }	
			ShowConsoleCursor(true);
			PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	        system("cls");
	        system("Color f0");
	        ifstream fi22("Display/execute2.txt",ios::in);
         	if(!fi22)
	        {
		        cout<<"Nope";
		        exit(1);
	        }
	        string in2;
            while(!fi22.eof())
            {
    	       getline(fi22,in2);
   	           cout<<in2<<endl;
            }          
            int start2,date2,month2;
            string batdau;
            float hour2;
	        gotoXY(85,11);
            cin>>batdau;
            for(int i=0;i<n;i++)
            {
              if(c[i].getnamect()== batdau)
              {
               start2 = i;
              }
            } 
            gotoXY(85,13);
            cin>>date2;
            while(date2<0 || date2 > 31)
            {
            	gotoXY(85,13);
            	cout<<"____";
            	gotoXY(85,13);
                cin>>date2;
            }
            gotoXY(85,15);
            cin>>month2;
            while(month2<0 || month2 > 12)
            {
            	gotoXY(85,15);
            	cout<<"____";
            	gotoXY(85,15);
                cin>>month2;
            }
            gotoXY(85,17);
            cin>>hour2;
            gotoXY(85,19);
            cin>>tien1;
            dijkstra(b,fee,timed,start2,N,n,c,tien1,hour2,month2);           	
        	//ket thuc tuy chon       	
        }
        else if(index == 2)
        {
        	//theo thu tu
        	setdata(c,a,hot,res,timeh,ten,bus,fee,ss,price,sun,rain,food,n,N);
			ShowConsoleCursor(true);
			PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	        system("cls");
	        system("Color f0");
	        ifstream fi("Display/execute2.txt",ios::in);
         	if(!fi)
	        {
		        cout<<"Nope";
		        exit(1);
	        }
	        string in;
            while(!fi.eof())
            {
    	       getline(fi,in);
   	           cout<<in<<endl;
            }          
            int start,month,date3;
            string b;
            float hour;
            float tien2;
	        gotoXY(85,11);
            cin>>b;
            /*for(int i=0;i<strlen(b);i++)
            {
            	if(!isalpha(b[i]))
            	{
	            	gotoXY(85,11);
	            	cout<<"_______";
	            	goto nhaptt;
	            }
            }*/
            for(int i=0;i<n;i++)
            {
              if(c[i].getnamect()== b)
              {
               start = i;
              }
            } 
            gotoXY(85,13);
            cin>>date3;
            while(date3<0 || date3 > 31)
            {
            	gotoXY(85,13);
            	cout<<"____";
            	gotoXY(85,13);
                cin>>date3;
            }
            gotoXY(85,15);
            cin>>month;
            while(month<0 || month > 12)
            {
            	gotoXY(85,15);
            	cout<<"____";
            	gotoXY(85,15);
                cin>>month;
            }
            gotoXY(85,17);
            cin>>hour;
            gotoXY(85,19);
            cin>>tien2;
            dijkstra(a,fee,timeh,start,N,n,c,tien2,hour,month);
        	//ket thuc theo thu tu
        }
			//end
		}
		//mac dinh
		else if(index == 1)
		{
			setdata(c,a,hot,res,timeh,ten,bus,fee,ss,price,sun,rain,food,N,N);
			ShowConsoleCursor(true);
			PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	        system("cls");
	        system("Color f0");
	        ifstream fi("Display/execute2.txt",ios::in);
         	if(!fi)
	        {
		        cout<<"Nope";
		        exit(1);
	        }
	        string in;
            while(!fi.eof())
            {
    	       getline(fi,in);
   	           cout<<in<<endl;
            }          
            int start,month;
            int date1;
			string b;
            float hour;
            float tien3;
		    gotoXY(85,11);
            cin>>b;
            for(int i=0;i<N;i++)
            {
              if(c[i].getnamect()== b)
              {
               start = i;
              }
            } 
            gotoXY(85,13);
            cin>>date1;
            while(date1<0 || date1 > 31)
            {
            	gotoXY(85,13);
            	cout<<"____";
            	gotoXY(85,13);
                cin>>date1;
            }
            gotoXY(85,15);
            cin>>month;
            while(month<0 || month > 12)
            {
            	gotoXY(85,15);
            	cout<<"____";
            	gotoXY(85,15);
                cin>>month;
            }
            gotoXY(85,17);
            cin>>hour;
            gotoXY(85,19);
            cin>>tien3;
            dijkstra(a,fee,timeh,start,N,N,c,tien3,hour,month);
		}
 	}
 	//mien nam
	else if(index == 2)
	{
		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
 		char key=0;
        int index =1; 
        gotoXY(66,11);
        system("Color f0");
        cout<<"CHON KIEU TRA CUU";
        while(key!=13){      
        gotoXY(70,13);
        Color(63);
        if(index==1){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"MAC DINH";
        gotoXY(70,14);
        Color(63);
        if(index==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"TU CHON ";
        key=getch();
        if(key==80){index++;}
        else if(key==72){index--;}
        if(index==3){index=1;}
        if(index==0){index=2;}
	    ShowConsoleCursor(false);  
        }
        //tuy chon
		if(index == 2)
		{
			//start
		   int n;
       	   PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
           system("cls");
           system("Color f0");
           ifstream fi("Display/execute.txt",ios::in);
           if(!fi)
          {
            cout<<"Nope";
            exit(1);
           }
           string aa3;
           while(!fi.eof())
          {
   	        getline(fi,aa3);
   	        cout<<aa3<<endl;
          }
          ShowConsoleCursor(true);
          gotoXY(66,11);
          cout<<"NHAP SO LUONG TP";
          gotoXY(66,12);
		  cout<<"BAN MUON (3<n<"<<N2<<")";
		  gotoXY(73,14);
		  cin>>n;
          ShowConsoleCursor(false);
		  	PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
          system("cls");
         system("Color f0");
         ifstream fi3("Display/execute.txt",ios::in);
         if(!fi3)
        {
            cout<<"Nope";
           exit(1);
        }
        string aa;
        while(!fi3.eof())
       {
   	      getline(fi3,aa);
   	      cout<<aa<<endl;
       }
         char key=0;
        int index =1; 
        gotoXY(70,11);
        cout<<"LUA CHON";
        while(key!=13){      
        gotoXY(63,13);
        Color(62);
        if(index==1){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<n<<" THANH PHO BAT KY";
        gotoXY(63,14);
        Color(62);
        if(index==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<n<<" THANH PHO THEO THU TU";
        /////////////UP=224/72 Down=224/80 Enter=13
        key=getch();
        if(key==80){index++;}
        else if(key==72){index--;}
        if(index==3){index=1;}
        if(index==0){index=2;}  
        }
        if(index ==1)
        {
        	//tuy chon
        	ShowConsoleCursor(true);
			PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	        system("cls");
	        system("Color f0");
	        ifstream fi("Display/option.txt",ios::in);
         	if(!fi)
	        {
		        cout<<"Nope";
		        exit(1);
	        }
	        string in;
            while(!fi.eof())
            {
    	       getline(fi,in);
   	           cout<<in<<endl;
            }
            city c[n];
			float tien1,timed[100][100];
			int b[100][100],y=10;
            for(int i=0;i<n;i++)
            {
            	gotoXY(65,y);
			    cout<<i+1<<".";
			    y++;
            }  
            int y2=10;
			for(int i=0;i<n;i++)
			{
				gotoXY(67,y2);
				string b=" ";
				cin>>b;
				c[i].setnamect(b);
				y2++;
			}
			for(int i=0;i<n;i++)
			{
			  for(int j=0;j<N2;j++)
			  {
					if(c[i].getnamect() == ten2[j])
					{
					    c[i].setindex(j);
					}
			   }
			}
					
            for(int i=0;i<n;i++)
			{
			   for(int j=0;j<n;j++)
			   {
			     timed[i][j] = timeh2[c[i].getindex()][c[j].getindex()];
			    }
			}
			for(int i=0;i<n;i++)
			{
  	           for(int j=0;j<N2;j++)
  	           {
			       if(c[i].getindex() == j)
			      {
 		             c[i].setbusct(bus2[j]);
  	              }
			   }
            }	
			for(int i=0;i<n;i++)
			{
               for(int j=0;j<N2;j++)
  	           {
			       if(c[i].getindex() == j)
			      {
			    		c[i].setfct(food2[j]);
  	              }
			   }
            }				
			for(int i=0;i<n;i++)
			{
			    for(int j=0;j<N2;j++)
			    {
			       if(c[i].getindex() == j)
		           {
			         c[i].setssct(ss2[j]);
			       }
			    }
			}
			for(int i=0;i<n;i++)
			{
			   for(int j=0;j<n;j++)
			   {
			       b[i][j] = a2[c[i].getindex()][c[j].getindex()];
			   }
			}
			for(int i=0;i<n;i++)
			{
			   for(int j=0;j<N2;j++)
			  {
			     if(c[i].getindex() == j)
			     {
			        c[i].setsun(sun2[j]);
			     }
			  }
			}	
			for(int i=0;i<n;i++)
            {
  	           for(int j=0;j<N2;j++)
  	           {
                  if(c[i].getindex() == j)
                 {
 		            c[i].ho.setnameks(hot2[j].getnameks());
 	                c[i].ho.setlocks(hot2[j].getlocks());
 		            c[i].ho.setroomks(hot2[j].getroomks());
	                c[i].ho.setrlks(hot2[j].getrlks());
 		            c[i].ho.setpriceks(hot2[j].getpriceks());
 		            c[i].ho.setphoneks(hot2[j].getphoneks());
  	             }
              } 	                        
            }
            for(int i=0;i<n;i++)
            {
  	            for(int j=0;j<N2;j++)
  	           {
  	              if(c[i].getindex() == j)
  	              {
 		           c[i].re.setnamenh(res2[j].getnamenh());
 		           c[i].re.setlocnh(res2[j].getlocnh());
 		           c[i].re.setroomnh(res2[j].getroomnh());
 		           c[i].re.setrt(res2[j].getrt());
 		           c[i].re.setpricenh(res2[j].getpricenh());
 		           c[i].re.setphonenh(res2[j].getphonenh());
  	              }
               }  	                        
            }	
			ShowConsoleCursor(true);
			PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	        system("cls");
	        system("Color f0");
	        ifstream fi22("Display/execute2.txt",ios::in);
         	if(!fi22)
	        {
		        cout<<"Nope";
		        exit(1);
	        }
	        string in2;
            while(!fi22.eof())
            {
    	       getline(fi22,in2);
   	           cout<<in2<<endl;
            }          
            int start2,date2,month2;
            string batdau;
            float hour2;
			gotoXY(85,11);
            cin>>batdau;
            for(int i=0;i<n;i++)
            {
              if(c[i].getnamect()== batdau)
              {
               start2 = i;
              }
            } 
            gotoXY(85,13);
            cin>>date2;
            while(date2<0 || date2 > 31)
            {
            	gotoXY(85,13);
            	cout<<"____";
            	gotoXY(85,13);
                cin>>date2;
            }
            gotoXY(85,15);
            cin>>month2;
            while(month2<0 || month2 > 12)
            {
            	gotoXY(85,15);
            	cout<<"____";
            	gotoXY(85,15);
                cin>>month2;
            }
            gotoXY(85,17);
            cin>>hour2;
            gotoXY(85,19);
            cin>>tien1;
            dijkstra(b,fee2,timed,start2,N2,n,c,tien1,hour2,month2);           	
        	//ket thuc tuy chon       	
        }
        else if(index == 2)
        {
        	//theo thu tu
        	setdata(c,a2,hot2,res2,timeh2,ten2,bus2,fee2,ss2,price2,sun2,rain2,food2,n,N2);
			ShowConsoleCursor(true);
			PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	        system("cls");
	        system("Color f0");
	        ifstream fi("Display/execute2.txt",ios::in);
         	if(!fi)
	        {
		        cout<<"Nope";
		        exit(1);
	        }
	        string in;
            while(!fi.eof())
            {
    	       getline(fi,in);
   	           cout<<in<<endl;
            }          
            int start,month,date3;
            string b;
            float hour;
            float tien2;
			gotoXY(85,11);
            cin>>b;
            for(int i=0;i<n;i++)
            {
              if(c[i].getnamect()== b)
              {
               start = i;
              }
            } 
            gotoXY(85,13);
            cin>>date3;
            while(date3<0 || date3 > 31)
            {
            	gotoXY(85,13);
            	cout<<"____";
            	gotoXY(85,13);
                cin>>date3;
            }
            gotoXY(85,15);
            cin>>month;
            while(month<0 || month > 12)
            {
            	gotoXY(85,15);
            	cout<<"____";
            	gotoXY(85,15);
                cin>>month;
            }
            gotoXY(85,17);
            cin>>hour;
            gotoXY(85,19);
            cin>>tien2;
            dijkstra(a2,fee2,timeh2,start,N2,n,c,tien2,hour,month);
        	//ket thuc theo thu tu
        }
			//end
		}
		//mac dinh
		else if(index == 1)
		{
			setdata(c,a2,hot2,res2,timeh2,ten2,bus2,fee2,ss2,price2,sun2,rain2,food2,N2,N2);
			ShowConsoleCursor(true);
			PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	        system("cls");
	        system("Color f0");
	        ifstream fi("Display/execute2.txt",ios::in);
         	if(!fi)
	        {
		        cout<<"Nope";
		        exit(1);
	        }
	        string in;
            while(!fi.eof())
            {
    	       getline(fi,in);
   	           cout<<in<<endl;
            }          
            int start,month,date1;
            string b;
            float hour;
            float tien3;
			gotoXY(85,11);
            cin>>b;
            for(int i=0;i<N2;i++)
            {
              if(c[i].getnamect()== b)
              {
               start = i;
              }
            } 
            gotoXY(85,13);
            cin>>date1;
            while(date1<0 || date1 > 31)
            {
            	gotoXY(85,13);
            	cout<<"____";
            	gotoXY(85,13);
                cin>>date1;
            }
            gotoXY(85,15);
            cin>>month;
            while(month<0 || month > 12)
            {
            	gotoXY(85,15);
            	cout<<"____";
            	gotoXY(85,15);
                cin>>month;
            }
            gotoXY(85,17);
            cin>>hour;
            gotoXY(85,19);
            cin>>tien3;
            dijkstra(a2,fee2,timeh2,start,N2,N2,c,tien3,hour,month);
		}
	}  
}

 void showmenu()
{
        char key=0;
        int index =1; 
        while(key!=13){      
        gotoXY(48,10);
        Color(63);
        if(index==1){Color(12);}
        cout<<"GIOI THIEU CHUONG TRINH";
        gotoXY(45,12);
        Color(63);
        if(index==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"THONG TIN TONG QUAT THANH PHO";
        gotoXY(45,14);
        Color(63);
        if(index==3){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"THONG TIN CHI TIET THANH PHO";
        gotoXY(55,16);
        Color(63);
        if(index==4){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"TRA CUU";
        /*gotoXY(54,18);
        Color(63);
        if(index==5){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"MINI GAME";*/
        gotoXY(56,18);
        Color(63);
        if(index==5){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"ADMIN";
        gotoXY(56,20);
        Color(63);
        if(index==6){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);Color(12);}
        cout<<"THOAT";
        /////////////UP=224/72 Down=224/80 Enter=13
        key=getch();
        if(key==80 || key==39){index++;}
        else if(key==72 || key==37){index--;}
        if(index==7){index=1;}
        if(index==0){index=6;}
        }
        if(index==1)
		{
          introduction();
          char key;
          key=getch();
		   if(key == 13 || key == 27 || key == -32)
          	    {
    	          	system("cls");
	    		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	         	system("Color b0");
	            ifstream fi("Display/tieude2.txt",ios::in);
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
                showmenu();
				ShowConsoleCursor(false);
    	          }
		}
        else if (index==2){
            generalinfo(ten,bus,ss);
            char key;
            key=getch();
            if(key == 27 || key == 13 || key == -32)
            {
    	        system("cls");
	    		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	         	system("Color b0");
	            ifstream fi("Display/tieude2.txt",ios::in);
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
                showmenu();
				ShowConsoleCursor(false);
           }
        }
        else if (index==3){
            detailinfo();
            char key;
            key=getch();
            if(key == 27 || key == 13 || key == -32)
            {
    	        system("cls");
	    		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	         	system("Color b0");
	            ifstream fi("Display/tieude2.txt",ios::in);
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
                showmenu();
				ShowConsoleCursor(false);
           }
        }
        else if (index==4){
            execute();
            char key;
            key=getch();
            if(key == 27 || key == 13 || key == -32)
            {
    	        system("cls");
	    		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	         	system("Color b0");
	            ifstream fi("Display/tieude2.txt",ios::in);
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
                showmenu();
				ShowConsoleCursor(false);
           }
        }
        /*else if (index==5){
                game();
                char key;
               key=getch();
               if(key == 27 || key == 13)
              {
    	        system("cls");
	    		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	         	system("Color b0");
	            ifstream fi("Display/tieude2.txt",ios::in);
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
                showmenu();
				ShowConsoleCursor(false);
              }
        }*/
        else if(index == 5 )
        {
        	    admin();
        	    system("cls");
	    		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	         	system("Color b0");
	            ifstream fi("Display/tieude2.txt",ios::in);
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
                showmenu();
				ShowConsoleCursor(false);
        }
        else if(index==6)
		{
  	            PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	    		system("cls");
	    		gotoXY(0,10);
	    		system("Color b0");
	    		loadend();
	    		gotoXY(47,21);
	    		exit(1);
        }
        system("Color b0");
  }
  void mainmenu()
{
    ShowConsoleCursor(false); 
	system("Color b0");
	ifstream fi("Display/tieude2.txt",ios::in);
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
    showmenu();   
}
void loading()
{
	ifstream fi("Display/car0.txt",ios::in);
	ifstream fi2("Display/car1.txt",ios::in);
	ifstream fi3("Display/car2.txt",ios::in);
	ifstream fi4("Display/car3.txt",ios::in);
	ifstream fi5("Display/car4.txt",ios::in);
	ifstream fi6("Display/car5.txt",ios::in);
	ifstream fi7("Display/car6.txt",ios::in);
	ifstream fi8("Display/car7.txt",ios::in);
	ifstream fi9("Display/car8.txt",ios::in);
	ifstream fi10("Display/car9.txt",ios::in);
	ifstream fi11("Display/car10.txt",ios::in);
	ifstream fi12("Display/car11.txt",ios::in);
	ifstream fi13("Display/car12.txt",ios::in);
	ifstream fi14("Display/car13.txt",ios::in);
	ifstream fi15("Display/car14.txt",ios::in);
	ifstream fi16("Display/car15.txt",ios::in);
	ifstream fi17("Display/car16.txt",ios::in);
	ifstream fi18("Display/car17.txt",ios::in);
	ifstream fi19("Display/car18.txt",ios::in);
	ifstream fi20("Display/car19.txt",ios::in);
	ifstream fi21("Display/car20.txt",ios::in);
	ifstream fi22("Display/car21.txt",ios::in);
	ifstream fi23("Display/car22.txt",ios::in);
	ifstream fi24("Display/car23.txt",ios::in);
	ifstream fi25("Display/car24.txt",ios::in);
	ifstream fi26("Display/car25.txt",ios::in);
	ifstream fi27("Display/car26.txt",ios::in);
	ifstream fi28("Display/car27.txt",ios::in);
	ifstream fi29("Display/car28.txt",ios::in);
	if(!fi)
	{
		cout<<"Nope";
		exit(1);
	}
	string a;
	gotoXY(0,10);
    while(!fi.eof())
    {
    	getline(fi,a);
    	cout<<a<<endl;
    }
    Sleep(200);
    system("cls");
    gotoXY(0,10);
    while(!fi2.eof())
    {
    	getline(fi2,a);
    	cout<<a<<endl;
    }
      Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi4.eof())
    {
    	getline(fi4,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi6.eof())
    {
    	getline(fi6,a);
    	cout<<a<<endl;
    }
      Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi8.eof())
    {
    	getline(fi8,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi10.eof())
    {
    	getline(fi10,a);
    	cout<<a<<endl;
    }
    Sleep(200);
    system("cls");
    gotoXY(0,10);
    while(!fi11.eof())
    {
    	getline(fi11,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi12.eof())
    {
    	getline(fi12,a);
    	cout<<a<<endl;
    }
      Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi13.eof())
    {
    	getline(fi13,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi14.eof())
    {
    	getline(fi14,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi15.eof())
    {
    	getline(fi15,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi16.eof())
    {
    	getline(fi16,a);
    	cout<<a<<endl;
    }
      Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi17.eof())
    {
    	getline(fi17,a);
    	cout<<a<<endl;
    }
      Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi18.eof())
    {
    	getline(fi18,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi19.eof())
    {
    	getline(fi19,a);
    	cout<<a<<endl;
    }
    Sleep(200);
    system("cls");
    gotoXY(0,10);
    while(!fi20.eof())
    {
    	getline(fi20,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi21.eof())
    {
    	getline(fi21,a);
    	cout<<a<<endl;
    }
      Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi22.eof())
    {
    	getline(fi22,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi23.eof())
    {
    	getline(fi23,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi24.eof())
    {
    	getline(fi24,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi25.eof())
    {
    	getline(fi25,a);
    	cout<<a<<endl;
    }
      Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi26.eof())
    {
    	getline(fi26,a);
    	cout<<a<<endl;
    }
      Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi27.eof())
    {
    	getline(fi27,a);
    	cout<<a<<endl;
    }
     Sleep(200);
     system("cls");
     gotoXY(0,10);
    while(!fi28.eof())
    {
    	getline(fi28,a);
    	cout<<a<<endl;
    }
    system("cls");
    mainmenu();
}
void start()
{
	system("Color b0");
    PlaySound(TEXT("Sound/welcome.wav"),NULL,SND_ASYNC);
	loadtitle();
	loadbg();	
	PlaySound(TEXT("Sound/horn.wav"),NULL,SND_ASYNC);
	gotoXY(0,23);
	cout<<setw(40)<<" ";
	char a[]="Press Enter to continue or ESC to exit";
    for(int i=0;i<strlen(a);i++)
    {
    	Sleep(30);
    	cout<<a[i];
    }
    ShowConsoleCursor(false);
    char key;
    while(true)
    {
    	if(kbhit())
    	{
	    	key=getch();
	    	if(key == 13)
	    	{
	    		PlaySound(TEXT("Sound/car.wav"),NULL,SND_ASYNC);
	    		system("cls");
	    		system("Color 70");
	    		loading();
	    	}
	    	else if(key == 27)
	    	{
	    		PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
	    		system("cls");
	    		gotoXY(0,10);
	    		loadend();
	    		gotoXY(47,21);
	    		exit(1);
	    	}
	    }
    }
}