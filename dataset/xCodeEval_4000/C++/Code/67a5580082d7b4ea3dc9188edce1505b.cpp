
#include <bits/stdc++.h>
using namespace std;
#define lc (rt << 1)
#define rc ((rt << 1) | 1)
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define PE(i, u) for (int i = head[u]; i != -1; i = edge[i].next)
typedef long long LL;
const int maxn = 1e6 + 20;
const int mod = 1e9 + 7;
int n, m;
LL INF = 1e18;
char s[maxn];
LL a[maxn];
LL p[maxn];
char pre[maxn];
char t[maxn];
string res[maxn];
int num[maxn], id[maxn];
int main(int argc, char const *argv[])
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int cnt = 0;
    per(i, n, 1){
        t[++cnt] = s[i];
        id[cnt] = i;
        if(cnt == 1) pre[cnt] = -1;
        else {
            if(t[cnt] == t[cnt - 1]) pre[cnt] = pre[cnt - 1];
            else pre[cnt] = t[cnt - 1];
        }
        while(cnt > 1 && t[cnt] == t[cnt - 1] && id[cnt - 1] - id[cnt] == 1){
            

            if(cnt == 2) cnt = 0;
            else if(pre[cnt - 1] < t[cnt]){
                cnt -= 2;
            } else break;
        }
        num[i] = cnt;
        if(cnt <= 10){
            per(j, cnt, 1) res[i] += t[j];
        } else {
            rep(j, 0, 4){
                res[i] += t[cnt - j];
            }
            rep(j, 1, 3) res[i] += '.';
            res[i] += t[2], res[i] += t[1];
        }
    }
    rep(i, 1, n) {
        

        

        

        

        cout << num[i] << ' ' << res[i] << '\n';
    }
    return 0;
}