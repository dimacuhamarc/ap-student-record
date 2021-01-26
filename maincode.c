#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

FILE *cRec;
FILE *eRec;
FILE *tempRec; //file
int caseMenu; //casemenu

//student object
struct record
{
    //student id number
    char id [25];
    //student names
    char lastName[25];
    char givenName[25];
    char gender[10];
    //grades
    int g1,g2,g3,g4, total;
    float ave;
};

void main()
{
    int sMenu, mCounter;
    while(mCounter=1)
    {
        caseMenu=NULL;
        printf("\t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
        printf("\t\t\t\t\t _  _     _  __    _     _  _  _  _  _  _  _  __ \n");
        printf("\t\t\t\t\t(_  | | || ||_ |\ | |    | ||_| | |_||_)|_|(_ |_ \n");
        printf("\t\t\t\t\t__) | |_||_||__| \| |    |_|| | | | ||_)| |__)|__\n\n");
        printf("\t\t\t\t\t-=-=-=-=-=-=-=-=-=- M E N U -=-=-==-=-=-=-=-=-=-\n");
        printf("\t\t\t\t\t|\t1.] Add New Student\t\t\t|\n");
        printf("\t\t\t\t\t|\t2.] Edit Student\t\t\t|\n");
        printf("\t\t\t\t\t|\t3.] Delete Student\t\t\t|\n");
        printf("\t\t\t\t\t|\t4.] Display Student\t\t\t|\n");
        printf("\t\t\t\t\t|\t5.] Display All Students\t\t|\n");
        printf("\t\t\t\t\t|\t6.] Export Student Data\t\t\t|\n");
        printf("\t\t\t\t\t|\t7.] Exit\t\t\t\t|\n");
        printf("\t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
        printf("\t\t\t\t\t\tEnter Choice [1/2/3/4/5/6/7]: ");

        scanf("%d",&sMenu);

        switch(sMenu)
        {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: deleteStudent(); break;
            case 4: displayStudent(); break;
            case 5: displayAllStudents(); break;
            case 6: exportFile(); break;
            case 7: printf("\t\t\tExiting Program..."); exit(0);
            default : system("cls");
        }
    }
    return 0;
}
void addStudent() //-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-
{
    system("cls");
    struct record std;
    do
    {
        cRec = fopen("ClassRecord.txt","ab+");
        if(cRec == NULL)
        {
            printf("Error opening file");
            exit(1);
        }
        printf("\t\t\t=======================================\n");
        printf("\t\t\t=            ADD A STUDENT            =\n");
        printf("\t\t\t=======================================\n\n\n");
        printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");

        printf("\t\t       -=-=-=- FILL UP INFORMATION -=-=-=-\n\n");
        printf("\t\t            -=- BASIC INFORMATION -=-\n");
        printf("\n\t\t            School ID    : ");
        scanf("%s",&std.id);
        printf("\n\t\t            First Name   : ");
        scanf("%s",&std.givenName);
        printf("\n\t\t            Last Name    : ");
        scanf("%s",&std.lastName);
        printf("\n\t\t            Gender M or F: ");
        scanf("%s",&std.gender);
        printf("\n\t\t            -=- QUARTERLY GRADES -=-\n");
        printf("\n\t\t            FIRST        : ");
        scanf("%d",&std.g1);
        printf("\n\t\t            SECOND       : ");
        scanf("%d",&std.g2);
        printf("\n\t\t            THIRD        : ");
        scanf("%d",&std.g3);
        printf("\n\t\t            FOURTH       : ");
        scanf("%d",&std.g4);
        fwrite(&std,sizeof(std),1,cRec);
        printf("\n\n\t\t\t    ADDED SUCCESSFULLY!");

        printf("\n\n\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-\n");
        printf("\t\t Press 1 to Exit  -  Press 2 to Add Another Student   ");
        switch(caseMenu)
        {
            case 1 : caseMenu = 1;
            case 2 : caseMenu = 0;
            default : printf("  => "); scanf("%d",&caseMenu); printf("\n\n");
        }
        system("cls");
        fclose(cRec);
    }
    while(caseMenu!=1);

    printf("\n\n");
    system("cls");
}
void editStudent() //-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-
{
    FILE *cRec;
    system("cls");
    char schoolId[25];
    struct record std;
    int checker = 0;
    int pick;

    do
    {
        printf("\t\t\t=======================================\n");
        printf("\t\t\t=            EDIT A STUDENT           =\n");
        printf("\t\t\t=======================================\n\n\n");

        printf("\t\t\t  Enter School ID of student to edit: ");
        fflush(stdin);
        printf("\n\t\t\t\t  => ");
        gets(schoolId);

        cRec = fopen("ClassRecord.txt","rb+");
        if(cRec == NULL)
        {
            printf("\n\n");
            printf("Error opening file");
            exit(1);
        }
        rewind(cRec);
        fflush(stdin);

        while(fread(&std,sizeof(std),1,cRec) == 1)
        {
            if(strcmp(schoolId,std.id) == 0)
            {
                checker = 1;
                printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                printf("\t\t          Which one do you want to edit?\n\n");
                printf("\t\t           1]  School ID  : %s\n", std.id);
                printf("\t\t           2]  First Name : %s\n", std.givenName);
                printf("\t\t           3]  Last Name  : %s\n", std.lastName);
                printf("\t\t           4]  Gender     : %s\n", std.gender);
                printf("\t\t           5]  Grade1     : %d\n", std.g1);
                printf("\t\t           6]  Grade2     : %d\n", std.g2);
                printf("\t\t           7]  Grade3     : %d\n", std.g3);
                printf("\t\t           8]  Grade4     : %d\n", std.g4);
                printf("\t\t           9]  Edit All Information\n\n");
                printf("\t\t           10]  Cancel\n\n");
                printf("\t               Enter Choice [1/2/3/4/5/6/7/8/9/10]: ");
                scanf("%d", &pick);
                printf("\n\n");
                fflush(stdin);

                if (pick == 1)
                {
                    printf("\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t          -=-=-=- FILL UP INFORMATION -=-=-=-\n");
                    printf("\t\t               -=- BASIC INFORMATION -=-\n\n");

                    printf("\t\t            Old School ID  : %s\n", std.id);
                    printf("\t\t   Enter Edited School ID  : ");
                    scanf("%s", &std.id);
                    fseek(cRec ,-sizeof(std),SEEK_CUR);
                    fwrite(&std,sizeof(std),1,cRec);
                    printf("\n\n");
                    printf("\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    break;
                }
                else if (pick == 2)
                {
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t          -=-=-=- FILL UP INFORMATION -=-=-=-\n");
                    printf("\t\t               -=- BASIC INFORMATION -=-\n\n");


                    printf("\t\t            Old First Name : %s\n", std.givenName);
                    printf("\t\t      Enter New First Name : ");
                    scanf("%s", &std.givenName);
                    fseek(cRec ,-sizeof(std),SEEK_CUR);
                    fwrite(&std,sizeof(std),1,cRec);
                    printf("\n\n");
                    printf("\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    break;
                }
                else if (pick == 3)
                {
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t          -=-=-=- FILL UP INFORMATION -=-=-=-\n");
                    printf("\t\t               -=- BASIC INFORMATION -=-\n\n");


                    printf("\t\t              Old Last Name : %s\n", std.lastName);
                    printf("\t\t        Enter New Last Name : ");
                    scanf("%s", &std.lastName);
                    fseek(cRec ,-sizeof(std),SEEK_CUR);
                    fwrite(&std,sizeof(std),1,cRec);
                    printf("\n\n");
                    printf("\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                break;
                }
                else if (pick == 4)
                {
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t          -=-=-=- FILL UP INFORMATION -=-=-=-\n");
                    printf("\t\t               -=- BASIC INFORMATION -=-\n\n");

                    printf("\t\t               Old Gender : %s\n", std.gender);
                    printf("\t\t         Enter New Gender : ");
                    scanf("%s", &std.gender);
                    fseek(cRec ,-sizeof(std),SEEK_CUR);
                    fwrite(&std,sizeof(std),1,cRec);
                    printf("\n\n");
                    printf("\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    break;
                }
                else if (pick == 5)
                {
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t          -=-=-=- FILL UP INFORMATION -=-=-=-\n");
                    printf("\n\t\t              -=- QUARTERLY GRADES -=-\n\n");

                    printf("\t\t        Old First Qtr Grade : %d\n", std.g1);
                    printf("\t\t  Enter New First Qtr Grade : ");
                    fflush(stdin);
                    scanf("%d", &std.g1);
                    fseek(cRec ,-sizeof(std),SEEK_CUR);
                    fwrite(&std,sizeof(std),1,cRec);
                    printf("\n\n");
                    printf("\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    break;
                }
                else if (pick == 6)
                {
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t          -=-=-=- FILL UP INFORMATION -=-=-=-\n");
                    printf("\n\t\t              -=- QUARTERLY GRADES -=-\n\n");

                    printf("\t\t        Old Second Qtr Grade : %d\n", std.g2);
                    printf("\t\t  Enter New Second Qtr Grade : ");
                    fflush(stdin);
                    scanf("%d", &std.g2);
                    fseek(cRec ,-sizeof(std),SEEK_CUR);
                    fwrite(&std,sizeof(std),1,cRec);
                    printf("\n\n");
                    printf("\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    break;
                }
                else if (pick == 7)
                {
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t          -=-=-=- FILL UP INFORMATION -=-=-=-\n");
                    printf("\n\t\t              -=- QUARTERLY GRADES -=-\n\n");

                    printf("\t\t        Old Third Qtr Grade : %d\n", std.g3);
                    printf("\t\t  Enter New Third Qtr Grade : ");
                    fflush(stdin);
                    scanf("%d", &std.g3);
                    fseek(cRec ,-sizeof(std),SEEK_CUR);
                    fwrite(&std,sizeof(std),1,cRec);
                    printf("\n\n");
                    printf("\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    break;
                }
                else if (pick == 8)
                {
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t          -=-=-=- FILL UP INFORMATION -=-=-=-\n");
                    printf("\n\t\t              -=- QUARTERLY GRADES -=-\n\n");

                    printf("\t\t       Old Fourth Qtr Grade : %d\n", std.g4);
                    printf("\t\t Enter New Fourth Qtr Grade : ");
                    scanf("%d", &std.g4);
                    fseek(cRec ,-sizeof(std),SEEK_CUR);
                    fwrite(&std,sizeof(std),1,cRec);
                    printf("\n\n");
                    printf("\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    break;
                }
                else if (pick == 9)
                {
                    printf("\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t          -=-=-=- FILL UP INFORMATION -=-=-=-\n");
                    printf("\t\t               -=- BASIC INFORMATION -=-\n\n");

                    printf("\t\t                Enter Edited School ID  : ");
                    scanf("%s", &std.id);
                    printf("\t\t                Enter Edited First Name : ");
                    scanf("%s", &std.givenName);
                    printf("\t\t                Enter Edited Last Name  : ");
                    scanf("%s", &std.lastName);
                    printf("\t\t                Enter Edited Gender     : ");
                    scanf("%s", &std.gender);


                    printf("\n\t\t              -=- QUARTERLY GRADES -=-\n\n");
                    printf("\t\t           Enter Grade in FIRST QUARTER : ");
                    fflush(stdin);
                    scanf("%d", &std.g1);
                    printf("\t\t           Enter Grade in SECOND QUARTER: ");
                    fflush(stdin);
                    scanf("%d", &std.g2);
                    printf("\t\t           Enter Grade in THIRD QUARTER : ");
                    scanf("%d", &std.g3);
                    printf("\t\t           Enter Grade in FOURTH QUARTER: ");
                    scanf("%d", &std.g4);
                    fseek(cRec ,-sizeof(std),SEEK_CUR);
                    fwrite(&std,sizeof(std),1,cRec);
                    printf("\n\n");
                    printf("\t\t        -=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    printf("\t\t    -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-\n");
                    break;
                }
                else if (pick == 10)
                {
                    break;
                }
                else if (pick >= 11 || pick <= 0)
                {
                    printf("\nInvalid\n");
                }
            }
        }

        if (checker != 1)
        {
            printf("\n");
            printf("\t\t\t   School ID '%s' cannot be found\n\n", schoolId);
        }
        else
            {
            printf("\n\n");
            printf("\t\t    Student '%s %s' has been edited successfully!!  \n", std.givenName, std.lastName);
        }
        printf("\t\t Press 1 to Exit  -  Press 2 to Add Another Student   ");
        switch(caseMenu)
        {
            case 1 : caseMenu = 1;
            case 2 : caseMenu = 0;
            default : printf("  => "); scanf("%d",&caseMenu); printf("\n\n");
        }
        system("cls");
    }
    while(caseMenu!=1);
    fclose(cRec);
    system ("cls");
}
void deleteStudent() //-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-
{
    FILE *cRec;
    FILE *tempRec;
    cRec = fopen("ClassRecord.txt","r+");
    struct record std;
    int flag=0;
    char schoolId[25];
    do
    {
        flag=0;
        system("cls");
        printf("\t\t\t=======================================\n");
        printf("\t\t\t=           SEARCH A STUDENT          =\n");
        printf("\t\t\t=======================================\n\n\n");

        printf("\t\t\t      Enter School ID of student: ");
        fflush(stdin);
        printf("\n\t\t\t\t   => ");
        gets(schoolId);

        tempRec = fopen ("TEMP.txt", "w") ;
        rewind (cRec) ;

        while (fread (&std, sizeof(std), 1, cRec) == 1 )
        {
            if (strcmp(std.id, schoolId) != 0 )
            {
                fwrite(&std, sizeof(std), 1, tempRec ) ;
            }
            else
            {
                flag=1;
            }
        }

        fclose (cRec) ;
        fclose (tempRec) ;


        if(flag==1)
        {
            remove ("ClassRecord.txt") ;
            rename ("TEMP.txt", "ClassRecord.txt") ;
            printf("\n");
            printf("\t\t              Successfully Deleted School ID '%s' \n\n", schoolId);
            system("pause");
        }
        else if (flag!=1)
        {
            printf("\n");
            printf("\t\t              School ID '%s' cannot be found\n\n", schoolId);
            system("pause");
        }
        printf("\n\n\t\t         -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\t\t Press 1 to Exit  -  Press 2 to Delete Another Student :  ");

        switch(caseMenu)
        {
            case 1 : caseMenu = 1;
            case 2 : caseMenu = 0;
            default : printf("  => "); scanf("%d",&caseMenu); printf("\n\n");
        }
        system("cls");
    }
    while(caseMenu!=1);
    caseMenu=NULL;
    system("cls");
    printf("\n\n");
}
void displayStudent() //-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-
{
    system("cls");
    struct record std;
    char schoolId[25];
    int checker = 0;

    do
    {
        printf("\t\t\t=======================================\n");
        printf("\t\t\t=           SEARCH A STUDENT          =\n");
        printf("\t\t\t=======================================\n\n\n");

        printf("\t\t\t      Enter School ID of student: ");
        fflush(stdin);
        printf("\n\t\t\t\t   => ");
        gets(schoolId);

        cRec = fopen("ClassRecord.txt","rb+");
        if(cRec == NULL)
        {
            printf("\n\n");
            printf("Error opening file");
            exit(1);
        }

        while(fread(&std,sizeof(std),1,cRec) == 1)
        {
            if(strcmp(schoolId,std.id) == 0)
            {
                checker = 1;
                printf("\t\t\t       -=- BASIC INFORMATION -=-\n");
                printf("\n");
                printf("\t\t\t   • ID Number   : %s\n",std.id);
                printf("\t\t\t   • Last Name   : %s\n",std.lastName);
                printf("\t\t\t   • First Name  : %s\n",std.givenName);

                printf("\n\n\t\t\t       -=- QUARTERLY GRADES -=-\n\n");
                printf("\t\t\t   • 1st Quarter : %d\n",std.g1);
                printf("\t\t\t   • 2nd Quarter : %d\n",std.g2);
                printf("\t\t\t   • 3rd Quarter : %d\n", std.g3);
                printf("\t\t\t   • 4th Quarter : %d\n\n", std.g4);

                printf("\t\t         -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

                std.ave = (std.g1 + std.g2 + std.g3 + std.g4) / 4;
                printf("\t\t\t\tAverage     : %.2f\n", std.ave);
                printf("\t\t\t\tREMARK      : ");

                if(std.ave >= 75 && std.ave <= 100)
                {
                    printf("PASSED");
                }
                else if (std.ave >= 0 && std.ave < 75)
                {
                    printf("FAILED");
                }
                break;
            }
        }
        if (checker !=1)
        {
            printf("\n");
            printf("\t\t              School ID '%s' cannot be found\n\n", schoolId);
        }

        fclose(cRec);
        printf("\n\n\t\t         -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\t\t Press 1 to Exit  -  Press 2 to View Another Student :  ");

        switch(caseMenu)
        {
            case 1 : caseMenu = 1;
            case 2 : caseMenu = 0;
            default : printf("  => "); scanf("%d",&caseMenu); printf("\n\n");
        }
        system("cls");
    }
    while(caseMenu!=1);
    caseMenu=NULL;
    system("cls");
    printf("\n\n");
}
void displayAllStudents() //-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-
{
    FILE *cRec;
    struct record std;
    int i;
    system("cls");

    printf("\t\t\t\t\t\t=======================================\n");
    printf("\t\t\t\t\t\t=            LIST OF STUDENTS         =\n");
    printf("\t\t\t\t\t\t=======================================\n\n\n");
    printf("\t\tSchool ID\tSurname\t\tName\t\tGender\t\tGr1\tGr2\tGr3\tGr4\tGWA\n");
    printf("\t\t-------------------------------------------------------------------------------------------------------\n");

    cRec = fopen("ClassRecord.txt","rb+");
    if(cRec == NULL)
    {
        printf("\nError opening file.");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,cRec) == 1)
    {
        std.ave = (std.g1 + std.g2 + std.g3 + std.g4) / 4;
        printf("\t\t%s\t%s\t\t%s\t\t%s\t\t%d\t%d\t%d\t%d\t%.2f\n",std.id,std.lastName,std.givenName, std.gender, std.g1, std.g2, std.g3, std.g4, std.ave);
        i++;
        std.total = i;
    }
    printf("\t\t-------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\tTotal Number of Students: %d", std.total);
    fclose(cRec);

    printf("\t\t\tPress 1 to Exit  :  ");
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
void exportFile() //-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-6
{
    system("cls");
    FILE *cRec;
    FILE *eRec;
    struct record std;
    int i;
    system("cls");
    eRec = fopen("ExportedRecord.txt","w+");
    cRec = fopen("ClassRecord.txt","rb+");

    fprintf(eRec,"\t\t\t\t\t\t=======================================\n");
    fprintf(eRec,"\t\t\t\t\t\t=      EXPORTED LIST OF STUDENTS      =\n");
    fprintf(eRec,"\t\t\t\t\t\t=======================================\n\n\n");
    fprintf(eRec,"\t\tSchool ID | Surname,Name | Gender | Gr1 | Gr2 | Gr3 | Gr4 | GWA\n");
    fprintf(eRec,"\t\t-------------------------------------------------------------------------------------------------------\n");


    while(fread(&std,sizeof(std),1,cRec) == 1)
    {
        std.ave = (std.g1 + std.g2 + std.g3 + std.g4) / 4;
        fprintf(eRec,"\t\t%s | %s,%s  | %s  | %d | %d | %d | %d | %.2f \n",std.id,std.lastName,std.givenName, std.gender, std.g1, std.g2, std.g3, std.g4, std.ave);
        i++;
        std.total = i;
    }
    fprintf(eRec,"\t\t-------------------------------------------------------------------------------------------------------\n");
    fprintf(eRec,"\n\t\tTotal Number of Student/s: %d", std.total);
    fclose(cRec);
    fclose(eRec);
    printf("\t\t\t\t\t\t=======================================\n");
    printf("\t\t\t\t\t\t=        SUCESSFULLY EXPORTED         =\n");
    printf("\t\t\t\t\t\t=======================================\n\n\n");
    printf("\t\t\t\t\t\tPress Any Key to Continue...\n");
    getche();
    system("cls");
}

