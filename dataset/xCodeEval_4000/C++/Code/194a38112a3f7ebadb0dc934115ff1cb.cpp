#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<pdb> vpd;

#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define vv <vector<vector> >
#define mp make_pair
#define str(a, b) substr((a), (b))
#define rr return
#define r0 return 0
#define mi map<int>
#define ms map<string>
#define ml map<ll>
#define all_sum(a,b) accumulate((a),(b),0)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
void adskiy_razgon(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};
ll nod(ll a, ll b) {
    if(b > a) {
        swap(a, b);
    }
    while(b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll nok(ll a,ll b) {
    return a * b / nod(a, b);
}
void sp(ll a,double b) {
    cout << fixed << setprecision(a) << b;
}
ll binpow (ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return binpow (a, n - 1) * a;
    }
    else {
        ll b = binpow (a, n / 2);
        return b * b;
    }
}

template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
	read(t...);
}
template<class A> void read(vector<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}
string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vector<bool> v) {
    string res;
	FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}

template<size_t S> string to_string(bitset<S> b) {
    string res;
	FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}
template<class A> void write(A x) {
    cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) {
    write(h);
    write(t...);
}
void print() {
     write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}

void yes(bool ok) {
    print((ok ? "YES" : "Yes"));
}
void no(bool ok) {
    print((ok ? "NO" : "No"));

}



void solve() {
    ll x1, y1, x2, y2;
    read(x1, y1, x2, y2);
    ll ans = 0;
    ans += abs(y1 - y2);
    ans += abs(x1 - x2);
    if(x1 != x2 && y1 != y2) ans+=2;
    print(ans);
}
int main(){
    adskiy_razgon();
    ll t = 1;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        

        solve();
    }
    r0;
}
