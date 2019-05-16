#include<self.h>
#include<stdio.h>
#include<conio.h>

struct account
{
    char name[20];
    int pin,id,blc;
};

 FILE *fp;

int main(int select)
{

 fp=fopen("db.dat","ab+");
    struct account acc;
    switch(select)
    {
    case 1:
        display(acc);
        break;
    case 2:
        create(acc);
        break;
    default:
        return 0;
    }
}

void create(struct account acc)
{
    fp=fopen("db.dat","r    b+");
    int id=10092,pin=856;
    if(!fp)
    {
        printf("File Can't Created");
        Sleep(200);
        exit(0);
    }
    while(fread(&acc,sizeof(acc),1,fp))
    {
        id++;pin++;
    }
    printf("\n Customer Name: ");
    gets(acc.name);
    printf("\n Balance: ");
    scanf("%d",&acc.blc);
    acc.pin=pin;
    acc.id=id;
    fwrite(&acc,sizeof(acc),1,fp);
    fclose(fp);

    printf("\n\t Account has been Opened!!!");
    printf("\n \t %s",acc.name);
        printf("\n Balance = %d",acc.blc);
        printf("\n Acc no: = %d",acc.id);
        printf("\n PIN     = %d",acc.pin);
}
void display(struct account acc)
{
    fp=fopen("db.dat","rb+");
    if(!fp)
    {
        printf("File Can't Found!!!");
        Sleep(2000);
        exit(0);
    }
    while(fread(&acc,sizeof(acc),1,fp)==1)
    {
        printf("\n \t %s",acc.name);
        printf("\n Balance = %d",acc.blc);
        printf("\n Acc no: = %d",acc.id);
        printf("\n Acc no: = %d",acc.pin);
        printf("\n======================");
    }
    fclose(fp);
}
getno(int n)
{

}
