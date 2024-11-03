



#define ONLINE_JUDGE 1

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
        putchar((i % 4) < 2 ? 'a' : 'b');
}

int main() {
    if(ONLINE_JUDGE) { 

    } else { 

        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
