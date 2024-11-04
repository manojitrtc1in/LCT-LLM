#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long lcm(long a, long b) {
    return a / gcd(a, b) * b;
}

long factorial(int number) {
    if (number < 0) {
        return 0;
    }
    return (number > 0) ? number * factorial(number - 1) : 1;
}

int main() {
    int g, sh, j, p, priceFirst, priceSecond;
    long answer = 0;

    scanf("%d %d %d %d %d %d", &g, &sh, &j, &p, &priceFirst, &priceSecond);

    if (priceFirst <= priceSecond) {
        answer = fmin(fmin(sh, j), p);
        p -= answer;
        answer *= priceSecond;
        answer += (fmin(p, g) * priceFirst);
    } else {
        answer = fmin(g, p);
        p -= answer;
        answer *= priceFirst;
        answer += (fmin(fmin(sh, j), p) * priceSecond);
    }

    printf("%ld\n", answer);
    return 0;
}
