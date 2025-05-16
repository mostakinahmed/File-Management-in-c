#include <stdio.h>
#include <string.h>
// function declaration
int menu();
void signUp();
void signIn();
void profile(char name[20]);
void logOut();

// File declaration
FILE *fp;

/*....................................................*/
// signup system
// user data send to external file
void signUp()
{
    char uName[20];
    char uPass[20];
    printf("\n          Registration Form\n");
    printf("       ------------------------");
    getchar();
    printf("\nUser Name: ");
    gets(uName);
    printf("User Pass: ");
    gets(uPass);

    // create file

    fp = fopen("userData.text", "a");

    // send data to file
    fprintf(fp, "%s %s\n", uName, uPass);
    printf("User added successful.\n\n");
    fclose(fp);

    // goto homepage
    menu();
}

/*....................................................*/

// signIn system
// data retrive from file
void signIn()
{
    char uName[20];
    char uPass[20];
    char name[20];
    char pass[20];
    int found = 0;
    printf("\n             Sign in Form\n");
    printf("       ------------------------");
    getchar();
    printf("\nUser Name: ");
    gets(uName);
    printf("User Pass: ");
    gets(uPass);

    // open file
    fp = fopen("userData.text", "r");

    // cheak user for login
    if (fp == NULL) // if file have zero data
    {
        printf("File not exist.");
    }
    else
    {
        while (fscanf(fp, "%s %s", name, pass) != EOF)
        {
            if (strcmp(uName, name) == 0 && strcmp(uPass, pass) == 0)
            {
                found = 1; // if userName & password is matched
                break;
            }
        }
        // fclose(fp);

        if (found) // user found
        {
            profile(uName);
        }

        else if (found == 0) // user not found
        {
            printf("Error userName & password.\n");
            menu();
        }
    }

    //  menu();
}

/*....................................................*/

// user profile
void profile(char name[20])
{
    int n;
    printf("\n              Profile\n");
    printf("      ''''''''-------''''''''''\n\n\n");
    printf("           Welcome %s\n\n\n", name);
    printf("           Login successful\n");
    printf("     ''''''''''''''''''''''''''\n");
    printf("     press 0 to logout......");
    scanf("%d", &n);
    logOut();
}

/*....................................................*/

// logOut Function
void logOut()
{
    printf("\n     Logout successful.\n\n");
    menu();
}

/*....................................................*/

// menu to manage operation list
int menu()
{
    int choose;
    printf("\n\n               Home Page\n");
    printf("       ------------------------");
    printf("\n1. sign up. \n2. sign in. \npress 0 to Exit\n");
    printf("choose option.....");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        signUp();
        break;

    case 2:
        signIn();
        break;

    case 0:
        return 0;

    default:
        printf("\nInvalid option.\n");
        menu();
        break;
    }
}

/*....................................................*/

// main function:
int main()
{
    printf("\n        welcome to our system\n");
    printf("<<---------------------------------->>\n");
    menu();
}