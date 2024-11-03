#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#define DEBUG(x) printf("%s: %lld\n", #x, x)

typedef long long int int64;
typedef unsigned long long int uint64;

void b303() {
    int64 n, m, x, y, a, b;
    scanf("%lld %lld %lld %lld %lld %lld", &n, &m, &x, &y, &a, &b);

    int64 g = gcd(a, b);
    a /= g;
    b /= g;

    DEBUG(g);
    DEBUG(a);
    DEBUG(b);

    int64 k = min(m / b, n / a);
    int64 width = k * a;
    int64 height = k * b;

    DEBUG(k);
    DEBUG(width);
    DEBUG(height);

    int64 x1 = max(x - (width + 1) / 2, 0LL);
    int64 x2 = min(x1 + width, n);
    x1 = x2 - width;

    int64 y1 = max(y - (height + 1) / 2, 0LL);
    int64 y2 = min(y1 + height, m);
    y1 = y2 - height;

    printf("%lld %lld %lld %lld\n", x1, y1, x2, y2);
}

const char* b198() {
    size_t n, k;
    scanf("%zu %zu", &n, &k);
    char wall[2][n + 1];
    scanf("%s %s", wall[0], wall[1]);

    int tag[2][n];
    memset(tag, 0, sizeof(tag));

    tag[0][0] = 1;
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 1; j < n; j++) {
            if (wall[i][j] == 'X') {
                tag[i][j] = 1;
                continue;
            }
            if (j >= k && tag[i][j - k]) {
                tag[i][j] = 1;
            } else if (j >= k - 1 && tag[1 - i][j - k + 1]) {
                tag[i][j] = 1;
            } else if (j >= k + 1 && tag[1 - i][j - k - 1]) {
                tag[i][j] = 1;
            }
        }
    }

    return tag[0][n - 1] ? "YES" : "NO";
}

size_t a442() {
    char xs[100000];
    scanf("%s", xs);

    int char_map[26][26] = {0};
    int digit_map[10][10] = {0};
    size_t n = strlen(xs);

    for (size_t i = 0; i < n - 1; i++) {
        char_map[xs[i] - 'a'][xs[i + 1] - 'a'] = 1;
        digit_map[xs[i] - '0'][xs[i + 1] - '0'] = 1;
    }

    size_t char_count = 0, digit_count = 0;
    for (size_t i = 0; i < 26; i++) {
        size_t char_sum = 0, digit_sum = 0;
        for (size_t j = 0; j < 26; j++) {
            char_sum += char_map[i][j];
            digit_sum += digit_map[i][j];
        }
        if (char_sum > 0 && digit_sum == 0) {
            char_count++;
        }
    }

    for (size_t i = 0; i < 10; i++) {
        size_t char_sum = 0, digit_sum = 0;
        for (size_t j = 0; j < 10; j++) {
            char_sum += char_map[i][j];
            digit_sum += digit_map[i][j];
        }
        if (digit_sum > 0 && char_sum == 0) {
            digit_count++;
        }
    }

    return min(digit_count + (char_count < 26 ? 26 - char_count : 0),
               char_count + (digit_count < 10 ? 10 - digit_count : 0));
}

uint64 a163() {
    char subj[100001];
    char targ[100001];
    scanf("%s %s", subj, targ);

    size_t pos[26][100001] = {0};
    size_t n = strlen(subj);

    for (size_t i = 0; i < n; i++) {
        pos[subj[i] - 'a'][i] = 1;
    }

    uint64 val = 0;
    uint64 soln[100001] = {0};
    uint64 id12[100001] = {0};
    const uint64 m = 1000000007ULL;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < 26; j++) {
            if (pos[j][i]) {
                soln[i + 1] = (1 + id12[i]) % m;
            }
        }
        for (size_t j = 1; j <= i + 1; j++) {
            id12[j] = (id12[j] + soln[j]) % m;
        }
        val = (val + soln[i + 1]) % m;
    }

    return val;
}

int main(const int argc, char* argv[]) {
    printf("%llu\n", a163());

    return EXIT_SUCCESS;
}
