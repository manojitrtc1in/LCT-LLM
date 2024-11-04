

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
#define nl printf("\n");
#define clbuff fflush(stdin);

mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 1e3 + 2;
const int M = 1e6 + 200;
const int mod = 0;
const int inf = 2e9 + 3;
const ll INF = 1e18;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void files() {
	#ifndef PC
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif
}

int T, n, m, a[N][N], sz;
string s;
pii x[M], y[M], z[M];

void del1(int i, int j) {
	bool f = 0;
	for (int k1 = i; k1 <= i + 1; ++k1) {
		for (int k2 = j; k2 <= j + 1; ++k2) {
			if (a[k1][k2] == 1) {
				sz++;
				x[sz] = {k1, k2};
				y[sz] = {k1 + (i == k1 ? +1 : -1), k2};
				z[sz] = {k1, k2 + (j == k2 ? +1 : -1)};
				f = 1;
				a[x[sz].F][x[sz].S] ^= 1;
				a[y[sz].F][y[sz].S] ^= 1;
				a[z[sz].F][z[sz].S] ^= 1;
			}
			if (f)
				break;
		}
		if (f)
			break;						
	}
}

void del2(int i, int j) {
	bool f = 0;
	for (int k1 = i; k1 <= i + 1; ++k1) {
		for (int k2 = j; k2 <= j + 1; ++k2) {
			if (a[k1][k2] == 1) {
				sz++;
				x[sz] = {k1, k2};
				y[sz] = {k1 + (i == k1 ? +1 : -1), k2};
				z[sz] = {k1, k2 + (j == k2 ? +1 : -1)};
				f = 1;
				a[x[sz].F][x[sz].S] ^= 1;
				a[y[sz].F][y[sz].S] ^= 1;
				a[z[sz].F][z[sz].S] ^= 1;
			}
			if (f)
				break;
		}
		if (f)
			break;						
	}
}

void del22(int i, int j) {
	bool f = 0;
	for (int k1 = i; k1 <= i + 1; ++k1) {
		for (int k2 = j; k2 <= j + 1; ++k2) {
			if (a[k1][k2] == 0) {
				sz++;
				x[sz] = {k1, k2};
				y[sz] = {k1 + (i == k1 ? +1 : -1), k2};
				z[sz] = {k1, k2 + (j == k2 ? +1 : -1)};
				f = 1;
				a[x[sz].F][x[sz].S] ^= 1;
				a[y[sz].F][y[sz].S] ^= 1;
				a[z[sz].F][z[sz].S] ^= 1;
			}
			if (f)
				break;
		}
		if (f)
			break;						
	}
}

void del3(int i, int j) {
	bool f = 0;
	for (int k1 = i; k1 <= i + 1; ++k1) {
		for (int k2 = j; k2 <= j + 1; ++k2) {
			if (a[k1][k2] == 1) {
				if (a[k1 + (i == k1 ? +1 : -1)][k2] == 1 && a[k1][k2 + (j == k2 ? +1 : -1)] == 1) {
					sz++;
					x[sz] = {k1, k2};
					y[sz] = {k1 + (i == k1 ? +1 : -1), k2};
					z[sz] = {k1, k2 + (j == k2 ? +1 : -1)};
					f = 1;
					a[x[sz].F][x[sz].S] ^= 1;
					a[y[sz].F][y[sz].S] ^= 1;
					a[z[sz].F][z[sz].S] ^= 1;
				}
			}
			if (f)
				break;
		}
		if (f)
			break;						
	}	
}

