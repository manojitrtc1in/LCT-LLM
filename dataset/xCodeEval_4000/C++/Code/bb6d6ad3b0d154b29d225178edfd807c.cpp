

#include<string>
#include <iostream>
#include<set>
#include <algorithm>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<cmath>
#include <functional> 
#include<fstream>
typedef long long ll;




using namespace std;
ofstream out("output.txt", ios::out);
ifstream in("input.txt", ios::in);


#define MP make_pair
#define PB push_back
#define all(a) (a).begin(), (a).end()










































































































































































































































































































































































































































































































































































































































ll exgcd(ll a, ll b, ll& x, ll& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = exgcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	gcd(b, a % b);
}

ll fastpow(ll a, ll n, ll M) {

	if (n == 0ll) {
		return 1ll;
	}
	if (n % 2 == 1) {
		return (a * fastpow(a, n - 1, M));
	}
	else {
		ll tmp = fastpow(a, n / 2, M) % M;
		return (tmp * tmp) % M;
	}

}

ll divmodP(ll a, ll b, ll M) {
	return (((a % M) * (fastpow(b, M - 2ll, M) % M)) % M);
}

ll mulMOD(ll a, ll b, ll M) {
	return ((a % M + M) * (b % M + M)) % M;
}

ll divmodM(ll a, ll b, ll M) {
	ll x0, y0;
	ll d = exgcd(b, M, x0, y0);
	if (a % d != 0) {
		return -1ll;
	}
	return (mulMOD(a / d, x0, M));
}

ll reverse_el(ll a, ll m) {
	ll x, y;
	ll g = exgcd(a, m, x, y);
	if (g != 1) {
		return -1;
	}
	else {
		x = (x % m + m) % m;
		return x;
	}
}


































































































class LessString : binary_function<string, string, bool> {
public:
	bool operator ()(pair<int, int> a, pair<int, int>b) const {
		if (a.second < b.second) {
			return true;
		}
		else {
			return (a.first < b.first);
		}
	}
};
long long mul(long long a, long long b, long long m) {
	if (b == 1)
		return a;
	if (b % 2 == 0) {
		long long t = mul(a, b / 2, m);
		return (2 * t) % m;
	}
	return (mul(a, b - 1, m) + a) % m;
}
long long pows(long long a, long long b, long long m) {
	if (b == 0)
		return 1;
	if (b % 2 == 0) {
		long long t = pows(a, b / 2, m);
		return mul(t, t, m) % m;
	}
	return (mul(pows(a, b - 1, m), a, m)) % m;
}
bool ferma(long long x) {
	if (x == 2)
		return true;
	srand(time(NULL));
	for (int i = 0;i < 100;i++) {
		long long a = (rand() % (x - 2)) + 2;
		if (gcd(a, x) != 1)
			return false;
		if (pows(a, x - 1, x) != 1)
			return false;
	}
	return true;
}













































void dfs(const vector<vector<int>>& g, int v, int prev, bool& ans, vector<int>& h, vector<int>& p, int sum = 0) {


	for (auto to : g[v]) {
		if (to == prev) continue;
		
		dfs(g, to, v, ans, h, p);
		sum += p[to];
	}
	if (abs(h[v]) - p[v] > sum) {
		ans &= false;
	}

}

ll mod = 1791791791;
ll cur , a, b;
vector<int> vec;
ll NextRand() {
	 cur = (cur * a + b) % mod;
	return cur;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	

	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n>> m;
		vector<string> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i][m - 1] == 'R') {
				ans++;
			}
		}
		for (int i = 0; i < m - 1; i++) {
			if (s[n - 1][i] == 'D') {
				ans++;
			}
		}
		cout << ans<<endl;
	}

}



























