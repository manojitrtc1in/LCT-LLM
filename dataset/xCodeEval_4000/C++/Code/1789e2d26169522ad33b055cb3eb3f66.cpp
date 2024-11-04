


























































































































































































































































































































































































































































































































#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <stdio.h>
#include <unordered_map>
#include <numeric>
#include <fstream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma GCC diagnostic ignored "-Wunused-const-variable"

using namespace std;

#ifndef __clang__
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#endif

#define ll long long
#define int long long
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define MP make_pair
int max(int a, int b) { return (a>b) ? a : b;}
int min(int a, int b) { return (a<b) ? a : b;}
double max(double a, double b) { return (a>b) ? a : b;}
double min(double a, double b) { return (a<b) ? a : b;}
void ain(vi &a) { for(int i=0;i<a.size();i++) cin>>a[i]; }
int Ceil(double d) { return ((int)d == d) ? d : d+1; }
int gcd(int a, int b) { return (a==0) ? b : gcd(b%a, a); }

template<class T, class V> ostream& operator<< (ostream& out, const pair<T, V>& p) {out << p.first << ", " << p.second; return out;}
template<class T> ostream& operator<< (ostream &out, const vector<T>& c){ for(int i : c) out << i << ' '; return out;}
template<class T, class V> ostream& operator<< (ostream& out, const map<T, V> m) {out << "{"; for(auto p : m) out << p.first << ": " << p.second <<", "; out << "}"; return out; }
template<class T> ostream& operator<< (ostream& out, const set<T> m) {out << "{"; for(T p : m) out << p <<", "; out << "}"; return out; }



int power(long long x, int y, int p){
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0){
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

vi sieve(int n) {
    vi prime(n+1, 1);
    

    prime[0] = prime[1] = 0;
    for(int i=2;i<=n;i++) {
        if(prime[i]) {
            for(int j=i*i;j<=n;j+=i) {prime[j] = 0;}
        }
    }
    return prime;
}













































































const int N = 200005;
vi fac, rfac;
const int M = 1e9+7;
void buildFac(int n = N){
    fac.assign(n, 0); rfac.assign(n, 0);
    fac[0] = rfac[0] = 1;
    for(int i=1;i<n;i++){
        fac[i] = (i*fac[i-1]) % M;
        rfac[i] = power(fac[i], M-2, M);
    }
}

int nCr(int n, int r){
    if(r < 0 || n < 0 || r > n) return 0;
    return (((fac[n]*rfac[r])%M)*rfac[n-r])%M;
}



int n,k;
vvi a;
vi sub;
vi cnt;
void dfs(int c, int p) {
    sub[c] = 1;
    cnt[c] = 0;
    for(int v:a[c]) {
        if(v==p) continue;;
        dfs(v, c);
        sub[c] += sub[v];
        sub[c]%=M;
        cnt[c] += nCr(sub[v], k);
        cnt[c] %=M;
    }
    cnt[c] = (nCr(sub[c], k) - cnt[c] + M) %M;
}
int ans = 0;
int cur = 0;
void reroot(int c, int p) {
    

        

    ans += cur;
    ans %= M;
    

    

    for(int v:a[c]) {
        if(v==p) continue;
        

        int oriCur = cur;
        cur = (cur - cnt[v]*sub[v])%M;
        cur = (cur - cnt[c]*sub[c])%M;
        int oriCntV = cnt[v], oriSubV = sub[v];
        int oriCntC = cnt[c], oriSubC = sub[c];

        sub[c] -= sub[v];
        sub[v] += sub[c];
        cnt[v] = (cnt[v] - nCr(oriSubV, k) + nCr(sub[v], k) + M)%M;
        cnt[v] = (cnt[v] - nCr(sub[c], k));
        cnt[c] = (cnt[c] - nCr(oriSubC, k) + nCr(sub[c], k) + M)%M;
        cnt[c] = (cnt[c] + nCr(oriSubV, k))%M;
        cur = (cur + cnt[v]*sub[v])%M;
        cur = (cur + cnt[c]*sub[c])%M;
        cur %=M;
        
        reroot(v, c);
        cnt[v] = oriCntV; sub[v] = oriSubV;
        cnt[c] = oriCntC; sub[c] = oriSubC;
        cur = oriCur;
        

        

        


        

        

        

    }
    

    cur%=M;
    

    ans %= M;
}
int32_t main() {
    

    

    

    

    buildFac();
    cin>>n>>k;
    a.assign(n, vi());
    sub.assign(n,0);
    cnt.assign(n,0);
    for(int i=0;i<n-1;i++) {
        int u,v; cin>>u>>v; u--; v--;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(0,0);
    

    for(int i=0;i<n;i++) {
        cur += cnt[i] * sub[i];
        cur%=M;
        

        

    }
    

    

    reroot(0,0);
    

    cout << ans <<endl;
    

    

    ans %= M;
    

    

    return 0;
}
#pragma GCC diagnostic pop

  