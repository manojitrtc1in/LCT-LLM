#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 12
#define MAX_INT 1000000000

typedef struct {
    int *arr;
    int sign;
    int size;
} Int;

Int create_int(const char *a);
void free_int(Int *a);
Int int_copy(const Int *a);
Int int_assign(Int *a, const Int *b);
Int int_assign_str(Int *a, const char *b);
int int_greater(const Int *a, const Int *b);
int int_less(const Int *a, const Int *b);
int int_equal(const Int *a, const Int *b);
Int int_negate(const Int *a);
Int int_add(Int *a, const Int *b);
Int int_subtract(Int *a, const Int *b);
Int int_multiply(Int *a, const Int *b);
void int_print(const Int *a);
void int_set_size(Int *a, int size);
int int_num(const char *a);
char* int_str(int a);
Int solve(const char *s, int h);

int qanak;

Int create_int(const char *a) {
    Int result;
    result.arr = (int *)malloc((MAX_SIZE + 1) * sizeof(int));
    for (int i = 0; i <= MAX_SIZE; i++)
        result.arr[i] = 0;
    result.sign = 0;
    if (a[0] == '-') {
        result.sign = 1;
        a++;
    }
    result.arr[0] = 0;
    while (strlen(a) > 9) {
        result.arr[0]++;
        result.arr[result.arr[0]] = int_num(strndup(a + strlen(a) - 9, 9));
        a[strlen(a) - 9] = '\0';
    }
    result.arr[0]++;
    result.arr[result.arr[0]] = int_num(a);
    return result;
}

void free_int(Int *a) {
    free(a->arr);
}

Int int_copy(const Int *a) {
    Int result = create_int("0");
    result.arr[0] = a->arr[0];
    for (int i = 1; i <= result.arr[0]; i++)
        result.arr[i] = a->arr[i];
    result.sign = a->sign;
    return result;
}

Int int_assign(Int *a, const Int *b) {
    if (a != b) {
        free(a->arr);
        *a = int_copy(b);
    }
    return *a;
}

Int int_assign_str(Int *a, const char *b) {
    return int_assign(a, &create_int(b));
}

int int_greater(const Int *a, const Int *b) {
    if (a->sign != b->sign)
        return a->sign < b->sign;
    if (a->sign == 0) {
        if (a->arr[0] != b->arr[0])
            return a->arr[0] > b->arr[0];
        for (int i = a->arr[0]; i >= 1; i--)
            if (a->arr[i] != b->arr[i])
                return a->arr[i] > b->arr[i];
        return 0;
    }
    if (a->arr[0] != b->arr[0])
        return a->arr[0] < b->arr[0];
    for (int i = a->arr[0]; i >= 1; i--)
        if (a->arr[i] != b->arr[i])
            return a->arr[i] < b->arr[i];
    return 0;
}

int int_less(const Int *a, const Int *b) {
    return int_greater(b, a);
}

int int_equal(const Int *a, const Int *b) {
    return !(int_greater(a, b) || int_less(a, b));
}

Int int_negate(const Int *a) {
    Int result = int_copy(a);
    result.sign = (result.sign + 1) % 2;
    return result;
}

Int int_add(Int *a, const Int *b) {
    int carry = 0;
    Int result = create_int("0");
    if (int_less(a, &(Int){"0"})) {
        if (int_less(b, &(Int){"0"})) {
            if (a->arr[0] >= b->arr[0]) {
                for (int i = 1; i <= b->arr[0]; i++) {
                    result.arr[i] = a->arr[i] + b->arr[i] + carry;
                    carry = result.arr[i] / MAX_INT;
                    result.arr[i] %= MAX_INT;
                }
                while (carry) {
                    result.arr[result.arr[0] + 1] = carry;
                    carry = result.arr[result.arr[0]] / MAX_INT;
                    result.arr[result.arr[0]] %= MAX_INT;
                    result.arr[0]++;
                }
                if (result.arr[0] == a->arr[0] + 2)
                    result.arr[0]++;
            } else {
                Int c = int_copy(a);
                Int d = int_copy(b);
                result = int_add(&d, &c);
            }
        } else {
            if (int_equal(a, &(Int){"0"}))
                return create_int("0");
            else if (int_greater(int_negate(a), b)) {
                for (int i = 1; i <= b->arr[0]; i++) {
                    result.arr[i] = a->arr[i] - b->arr[i] + carry;
                    if (result.arr[i] < 0) {
                        carry = -1;
                        result.arr[i] += MAX_INT;
                    } else
                        carry = 0;
                }
                while (carry) {
                    result.arr[result.arr[0] + 1] = result.arr[result.arr[0]] + carry;
                    if (result.arr[result.arr[0]] < 0) {
                        carry = -1;
                        result.arr[result.arr[0]] += MAX_INT;
                    } else
                        carry = 0;
                    result.arr[0]++;
                }
                while (result.arr[result.arr[0]] == 0 && result.arr[0] > 1)
                    result.arr[0]--;
            } else {
                Int c = int_copy(a);
                Int d = int_copy(b);
                result = int_add(&d, &c);
            }
        }
    } else {
        if (int_less(b, &(Int){"0"})) {
            if (int_equal(a, int_negate(b)))
                return create_int("0");
            else if (int_greater(a, int_negate(b))) {
                for (int i = 1; i <= b->arr[0]; i++) {
                    result.arr[i] = a->arr[i] - b->arr[i] + carry;
                    if (result.arr[i] < 0) {
                        carry = -1;
                        result.arr[i] += MAX_INT;
                    } else
                        carry = 0;
                }
                while (carry) {
                    result.arr[result.arr[0] + 1] = result.arr[result.arr[0]] + carry;
                    if (result.arr[result.arr[0]] < 0) {
                        carry = -1;
                        result.arr[result.arr[0]] += MAX_INT;
                    } else
                        carry = 0;
                    result.arr[0]++;
                }
                while (result.arr[result.arr[0]] == 0 && result.arr[0] > 1)
                    result.arr[0]--;
            } else {
                Int c = int_copy(a);
                Int d = int_copy(b);
                result = int_add(&d, &c);
            }
        } else {
            Int c = int_negate(a);
            Int d = int_negate(b);
            result = int_negate(int_add(&d, &c));
        }
    }
    return result;
}

