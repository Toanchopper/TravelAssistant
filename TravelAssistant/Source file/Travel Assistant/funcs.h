using namespace std;

bool onplay;
int onpause=0;
int direction=0;
////////////////////////////////////////
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class board
{
public:
    int mat[matx][maty];
    board()
    {
        for (int j=0;j<maty;j++)
        {
            for (int i=0;i<matx;i++)//(i==0 || i==matx-1 || j==0 || j==maty-1)
            {
                mat[i][j]=0;
                //
                mat[0][j]=2;
                mat[matx-1][j]=2;
                mat[i][0]=2;
                mat[i][maty-1]=2;

            }
        }
    }
    void addpt(int x,int y,int val)
    {
        if(mat[x][y]!=2){
        mat[x][y]=val;
        }
    }
    void delpt(int x,int y)
    {
        if(mat[x][y]!=2){
        mat[x][y]=0;
        }
    }
};
class foodsnake
{
public:
    int x,y;
    foodsnake(board* b)
    {
        x=8;
        y=9;
        b->addpt(8,9,3);
    }
    void newfood(board* b)
    {
        b->addpt(x,y,1);
        x=rand()%(matx-2)+1;
        y=rand()%(maty-2)+1;
        if (x==0 | x==matx-1 |  y==0 | y==maty-1 )
        {
            x=5;
            y=7;
        }
        b->addpt(x,y,3);
    }
};

class snake
{
public:
    POINT temp,tempR;
    vector<POINT> body;
    int score;
    int level;
    snake(board* b)
    {
        score=10;
        level=0;
        //
        b->addpt(5,5,5);//End(tail) is 5
        temp.x=5;
        temp.y=5;
        body.push_back(temp);
        b->addpt(6,5,1);
        temp.x=6;
        temp.y=5;
        body.push_back(temp);
        b->addpt(7,5,4);//Head is 4
        temp.x=7;
        temp.y=5;
        body.push_back(temp);
    }
    void move(board* b,int direction)
    {
        temp=body[body.size()-1];
        b->addpt(temp.x,temp.y,1);//it was Head(4), now we made it Body(1)
        if (direction==0)
        {
            temp.x++;
        }
        else if (direction==1)
        {
            temp.y--;
        }
        else if (direction==2)
        {
            temp.x--;
        }
        else if (direction==3)
        {
            temp.y++;
        }
        body.push_back(temp);
        //if (b->mat[temp.x][temp.y]!=2 & b->mat[temp.x][temp.y]!=1){
            b->addpt(temp.x,temp.y,4);
        //}
        //
        temp=body[0];
        b->delpt(temp.x,temp.y);
        body.erase(body.begin()+0);
        //
        temp=body[0];
        b->addpt(temp.x,temp.y,5);//it was Body(1), now we made it End(5)
    }
    void checkeat(board* b,foodsnake* f,int direction)
    {
        temp=body[body.size()-1];
        tempR=body[0];
        if (temp.x==f->x & temp.y==f->y)
        {
            //b->addpt(temp.x,temp.y,1);
            b->addpt(tempR.x,tempR.y,1);//turn the End(5) to Body(1)
            if (direction==0)
            {
                //temp.x++;
                tempR.x--;
            }
            else if (direction==1)
            {
                //temp.y--;
                tempR.y++;
            }
            else if (direction==2)
            {
                //temp.x--;
                tempR.x++;
            }
            else if (direction==3)
            {
                //temp.y++;
                tempR.y--;
            }
            f->newfood(b);
            //body.push_back(temp);
            //b->addpt(temp.x,temp.y,4);
            score+=10;
            body.insert(body.begin(),tempR);
            b->addpt(tempR.x,tempR.y,5);
        }
        level=score/100;
    }
    void checkcoll(board* b,bool* bul)
    {
        temp=body[body.size()-1];
        if (b->mat[temp.x][temp.y]==2) { *bul=false; }
        //else if (b->mat[temp.x][temp.y]==1) { *bul=false; }
    }

};

class display
{
public:
    int delay;
    void draw(board b)
    {
        for (int j=0;j<maty;j++)
        {
            for (int i=0;i<matx;i++)
            {
                gotoxy(i,j);
                if (b.mat[i][j]==1)
                {
                    cout<<"O";
                }
                else if (b.mat[i][j]==2)
                {
                    cout<<"O";
                }
                else if (b.mat[i][j]==3)
                {
                    cout<<"O";
                }
                else if (b.mat[i][j]==4)
                {
                    cout<<"O";
                }
                else if (b.mat[i][j]==5)
                {
                    cout<<"O";
                }
                else
                {
                    cout<<" ";
                }
            }
        }
    }
    void showdata(snake* s){
    gotoxy(matx+3,2);//cout<<"onpause:"<<onpause;gotoxy(33,3);cout<<"direction:"<<direction;
        if(onpause){cout<<"PAUSED";}else{cout<<"          ";}
        gotoxy(matx+3,3);
        cout<<"SCORE:"<<s->score;
        gotoxy(matx+3,4);
        cout<<"LEVEL:"<<s->level;
    }
    void delayit(snake* s){
        delay=10-2*(s->level);
        if(delay<0){delay=0;}
        Sleep(delay*10);
    }
};
//////////////////////////////////////////////////////////////////
void startinput();
void stopinput();
void startinputA(snake* s,foodsnake* f);
void stopinputA();
void play()
{
    onplay=true;
    onpause=false;
    /////////////////
    board mb;
    foodsnake mfud(&mb);
    snake msnk(&mb);
    display mdis;

    startinput();
    while (onplay)
    {
        msnk.checkcoll(&mb,&onplay);
        msnk.move(&mb,direction);
        msnk.checkeat(&mb,&mfud,direction);
        mdis.draw(mb);
        mdis.showdata(&msnk);
        mdis.delayit(&msnk);
        while(onpause==1){Sleep(100);}

    }
    stopinput();
}

void autoplay()
{
    onplay=true;
    onpause=false;
    /////////////////
    board mb;
    foodsnake mfud(&mb);
    snake msnk(&mb);
    display mdis;

    startinputA(&msnk,&mfud);//startinput();
    while (onplay)
    {
        msnk.checkcoll(&mb,&onplay);
        msnk.move(&mb,direction);
        msnk.checkeat(&mb,&mfud,direction);
        mdis.draw(mb);
        mdis.showdata(&msnk);
        //mdis.delayit(&msnk);
        while(onpause==1){Sleep(100);}

    }
    stopinputA();//stopinput();
}
