#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 12

typedef struct {
    int* arr;
    int sign;
} Int;

int size;
int max = 1000000000;

Int* createInt() {
    Int* a = (Int*)malloc(sizeof(Int));
    a->arr = (int*)calloc(size + 1, sizeof(int));
    a->sign = 0;
    return a;
}

Int* createIntFromString(char* a) {
    Int* num = createInt();
    int i;
    num->arr[0] = 0;
    if (a[0] == '-') {
        num->sign = 1;
        memmove(a, a + 1, strlen(a));
    }
    while (strlen(a) > 9) {
        num->arr[0]++;
        num->arr[num->arr[0]] = atoi(a + strlen(a) - 9);
        a[strlen(a) - 9] = '\0';
    }
    num->arr[0]++;
    num->arr[num->arr[0]] = atoi(a);
    return num;
}

Int* copyInt(Int* a) {
    Int* copy = createInt();
    copy->arr[0] = a->arr[0];
    for (int i = 1; i <= copy->arr[0]; i++) {
        copy->arr[i] = a->arr[i];
    }
    copy->sign = a->sign;
    return copy;
}

void destroyInt(Int* a) {
    free(a->arr);
    free(a);
}

Int* assignInt(Int* a, Int* b) {
    if (a != b) {
        destroyInt(a);
        a = copyInt(b);
    }
    return a;
}

void assignIntFromString(Int* a, char* b) {
    assignInt(a, createIntFromString(b));
}

bool greaterThanInt(Int* a, Int* b) {
    int* brr = b->arr;
    if (a->sign != b->sign) {
        return a->sign < b->sign;
    }
    if (a->sign == 0) {
        if (a->arr[0] != brr[0]) {
            return a->arr[0] > brr[0];
        }
        for (int i = a->arr[0]; i >= 1; i--) {
            if (a->arr[i] != brr[i]) {
                return a->arr[i] > brr[i];
            }
        }
        return false;
    }
    if (a->arr[0] != brr[0]) {
        return a->arr[0] < brr[0];
    }
    for (int i = a->arr[0]; i >= 1; i--) {
        if (a->arr[i] != brr[i]) {
            return a->arr[i] < brr[i];
        }
    }
    return false;
}

bool lessThanInt(Int* a, Int* b) {
    return greaterThanInt(b, a);
}

bool equalToInt(Int* a, Int* b) {
    return !(greaterThanInt(a, b) || lessThanInt(a, b));
}

bool notEqualToInt(Int* a, Int* b) {
    return !equalToInt(a, b);
}

bool lessThanOrEqualToInt(Int* a, Int* b) {
    return !greaterThanInt(a, b);
}

bool greaterThanOrEqualToInt(Int* a, Int* b) {
    return !lessThanInt(a, b);
}

Int* negateInt(Int* a) {
    Int* c = copyInt(a);
    c->sign = (a->sign + 1) % 2;
    return c;
}

Int* addInt(Int* a, Int* b) {
    int* brr = b->arr;
    int carry = 0;
    int i;

    if (lessThanInt(a, createIntFromString("0"))) {
        if (lessThanInt(b, createIntFromString("0"))) {
            if (a->arr[0] >= brr[0]) {
                for (i = 1; i <= brr[0]; i++) {
                    a->arr[i] = a->arr[i] + brr[i] + carry;
                    carry = a->arr[i] / max;
                    a->arr[i] %= max;
                }
                while (carry) {
                    i++;
                    a->arr[i] = a->arr[i] + carry;
                    carry = a->arr[i] / max;
                    a->arr[i] %= max;
                }
                if (i == a->arr[0] + 2) {
                    a->arr[0]++;
                }
            } else {
                Int* c = copyInt(a);
                Int* d = copyInt(b);
                assignInt(a, addInt(d, c));
                destroyInt(c);
                destroyInt(d);
            }
        } else {
            if (equalToInt(a, negateInt(b))) {
                assignInt(a, createIntFromString("0"));
            } else if (lessThanInt(negateInt(a), b)) {
                for (i = 1; i <= brr[0]; i++) {
                    a->arr[i] = a->arr[i] - brr[i] + carry;
                    if (a->arr[i] < 0) {
                        carry = -1;
                        a->arr[i] += max;
                    } else {
                        carry = 0;
                    }
                }
                while (carry) {
                    i++;
                    a->arr[i] = a->arr[i] + carry;
                    if (a->arr[i] < 0) {
                        carry = -1;
                        a->arr[i] += max;
                    } else {
                        carry = 0;
                    }
                }
                while (a->arr[a->arr[0]] == 0 && a->arr[0] > 1) {
                    a->arr[0]--;
                }
            } else {
                Int* c = copyInt(a);
                Int* d = copyInt(b);
                assignInt(a, addInt(d, c));
                destroyInt(c);
                destroyInt(d);
            }
        }
    } else {
        if (lessThanInt(b, createIntFromString("0"))) {
            if (equalToInt(a, negateInt(b))) {
                assignInt(a, createIntFromString("0"));
            } else if (greaterThanInt(a, negateInt(b))) {
                for (i = 1; i <= brr[0]; i++) {
                    a->arr[i] = a->arr[i] - brr[i] + carry;
                    if (a->arr[i] < 0) {
                        carry = -1;
                        a->arr[i] += max;
                    } else {
                        carry = 0;
                    }
                }
                while (carry) {
                    i++;
                    a->arr[i] = a->arr[i] + carry;
                    if (a->arr[i] < 0) {
                        carry = -1;
                        a->arr[i] += max;
                    } else {
                        carry = 0;
                    }
                }
                while (a->arr[a->arr[0]] == 0 && a->arr[0] > 1) {
                    a->arr[0]--;
                }
            } else {
                Int* c = copyInt(a);
                Int* d = copyInt(b);
                assignInt(a, addInt(d, c));
                destroyInt(c);
                destroyInt(d);
            }
        } else {
            Int* c = negateInt(a);
            Int* d = negateInt(b);
            assignInt(a, negateInt(addInt(d, c)));
            destroyInt(c);
            destroyInt(d);
        }
    }
    return a;
}

