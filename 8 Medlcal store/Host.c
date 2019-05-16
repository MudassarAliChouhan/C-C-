#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<self.h>
#include"child fun.c"
#define up 72
#define down 80
#define right 67
#define left 68

int date(char,int,int);
int main()
{
    while(1)
        menu();
}
menu()
{
    system("cls");
    gotoxy(3,3);    printf("(Suppliers Info");
    gotoxy(30,3);   printf("(Customer Info");
    gotoxy(50,3);   printf("(Medicine");
    gotoxy(3,5);    printf("(Report");
    gotoxy(30,5);   printf("(Bill");
    gotoxy(4,7);    printf("About");
    gotoxy(20,7);   printf("EXIT");
    gotoxy(2,8);    printf("=========================");
    gotoxy(20,15);  printf("Welcome To Medical Store  ");
    switch(getch())
    {
    case 's':system("cls");
        supplier();
        break;
    case 'c':system("cls");
        customer();
        break;
    case 'm':system("cls");
        medicine();
        break;
    case 'r':system("cls");
        report();
        break;
    case 'b':system("cls");
        bill();
        break;
    case 'a':system("cls");
        printf("We provide Services for some operation. ");
        getch();
        break;
    case 'e':system("cls");
        exit(0);
        break;
    default:
        gotoxy(20,20);  Sleep(111);
        puts("Press First Character. ");
        break;
    }
    fflush(stdin);
}

