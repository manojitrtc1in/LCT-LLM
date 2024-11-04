











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
#include <unordered_map>
using namespace std;

#define NDC ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define iMax INT_MAX
#define iMin INT_MIN
#define ll long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define nl '\n'
#define yes cout<<"Yes"<<nl
#define no cout<<"No"<<nl

typedef struct vector<ll> vll;
typedef struct vector<ld> vld;
typedef struct vector<vll> vvll;
typedef struct vector<vld> vvld;
typedef struct pair<ll, ll> ii;
const int MOD = 1e9 + 7;
const int MX = 1e5 + 7;
const long double PI = 3.141592653589793238462643383279;
struct defaut {
	ll cnt = 0;
};

int dem(ll x) {
	int cnt = 0;
	if (x == 1)return 0;
	while (x % 2 == 0) cnt++, x /= 2;
	for (int i = 3; i * i <= x; i += 2) {
		while (x % i == 0 and x > 1) cnt++, x /= i;
	}
	if (x > 1) cnt++;
	return cnt;
}

void solve(ll testcase) {
	ll n, m; cin >> n >> m;
	string s, st; cin >> s;
	vll a;
	ll cnt;
	for (int i = 0; i < m; i++) {
		cnt = 0;
		a.clear();
		if (s[0] == '0' && s[1] == '1') {
			cnt++;
			a.push_back(0);
		}
		if (s[n - 1] == '0' && s[n - 2] == '1') {
			cnt++;
			a.push_back(n - 1);
		}
		for (int j = 1; j < n - 1; j++) {
			if (s[j] == '0')
				if (s[j - 1] == '0' and s[j + 1] == '1') a.push_back(j);
				else if (s[j - 1] == '1' and s[j + 1] == '0') a.push_back(j);
		}
		if (a.size() + cnt == 0) break;
		else {
			for (auto x : a) s[x] = '1';
		}
	}
	cout << s << nl;
}

int main() {
	NDC;
	ll tc; ll i = 0;
	cin >> tc; for (i = 1; i <= tc; i++)
		solve(i);
	return 0;
}
