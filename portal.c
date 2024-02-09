#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
struct client
{
    char name[50];
    char dob[12];
    char address[50];
    char  sex [8];
    int age;
    char NIN[12];
    char phone [20];
    double  bal;
    char type[10];
    char branch[15];
    char accnum[15];
    char  dop[12];
} create, seek;


void end();
void menu();
void add_record();
void account_check();

void rmspace(char *word)
{
    word[strcspn(word, "\n")] = '\0';
}

void end()
{
    system("clear");
            printf("\nEXITING PORTAL");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                sleep(1);
            }
            system("clear");
            exit(0);
}
void menu()
{                          
    int choice;
    printf("\t\tWELCOME TO OLU BANK\n\t\t MAIN MENU PORTAL\n" );
    printf("\n1. CREATE NEW ACCOUNT\n2. CHECK EXISTING ACCOUNT\n3. TRANSACTION\n4. UPDATE ACCOUNT\n5. EXIT PORTAL\n\n");
again: 
        printf("SELECT AN OPTION: ");
        scanf("%d", &choice);
    
        switch (choice)
        {
            case 1:
            system("clear");
                add_record();
            break;
            case 2:
               // account_check();
            //break;
            case 3:
                //transact();
            //break;
            case 4:
                //update();
            //break;

            case 5:
                end();
            default:
                printf("\nENTER A VALID OPTION\n");
                goto again;
    }
}

void add_record()
{
    int option;
    FILE *ptr;
    printf("\t\tCUSTOMER APPLICATION FORM\n");
    getchar();

    printf("\n1. NAMES: ");
    fgets(create.name, sizeof(create.name), stdin);
    rmspace(create.name);

    printf("2. ADDRESS: ");
    fgets(create.address, sizeof(create.address), stdin);
    rmspace(create.address);

    printf("3. SEX: ");
    fgets(create.sex, sizeof(create.sex), stdin);
    rmspace(create.sex);

    printf("4. AGE: ");
    scanf(" %d", &create.age);
    getchar();

    printf("5. NIN: ");
    fgets(create.NIN, sizeof(create.NIN), stdin);
    rmspace(create.NIN);

    printf("6. PHONE NUMBER: ");
    fgets(create.phone, sizeof(create.phone), stdin);
    rmspace(create.phone);

    printf("7. D.O.B (DD/MM/YYYY): ");
    fgets(create.dob, sizeof(create.dob), stdin);
    rmspace(create.dob);

    printf("8. ACCOUNT NUMBER: ");
    fgets(create.accnum, 15, stdin);

    printf("9. OPENING BALANCE: ₦");
    scanf(" %lf", &create.bal);
    getchar();

    printf("10. DATE OF OPENING(DD/MM/YYYY): ");
    fgets(create.dop, sizeof(create.dop), stdin);
    rmspace(create.dop);

    printf("11. TYPE OF ACCOUNT(SAVINGS/CURRENT/FIXED): ");
    fgets(create.type, sizeof(create.type), stdin);
    rmspace(create.type);

    printf("12. BRANCH: ");
    fgets(create.branch, sizeof(create.branch), stdin);
    rmspace(create.branch);
    
    ptr = fopen("Clientlist", "a");
    if(ptr==NULL)
    {
        printf("\nERROR OPENING FILE\n");
        exit(1);
    }
    fprintf(ptr,"Name: %s\nAddress: %s\nSex: %s\nAge: %d\nNIN: %s\nPhone No: %s\nD.O.B: %s\nAccount number: %s\nBalance: ₦%.2lf\nOpening date: %s\nAccount type: %s\nBranch: %s\n\n---------------------------------------------\n", create.name, create.address, create.sex, create.age, create.NIN, create.phone, create.dob, create.accnum, create.bal, create.dop, create.type, create.branch);

    fclose(ptr);
    system("clear");
    printf("\n\n ACCOUNT SUCCESSFULLY CREATED!!!\n");
    
    while(1)
    {
        printf("\n\n PRESS 1 TO GO TO MAIN MENU OR PRESS 0 TO EXIT: ");
        scanf("%d", &option);
        if(option==1)
        {
            system("clear");
            menu();
        }
        else if (option == 0)
        {
            end();
        }
        else
        {
            system("clear");
            printf("\nINVALID!!! TRY AGAIN:");
        }
    }
        
}

int main()
{
    int run = 3;
    char password[20];

    while (run > 0)
    {
        system("clear");
        printf("\n\nENTER PORTAL PASSWORD: ");
        printf("\033[8m");
        scanf("%s", password);
        printf("\033[0m");

        if (strcmp("Bank1234", password) != 0)
        {
            run--;
            system("clear");
            {
                printf("\033[0m");
                printf("\n\nPASSWORD INCORRECT..\n%d ATTEMPTS LEFT", run);
            }
            if(run==0)
            {
                printf("\033[0m");
                printf("\n\n: PORTAL CLOSED\n\n");
            }
        }
        else
        {
            printf("\033[0m");
            system("clear");
            printf("\n\nLOGIN SUCCESSFUL!!!\n\nPORTAL OPENING");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                sleep(2);
            }

            system("clear");
            menu();
        }
    }
    return 0;
}
