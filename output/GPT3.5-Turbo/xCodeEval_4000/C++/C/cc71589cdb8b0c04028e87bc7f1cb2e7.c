#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MULTITEST

#define N 1000 + 7

typedef long long li;

int n;
char s[N];

li lim[] = {0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099};
char pr1[][4] = {"", "198", "19", "2", "", "", "", "", "", ""};
char pr2[][4] = {"", "199", "20", "3", "1", "1", "1", "1", "1", "1"};

char* solve() {
    li x = atoll(s);
    if (x >= lim[n])
        return strcat(pr1[n], s);
    else
        return strcat(pr2[n], s);
}

int read() {
    if (scanf("%s", s) != 1)
        return 0;
    strcpy(s, s + 4);
    n = strlen(s);
    return 1;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);

    int tt = clock();
#endif

    printf("%.15lf\n", 0.0);
    printf("%.15lf\n", 0.0);

#ifdef MULTITEST
    int tc;
    scanf("%d", &tc);
    while(tc--){
        read();
#else
    while(read()) {    
#endif
        puts(solve());
        
#ifdef _DEBUG
    printf("TIME = %d\n", clock() - tt);
    tt = clock();
#endif

    }
}
