#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char name[40];
    int count = 0;
    printf("Enter name: ");
    scanf("%s", name);

    // data send
    fp = fopen("data.txt", "w");
    fprintf(fp, "%s", name);
    fclose(fp);

    // data receive
    fp = fopen("data.txt", "r");
    while (fgetc(fp) != EOF)
    {
        count++;
    }
    fclose(fp);
    printf("char size : %d", count);

    return 0;
}
