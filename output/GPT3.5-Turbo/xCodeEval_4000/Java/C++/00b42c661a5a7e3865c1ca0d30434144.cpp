#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <climits>
using namespace std;

long long mul(long long a, long long b, long long p)
{
    long long res=0,base=a;
    while(b>0)
    {
        if((b&1LL)>0)
            res=(res+base)%p;
        base=(base+base)%p;
        b>>=1;
    }
    return res;
}

long long mod_pow(long long k, long long n, long long p)
{
    long long res = 1LL;
    long long temp = k;
    while(n!=0LL)
    {
        if((n&1LL)==1LL)
        {
            res = (res*temp)%p;
        }
        temp = (temp*temp)%p;
        n = n>>1LL;
    }
    return res%p;
}

int ct = 0;
int f[200001];
int b[200001];
int str[200001];

void go(int rt, vector<int> g[])
{
    str[ct] = rt;
    f[rt] = ct;
    for(int cd : g[rt])
    {
        ct++;
        go(cd, g);
    }
    b[rt] = ct;
}

int add = 0;

void sort(vector<long long>& a)
{
    random_device rd;
    for (int i = 1; i < a.size(); ++i)
    {
        int p = rd() % i;
        long long x = a[p];
        a[p] = a[i];
        a[i] = x;
    }
    sort(a.begin(), a.end());
}

void dfs(int from, int k)
{

}

void add(int u, int v)
{
    to[ct] = u;
    ne[ct] = h[v];
    h[v] = ct++;
}

int r = 0;

void dfs1(int c, int ff)
{
    clr[c][aa[c]]++;
    for(int j=h[c];j!=-1;j=ne[j])
    {
        if(to[j]==ff) continue;
        dfs1(to[j],c);
        clr[c][1] += clr[to[j]][1];
        clr[c][2] += clr[to[j]][2];
        if(clr[to[j]][1]==s1&&clr[to[j]][2]==0||clr[to[j]][2]==s2&&clr[to[j]][1]==0)
        {
            r++;
        }
    }
}

int[] h,ne,to,fa;
int clr[][];
int aa[];
int s1 = 0;
int s2 = 0;

bool f(int n)
{
    int c = 0;
    while(n>0)
    {
        c += n%10;
        n /=10;
    }
    return (c&3)==0;
}

int[][] next(string s)
{
    int len = s.length();
    int ne[][] = new int[len+1][26];
    memset(ne[len], -1, sizeof(ne[len]));
    for(int i=len-1;i>=0;--i)
    {
        memcpy(ne[i], ne[i+1], sizeof(ne[i+1]));
        ne[i][s[i]-'a'] = i+1;
    }
    return ne;
}

void solve()
{
    string s = ns();
    string t = ns();
    int len = s.length();
    int pref[len];
    int suf[len+1];
    int p = 0;
    int tlen = t.length();
    for(int i=0;i<len;++i)
    {
        if(p<tlen&&s[i]==t[p])
        {
            p++;
        }
        pref[i] = p;
    }
    p = 0;
    for(int i=len-1;i>=0;--i)
    {
        if(p<tlen&&s[i]==t[tlen-1-p])
        {
            p++;
        }
        suf[i] = p;
    }
    int e = -1;
    int all = 0;
    for(int i=-1;i<len;++i)
    {
        int r = tlen - (i<0?0:pref[i]);
        while(e+1<=len&&suf[e+1]>=r)
        {
            e++;
        }
        all = max(all,e-i-1);
    }
    cout << all << endl;
}

long long t1[];

void update(long long t[], int i, long long v)
{
    for(;i<t.length;i+=(i&-i))
    {
        t[i] += v;
    }
}

long long get(long long t[], int i)
{
    long long s = 0;
    for(;i>0;i-=(i&-i))
    {
        s += t[i];
    }
    return s;
}

int equal_bigger(long long t[], long long v)
{
    int s=0,p=0;
    for(int i=Integer.numberOfTrailingZeros(Integer.highestOneBit(t.length));i>=0;--i)
    {
        if(p+(1<<i)< t.length && s + t[p+(1<<i)] < v)
        {
            v -= t[p+(1<<i)];
            p |= 1<<i;
        }
    }
    return p+1;
}

struct S
{
    int l = 0;
    int r = 0 ;
    long long le = 0;
    long long ri = 0;
    long long tot = 0;
    long long all = 0;

    S(int l, int r)
    {
        this->l = l;
        this->r = r;
    }
};

S a[];
int o[];

void init(int f[])
{
    o = f;
    int len = o.length;
    a = new S[len*4];
    build(1,0,len-1);
}

void build(int num, int l, int r)
{
    S cur(l, r);
    if(l==r)
    {
        a[num] = cur;
        return;
    }
    else
    {
        int m = (l+r)>>1;
        int le = num<<1;
        int ri = le|1;
        build(le, l, m);
        build(ri, m+1, r);
        a[num] = cur;
        pushup(num, le, ri);
    }
}

long long dd = 10007;

void update(int num, int l, long long v)
{
    if(a[num].l==a[num].r)
    {
        a[num].le = v%dd;
        a[num].ri = v%dd;
        a[num].all = v%dd;
        a[num].tot = v%dd;
    }
    else
    {
        int m = (a[num].l+a[num].r)>>1;
        int le = num<<1;
        int ri = le|1;
        pushdown(num, le, ri);
        if(l<=m)
        {
            update(le, l, v);
        }
        if(l>m)
        {
            update(ri, l, v);
        }
        pushup(num,le,ri);
    }
}

void pushup(int num, int le, int ri)
{
    a[num].all = (a[le].all*a[ri].all)%dd;
    a[num].le = (a[le].le + a[le].all*a[ri].le)%dd;
    a[num].ri = (a[ri].ri + a[ri].all*a[le].ri)%dd;
    a[num].tot = (a[le].tot + a[ri].tot + a[le].ri*a[ri].le)%dd;
}

void pushdown(int num, int le, int ri)
{

}

long long gcd(long long a, long long b)
{
    return b==0?a: gcd(b,a%b);
}

int gcd(int a, int b)
{
    return b==0?a: gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Main obj;
    obj.run();
    return 0;
}
