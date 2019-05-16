struct date
{
    int dd,mm,yy;
};
struct SupCust
{
    char phn[13],name[25];
    int id;
    char city[20],email[30];
}sup,cust;
struct Medicine
{
    int     id;
    char    name[25];
    int     rack,cabnit;
    char    cdate[24];
    struct  date    mfg,exp;
    int     qty,priceUnit,priceSale;
    char    comp[20],supname[25];

}medi;
struct report
{
    int     id;
    char    name[25],pname[25];
    int     qty,rate,total;
    char    cdate[26];
    int     unit;
}rep;

int x,y;
    time_t t;
    FILE *fp,*fp1,*tmp;

void supplier()
{
    char ch[30];
    supplier:   system("cls");
    fp=fopen("Supplier.dat","ab+");
    title("Supplier");
    gotoxy(x=20,y=8);printf("Insert New Supplier");
    gotoxy(x,y+=3);printf("Edit Supplier");
    gotoxy(x,y+=3);printf("Search Supplier");
    gotoxy(x,y+=3);printf("List of Existing Supplier's");
    gotoxy(x,y+=3);printf("Main Menu ");
    switch(getch())
    {
    case 'i':system("cls");
        title("Insert Supplier");
        gotoxy(20,5);printf("Supplier ID %d",sup.id=getid());
        gotoxy(50,5);printf("Name");
        gotoxy(20,8);printf("City");
        gotoxy(50,8);printf("E-mail ");
        gotoxy(20,11);printf("Contact~#");
        gotoxy(55,5);gets(sup.name);
        gotoxy(25,8);gets(sup.city);
        gotoxy(58,8);gets(sup.email);
        gotoxy(30,11);gets(sup.phn);
        gotoxy(15,13);puts("==============================================================");
        gotoxy(20,15);puts("Do You Want to Save This \" (y/n) \"");
        if(getch()=='y'||getch()=='Y')
            fwrite(&sup,sizeof(sup),1,fp);
        fclose(fp);
        break;
    case 'e':system("cls");
        title("Edit Supplier");
        int id;
        puts("ID for Find");
        scanf("%d",&id);
        while(fread(&sup,sizeof(sup),1,fp))
        {
            if(id==sup.id)
            {
                gotoxy(3,25);printf("%d",sup.id);
                gotoxy(12,25);printf("%s",sup.name);
                gotoxy(30,25);printf("%s",sup.city);
                gotoxy(50,25);printf("%s",sup.email);
                gotoxy(80,25);printf("%s",sup.phn);
                gotoxy(20,5);printf("Supplier ID %d",sup.id);
                gotoxy(50,5);printf("Name");
                gotoxy(20,8);printf("City");
                gotoxy(50,8);printf("E-mail ");
                gotoxy(20,11);printf("Contact~#");
                fflush(stdin);
                gotoxy(55,5);gets(sup.name);
                gotoxy(25,8);gets(sup.city);
                gotoxy(58,8);gets(sup.email);
                gotoxy(30,11);gets(sup.phn);
                gotoxy(15,13);puts("==============================================================");
                gotoxy(20,15);puts("Do You Want to Save This \"(y/n)\"");
                fseek(fp,-sizeof(sup),SEEK_CUR);
                if(getch()=='y'||getch()=='Y')
                    fwrite(&sup,sizeof(sup),1,fp);
                break;
            }
        }
        fclose(fp);
        break;
    case 's':system("cls");
        break;
    case 'l':system("cls");
        y=3;
        gotoxy(3,1);puts("ID");
        gotoxy(12,1);puts("NAME");
        gotoxy(30,1);puts("CITY");
        gotoxy(50,1);puts("E-MAIL");
        gotoxy(80,1);puts("CONTECT");
        while(fread(&sup,sizeof(sup),1,fp)==1)
        {
            gotoxy(3,y);printf("%d",sup.id);
            gotoxy(12,y);printf("%s",sup.name);
            gotoxy(30,y);printf("%s",sup.city);
            gotoxy(50,y);printf("%s",sup.email);
            gotoxy(80,y++);printf("%s",sup.phn);
        }
        fclose(fp);
        getch();
        break;
    case 'm':menu();break;
    default:
        gotoxy(20,20);
        puts("Press First Character. ");
        Sleep(300);
        break;
    }
    fflush(stdin);    goto supplier;
}
void customer()
{
    char ch[30];
    Customer:   system("cls");
    fp=fopen("Customer.dat","ab+");
    title(" Customer ");
    gotoxy(x=20,y=8);printf("Insert New Customer");
    gotoxy(x,y+=3);printf("Edit Customer");
    gotoxy(x,y+=3);printf("Search Customer");
    gotoxy(x,y+=3);printf("List of Existing Customer's");
    gotoxy(x,y+=3);printf("Main Menu ");
    switch(getch())
    {
    case 'i':system("cls");
        gotoxy(20,5);printf("Customer ID %d",cust.id=getid());
        gotoxy(50,5);printf("Name");
        gotoxy(20,8);printf("City");
        gotoxy(50,8);printf("E-mail ");
        gotoxy(20,11);printf("Contact~#");
        gotoxy(55,5);gets(cust.name);
        gotoxy(25,8);gets(cust.city);
        gotoxy(58,8);gets(cust.email);
        gotoxy(30,11);gets(cust.phn);
        gotoxy(15,13);puts("==============================================================");
        gotoxy(20,15);puts("Do You Want to Save This \" (y/n) \"");
        if(getch()=='y'||getch()=='Y')
            fwrite(&cust,sizeof(cust),1,fp);
        fclose(fp);
        break;
    case 'e':system("cls");
        int id;
        puts("ID for Find");
        scanf("%d",&id);
        while(fread(&cust,sizeof(cust),1,fp))
        {
            if(id==cust.id)
            {
                gotoxy(3,25);printf("%d",cust.id);
                gotoxy(12,25);printf("%s",cust.name);
                gotoxy(30,25);printf("%s",cust.city);
                gotoxy(50,25);printf("%s",cust.email);
                gotoxy(80,25);printf("%s",cust.phn);
                gotoxy(20,5);printf("Customer ID %d",cust.id);
                gotoxy(50,5);printf("Name");
                gotoxy(20,8);printf("City");
                gotoxy(50,8);printf("E-mail ");
                gotoxy(20,11);printf("Contact~#");
                fflush(stdin);
                gotoxy(55,5);gets(cust.name);
                gotoxy(25,8);gets(cust.city);
                gotoxy(58,8);gets(cust.email);
                gotoxy(30,11);gets(cust.phn);
                gotoxy(15,13);puts("==============================================================");
                gotoxy(20,15);puts("Do You Want to Save This \"(y/n)\"");
                fseek(fp,-sizeof(cust),SEEK_CUR);
                if(getch()=='y'||getch()=='Y')
                    fwrite(&cust,sizeof(cust),1,fp);
                break;
            }
        }
        fclose(fp);
        break;
    case 's':system("cls");
        break;
    case 'l':system("cls");
    y=3;
        gotoxy(3,1);puts("ID");
        gotoxy(12,1);puts("NAME");
        gotoxy(30,1);puts("CITY");
        gotoxy(50,1);puts("E-MAIL");
        gotoxy(80,1);puts("CONTECT");
        while(fread(&cust,sizeof(cust),1,fp)==1)
        {
            gotoxy(3,y);printf("%d",cust.id);
            gotoxy(12,y);printf("%s",cust.name);
            gotoxy(30,y);printf("%s",cust.city);
            gotoxy(50,y);printf("%s",cust.email);
            gotoxy(80,y++);printf("%s",cust.phn);
        }
        fclose(fp);
        getch();
        break;
    case 'm':menu();break;
    default:
        gotoxy(20,20);
        puts("Press First Character. ");
        Sleep(300);
        break;
    }
    fflush(stdin);    goto Customer;
}
void medicine()
{
    title(" Medicine Menu ");
    Medicine: system("cls");
    gotoxy(x=20,y=8);   puts("Purchase New Medicine");
    gotoxy(x,y+=3);     puts("Sale of Medicine");
    gotoxy(x,y+=3);     puts("List of Stock Medicine");
    gotoxy(x,y+=3);     puts("Find Particular Medicine");
    gotoxy(x,y+=3);     puts("Main Menu");
    switch(getch())
    {
    case 'p':system("cls");
        title(" Purchasing Medicine");
        addmedi(fp);
        break;
    case 's':system("cls");
        title(" Sold of Medicine ");
        salemedi();
        getch();
        break;
    case 'l':system("cls"); y=9;
        title(" Stock of Medicine's ");
        stockmedi();
        break;
    case 'f':system("cls");
        title(" Search Medicine");
        searchmedi();
        getch();
        break;
    case 'm':menu();break;
    default:
        gotoxy(20,20);
        puts("Press First Character. ");
        Sleep(300);
        break;
    }
    fflush(stdin);    goto Medicine;
}
void report()
{
    Report:   system("cls");
    title(" Reporting ");
    gotoxy(x=20,y=8);printf("Purchase Report");
    gotoxy(x,y+=3);printf("Sale Report");
    gotoxy(x,y+=3);printf("Report of Profit");
    // gotoxy(x,y+=3);printf("Regard of Sold Report");

    gotoxy(x,y+=3);printf("Main Menu ");
    switch(getch())
    {
    case 'p':system("cls"); y=9;
        fp1 = fopen("Report Purchase.dat","rb");
        title(" Purchase Report ");
        gotoxy(3,7);puts("ID");
        gotoxy(10,7);puts("Medicine Name");
        gotoxy(30,7);puts("Supplier Name");
        gotoxy(50,7);puts("QTY");
        gotoxy(55,7);puts("Rate");
        gotoxy(70,7);puts("Total");
        gotoxy(80,7);puts("Date");
        while(fread(&rep,sizeof(rep),1,fp1))
        {
                gotoxy(3,y);printf("%d",rep.id);
                gotoxy(10,y);printf("%s",rep.name);
                gotoxy(30,y);printf("%s",rep.pname);
                gotoxy(50,y);printf("%d",rep.qty);
                gotoxy(55,y);printf("%d",rep.rate);
                gotoxy(70,y);printf("%d",rep.total);
                gotoxy(80,y++);printf("%s",rep.cdate);
        }
        fclose(fp1);
        getch();
        break;
    case 's':system("cls"); y=9;
        fp1 = fopen("Report Sale.dat","rb");
        title(" Sold Report ");
        gotoxy(3,7);puts("ID");
        gotoxy(10,7);puts("Medicine Name");
        gotoxy(30,7);puts("Customer Name");
        gotoxy(50,7);puts("QTY");
        gotoxy(55,7);puts("Rate");
        gotoxy(70,7);puts("Total");
        gotoxy(80,7);puts("Date");
        while(fread(&rep,sizeof(rep),1,fp1))
        {
                gotoxy(3,y);printf("%d",rep.id);
                gotoxy(10,y);printf("%s",rep.name);
                gotoxy(30,y);printf("%s",rep.pname);
                gotoxy(50,y);printf("%d",rep.qty);
                gotoxy(55,y);printf("%d",rep.rate);
                gotoxy(70,y);printf("%d",rep.total);
                gotoxy(80,y++);printf("%s",rep.cdate);
        }
        fclose(fp1);
        getch();
        break;
    case 'r':system("cls"); y=9;
        fp1 = fopen("Report Sale.dat","rb");
        gotoxy(3,7);puts("ID");
        gotoxy(10,7);puts("Medicine Name");
        gotoxy(30,7);puts("QTY");
        gotoxy(39,7);puts("Sale");
        gotoxy(49,7);puts("Purchase");
        gotoxy(60,7);puts("Profit");
        while(fread(&rep,sizeof(rep),1,fp1))
        {
                gotoxy(3,y);printf("%d",rep.id);
                gotoxy(10,y);printf("%s",rep.name);
                gotoxy(30,y);printf("%d",rep.qty);
                gotoxy(39,y);printf("%d",rep.rate);
                gotoxy(49,y);printf("%d",rep.unit);
                gotoxy(60,y++);printf("%d",rep.total-(rep.unit*rep.qty));
        }
        fclose(fp1);
        getch();
        break;
    case 'm':menu();break;
    default:
        gotoxy(20,20);
        puts("Press First Character. ");
        Sleep(300);
        break;
    }
    fflush(stdin);    goto Report;
}
