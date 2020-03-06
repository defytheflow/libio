#include <stdio.h>

#include <clear-io.h>

#define NUM_WORDS 5
#define MAX_WORD  256

int main(void)
{
        int i, j, len;
        char words[NUM_WORDS][MAX_WORD];

        printf("Enter %d words.\n", NUM_WORDS);
        for (i = 0; i < NUM_WORDS; ++i) {
                if ((len = get_string("word: ", words[i], MAX_WORD)) == 0)
                        break;
        }

        printf("Entered words:\n");
        for (j = 0; j < i; ++j)
                printf("%s\n", words[j]);

        return 0;
}
