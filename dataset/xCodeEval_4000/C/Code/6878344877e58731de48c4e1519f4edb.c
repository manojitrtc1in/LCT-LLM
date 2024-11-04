



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int main() {

    int n;
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");
    fscanf(in, "%d\n", &n);
    char* string = malloc(n);
    fgets(string, n + 1, in);

    for (int i=0; n/2>i; i++) {
        if (string[i]=='R' && string[i+n/2]=='L')
            fprintf(out, "%d %d\n", i+n/2+1, i+1);
        else
            fprintf(out, "%d %d\n", i+1, i+n/2+1);
    }

return 0;

}
