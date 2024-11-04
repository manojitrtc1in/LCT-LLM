#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

typedef long long int int64;

#define MAX_CARDS 100
#define MAX_UNIQUE 6

typedef struct {
    int color;
    int digit;
} Card;

Card cards[MAX_CARDS];
size_t card_count = 0;

size_t count_unique(char *arr, size_t k) {
    bool seen[256] = { false };
    size_t count = 0;

    for (size_t i = 0; i < card_count; i++) {
        if (!seen[arr[i * 2 + k]]) {
            seen[arr[i * 2 + k]] = true;
            count++;
        }
    }
    return count;
}

size_t count_bars(size_t a) {
    size_t k = 0;
    while (a > 0) {
        k += a & 1;
        a >>= 1;
    }
    return k;
}

size_t a442() {
    size_t cnt_unq_char = count_unique((char *)cards, 0);
    size_t cnt_unq_digit = count_unique((char *)cards, 1);

    size_t val = cnt_unq_char + cnt_unq_digit - 2;

    for (size_t i = 0; i < (1 << 6) - 1; ++i) {
        size_t icnt = count_bars(i);
        if (icnt < val) {
            for (size_t j = 0; j < (1 << 6) - 1; ++j) {
                size_t jcnt = count_bars(j);
                if (icnt + jcnt < val) {
                    bool flag = true;

                    for (size_t a = 0; a < card_count; a++) {
                        for (size_t b = 0; b < card_count; b++) {
                            if (a != b) {
                                bool u = (cards[a].color == cards[b].color) ||
                                         (icnt + 1 < cnt_unq_char && !(i & (1 << cards[a].color)) && !(i & (1 << cards[b].color)));

                                bool v = (cards[a].digit == cards[b].digit) ||
                                         (jcnt + 1 < cnt_unq_digit && !(j & (1 << cards[a].digit)) && !(j & (1 << cards[b].digit)));

                                if (v && u) {
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        if (!flag) break;
                    }
                    if (flag) {
                        val = icnt + jcnt;
                    }
                }
            }
        }
    }

    return val;
}

int main() {
    // Example input
    card_count = 3;
    cards[0] = (Card){0, 1}; // R0
    cards[1] = (Card){1, 2}; // G1
    cards[2] = (Card){2, 0}; // B2

    printf("%zu\n", a442());

    return EXIT_SUCCESS;
}
