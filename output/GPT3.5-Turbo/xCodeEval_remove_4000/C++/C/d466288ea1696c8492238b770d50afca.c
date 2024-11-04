#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int* arr;
    int sign;
} Int;

int size;
int max = 1000000000;

Int* createInt(const char* a);
Int* copyInt(const Int* a);
void destroyInt(Int* a);

Int* assignInt(Int* a, const Int* b);
Int* assignString(Int* a, const char* b);

int compareInt(const Int* a, const Int* b);
int compareString(const Int* a, const char* b);

Int* negateInt(const Int* a, Int* result);

Int* addInt(const Int* a, const Int* b, Int* result);
Int* addString(const Int* a, const char* b, Int* result);

Int* subtractInt(const Int* a, const Int* b, Int* result);
Int* subtractString(const Int* a, const char* b, Int* result);

Int* multiplyInt(const Int* a, const Int* b, Int* result);
Int* multiplyString(const Int* a, const char* b, Int* result);

char* toString(const Int* a);

void set_size(int k);
int num(const char* a);
char* str(int a);
Int* absInt(const Int* a);

int qanak;

Int* solve(const char* s, int h);
void mainFunction();

int main() {
    qanak = 0;
    set_size(12);
    Int* answer = createInt("0");
    char s[100];
    scanf("%s", s);
    if (strlen(s) == 1) {
        if (s[0] == '?' || (s[0] >= 'A' && s[0] <= 'Z')) {
            assignString(answer, "9");
        } else {
            assignString(answer, "1");
        }
        printf("%s\n", toString(answer));
        destroyInt(answer);
        return 0;
    }
    if (s[0] == '?') {
        char st[100];
        strcpy(st, s);
        memmove(st, st + 1, strlen(st));
        Int* temp = solve(st, 0);
        multiplyString(temp, "9", answer);
        destroyInt(temp);
    } else if (s[0] >= 'A' && s[0] <= 'Z') {
        for (int k = 1; k < 10; ++k) {
            char st[100];
            strcpy(st, s);
            qanak = 0;
            for (int i = 0; i < strlen(st); ++i) {
                if (st[i] == s[0]) {
                    st[i] = (char)('0' + k);
                }
            }
            Int* temp = solve(st, 1);
            addInt(answer, temp, answer);
            destroyInt(temp);
        }
    } else {
        solve(s, 0);
        multiplyString(answer, "9", answer);
    }
    printf("%s", toString(answer));
    for (int i = 0; i < qanak; ++i) {
        printf("0");
    }
    printf("\n");
    destroyInt(answer);
    return 0;
}

Int* createInt(const char* a) {
    Int* num = (Int*)malloc(sizeof(Int));
    num->arr = (int*)calloc(size + 1, sizeof(int));
    num->sign = 0;
    if (a[0] == '-') {
        num->sign = 1;
        memmove(a, a + 1, strlen(a));
    }
    num->arr[0] = 0;
    while (strlen(a) > 9) {
        num->arr[0]++;
        num->arr[num->arr[0]] = num(a + strlen(a) - 9);
        memmove(a + strlen(a) - 9, a, strlen(a));
        a[strlen(a) - 9] = '\0';
    }
    num->arr[0]++;
    num->arr[num->arr[0]] = num(a);
    return num;
}

Int* copyInt(const Int* a) {
    Int* num = (Int*)malloc(sizeof(Int));
    num->arr = (int*)calloc(size + 1, sizeof(int));
    num->sign = a->sign;
    num->arr[0] = a->arr[0];
    for (int i = 1; i <= num->arr[0]; i++) {
        num->arr[i] = a->arr[i];
    }
    return num;
}

void destroyInt(Int* a) {
    free(a->arr);
    free(a);
}

Int* assignInt(Int* a, const Int* b) {
    if (a != b) {
        free(a->arr);
        a->arr = (int*)calloc(size + 1, sizeof(int));
        a->sign = b->sign;
        a->arr[0] = b->arr[0];
        for (int i = 1; i <= a->arr[0]; i++) {
            a->arr[i] = b->arr[i];
        }
    }
    return a;
}

Int* assignString(Int* a, const char* b) {
    Int* num = createInt(b);
    assignInt(a, num);
    destroyInt(num);
    return a;
}

int compareInt(const Int* a, const Int* b) {
    int* brr = b->arr;
    if (a->sign != b->sign) {
        return a->sign < b->sign ? -1 : 1;
    }
    if (a->sign == 0) {
        if (a->arr[0] != brr[0]) {
            return a->arr[0] > brr[0] ? 1 : -1;
        }
        for (int i = a->arr[0]; i >= 1; i--) {
            if (a->arr[i] != brr[i]) {
                return a->arr[i] > brr[i] ? 1 : -1;
            }
        }
        return 0;
    }
    if (a->arr[0] != brr[0]) {
        return a->arr[0] < brr[0] ? 1 : -1;
    }
    for (int i = a->arr[0]; i >= 1; i--) {
        if (a->arr[i] != brr[i]) {
            return a->arr[i] < brr[i] ? 1 : -1;
        }
    }
    return 0;
}

