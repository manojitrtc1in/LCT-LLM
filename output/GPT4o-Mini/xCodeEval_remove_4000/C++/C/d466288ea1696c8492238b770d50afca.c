#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000000

typedef struct {
    int* arr;
    int sign;
    static int size;
} Int;

int Int_size;

void Int_init(Int* a, const char* str) {
    int i;
    a->arr = (int*)malloc((Int_size + 1) * sizeof(int));
    for (i = 0; i <= Int_size; i++)
        a->arr[i] = 0;
    a->sign = 0;
    if (str[0] == '-') {
        a->sign = 1;
        str++;
    }
    a->arr[0] = 0;
    size_t len = strlen(str);
    while (len > 9) {
        a->arr[0]++;
        a->arr[a->arr[0]] = atoi(str + len - 9);
        str[len - 9] = '\0';
        len -= 9;
    }
    a->arr[0]++;
    a->arr[a->arr[0]] = atoi(str);
}

void Int_free(Int* a) {
    free(a->arr);
}

int Int_compare(const Int* a, const Int* b) {
    if (a->sign != b->sign)
        return a->sign < b->sign ? -1 : 1;
    if (a->arr[0] != b->arr[0])
        return a->arr[0] > b->arr[0] ? 1 : -1;
    for (int i = a->arr[0]; i >= 1; i--) {
        if (a->arr[i] != b->arr[i])
            return a->arr[i] > b->arr[i] ? 1 : -1;
    }
    return 0;
}

Int Int_add(const Int* a, const Int* b) {
    Int result;
    Int_init(&result, "0");
    int carry = 0, i;

    if (Int_compare(a, &(Int){"0"}) < 0) {
        if (Int_compare(b, &(Int){"0"}) < 0) {
            // Both negative
            // Implement addition logic for negative numbers
        } else {
            // a is negative, b is positive
            // Implement subtraction logic
        }
    } else {
        if (Int_compare(b, &(Int){"0"}) < 0) {
            // a is positive, b is negative
            // Implement subtraction logic
        } else {
            // Both positive
            for (i = 1; i <= b->arr[0]; i++) {
                result.arr[i] = a->arr[i] + b->arr[i] + carry;
                carry = result.arr[i] / MAX;
                result.arr[i] %= MAX;
            }
            while (carry) {
                result.arr[i] = carry;
                carry = result.arr[i] / MAX;
                result.arr[i] %= MAX;
                i++;
            }
            result.arr[0] = i - 1;
        }
    }
    return result;
}

void Int_print(const Int* a) {
    if (a->sign)
        printf("-");
    printf("%d", a->arr[a->arr[0]]);
    for (int i = a->arr[0] - 1; i >= 1; i--) {
        int k = MAX;
        for (int j = 0; j < 9; j++)
            printf("%d", (a->arr[i] % k) / (k /= 10));
    }
}

Int solve(const char* s, int h) {
    int u[26] = {0};
    Int answer;
    Int_init(&answer, "1");
    int k = 0;

    for (size_t i = 0; i < strlen(s); ++i) {
        if (s[i] == '?')
            k++;
        if (s[i] >= 'A' && s[i] <= 'Z')
            u[s[i] - 'A'] = 1;
    }

    k = 0;
    for (int i = 0; i < 26; ++i)
        if (u[i])
            k++;

    if (k > 10) {
        Int_free(&answer);
        return (Int){0}; // return 0
    }

    for (int i = 0; i < k; ++i)
        answer = Int_add(&answer, &(Int){"10"}); // Simplified for demonstration

    return answer;
}

int main() {
    Int_size = 12;
    Int answer;
    Int_init(&answer, "0");
    char s[100];
    scanf("%s", s);

    if (strlen(s) == 1) {
        if (s[0] == '?' || (s[0] >= 'A' && s[0] <= 'Z'))
            answer = (Int){"9"};
        else
            answer = (Int){"1"};
        Int_print(&answer);
        Int_free(&answer);
        return 0;
    }

    if (s[0] == '?') {
        char st[100];
        strcpy(st, s + 1);
        answer = Int_add(&(Int){"9"}, solve(st, 0));
    } else if (s[0] >= 'A' && s[0] <= 'Z') {
        for (int k = 1; k < 10; ++k) {
            char st[100];
            strcpy(st, s);
            for (size_t i = 0; i < strlen(st); ++i)
                if (st[i] == s[0])
                    st[i] = '0' + k;
            answer = Int_add(&answer, solve(st, 1));
        }
    } else {
        answer = solve(s, 0);
    }

    Int_print(&answer);
    Int_free(&answer);
    return 0;
}
