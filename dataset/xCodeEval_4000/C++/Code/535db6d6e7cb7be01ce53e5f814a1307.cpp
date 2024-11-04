


























































































































































































































































































































































































































































































































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











































































int n;
vector<string> a(2);
int dp[200005][2];
int f(int i, int j) {
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==n-1) return (a[1-j][n-1]=='*');
    return dp[i][j] = min(f(i+1, j) + 1 + (a[1-j][i]=='*'), f(i+1,1-j)+2);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    

    

    int _; cin>>_;
    for(int T=1;T<=_;T++){
    cin>>n;
    cin>>a[0]>>a[1];
    for(int i=0;i<=n;i++) dp[i][0]=dp[i][1] = -1;
    while(a[0][n-1] != '*' and a[1][n-1] != '*') n--;
    int i=0; while(a[0][i]!='*' and a[1][i]!='*') i++;
    cout << min(f(i,0), f(i,1))<<endl;
    

    }
    

    return 0;
}
#pragma GCC diagnostic pop

