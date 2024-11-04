#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define C 100
#define DELIMS ",.?!\"\\/|"

typedef struct {
    char word[100];
    double value;
} Category;

Category cat[3 * C];
char buf[1100000];
double p[10];
int sel;

int main() {
    FILE *inputFile = fopen("input.txt", "rt");
    FILE *outputFile = fopen("output.txt", "wt");

    int i, j;
    for (i = 0; i < 3 * C; i++) {
        double x;
        sscanf(cat[i].word, "%s%lf", buf, &x);
        strcpy(cat[i].word, buf);
        cat[i].value = x;
    }

    fgets(buf, sizeof(buf), inputFile);
    char text[1100000] = "";
    while (fgets(buf, sizeof(buf), inputFile)) {
        strcat(text, buf);
        strcat(text, " ");
    }

    for (i = 0; i < strlen(text); i++) {
        if (strchr(DELIMS, text[i]) != NULL) {
            text[i] = ' ';
        }
    }

    char *token;
    token = strtok(text, " ");
    while (token != NULL) {
        for (i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        for (i = 0; i < 3; i++) {
            int found = 0;
            for (j = 0; j < 3 * C; j++) {
                if (strcmp(cat[j].word, token) == 0) {
                    p[i] += log(cat[j].value);
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
    for (i = 2; i >= 0; i--) {
        if (p[i] > p[sel]) {
            sel = i;
        }
    }

    fprintf(outputFile, "%d\n", sel + 1);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
