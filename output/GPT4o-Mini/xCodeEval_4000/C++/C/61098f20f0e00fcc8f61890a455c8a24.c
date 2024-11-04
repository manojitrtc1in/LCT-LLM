#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define C 100
#define DELIMS ",.?!\"\\/|#“”@*"
#define EPS 1E-9

typedef long long int64;

char buf[1100000];
double ma[3][C][2]; // Store word and its probability
double p[10];
int sel;

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    const char *cat[3 * C] = {
        "dealers 0.0038157536113382394",
        "customer 0.0010902153175252113",
        // ... (rest of the entries)
        "yasuhiro 0.001006893346758578",
    };

    for (int i = 0; i < 3 * C; i++) {
        char word[100];
        double x;
        sscanf(cat[i], "%s %lf", word, &x);
        strcpy(ma[i / C][i % C][0], word);
        ma[i / C][i % C][1] = x;
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
        for (int i = 0; i < strlen(tok); i++) {
            tok[i] = tolower(tok[i]);
        }

        for (int i = 0; i < 3; i++) {
            int found = 0;
            for (int j = 0; j < C; j++) {
                if (strcmp(ma[i][j][0], tok) == 0) {
                    p[i] += log(ma[i][j][1]);
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

    sel = 1;
    for (int i = 2; i >= 0; i--) {
        if (p[i] > p[sel] + EPS) {
            sel = i;
        }
    }

    printf("%d\n", sel + 1);

    return 0;
}
