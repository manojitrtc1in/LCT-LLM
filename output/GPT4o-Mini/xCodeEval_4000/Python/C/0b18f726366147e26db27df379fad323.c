#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE "0123456789`~!@"

long long from_base(const char *X) {
    int l = strlen(BASE);
    long long r = 0;
    long long e = 1;
    
    for (int i = 0; X[i] != '\0'; i++) {
        char *pos = strchr(BASE, X[i]);
        if (pos) {
            r += (pos - BASE) * e;
            e *= l;
        }
    }
    return r;
}

int main() {
    int N, mod;
    char input[100];
    
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %d", &N, &mod);
    
    const char *A[] = {
        "0", "1", "2", "6", "(", "D", "E3", "_&", "/51", "n`6", 
        "n4>", "!rR2", "E+a*", "j61h1", "!3ab!", "q`t6"
    };
    
    printf("%lld\n", from_base(A[N]) % mod);
    
    return 0;
}
