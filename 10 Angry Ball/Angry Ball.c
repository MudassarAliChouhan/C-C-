
#include<windows.h>
#include<time.h>
#include<conio.h>

int random()
{
    int random;
    srand(time(NULL));
    random = (rand()%90);
    return random;
}
void gotoxy(int column,int row)
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void ball(int size,int xaxis,int yaxis)
{
    if(size<2)
        size = 3;
    if(size%2==0)
        size++;
    int half = size/2;
    int z=half;

    for(int i=0,j; i<size; i++)
    {
        gotoxy(xaxis,yaxis++);
        for(j=0; j<size-z; j++)
            if(j>=z)
                printf("*");
            else
                printf(" ");
        if(i<half)
            z--;
        else
            z++;
    }
}
void eraseBall(int size,int xaxis,int yaxis)
{
    if(size<2)
        size = 3;
    if(size%2==0)
        size++;
    int half = size/2;
    int z=half;

    for(int i=0,j; i<size; i++)
    {
        gotoxy(xaxis,yaxis++);
        for(j=0; j<size-z; j++)
            if(j>=z)
                printf(" ");
            else
                printf(" ");
        if(i<half)
            z--;
        else
            z++;
    }
}
int retNetX(int x)
{
    static int deci =0, turn=1;
    int *turnptr = &turn;
    static int mod=30;
    int *modptr = &mod;
    if(deci%*modptr==0)
    {
        if(turn == 1)
            *turnptr = 0;
        else
            *turnptr = 1;

        int tmp;
        tmp=random();
        if(tmp>9 && tmp<41)
            if(tmp%10!=0)
            {
                tmp=tmp/10;
                *modptr=tmp*10;
            }
    }
    deci++;
    //if(x>-1&&x<40)
    if(turn==1)
        return x-=1;
    else
        return x+=1;
}
int retNetY(int y)
{
    static int deci = 0, turn=1;
    int *turnptr = &turn;
    static int mod=30;
    int *modptr = &mod;

    if(deci%20==0)
    {
        if(turn == 1)
            *turnptr = 0;
        else
            *turnptr = 1;

        int tmp;
        tmp=random();
        if(tmp>9 && tmp<61)
            if(tmp%10!=0)
            {
                tmp=tmp/10;
                *modptr=tmp*10;
            }
    }
    deci++;
    //if(y>-1&&y<40)
    if(turn==1)
        return --y;
    else
        return ++y;
}
void mvBal(int delay)
{
    int mv = 0;
    int size=3,x=0,y=0;
    while(1)
    {
        ball(size,x,y);
        Sleep(delay);
        eraseBall(size,x,y);
        x = retNetX(x);
        y = retNetY(y);
    }
}
int main()
{
    mvBal(200);
    exit(0);
    getch();
}