int compareString(const Int* a, const char* b) {
    Int* num = createInt(b);
    int result = compareInt(a, num);
    destroyInt(num);
    return result;
}

Int* negateInt(const Int* a, Int* result) {
    assignInt(result, a);
    result->sign = (result->sign + 1) % 2;
    return result;
}

Int* addInt(const Int* a, const Int* b, Int* result) {
    int* brr = b->arr;
    int carry = 0;
    if (compareString(a, "0") < 0) {
        if (compareString(b, "0") < 0) {
            if (a->arr[0] >= brr[0]) {
                for (int i = 1; i <= brr[0]; i++) {
                    result->arr[i] = a->arr[i] + brr[i] + carry;
                    carry = result->arr[i] / max;
                    result->arr[i] %= max;
                }
                while (carry) {
                    result->arr[i] = result->arr[i] + carry;
                    carry = result->arr[i] / max;
                    result->arr[i] %= max;
                    i++;
                }
                if (i == result->arr[0] + 2) {
                    result->arr[0]++;
                }
            } else {
                Int* c = copyInt(a);
                Int* d = copyInt(b);
                assignInt(result, addInt(d, c, result));
                destroyInt(c);
                destroyInt(d);
            }
        } else {
            if (compareInt(a, negateInt(b, result)) == 0) {
                assignString(result, "0");
            } else if (compareInt(negateInt(a, result), b) > 0) {
                for (int i = 1; i <= brr[0]; i++) {
                    result->arr[i] = a->arr[i] - brr[i] + carry;
                    if (result->arr[i] < 0) {
                        carry = -1;
                        result->arr[i] += max;
                    } else {
                        carry = 0;
                    }
                }
                while (carry) {
                    result->arr[i] = result->arr[i] + carry;
                    if (result->arr[i] < 0) {
                        carry = -1;
                        result->arr[i] += max;
                    } else {
                        carry = 0;
                    }
                    i++;
                }
                while (result->arr[result->arr[0]] == 0 && result->arr[0] > 1) {
                    result->arr[0]--;
                }
            } else {
                Int* c = copyInt(a);
                Int* d = copyInt(b);
                assignInt(result, subtractInt(d, c, result));
                destroyInt(c);
                destroyInt(d);
            }
        }
    } else {
        if (compareString(b, "0") < 0) {
            if (compareInt(a, negateInt(b, result)) == 0) {
                assignString(result, "0");
            } else if (compareInt(a, negateInt(b, result)) > 0) {
                for (int i = 1; i <= brr[0]; i++) {
                    result->arr[i] = a->arr[i] - brr[i] + carry;
                    if (result->arr[i] < 0) {
                        carry = -1;
                        result->arr[i] += max;
                    } else {
                        carry = 0;
                    }
                }
                while (carry) {
                    result->arr[i] = result->arr[i] + carry;
                    if (result->arr[i] < 0) {
                        carry = -1;
                        result->arr[i] += max;
                    } else {
                        carry = 0;
                    }
                    i++;
                }
                while (result->arr[result->arr[0]] == 0 && result->arr[0] > 1) {
                    result->arr[0]--;
                }
            } else {
                Int* c = copyInt(a);
                Int* d = copyInt(b);
                assignInt(result, subtractInt(d, c, result));
                destroyInt(c);
                destroyInt(d);
            }
        } else {
            Int* c = negateInt(a, result);
            Int* d = negateInt(b, result);
            assignInt(result, addInt(d, c, result));
            destroyInt(c);
            destroyInt(d);
        }
    }
    return result;
}

Int* addString(const Int* a, const char* b, Int* result) {
    Int* num = createInt(b);
    addInt(a, num, result);
    destroyInt(num);
    return result;
}

Int* subtractInt(const Int* a, const Int* b, Int* result) {
    Int* c = negateInt(b, result);
    addInt(a, c, result);
    destroyInt(c);
    return result;
}

Int* subtractString(const Int* a, const char* b, Int* result) {
    Int* num = createInt(b);
    subtractInt(a, num, result);
    destroyInt(num);
    return result;
}

