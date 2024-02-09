
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
    int accnum;
    char  dop[12];
} create, seek;


void account_check()
{
    FILE *ptr;
    ptr= fopen("Clientlist", "r");
    if(ptr == NULL)
    {
        printf("\nFilE DOES NOT EXIST\n");
        exit(1);
    }
    system("clear");

    printf("ENTER ACCOUNT NUNBER: ");
    scanf(" %d", &seek.accnum);

    while(fscanf(ptr, "Name: %s Address: %s Sex: %s Age: %d NIN: %s Phone No: %s D.O.B: %s Account number: %d Balance: ₦%lf Opening date: %s Account type: %s Branch: %s", seek.name, seek.address, seek.sex, &seek.age, seek.NIN, seek.phone, seek.dob, &seek.accnum, &seek.bal, seek.dop, seek.type, seek.branch) != EOF)
    {
        if (create.accnum == seek.accnum)
        {
            printf("\n\n\nACCOUNT FOUND!!!\nLOADING DETAILS");
            for (int i =0; i<3; i++)
            {
                printf(".");
                fflush(stdout);
                sleep(2);
            }
            system("clear");
            printf("Name: %s\nAddress: %s\nSex: %s\nAge: %d\nNIN: %s\nPhone No: %s\nD.O.B: %s\nAccount number: %d\nBalance: ₦%.2lf\nOpening date: %s\nAccount type: %s\nBranch: %s\n\n", seek.name, seek.address, seek.sex, seek.age, seek.NIN, seek.phone, seek.dob, seek.accnum, seek.bal, seek.dop, seek.type, seek.branch);
        }
    }
    fclose(ptr);

}
int main()
{
    account_check();
    return 0;
}
