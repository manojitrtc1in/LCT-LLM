#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define C 100
#define DELIMS ",.?!\"\\/|"

char buf[1100000];
double ma[3 * C][2];
double p[10];
int sel;

int main() {
    FILE *inputFile = fopen("input.txt", "rt");
    FILE *outputFile = fopen("output.txt", "wt");

    for (int i = 0; i < 3 * C; i++) {
        double x;
        sscanf(cat[i], "%s%lf", buf, &x);
        ma[i][0] = atof(buf);
        ma[i][1] = x;
    }

    fgets(buf, sizeof(buf), inputFile);
    char text[1100000];
    while (fgets(buf, sizeof(buf), inputFile)) {
        strcat(text, buf);
        strcat(text, " ");
    }

    for (int i = 0; i < strlen(text); i++) {
        if (strchr(DELIMS, text[i]) != NULL)
            text[i] = ' ';
    }

    char *token;
    token = strtok(text, " ");
    while (token != NULL) {
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        for (int i = 0; i < 3; i++) {
            int found = 0;
            for (int j = 0; j < 3 * C; j++) {
                if (strcmp(token, ma[j][0]) == 0) {
                    p[i] += log(ma[j][1]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                p[i] += log(1E-6);
            }
        }

        token = strtok(NULL, " ");
    }

    sel = 1;
    for (int i = 2; i >= 0; i--) {
        if (p[i] > p[sel] + 1E-9) {
            sel = i;
        }
    }

    fprintf(outputFile, "%d\n", sel + 1);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
