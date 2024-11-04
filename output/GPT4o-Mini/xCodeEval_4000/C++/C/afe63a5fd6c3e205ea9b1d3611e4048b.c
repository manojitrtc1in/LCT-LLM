#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define C 100
#define DELIMS ",.?!\"\\/|#@*"
#define EPS 1E-9

typedef long long int64;

char buf[1100000];
double ma[3][C][2]; // Using a 2D array to store string and its corresponding value
double p[10];
int sel;

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    for (int i = 0; i < 3 * C; i++) {
        double x;
        sscanf(cat[i], "%s%lf", buf, &x);
        strcpy(ma[i / C][0], buf); // Store the string
        ma[i / C][1] = x; // Store the value
    }

    fgets(buf, sizeof(buf), stdin);
    char text[1100000] = "";
    while (fgets(buf, sizeof(buf), stdin)) {
        strcat(text, buf);
        strcat(text, " ");
    }

    for (int i = 0; i < strlen(text); i++)
        if (strchr(DELIMS, text[i]) != NULL)
            text[i] = ' ';
    
    char *tok = strtok(text, " ");
    while (tok != NULL) {
        for (int i = 0; tok[i]; i++)
            tok[i] = tolower(tok[i]);

        for (int i = 0; i < 3; i++) {
            int found = 0;
            for (int j = 0; j < C; j++) {
                if (strcmp(ma[i][j][0], tok) == 0) {
                    p[i] += log(ma[i][j][1]);
                    found = 1;
                    break;
                }
            }
            if (!found)
                p[i] += log(1E-6);
        }

        tok = strtok(NULL, " ");
    }

    sel = 1;
    for (int i = 2; i >= 0; i--)
        if (p[i] > p[sel] + EPS)
            sel = i;

    printf("%d\n", sel + 1);

    return 0;
}
