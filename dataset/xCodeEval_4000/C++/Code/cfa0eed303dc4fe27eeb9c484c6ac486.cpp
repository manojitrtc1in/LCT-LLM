



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
    string s;
    s = "aabb";
    for(int i = 0;i < 50000;i++)
        s += "aabb";
    cout << s.substr(0, n);
}

int main() {
    if(ONLINE_JUDGE) { 

    } else { 

        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}