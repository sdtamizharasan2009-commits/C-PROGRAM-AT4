#include <stdio.h>
#include <ctype.h>

int word_count(char str[])
{
    int i, count = 0, inWord = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            if (inWord == 0)
            {
                count++;
                inWord = 1;
            }
        }
        else
        {
            inWord = 0;
        }
    }

    return count;
}

int is_palindrome(char str[])
{
    int left = 0, right = 0;

    while (str[right] != '\0')
        right++;

    right--;

    while (left < right)
    {
        while (left < right && !isalnum((unsigned char)str[left]))
            left++;

        while (left < right && !isalnum((unsigned char)str[right]))
            right--;

        if (tolower((unsigned char)str[left]) !=
            tolower((unsigned char)str[right]))
            return 0;

        left++;
        right--;
    }

    return 1;
}

int main()
{
    printf("Words: %d\n", word_count("Meet at the library at 5PM"));

    printf("%d\n", is_palindrome("Madam,I'mAdam"));
    printf("%d\n", is_palindrome("Hello"));

    return 0;
}