#include <stdio.h>
#include <string.h>

int main()
{
    char names[10][30] = {
        "Kumar", "Arun", "David", "Bala", "Charlie",
        "Arun", "Ravi", "Manoj", "John", "Ajay"
    };

    char temp[30], searchName[] = "Arun";
    int i, j, found = 0;

    for (i = 0; i < 10 - 1; i++)
    {
        for (j = 0; j < 10 - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("Sorted Names:\n");

    for (i = 0; i < 10; i++)
        printf("%s\n", names[i]);

    printf("\nDuplicate Names:\n");

    for (i = 0; i < 9; i++)
    {
        if (strcmp(names[i], names[i + 1]) == 0)
            printf("%s\n", names[i]);
    }

    i = 0;
    j = 9;

    while (i <= j)
    {
        int mid = (i + j) / 2;
        int result = strcmp(names[mid], searchName);

        if (result == 0)
        {
            found = 1;
            break;
        }
        else if (result < 0)
            i = mid + 1;
        else
            j = mid - 1;
    }

    if (found)
        printf("\n%s Found\n", searchName);
    else
        printf("\n%s Not Found\n", searchName);

    return 0;
}