#include<stdio.h>
#include<windows.h>
#include<self.h>
#define O 'U'
#define X 'C'

    char buffer[9];
    int num,round=1;

int main()
{
    draw();
    while(round<10)
    {
        gotoxy(30,24);printf("          ");
        gotoxy(20,24);printf("You Turn  ");

        scanf("%d",&num);
        buffer[chk(num)-1]=O;
        round++;

        num=chk(getno());
        printf("check=%d getno=%d",num,getno());
        buffer[num-1]=X;
        round++;
        disto();
    }
}
int getno()
{
    if(round==2&&buffer[4]==0)
        return 5;
    else if(round==2&&buffer[4]!=0)
        return 9;

                if(buffer[4]==O&&buffer[2]==O)
                {
                    if(buffer[4]==O&&buffer[8]==O)
                    {
                        if(buffer[4]==O&&buffer[0]==O)
                        {
                            if(buffer[4]==O&&buffer[6]==O)
                            {
                                return 3;
                            }
                            return 9;
                        }
                        return 1;
                    }
                    return 7;
                }

                if(buffer[0]==O&&buffer[2]==O)
                    return 2;
                else if(buffer[3]==O&&buffer[5]==O)
                    return 5;
                else if(buffer[6]==O&&buffer[8]==O)
                    return 8;

                if(buffer[0]==O&&buffer[6]==O)
                    return 4;
                else if(buffer[1]==O&&buffer[7]==O)
                    return 5;
                else if(buffer[2]==O&&buffer[8]==O)
                    return 6;

                if(buffer[0]==O&&buffer[1]==O)
                    return 3;
                else if(buffer[3]==O&&buffer[4]==O)
                    return 6;
                else if(buffer[6]==O&&buffer[7]==O)
                    return 9;

                if(buffer[1]==O&&buffer[2]==O)
                    return 1;
                else if(buffer[4]==O&&buffer[5]==O)
                    return 4;
                else if(buffer[7]==O&&buffer[8]==O)
                    return 7;

                if(buffer[4]==O&&buffer[0]==O)
                    return 9;
                if(buffer[4]==O&&buffer[6]==O)
                    return 3;
                if(buffer[4]==O&&buffer[8]==O)
                    return 1;
                if(buffer[4]==O&&buffer[6]==O)
                    return 3;
        return 1;
}
int chk(int chk)
{
    for(int i=0;i<10;i++)
    {
        if(buffer[i]==0)
            return i;
    }
}
void draw()
{
    gotoxy(20,2);
    printf("T i c    T a c    T o c");
    gotoxy(20,3);
    printf("=======================");
    for(int i=16;i<51;i++)
    {
        gotoxy(i,10);
        printf("_");
        gotoxy(i,15);
        printf("_");
    }
    for(int i=6;i<20;i++)
    {
        gotoxy(26,i);
        printf("|");
        gotoxy(38,i);
        printf("|");
    }
}
void pass(int index,char c)
{
    switch(index)
    {
    case 1: gotoxy(20,7);
        printf("%c",c);  break;

    case 2: gotoxy(32,7);
        printf("%c",c);  break;

    case 3: gotoxy(44,7);
        printf("%c",c);  break;

    case 4: gotoxy(20,12);
        printf("%c",c);  break;

    case 5: gotoxy(32,12);
        printf("%c",c);  break;

    case 6: gotoxy(44,12);
        printf("%c",c);  break;

    case 7: gotoxy(20,17);
        printf("%c",c);  break;

    case 8: gotoxy(32,17);
        printf("%c",c);  break;

    case 9: gotoxy(44,17);
        printf("%c",c);  break;
    }
}
void disto()
{
        for(int i=0;i<10;i++)
        {
            if(buffer[i]==O)
                pass(i+1,O);
            else if(buffer[i]==X)
                pass(i+1,X);
        }
}

