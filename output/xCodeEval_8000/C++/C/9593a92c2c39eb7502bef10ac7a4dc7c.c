#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 109

typedef struct {
    int data[MAX_BUF_SIZE];
} bignum;

void bignum_input(bignum *a) {
    char buf[MAX_BUF_SIZE];
    scanf("%s", buf);
    int t, i;
    int c = 0;
    int d = 0;
    for (i = strlen(buf) - 8; i > 0; i -= 8) {
        sscanf(buf + i, "%d", &t);
        a->data[d++] = t;
    }
    sscanf(buf, "%d", &t);
    a->data[d++] = t;
}

void bignum_output(bignum a) {
    int i;
    printf("%d", a.data[a.size() - 1]);
    for (i = a.size() - 2; i >= 0; i--) {
        if (a.data[i] >= 10000) {
            if (a.data[i] >= 1000000) {
                if (a.data[i] >= 10000000) {
                    printf("%d", a.data[i]);
                } else {
                    printf("0%d", a.data[i]);
                }
            } else {
                if (a.data[i] >= 100000) {
                    printf("%d", a.data[i]);
                } else {
                    printf("00%d", a.data[i]);
                }
            }
        } else {
            if (a.data[i] >= 100) {
                if (a.data[i] >= 1000) {
                    printf("000%d", a.data[i]);
                } else {
                    printf("0000%d", a.data[i]);
                }
            } else {
                if (a.data[i] >= 10) {
                    printf("00000%d", a.data[i]);
                } else {
                    printf("000000%d", a.data[i]);
                }
            }
        }
    }
}

int main() {
    bignum a;
    bignum_input(&a);
    bignum_output(a);
    return 0;
}
