#define ONLINE_JUDGE 0

#include <bits/stdc++.h>

#define x first
#define y second
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

namespace my {
    ii operator+(const ii &a, const ii &b) {return {a.x + b.x, a.y + b.y};}
    ii operator-(const ii &a, const ii &b) {return {a.x - b.x, a.y - b.y};}
    ii operator*(const ii &a, const ii &b) {return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};}
    ii operator*(const ii &a, const int &b) {return {a.x * b, a.y * b};}
    ii operator/(const ii &a, const int &b) {return {a.x / b, a.y / b};}
    ii conj(const ii &e) {return {e.x, -e.y};};
    ostream& operator<<(ostream &s, const ii &p) {s << '(' << p.x << ", " << p.y << ')';return s;}
}

using namespace my;

void solve() {
    string s, u;
    int ans = 999999, curwa;
    cin >> s >> u;
    for(size_t i = 1;i < u.length();i++)
        s = '$' + s;
    for(size_t i = 1;i < u.length();i++)
        s = s + '$';
    for(size_t i = 0;i < s.length() - u.length() + 1;i++) {
        curwa = 0;
        for(size_t j = 0;j < u.length();j++)
            curwa += (s[i + j] != u[j]);
        ans = min(ans, curwa);
    }
    printf("%d", ans);
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
