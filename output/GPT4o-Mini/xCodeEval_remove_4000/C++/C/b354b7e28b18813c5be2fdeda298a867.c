#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define C 100
#define EPS 1E-9

typedef long long int64;

char buf[1100000];
double ma[3][C];
double p[10];
int sel;

const char* DELIMS = ",.?!\"\\/|";

const char* cat[3 * C] = {
    "dealers 0.0038157536113382394",
    "customer 0.0010902153175252113",
    "dealer 9.539384028345599E-4",
    // ... (rest of the strings)
    "yasuhiro 0.001006893346758578",
};

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    for (int i = 0; i < 3 * C; i++) {
        char word[100];
        double x;
        sscanf(cat[i], "%s %lf", word, &x);
        ma[i / C][word[0]] = x; // Assuming word[0] is a valid index
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

    char* tok = strtok(text, " ");
    while (tok != NULL) {
        for (int i = 0; tok[i]; i++) {
            tok[i] = tolower(tok[i]);
        }

        for (int i = 0; i < 3; i++) {
            if (ma[i][tok[0]] != 0) { // Assuming tok[0] is a valid index
                p[i] += log(ma[i][tok[0]]);
            } else {
                p[i] += log(1E-6);
            }
        }

        tok = strtok(NULL, " ");
    }

    sel = 1;
    for (int i = 0; i < 3; i++) {
        if (p[i] > p[sel] + EPS) {
            sel = i;
        }
    }

    printf("%d\n", sel + 1);

    return 0;
}
