#include <stdio.h>

int binarySearch(int arr[], int size, int key, int *comparisons)
{
    int low = 0, high = size - 1;

    *comparisons = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        (*comparisons)++;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int accession[] = {1021, 1048, 1103, 1190, 1222, 1305, 1377, 1402, 1460, 1533};
    int keys[] = {1021, 1305, 1533, 1400};
    int size = 10, comparisons, i, result;

    for (i = 0; i < 4; i++)
    {
        result = binarySearch(accession, size, keys[i], &comparisons);
        printf("Key: %d\n", keys[i]);
        printf("Index: %d\n", result);
        printf("Comparisons: %d\n\n", comparisons);
    }

    return 0;
}