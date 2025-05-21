#include <stdio.h>
#include <string.h>
#define MAX 100

struct product
{
    char name[50];
    int price;
};
struct product data[100];

// int data[MAX];
int inx = -1;

// Function list
void addData();
void delData();
void dispData();
void latestData();

void addData()
{

    int pPrice;
    char pName[50];
    printf("\nData Insertion:\n");
    printf("------------------\n");
    getchar();
    printf("Enter Product Name: ");
    gets(pName);

    printf("Enter Data: ");
    scanf("%d", &pPrice);

    // data[inx] = num;

    // file management
    FILE *fp;
    fp = fopen("data.txt", "a");
    if (fp == NULL)
    {

        printf("file not exist.\n");
    }
    else
    {
        fprintf(fp, "%s %d\n", pName, pPrice);
        fclose(fp);
    }

    printf("Data Added Successful.\n");
}

// Get Latest Data in array
void latestData()
{

    int pPrice;
    char pName[50];
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {

        printf("file not exist.\n");
    }
    else
    {
        inx = -1;
        while (fscanf(fp, "%s %d", &pName, &pPrice) != EOF)
        {
            inx++;
            // data[inx].name=pName;
            strcpy(data[inx].name, pName);
            data[inx].price = pPrice;
        }

        fclose(fp);
    }
}

//  show data
void dispData()
{
    latestData();

    printf("\nData Display:\n");
    printf("----------------\n");
    for (int i = 0; i <= inx; i++)
    {
        printf("%s %d \n", data[i].name, data[i].price);
    }
}

void delData()
{
    latestData();

    printf("\nData Delete:\n");
    printf("----------------\n");
    int num, i, found = 0;
    printf("Enter index to delete: ");
    scanf("%d", &num);
    // for (i = 0; i <= inx; i++)
    // {
    //     if (data[i] == num)
    //     {
    //         found = 1;
    //         break;
    //     }
    // }
    // if (found)
    // {
    for (int j = num - 1; j <= inx - 1; j++)
    {
        data[j] = data[j + 1];
    }
    inx--;
    printf("%d Deleted successfully.\n", num);

    // file management
    FILE *fp;
    fp = fopen("data.txt", "w"); // clear all previous data
    fclose(fp);
    // new data push
    fp = fopen("data.txt", "a");
    if (fp == NULL)
    {

        printf("file not exist.\n");
    }
    else
    {
        for (int i = 0; i <= inx; i++)
        {
            fprintf(fp, "%s %d\n", data[i].name, data[i].price);
        }

        fclose(fp);
    }
}

// main function
int main()
{
    while (1)
    {
        int n;
        printf("\nMenu:\n");
        printf("1. Add \n2. Delete \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            addData();
            break;
        case 2:
            delData();
            break;
        case 3:
            dispData();
            break;
        case 0:
            return 0;
        }
    }
}
