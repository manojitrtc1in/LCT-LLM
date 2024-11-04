#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000
#define MOD 1000000007LL

typedef long long int int64;

int64 b494(const char *str, const char *pat) {
    int len_str = strlen(str);
    int len_pat = strlen(pat);
    bool tag[MAX_LEN] = {false};
    int64 soln[MAX_LEN] = {0}, cum[MAX_LEN] = {0};
    
    for (int i = 0; i <= len_str - len_pat; i++) {
        if (strncmp(&str[i], pat, len_pat) == 0) {
            tag[i + len_pat - 1] = true;
        }
    }

    soln[0] = tag[0] ? 1 : 0;
    cum[0] = soln[0];

    size_t last = -1;
    int64 carry = 0;

    for (size_t i = 1; i < len_str; i++) {
        if (!tag[i]) {
            soln[i] = soln[i - 1] + (last < i ? carry : 0);
            soln[i] %= MOD;
            cum[i] = (soln[i] + cum[i - 1]) % MOD;
        } else {
            last = i;
            int j = 1 + i - len_pat;

            soln[i] = soln[i - 1] + 1 + j;
            if (j > 0) {
                soln[i] += cum[j - 1];
            }
            soln[i] %= MOD;
            cum[i] = (soln[i] + cum[i - 1]) % MOD;

            carry = (soln[i] - soln[i - 1] + MOD) % MOD;
        }
    }

    return (soln[len_str - 1] + MOD) % MOD;
}

size_t idiff(const char *a, const char *b, size_t k) {
    size_t n = (strlen(a) < strlen(b) ? strlen(a) : strlen(b)) + 1;
    for (size_t i = 0; i + 1 < (n < k ? n : k); i++) {
        if (a[i] != b[i]) {
            return i;
        }
    }
    return -1;
}

void bigger(char *a, char *b, const char *first, size_t len) {
    if (strlen(a) < strlen(b) + 1) {
        size_t k = idiff(first, b, len);
        if (strlen(a) < strlen(b) && k != (size_t)-1) {
            char temp[MAX_LEN];
            strcpy(temp, a);
            strcpy(a, b);
            strcpy(b, temp);
        } else if (strlen(a) == strlen(b) && k < idiff(first, a, len)) {
            char temp[MAX_LEN];
            strcpy(temp, a);
            strcpy(a, b);
            strcpy(b, temp);
        }
    }
}

bool startswith(const char *a, const char *b) {
    if (strlen(a) < strlen(b)) {
        return false;
    }
    return strncmp(a, b, strlen(b)) == 0;
}

void revmatch(size_t i, size_t j, const char str[2][MAX_LEN], const char *vir, char cache[MAX_LEN][MAX_LEN][MAX_LEN]) {
    if (i == strlen(str[0]) || j == strlen(str[1])) {
        return;
    }

    if (str[0][i] != str[1][j]) {
        revmatch(i + 1, j, str, vir, cache);
        revmatch(i, j + 1, str, vir, cache);
    } else {
        revmatch(i + 1, j + 1, str, vir, cache);
    }
}

char* b346(const char str[2][MAX_LEN], const char *vir) {
    static char result[MAX_LEN];
    char cache[MAX_LEN][MAX_LEN][MAX_LEN] = {{{0}}};

    revmatch(0, 0, str, vir, cache);
    strcpy(result, cache[0][0]);

    return (strlen(result) == 0) ? "0" : result;
}

int main() {
    char str[2][MAX_LEN];
    char vir[MAX_LEN];

    scanf("%s %s", str[0], vir);
    printf("%s", b346(str, vir));

    return EXIT_SUCCESS;
}
