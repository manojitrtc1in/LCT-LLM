#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    int w;
    scanf("%d", &w);
    if (w == 2) {
        printf("NO");
        return;
    }
    if (w % 2 == 0) printf("YES");
    else printf("NO");
}
