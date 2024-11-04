
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE 
#define namdc chienngu 
#endif 
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) 
#define iMax INT_MAX
#define iMin INT_MIN
#define ll long long
#define ull unsigned
#define ld long double
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define nl '\n'
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define pq priority_queue
typedef struct vector<ll> vll;
typedef struct vector<ld> vld;
typedef struct vector<vll> vvll;
typedef struct vector<vld> vvld;
typedef struct pair<ll, ll> pll;
const int MOD = (int)1e9 + 7;
const int MX = (int)2e5 + 5;
const long long INF = 1e18 + 7;
const long double PI = 3.141592653589793238462643383279;

void solve(ll tc) {
	int n;cin >> n;
	map<char, int> mp;
	vector<string> a(2 * n+1);
	for (int i = 0; i < 2 *n+1; i++) {
		cin >> a[i];
		for (auto x : a[i]) {
			mp[x]++;
		}
	}
	for(auto [x,y]:mp){
	    if(y%2)cout<<x<<nl;
	}
}
int main() {
	fast;
#ifdef namdc
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << setprecision(10) << fixed;
	ll tc = 1;
	ll i = 1;
	cin >> tc;
	for (i = 1; i <= tc; i++)
		solve(i);
	return (0 - 0);
}
