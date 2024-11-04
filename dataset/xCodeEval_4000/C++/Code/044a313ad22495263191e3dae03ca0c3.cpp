#define ONLINE_JUDGE 0

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, y = 2;
    scanf("%I64d", &n);
    printf("2\n");
    for(long long k = 2;k <= n;k++)
        printf("%I64d\n", k * k * k + 2 * k * k + 1);
}

int main() {
    srand(time(nullptr));
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
