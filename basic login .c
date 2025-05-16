#include <stdio.h>
#include <string.h>
int main()
{
    char name[100];
    char pass[100];
    char fName[100];
    char fPass[100];
    printf("Enter userName : ");
    gets(name);
    printf("Enter pass : ");
    gets(pass);

    FILE *fp;
    // create file
    fp = fopen("data.text", "a");

    // // send data to file
    // if (fp == NULL)
    // {
    //     printf("error opening file.");
    // }
    // else
    // {

    //     fprintf(fp, "%s %s\n", name, pass);
    //     // fclose(fp);
    // }
    int found = 0;
    fp = fopen("data.text", "r");
    // data read
    while (fscanf(fp, "%s %s", fName, fPass) != EOF)
    {
        if (strcmp(name, fName) == 0 && strcmp(pass, fPass) == 0)
        {
            found++;
        }
    }

    if (found)
    {
        printf("\nUser Exist. Logined.\n");
    }
    else
    {
        printf("\nUser Not found.\n");
    }

    fclose(fp);
    return 0;
}
