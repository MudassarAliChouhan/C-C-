int isChar(char);
int isInt(char);

char spacial[20][20];
char room[20][10][5];

void AddMenu()
{
    add:    x=1;
    system("cls");
    title(" Add new patient record ");
	do
    {
        if(x==1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(20,10);  puts("O.P.D");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(20,12);  puts("Emergency ");
            gotoxy(20,14);  puts("Back      ");
        }
        else if(x==2)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(20,12);  puts("Emergency");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(20,10);  puts("O.P.D     ");
            gotoxy(20,14);  puts("Back      ");
        }
        else if(x==3)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(20,14);  puts("Back");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(20,10);  puts("O.P.D     ");
            gotoxy(20,12);  puts("Emergency ");
        }
        get=getch();
        if(get==down)
            x++;
        else if(get==up)
            x--;
        if(x>3 || x<1)
            x=3;
    }while(get!=13);
    switch(x)
    {
    case 1:system("cls");
        title(" Add new patient of O.P.D ");
        addRecord("O.P.D");
        break;
    case 2:system("cls");
        title(" Add new patient of Emergency ");
        addRecord("Emergency");
        break;
    case 3:
        init();
        break;
    }
        goto add;
}
void addRecord(char *ch)
{
    fw = fopen("Record.dat","a");
    int i=0;
    time(&t);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    gotoxy(5,7);  	printf("ID:");
    gotoxy(x=20,y=7);    puts("Name :");
    gotoxy(x,y+=2);      puts("Address :");
    gotoxy(x,y+=2);      puts("Age :");
    gotoxy(x,y+=2);      puts("Gender.(m/f) :");
    gotoxy(x,y+=2);      puts("Disease Descrp :");
    gotoxy(25,++y);         puts("In Short :");
	for(int i=7;i<17;i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		gotoxy(18,i);
		printf("%c",434);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

					strcpy(hosp.cas,ch);
					hosp.id = getid();
    gotoxy(9,7);  	printf("%d",hosp.id);
    gotoxy(27,7);  	gets(hosp.name);
                    SpaceOut(hosp.name);
    gotoxy(30,9); 	gets(hosp.addr);
                    SpaceOut(hosp.addr);
					hosp.age=chos(26,11);
	gender:
    gotoxy(35,13); 	hosp.gender=getch();
					{
						if(hosp.gender=='m'||hosp.gender=='M')
							hosp.gender='M';
						else if(hosp.gender=='F'||hosp.gender=='f')
							hosp.gender='F';
						else
						{
							        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
							gotoxy(40,13);puts("Wrong");
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
							goto gender;
						}
							gotoxy(35,13); 	printf("%c",hosp.gender);
							gotoxy(40,13);puts("     ");
					}
    gotoxy(37,15);  gets(hosp.dsp);
                    SpaceOut(hosp.dsp);
    readfile();
	refer();
	room_no();
	strcpy(getstr,ctime(&t));
	SpaceOut(getstr);
	getstr[24]='\0';
	strcpy(hosp.dt,getstr);

	for(int i=19;i<22;i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		gotoxy(18,i);
		printf("%c",434);
	}
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	gotoxy(20,19);  printf("Reff. Specialist no :");
	gotoxy(20,21);  printf("Room#");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(42,19);  printf("%s",hosp.refer);
	gotoxy(26,21);  printf("%s",hosp.room);

	gotoxy(30,26);	printf("Save"); x=0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
    gotoxy(15,26);	printf("Cancel");
	do
    {
        if(x==left)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(30,26);	printf("Save");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(15,26);	printf("Cancel");   y=0;
        }
        else if(x==right)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            gotoxy(15,26);	printf("Cancel");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
            gotoxy(30,26);	printf("Save"); y=1;
        }
        x=getch();
    }while(x!=13);
    if(y==1)
    {
        fprintf(fw,"\n%d %s %s %d %s %s %s %c %s %s",
        hosp.id,hosp.dt,hosp.refer,hosp.age,hosp.addr,hosp.cas,
        hosp.dsp,hosp.gender,hosp.name,hosp.room);
    }
    fclose(fw);
}
void readfile()
{
    int i=0,indexOfSpacial=0,indexOfRoom=0,num=0,enter=0,space = 0,inrow=0;
    char ch;
    fr=fopen("Specialists.txt","r");
    if(!fr)
    {
        puts("Create an file with the name of \"Specialists.txt\"");
        AddMenu();
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	gotoxy(70,7);puts("Specialists");
	gotoxy(90,7);puts("Room#");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    y = 7;
    while(!feof(fr))
    {
        ch = fgetc(fr);
        if(!(space == 0 && ch == ' '))
        {
            if(enter)
            {
                if(isChar(ch)&&num==0)
                {
                    gotoxy(x,y);
                    spacial[indexOfSpacial][i]=ch;
                    printf("%c",spacial[indexOfSpacial][i]);
                    i++;
                }
                else
                {
                    if(ch=='=')
                    {
                        x=90;	spacial[indexOfSpacial][i-1]=NULL;
                        i=0;	num=1;
                    }
                    else if(isInt(ch) && num)
                    {
                        gotoxy(x,y);
                        printf("%c",ch);
                        room[indexOfRoom][inrow][i]=ch;
                        i++;
                    }
                }
                if((ch == ' ' || ch == 10) && num==1)
                {
                    i++;
                    room[indexOfRoom][inrow][i]=NULL;
                    i=0; inrow++; space=0;  x++;
                }
                else if(ch == ' ' || ch == '=')
                {
                     space = 0;
                }
                else space = 1;
            }
        }
        if(ch == '#')
        {
            enter = 1;  x = 70;	y+=2;  num=0;	space = 0;
        }
        else if(ch == 10 && enter == 1)
        {
            enter=0;	space = 0;  num=1;	inrow=0;
            x=70;	indexOfSpacial++;	i=0; indexOfRoom++;
        }
        else if(space == 1)
            x++;
    }
    fclose(fr);
}
int chos(int x,int y)
{
    int i=6;
    char chk;
        do
        {
            gotoxy(x,y);
            printf("%3d",i);
            chk = getch();

                if(chk==72)
                    i++;
                if(chk==down)
                    i--;
                if(i<5||i>150)
                    i=6;

        }while(chk!=13);
        return i;
}
int isChar(char ch)
{
	if( (ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z') || ch=='.' || ch=='_' || ch==' ')
		return 1;
	return 0;
}
int isInt(char ch)
{
	if(ch>='0' && ch<='9')
		return 1;
	return 0;
}
void refer()
{
    int i=0;
		x=70;y=9;
		char chk;
        do
        {
            gotoxy(x,y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
			printf("%s",spacial[i]);
            chk=getch();
			gotoxy(x,y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("%s",spacial[i]);
            if(chk==down)
			{
                i++;	y+=2;
			}
            else if(chk==up)
			{
                i--;	y-=2;
			}
            if(i<0||i>9)
			{
                i=0;	y=9;
			}
        }while(chk!=13);
        SpaceOut(spacial[i]);
		strcpy(hosp.refer,spacial[i]);
		x = i;
	}
void room_no()
{
    int i = x, inrow=0;
		x=90;y=9+i*2;
		char chk;
        do
        {
            gotoxy(x,y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),139);
			printf("%s",room[i][inrow]);
            chk=getch();
			gotoxy(x,y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			printf("%s",room[i][inrow]);
            if(chk==down)
			{
                i++;	y+=2;
			}
            else if(chk==up)
			{
                i--;	y-=2;
			}
            else if(chk==left)
			{
                inrow--;	x-=4;
			}
            else if(chk==right)
			{
                inrow++;	x+=4;
			}
            if(i<0||i>20)
			{
                i=0;	y=9;
			}
        }while(chk!=13);
		strcpy(hosp.room,room[i][inrow]);
	}
void SpaceOut(char *str)
{
    for(int index=0; str[index]!='\0'; index++)
    {
        if(str[index]==32)
        {
            str[index]='_';
        }
    }
}
void SpaceIn(char *str)
{
    for(int index=0; str[index]!='\0'; index++)
    {
        if(str[index]=='_')
        {
            str[index]=' ';
        }
    }
}

