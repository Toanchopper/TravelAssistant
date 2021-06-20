
DWORD WINAPI ThreadFn(LPVOID vpParam)
{
    int k[9] = { 13,32,36,37,38, 39, 40,41,42 };
    int i=0;
    while (1)
    {
        for (int n=0;n<9;n++)
        {
            i=k[n];
            if (GetAsyncKeyState(i)==-32767)
            {
                if (i==32)
                {
                    if(onpause==0){onpause=1;}
                    else if(onpause==1){onpause=0;}
                }
                if (i==37)
                {
                    direction=left;
                }
                else if (i==39)
                {
                    direction=right;
                }
                else if (i==38)
                {
                    direction=up;
                }
                else if (i==40)
                {
                    direction=down;
                }
            }
        }
    }
    return 0;
}
///////////////////////////////////////////////////////////
DWORD tid;
HANDLE hThread;
void startinput()
{
    hThread = CreateThread(0, 0, ThreadFn, 0, 0, &tid);
}
void stopinput()
{
    CloseHandle(hThread);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////                 //////////////////////////////////////////////////////////////////////////
/////////////////   AUTO INPUT    //////////////////////////////////////////////////////////////////////////
/////////////////                 //////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AI{
public:
snake* asnk;
foodsnake* afud;
int dx,dy;
int sx,sy;
    void init(snake* s,foodsnake* f){
        asnk=s;
        afud=f;
    }
    void getsd(){
        dx=afud->x;
        dy=afud->y;
        ////
        int size=asnk->body.size();
        POINT temp=asnk->body[size-1];
        sx=temp.x;
        sy=temp.y;
    }
    void follow(){
        if(dx>sx){direction=right;}
        if(dy>sy){direction=down;}
        if(dx<sx){direction=left;}
        if(dy<sy){direction=up;}
        Sleep(5);
    }
};
/////////////////////////
AI ai;
DWORD WINAPI ThreadFn2(LPVOID vpParam)
{
    while (1)
    {
        ai.getsd();
        ai.follow();
    }
    return 0;
}
////////////////////////////////////////////////////////////
DWORD tid2;
HANDLE hThread2;
void startinputA(snake* s,foodsnake* f)
{
    hThread2 = CreateThread(0, 0, ThreadFn2, 0, 0, &tid2);
    ai.init(s,f);
}
void stopinputA()
{
    CloseHandle(hThread2);
}