void addmedi()
{
        fp = fopen("Medicine.dat","ab");
        tmp = fopen("Supplier.dat","rb");
        fp1 = fopen("Report Purchase.dat","ab");
        gotoxy(20,7);printf("Medicine ID");
        gotoxy(60,8);printf("Name");
        gotoxy(20,9);printf("Company");
        gotoxy(60,10);printf("Supplier");
        gotoxy(20,11);printf("Rack");
        gotoxy(60,12);printf("Cabnit");
        gotoxy(20,13);printf("Price of Unit");
        gotoxy(60,14);printf("Price for Sale");
        gotoxy(20,15);printf("Quantity of Units");
        gotoxy(25,18);printf("DD MM YYYY");
        gotoxy(15,19);printf("MFG Date");
        gotoxy(15,20);printf("Exp Date");

        y=7;
        while(fread(&sup,sizeof(sup),1,tmp)==1)
        {
            gotoxy(90,y);printf("%d",sup.id);
            gotoxy(98,y++);printf("%s",sup.name);
        }
        fclose(tmp);

        gotoxy(32,7);scanf("%d",&medi.id);  fflush(stdin);
        rep.id=medi.id;
        gotoxy(65,8);gets(medi.name);
        strcpy(rep.name,medi.name);
        gotoxy(28,9);gets(medi.comp);
        gotoxy(69,10);gets(medi.supname);
        strcpy(rep.pname,medi.supname);
        gotoxy(25,11);scanf("%d",&medi.rack);
        gotoxy(67,12);scanf("%d",&medi.cabnit);
        gotoxy(34,13);scanf("%d",&medi.priceUnit);
        rep.unit = medi.priceUnit;
        medi.priceSale=(medi.priceUnit/10)+medi.priceUnit;
        gotoxy(75,14);printf("%d",medi.priceSale);
        rep.rate=medi.priceSale;
        gotoxy(38,15);scanf("%d",&medi.qty);
        rep.qty=medi.qty;
        gotoxy(60,16);printf("Total :: %d",medi.qty*medi.priceSale);
        medi.mfg.dd=date('d',25,19);
        medi.mfg.mm=date('m',28,19);
        medi.mfg.yy=date('y',31,19);
        medi.exp.dd=date('d',25,20);
        medi.exp.mm=date('m',28,20);
        medi.exp.yy=date('y',31,20);
        time(&t);
        strcpy(medi.cdate,ctime(&t));
        strcpy(rep.cdate,ctime(&t));
        rep.total=medi.qty*medi.priceSale;
        gotoxy(15,20);puts("=====================================================");
        gotoxy(20,21);puts("Do You Want to Save This \"(y/n)\"");
        if(getch()=='y'||getch()=='Y')
        {
            fwrite(&medi,sizeof(medi),1,fp);
            fwrite(&rep,sizeof(rep),1,fp1);
        }
        fclose(fp);
        fclose(fp1);
        fclose(tmp);
}
void salemedi()
{
    int tmp1;
    char name[30];
        fp = fopen("Medicine.dat","rb+");
        tmp = fopen("Customer.dat","rb");
        fp1 = fopen("Report Sale.dat","ab");
        gotoxy(3,7);printf("Medicine ID for Sale :: ");
        scanf("%d",&tmp1);
        rewind(fp);
        while(fread(&medi,sizeof(medi),1,fp))
        {
            if(medi.id==tmp1)
            {
                rep.id = medi.id;
                strcpy(rep.name,medi.name);
                rep.rate = medi.priceSale;
                time(&t);
                strcpy(rep.cdate,ctime(&t));
                gotoxy(20,9);printf("Medicine Name :: %s",medi.name);
                gotoxy(20,11);printf("Price :: %d",medi.priceSale);
                gotoxy(20,13);printf("Stock Quantity :: %d",medi.qty);
                gotoxy(25,15);printf("Customer");
                gotoxy(25,17);printf("Sold Quantity");

                y=7;
                while(fread(&cust,sizeof(cust),1,tmp))
                {
                    gotoxy(90,y);printf("%d",cust.id);
                    gotoxy(98,y++);printf("%s",cust.name);
                }
                fclose(tmp);

                gotoxy(34,15);fflush(stdin);gets(name);
                gotoxy(39,17);scanf("%d",&x);
                strcpy(rep.pname,name);
                medi.qty = (medi.qty - x);
                rep.qty = x;
                rep.unit = medi.priceUnit;
                rep.total = x * rep.rate;
                fseek(fp,-sizeof(medi),SEEK_CUR);
                fwrite(&medi,sizeof(medi),1,fp);
                gotoxy(25,18);printf("Customer Paid Rs. %d",medi.priceSale*x);
                fwrite(&rep,sizeof(rep),1,fp1);
                break;
            }
        }
        fclose(fp);
        fclose(fp1);
        fclose(tmp);
}
void stockmedi()
{
        fp = fopen("Medicine.dat","rb");
        gotoxy(3,7);puts("ID");
        gotoxy(10,7);puts("Medicine Name");
        gotoxy(30,7);puts("QTY");
        gotoxy(38,7);puts("Supplier Name");
        gotoxy(60,7);puts("Exp... Date");
        while(fread(&medi,sizeof(medi),1,fp))
        {
                gotoxy(3,y);printf("%d",medi.id);
                gotoxy(10,y);printf("%s",medi.name);
                gotoxy(30,y);printf("%d",medi.qty);
                gotoxy(38,y);printf("%s",medi.supname);
                gotoxy(60,y++);printf("%2d/%2d/%4d",medi.exp.dd,medi.exp.mm,medi.exp.yy);
        }
        fclose(fp); getch();
}
void searchmedi()
{
    int tmp;
        fp = fopen("Medicine.dat","rb");
        gotoxy(20,7);printf("Medicine ID:: ");
        scanf("%d",&tmp);
        while(fread(&medi,sizeof(medi),1,fp))
        {
            if(medi.id==tmp)
            {
                gotoxy(20,7);printf("Medicine ID :: %d",medi.id);
                gotoxy(60,8);printf("Name :: %s",medi.name);
                gotoxy(20,9);printf("Company :: %s",medi.comp);
                gotoxy(60,10);printf("Supplier :: %s",medi.supname);
                gotoxy(20,11);printf("Rack :: %d",medi.rack);
                gotoxy(60,12);printf("Cabinet :: %d",medi.cabnit);
                gotoxy(20,13);printf("Price of Unit :: %d",medi.priceUnit);
                gotoxy(60,14);printf("Price for Sale :: %d",medi.priceSale);
                gotoxy(20,15);printf("Quantity of Units :: %d",medi.qty);
                gotoxy(60,16);printf("Purchase Date :: %s",medi.cdate);
                gotoxy(15,17);printf("Exp :: %d/%d/%d",medi.exp.dd,medi.exp.mm,medi.exp.yy);
                gotoxy(15,18);printf("MFG :: %d/%d/%d",medi.mfg.dd,medi.mfg.mm,medi.mfg.yy);
                break;
            }
        }
        fclose(fp);
}
void bill()
{

}
int getid()
{
    srand(time(NULL));
    return (rand()%100000);
}
int date(char d,int x,int y)
{
    int i;
    char chk;
    switch(d)
    {
    case 'd':
        i=1;
        do
        {
            gotoxy(x,y);
            printf("%2d",i);
            chk=getch();
            if(chk==up)
                i++;
            if(chk==down)
                i--;
            if(i<1||i>31)
                i=1;
        }while(chk!=13);
        return i;
        break;
    case 'm':
        i=1;
        do
        {
            gotoxy(x,y);
            printf("%2d",i);
            chk=getch();
            if(chk==up)
                i++;
            if(chk==down)
                i--;
            if(i<1||i>12)
                i=1;
        }while(chk!=13);
        return i;
        break;
    case 'y':
        i=2000;
        do
        {
            gotoxy(x,y);
            printf("%4d",i);
            chk=getch();
            if(chk==up)
                i++;
            if(chk==down)
                i--;
            if(i<2000)
                i=2000;
        }while(chk!=13);
        return i;
        break;
    }
}
void title(char *ti)
{
    for(int i=0;ti[i]!='\0';i++)
    {
        gotoxy(40+i,2);printf("-");
        gotoxy(40+i,4);printf("-");
    }
    gotoxy(40,3);puts(ti);
}
