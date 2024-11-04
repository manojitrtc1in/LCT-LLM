#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define C 100
#define EPS 1E-9

typedef long long int64;

char buf[1100000];
double ma[3][C][2]; // to store word and its probability
double p[10];
int sel;

const char* DELIMS = ",.?!\"\\/|";

const char* cat[3 * C] = {
    "dealers 0.0038157536113382394",
    "customer 0.0010902153175252113",
    "dealer 9.539384028345599E-4",
    // ... (rest of the data)
    "yasuhiro 0.001006893346758578",
};

int main() {
    FILE *input = fopen("input.txt", "rt");
    FILE *output = fopen("output.txt", "wt");

    for (int i = 0; i < 3 * C; i++) {
        char word[100];
        double x;
        sscanf(cat[i], "%s %lf", word, &x);
        int index = i / C;
        strcpy(ma[index][i % C][0], word);
        ma[index][i % C][1] = x;
    }

    fgets(buf, sizeof(buf), input);
    char text[1100000] = "";
    while (fgets(buf, sizeof(buf), input)) {
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
    for (int i = 0; i < 3; i++) {
        if (p[i] > p[sel] + EPS) {
            sel = i;
        }
    }

    fprintf(output, "%d\n", sel + 1);

    fclose(input);
    fclose(output);

    return 0;
}
