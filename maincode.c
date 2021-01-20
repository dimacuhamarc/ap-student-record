#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

//global variables
FILE *cRec; //file
int caseMenu; //casemenu
struct record
{
    char lastName[20];
    char givenName[20];
    char gender[10]; //student names
    int cNum,g1,g2,g3,g4; //grades

};

void redeClassRecord();
void readClassRecord();

void readClassRecord()
{
    struct record std;
    cRec = fopen("ClassRecord.txt","a+");
}
void main()
{
    // Variables
    int sMenu, mCounter; //menu variable
     //student's name
    while(mCounter=1)
    {
    caseMenu=NULL;
    printf("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
    printf("\t\t _____    _  __   ___    _  _ ___ _  _  _  __ __\n");
    printf("\t\t(_  | | || ||_ |`| |    | ||_| | |_||_)|_|(_ |_ \n");
    printf("\t\t__) | |_||_||__| | |    |_|| | | | ||_)| |__)|__\n\n");
    printf("\t\t-=-=-=-=-=-=-=-=-=- M E N U -=-=-==-=-=-=-=-=-=-\n");
    printf("\t\t|\t1.] Add New Student\t\t\t|\n");
    printf("\t\t|\t2.] Edit Student\t\t\t|\n");
    printf("\t\t|\t3.] Delete Student\t\t\t|\n");
    printf("\t\t|\t4.] Display Student\t\t\t|\n");
    printf("\t\t|\t5.] Display All\t\t\t\t|\n");
    printf("\t\t|\t6.] Exit\t\t\t\t|\n");
    printf("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
    printf("\t\t\tEnter Choice [1/2/3/4/5/6]: ");

    scanf("%d",&sMenu);

        switch(sMenu)
        {
        case 1: addStudent(); break;
        case 2: editStudent(); printf("\t\t\t-=-=-=- Edit Student -=-=-=-\n"); break;
        case 3: deleteStudent();printf("\t\t\t-=-=-=- Delete Student -=-=-=-\n"); break;
        case 4: displayStudent(); break;
        case 5: displayAllStudents(); break;
        case 6: printf("\t\t\tExiting Program..."); int mCounter = 0; exit(0);
        default : system("cls");
        }
    }
    return 0;
}
void deleteStudent()
{
    printf("\nID Number\tLast Name\tFirst Name\tMath\tScience\t\tEnglish\t\tAverage\n");
    printf("-----------------------------------------------------------------------------------------------\n");
}
void addStudent()
{
    system("cls");
    struct record std;

    char tempSurname[20];
    char tempGiven[20];
    char tempGender[10];
    int tempcNum,tg1,tg2,tg3,tg4;

    printf("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
    readClassRecord();
    while(fscanf(cRec,"%d\t%s\t%s\t%s\t\t%d\t%d\t%d\t%d\n",&std.cNum,&std.gender,&std.givenName,&std.lastName,&std.g1,&std.g2,&std.g3,&std.g4)!=EOF){}
    fclose(cRec);


    readClassRecord();
    printf("\t\t       -=-=-=- FILL UP INFORMATION -=-=-=-\n\n");
    printf("\t\t            -=- BASIC INFORMATION -=-\n");
    printf("\n\t\t            Name         : ");
    scanf("%s",&tempGiven);
    printf("\n\t\t            Surname      : ");
    scanf("%s",&tempSurname);
    printf("\n\t\t            Gender M or F: ");
    scanf("%s",&tempGender);
    printf("\n\t\t            -=- QUARTERLY GRADES -=-\n");
    printf("\n\t\t            FIRST        : ");
    scanf("%d",&tg1);
    printf("\n\t\t            SECOND       : ");
    scanf("%d",&tg2);
    printf("\n\t\t            THIRD        : ");
    scanf("%d",&tg3);
    printf("\n\t\t            FOURTH      : ");
    scanf("%d",&tg4);

    tempcNum = std.cNum + 1;

    fprintf(cRec,"%d\t%s\t%s\t%s\t\t%d\t%d\t%d\t%d\n",tempcNum,tempGender,tempGiven,tempSurname,tg1,tg2,tg3,tg4);
    fclose(cRec);
    system("cls");

}
void displayStudent()
{
    struct record std;
    char tempSurname[20];
    do
    {
        system("cls");
        printf("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
        printf("\t\t\t-=-=-=- Display Student -=-=-=-\n");
        readClassRecord();
        printf("\t\t\tEnter Student Surname: ");
        scanf("%s",tempSurname);
        while(fscanf(cRec,"%d\t%s\t%s\t%s\t\t%d\t%d\t%d\t%d\n",&std.cNum,&std.gender,&std.givenName,&std.lastName,&std.g1,&std.g2,&std.g3,&std.g4)!=EOF)
        {
            if(strcmp(std.lastName,tempSurname) == 0)
            {
                printf("\n\t\t\t-=-=-=- INFORMATION -=-=-=-\n");
                printf("\t\tID NUMBER: %d \n", std.cNum);
                printf("\t\tLast Name: %s \n", std.lastName);
                printf("\t\tFirst Name: %s \n", std.givenName);
                printf("\n\t\t\t-=-=-=- GRADES -=-=-=-\n");
                printf("\t\tFirst Quarter: %d \n", std.g1);
                printf("\t\tSecond Quarter: %d \n", std.g2);
                printf("\t\tThird Quarter: %d \n", std.g3);
                printf("\t\tFourth Quarter: %d \n", std.g4);
                break;
            }
            else
            {
                continue;
            }
            break;
        }
        fclose(cRec);



        printf("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
        printf("\t    Press 1 to Exit  -  Press 2 to Search Another Student  :  ");
        switch(caseMenu)
        {
            case 1 : caseMenu = 1;
            case 2 : caseMenu = 0;
            default : scanf("%d",&caseMenu);
        }
    }
    while(caseMenu!=1);
    caseMenu=NULL;
    system("cls");
}
void displayAllStudents()
{
    struct record std;
    system("cls");
    printf("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
    printf("\t\t\t-=-=-=- Student Record -=-=-=-\n");
    readClassRecord();
    while(fscanf(cRec,"%d\t%s\t%s\t%s\t\t%d\t%d\t%d\t%d\n",&std.cNum,&std.gender,&std.givenName,&std.lastName,&std.g1,&std.g2,&std.g3,&std.g4)!=EOF)
    {
        printf("\n\t\t\t-=-=-=- INFORMATION -=-=-=-\n");
        printf("\t\tID NUMBER: %d \n", std.cNum);
        printf("\t\tLast Name: %s \n", std.lastName);
        printf("\t\tFirst Name: %s \n", std.givenName);
        printf("\n\t\t\t-=-=-=- GRADES -=-=-=-\n");
        printf("\t\tFirst Quarter: %d \n", std.g1);
        printf("\t\tSecond Quarter: %d \n", std.g2);
        printf("\t\tThird Quarter: %d \n", std.g3);
        printf("\t\tFourth Quarter: %d \n", std.g4);
    }
    fclose(cRec);
    printf("\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
    printf("\t\tPress 1 to Exit  :  ");
    scanf("%d",&caseMenu);
    while(caseMenu!=1)
    {
        switch(caseMenu)
        {
            case 1 : system("cls"); break;
            default : printf("\t\t\tPress 1 to Exit  :  \n"); scanf("%d",&caseMenu); break;
        }
    }
    caseMenu=NULL;
    system("cls");
    return 0;
}

void editStudent()
{
    FILE *cRec;
    char tempSurname[20];
    struct record std;
    system("cls");

    printf("========================================\n");
    printf("=                 EDIT                 =\n");
    printf("========================================\n\n\n");

    printf("\nEnter ID Number of student to edit: ");
    fflush(stdin);
    gets(tempSurname);

    cRec = fopen("ClassRecord.txt","rb+");
    if(cRec == NULL)
        {
        printf("\nError opening file.");
        exit(1);
        }
    rewind(cRec);
    fflush(stdin);

    while(fscanf(cRec,"%d\t%s\t%s\t%s\t\t%d\t%d\t%d\t%d\n",&std.cNum,&std.gender,&std.givenName,&std.lastName,&std.g1,&std.g2,&std.g3,&std.g4)!=EOF)
    {
        if(strcmp(tempSurname,std.lastName) == 0)
        {
            printf("\t\t       -=-=-=- FILL UP INFORMATION -=-=-=-\n\n");
            printf("\t\t            -=- BASIC INFORMATION -=-\n");
            printf("\n\t\t            NEW Name         : ");
            scanf("%s",&std.givenName);
            fflush(stdin);
            printf("\n\t\t            NEW Surname      : ");
            scanf("%s",&std.lastName);
            printf("\n\t\t            NEW Gender M or F: ");
            scanf("%s",&std.gender);
            printf("\n\t\t            -=- QUARTERLY GRADES -=-\n");
            printf("\n\t\t            NEW FIRST        : ");
            scanf("%d",&std.g1);
            printf("\n\t\t            NEW SECOND       : ");
            scanf("%d",&std.g2);
            printf("\n\t\t            NEW THIRD        : ");
            scanf("%d",&std.g3);
            printf("\n\t\t            NEW FOURTH      : ");
            scanf("%d",&std.g4);
            fseek(cRec,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,cRec);
            break;
        }
    fclose(cRec);
    printf("\n\nPress any key to continue.");
    getch();
    }
}




