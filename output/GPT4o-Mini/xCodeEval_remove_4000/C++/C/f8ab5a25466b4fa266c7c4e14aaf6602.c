#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* id0(long long n) {
    char* ans = (char*)malloc(21); // Enough for long long
    sprintf(ans, "%lld", n);
    return ans;
}

char* sum(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    
    char* result = (char*)malloc(max_len + 2); // +1 for carry, +1 for null terminator
    int carry = 0, index = 0;

    for (int i = 0; i < max_len; i++) {
        int digit_a = (len_a - 1 - i >= 0) ? a[len_a - 1 - i] - '0' : 0;
        int digit_b = (len_b - 1 - i >= 0) ? b[len_b - 1 - i] - '0' : 0;
        int sum = digit_a + digit_b + carry;
        result[index++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry) {
        result[index++] = carry + '0';
    }
    result[index] = '\0';

    // Reverse the result
    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - 1 - i];
        result[index - 1 - i] = temp;
    }
    return result;
}

char* multiply(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    char** vect = (char**)malloc(len_a * sizeof(char*));

    for (int i = 0; i < len_a; i++) {
        vect[i] = (char*)calloc(len_b + len_a + 1, sizeof(char)); // Enough space for result
        for (int j = 0; j < len_a - i - 1; j++) {
            vect[i][j] = '0';
        }
        for (int j = len_b - 1; j >= 0; j--) {
            int product = (a[len_a - 1 - i] - '0') * (b[j] - '0');
            sprintf(vect[i] + strlen(vect[i]), "%d", product);
        }
    }

    char* ans = id0(0);
    for (int i = 0; i < len_a; i++) {
        char* temp = sum(ans, vect[i]);
        free(ans);
        ans = temp;
    }
    for (int i = 0; i < len_a; i++) {
        free(vect[i]);
    }
    free(vect);
    return ans;
}

long long rec1(long long n) {
    long long ans = 0;
    if (n == 1) {
        for (int i = 0; i < 10; i++) {
            if (i != 0) ans++;
        }
    } else if (n == 2) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (i != 0 && i != k) ans++;
            }
        }
    } else if (n == 3) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    if (i != 0 && i != k && i != c && k != c) ans++;
    } else if (n == 4) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        if (i != 0 && i != k && i != c && i != d && k != c && k != d && c != d) ans++;
    } else if (n == 5) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            if (i != 0 && i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) ans++;
    } else if (n == 6) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                if (i != 0 && i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) ans++;
    } else if (n == 7) {
        for (int i = 1; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                for (int g = 0; g < 10; g++)
                                    if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) ans++;
    } else if (n == 8) {
        ans = 1632960;
    } else if (n == 9) {
        ans = 3265920;
    } else if (n == 10) {
        ans = 3265920;
    }
    return ans;
}

long long rec(long long n) {
    long long ans = 0;
    if (n == 1) {
        for (int i = 0; i < 10; i++) {
            ans++;
        }
    } else if (n == 2) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                if (i != k) ans++;
            }
        }
    } else if (n == 3) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    if (i != k && i != c && k != c) ans++;
    } else if (n == 4) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        if (i != k && i != c && i != d && k != c && k != d && c != d) ans++;
    } else if (n == 5) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            if (i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e) ans++;
    } else if (n == 6) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                if (i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f) ans++;
    } else if (n == 7) {
        for (int i = 0; i < 10; i++)
            for (int k = 0; k < 10; k++)
                for (int c = 0; c < 10; c++)
                    for (int d = 0; d < 10; d++)
                        for (int e = 0; e < 10; e++)
                            for (int f = 0; f < 10; f++)
                                for (int g = 0; g < 10; g++)
                                    if (i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g) ans++;
    } else if (n == 8) {
        ans = 1814400;
    } else if (n == 9) {
        ans = 3628800;
    } else if (n == 10) {
        ans = 3628800;
    }
    return ans;
}

int main() {
    char x[101];
    while (scanf("%s", x) != EOF) {
        char* ans = id0(1);
        int vis[101] = {0};

        long long CHn = 0;
        long long F = 0;
        for (int i = 0; i < strlen(x); i++) {
            if ((x[i] >= 'A' && x[i] <= 'J') && i != 0 && !vis[x[i] - 'A']) {
                CHn++;
                vis[x[i] - 'A'] = 1;
            } else if ((x[i] >= 'A' && x[i] <= 'J') && i == 0 && !vis[x[i] - 'A']) {
                F++;
                vis[x[i] - 'A'] = 1;
            }
        }

        long long Zeros = 0;
        if (x[0] == '?') {
            ans = id0(9);
        }
        for (int i = 1; i < strlen(x); i++) {
            if (x[i] == '?') {
                Zeros++;
            }
        }
        if (F != 0) {
            char* temp = multiply(id0(rec1(F + CHn)), ans);
            free(ans);
            ans = temp;
        } else if (CHn > 0) {
            char* temp = multiply(id0(rec(CHn)), ans);
            free(ans);
            ans = temp;
        }

        printf("%s", ans);
        for (int i = 0; i < Zeros; i++) {
            printf("0");
        }
        printf("\n");
        free(ans);
    }
    return 0;
}
