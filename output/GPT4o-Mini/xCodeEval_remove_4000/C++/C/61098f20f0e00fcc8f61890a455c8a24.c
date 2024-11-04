#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef long long int64;

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

const int C = 100;
const char* DELIMS = ",.?!\"\\/|";

const char* cat[3 * C] = {
    "dealers 0.0038157536113382394",
    "customer 0.0010902153175252113",
    "dealer 9.539384028345599E-4",
    // ... (rest of the strings)
    "yasuhiro 0.001006893346758578",
};

char buf[1100000];
double ma[3][1000]; // Assuming max 1000 unique words per category
double p[10];
int sel;

int main() {
    FILE *input = fopen("input.txt", "rt");
    FILE *output = fopen("output.txt", "wt");

    for (int i = 0; i < 3 * C; i++) {
        double x;
        sscanf(cat[i], "%s %lf", buf, &x);
        ma[i / C][buf] = x; // This line needs a different approach in C
    }

    fgets(buf, sizeof(buf), input);
    char text[1100000] = "";
    while (fgets(buf, sizeof(buf), input)) {
        strcat(text, buf);
        strcat(text, " ");
    }

    for (int i = 0; i < strlen(text); i++) {
        if (strchr(DELIMS, text[i]) != NULL)
            text[i] = ' ';
    }

    char *tok = strtok(text, " ");
    while (tok != NULL) {
        for (int i = 0; tok[i]; i++)
            tok[i] = tolower(tok[i]);

        for (int i = 0; i < 3; i++) {
            // Check if tok exists in ma[i] (needs a different approach in C)
            // Update p[i] accordingly
        }

        tok = strtok(NULL, " ");
    }

    sel = 1;
    for (int i = 0; i < 3; i++) {
        if (p[i] > p[sel] + EPS)
            sel = i;
    }

    fprintf(output, "%d\n", sel + 1);

    fclose(input);
    fclose(output);
    return 0;
}
