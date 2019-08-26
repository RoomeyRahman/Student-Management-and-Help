//Name: Md. Ataur Rahman Bhuiyan
//Id: 2014-1-60-101
//Project Name: Student database systme
//Course: CSE107
//Instructor: Mohammad Kamrul Islam (MKI)
//Section: 02



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int showmenu();
void registration();
void login();
int loginmenu();
int registrationmenu();
void help();
int gosystem();
int menu();
void advisor();
void profile();
void edit();
void advisor_login();
void course();
void result();
void time_sheudule();
void evaluation();
void time();

struct student
{
    int id;
    char name[50];
    char uname[30];
    char pass[25];
    char contact[20];
    char email[20];
    char fname[50];
    char mname[50];
    char gname[50];
    char dpt[10];
    int sem;
    char gcontact[20];
};


int main()
{
    struct student info[100];
    int choice,flag,fcall;

    choice=showmenu();

    switch(choice)
        {
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            flag=0;
            break;
        default:
            printf("warning:: give input according to the menu\n");
        }

    return 0;
}

int showmenu()
{
    int choice;

    printf("|-------------------------------------------------------------------|\n");
    printf("|                    welcome to East West University                |\n");
    printf("|                                                                   |\n");
    printf("|1. Register                                                        |\n");
    printf("|2. Login                                                           |\n");
    printf("|3. Exit                                                            |\n");
    printf("|                                                                   |\n");
    printf("|                                                                   |\n");
    printf("|-------------------------------------------------------------------|\n");

    scanf("%d",&choice);
    fflush(stdin);

    system("cls");

    return choice;
}


void registration()
{
    struct student d;
    int n=0;


    printf("Student's Information: \n");
    printf("Name: \n");
    gets(d.name);
    fflush(stdin);

    printf("ID: \n");
    scanf("%d",&d.id);
    fflush(stdin);

    printf("Semister: \n");
    scanf("%d",&d.sem);
    fflush(stdin);

    printf("Department: \n");
    scanf("%s",d.dpt);
    fflush(stdin);

    printf("Contact Number: \n");
    scanf("%s",d.contact);
    fflush(stdin);

    printf("Email: \n");
    gets(d.email);
    fflush(stdin);

    printf("\nFamily Information \n\n");

    printf("Father's name: \n");
    gets(d.fname);
    fflush(stdin);

    printf("Mother's name: \n");
    gets(d.mname);
    fflush(stdin);

    printf("Gurdian's name: \n");
    gets(d.gname);
    fflush(stdin);

    printf("Contact Number: \n");
    gets(d.gcontact);
    fflush(stdin);

    printf("\nUser Name: \n");
    gets(d.uname);
    fflush(stdin);

    printf("Give a password: \n");
    scanf("%s",d.pass);
    fflush(stdin);


    FILE *fp;

    fp=fopen("student number.txt","r");

    fscanf(fp,"%d",&n);

    fclose(fp);

    n=n+1;

    fp=fopen("student number.txt","w");

    fprintf(fp,"%d\n",n);

    fclose(fp);

    fp=fopen("registration.txt","a");

    fprintf(fp,"%s\n",d.name);
    fprintf(fp,"%d\n",d.id);
    fprintf(fp,"%d\n",d.sem);
    fprintf(fp,"%s\n",d.dpt);
    fprintf(fp,"%s\n",d.contact);
    fprintf(fp,"%s\n",d.email);
    fprintf(fp,"%s\n",d.fname);
    fprintf(fp,"%s\n",d.mname);
    fprintf(fp,"%s\n",d.gname);
    fprintf(fp,"%s\n",d.gcontact);
    fprintf(fp,"%s\n",d.uname);
    fprintf(fp,"%s\n",d.pass);


    fclose(fp);

    system("cls");


    login();
}

