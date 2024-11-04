



#include<bits/stdc++.h>
#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")








































using namespace std;













































































































































































































































#include <bits/stdc++.h>
using namespace std;
#define Rep(i, l, r) for(int i = l ; i <= r ; i ++)
#define Lep(i, r, l) for(int i = r ; i >= l ; i --)

inline int read() {
    int x = 0, flag = 1;
    char ch = getchar();
    for( ; ch > '9' || ch < '0' ; ch = getchar()) if(ch == '-') flag = -1;
    for( ; ch >= '0' && ch <= '9' ; ch = getchar()) x = x * 10 + ch - '0';
    return x * flag;
}
const int MAXN = 2e5 + 50;
typedef long long LL;
int n, val[MAXN], tim[MAXN], siz[MAXN];
int rt[MAXN], pos[MAXN], cnt = 0, m;
LL Ans[MAXN], TSUM;
vector <int> E[MAXN];
struct SegmentTree1 {
    int ls, rs, siz; LL tsum;
} T[MAXN * 62];
struct Qs { 
    int tim, id; 
    bool operator <(const Qs& f) const { return tim < f.tim; }
} ;
vector <Qs> Q[MAXN];
bool cmp(int a, int b) { return tim[a] < tim[b]; }
void erase(int x) { T[x].ls = T[x].rs = T[x].siz = T[x].tsum = 0; }
int Get(int x, int P, int l, int r, int w, LL Sz, LL tsum) { 

    if(l == r) return l - 1e8;
    int mid = (l + r) >> 1; LL SumL = mid - 1e8, sz = 0, t = 0;  

    for(int i = 0 ; i <= P ; i ++) {
        int u = pos[E[x][i]], ls = T[u].ls, p = mid - 1e8;
        if(mid - 1e8 < tim[E[x][i]]) continue;
        SumL += 1ll * p * T[ls].siz - T[ls].tsum;
        sz += T[ls].siz, t += T[ls].tsum;
    } SumL -= tsum, SumL += 1ll * (mid - 1e8) * Sz;
    if(SumL >= w) {
        Rep(i, 0, P) pos[E[x][i]] = T[pos[E[x][i]]].ls;
        return Get(x, P, l, mid, w, Sz, tsum);
    }
    Rep(i, 0, P) pos[E[x][i]] = T[pos[E[x][i]]].rs;
    return Get(x, P, mid + 1, r, w, sz + Sz, tsum + t);
}
int merge(int x, int y) { 

    if(!x || !y) return x | y;
    int cur = ++ cnt;
    T[cur].siz = T[x].siz + T[y].siz;
    T[cur].tsum = T[x].tsum + T[y].tsum;
    T[cur].ls = merge(T[x].ls, T[y].ls);
    T[cur].rs = merge(T[x].rs, T[y].rs);
    erase(x), erase(y); return cur;
}
void insert(int &x, int l, int r, int pos, int a, LL b) { 

    if(!x) x = ++ cnt; int mid = (l + r) >> 1;
    T[x].siz += a, T[x].tsum += b;
    if(l == r) return ;
    if(pos + 1e8 <= mid) insert(T[x].ls, l, mid, pos, a, b);
    else insert(T[x].rs, mid + 1, r, pos, a, b);
    T[x].siz = T[T[x].ls].siz + T[T[x].rs].siz;
    T[x].tsum = T[T[x].ls].tsum + T[T[x].rs].tsum;
    return ;
}
int Cover(int &x, int l, int r, int pos) { 

    int cur = x, Sz = 0;
    if(l == r) { TSUM += T[x].tsum, Sz = T[cur].siz, erase(x), x = 0; return Sz; }
    int mid = (l + r) >> 1;
    if(pos + 1e8 <= mid) Sz = Cover(T[x].ls, l, mid, pos);
    else {
        Sz += T[T[x].ls].siz, TSUM += T[T[x].ls].tsum,
        erase(T[x].ls), T[x].ls = 0, 
        Sz += Cover(T[x].rs, mid + 1, r, pos);
    }
    T[x].siz = T[T[x].ls].siz + T[T[x].rs].siz;
    T[x].tsum = T[T[x].ls].tsum + T[T[x].rs].tsum;
    return Sz;
}
LL Find(int x, int l, int r, int pos) {
    if(!x) return 0;
    if(l == r) return 1ll * pos * T[x].siz - T[x].tsum;
    int mid = (l + r) >> 1;
    if(pos + 1e8 <= mid) return Find(T[x].ls, l, mid, pos);
    return Find(T[x].rs, mid + 1, r, pos) +  1ll * pos * T[T[x].ls].siz - T[T[x].ls].tsum;
}
void dfs1(int x) {
    int Siz = E[x].size() - 1, now = 0;
    Rep(i, 0, Siz) {
        dfs1(E[x][i]);
        pos[E[x][i]] = rt[E[x][i]]; TSUM = 0;
        int fs = Cover(rt[E[x][i]], 0, 2e8, tim[E[x][i]] - 1);
        insert(rt[E[x][i]], 0, 2e8, tim[E[x][i]], fs, TSUM);
    }
    tim[x] = Get(x, Siz, 0, 2e8, -val[x], 0, 0);
    sort(E[x].begin(), E[x].end(), cmp);

    while(now != Q[x].size()) {
        int Tim = Q[x][now].tim, Id = Q[x][now].id;
        if(E[x].size() == 0) { Ans[Id] = val[x] + Tim; now ++; continue; }
        if(Tim < tim[E[x][0]]) { Ans[Id] = val[x] + Tim; now ++; continue; }
        break;
    }

    Rep(i, 0, Siz) {
        rt[x] = merge(rt[x], rt[E[x][i]]);
        if(now == Q[x].size()) continue;
        int Tim = Q[x][now].tim, Id = Q[x][now].id, f;
        while(Tim >= tim[E[x][i]] && now < Q[x].size()) {
            if(i != Siz) if(Tim >= tim[E[x][i + 1]]) break;
            Ans[Id] = Find(rt[x], 0, 2e8, Tim) + Tim + val[x];
            now ++; if(now == Q[x].size()) break;
            Tim = Q[x][now].tim, Id = Q[x][now].id;
        }
    }
    insert(rt[x], 0, 2e8, tim[x], 1, -val[x]);
    return ;
}
inline void Write(LL x, char c) {
    LL Putout[35], Numbercnt = 0;
    if(x < 0) putchar('-'), x = -x;
    if(!x) { putchar('0'), putchar(c); return ; }
    while(x) Putout[++ Numbercnt] = x % 10, x /= 10;
    for(int i = Numbercnt ; i >= 1 ; i --) putchar(Putout[i] + '0');
    if(Numbercnt == 0) putchar('0'); putchar(c);
    return ;
}

vector<int>GG[MAXN];


void DFS(int x,int fat){
  if(x!=1)E[fat].push_back(x),++val[fat];
  for(int i=0;i<GG[x].size();++i)if(GG[x][i]!=fat)DFS(GG[x][i],x);
}

int V[MAXN];

int main() {
    n = read(); int X, Y;
    Rep(i, 2, n) X = read(), Y = read(), GG[X].push_back(Y), GG[Y].push_back(X);
    DFS(1, 0);
    

    

    

    

    

    

    m = read();
    Rep(i, 1, m)  {
        int u = read(), x = read();
        V[i] = x;
        Q[u].push_back((Qs) { - x - 1, i } );
    } 
    Rep(i, 1, n) sort(Q[i].begin(), Q[i].end()); dfs1(1);
    Rep(i, 1, m) Write(Ans[i] + V[i] + 1, ' '), putchar('\n');
    return 0;
}