Int* addIntFromString(Int* a, char* b) {
    return addInt(a, createIntFromString(b));
}

Int* subtractInt(Int* a, Int* b) {
    return addInt(a, negateInt(b));
}

Int* subtractIntFromString(Int* a, char* b) {
    return subtractInt(a, createIntFromString(b));
}

Int* multiplyInt(Int* a, Int* b) {
    if (equalToInt(b, createIntFromString("0"))) {
        assignInt(a, createIntFromString("0"));
    } else if (equalToInt(b, createIntFromString("1000000000"))) {
        if (!equalToInt(a, createIntFromString("0"))) {
            for (int i = a->arr[0]; i >= 1; i--) {
                a->arr[i + 1] = a->arr[i];
            }
            a->arr[1] = 0;
            a->arr[0]++;
        }
    } else if (lessThanInt(absInt(b), createIntFromString("1000000000"))) {
        long long tmp;
        int carry = 0;
        int* brr = b->arr;
        for (int i = 1; i <= a->arr[0]; i++) {
            tmp = (long long)a->arr[i] * (long long)brr[1] + (long long)carry;
            a->arr[i] = tmp % (long long)max;
            carry = tmp / (long long)max;
        }
        if (carry) {
            a->arr[a->arr[0] + 1] = carry;
            a->arr[0]++;
        }
    } else {
        Int* tmp = createIntFromString("0");
        Int* res = createIntFromString("0");
        int* brr = b->arr;
        for (int i = brr[0]; i >= 1; i--) {
            multiplyInt(tmp, a);
            multiplyInt(tmp, createIntFromString("1000000000"));
            addInt(res, tmp);
        }
        assignInt(a, res);
        destroyInt(tmp);
        destroyInt(res);
    }
    a->sign = (a->sign + b->sign) % 2;
    return a;
}

Int* multiplyIntFromString(Int* a, char* b) {
    return multiplyInt(a, createIntFromString(b));
}

Int* absInt(Int* a) {
    if (lessThanInt(a, createIntFromString("0"))) {
        return negateInt(a);
    }
    return a;
}

int numInt(char* a) {
    return atoi(a);
}

char* strInt(int a) {
    char* res = (char*)malloc(12 * sizeof(char));
    int h = (a < 0 ? 1 : 0);
    a = (a < 0 ? -a : a);
    sprintf(res, "%d", a);
    if (strlen(res) == 0) {
        strcpy(res, "0");
    }
    if (h) {
        char* temp = (char*)malloc((strlen(res) + 2) * sizeof(char));
        strcpy(temp, "-");
        strcat(temp, res);
        free(res);
        return temp;
    }
    return res;
}

void setSize(int k) {
    size = k;
}

int qanak;

Int* solve(char* s, int h) {
    bool u[26] = { false };
    Int* answer = createIntFromString("1");
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
        return createIntFromString("0");
    }
    for (int i = 0; i < k; ++i) {
        Int* temp = createIntFromString(strInt(10 - i - h));
        multiplyInt(answer, temp);
        destroyInt(temp);
    }
    return answer;
}

int main() {
    qanak = 0;
    setSize(MAX_SIZE);
    Int* answer = createIntFromString("0");
    char s[100];
    scanf("%s", s);
    if (strlen(s) == 1) {
        if (s[0] == '?' || (s[0] >= 'A' && s[0] <= 'Z')) {
            answer = createIntFromString("9");
        } else {
            answer = createIntFromString("1");
        }
        printf("%s\n", strInt(answer->arr[1]));
        return 0;
    }
    if (s[0] == '?') {
        char st[100];
        strcpy(st, s + 1);
        answer = multiplyIntFromString(createIntFromString("9"), solve(st));
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
            addInt(answer, temp);
            destroyInt(temp);
        }
    } else {
        answer = solve(s);
    }
    printf("%s", strInt(answer->arr[answer->arr[0]]));
    for (int i = 0; i < qanak; ++i) {
        printf("0");
    }
    printf("\n");
    return 0;
}
