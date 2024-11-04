#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef long long lli;

int ctoi(char c) {
    if (c >= '0' && c <= '9') {
        return (int)(c - '0');
    }
    return -1;
}

int alphabet_pos(char c) {
    if (c >= 'a' && c <= 'z') {
        return (int)(c - 'a');
    }
    return -1;
}

int id6(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (int)(c - 'A');
    }
    return -1;
}

void split(char *str, char ch, char ***result, int *count) {
    int first = 0;
    int last = 0;
    *count = 0;

    while (str[last] != '\0') {
        if (str[last] == ch) {
            str[last] = '\0';
            (*count)++;
        }
        last++;
    }
    (*count)++; // for the last segment

    *result = (char **)malloc((*count) * sizeof(char *));
    last = 0;
    for (int i = 0; i < *count; i++) {
        (*result)[i] = strdup(&str[first]);
        first = last + 1;
        last++;
        while (str[last] != '\0' && str[last] != ch) {
            last++;
        }
    }
}

int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long gcd_long(long long a, long long b) {
    if (a < b) {
        long long temp = a;
        a = b;
        b = temp;
    }
    if (b == 0LL) {
        return a;
    }
    return gcd_long(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

long long lcm_long(long long a, long long b) {
    return a * b / gcd_long(a, b);
}

long long pow_fast(long long x, long long n_power, long long modulus) {
    if (n_power == 0) {
        return 1;
    }
    if (n_power % 2 == 0) {
        return pow_fast(x * x % modulus, n_power / 2, modulus);
    }
    return x * pow_fast(x, n_power - 1, modulus) % modulus;
}

void print_vector_int(int *h, int size, bool verbose) {
    for (int i = 0; i < size; i++) {
        if (verbose) {
            printf("%d", h[i]);
        } else {
            fprintf(stderr, "%d", h[i]);
        }
        if (i != size - 1) {
            if (verbose) {
                printf(" ");
            } else {
                fprintf(stderr, " ");
            }
        } else {
            if (verbose) {
                printf("\n");
            } else {
                fprintf(stderr, "\n");
            }
        }
    }
}

void print_vector_long(long long *h, int size, bool verbose) {
    for (int i = 0; i < size; i++) {
        if (verbose) {
            printf("%lld", h[i]);
        } else {
            fprintf(stderr, "%lld", h[i]);
        }
        if (i != size - 1) {
            if (verbose) {
                printf(" ");
            } else {
                fprintf(stderr, " ");
            }
        } else {
            if (verbose) {
                printf("\n");
            } else {
                fprintf(stderr, "\n");
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    lli *a = (lli *)malloc(N * sizeof(lli));
    lli *b = (lli *)malloc(N * sizeof(lli));
    int *mp = (int *)calloc(1000000, sizeof(int)); // Assuming values in a are less than 1,000,000
    lli *vs = (lli *)malloc(N * sizeof(lli));
    int vs_count = 0;

    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        mp[a[i]]++;
    }

    for (int i = 0; i < N; i++) {
        scanf("%lld", &b[i]);
    }

    for (int i = 0; i < 1000000; i++) {
        if (mp[i] > 1) {
            vs[vs_count++] = i;
        }
    }

    lli ans = 0;
    for (int i = 0; i < N; i++) {
        bool isok = false;
        for (int j = 0; j < vs_count; j++) {
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

    free(a);
    free(b);
    free(mp);
    free(vs);
    return 0;
}