void login()
{
    char uname[25];
    char pass[25];
    struct student x[100];
    int i,n,ucount,pcount,choice;

    printf("Enter your user name: ");
    gets(uname);
    fflush(stdin);
    printf("Enter your password: ");
    scanf("%s",pass);
    fflush(stdin);

    FILE *fp;

    fp=fopen("student number.txt","r");

    fscanf(fp,"%d",&n);

    fclose(fp);

    fp=fopen("registration.txt","r");

    for(i=0;i<n;i++){
        fscanf(fp,"%s",x[i].name);
        fscanf(fp,"%d",&x[i].id);
        fscanf(fp,"%d",&x[i].sem);
        fscanf(fp,"%s",x[i].dpt);
        fscanf(fp,"%s",x[i].contact);
        fscanf(fp,"%s",x[i].email);
        fscanf(fp,"%s",x[i].fname);
        fscanf(fp,"%s",x[i].mname);
        fscanf(fp,"%s",x[i].gname);
        fscanf(fp,"%s",x[i].gcontact);
        fscanf(fp,"%s",x[i].uname);
        fscanf(fp,"%s",x[i].pass);
    }

    fclose(fp);

    ucount=0;
    for(i=0;i<n;i++){
        if(strcmp(uname,x[i].uname)==0){
            ucount++;
            break;
        }
    }

    pcount=0;
    if(strcmp(pass,x[i].pass)==0){
        pcount++;
    }

    fp=fopen("nth student.txt","w");

    fprintf(fp,"%d\n",i);

    fclose(fp);

    printf("\n\n");


    if(ucount>0&&pcount>0){
        system("cls");
        gosystem();
    }
    else if(ucount>0&&pcount<=0){
        printf("Password Mismatch\n");

        choice=loginmenu();
        system("cls");

        switch(choice)
        {
            case 1: login();
                break;
            case 2: exit(0);
                break;
            case 3: help();
                break;
            default: printf("warning:: give input according to the menu\n");
        }
    }
    else if(ucount==0){
        printf("no such user in the record\n");

        choice=registrationmenu();
        system("cls");

        switch(choice)
        {
            case 1: registration();
                break;
            case 2: exit(0);
                break;
            default: printf("warning:: give input according to the menu\n");
        }
    }

}

int loginmenu()
{
    int choice;

    printf("1. Please Type your password properly \n");
    printf("2.Exit\n");
    printf("If you forget your password then press 3\n");

    scanf("%d",&choice);
    fflush(stdin);

    return choice;
}

int registrationmenu()
{
    int choice;

    printf("1. Please registration first \n");
    printf("2.Exit\n");

    scanf("%d",&choice);
    fflush(stdin);

    return choice;
}

void help()
{
    struct student x[1000];
    int id,i,j,n;

    printf("Go to your Advisor\n");
    advisor_login();
    system("cls");

    printf("Enter the students ID\n");
    scanf("%d",&id);
    fflush(stdin);

    FILE *fp;

    fp=fopen("nth student.txt","r");
    fscanf(fp,"%d",&j);
    fclose(fp);

    fp=fopen("student number.txt","r");
    fscanf(fp,"%d",&n);
    fclose(fp);

    fp=fopen("registration.txt","r");
    for(i=0;i<n;i++){
        fscanf(fp,"%s",x[i].name);
        fscanf(fp,"%d",&x[i].id);
        fscanf(fp,"%d",&x[i].sem);
        fscanf(fp,"%s",x[i].dpt);
        fscanf(fp,"%s",x[i].contact);
        fscanf(fp,"%s",x[i].email);
        fscanf(fp,"%s",x[i].fname);
        fscanf(fp,"%s",x[i].mname);
        fscanf(fp,"%s",x[i].gname);
        fscanf(fp,"%s",x[i].gcontact);
        fscanf(fp,"%s",x[i].uname);
        fscanf(fp,"%s",x[i].pass);
    }

    fclose(fp);

    if(id==x[j].id){
        printf("Your password is: %s\n",x[j].pass);
    }
    else{
        printf("User is missing\n");
    }
}

int gosystem()
{
    time();

    int choice;

    choice=menu();

    switch(choice){
        case 1: profile();
            break;
        case 2: course();
            break;
        case 3: time_sheudule();
            break;
        case 4: result();
            break;
        case 5: evaluation();
            break;
        case 6: exit(0);
            break;
        default:
            printf("warning:: give input according to the menu\n");
    }
    scanf("%d",&choice);
    fflush(stdin);

    return choice;
}

