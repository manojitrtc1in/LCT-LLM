#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 109

typedef struct {
    int data[MAX_BUF_SIZE];
    int size;
} bignum;

void bignum_input(bignum *a) {
    memset(a->data, 0, sizeof(a->data));
    char buf[MAX_BUF_SIZE];
    scanf("%s", buf);
    int len = strlen(buf);
    int t = 0, c = 0;
    for (int i = len - 1; i >= 0; i--) {
        t += (buf[i] - '0') * (int)pow(10, c);
        c++;
        if (c == 8) {
            a->data[a->size] = t;
            a->size++;
            t = 0;
            c = 0;
        }
    }
    if (c > 0) {
        a->data[a->size] = t;
        a->size++;
    }
}

void bignum_output(bignum a) {
    for (int i = a.size - 1; i >= 0; i--) {
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
                    printf("%d", a.data[i]);
                } else {
                    printf("000%d", a.data[i]);
                }
            } else {
                if (a.data[i] >= 10) {
                    printf("0000%d", a.data[i]);
                } else {
                    printf("00000%d", a.data[i]);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    bignum a;
    bignum_input(&a);
    bignum_output(a);
    return 0;
}
