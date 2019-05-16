#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<self.h>
#include "Header.h"
FILE *fr,*fw,*fp1,*fp2;

 int x,y;
 char get,getstr[200];

char menu();
int getid();

struct tm t;

#include "Add Records.c"
#include "Delete.c"
#include "Search.c"

main()
{
    while(1)
        init();
}

char menu()
{
    system("cls");  title(" Hospital Management ");
    x=1;
	do
    {
        if(x==1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(20,10);   puts("Add new patient record");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(20,12);   puts("Search  or edit record");
            gotoxy(20,14);   puts("Know the records of patients");
            gotoxy(20,16);   puts("Delete the records");
            gotoxy(20,18);   puts("Exit");
        }
        else if(x==2)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(20,12);   puts("Search  or edit record");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(20,10);   puts("Add new patient record");
            gotoxy(20,14);   puts("Know the records of patients");
            gotoxy(20,16);   puts("Delete the records");
            gotoxy(20,18);   puts("Exit");
        }
        else if(x==3)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(20,14);   puts("Know the records of patients");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(20,10);   puts("Add new patient record");
            gotoxy(20,12);   puts("Search  or edit record");
            gotoxy(20,16);   puts("Delete the records");
            gotoxy(20,18);   puts("Exit");
        }
        else if(x==4)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(20,16);   puts("Delete the records");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(20,10);   puts("Add new patient record");
            gotoxy(20,12);   puts("Search  or edit record");
            gotoxy(20,14);   puts("Know the records of patients");
            gotoxy(20,18);   puts("Exit");
        }
        else if(x==5)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(20,18);   puts("Exit");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(20,10);   puts("Add new patient record");
            gotoxy(20,12);   puts("Search  or edit record");
            gotoxy(20,14);   puts("Know the records of patients");
            gotoxy(20,16);   puts("Delete the records");
        }
        get=getch();
        if(get==down)
            x++;
        else if(get==up)
            x--;
        if(x>5 || x<1)
            x=5;
    }while(get!=13);
    return x;
}
void init()
{
    switch(menu())
    {
    case 1:system("cls");
        AddMenu();
        break;
    case 2:system("cls");
        SearchRecord();
        break;
    case 3:system("cls");
        SearchRecord();
        break;
    case 4:system("cls");
        DeleteRecord();
        break;
    case 5:system("cls");
        gotoxy(20,10);   puts("Thank You for using our service");
        Sleep(700);
        _Exit(1);
        break;
    }
}
int getid()
{
    srand(time(NULL));
    return (rand()%100000);
}
void title(char *ti)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoxy(40,3);printf("%s",ti);
    puts("      ");
    for(int i=0;ti[i]!='\0';i++)
    {
        gotoxy(40+i,2);		printf(" %5c ",32);
        gotoxy(40+i,4);		printf(" %5c ",32);
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),128);
    for(int i=0;ti[i]!='\0';i++)
    {
        gotoxy(40+i,2);		printf("%c",433);
        gotoxy(40+i,4);		printf("%c",433);
    }
}