int menu()
{
    int choice;

    printf("welcome to system:\n\n");

    advisor();

    printf("|*******************************|\n");
    printf("|1.Profile                      |\n");
    printf("|2.Course Plan                  |\n");
    printf("|3.Sheudule                     |\n");
    printf("|4.Result                       |\n");
    printf("|5.Evaluation                   |\n");
    printf("|6.Exit                         |\n");
    printf("|*******************************|\n");

    printf("\n\n");

    scanf("%d",&choice);
    fflush(stdin);

    system("cls");

    return choice;
}

void advisor()
{
    struct student x[100];
    int n,i;

    FILE *fp;

    fp=fopen("student number.txt","r");

    fscanf(fp,"%d",&n);

    fclose(fp);

    fp=fopen("registration.txt","r");

    for(i=0;i<n;i++){
        fscanf(fp,"%s",x[i].name);
        fscanf(fp,"%d",&x[i].id);
        fscanf(fp,"%d",&x[i].sem);
        fscanf(fp,"%s",x[i].dpt);
        fscanf(fp,"%s",x[i].contact);
        fscanf(fp,"%s",x[i].email);
        fscanf(fp,"%s",x[i].fname);
        fscanf(fp,"%s",x[i].mname);
        fscanf(fp,"%s",x[i].gname);
        fscanf(fp,"%s",x[i].gcontact);
        fscanf(fp,"%s",x[i].uname);
        fscanf(fp,"%s",x[i].pass);
    }
    fclose(fp);

    fp=fopen("nth student.txt","r");

    fscanf(fp,"%d",&i);

    fclose(fp);

    if(x[i].id>=1&&x[i].id<=10){
        printf("|********************************************|\n");
        printf("|Advisor Name: Dr. Shamim Hasnat Ripon       |\n");
        printf("|Office: 601                                 |\n");
        printf("|homepage:  http://www.ewubd.edu/~dshr       |\n");
        printf("|********************************************|\n");
        printf("\n\n\n");
    }

    else if(x[i].id>=11&&x[i].id<=20){
        printf("|*************************************************|\n");
        printf("|Advisor Name: Dr. Shaikh Muhammad Allayear       |\n");
        printf("|Office: 602                                      |\n");
        printf("|homepage:   http://ewubd.edu/~allayear           |\n");
        printf("|*************************************************|\n");
        printf("\n\n\n");
    }

    else if(x[i].id>=21&&x[i].id<=30){
        printf("|******************************************|\n");
        printf("|Advisor Name: Dr. Taskeed Jabid           |\n");
        printf("|Office: 603                               |\n");
        printf("|homepage:   http://ewubd.edu/~taskeed     |\n");
        printf("|******************************************|");
        printf("\n\n\n");
    }

    else if(x[i].id>=31&&x[i].id<=40){
        printf("|********************************************|\n");
        printf("|Advisor Name: Mohammad Kamrul Islam         |\n");
        printf("|Office: 604                                 |\n");
        printf("|homepage:   http://ewubd.edu/~kamrultopu    |\n ");
        printf("|********************************************|");
        printf("\n\n\n");
    }

    else if(x[i].id>=41&&x[i].id<=50){
        printf("|*************************************|\n");
        printf("|Advisor Name: Fahmida Azmi           |\n");
        printf("|Office: 605                          |\n");
        printf("|homepage:   http://ewubd.edu/~fazmi  |\n");
        printf("|*************************************|");
        printf("\n\n\n");
    }
}

