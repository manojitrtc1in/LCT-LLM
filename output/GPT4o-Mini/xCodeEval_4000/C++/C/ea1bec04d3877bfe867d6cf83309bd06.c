#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define C 100
#define DELIMS ",.?!\"\\/|#“”@*"
#define EPS 1E-9

typedef struct {
    char word[100];
    double value;
} WordValue;

WordValue cat[3 * C] = {
    {"dealers", 0.0038157536113382394},
    {"customer", 0.0010902153175252113},
    {"dealer", 9.539384028345599E-4},
    {"of", 0.034750613246116106},
    {"given", 0.0012264922322158627},
    {"futures", 8.176614881439084E-4},
    // ... (remaining entries omitted for brevity)
    {"trade", 0.019595693594609248},
    {"issue", 9.294400123925335E-4},
    {"goods", 0.002710866702811556},
    {"baldrige", 0.001006893346758578},
    {"chirac", 8.51986678026489E-4},
    {"war", 0.0027883200371776004},
    {"japan", 0.009914026798853691},
    {"chip", 0.002865773371543645},
    {"is", 0.008364960111532802},
    {"export", 8.51986678026489E-4},
    {"agreement", 0.0033304933777399117},
    {"expected", 0.0014716133529548447},
    {"yeutter", 0.0010843466811246223},
    {"democratic", 9.294400123925335E-4},
    {"act", 8.51986678026489E-4},
    {"yasuhiro", 0.001006893346758578},
};

char buf[1100000];
double p[3];
int sel;

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    for (int i = 0; i < 3 * C; i++) {
        // No need to parse as we already have the data in the array
    }

    fgets(buf, sizeof(buf), stdin);
    char text[1100000] = "";
    while (fgets(buf, sizeof(buf), stdin)) {
        strcat(text, buf);
        strcat(text, " ");
    }

    for (int i = 0; i < strlen(text); i++) {
        if (strchr(DELIMS, text[i]) != NULL) {
            text[i] = ' ';
        }
    }

    char *tok = strtok(text, " ");
    while (tok != NULL) {
        for (int i = 0; tok[i]; i++) {
            tok[i] = tolower(tok[i]);
        }

        for (int i = 0; i < 3; i++) {
            int found = 0;
            for (int j = 0; j < C; j++) {
                if (strcmp(cat[j + i * C].word, tok) == 0) {
                    p[i] += log(cat[j + i * C].value);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                p[i] += log(1E-6);
            }
        }

        tok = strtok(NULL, " ");
    }

    sel = 0;
    for (int i = 1; i < 3; i++) {
        if (p[i] > p[sel] + EPS) {
            sel = i;
        }
    }

    printf("%d\n", sel + 1);

    return 0;
}
