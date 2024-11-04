#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    long a;
    long b;
    long c;
} Tuple;

long min(long x, long y) {
    return (x < y) ? x : y;
}

void solver() {
    long n;
    scanf("%ld", &n);
    
    long ar[3], br[3];
    for (int i = 0; i < 3; i++) {
        scanf("%ld", &ar[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%ld", &br[i]);
    }

    long mxWins = 0;
    long mxLosesOrDraw = 0;

    for (int i = 0; i < 3; i++) {
        mxWins += min(ar[i], br[(i + 1) % 3]);
        long mxLose = min(br[i], ar[(i + 1) % 3]);
        long mxDraw = min(br[i], ar[i]);
        mxLosesOrDraw += min(br[i], mxLose + mxDraw);
    }

    printf("%ld %ld\n", n - mxLosesOrDraw, mxWins);
}

int main() {
    solver();
    return 0;
}
