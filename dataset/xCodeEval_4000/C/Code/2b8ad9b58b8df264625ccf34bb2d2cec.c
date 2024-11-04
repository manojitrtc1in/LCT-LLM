



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int main() {

    int n;
    scanf("%d", &n);

    int array[n];
    int sum[n];

    for(int i = 0; i < n; i++) {

        scanf("%d", &array[i]);

    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(i == j)
                continue;
            for(int k = 0; k < n; k++) {

                if(array[i] + array[j] == array[k]) {

                    if(i > j)
                        printf("%d %d %d", k + 1, i + 1, j + 1);
                    else
                        printf("%d %d %d", k + 1, j + 1, i + 1);
                    return 0;

                }

            }
        }
    }

    printf("-1");
    return 0;

}
