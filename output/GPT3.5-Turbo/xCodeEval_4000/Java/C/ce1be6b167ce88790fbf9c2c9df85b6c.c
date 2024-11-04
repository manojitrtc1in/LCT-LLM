#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

typedef struct {
    int a;
    int b;
    int c;
} Tuple;

int min(int a, int b) {
    return a < b ? a : b;
}

long long int abs(long long int a) {
    return a >= 0 ? a : -a;
}

void solver() {
    long long int n;
    scanf("%lld", &n);

    long long int ar[3];
    for (int i = 0; i < 3; i++) {
        scanf("%lld", &ar[i]);
    }

    long long int br[3];
    for (int i = 0; i < 3; i++) {
        scanf("%lld", &br[i]);
    }

    long long int mxWins = 0;
    long long int mxLosesOrDraw = 0;
    long long int draws = 0;
    for (int i = 0; i < 3; i++) {
        mxWins += min(ar[i], br[(i + 1) % 3]);
        long long int mxLose = min(br[i], ar[(i + 1) % 3]);
        long long int mxDraw = min(br[i], ar[i]);
        mxLosesOrDraw += min(br[i], mxLose + mxDraw);
    }

    printf("%lld %lld\n", n - mxLosesOrDraw, mxWins);
}

int main() {
    solver();
    return 0;
}
