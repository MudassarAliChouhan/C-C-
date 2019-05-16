

void SearchRecord();


void SearchRecord()
{
    char id[8], getLine[200], inputID[8];
    char passData[50];

    int i=0 , j=0;
    fp1 = fopen("Record.dat","r");
    fp2 = fopen("Record.dat.temp","w");
    puts("Enter Id ");
    gets(inputID);
    while(!feof(fp1))
    {
        fgets(getLine,200,fp1);
        i = 0;
        while(getLine[i]!=' ')
        {
            id[i]=getLine[i];
            i++;
        }id[i]='\0';
        strcpy(getstr,getLine);
        if( strcmp(inputID,id) == 0 )
        {
            printf("%s",getstr);
            puts("Do you Want to Edit");
            if(getch()=='y')
            {
                i=0; j=0;
                while(1)
                {
                    if(getstr[i]==' ')
                        j++;
                    if(j>2)
                        break;
                    passData[i]=getstr[i];
                    i++;
                }

                gotoxy(x=20,y=7);    puts("Name :");
                gotoxy(x,y+=2);      puts("Address :");
                gotoxy(x,y+=2);      puts("Age :");
                gotoxy(x,y+=2);      puts("Gender.(m/f) :");
                gotoxy(x,y+=2);      puts("Disease Descrp :");
                gotoxy(25,++y);         puts("In Short :");

                fputs(passData,fp2);

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


                fputs(" ",fp2);
                fputs(hosp.refer,fp2);
                fputs(" ",fp2);
                fprintf(fp2,"%d",hosp.age);
                fputs(" ",fp2);
                fputs(hosp.addr,fp2);
                fputs(" ",fp2);
                fputs(hosp.dsp,fp2);
                fputs(" ",fp2);
                fprintf(fp2,"%c",hosp.gender);
                fputs(" ",fp2);
                fputs(hosp.name,fp2);
                fputs(" ",fp2);
                fputs(hosp.room,fp2);
                fputs("\n",fp2);

                continue;
            }
        }
        fputs(getLine,fp2);
    }
    fclose(fp2);
    fclose(fp1);
    remove("Record.dat");
    rename("Record.dat.temp","Record.dat");
}