Int int_subtract(Int *a, const Int *b) {
    return int_add(a, &int_negate(b));
}

Int int_multiply(Int *a, const Int *b) {
    int i;
    Int result = create_int("0");
    if (int_equal(b, &(Int){"0"}))
        return create_int("0");
    else if (int_equal(b, int_str(MAX_INT)))
        if (!int_equal(a, &(Int){"0"})) {
            for (i = a->arr[0]; i >= 1; i--)
                a->arr[i + 1] = a->arr[i];
            a->arr[1] = 0;
            a->arr[0]++;
        }
    else if (int_less(&(Int){"0"}, b) && int_less(b, int_str(MAX_INT))) {
        long long tmp;
        int carry = 0;
        for (i = 1; i <= a->arr[0]; i++) {
            tmp = (long long)a->arr[i] * (long long)b->arr[1] + (long long)carry;
            a->arr[i] = tmp % (long long)MAX_INT;
            carry = tmp / (long long)MAX_INT;
        }
        if (carry) {
            a->arr[i] = carry;
            a->arr[0]++;
        }
    } else {
        Int tmp, res = create_int("0");
        for (i = b->arr[0]; i >= 1; i--) {
            tmp = int_multiply(a, int_str(b->arr[i]));
            res = int_add(&res, &tmp);
        }
        *a = res;
    }
    a->sign = (a->sign + b->sign) % 2;
    return *a;
}

void int_print(const Int *a) {
    if (a->sign)
        printf("-");
    printf("%d", a->arr[a->arr[0]]);
    for (int i = a->arr[0] - 1; i >= 1; i--) {
        int k = MAX_INT;
        for (int j = 0; j < 9; j++)
            printf("%d", (a->arr[i] % k) / (k /= 10));
    }
}

int int_num(const char *a) {
    int res = 0;
    for (int i = 0; i < strlen(a); i++)
        res = res * 10 + (a[i] - '0');
    return res;
}

char* int_str(int a) {
    char *res = (char *)malloc(12 * sizeof(char));
    int h = (a < 0 ? 1 : 0);
    a = (a < 0 ? -a : a);
    int index = 0;
    while (a != 0) {
        res[index++] = (char)(a % 10 + '0');
        a /= 10;
    }
    if (index == 0)
        res[index++] = '0';
    if (h)
        res[index++] = '-';
    res[index] = '\0';
    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = res[i];
        res[i] = res[index - i - 1];
        res[index - i - 1] = temp;
    }
    return res;
}

Int solve(const char *s, int h) {
    int u[26] = {0};
    Int answer = create_int("1");
    int k = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '?')
            k++;
        if (s[i] >= 'A' && s[i] <= 'Z')
            u[s[i] - 'A'] = 1;
    }
    for (int i = 0; i < k; ++i)
        qanak++;

    k = 0;
    for (int i = 0; i < 26; ++i)
        if (u[i])
            k++;
    if (k > 10)
        return create_int("0");
    for (int i = 0; i < k; ++i)
        answer = int_multiply(&answer, int_str(10 - i - h));
    return answer;
}

int main() {
    qanak = 0;
    Int answer = create_int("0");
    char s[100];
    scanf("%s", s);
    if (strlen(s) == 1) {
        if (s[0] == '?' || (s[0] >= 'A' && s[0] <= 'Z'))
            answer = create_int("9");
        else
            answer = create_int("1");
        int_print(&answer);
        printf("\n");
        return 0;
    }
    if (s[0] == '?') {
        char st[100];
        strcpy(st, s + 1);
        answer = int_multiply(&create_int("9"), &solve(st, 0));
    } else if (s[0] >= 'A' && s[0] <= 'Z') {
        for (int k = 1; k < 10; ++k) {
            char st[100];
            strcpy(st, s);
            qanak = 0;
            for (int i = 0; i < strlen(st); ++i)
                if (st[i] == s[0])
                    st[i] = (char)('0' + k);
            answer = int_add(&answer, &solve(st, 1));
        }
    } else {
        answer = solve(s, 0);
    }
    int_print(&answer);
    for (int i = 0; i < qanak; ++i)
        printf("0");
    printf("\n");
    free_int(&answer);
    return 0;
}