void profile()
{
    struct student x[1000];
    int student,n,i,choice;

    FILE *fp;

    fp=fopen("student number.txt","r");
    fscanf(fp,"%d",&n);
    fclose(fp);

    fp=fopen("nth student.txt","r");
    fscanf(fp,"%d",&student);
    fclose(fp);

    fp=fopen("registration.txt","r");

    for(i=0;i<n;i++){
        fscanf(fp,"%s",x[i].name);
        fscanf(fp,"%d",&x[i].id);
        fscanf(fp,"%d",&x[i].sem);
        fscanf(fp,"%s",x[i].dpt);
        fscanf(fp,"%s",x[i].contact);
        fscanf(fp,"%s",x[i].email);
        fscanf(fp,"%s",x[i].fname);
        fscanf(fp,"%s",x[i].mname);
        fscanf(fp,"%s",x[i].gname);
        fscanf(fp,"%s",x[i].gcontact);
        fscanf(fp,"%s",x[i].uname);
        fscanf(fp,"%s",x[i].pass);
    }

    fclose(fp);


    printf("Name                      : %s\n",x[student].name);
    printf("ID                        : %d\n",x[student].id);
    printf("Semister                  : %d\n",x[student].sem);
    printf("Department                : %s\n",x[student].dpt);
    printf("Contact Number            : %s\n",x[student].contact);
    printf("Mail                      : %s\n",x[student].email);
    printf("Father's Name             : %s\n",x[student].fname);
    printf("Mother's Name             : %s\n",x[student].mname);
    printf("Guardian's Name           : %s\n",x[student].gname);
    printf("Guardian's Contact Number : %s\n",x[student].gcontact);

    printf("\n\n\n");
    printf("|*************************|\n");
    printf("|1. Edit                  |\n");
    printf("|2. Home                  |\n");
    printf("|3. Log out               |\n");
    printf("|*************************|");

    scanf("%d",&choice);
    fflush(stdin);

    if(choice==1){
        system("cls");
        edit();
    }

    else if(choice==2){
        system("cls");
    }

    switch(choice){
        case 2: gosystem();
            break;
        case 3: exit(0);
            break;
    }

}

void edit()
{
    struct student x[1000];
    int student,n,i,choice;

    FILE *fp;

    fp=fopen("student number.txt","r");
    fscanf(fp,"%d",&n);
    fclose(fp);

    fp=fopen("nth student.txt","r");
    fscanf(fp,"%d",&student);
    fclose(fp);

    fp=fopen("registration.txt","r");

    for(i=0;i<n;i++){
        fscanf(fp,"%s",x[i].name);
        fscanf(fp,"%d",&x[i].id);
        fscanf(fp,"%d",&x[i].sem);
        fscanf(fp,"%s",x[i].dpt);
        fscanf(fp,"%s",x[i].contact);
        fscanf(fp,"%s",x[i].email);
        fscanf(fp,"%s",x[i].fname);
        fscanf(fp,"%s",x[i].mname);
        fscanf(fp,"%s",x[i].gname);
        fscanf(fp,"%s",x[i].gcontact);
        fscanf(fp,"%s",x[i].uname);
        fscanf(fp,"%s",x[i].pass);
    }

    fclose(fp);

    printf("1.  Name                      : %s\n",x[student].name);
    printf("Edit\n");
    printf("2.  ID                        : %d\n",x[student].id);
    printf("Edit\n");
    printf("3.  Semister                  : %d\n",x[student].sem);
    printf("Edit\n");
    printf("4.  Department                : %s\n",x[student].dpt);
    printf("Edit\n");
    printf("5.  Contact Number            : %s\n",x[student].contact);
    printf("Edit\n");
    printf("6.  Mail                      : %s\n",x[student].email);
    printf("Edit\n");
    printf("7.  Father's Name             : %s\n",x[student].fname);
    printf("8.  Mother's Name             : %s\n",x[student].mname);
    printf("9.  Guardian's Name           : %s\n",x[student].gname);
    printf("10. Guardian's Contact Number : %s\n",x[student].gcontact);

    scanf("%d",&choice);
    fflush(stdin);

    switch(choice)
    {
        case 1: printf("Name: \n");
                scanf("%s",x[student].name);
                fflush(stdin);
                break;

        case 2: printf("ID: \n");
                scanf("%d",&x[student].id);
                fflush(stdin);
                break;

        case 3: printf("Semister: \n");
                scanf("%d",&x[student].sem);
                fflush(stdin);
                break;

        case 4: printf("Semister: \n");
                scanf("%s",x[student].dpt);
                fflush(stdin);
                break;

        case 5: printf("Contact Number : \n");
                scanf("%s",x[student].contact);
                fflush(stdin);
                break;

        case 6: printf("Mail: \n");
                scanf("%s",x[student].email);
                fflush(stdin);
                break;
    }

    fp=fopen("registration.txt","w");

    for(i=0;i<n;i++){
        fprintf(fp,"%s\n",x[student].name);
        fprintf(fp,"%d\n",x[student].id);
        fprintf(fp,"%d\n",x[student].sem);
        fprintf(fp,"%s\n",x[student].dpt);
        fprintf(fp,"%s\n",x[student].contact);
        fprintf(fp,"%s\n",x[student].email);
        fprintf(fp,"%s\n",x[student].fname);
        fprintf(fp,"%s\n",x[student].mname);
        fprintf(fp,"%s\n",x[student].gname);
        fprintf(fp,"%s\n",x[student].gcontact);
        fprintf(fp,"%s\n",x[student].uname);
        fprintf(fp,"%s\n",x[student].pass);
    }

    fclose(fp);

    system("cls");

    profile();

}

