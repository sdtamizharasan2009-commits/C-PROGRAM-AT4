#include <stdio.h>

int main()
{
    int original[] = {45, 12, 30, 8, 25, 18};
    int arr[6], i, j, temp;
    int comparisons, swaps, flag;

    for (i = 0; i < 6; i++)
        arr[i] = original[i];

    comparisons = 0;
    swaps = 0;

    for (i = 0; i < 5; i++)
    {
        flag = 0;

        for (j = 0; j < 5 - i; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }

    printf("Bubble Sort: ");
    for (i = 0; i < 6; i++)
        printf("%d ", arr[i]);

    printf("\nComparisons: %d\nSwaps: %d\n\n", comparisons, swaps);

    for (i = 0; i < 6; i++)
        arr[i] = original[i];

    comparisons = 0;
    swaps = 0;

    for (i = 0; i < 5; i++)
    {
        int min = i;

        for (j = i + 1; j < 6; j++)
        {
            comparisons++;

            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            swaps++;
        }
    }

    printf("Selection Sort: ");
    for (i = 0; i < 6; i++)
        printf("%d ", arr[i]);

    printf("\nComparisons: %d\nSwaps: %d\n\n", comparisons, swaps);

    for (i = 0; i < 6; i++)
        arr[i] = original[i];

    comparisons = 0;

    for (i = 1; i < 6; i++)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
                break;
        }

        arr[j + 1] = temp;
    }

    printf("Insertion Sort: ");
    for (i = 0; i < 6; i++)
        printf("%d ", arr[i]);

    printf("\nComparisons: %d\n", comparisons);

    return 0;
}