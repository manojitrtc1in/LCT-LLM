#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    int first;
    int second;
} Pair;

Pair makePair(int first, int second) {
    Pair p;
    p.first = first;
    p.second = second;
    return p;
}

int main() {
    long n, a1, a2, a3, b1, b2, b3;
    scanf("%ld %ld %ld %ld %ld %ld %ld", &n, &a1, &a2, &a3, &b1, &b2, &b3);

    long min = 0;

    if (b1 >= a1 + a2) {
        min = a3 - b2 - b3;
    } else if (b2 >= a3 + a2) {
        min = a1 - b1 - b3;
    } else if (b3 >= a1 + a3) {
        min = a2 - b2 - b1;
    } else {
        min = 0;
    }

    long max = (a1 < b2 ? a1 : b2) + (a2 < b3 ? a2 : b3) + (a3 < b1 ? a3 : b1);

    printf("%ld %ld\n", min, max);

    return 0;
}
