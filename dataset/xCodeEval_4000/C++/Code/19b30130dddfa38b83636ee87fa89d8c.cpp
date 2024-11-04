
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
 
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define INF 1e9 + 5;
 
inline string IntToString(LL a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}
 
inline LL StringToInt(string a)
{
    char x[100];
    LL res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}
 
inline string GetString(void)
{
    char x[1000005];
    scanf("%s", x);
    string s = x;
    return s;
}
 
inline string uppercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'a' && s[i] <= 'z')
        s[i] = s[i] - 'a' + 'A';
    return s;
}
 
inline string lowercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] = s[i] - 'A' + 'a';
    return s;
}
 
void solve() {
    int n;
    scanf("%i", &n);
    int a[n];
    int counter[n + 1];
    for(int i = 0; i < n; i++) {
        scanf("%i", &a[i]);
        counter[a[i]]++;
    }
    int meh = 0, meh_update = 0;
    vi way;
    int ans = 0;
    int sum_meh = 0;
    bool z[n + 2];
    int anss[n + 1];
    while(meh_update < n) {
        memset(z, 0, sizeof(z));
        for(int i = meh_update; i < n; i++) {
            z[a[i]] = true;
            if(a[i] == meh){
                meh_update = i;
                for(int h = meh; z[h]; h++) {
                    meh = h + 1;
                }
                if(!counter[meh]) break;
            }
        }
        anss[ans] = meh;
        meh_update++;
        meh = 0;
        ans++;
    }
    printf("%i\n", ans);
    for(int i = 0; i < ans; i++) {
        printf("%i ", anss[i]);
    }
    printf("\n");
}
 
int main()
{
    int k;
    scanf("%i", &k);
    while(k--) {
        solve();
    }
    return 0;
}