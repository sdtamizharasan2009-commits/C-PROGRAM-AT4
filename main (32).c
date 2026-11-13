#include <stdio.h>

int main()
{
    int A[] = {98, 91, 85, 72};
    int B[] = {95, 91, 80};
    int C[7];

    int i = 0, j = 0, k = 0;

    while (i < 4 && j < 3)
    {
        if (A[i] >= B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < 4)
        C[k++] = A[i++];

    while (j < 3)
        C[k++] = B[j++];

    printf("Merged Merit List: ");

    for (i = 0; i < 7; i++)
        printf("%d ", C[i]);

    return 0;
}