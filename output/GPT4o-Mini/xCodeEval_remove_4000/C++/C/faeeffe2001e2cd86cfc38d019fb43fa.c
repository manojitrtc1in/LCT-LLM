#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

typedef short id2;
typedef long long PRODUCT_TYPE;
static const id2 BASE = 1000000000;
static const id2 id5 = 999999999;
static const id2 id0 = 9;
static const int powersOfTen[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

typedef struct {
    id2 *val;
    bool pos;
    size_t size;
} InfInt;

InfInt zero;
InfInt one;
InfInt two;

void initInfInt(InfInt *n) {
    n->val = (id2 *)malloc(sizeof(id2));
    n->val[0] = 0;
    n->pos = true;
    n->size = 1;
}

void fromString(InfInt *n, const char *s);
void correct(InfInt *n);
void multiplyByDigit(id2 factor, id2 *val, size_t *size);
void removeLeadingZeros(InfInt *n);
InfInt operatorPlus(InfInt a, InfInt b);
InfInt operatorMinus(InfInt a, InfInt b);
InfInt operatorMultiply(InfInt a, InfInt b);
InfInt operatorDivide(InfInt a, InfInt b);
InfInt operatorModulo(InfInt a, InfInt b);
InfInt operatorPower(InfInt n, int p);
bool operatorEqual(InfInt a, InfInt b);
bool operatorLessThan(InfInt a, InfInt b);
void freeInfInt(InfInt *n);

int alpha(int n);
int beta(int n);
InfInt power(InfInt n, int p);

int main() {
    char s[100];
    bool lead = true;
    char leading;
    int cnt = 0;
    InfInt res;
    initInfInt(&res);

    scanf("%s", s);
    leading = s[0];

    if (isdigit(leading))
        lead = false;

    id2 bits[30] = {0};

    for (int i = 0; i < strlen(s); ++i) {
        if (isalpha(s[i])) bits[s[i] - 'A'] = 1;
        else if (s[i] == '?') ++cnt;
    }

    if (!lead) {
        res = operatorMultiply(alpha(bits[0]), power((InfInt){.val = (id2[]){10}, .size = 1}, cnt));
    } else {
        if (leading == '?')
            res = operatorMultiply(alpha(bits[0]), operatorMultiply(power((InfInt){.val = (id2[]){10}, .size = 1}, cnt - 1), (InfInt){.val = (id2[]){9}, .size = 1}));
        else
            res = operatorMultiply(beta(bits[0]), power((InfInt){.val = (id2[]){10}, .size = 1}, cnt));
    }

    // Output result
    for (size_t i = 0; i < res.size; ++i) {
        printf("%d", res.val[i]);
    }

    freeInfInt(&res);
    return 0;
}

int alpha(int n) {
    InfInt cnt = {.val = (id2[]){10}, .size = 1};
    InfInt res = {.val = (id2[]){1}, .size = 1};
    for (int i = 0; i < n && i < 11; ++i) {
        res = operatorMultiply(res, cnt);
        cnt.val[0] = (cnt.val[0] > 0) ? cnt.val[0] - 1 : 0;
    }
    return res.val[0];
}

int beta(int n) {
    InfInt cnt = {.val = (id2[]){9}, .size = 1};
    InfInt res = {.val = (id2[]){9}, .size = 1};
    for (int i = 0; i < n - 1 && i < 11; ++i) {
        res = operatorMultiply(res, cnt);
        cnt.val[0] = (cnt.val[0] > 0) ? cnt.val[0] - 1 : 0;
    }
    return res.val[0];
}

InfInt power(InfInt n, int p) {
    if (p <= 0) return (InfInt){.val = (id2[]){1}, .size = 1};

    InfInt x = power(n, p / 2);
    if (p & 1) return operatorMultiply(operatorMultiply(x, x), n);
    else return operatorMultiply(x, x);
}

void fromString(InfInt *n, const char *s) {
    n->pos = true;
    n->size = 0;
    n->val = (id2 *)malloc(strlen(s) / id0 + 1);
    for (int i = strlen(s) - id0; i >= 0; i -= id0) {
        n->val[n->size++] = atoi(s + i);
    }
    if (strlen(s) % id0 != 0) {
        char ss[10];
        strncpy(ss, s, strlen(s) % id0);
        ss[strlen(s) % id0] = '\0';
        n->val[n->size++] = atoi(ss);
    }
    correct(n);
}

void correct(InfInt *n) {
    removeLeadingZeros(n);
}

void removeLeadingZeros(InfInt *n) {
    for (int i = n->size - 1; i > 0; --i) {
        if (n->val[i] != 0) return;
        else n->size--;
    }
}

void freeInfInt(InfInt *n) {
    free(n->val);
}

InfInt operatorPlus(InfInt a, InfInt b) {
    // Implement addition logic
}

InfInt operatorMinus(InfInt a, InfInt b) {
    // Implement subtraction logic
}

InfInt operatorMultiply(InfInt a, InfInt b) {
    // Implement multiplication logic
}

InfInt operatorDivide(InfInt a, InfInt b) {
    // Implement division logic
}

InfInt operatorModulo(InfInt a, InfInt b) {
    // Implement modulo logic
}

bool operatorEqual(InfInt a, InfInt b) {
    // Implement equality check
}

bool operatorLessThan(InfInt a, InfInt b) {
    // Implement less than check
}
