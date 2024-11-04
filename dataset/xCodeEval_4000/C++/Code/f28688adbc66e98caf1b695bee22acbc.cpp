#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>


using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int             long long
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> prime;
vector<int> spf(100005, INF);
map<int, int> prime_factor;

int setBit(int n) {
    int count = 0;
    while (n) {n = n & (n - 1); count += 1;}
    return count;
}

int fme(int a, int b, int mod) {
    int rest = 1;
    a = a % mod;
    if (a == 0) return 0;
    while (b) {
        if (b & 1) rest = ((int)1 * rest * a + mod) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return rest;
}

int btod(string s) {
    int len = s.length(), cur = 0, ind = 0;
    for (int i = (len - 1); i >= 0; i--) {
        if (s[i] == '1') cur += pow(2, ind);
        ind++;
    }
    return cur;
}

int extended_euclid(int a, int b) {
    if (b > a) swap(a, b);
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int gcd = extended_euclid(b, a % b);
    int lastx = x, lasty = y;
    x = lasty;
    y = lastx - (a / b) * lasty;
    return gcd;
}

void sieve(int mx) { 

    vector<int> v(mx, 1);
    v[0] = 0, v[1] = 0;
    for (int i = 2; i < mx; i++) {
        if (v[i]) {
            for (int j = i * i; j < mx; j += i) v[j] = 0;
        }
    }
    for (int i = 2; i < mx; i++) {
        if (v[i]) prime.pb(i);
    }
    return;
}

void SPF(int mx) { 

    spf[1] = 1;
    for (int i = 2; i < mx; i ++) {
        if (spf[i] == INF) {
            spf[i] = i;
            for (int j = i * i; j < mx; j += i) spf[j] = min(spf[j], i);
        }
    }
}

void prime_factorisation(int num) { 

    while (num > 1) {
        prime_factor[spf[num]]++;
        num /= spf[num];
    }
    return;
}

void solve() {
    cin >> n; vector<int> arr(n, 0); fo(i, n) cin >> arr[i];
    cin >> x;
    fo(i, n) arr[i] -= x;
    vector<int> cpy(arr);
    fo1(i, n) arr[i] += arr[i - 1];
    stack<int> st; st.push(0); multiset<int> mst; mst.insert(0);
    int ans = n;
    fo1(i, n) {
        int rem = 0;
        if (mst.lower_bound(arr[i]) == mst.end()) {
            

        }
        else {
            auto it = mst.lower_bound(arr[i]);
            int num = *(it);
            if (num == arr[i]) it++;
            if (it != mst.end()) rem = 1;
        }
        debug(i) debug(arr[i]) debug(rem)
        debug(mst)
        if (rem) {
            ans--;
            while (!st.empty()) {
                mst.erase(mst.find(st.top()));
                st.pop();
            }
        }
        else {
            while (!st.empty() && arr[i - 1] >= st.top()) {
                mst.erase(mst.find(st.top()));
                st.pop();
            }
            st.push(arr[i - 1]);
            mst.insert(arr[i - 1]);
        }
    }
    cout << ans << endl;
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    

    freopen("input.txt", "r", stdin);
    

    freopen("output.txt", "w", stdout);
    

    freopen("Errors.txt", "w", stderr);
# endif
    cin >> t;
    fo(i, t) solve();
    return 0;
}


