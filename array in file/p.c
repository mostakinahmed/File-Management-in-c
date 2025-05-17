#include <stdio.h>

void dataSend(int data[], int n);
void dataReceive(int n);

// data send to file
void dataSend(int data[], int n)
{
    FILE *fp = fopen("data.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d        %d\n", i, data[i]);
    }
    fclose(fp);
}

// data recieved from file
void dataReceive(int n)
{
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    int newData[100] = {0}, id[100], data, num;
    int k = 0;

    while (fscanf(fp, "%d        %d", &num, &data) != EOF)
    {

        id[k] = num;
        newData[num] = data;
        k++;
    }

    fclose(fp);

    // here is our new Array "newData[]"
    printf("Show data:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Id[%d]: %d\n", id[i], newData[i]);
    }
}

int main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int data[n];

    printf("Input data:\n");
    for (int i = 0; i < n; i++)
    {
        printf("data[%d]: ", i);
        scanf("%d", &data[i]);
    }

    dataSend(data, n);
    dataReceive(n);

    return 0;
}
