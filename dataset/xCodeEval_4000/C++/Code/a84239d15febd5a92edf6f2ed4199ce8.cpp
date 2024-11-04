#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <cmath>
#include <set>
#include <string.h>
#include <bits/stdc++.h>
 
 
 
using namespace std;
 
const double EPS = 1e-6;
const int PRECISION = 20;
const int MOD = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
#define forr(n, arr) for (ll i = 0; i < n; i++) cin >> arr[i];
#define all(arr) arr.begin(), arr.end()
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second
 
 






 
 
 
struct matrix {
 
    vector<vector<ll>> a;
    int DIM;
    matrix(ll d) {
        DIM = d;
        a.resize(DIM, vector<ll>(DIM, 0));
    }
 
    matrix operator* (matrix b) {
        matrix c(b.DIM);
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                for (int z = 0; z < DIM; z++) {
                    c.a[i][j] += (a[i][z] % 10) * (b.a[z][j] % 10);
                    c.a[i][j] %= 10;
                }
            }
        }
        return c;
    }
 
    matrix operator+ (matrix b) {
        matrix c(b.DIM);
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                c.a[i][j] = (b.a[i][j] + a[i][j]) % 10;
 
            }
        }
        return c;
    }
    void operator+= (matrix b) {
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                a[i][j] = (b.a[i][j] + a[i][j]) % 10;
            }
        }
    }
 
    bool operator== (matrix b) {
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                if ((b.a[i][j] % 10) != (a[i][j] % 10))
                    return false;
            }
        }
        return true;
    }
 
    void mult(matrix b, matrix c) {
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                for (int z = 0; z < DIM; z++) {
                    c.a[i][j] += (a[i][z] % 10) * (b.a[z][j] % 10);
                    c.a[i][j] %= 10;
                }
            }
        }
    }
};
 
 
struct segmentTree {
 
    vector<ll> tree;
 
    explicit segmentTree(const vector<ll> &arr) {
        tree.resize((arr.size() + 10) * 4);
        init(arr, 0, arr.size() - 1, 1);
    }
 
    void init(const vector<ll> &arr, ll l, ll r, ll ind) {
        if (l == r) {
            tree[ind] = arr[l];
        } else {
            ll mid = (r + l) / 2;
            init(arr, l, mid, ind * 2);
            init(arr, mid + 1, r, ind * 2 + 1);
            tree[ind] = max(tree[ind * 2], tree[ind * 2 + 1]);
        }
    }
 
    ll query(ll left, ll right, ll n) {
        return maxQuery(left, right, 0, n - 1, 1);
    }
 
    ll maxQuery(ll l, ll r, ll tl, ll tr, ll ind) {
        if (l > tr || r < tl)
            return LLONG_MIN;
        if (l >= tl && r <= tr) {
            return tree[ind];
        }
        ll mid = (tl + tr) / 2;
        return max(maxQuery(l, min(r, mid), tl, mid, ind * 2), maxQuery(max(l, mid + 1), r, mid + 1, tr, ind * 2 + 1));
    }
};
 
struct node {
    ll val;
    node* next;
    node* prev;
    bool initialPos;
    node(int v) {
        val = v;
        next = nullptr;
        prev = nullptr;
        initialPos = true;
    }
};
 
 
struct group {
    ll mul, last, gcd;
    group(ll m, ll l, ll lm){
        mul = m;
        last = l;
        gcd = lm;
    }
};
 
bool tryBoxes(ll mid, vector<ll> arr, ll boxes);
 
bool comp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second < p2.second;
}
 
int bs(vector<int> vc, int target) {
    int low = 0, high = vc.size() - 1;
    while (high > low) {
        int mid = ((high - low + 1)/2) + low;
        if (vc[mid] <= target)
            low = mid;
        else
            high = mid - 1;
    }
    return low;
}
 
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
 
ll fastPow(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1)
        return a;
 
    ll x = fastPow(a, n / 2);
    x = (x * x);
    return (n % 2 == 0 ? x : (x * a));
}
 
int char2index(char a) {
    return a >= 'a' ? a - 'a' : a - 'A' + 26;
}
 
int flipCase(char a) {
    return a >= 'a' ? char2index(a - ('a' - 'A')) : char2index(a + ('a' - 'A'));
}
 
void prefix(vector<ll> &arr) {
 
    for (int i = 1; i < arr.size(); i++)
        arr[i] += arr[i - 1];
}
 
ll eval(vector<ll> &coeffs, ll x) {
    ll ans = 0; ll xs = 1;
    for (ll i = coeffs.size() - 1; i >= 0; i--) {
        ans += (coeffs[i] * xs);
        xs *= x;
    }
    return ans;
}
 
 
int bracketToInt(char a) {
    switch (a) {
        case '(': return 1;
        case ')': return -1;
        case '{': return 2;
        case '}': return -2;
        case '[': return 3;
        case ']': return -3;
        case '<': return 4;
        case '>': return -4;
        default:return -1;
    }
}
 
