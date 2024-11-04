
#pragma GCC optimize "trapv"
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <list>
#include <numeric>
#include <stack>
#include <map>
#include <sstream>
#define ll long long
#define ul unsigned long long
#define modu 1000000007
#define f(i,j, n) for (ll i = j; i < n; ++i)
#define fo(i, j, n) for (ll i = j; i >=n; --i)
#define print(x) cout << x << "\n"
#define gi(x) scanf("%lld",&x)
#define gc(x) scanf("%s",&x)
#define ac(arr) accumulate(arr.begin(),arr.end(),0)
#define pb push_back
#define all(o) (o).begin(), (o).end()
#define ff first
#define ss second
#define mp make_pair
#define endl "\n"
using namespace std;


template<class t1, class t2> using pi = pair<t1, t2>;
template<class t> using vi = vector<t>;
template<class t> using vvi = vi<vi<t>>;
template<class t1, class t2> using um = unordered_map<t1, t2>;
template<typename T>
void printv(vi<T>arr) {
    f(i, 0, arr.size())cout << arr[i] << " ";
    cout << "\n";
    

}
template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }
template<class T> inline void amax(T &x, const T &y) { if (x < y) x = y; }





























































struct jutsu {
    int  a, b, c;
};

bool jutsu_compare(pi<ll, ll> s1, pi<ll, ll> s2) {
    return s1.ss > s2.ss;
}

ll ncr(ll n, ll k)
{
    ll res = 1;
    if (k > n - k)
        k = n - k;
    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}






























ll max(ll a, ll b)
{
    return (a > b) ? a : b;
}
ll min(ll a, ll b)
{
    return (a < b) ? a : b;
}


unsigned long long powerMod(ll x,
                            ll y, ll p)
{
    unsigned long long res = 1; 


    x = x % p; 

    


    while (y > 0)
    {

        

        if (y & 1)
            res = (res * x) % p;

        

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;
}



unsigned long long modInverse(unsigned long long n,
                              ll p)
{
    return powerMod(n, p - 2, p);
}





unsigned long long nCrModPFermat(unsigned long long n,
                                 ll r, ll p)
{
    

    if (n < r)
        return 0;
    

    if (r == 0)
        return 1;

    

    

    

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}





void swap(ll &a, ll &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

unsigned long long modFact(ll n)
{
    const unsigned int M = 1000000007;

    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f = (f * i) % M; 

    

    return f;
}
ll fact(ll x) {
    if (x == 1 || x == 0)return 1;
    return (x * (fact(x - 1)));
}
bool binarySearch(vector<ll>arr, ll val, ll i, ll j) {
    if (i > j)return 0;
    if (arr[i + ((j - i) / 2)] == val)return 1;
    if (arr[i + ((j - i) / 2)] < val)return binarySearch(arr, val, i + ((j - i) / 2) + 1, j);
    return binarySearch(arr, val, i, i + ((j - i) / 2) - 1);
}



const int N = 2e5 + 5;
int tree[4 * N];









void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        tree[v] = min(tree[v * 2] , tree[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v] = min(tree[v * 2] , tree[v * 2 + 1]);
    }
}

int sumSeg(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return min(sumSeg(v * 2, tl, tm, l, min(r, tm))
               , sumSeg(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void readSentence(void) {
    string s, t;
    getline(cin, s);
    stringstream sent(s);
    while (getline(sent, t, ' ')) {
        cout << t << " ";
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r, ll &to) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        to = min(to, tree[v]);
        return tree[v];
    }
    ll tm = (tl + tr) / 2;
    return (query(v * 2, tl, tm, l, min(r, tm), to)
            + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, to));
}
void rangebuild(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        tree[v] = a[tr];
    } else {
        ll tm = (tl + tr) / 2;
        rangebuild(a, v * 2, tl, tm);
        rangebuild(a, v * 2 + 1, tm + 1, tr);
        tree[v] = 0;
    }
}

void rangeupdate(ll v, ll tl, ll tr, ll l, ll r, ll add) {
    if (l > r)
        return ;
    if (l == tl && r == tr) {
        tree[v] += (add);
    } else {
        ll tm = (tl + tr) / 2;
        rangeupdate(v * 2, tl, tm, l, min(r, tm), add);
        rangeupdate(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

ll rangeget(ll v, ll tl, ll tr, ll pos) {
    if (tl == tr)
        return tree[v];
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return tree[v] + rangeget(v * 2, tl, tm, pos);
    else
        return tree[v] + rangeget(v * 2 + 1, tm + 1, tr, pos);
}



void bitsetoperation(ll n) {
    string binary = bitset<14>(n).to_string();
    ll decimal = bitset<14>(binary).to_ulong();
}


int isSubstring(string s2, string s1)
{
    int M = s1.length();
    int N = s2.length();

    
    for (int i = 0; i <= N - M; i++) {
        int j;

        
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return 0;
}

































void hinataVSsakura(void);
int main()
{
    

    


#ifndef ONLINE_JUDGE
    

    freopen("input.txt", "r", stdin);

    

    freopen("output.txt", "w", stdout);
#endif
    long long T = 1;
    cin >> T;
    

    ll k = 1;

    while (T--) {
        

        

        hinataVSsakura();
        

    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
}















































           




































void hinataVSsakura(void)
{
    string s;
    cin>>s;
    ll ans=0;
    ll dp[s.size()][2];
    memset(dp,0,sizeof(dp));
    f(i,0,s.size()){
        if(i==0){
            if(s[i]=='?')dp[i][0]=dp[i][1]=1;
            else dp[i][s[i]-'0']=1;
        }
        else{
            if(s[i]=='?')dp[i][0]=dp[i-1][1]+1,dp[i][1]=dp[i-1][0]+1;
            else{
                dp[i][s[i]-'0']+=dp[i-1][(s[i]-'0')^1]+1;
            }
        }
        ans+=max(dp[i][0],dp[i][1]);
    }
    print(ans);
}