int main() {
	speed_up;
	cin >> T;
	while (T--) {
		sz = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> s;
			for (int j = 1; j <= m; ++j) {
				a[i][j] = s[j - 1] - '0';
			}
		}
		for (int i = 1; i < n; i += 2) {
			for (int j = 1; j < m; j += 2) {
				int sum = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				if (sum == 0) {
					continue;
				}
				if (sum == 1) {
					del1(i, j);
					del2(i, j);
					del3(i, j);					
				}
				if (sum == 2) {
					if (a[i][j] + a[i][j + 1] == 1 && a[i][j] + a[i + 1][j] == 1) {
						del2(i, j);
						del3(i, j);
					}
					else {
						del22(i, j);
						del3(i, j);
					}
				}
				if (sum == 3) {
					del3(i, j);
				}
				if (sum == 4) {
					del1(i, j);
					del1(i, j);
					del2(i, j);
					del3(i, j);					
				}
			}
		}
		for (int i = 1; i < n - 1; i++) {
			for (int j = m - 1; j < m; j++) {
				int sum = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				if (sum == 0) {
					continue;
				}
				if (sum == 1) {
					if (a[i][j] == 1) {
						++sz;
						x[sz] = {i, j};
						y[sz] = {i + 1, j};
						z[sz] = {i + 1, j + 1};			
						a[x[sz].F][x[sz].S] ^= 1;
						a[y[sz].F][y[sz].S] ^= 1;
						a[z[sz].F][z[sz].S] ^= 1;
					}
					else if (a[i][j + 1] == 1) {
						++sz;
						x[sz] = {i, j + 1};
						y[sz] = {i + 1, j};
						z[sz] = {i + 1, j + 1};
						a[x[sz].F][x[sz].S] ^= 1;
						a[y[sz].F][y[sz].S] ^= 1;
						a[z[sz].F][z[sz].S] ^= 1;
					}

				}
				else if (sum == 2) {
					if (a[i][j] + a[i][j + 1] == 1 && a[i][j] + a[i + 1][j] == 1) {
						if (a[i + 1][j] == 0) {
							++sz;
							x[sz] = {i, j};
							y[sz] = {i + 1, j};
							z[sz] = {i + 1, j + 1};
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;
						}
						else if (a[i + 1][j + 1] == 0) {
							++sz;
							x[sz] = {i, j + 1};
							y[sz] = {i + 1, j};
							z[sz] = {i + 1, j + 1};							
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;
						}
					}
					else {
						if (a[i][j] + a[i][j + 1] == 2) {
							++sz;
							x[sz] = {i, j};
							y[sz] = {i, j + 1};
							z[sz] = {i + 1, j + 1};
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;
						}
						else if (a[i][j] + a[i + 1][j] == 2) {
							++sz;
							x[sz] = {i, j};
							y[sz] = {i + 1, j};
							z[sz] = {i + 1, j + 1};
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;
						}
						else if (a[i][j + 1] + a[i + 1][j + 1] == 2) {
							++sz;
							x[sz] = {i, j + 1};
							y[sz] = {i + 1, j + 1};
							z[sz] = {i + 1, j};
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;							
						}
					}
				}
				else if (sum == 3) {
					del3(i, j);
				}
				else if (sum == 4) {
					++sz;
					x[sz] = {i, j};
					y[sz] = {i + 1, j};
					z[sz] = {i + 1, j + 1};	
					a[x[sz].F][x[sz].S] ^= 1;
					a[y[sz].F][y[sz].S] ^= 1;
					a[z[sz].F][z[sz].S] ^= 1;			
				}
			}
		}
		for (int i = n - 1; i < n; i++) {
			for (int j = 1; j < m - 1; j++) {
				int sum = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				if (sum == 0) {
					continue;
				}
				if (sum == 1) {
					if (a[i][j] == 1) {
						++sz;
						x[sz] = {i, j};
						y[sz] = {i, j + 1};
						z[sz] = {i + 1, j + 1};			
						a[x[sz].F][x[sz].S] ^= 1;
						a[y[sz].F][y[sz].S] ^= 1;
						a[z[sz].F][z[sz].S] ^= 1;
					}
					else if (a[i + 1][j] == 1) {
						++sz;
						x[sz] = {i + 1, j};
						y[sz] = {i, j + 1};
						z[sz] = {i + 1, j + 1};
						a[x[sz].F][x[sz].S] ^= 1;
						a[y[sz].F][y[sz].S] ^= 1;
						a[z[sz].F][z[sz].S] ^= 1;
					}

				}
				else if (sum == 2) {
					if (a[i][j] + a[i][j + 1] == 1 && a[i][j] + a[i + 1][j] == 1) {
						if (a[i + 1][j] == 0) {
							++sz;
							x[sz] = {i, j};
							y[sz] = {i, j + 1};
							z[sz] = {i + 1, j + 1};
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;
						}
						else if (a[i + 1][j + 1] == 0) {
							++sz;
							x[sz] = {i, j + 1};
							y[sz] = {i + 1, j};
							z[sz] = {i + 1, j + 1};							
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;
						}
					}
					else {
						if (a[i][j] + a[i][j + 1] == 2) {
							++sz;
							x[sz] = {i, j};
							y[sz] = {i, j + 1};
							z[sz] = {i + 1, j + 1};
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;
						}
						else if (a[i][j] + a[i + 1][j] == 2) {
							++sz;
							x[sz] = {i, j};
							y[sz] = {i + 1, j};
							z[sz] = {i + 1, j + 1};
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;
						}
						else if (a[i + 1][j] + a[i + 1][j + 1] == 2) {
							++sz;
							x[sz] = {i + 1, j};
							y[sz] = {i + 1, j + 1};
							z[sz] = {i, j + 1};
							a[x[sz].F][x[sz].S] ^= 1;
							a[y[sz].F][y[sz].S] ^= 1;
							a[z[sz].F][z[sz].S] ^= 1;							
						}
					}
				}
				else if (sum == 3) {
					del3(i, j);
				}
				else if (sum == 4) {
					++sz;
					x[sz] = {i, j};
					y[sz] = {i + 1, j};
					z[sz] = {i + 1, j + 1};	
					a[x[sz].F][x[sz].S] ^= 1;
					a[y[sz].F][y[sz].S] ^= 1;
					a[z[sz].F][z[sz].S] ^= 1;			
				}
			}
		}
		for (int i = n - 1; i < n; i++) {
			for (int j = m - 1; j < m; j++) {
				int sum = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
				if (sum == 0) {
					continue;
				}
				if (sum == 1) {
					del1(i, j);
					del2(i, j);
					del3(i, j);					
				}
				if (sum == 2) {
					if (a[i][j] + a[i][j + 1] == 1 && a[i][j] + a[i + 1][j] == 1) {
						del2(i, j);
						del3(i, j);
					}
					else {
						del22(i, j);
						del3(i, j);
					}
				}
				if (sum == 3) {
					del3(i, j);
				}
				if (sum == 4) {
					del1(i, j);
					del1(i, j);
					del2(i, j);
					del3(i, j);					
				}
			}
		}
		printf("%d\n", sz);
		for (int i = 1; i <= sz; ++i) {
			printf("%d %d %d %d %d %d\n", x[i].F, x[i].S, y[i].F, y[i].S, z[i].F, z[i].S);
		}
		
		
	}
}
