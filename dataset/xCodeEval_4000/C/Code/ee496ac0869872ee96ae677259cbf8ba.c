



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int main() {

    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");
    int n;
    fscanf(in, "%d", &n);

    for(int i = 0, a, b; i < 3; i++) {

        fscanf(in, "%d %d", &a, &b);
        if(n == a)
            n = b;
        else if(n == b)
            n = a;
    }
    fprintf(out, "%d", n);
    return 0;

}