ll findOpposite(ll x, ll y, ll n) {
    ll ans = 0;
 
    if (x - 2 >= 1) {
        if (y - 1 >= 1) ans++;
        if (y + 1 < n) ans++;
    }
 
    if (x + 2 <= n) {
        if (y - 1 >= 1) ans++;
        if (y + 1 <= n) ans++;
    }
 
    if (y - 2 >= 1) {
        if (x + 1 <= n) ans++;
        if (x - 1 >= 1) ans++;
    }
 
    if (y + 2 < n) {
        if (x + 1 <= n) ans++;
        if (x - 1 >= 1) ans++;
    }
 
    return ans;
 
 
}
 

 
ll bs(const vector<ll> &v, ll target) {
 
    ll low = 0;
    ll high = v.size() - 1;
 
    while (low < high) {
        ll mid = ((high - low + 1) / 2) + low;
        if (v[mid] > target)
            high = mid - 1;
        else
            low = mid;
    }
    return low;
}
 
ll bs(const vector<ll> &v, ll target, ll start, ll dest) {
 
    ll low = start;
    ll high = dest;
 
    while (low < high) {
        ll mid = ((high - low) / 2) + low;
        if (v[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return high;
}
 
ll bsForPairs(const vector<pair<ll,ll>> &v, ll target) {
    ll low = 0;
    ll high = v.size() - 1;
 
    while (low < high) {
        ll mid = ((high - low + 1) / 2) + low;
        if (v[mid].X > target)
            high = mid - 1;
        else
            low = mid;
    }
    return low;
}
 
 
 
bool customComp(pair<ll,ll> p1, pair<ll,ll> p2) {
    return p1.second < p2.second;
}
 


long long power(long long x, long long y, int p)
{
    long long res = 1;
 
    x = x % p;
 
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
 long long add(long long a, long long b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}
 long long mul( long long a,  long long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
 
 
ll edit_distance(const string& s, const string& t) {
    vector<vector<ll>> dp(s.size() + 1, vector<ll>(t.size() + 1, 0));
    for (ll i = 0; i < s.size(); i++) {
        dp[i][0] = i;
    }
    for (ll j = 0; j < t.size(); j++) {
        dp[0][j] = j;
    }
 
    for (ll i = 1; i <= s.size(); i++) {
        for (ll j = 1; j <= t.size(); j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
 
    return dp[s.size()][t.size()];
}
 
string reverse(string a) {
    reverse(a.begin(), a.end());
    return a;
}
 
pair<ll,ll> palind(const vector<ll>& s, ll ind) {
    ll len = 1;
    ll start = ind, end = ind;
 
    while (start > 0 && end < s.size() - 1 && s[start] == s[end]) {
        start--; end++;
    }
    if (s[start] != s[end]) {
        start++;
        end--;
    }
 
    len = end - start + 1;
    pair<ll,ll> ans = mp(start, end);
    if(ind == s.size() - 1 || s[ind] != s[ind + 1]) return ans;
 
    start = ind;
    end = start + 1;
 
    while (start > 0 && end < s.size() - 1 && s[start] == s[end]) {
        start--; end++;
    }
    if (s[start] != s[end]) {
        start++;
        end--;
    }
 
    if (len < end - start + 1) {
        return mp(start, end);
    }
    else
        return ans;
 
}
 
 
string arrToString(const vector<ll>& arr) {
    string s;
    for (long long i : arr) {
        s += to_string(i) + ",";
    }
    return s;
}
 
bool cusSort(pair<ll,ll> p, pair<ll,ll> x) {
    if (p.X == x.X)
        return x.Y < p.Y;
    else
        return p.X < x.X;
}
queue<ll> q;
ll k;
void mergeCount(vector<ll>& arr, ll l, ll r) {
    

    if (r - l == 1) {
      arr[l] = q.front();
      q.pop();
      return;
    }
    else if (l >= r) return;
    if (k < 2) {
        for (ll i = r - 1; i >= l; i--) {
            arr[i] = q.front();
            q.pop();
        }
        return;
    }
    k -= 2;
    ll mid = (r + l) / 2;
    mergeCount(arr, l, mid);
    mergeCount(arr, mid, r);
}
 
 

 
void reverse(vector<int> &ls, int low, int high) {
    int slice = high - low + 1;
    for (int i = 0; i < slice / 2; i++) {
        int temp = ls[i + low];
        ls[i + low] = ls[high - i];
        ls[high - i] = temp;
    }
}
 
void swap(int *p, int *qq) {
    int temp = *p;
    *p = *qq;
    *qq = temp;
}
 
ll sumOfDigits(ll a) {
    ll ans = 0;
    while(a != 0) {
        ans += (a % 10);
        a /= 10;
    }
    return ans;
}
 
ll sumGCD(ll a) {
    return gcd(a, sumOfDigits(a));
}
 
 
int main() {
    

    

 
 
 
        

        

       

    

      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
 
      int t;
      cin >> t;
      while(t--) {
          ll a;
          cin >> a;
          while(sumGCD(a) == 1)
              a++;
          cout << a << '\n';
      }
 
 
      

      

      return 0;
}
  	    				 			 	 	   	 		  	 	