struct advisor{
    char uname[30];
    char password[20];
};

void advisor_login()
{
    struct advisor x[10];
    char username[25];
    char pass[10];
    int flag,flag1,i;

    printf("Advisor User Name:");
    scanf("%s",username);
    fflush(stdin);

    printf("Password:");
    scanf("%s",pass);
    fflush(stdin);

    for(i=0;i<5;i++){
        strcpy(x[i].uname,"");
        strcpy(x[i].password,"");
    }

    FILE *fp;
    fp=fopen("advisor login.txt","r");

    for(i=0;i<5;i++){
        fscanf(fp,"%s",x[i].uname);
        fscanf(fp,"%s",x[i].password);
    }

    fclose(fp);

    flag=0;
    for(i=0;i<5;i++){
        if(strcmp(username,x[i].uname)==0){
            flag++;
            break;
        }
    }


    flag1=0;
    if(strcmp(pass,x[i].password)==0){
        flag1++;
    }

    printf("\n\n");


    if(flag>0&&flag1>0){
        system("cls");
    }
    else if(flag>0&&flag1<=0){
        printf("Password Mismatch");
    }
    else if(flag==0){
        printf("no such user in the record");
    }
}

void course()
{
    struct student x[1000];
    int student,n,i,choice,option;

    FILE *fp;

    fp=fopen("student number.txt","r");
    fscanf(fp,"%d",&n);
    fclose(fp);

    fp=fopen("nth student.txt","r");
    fscanf(fp,"%d",&student);
    fclose(fp);

    fp=fopen("registration.txt","r");

    for(i=0;i<n;i++){
        fscanf(fp,"%s",x[i].name);
        fscanf(fp,"%d",&x[i].id);
        fscanf(fp,"%d",&x[i].sem);
        fscanf(fp,"%s",x[i].dpt);
        fscanf(fp,"%s",x[i].contact);
        fscanf(fp,"%s",x[i].email);
        fscanf(fp,"%s",x[i].fname);
        fscanf(fp,"%s",x[i].mname);
        fscanf(fp,"%s",x[i].gname);
        fscanf(fp,"%s",x[i].gcontact);
        fscanf(fp,"%s",x[i].uname);
        fscanf(fp,"%s",x[i].pass);
    }

    fclose(fp);

    printf("Your course for this semister\n");

    switch(x[student].sem)
    {
        case 1: printf("1. CSE 105\n");
                printf("2. MAT 101\n");
                printf("3. ENG 101\n");
                break;

        case 2: printf("1. CSE 107\n");
                printf("2. MAT 102\n");
                printf("3. ENG 102\n");
                printf("4. CHE 109\n");
                break;

        case 3: printf("1. CSE 109\n");
                printf("2. MAT 104\n");
                printf("3. PHY 102\n");
                printf("4. STA 102\n");
                break;

        case 4: printf("1. CSE 205\n");
                printf("2. MAT 205\n");
                printf("3. GEN 201\n");
                printf("4. OGEN 1\n");
                break;

        case 5: printf("1. CSE 207\n");
                printf("2. MAT 225\n");
                printf("3. PHY 245\n");
                printf("4. OGEN 2\n");
                break;

        case 6: printf("1. CSE 251\n");
                printf("2. CSE 301\n");
                printf("3. PHY 109\n");
                break;

        case 7:
                printf("1. CSE 325\n");
                printf("2. PHY 109\n");
                printf("3. OBE 1\n");
                break;

        case 8: printf("1. CSE 345\n");
                printf("2. CSE 350\n");
                printf("3. CSE 360\n");
                printf("4. OBE 2\n");
                break;

        case 9: printf("1. CSE 365\n");
                printf("2. CSE 375\n");
                printf("3. OSCI 1\n");
                break;

        case 10: printf("1. CSE 405\n");
                 printf("2. CSE 497\n");
                 printf("3. OSCI 2\n");
                 break;

        case 11: printf("1. CSE 498\n");
                 printf("2. OSCI 3\n");
                 printf("3. OSCI 4\n");
                 break;

        case 12: printf("1. CSE 411\n");
                 printf("2. CSE 442\n");
                 printf("3. CSE 499\n");
                 printf("4. OSCI 5\n");
                 break;
    }

    printf("\n\n");
    printf("|*****************|\n");
    printf("|1. Home          |\n");
    printf("|2. logout        |\n");
    printf("|*****************|\n");
    scanf("%d",&option);
    fflush(stdin);

    if(option==1){
        system("cls");
        gosystem();
    }
    else if(option==2){
        exit(0);
    }
    else{
        system("cls");
        printf("Please input correctly\n");
        course();
    }
}


