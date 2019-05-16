#include<stdio.h>
#include<time.h>
#include<self.h>
struct account
{
    char name[20];
    int pin,id,blc;
}cust,cust1;
struct capture
{
    char type[10];
    int account;
    char DateTime[24];
    int amount;
}cap;

FILE *fp,*fp2,*fcap;

main()
{
    while(1)
    {
        welcome();
        getch();
        system("cls");
        intro();
    }
}
welcome()
{
    system("cls");gotoxy(30,10);
    printf("Welcome on Punjab Bank!!! \n");
}
int menu()
{
    system("cls");
    printf("\n <1>--Mini Statement");
    printf("\n <2>--withdraw cash");
    printf("\n <3>--Pin change");
    printf("\n <4>--To fund transfer");
    printf("\n\n\t <0> To Exit");
    printf("\n\t\t Your Choice::  ");
    return getch();
}
intro()
{
    fp = fopen("db.dat","rb+");
    int id,pin;
    printf("Account# ");
    scanf("%d",&id);
    rewind(fp);
    while(fread(&cust,sizeof(cust),1,fp))
    {
        if(id==cust.id)
        {
            printf(" Welcome!!! %s",cust.name);
            printf("\n PIN# ");
            scanf("%d",&pin);
            if(cust.pin==pin)
            {
                session(cust,fp);
            }
        }
    }
    fclose(fp);
}
session(struct account cust,FILE *fp)
{
    int blc=0,rec=NULL;
    start:
        switch(menu())
        {
        case '1':system("cls");
            fcap = fopen("cap","a+b");
            while(fread(&cap,sizeof(cap),1,fcap))
            {
                if(cust.id==cap.account)
                {
                    printf("\n%d\t",cap.account);
                    printf("%s\t",cap.type);
                    printf("%s\t",cap.DateTime);
                    printf("%d\t",cap.amount);
                }
            }
            fclose(fcap);
            getch();
            break;
        case '2':system("cls");
            fcap = fopen("cap","rb+");
            printf("Amount for Cash:: ");
            scanf("%d",&blc);
            if(blc<20000)
            {
                if(blc<=cust.blc)
                {
                    time_t t = time(NULL);
                    struct tm *tm = localtime(&t);
                    fflush(stdin);strcpy(cap.DateTime , asctime(tm));
                    getch();
                    cust.blc = cust.blc-blc;
                    cap.account = cust.id;
                    fflush(stdin);strcpy(cap.type,"Withdraw");
                    cap.amount = blc;
                    fseek(fp,-sizeof(cust),SEEK_CUR);
                    fwrite(&cust,sizeof(cust),1,fp);
                    fwrite(&cap,sizeof(cap),1,fcap);

                }
            }
            fclose(fp);
            fclose(fcap);
            break;
        case '3':
            printf("Insert NEW!!! PIN:: ");
            scanf("%d",&blc);
            cust.pin = blc;
            fseek(fp,-sizeof(cust),SEEK_CUR);
            fwrite(&cust,sizeof(cust),1,fp);
            break;
        case '4':
            fcap = fopen("cap","ab+");
            printf("Amount for Transfer:: ");
            scanf("%d",&blc);
            if(blc<9999999)
            {
                if(blc<=cust.blc)
                {
                    time_t t = time(NULL);
                    struct tm *tm = localtime(&t);
                    fflush(stdin);strcpy(cap.DateTime , asctime(tm));
                    printf("Receiver Account:: ");
                    scanf("%d",&rec);
                    transf(rec,blc);
                    cust.blc = cust.blc-blc;
                    cap.account = cust.id;
                    cap.amount = blc;
                    fflush(stdin);strcpy(cap.type,"Transfer");
                    fseek(fp,-sizeof(cust),SEEK_CUR);
                    fwrite(&cust,sizeof(cust),1,fp);
                    fwrite(&cap,sizeof(cap),1,fcap);
                }
            }
            fclose(fp);
            fclose(fcap);
            break;
        case '0':
            exit(0);
            break;
        default:
            goto start;
            break;
        }
        fclose(fp);
}
transf(int rec,int blc)
{
    fp2 = fopen("db.dat","rb+");
    while(fread(&cust1,sizeof(cust1),1,fp2))
    {
        if(rec==cust1.id)
        {
            cust1.blc += blc;
            fseek(fp2,-sizeof(cust1),SEEK_CUR);
            fwrite(&cust1,sizeof(cust1),1,fp2);
            break;
        }
    }
    fclose(fp2);
}
