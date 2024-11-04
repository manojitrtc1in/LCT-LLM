



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int freq[1001];
int main() {

    int n;
    scanf("%d", &n);
    int* array = (int*)malloc(sizeof(int) * n);
    int ct = 0;

    for(int i = 0; i < n; i++) {

        scanf("%d", &array[i]);
        freq[array[i]]++;
    }

    for(int i = 0; i < 1001; i++) {

        if(freq[i] > (ceil)(1.0 * n / 2)) {

            printf("NO");
            return 0;

        }
    }

    printf("YES");
    return 0;

}
