
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
    char  sex [8];                                                  int age;
     int NIN;
    char phone [15];
    double  bal;
    char type[8];
    char branch[10];
    int accnum;
    char  dop[12];
} create, seek;


void account_check()
{
    int look;
    int anum;
    FILE *ptr;
    ptr= fopen("Clientlist.txt", "r");
    if(ptr == NULL)
    {
        printf("\nFilE DOES NOT EXIST\n");
        exit(1);
    }
    system("clear");

    printf("\nENTER NIN: ");
    scanf("%d", &look);
    while(fscanf(ptr, "Name: %s\nAddress: %s\nSex: %s\nAge: %d\nNIN: %d\nPhone No: %s\nD.O.B: %s\nAccount number: %d\nBalance: ₦%lf\nOpening date: %s\nAccount type: %s\nBranch: %s", seek.name, seek.address, seek.sex, &seek.age, &seek.NIN, seek.phone, seek.dob, &seek.accnum, &seek.bal, seek.dop, seek.type, seek.branch) != EOF)
    {
        if (look == seek.NIN)
        {
            printf("\n\n\nACCOUNT FOUND\nLOADING DETAILS");
            for (int i =0; i<3; i++)
            {
                printf(".");
                fflush(stdout);
                sleep(2);
            }
            system("clear");
            printf("Name: %s\nAddress: %s\nSex: %s\nAge: %d\nNIN: %d\nPhone No: %s\nD.O.B: %s\nAccount number: %d\nBalance: ₦%.2lf\nOpening date: %s\nAccount type: %s\nBranch: %s\n\n", seek.name, seek.address, seek.sex, seek.age, seek.NIN, seek.phone, seek.dob, seek.accnum, seek.bal, seek.dop, seek.type, seek.branch);
            fclose(ptr);
            //while(1)
            //{
              //  printf("\nn\n\nENTER 1 TO GO BACK TO MAIN MENU OR 0 TO EXIT: ");
                //scanf("%d", &choice);
               // if(choice == 0)
//                {
//                    end();
  //              }
    //            else if(choice == 1)
      //          {
        //            menu();
          //      }
            //    else
              //  {
                //    printf("\nENTER A VALID OPTION: ");

        //        }
      //  }
        }
    }

}
int main()
{
    account_check();
    return 0;
}
