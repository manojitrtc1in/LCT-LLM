#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char color;
    int number;
} Card;

int count_unique(char cards[MAX_SIZE][3], int k) {
    char unique_chars[MAX_SIZE];
    int count = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        bool found = false;
        for (int j = 0; j < count; j++) {
            if (cards[i][k] == unique_chars[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique_chars[count] = cards[i][k];
            count++;
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

int a442() {
    char cards[MAX_SIZE][3];
    for (int i = 0; i < MAX_SIZE; i++) {
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

    int xs[MAX_SIZE][2];
    for (int i = 0; i < MAX_SIZE; i++) {
        xs[i][0] = 1 << char_map[cards[i][0]];
        xs[i][1] = 1 << (cards[i][1] - '0');
    }

    int val = cnt_unq_char + cnt_unq_digit - 2;

    for (int i = 0; i < (1 << 6) - 1; i++) {
        int icnt = count_bars(i);
        if (icnt < val) {
            for (int j = 0; j < (1 << 6) - 1; j++) {
                int jcnt = count_bars(j);
                if (icnt + jcnt < val) {
                    bool flag = true;

                    for (int a = 0; a < MAX_SIZE; a++) {
                        for (int b = 0; b < MAX_SIZE; b++) {
                            if (a != b) {
                                int u = xs[a][0] == xs[b][0] || (icnt + 1 < cnt_unq_char && !(xs[a][0] & i) && !(xs[b][0] & i));
                                int v = xs[a][1] == xs[b][1] || (jcnt + 1 < cnt_unq_digit && !(xs[a][1] & j) && !(xs[b][1] & j));
                                if (u && v) {
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        if (!flag) {
                            break;
                        }
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
    printf("%d\n", a442());

    return 0;
}
