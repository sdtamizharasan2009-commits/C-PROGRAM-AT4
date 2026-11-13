#include <stdio.h>

int main()
{
    int rainfall[3][4] = {
        {100, 120, 80, 90},
        {40, 30, 50, 35},
        {200, 180, 220, 190}
    };

    int i, j, total = 0, maximum = 0;
    float districtTotal, stateAverage, districtAverage;

    for (i = 0; i < 3; i++)
    {
        districtTotal = 0;

        for (j = 0; j < 4; j++)
        {
            districtTotal += rainfall[i][j];
            total += rainfall[i][j];

            if (rainfall[i][j] > maximum)
                maximum = rainfall[i][j];
        }

        printf("District %d Total: %.0f\n", i + 1, districtTotal);
        printf("District %d Average: %.2f\n\n", i + 1, districtTotal / 4);
    }

    stateAverage = (float)total / 12;

    printf("State Average: %.2f\n", stateAverage);
    printf("Maximum Rainfall: %d\n", maximum);

    printf("Deficient Districts:\n");

    for (i = 0; i < 3; i++)
    {
        districtTotal = 0;

        for (j = 0; j < 4; j++)
            districtTotal += rainfall[i][j];

        districtAverage = districtTotal / 4;

        if (districtAverage < 0.60 * stateAverage)
            printf("District %d\n", i + 1);
    }

    return 0;
}