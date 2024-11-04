











#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
#include <chrono>
#include <random>
#include <functional>
#include <tuple>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <array>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define NDC ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define iMax INT_MAX
#define iMin INT_MIN
#define ll long long
#define ull unsigned long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define get(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define get1(a,n) for(int i=1;i<=n;i++)cin>>a[i]
#define vec(x) vector<x>
#define ins insert
#define nl '\n'
#define yes cout<<"Yes"<<nl
#define no cout<<"No"<<nl

typedef struct vector<ll> vll;
typedef struct vector<ld> vld;
typedef struct vector<vll> vvll;
typedef struct vector<vld> vvld;
typedef struct pair<ll, ll> ii;
const int MOD = 2111992;
const int MX = 10001;
const long long INF = 1e18 + 7;
const long double PI = 3.141592653589793238462643383279;
struct home {
	ll x1 = 0, y1 = 0;
	ll cnt = 0;
};
bool cmp(ll a, ll b) {
	return a > b;
}

void solve(ll testcase) {
	ll n, x; cin >> n;
	ll sum1 = 0, sum2 = 0;
	ll res = 0;
	vll a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(all(a));
	sort(all(b), cmp);
	vll sa(n + 1), sb(n + 1);
	for (int i = 1; i <= n; i++) {
		sa[i] = a[i - 1] + sa[i - 1];
		sb[i] = b[i - 1] + sb[i - 1];
	}
	while (1) {
		ll k = (n + res) / 4;
		ll h = (n + res) - k;
		sum1 = sa[n] + res * 100;
		sum1 -= sa[k];
		sum2 = sb[min(n, h)];
		if (sum1 >= sum2)break;
		res++;
	}
	cout << res << nl;
}

int main() {
	NDC;
	ll i = 1LL;
	ll tc; cin >> tc;
	for (i = 1; i <= tc; i++)
		solve(i);
	return 0;
}

