#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val[30];
} bitset;

typedef struct {
    int digits[1000];
    int size;
} InfInt;

InfInt zero;
InfInt one;
InfInt two;

void init(InfInt* num) {
    memset(num->digits, 0, sizeof(num->digits));
    num->size = 1;
}

void fromString(InfInt* num, const char* str) {
    init(num);
    int len = strlen(str);
    int i = 0;
    if (str[0] == '-') {
        num->digits[0] = -1;
        i = 1;
    }
    for (; i < len; i++) {
        num->digits[i] = str[i] - '0';
    }
    num->size = len;
}

void toString(const InfInt* num, char* str) {
    int i = 0;
    if (num->digits[0] == -1) {
        str[0] = '-';
        i = 1;
    }
    for (; i < num->size; i++) {
        str[i] = num->digits[i] + '0';
    }
    str[num->size] = '\0';
}

void add(InfInt* res, const InfInt* a, const InfInt* b) {
    int carry = 0;
    int i;
    for (i = 0; i < a->size || i < b->size; i++) {
        int sum = carry;
        if (i < a->size) {
            sum += a->digits[i];
        }
        if (i < b->size) {
            sum += b->digits[i];
        }
        res->digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) {
        res->digits[i] = carry;
        i++;
    }
    res->size = i;
}

void multiplyByDigit(InfInt* res, const InfInt* a, int digit) {
    int carry = 0;
    int i;
    for (i = 0; i < a->size; i++) {
        int prod = a->digits[i] * digit + carry;
        res->digits[i] = prod % 10;
        carry = prod / 10;
    }
    if (carry > 0) {
        res->digits[i] = carry;
        i++;
    }
    res->size = i;
}

void multiply(InfInt* res, const InfInt* a, const InfInt* b) {
    InfInt temp;
    init(&temp);
    init(res);
    int i;
    for (i = 0; i < b->size; i++) {
        multiplyByDigit(&temp, a, b->digits[i]);
        InfInt shift;
        init(&shift);
        int j;
        for (j = 0; j < i; j++) {
            shift.digits[j] = 0;
        }
        shift.digits[j] = 1;
        shift.size = j + 1;
        multiplyByDigit(&temp, &temp, 10);
        add(res, res, &temp);
    }
}

void power(InfInt* res, const InfInt* n, int p) {
    InfInt x;
    init(&x);
    if (p <= 0) {
        res->digits[0] = 1;
        res->size = 1;
        return;
    }
    power(&x, n, p / 2);
    multiply(res, &x, &x);
    if (p % 2 == 1) {
        multiplyByDigit(res, res, n->digits[0]);
    }
}

void alpha(InfInt* res, const bitset* bits, int n) {
    InfInt cnt;
    init(&cnt);
    cnt.digits[0] = 10;
    cnt.size = 1;
    init(res);
    int i;
    for (i = 0; i < n && i < 11; i++) {
        multiply(res, res, &cnt);
        subtract(&cnt, &cnt, &one);
    }
}

void beta(InfInt* res, const bitset* bits, int n) {
    InfInt cnt;
    init(&cnt);
    cnt.digits[0] = 9;
    cnt.size = 1;
    init(res);
    int i;
    for (i = 0; i < n - 1 && i < 11; i++) {
        multiply(res, res, &cnt);
        subtract(&cnt, &cnt, &one);
    }
}

void subtract(InfInt* res, const InfInt* a, const InfInt* b) {
    InfInt temp;
    init(&temp);
    init(res);
    int borrow = 0;
    int i;
    for (i = 0; i < a->size || i < b->size; i++) {
        int diff = borrow;
        if (i < a->size) {
            diff += a->digits[i];
        }
        if (i < b->size) {
            diff -= b->digits[i];
        }
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        res->digits[i] = diff;
    }
    res->size = i;
    while (res->size > 1 && res->digits[res->size - 1] == 0) {
        res->size--;
    }
}

void solve(const char* s, char* result) {
    bitset bits;
    memset(&bits, 0, sizeof(bits));
    int cnt = 0;
    int i;
    char leading = s[0];
    int lead = 1;
    if (isdigit(leading)) {
        lead = 0;
    }
    for (i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            bits.val[s[i] - 'A'] = 1;
        } else if (s[i] == '?') {
            cnt++;
        }
    }
    InfInt res;
    init(&res);
    if (!lead) {
        alpha(&res, &bits, __builtin_popcount(bits));
        power(&temp, &ten, cnt);
        multiply(&res, &res, &temp);
    } else {
        if (leading == '?') {
            alpha(&res, &bits, __builtin_popcount(bits));
            power(&temp, &ten, cnt - 1);
            multiply(&res, &res, &temp);
            multiplyByDigit(&res, &res, 9);
        } else {
            beta(&res, &bits, __builtin_popcount(bits));
            power(&temp, &ten, cnt);
            multiply(&res, &res, &temp);
        }
    }
    toString(&res, result);
}

int main() {
    InfInt zero;
    init(&zero);
    InfInt one;
    init(&one);
    one.digits[0] = 1;
    one.size = 1;
    InfInt two;
    init(&two);
    two.digits[0] = 2;
    two.size = 1;

    char s[100];
    scanf("%s", s);

    char result[1000];
    solve(s, result);

    printf("%s\n", result);

    return 0;
}
