
DeleteRecord()
{
    int i=0; char id[5],getid[5];
    title(" Deleting Record of Patient's ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    fr = fopen("Record.dat","r");
    fw = fopen("Record.dat.tmp","w");

    gotoxy(20,10);puts("Enter ID of Patient: ");
    gotoxy(43,10);gets(&getid);

    while(!feof(fr))
    {
        i=0;
        fgets(getstr,sizeof(hosp),fr);
        while(getstr[i]!=' ')
        {
            id[i]=getstr[i];
            i++;
        }
        id[i]='\0';
        if(strcmp(id,getid)!=0)
        {
            fputs(getstr,fw);
        }
        else
        {
            printf("Data will Deleted Successfully!!! ");
        }
    }

    fclose(fr);
    fclose(fw);

    getch();

    remove("Record.dat");
    rename("Record.dat.tmp","Record.dat");
}
