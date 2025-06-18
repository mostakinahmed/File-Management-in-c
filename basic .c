#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char value[50];
    // fp = fopen("data.txt", "w");
    // for (int i = 1; i <= 50; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         fprintf(fp, "%d\n", i);
    //     }
    // }
    // fclose(fp);

    fp = fopen("data.txt", "r");
    while (fscanf(fp, "%s\n", value) != EOF)
    {
        printf("%s\n", value);
    }
    fclose(fp);

    return 0;
}