struct time_sheudule
{
    char course[100];
    int sec;
    char instructor[25];
    int room;
    char time[20];
    char slot[10];
};

void time_sheudule()
{
    struct time_sheudule t[100];
    int section,i,j,option;
    char course[100];

    printf("Enter your course: ");
    scanf("%s",course);
    fflush(stdin);

    printf("Enter your section: ");
    scanf("%d",&section);
    fflush(stdin);

    FILE *fp;

    fp=fopen("index.txt","r");

    for(i=0;i<14;i++)
    {
        fscanf(fp,"%s",t[i].course);
        fscanf(fp,"%d",&t[i].sec);
        fscanf(fp,"%s",t[i].instructor);
        fscanf(fp,"%d",&t[i].room);
        fscanf(fp,"%s",t[i].time);
        fscanf(fp,"%s",t[i].slot);
    }

    fclose(fp);

    for(i=0;i<14;i++){
        if(strcmp(course,t[i].course)==0&&section==t[i].sec){
            j=i;
            break;
        }
    }

    printf("\n\n\n");
    printf("Your course is %s\n",t[j].course);
    printf("Your section is %d\n",t[j].sec);
    printf("Your course instructor is %s\n",t[j].instructor);
    printf("Room number is %d\n",t[j].room);
    printf("Time is %s\n",t[j].time);
    printf("Slot is %s\n",t[j].slot);
    printf("\n\n\n");

    printf("|*****************|\n");
    printf("|1. Home          |\n");
    printf("|2. logout        |\n");
    printf("|*****************|\n");

    scanf("%d",&option);
    fflush(stdin);

    system("cls");

    switch(option)
    {
    case 1: gosystem();
            break;
    case 2: exit(0);
            break;
    }

}

void result()
{
    int course,i,sum1,sum,ans,credit,option;
    float cgpa,grade;
    char cname[50];

    printf("Enter how many courses you have done this semister:");
    scanf("%d",&course);
    fflush(stdin);

    sum=0;
    sum1=0;

    for(i=1;i<=course;i++)
    {
        printf("\n\nEnter the name of your %dth course :",i);
        scanf("%s",cname);
        fflush(stdin);

        printf("Enter your grade of %dth course : " ,i);
        scanf("%f",&grade);
        fflush(stdin);

        printf("Enter the credit of this course : ");
        scanf("%d",&credit);
        fflush(stdin);

        printf("\n\n\n");


        ans=credit*grade;
        sum1=sum1+ans;
        sum=sum+credit;
    }
    cgpa= (float)sum1/sum;

    printf("\n\n");
    printf("Your CGPA is = %f",cgpa);
    printf("\n\n");

    printf("|*****************|\n");
    printf("|1. Home          |\n");
    printf("|2. logout        |\n");
    printf("|*****************|\n");

    scanf("%d",&option);
    fflush(stdin);

    system("cls");

    switch(option)
    {
    case 1: gosystem();
            break;
    case 2: exit(0);
            break;
    }
}

