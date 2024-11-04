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
#include <fstream>
#include <sstream>
#include <ctime>
#include <cassert>
#include <climits>
#include <complex>
#include <numeric>
using namespace std;

int groups = 0;
vector<int> fa;
vector<int> sz;

void init1(int n) {
    groups = n;
    fa.resize(n);
    for (int i = 1; i < n; ++i) {
        fa[i] = i;
    }
    sz.resize(n);
    fill(sz.begin(), sz.end(), 1);
}

int root(int p) {
    while (p != fa[p]) {
        fa[p] = fa[fa[p]];
        p = fa[p];
    }
    return p;
}

void combine(int p, int q) {
    int i = root(p);
    int j = root(q);
    if (i == j) {
        return;
    }
    fa[i] = j;
    if (sz[i] < sz[j]) {
        fa[i] = j;
        sz[j] += sz[i];
    } else {
        fa[j] = i;
        sz[i] += sz[j];
    }
    groups--;
}

string roundS(double result, int scale) {
    string fmt = string("%.") + to_string(scale) + "f";
    char buffer[100];
    sprintf(buffer, fmt.c_str(), result);
    return string(buffer);
}

vector<int> unique(vector<int> a) {
    int p = 1;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != a[i - 1]) {
            a[p++] = a[i];
        }
    }
    return vector<int>(a.begin(), a.begin() + p);
}

int bigger(vector<long long> a, long long key) {
    return upper_bound(a.begin(), a.end(), key) - a.begin();
}

vector<int> h;
vector<int> to;
vector<int> ne;
int m = 0;

void addEdge(int u, int v, int w) {
    to.push_back(v);
    ne.push_back(h[u]);
    h[u] = m++;
}

vector<int> w;

int cc = 0;

void add(int u, int v, int ww) {
    to.push_back(u);
    w.push_back(ww);
    ne.push_back(h[v]);
    h[v] = cc++;

    to.push_back(v);
    w.push_back(ww);
    ne.push_back(h[u]);
    h[u] = cc++;
}

struct S {
    int l = 0;
    int r = 0;
    int miss = 0;
    int cnt = 0;
    int c = 0;

    S(int l, int r) {
        this->l = l;
        this->r = r;
    }
};

vector<S> a;
vector<int> o;

void init11(vector<int> f) {
    o = f;
    int len = o.size();
    a.resize(len * 4);
    build1(1, 0, len - 1);
}

void build1(int num, int l, int r) {
    S cur(l, r);
    if (l == r) {
        cur.c = o[l];
        a[num] = cur;
        return;
    } else {
        int m = (l + r) >> 1;
        int le = num << 1;
        int ri = le | 1;
        build1(le, l, m);
        build1(ri, m + 1, r);
        a[num] = cur;
        pushup(num, le, ri);
    }
}

int query1(int num, int l, int r) {
    if (a[num].l >= l && a[num].r <= r) {
        return a[num].c;
    } else {
        int m = (a[num].l + a[num].r) >> 1;
        int le = num << 1;
        int ri = le | 1;

        int mi = -1;

        if (r > m) {
            int res = query1(ri, l, r);
            mi = max(mi, res);
        }

        if (l <= m) {
            int res = query1(le, l, r);
            mi = max(mi, res);
        }

        return mi;
    }
}

void pushup(int num, int le, int ri) {
    a[num].c = max(a[le].c, a[ri].c);
}

vector<int> clr;
vector<vector<int>> qr;
vector<int> qs;

int rr = 100;
deque<int> cao;
void df(int n, deque<int> li){
    int sz = li.size();
    if(sz>=rr||sz>=11) return;
    int v = li.back();
    if(v==n){
        cao = deque<int>(li);
        rr = sz;
        return;
    }
    vector<int> res(li.rbegin(), li.rend());

    for(int u:res){
        for(int vv:res){
            if(u+vv>v&&u+vv<=n){
                li.push_back(u+vv);
                df(n,li);
                li.pop_back();
            }else if(u+vv>n){break;}
        }
    }
}

random_device rd;
mt19937 gen(rd());

vector<long long> ex_gcd(long long a,long long b){
    if(b==0) {
        return {1,0,a};
    }
    vector<long long> r = ex_gcd(b,a%b);
    return {r[1], r[0]-(a/b)*r[1], r[2]};
}

void chinese_rm(vector<long long> m,vector<long long> r){
    vector<long long> res = ex_gcd(m[0],m[1]);
    long long rm = r[1]-r[0];
    if(rm%res[2]==0){

    }

}

void go(int i,int c,vector<int>& cl){
    cl[i] = c;
    for(int j=h[i];j!=-1;j=ne[j]){
        int v = to[j];
        if(cl[v]==0){
            go(v,-c,cl);
        }
    }
}

void solve() {
    int t;
    cin >> t;
    vector<int> dp(1000001);
    for(int i = 0; i<t;++i){
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for(int j=0;j<n;++j){
            cin >> a[j];
        }

        int g = 0;
        for(int j=0;j<d;++j){
            if(dp[a[j]]++==0){
                g++;
            }
        }
        int all = g;
        for(int j=d;j<n;++j){
            if(--dp[a[j-d]]==0){
                g--;
            }
            if(dp[a[j]]++==0){
                g++;
            }
            all = min(all,g);
        }
        cout << all << endl;
        for(int j=0;j<d;++j){
            dp[a[n-j-1]]--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
