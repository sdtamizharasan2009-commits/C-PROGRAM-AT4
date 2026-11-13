#include <stdio.h>

#define MAX_CANDIDATES 12
#define MAX_VOTES 5000

int main()
{
    int votes[] = {
        1, 2, 3, 1, 2, 4, 1, 3, 5, 2,
        1, 4, 2, 3, 1, 5, 2, 0, 6, -1
    };

    int count[MAX_CANDIDATES] = {0};
    int result[MAX_CANDIDATES];
    int candidateCount = 5;
    int voteCount = 20;
    int valid = 0, invalid = 0;
    int i, j, temp;

    for (i = 0; i < voteCount && i < MAX_VOTES; i++)
    {
        if (votes[i] >= 1 && votes[i] <= candidateCount)
        {
            count[votes[i] - 1]++;
            valid++;
        }
        else
        {
            invalid++;
        }
    }

    printf("Valid Votes: %d\n", valid);
    printf("Invalid Votes: %d\n", invalid);

    for (i = 0; i < candidateCount; i++)
        result[i] = i;

    for (i = 0; i < candidateCount - 1; i++)
    {
        for (j = 0; j < candidateCount - i - 1; j++)
        {
            if (count[result[j]] < count[result[j + 1]])
            {
                temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    printf("\nCandidate Results:\n");

    for (i = 0; i < candidateCount; i++)
        printf("Candidate %d: %d votes\n",
               result[i] + 1, count[result[i]]);

    if (count[result[0]] == count[result[1]])
    {
        printf("\nElection Result: Tie\n");
    }
    else
    {
        printf("\nWinner: Candidate %d\n", result[0] + 1);
    }

    return 0;
}