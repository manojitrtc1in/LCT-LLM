#include <stdio.h>
#include <stdbool.h>

#define MAX_N 310000000
#define MAX_M 100000

int num[MAX_N / MAX_M];

void pre(int n, int len) {
    bool np[n];
    np[0] = np[1] = true;
    for (int i = 0; i < n; i++) {
        if (!np[i]) {
            for (int j = i + i; j < n; j += i) {
                np[j] = true;
            }
        }
    }
    int div = n / len;
    int num[div];
    for (int i = 0, i2 = 0, j = 0; i < n; i++) {
        if (i == 2 || (!np[i] && i % 4 == 1)) {
            num[j]++;
        }
        if (i2 == len - 1) {
            j++;
            i2 = 0;
        } else {
            i2++;
        }
    }
    printf("[");
    for (int i = 0; i < div; i++) {
        printf("%d", num[i]);
        if (i != div - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int nextInt() {
    int c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        c = getchar();
    }
    if (c == '-') {
        return -nextInt();
    }
    int res = 0;
    do {
        res *= 10;
        res += c - '0';
        c = getchar();
    } while ('0' <= c && c <= '9');
    return res;
}

long nextLong() {
    int c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        c = getchar();
    }
    if (c == '-') {
        return -nextLong();
    }
    long res = 0;
    do {
        res *= 10;
        res += c - '0';
        c = getchar();
    } while ('0' <= c && c <= '9');
    return res;
}

double nextDouble() {
    double res;
    scanf("%lf", &res);
    return res;
}

char* next() {
    char* res = malloc(100 * sizeof(char));
    scanf("%s", res);
    return res;
}

char* nextLine() {
    char* res = malloc(100 * sizeof(char));
    scanf(" %[^\n]", res);
    return res;
}

void run() {
    int n = 310000000;
    int m = 100000;

    int l = nextInt();
    int r = nextInt() + 1;
    long res = calc(r) - calc(l);
    printf("%ld\n", res);
}

int calc(int l) {
    int to = l / m;
    long res = 0;
    for (int i = 0; i < to; i++) {
        res += num[i];
    }
    for (int i = to * m; i < l; i++) {
        if (isLucky(i)) {
            res++;
        }
    }
    return res;
}

bool isLucky(int i) {
    return i == 2 || isP(i) && i % 4 == 1;
}

bool isP(int i) {
    if (i < 2) {
        return false;
    }
    for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    run();
    return 0;
}
