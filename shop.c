#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
COORD coord={0,0};
void eleccart(int pcode,int pq);
void fashioncart(int pcode,int pq);
void signin();
long int sum;
int i=1;
int code;
char u_name[15];
char u_pass[8];
char filename[20];
FILE *fp1,*fp2,*fp3,*fp4;
typedef struct
{
    int pro_code;
    char pro_name[30];
    int pro_rate;
}pro_list;
pro_list pro1,pro2;
void add();
typedef struct
{
    char user_name[15];
    char name[30];
    long long int phone;
    char address[100];
    char user_pass[8];
} user;
user userr, userw,dread;
FILE *fpr, *fpw;
struct cart_list
{
    char product[50];
    int rate;
    int quantity;
    int total;
}data,data1;
void gotoxy (int , int);
void sign_up();
void customer();
void afteradd(int code, int q,int item);
void home();
void administrate();
void user_login();
void electronics();
void fashion();
void cartw();
void details();
void payment();
void bill();
void main()
{
    sum=0;
    system("color b5");
    home();
    getch();
}
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 void home()
 {
     system("cls");
     int i,o;
     i=0;
     char admin[]=("password");
     char ad_pass[20],c=' ';
     printf("\n\n\n\n\n");
     printf("\n\t\t\t\t*                               WELCOME                                      *");
     printf("\n\t\t\t\t*                                                                            *");
     printf("\n\t\t\t\t*                   1. Administrator                                         *");
     printf("\n\t\t\t\t*                   2. User                                                  *");
     printf("\n\t\t\t\t*                                                                            *");
     printf("\n\t\t\t\t* ENTER CHOICE");
     scanf("%d",&o);
     switch(o)
     {
     case 1:
        gotoxy(1,33);
        printf("\tUser Name                     :  Admin\n");
        printf("\tPassword ( 8 characters  )   :  ");
        while (i<=8)
        {
            ad_pass[i]=getch();
            c=ad_pass[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        ad_pass[i]='\0';
        i=0;
        if(strcmp(ad_pass,admin)==0)
        {
            printf("\nCorrect Password...");
            printf("\nPress any key to continue...");
            getch();
            administrate();
        }
        else
        {
            printf("\nWrong Password...");
            printf("\nPress any key to try again...");
            getch();
            home();
        }
        break;
     case 2:
        gotoxy(1,33);
        user_login();
        break;
     default:
        gotoxy(1,33);
        printf("Wrong Input!!!");
        printf("\nPress any Key to try again...");
        getch();
        home();
        break;
     }
 }
 void administrate()
 {
    system("cls");
    int cat_ch,choice3;
    int c;
    printf("\nSelect Category.....");
    printf("\n1. electronics");
    printf("\n2. fashion");
    printf("\n3. EXIT");
    gotoxy(90,35);
    printf("   Choose Your Option:  ");
    scanf("%d",&cat_ch);
    switch (cat_ch)
    {
        case 1:
            go13:printf("\n\t1.Add Product");
            printf("\n\t2.Display Product");
            printf("\nYour Choice  :  ");
            scanf("%d",&choice3);
            switch(choice3)
            {
            case 1:
                fp1=fopen("electronics.bin","a");
                add();
                fwrite(&pro1,sizeof(pro1),1,fp1);
                fclose(fp1);
                break;
            case 2:
                fp1=fopen("electronics.bin","r");
                system("cls");
                printf("\n\tProduct Code\tProduct Name\t\tRate");
                while(fread(&pro2,sizeof(pro2),1,fp1))
                {
                    printf("\n\t%d\t%s\t%d",pro2.pro_code,pro2.pro_name,pro2.pro_rate);
                }
                fclose(fp1);
                break;
            default:
                printf("\nWrong Input!!!\n\tPress any Key to try again...");
                getch();
                goto go13;
                break;
            }
            getch();
            break;
        case 2:
            go5:printf("\n\t1.Add Product");
            printf("\n\t2.Display Product");
            printf("\nYour Choice  :  ");
            scanf("%d",&choice3);
            switch(choice3)
            {
            case 1:
                fp4=fopen("fashion.bin","a");
                add();
                fwrite(&pro1,sizeof(pro1),1,fp4);
                fclose(fp4);
                break;
            case 2:
                fp4=fopen("fashion.bin","r");
                system("cls");
                printf("\n\tProduct Code\tProduct Name\t\tRate");
                while(fread(&pro2,sizeof(pro2),1,fp4))
                {
                    printf("\n\t%d\t%s\t%d",pro2.pro_code,pro2.pro_name,pro2.pro_rate);
                }
                fclose(fp4);
                break;
            default:
                printf("\nWrong Input!!!\n\tPress any Key to try again...");
                getch();
                goto go5;
                break;
            }
            getch();
            break;
        case 3:
            getch();
            exit(0);
            break;
        default:
            printf("\a");
            printf("\n\t\t!!! Wrong input !!!\n\t\tPress any key to Continue...");
            getch();
            administrate();
            break;
    }
    printf("\nDo you want to Continue?\n1. Yes\n2. No");
    scanf("%d",&c);
    if(c==1)
    {
        administrate();
    }
    else
    {
        exit(0);
    }
    getch();
 }
 void add()
    {
        system("cls");
        int con;
        go11:printf("\n\n\tProduct code (2 Digit) :  ");
        scanf("%d",&pro1.pro_code);
        if(pro1.pro_code<100&&pro1.pro_code>999)
        {
            printf("\tInvalid!!!");
            goto go11;
        }
        printf("\n\n\tProduct Name  :  ");
        scanf("%s",pro1.pro_name);
        printf("\n\n\tProduct Rate  :  ");
        scanf("%d",&pro1.pro_rate);
        printf("\nYou Want to add :\t%d\t%s\t%d",pro1.pro_code,pro1.pro_name,pro1.pro_rate);
        printf("\n1.Continue                     2.Edit                       3.exit");
        printf("\n\nYour Choice  :  ");
        scanf("%d",&con);
        switch(con)
        {
        case 1:
            printf("\nItem added to list");
            break;
        case 2:
            add();
            break;
        case 3:exit(0);
            break;
        default:
            printf("\nWrong Input!!!");
            printf("\n\tPress any key to try again...");
            getch();
            add();
            break;
        }
    }
 void user_login()
 {
     system("cls");
     int si_ch;
     printf("\n\n\n\n\n");
     printf("\n\t\t\t\t******************************************************************************");
     printf("\n\t\t\t\t*                               CHOOSE ANY OPTION                            *");
     printf("\n\t\t\t\t*                                                                            *");
     printf("\n\t\t\t\t*                   1. NEW USER                                              *");
     printf("\n\t\t\t\t*                   2. EXISTING USER                                         *");
     printf("\n\t\t\t\t*                                                                            *");
     printf("\n\t\t\t\t*   ENTER CHOICE                                                             *");
     printf("\n\t\t\t\t******************************************************************************");
     gotoxy(48,21);
     scanf("%d",&si_ch);
     switch(si_ch)
     {
     case 1:
        sign_up();
        break;
     case 2:
        signin();
        break;
     default:
        gotoxy(1,33);
        printf("Wrong Input!!!");
        printf("\nPress any Key to try again...");
        getch();
        user_login();
        break;
     }
 }
 void signin()
 {
     system("cls");
     FILE *fpud;
     int i,check=0;
     i=0;
     char c=' ';
     char match[8];
     gotoxy(1,10);
        fpud=fopen("user_details.bin","r");
        printf("\tUser Name                     :  ");
        scanf("%s",u_name);
        while(fread(&userr,sizeof(userr),1,fpud))
        {
            if(strcmp(u_name,userr.user_name)==0)
            {
                printf("\nUser Name Found...");
                strcpy(match,userr.user_pass);
                printf("\nPress any key to continue...");
                check=0;
                getch();
                break;
            }
            else
            {
                check=1;
            }
        }
        if(check==1)
        {
            printf("\nUser Name NOT Found...");
            printf("\nPress any key to try again...");
            getch();
            fclose(fpud);
            user_login();
        }
        printf("\n\tPassword ( 8 characters  )   :  ");
        while (i<=7)
        {
            u_pass[i]=getch();
            c=u_pass[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        u_pass[i]='\0';
        i=0;
        if(strcmp(u_pass,match)==0)
        {
            check=0;
            printf("\nCorrect Password...");
            printf("\nPress any key to Start Shopping...");
            getch();
        }
        else
        {
            check=1;
        }
        if(check==0)
        {
            sprintf(filename,"cart%s.bin",u_name);
            customer();
        }
        if(check==1)
        {
            printf("\nWrong Password...");
            printf("\nPress any key to try again...");
            getch();
            user_login();
        }
 }
 void sign_up()
 {
     system("cls");
    FILE *fpmu,*fpsv;
    user userm,u_save;
    int i;
    i=0;
    char c;
    char temp[15],pass[8],fix[10];
    printf("\n\n");
    fpmu=fopen("user_details.bin","r");
    go3: printf("User Name ( max. 15 chars, No Space ) : ");
    scanf("%s",temp);
    while(fread(&userm, sizeof(userm),1,fpmu))
    {
        if(strcmp(temp,userm.user_name)==0)
        {
            printf("Already Exists!!!\n");
            goto go3;
        }
    }
    fclose(fpmu);
    fpsv = fopen("user_details.bin","a");
    strcpy(u_save.user_name,temp);
    printf("\tUser Name accepted\n");
    printf("\tPassword ( 8 characters  )   :  ");
    while (i<=7)
    {
        pass[i]=getch();
        c=pass[i];
        if(c==13)
            break;
        else
            printf("*");
        i++;
    }
    pass[i]='\0';
    i=0;
    strcpy(u_save.user_pass,pass);
    printf("\n\tName                    :  ");
    scanf("%s",u_save.name);
    go7:printf("\n\tMobile (10 Digit)          :  +91-");
    scanf("%lli",&u_save.phone);
    if(u_save.phone<1000000000||u_save.phone>9999999999)
    {
        printf("\tInvalid!!!");
        goto go7;
    }
    gets(fix);
    printf("\n\tAddress                        :  ");
    gets(u_save.address);
    fwrite(&u_save,sizeof(u_save),1,fpsv);
    fclose(fpsv);
    printf("\nPress any key to Sign In...");
    getch();
    user_login();
 }
 void eleccart(int pcode, int pq)
{
FILE *fpro;
fpro=fopen("electronics.bin","r");
while(fread(&pro2,sizeof(pro2),1,fpro))
{
    strcpy(data.product,pro2.pro_name);
    data.rate=pro2.pro_rate;
}
fclose(fpro);
    data.quantity=pq;
    data.total=data.rate*data.quantity;
sum=sum+data.total;
i++;
fwrite(&data,sizeof(data),1,fpw);
fclose(fpw);
}
 void fashioncart(int pcode, int pq)
{
FILE *fpro;
fpro=fopen("fashion.bin","r");
while(fread(&pro2,sizeof(pro2),1,fpro))
{
    strcpy(data.product,pro2.pro_name);
    data.rate=pro2.pro_rate;
}
    data.quantity=pq;
    data.total=data.rate*data.quantity;
sum=sum+data.total;
i++;
fwrite(&data,sizeof(data),1,fpw);
fclose(fpw);
}
void bill()
{    int ch2;
    fpr=fopen(filename,"r");
    system("cls");
    int j;
    j=1;
    printf("\n\n\t\tSr. No.\tProduct Name\t\tQuantity\t\tRate\t\tTotal\n");
    printf("\t\t*******************************************************************************************************");
    while(fread(&data1,sizeof(data1),1,fpr)>0)
    {
                  printf("\n\t\t%d\t%s\t\t%d\t\t%d\t\t%d\n",j,data1.product,data1.quantity,data1.rate,data1.total);
                  j++;
    }
    fclose(fpr);
    printf("\t\t*******************************************************************************************************");
    printf("\n\n\n\t\t\t\t\t\t Net Amount = %li",sum);
    printf("\n\n1. Proceed to Login & Payment\t\t2. Continue Shopping\t \t Choose OPTION :  ");
    scanf("%d",&ch2);
    switch(ch2)
    {
    case 2:
        customer();
        break;
    case 1:
        details();
        break;
    default:
        printf("\nWrong Input!!!\nPress any key to continue....");
        getch();
        bill();
        break;
    }
    getch();
}
void cartview()
{
    int ch2;
    long int sum1;
    sum1=0;
    fpr=fopen(filename,"r");
    system("cls");
    int j;
    j=1;
    printf("\n\n\t\tSr. No.\tProduct Name\t\tQuantity\t\tRate\t\tTotal\n");
    printf("\t\t*******************************************************************************************************");
    while(fread(&data1,sizeof(data1),1,fpr)>0)
    {
                  printf("\n\t\t%d\t%s\t\t%d\t\t%d\t\t%d\n",j,data1.product,data1.quantity,data1.rate,data1.total);
                  j++;
                  sum1=sum1+data1.total;
    }
    fclose(fpr);
    printf("\t\t*******************************************************************************************************");
    printf("\n\n\n\t\t\t\t\t\t Net Amount = %li",sum1);
    printf("\n\n1. HOME\t\t2. EXIT\t \t Choose OPTION :  ");
    scanf("%d",&ch2);
    switch(ch2)
    {
    case 2:
        customer();
        break;
    case 1:
        break;
    default:
        printf("\nWrong Input!!!\nPress any key to continue....");
        getch();
        cartview();
        break;
    }
    getch();
}
void details()
{
    system("cls");
    FILE *detail;
    detail=fopen("user_details.bin","r");
    while(fread(&dread, sizeof(dread),1,detail))
    {
        if(strcmp(u_name,dread.user_name)==0)
            break;
    }
    int choice;

    printf("\n\t********************************************************************************************************************************\n");
    printf("\n\t                                                      YOUR    DETAILS                                                             ");
    printf("\n\t********************************************************************************************************************************\n");
    printf("\n\tPersonal Details:");
    printf("\n\t\t     First Name                    :   "); printf("%s",dread.name);
    printf("\n\t\t     Contact Number                :   +91-"); printf("%lli",dread.phone);
    printf("\n\tAddress:");
    printf("\n\t\t     Address                       :   "); printf("%s",dread.address);
    printf("\n\t********************************************************************************************************************************\n");
    printf("\n\n\t1. PAYMENT               ||                2. Home               ||                3. MY CART             ||              4. Exit");
    printf("\n\n\t Choose OPTION :   ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("\n Order Received and Invoice sent to your registered Email\n Pay on Delivery\nPress any key to exit");
        getch();
        break;
    case 2:
        customer();
        break;
    case 3:
        bill();
        break;
    case 4:
        break;
    default:
       printf("\a");
        printf("\n\t\t!!! Wrong input !!!\n\t\tPress any key to Continue...");
        getch();
        details();
        break;
    }
}
void afteradd ( int code, int q,int item)
{
    int chcart,callch;
    printf("\a");
    printf("\n\tItem added to CART.                 1. GO TO CART                 2. CONTINUE SHOPPING            ");
    printf("Your Choice :  ");
    scanf("%d",&chcart);
    callch=item;
    switch(callch)
    {
    case 1:
        if (chcart==1)
    {
        fpw=fopen(filename,"a");
        eleccart(code,q);
        bill();
    }
    else
    {
        fpw=fopen(filename,"a");
        eleccart(code,q);
        customer();
    }
        break;
    case 2:
        if (chcart==1)
    {
        fpw=fopen(filename,"a");
        fashioncart(code,q);
        bill();
    }
    else
    {
        fpw=fopen(filename,"a");
        fashioncart(code,q);
        customer();
    }
        break;
    default:
        printf("\nERROR");
    }
}
void customer()
{
    system("cls");
    int choice1;
    char choice_def;
    printf("\a");
    printf("1. electronics");
    printf("2. fashion");
    printf("3. My Order");
    printf("4. EXIT");
    printf("   Choose Your Option:  ");
    scanf("%d",&choice1);
    switch (choice1)
    {
    case 1:
        electronics();
        break;
    case 2:
        fashion();
        break;
    case 3:
        cartview();
        break;
    case 4:
        exit(0);
        break;
    default:
       printf("\a");
        printf("\n\t\t!!! Wrong input !!!\n\t\tPress any key to Continue...");
        getch();
        customer();
        break;
    }
}
void fashion()
{
    int q;
    int item=4;
    FILE *fps;
    fps=fopen("fashion.bin","r");
    printf("\a");

    printf("\n\nHOME >> fashion\n\n");
    while(fread(&pro1,sizeof(pro1),1,fps))
    {
    printf("\n%d \t %s \t - Price: %d\n",pro1.pro_code,pro1.pro_name,pro1.pro_rate);
    }
    printf("11. Go BACK                ||                 12. Home               ||                 13. MY CART           ||          14. Exit");
    fclose(fps);
    printf("Choose OPTION   or   Enter PRODUCT CODE to proceed:   ");
    scanf("%d",&code);
    switch(code)
    {
    case 11:
        customer();
        break;
    case 12:
        customer();
        break;
    case 14:
        exit(0);
        break;
    case 13:
        bill();
        break;
    case 201:
        printf("\n\tEnter Quantity ");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    case 202:
        printf("\n\tEnter Quantity ");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    case 203:
        printf("\n\tEnter Quantity ");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    case 204:
        printf("\n\tEnter Quantity");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    case 205:
        printf("\n\tEnter Quantity");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    default:
        printf("\a");
        printf("\n\t\t!!! Wrong input !!!\n\t\tPress any key to Continue...");
        getch();
        fashion();
        break;
    }
    getch();
}

void electronics()
{
    int q;
    int item=1;
    FILE *fps;
    fps=fopen("electronics.bin","r");
    system("cls");
    printf("\a");

    printf("\nHOME >> electronics\n");
    printf("\n Have a look...");
    gotoxy(1,22);
    while(fread(&pro1,sizeof(pro1),1,fps))
    {
    printf("\n%d \t %s \t - Price: %d\n",pro1.pro_code,pro1.pro_name,pro1.pro_rate);
    }
    gotoxy(10,35);
    printf("11. Go BACK                ||                 12. Home               ||                 13. MY CART           ||          14. Exit");
    gotoxy(60,37);
    fclose(fps);
    printf("Choose OPTION   or   Enter PRODUCT CODE to proceed:   ");
    scanf("%d",&code);
    switch(code)
    {
    case 11:
        customer();
        break;
    case 12:
        customer();
        break;
    case 14:
        exit(0);
        break;
    case 13:
        bill();
        break;
    case 101:
        printf("\n\tEnter Quantity");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    case 102:
        printf("\n\tEnter Quantity");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    case 103:
        printf("\n\tEnter Quantity");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    case 104:
        printf("\n\tEnter Quantity");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    case 105:
        printf("\n\tEnter Quantity");
        scanf("%d",&q);
        afteradd(code,q,item);
        break;
    default:
        printf("\n\t\t!!! Wrong input !!!\n\t\tPress any key to Continue...");
        getch();
        electronics();
        break;
    }
    getch();
}
