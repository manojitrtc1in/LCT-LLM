



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int freq1[27], freq2[27];

int main() {

    char* gen1 = malloc(100001);
    char* gen2 = malloc(100001);
    gets(gen1);
    gets(gen2);

    int size1 = strlen(gen1);
    int size2 = strlen(gen2);

    if(size1 != size2) {

        printf("NO");
        return 0;

    }

    int ct = 0;

    for(int i = 0; i < size1; i++) {

        if(ct > 2) {

            printf("NO");
            return 0;

        }

        if(gen1[i] != gen2[i])
            ct++;

        freq1[gen1[i] - 'a']++;
        freq2[gen2[i] - 'a']++;

    }

    for(int i = 0; i < 27; i++)
        if(freq1[i] != freq2[i]) {

            printf("NO");
            return 0;

        }

    if(ct == 2 || ct == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
