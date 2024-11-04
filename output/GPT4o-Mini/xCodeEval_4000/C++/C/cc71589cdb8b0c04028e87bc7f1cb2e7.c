#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 1000 + 7

long long lim[] = {0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099};
char *pr1[] = {"", "198", "19", "2", "", "", "", "", "", ""};
char *pr2[] = {"", "199", "20", "3", "1", "1", "1", "1", "1", "1"};

int n;
char s[N];

int read() {
    if (scanf("%s", s) != 1)
        return 0;
    memmove(s, s + 4, strlen(s) - 3); // Remove first 4 characters
    s[strlen(s) - 4] = '\0'; // Null-terminate the string
    n = strlen(s);
    return 1;
}

char* solve() {
    long long x = atoll(s);
    static char result[N];
    if (x >= lim[n])
        sprintf(result, "%s%s", pr1[n], s);
    else
        sprintf(result, "%s%s", pr2[n], s);
    return result;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int tc;
#ifdef MULTITEST
    scanf("%d", &tc);
    while(tc--) {
#else
    while(read()) {
#endif
        puts(solve());
    }
}
