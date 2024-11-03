#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char color;
    int digit;
} Card;

int count_unique(char cards[MAX_SIZE][3], int k) {
    char unique_chars[MAX_SIZE];
    int count = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        bool exists = false;
        for (int j = 0; j < count; j++) {
            if (cards[i][k] == unique_chars[j]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            unique_chars[count++] = cards[i][k];
        }
    }

    return count;
}

int count_bars(int a) {
    int count = 0;
    while (a > 0) {
        if (a & 1) {
            count++;
        }
        a >>= 1;
    }
    return count;
}

int main() {
    char cards[MAX_SIZE][3];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", cards[i]);
    }

    int cnt_unq_char = count_unique(cards, 0);
    int cnt_unq_digit = count_unique(cards, 1);

    char char_map[256];
    char_map['R'] = 0;
    char_map['G'] = 1;
    char_map['B'] = 2;
    char_map['Y'] = 3;
    char_map['W'] = 4;

    Card xs[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        xs[i].color = 1 << char_map[cards[i][0]];
        xs[i].digit = 1 << (cards[i][1] - '0');
    }

    int val = cnt_unq_char + cnt_unq_digit - 2;

    for (int i = 0; i < (1 << 6) - 1; i++) {
        int icnt = count_bars(i);
        if (icnt < val) {
            for (int j = 0; j < (1 << 6) - 1; j++) {
                int jcnt = count_bars(j);
                if (icnt + jcnt < val) {
                    bool flag = true;

                    for (int a = 0; a < n; a++) {
                        for (int b = 0; b < n; b++) {
                            if (a != b) {
                                int u = xs[a].color == xs[b].color || (icnt + 1 < cnt_unq_char && !(xs[a].color & i) && !(xs[b].color & i));
                                int v = xs[a].digit == xs[b].digit || (jcnt + 1 < cnt_unq_digit && !(xs[a].digit & j) && !(xs[b].digit & j));

                                if (v && u) {
                                    flag = false;
                                    break;
                                }
                            }
                        }
                    }
                    if (flag) {
                        val = icnt + jcnt;
                    }
                }
            }
        }
    }

    printf("%d\n", val);

    return 0;
}
