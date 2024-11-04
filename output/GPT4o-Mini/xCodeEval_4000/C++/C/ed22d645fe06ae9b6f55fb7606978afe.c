#include <stdio.h>
#include <string.h>

#define N 109

char a[N], c[N];
int t[N];
int b, d;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    scanf("%d %d", &b, &d);
    scanf("%s %s", a, c);
    int an = strlen(a), cn = strlen(c);

    for (int i = 0; i < cn; i++) {
        int k = t[i];