Int* multiplyInt(const Int* a, const Int* b, Int* result) {
    if (compareString(b, "0") == 0) {
        assignString(result, "0");
    } else if (compareString(b, str(max)) == 0) {
        if (compareString(a, "0") != 0) {
            for (int i = a->arr[0]; i >= 1; i--) {
                result->arr[i + 1] = a->arr[i];
            }
            result->arr[1] = 0;
            result->arr[0]++;
        }
    } else if (compareInt(absInt(b), str(max)) < 0) {
        long long tmp;
        int carry = 0;
        int* brr = b->arr;
        for (int i = 1; i <= a->arr[0]; i++) {
            tmp = (long long)a->arr[i] * (long long)brr[1] + (long long)carry;
            result->arr[i] = tmp % (long long)max;
            carry = tmp / (long long)max;
        }
        if (carry) {
            result->arr[result->arr[0] + 1] = carry;
            result->arr[0]++;
        }
    } else {
        Int* tmp = createInt("0");
        Int* res = createInt("0");
        int* brr = b->arr;
        for (int i = brr[0]; i >= 1; i--) {
            multiplyString(a, str(brr[i]), tmp);
            multiplyString(res, str(max), res);
            addInt(res, tmp, res);
        }
        assignInt(result, res);
        destroyInt(tmp);
        destroyInt(res);
    }
    result->sign = (a->sign + b->sign) % 2;
    return result;
}

Int* multiplyString(const Int* a, const char* b, Int* result) {
    Int* num = createInt(b);
    multiplyInt(a, num, result);
    destroyInt(num);
    return result;
}

char* toString(const Int* a) {
    char* res = (char*)malloc(1000 * sizeof(char));
    int j, k;
    int* brr = a->arr;
    if (a->sign) {
        res[0] = '-';
        res[1] = '\0';
    } else {
        sprintf(res, "%d", brr[brr[0]]);
        for (int i = brr[0] - 1; i >= 1; i--) {
            k = max;
            for (j = 0; j < 9; j++) {
                sprintf(res + strlen(res), "%d", (brr[i] % k) / (k /= 10));
            }
        }
    }
    return res;
}

void set_size(int k) {
    size = k;
}

int num(const char* a) {
    int res = 0;
    for (int i = 0; i < strlen(a); i++) {
        res = res * 10 + (a[i] - '0');
    }
    return res;
}

char* str(int a) {
    char* res = (char*)malloc(1000 * sizeof(char));
    int h = (a < 0 ? 1 : 0);
    a = (a < 0 ? -a : a);
    int i = 0;
    while (a != 0) {
        res[i++] = (char)(a % 10 + '0');
        a /= 10;
    }
    if (i == 0) {
        res[i++] = '0';
    }
    if (h) {
        res[i++] = '-';
    }
    res[i] = '\0';
    return res;
}

Int* absInt(const Int* a) {
    Int* result = copyInt(a);
    if (compareString(result, "0") < 0) {
        negateInt(result, result);
    }
    return result;
}

int qanak;

Int* solve(const char* s, int h) {
    bool u[26] = { false };
    Int* answer = createInt("1");
    int k = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '?') {
            k++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            u[s[i] - 'A'] = true;
        }
    }
    for (int i = 0; i < k; ++i) {
        qanak++;
    }
    k = 0;
    for (int i = 0; i < 26; ++i) {
        if (u[i]) {
            k++;
        }
    }
    if (k > 10) {
        return createInt("0");
    }
    for (int i = 0; i < k; ++i) {
        multiplyString(answer, str(10 - i - h), answer);
    }
    return answer;
}

void mainFunction() {
    qanak = 0;
    set_size(12);
    Int* answer = createInt("0");
    char s[100];
    scanf("%s", s);
    if (strlen(s) == 1) {
        if (s[0] == '?' || (s[0] >= 'A' && s[0] <= 'Z')) {
            assignString(answer, "9");
        } else {
            assignString(answer, "1");
        }
        printf("%s\n", toString(answer));
        destroyInt(answer);
        return;
    }
    if (s[0] == '?') {
        char st[100];
        strcpy(st, s);
        memmove(st, st + 1, strlen(st));
        Int* temp = solve(st, 0);
        multiplyString(temp, "9", answer);
        destroyInt(temp);
    } else if (s[0] >= 'A' && s[0] <= 'Z') {
        for (int k = 1; k < 10; ++k) {
            char st[100];
            strcpy(st, s);
            qanak = 0;
            for (int i = 0; i < strlen(st); ++i) {
                if (st[i] == s[0]) {
                    st[i] = (char)('0' + k);
                }
            }
            Int* temp = solve(st, 1);
            addInt(answer, temp, answer);
            destroyInt(temp);
        }
    } else {
        solve(s, 0);
        multiplyString(answer, "9", answer);
    }
    printf("%s", toString(answer));
    for (int i = 0; i < qanak; ++i) {
        printf("0");
    }
    printf("\n");
    destroyInt(answer);
}

