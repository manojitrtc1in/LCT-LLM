#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BITS 30
#define MAX_SIZE 1000

typedef struct {
    unsigned long long *val;
    int size;
    int pos;
} InfInt;

InfInt createInfInt() {
    InfInt num;
    num.val = (unsigned long long *)malloc(sizeof(unsigned long long) * MAX_SIZE);
    num.size = 0;
    num.pos = 1;
    return num;
}

void freeInfInt(InfInt *num) {
    free(num->val);
}

InfInt alpha(int n);
InfInt beta(int n);
InfInt power(InfInt n, int p);
void fromString(InfInt *num, const char *s);
void printInfInt(InfInt num);

char s[MAX_SIZE];
int bits[MAX_BITS] = {0};
int cnt = 0;
char leading;
int lead = 1;
InfInt res;

int main() {
    scanf("%s", s);
    leading = s[0];

    if (isdigit(leading))
        lead = 0;

    for (int i = 0; i < strlen(s); ++i) {
        if (isalpha(s[i])) bits[s[i] - 'A'] = 1;
        else if (s[i] == '?') ++cnt;
    }

    if (!lead) {
        res = alpha(0);
        for (int i = 0; i < MAX_BITS; ++i) {
            if (bits[i]) res = power(res, 10);
        }
    } else {
        if (leading == '?')
            res = alpha(0);
        else
            res = beta(0);
        for (int i = 0; i < MAX_BITS; ++i) {
            if (bits[i]) res = power(res, 10);
        }
    }

    printInfInt(res);
    freeInfInt(&res);
    return 0;
}

InfInt alpha(int n) {
    InfInt cnt = createInfInt();
    cnt.val[0] = 10;
    cnt.size = 1;
    InfInt res = createInfInt();
    res.val[0] = 1;
    res.size = 1;

    for (int i = 0; i < (n < 11 ? n : 11); ++i) {
        // Multiply res by cnt
        res.val[0] *= cnt.val[0];
        cnt.val[0] = (cnt.val[0] > 0) ? cnt.val[0] - 1 : 0;
    }
    return res;
}

InfInt beta(int n) {
    InfInt cnt = createInfInt();
    cnt.val[0] = 9;
    cnt.size = 1;
    InfInt res = createInfInt();
    res.val[0] = 9;
    res.size = 1;

    for (int i = 0; i < (n - 1 < 11 ? n - 1 : 11); ++i) {
        // Multiply res by cnt
        res.val[0] *= cnt.val[0];
        cnt.val[0] = (cnt.val[0] > 0) ? cnt.val[0] - 1 : 0;
    }
    return res;
}

InfInt power(InfInt n, int p) {
    if (p <= 0) {
        InfInt one = createInfInt();
        one.val[0] = 1;
        one.size = 1;
        return one;
    }

    InfInt x = power(n, p / 2);
    InfInt result = createInfInt();
    result.val[0] = x.val[0] * x.val[0];

    if (p & 1) {
        result.val[0] *= n.val[0];
    }
    return result;
}

void printInfInt(InfInt num) {
    if (!num.pos) {
        printf("-");
    }
    for (int i = num.size - 1; i >= 0; --i) {
        printf("%llu", num.val[i]);
    }
}
