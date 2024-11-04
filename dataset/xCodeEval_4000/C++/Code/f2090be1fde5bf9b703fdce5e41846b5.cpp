



#define ONLINE_JUDGE 1

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define trace(x) cout << #x << ": " << x << '\n';

typedef long long ll;
typedef pair<int, int> ii;

int n, m;
int a[200000];
deque<ii> ints;
vector<ii> st;
vector<int> b, booty(200000);

void solve() {
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    for(int i = 0;i < m;i++) {
        int t, r;
        scanf("%d %d", &t, &r);
        while(!st.empty() && st.back().Y <= r)
            st.pop_back();
        if(st.empty() || st.back().X != t)
            st.push_back({t, r});
    }
    int maxr = st[0].Y;
    sort(a, a + maxr, (st[0].X == 1 ? [](const int &x, const int &y) {return x < y;} : [](const int &x, const int &y) {return x > y;}));
    ints.push_front({0, maxr - 1});
    for(int i = 1;i < st.size();i++) {
        assert(st[i].X != st[i - 1].X);
        assert(st[i].Y < st[i - 1].Y);
        int l = ints.front().X, r = ints.front().Y, k = st[i].Y;
        ints.pop_front();
        ii new_int1, new_int2;
        if(l <= r) {
            new_int1 = {l + k - 1, l};
            new_int2 = {l + k, r};
        } else {
            new_int1 = {l - k + 1, l};
            new_int2 = {l - k, r};
        }
        assert(new_int1.X >= 0 && new_int1.X < n && new_int1.Y >= 0 && new_int1.Y < n);
        assert(new_int2.X >= 0 && new_int2.X < n && new_int2.Y >= 0 && new_int2.Y < n);
        ints.push_front(new_int2);
        ints.push_front(new_int1);
    }
    for(int i = 0;i < ints.size();i++) {
        if(ints[i].X <= ints[i].Y)
            for(int j = ints[i].X;j <= ints[i].Y;j += 1) {
                b.push_back(a[j]);
            }
        else
            for(int j = ints[i].X;j >= ints[i].Y;j -= 1) {
                b.push_back(a[j]);
            }
    }
    for(int i = maxr;i < n;i++)
        b.push_back(a[i]);
    assert(b.size() == n);
    for(int i = 0;i < b.size();i++)
        printf("%d ", b[i]);
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