void evaluation()
{
    struct time_sheudule t[100];
    struct student x[1000];
    int section,i,j,option,position,n;
    char course[100];
    int a,b,c,d;

    printf("Enter your course: ");
    scanf("%s",course);
    fflush(stdin);

    printf("Enter your section: ");
    scanf("%d",&section);
    fflush(stdin);

    FILE *fp;

    fp=fopen("index.txt","r");

    for(i=0;i<14;i++)
    {
        fscanf(fp,"%s",t[i].course);
        fscanf(fp,"%d",&t[i].sec);
        fscanf(fp,"%s",t[i].instructor);
        fscanf(fp,"%d",&t[i].room);
        fscanf(fp,"%s",t[i].time);
        fscanf(fp,"%s",t[i].slot);
    }

    fclose(fp);

    fp=fopen("student number.txt","r");

    fscanf(fp,"%d",&n);

    fclose(fp);

    fp=fopen("registration.txt","r");

    for(i=0;i<n;i++){
        fscanf(fp,"%s",x[i].name);
        fscanf(fp,"%d",&x[i].id);
        fscanf(fp,"%d",&x[i].sem);
        fscanf(fp,"%s",x[i].dpt);
        fscanf(fp,"%s",x[i].contact);
        fscanf(fp,"%s",x[i].email);
        fscanf(fp,"%s",x[i].fname);
        fscanf(fp,"%s",x[i].mname);
        fscanf(fp,"%s",x[i].gname);
        fscanf(fp,"%s",x[i].gcontact);
        fscanf(fp,"%s",x[i].uname);
        fscanf(fp,"%s",x[i].pass);
    }

    fclose(fp);

    fp=fopen("nth student.txt","r");

    fscanf(fp,"%d",&position);

    fclose(fp);


    for(i=0;i<14;i++){
        if(strcmp(course,t[i].course)==0&&section==t[i].sec){
            j=i;
            break;
        }
    }

    printf("\n\n\n");
    printf("Your Instructor is %s\n",t[j].instructor);
    printf("\n\n\n");

    fp=fopen("evaluation.txt","a");

    fprintf(fp,"Evaluation for %s by ID no %d student\n\n",t[j].instructor,x[position].id);

    printf("How does he approach?\n\n");
    printf("1.Good\n");
    printf("2.Better\n");
    printf("3.Best\n");

    fprintf(fp,"How does he approach?\n");

    scanf("%d",&a);
    fflush(stdin);

    if(a==1){
        fprintf(fp,"Good\n");
    }
    else if(a==2){
        fprintf(fp,"Better\n");
    }
    else{
        fprintf(fp,"best\n");
    }

    printf("Spoken English?\n");
    printf("1.Good\n");
    printf("2.Better\n");
    printf("3.Best\n");

    fprintf(fp,"Spoken English?\n");

    scanf("%d",&a);
    fflush(stdin);

    if(a==1){
        fprintf(fp,"Good\n");
    }
    else if(a==2){
        fprintf(fp,"Better\n");
    }
    else{
        fprintf(fp,"best\n");
    }

    printf("Marks distribution?\n");
    printf("1.Good\n");
    printf("2.Better\n");
    printf("3.Best\n");

    fprintf(fp,"Marks distribution?\n");

    scanf("%d",&b);
    fflush(stdin);

    if(b==1){
        fprintf(fp,"Good\n");
    }
    else if(b==2){
        fprintf(fp,"Better\n");
    }
    else{
        fprintf(fp,"best\n");
    }

    printf("Outline programme?\n");
    printf("1.Good\n");
    printf("2.Better\n");
    printf("3.Best\n");

    fprintf(fp,"Outline programme?\n");

    scanf("%d",&c);
    fflush(stdin);

    if(c==1){
        fprintf(fp,"Good\n");
    }
    else if(c==2){
        fprintf(fp,"Better\n");
    }
    else{
        fprintf(fp,"best\n");
    }
    fclose(fp);

    printf("\n\n");

    printf("|*****************|\n");
    printf("|1. Home          |\n");
    printf("|2. logout        |\n");
    printf("|*****************|\n");

    scanf("%d",&option);
    fflush(stdin);

    system("cls");

    switch(option)
    {
    case 1: gosystem();
            break;
    case 2: exit(0);
            break;
    }
}

void time()
{
    time_t ts;
    struct tm *current;
    int a, b, c;

    time(&ts);
    current=localtime(&ts);

    a=current->tm_mday;
    b=current->tm_mon+1;
    c=current->tm_year+1900;

    printf("                            Date: %d  %d  %d\n", a, b, c);
    printf("\n\n");
}



