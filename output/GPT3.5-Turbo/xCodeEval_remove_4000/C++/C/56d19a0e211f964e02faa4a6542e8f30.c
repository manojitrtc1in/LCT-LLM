#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

typedef struct {
    char words[MAXLEN][MAXLEN];
    int count;
} Set;

int main()
{
    Set S[4];
    char s[MAXLEN];
    int i, j, id;

    scanf("%d", &id);

    j = sizeof(S1) / sizeof(S1[0]);
    for (i = 0; i < j; ++i) {
        strcpy(S[1].words[i], S1[i]);
        S[1].count++;
    }
    j = sizeof(S2) / sizeof(S2[0]);
    for (i = 0; i < j; ++i) {
        strcpy(S[2].words[i], S2[i]);
        S[2].count++;
    }
    j = sizeof(S3) / sizeof(S3[0]);
    for (i = 0; i < j; ++i) {
        strcpy(S[3].words[i], S3[i]);
        S[3].count++;
    }

    while (scanf("%s", s) > 0) {
        int found = 0;
        for (i = 1; i <= 3; ++i) {
            for (j = 0; j < S[i].count; ++j) {
                if (strcmp(s, S[i].words[j]) == 0) {
                    printf("%d\n", i);
                    return 0;
                }
            }
        }
    }

    printf("%d\n", ((id + 4) % 3) + 1);

    return 0;
}
