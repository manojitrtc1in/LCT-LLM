#include <stdio.h>
#include <stdbool.h>

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
    for (int i = 0; i < div; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
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

int n = 310000000;
int m = 100000;
