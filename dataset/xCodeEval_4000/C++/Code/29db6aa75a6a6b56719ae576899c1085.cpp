






























































































































































































































































































































































































































































































































































































































































































































































































































































































#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cctype>
#include <stack>
#include <map>

using namespace std;

namespace fastIO {
#define BUF_SIZE 100000
    

    bool IOerror = 0;

    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if (p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if (pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }

    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }

    inline void read(int &x) {
        char ch;
        while (blank(ch = nc()));
        if (IOerror)
            return;
        for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }

    inline void readll(long long int &x) {
        char ch;
        while (blank(ch = nc()));
        if (IOerror)
            return;
        for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }

    inline void reads(char *s) {
        char ch;
        while (blank(ch = nc()));
        if (IOerror)return;
        s[0] = ch;
        for (int i = 1; (!blank(ch = nc())); ++i) {
            s[i] = ch;
        }
    }

#undef BUF_SIZE
};


#define loop(i, x) for(int i = 0; i < x; ++i)
#define circle(i, x) for(int i = 1; i <= x; ++i)
#define reverse(i, x) for(int i = x - 1; i >= 0; --i)
#define wh(t) while(t--)
#define mem(i, x) memåset(i, x, sizeof(i))
#define dsc(x) scanf("%lld", &x)
#define ssc(x) scanf("%s", s)
#define lfsc(x) scanf("%lf", &x)

typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

typedef int i1;
const double esp = 1e-7;
const double pi = acos(-1.0);
const int maxx = 210100;
const int mod = int(1e9 + 9);

ll dp[maxx];
bool vis[maxx];
ll fa[maxx];
vector<ll> v[maxx];
bool isleaf[maxx];
stack<ll> st;
vector<ll> ans;

void dfs(ll root) {
    for (auto i:v[root]) {
        if (i == fa[root])continue;
        fa[i] = root;
        if (v[i].empty()) {
            isleaf[i] = true;
            dp[i]++;
            continue;
        }
        dfs(i);
    }
    if (dp[root] & 1) {
        for (auto i: v[root]) {
            if (i == fa[root])continue;
            if (!vis[i] && isleaf[i]) {
                vis[i] = true;
                st.push(i);
            }
        }
        if (!vis[root]) {
            ans.push_back(root);
            vis[root] = true;
        }
    } else {
        isleaf[root] = true;
        dp[fa[root]]++;
        for (auto i: v[root]) {
            if (i == fa[root])continue;
            if (!vis[i] && isleaf[i]) {
                vis[i] = true;
                st.push(i);
            }
        }
    }
}

int main() {
    ll n;
    dsc(n);
    if (n & 1) {
        ll root = 1;

        ans.clear();
        while (!st.empty())st.pop();

        circle(i, n) {
            v[i].clear();
            vis[i] = isleaf[i] = false;
            fa[i] = dp[i] = 0;
        }
        circle(i, n) {
            ll a;
            dsc(a);
            if (!a)root = i;
            else {
                v[i].push_back(a);
                v[a].push_back(i);
            }
        }
        dfs(root);
        if (dp[0] == 1) {
            st.push(root);
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        printf("YES\n");
        loop(i, n) {
            printf("%lld\n", ans[i]);
        }
    } else {
        loop(i, n) {
            ll a;
            dsc(a);
        }
        printf("NO\n");
    }
    return 0;
}







