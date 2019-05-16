#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<dir.h>
#include<self.h>
char* GetWord(void);
FILE *fp,*freport,*fac;
struct account
{
    char username[20];
    int pass;
}ac;
int main()
{
while(1)
{
    char name[30];
    int pass;
    start:
        system("cls");
    printf("\n (C)reate an account: ");
    printf("\n (L)ogIn: ");
    printf("\n (E)xit: ");
    gotoxy(20,20);printf("First Character of String");
    fflush(stdin);
    switch(getch())
    {
    case 'c':system("cls");
        fac = fopen("user.txt","a+b");
        while(fread(&ac,sizeof(ac),1,fac))
        {
            printf("\t%s\n",ac.username);
        }
        printf("\nEnter You name ");
        scanf("%s",&ac.username);
        printf("\nPassword ");
        scanf("%d",&ac.pass);
        fwrite(&ac,sizeof(ac),1,fac);
        fclose(fac);
        break;
    case 'l':system("cls");
        fac = fopen("user.txt","rb");
        printf("\nEnter You name ");
        scanf("%s",&name);
        printf("\nPassword ");
        scanf("%d",&pass);
        while(fread(&ac,sizeof(ac),1,fac))
        {
            if(ac.pass==pass && strcmp(ac.username,name)==0)
            {
                system("cls");
                fprint();
                start(ac.username);
                break;
            }
        }
        fclose(fac);
        break;
    case 'e':system("cls");
        exit(0);
        break;
    default:
        system("cls");
        Sleep(200);
        gotoxy(30,20);
        printf("Invalid Key");
        goto start;
        break;
    }
}
}
fprint()
{
    fp = fopen("data.txt","r");
    while(!feof(fp))
        printf("%c",fgetc(fp));
    printf("\n\n\n");
    fclose(fp);
}
start(char *name)
{
    char ch[20],frep[30];
    time_t t;
    struct tm *today;
    time(&t);
    today=localtime(&t);
    strftime(frep,30,"%B %H.%M.%S-%p",today);
    int i=0;
    strcat(frep," ");
    strcat(frep,name);
    fp = fopen("data.txt","r");
    freport = fopen(frep,"w");
    while(!feof(fp))
    {
        ch[i] = fgetc(fp);
            fprintf(freport,"%c",ch[i]);
        if(ch[i]==' ')
        {
            ch[i]=NULL;
            if(cmp(ch))
            {
                fprintf(freport,"[%s --0] ",ch);
            }
            i=-1;
        }
        i++;
    }
    fclose(fp);
    fclose(freport);
}
int cmp(char *chk)
{
    char input[20];
    int i=0;
    while(input[i-1]!=' ')
    {
        input[i]=getch();
        printf("%c",input[i]);
        if(input[i]!=8)
            i++;
    }
    input[i-1]='\0';
    return strcmp(input,chk);
}
