using namespace std;

class menu{
public:
    HANDLE hstdout;
    int index;
    int key;
         menu(){
            hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
            index=1;
         }
    void showgamemenu(){
	    system("cls");
	    system("Color f0");
	    ifstream fi("Display/game.txt",ios::in);
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
        key=0;
        while(key!=13){
        gotoxy(56,11);
        colorit(43);
        if(index==1){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);colorit(14);}
        cout<<"PLAY";
        gotoxy(53,12);
        colorit(43);
        if(index==2){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);colorit(14);}
        cout<<"AUTO PLAY";
        gotoxy(55,13);
        colorit(43);
        if(index==3){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);colorit(14);}
        cout<<"ABOUT";
        gotoxy(53,14);
        colorit(43);
        if(index==4){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);colorit(14);}
        cout<<"MY CHANNEL";
        gotoxy(56,15);
        colorit(43);
        if(index==5){PlaySound(TEXT("Sound/select.wav"),NULL,SND_ASYNC);colorit(14);}
        cout<<"EXIT";
        /////////////UP=224/72 Down=224/80 Enter=13
        key=getch();
        if(key==80){index++;}
        else if(key==72){index--;}
        if(index==6){index=1;}
        if(index==0){index=5;}
        }
        if(index==1){PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);startit();}
        else if (index==2){
        	PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
            startauto();
        }
        else if (index==3){
        	PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
            showabout();
        }
        else if (index==4){
        	PlaySound(TEXT("Sound/click.wav"),NULL,SND_ASYNC);
            ShellExecute( NULL, NULL, TEXT( "http://www.google.com" ), NULL, NULL, SW_SHOW );
            showgamemenu();
        }
        else if(index==5)
        {
        	exit(1);
        }       
    }
    void startit(){
    	system("cls");
    	system("Color f0");
        play();
        showgamemenu();
        getch();
    }
    void startauto(){
    	system("cls");
    	system("Color f0");
        autoplay();
        showgamemenu();
        getch();
    }
    void showabout(){
        system("cls");
        system("Color f0");
        key=0;
        while(key!=13 & key!=8){
        gotoxy(3,3);colorit(12);
        cout<<"============================";
        gotoxy(3,4);
        cout<<"|    SNAKE GAME CONSOLE    |";
        gotoxy(3,5);
        cout<<"============================";
        gotoxy(3,6);colorit(15);
        cout<<"Written with native c++.";
        gotoxy(3,7);
        cout<<"Developed using Codeblocks IDE.";
        key=getch();
        }
        showgamemenu();
        getch();
    }
    void colorit(int col){//12=red, 15=white---------------->this.colorit(12);  this.colorit(15);
        SetConsoleTextAttribute( hstdout, col );
    }

};
