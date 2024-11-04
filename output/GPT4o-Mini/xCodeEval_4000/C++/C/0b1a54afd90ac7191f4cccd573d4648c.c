#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100000
#define INF 1000000007

long long a[MAX_N];
long long b[MAX_N];
int count[1000001]; // Assuming the values in a are within this range

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%lld", &a[i]);
        count[a[i]]++;
    }

    for (int i = 0; i < N; ++i) {
        scanf("%lld", &b[i]);
    }

    long long vs[MAX_N];
    int vs_size = 0;

    for (int i = 0; i < 1000001; ++i) {
        if (count[i] > 1) {
            vs[vs_size++] = i;
        }
    }

    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        bool isok = false;
        for (int j = 0; j < vs_size; ++j) {
            if ((vs[j] & a[i]) == a[i]) {
                isok = true;
                break;
            }
        }

        if (isok) {
            ans += b[i];
        }
    }

    printf("%lld\n", ans);
    return 0;
}
