#include<stdio.h>
#include<time.h>
#include<self.h>
SYSTEMTIME t;
int nweek,rmnth,year;
main()
{
    GetLocalTime(&t);
    nweek=t.wDayOfWeek+1;
    rmnth=t.wMonth;
    year=t.wYear;
    int nextMonth=0;
    while(1)
    {
        nextMonth = monthN(nextMonth);
        rmnth = mnthN(nextMonth);
        month(rmnth,nweek);
        getch();
    }
}
void month(mnth,wk)
{
    system("cls");
    graph();
    int day=1,week=wk;
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=7;j++)
        {
            gotoxy(6*j+4,2*i+6);
            week--;
            if(week<=0)
            {
                if(day>mnth)
                    break;
                nweek = rweek(j);
                printf("%d",day++);
            }
        }
    }
}
int monthN(int n)
{
    if(n>=1 && n<12)
    {
        n++;
        return n;
    }

    return 1;
}
int mnthN(int m)
{
    if(m==2)
    {
        if(year%4==0)
            return 29;
        else
            return 28;
    }
    else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        return 31;
    }
    else if(m==2||m==4||m==6||m==9||m==8||m==11)
    {
        return 30;
    }
}
int rweek(int wek)
{
    switch(wek)
    {
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    case 5:
        return 6;
    case 6:
        return 7;
    case 7:
        return 1;
    }
}
void graph()
{
    gotoxy(10,3);
    printf(" Year %d",year);
    gotoxy(10,5);
    printf("Su");
    gotoxy(16,5);
    printf("Mo");
    gotoxy(22,5);
    printf("Tu");
    gotoxy(28,5);
    printf("We");
    gotoxy(34,5);
    printf("Th");
    gotoxy(40,5);
    printf("Fir");
    gotoxy(46,5);
    printf("Sa");
}
