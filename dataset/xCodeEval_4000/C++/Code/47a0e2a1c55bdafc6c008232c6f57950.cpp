#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<ctime>
#include<deque>
#include<stack>
#include<functional>
#include<sstream>




using namespace std;
#define maxn 1000005
#define inf 0x7fffffff


#define rdint(x) scanf("%d",&x)
#define rdllt(x) scanf("%lld",&x)
#define rdult(x) scanf("%lu",&x)
#define rdlf(x) scanf("%lf",&x)
#define rdstr(x) scanf("%s",x)
typedef long long  ll;
typedef unsigned long long ull;
typedef unsigned int U;
#define ms(x) memset((x),0,sizeof(x))
const long long int mod = 1e9 + 7;
#define Mod 1000000000
#define sq(x) (x)*(x)
#define eps 1e-4
typedef pair<int, int> pii;
#define pi acos(-1.0)


#define REP(i,n) for(int i=0;i<(n);i++)
typedef pair<int, int> pii;
inline ll rd() {
	ll x = 0;
	char c = getchar();
	bool f = false;
	while (!isdigit(c)) {
		if (c == '-') f = true;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -x : x;
}

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
int sqr(int x) { return x * x; }




int h[4], w[4];
char mp[300][300];
char ch[3] = { 'A','B','C' };
int main() {
	

	for (int i = 1; i <= 3; i++) {
		cin >> h[i] >> w[i]; if (h[i] > w[i])swap(h[i], w[i]);
	}
	if ((w[1] == w[2]&&w[2] == w[3]) && h[1] + h[2] + h[3] == w[1]) {
		cout << w[1] << endl;
		for (int i = 1; i <= w[1]; i++) {
			for (int j = 1; j <= h[1]; j++)mp[i][j] = 'A';
		

		}
		for (int i = 1; i <= w[1]; i++) {
			for (int j = h[1] + 1; j <= h[2] + h[1]; j++)mp[i][j] = 'B';
		

		}
		for (int i = 1; i <= w[1]; i++) {
			for (int j = 1 + h[1] + h[2]; j <= w[1]; j++)mp[i][j] = 'C';
		

		}
		for (int i = 1; i <= w[1]; i++) {
			for (int j = 1; j <= w[1]; j++)cout << mp[i][j];
			cout << endl;
		}
		return 0;
	}
	else {
		int pos = 0;
		int maxx = 0;
		for (int i = 1; i <= 3; i++) {
			if (w[i] > maxx) {
				maxx = w[i]; pos = i;
			}
		}
		if (pos == 1) {
			if (h[2] + h[3] == w[1]) {
				if (w[3] == w[2] && w[2] + h[1] == w[1]) {
					cout << w[1] << endl;
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1; j <= h[1]; j++)mp[i][j] = 'A';
						

					}
					for (int i = 1; i <= h[2]; i++) {
						for (int j = 1 + h[1]; j <= w[1]; j++)mp[i][j] = 'B';
						

					}
					for (int i = 1 + h[2]; i <= w[1]; i++)
						for (int j = 1 + h[1]; j <= w[1]; j++)mp[i][j] = 'C';
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1; j <= w[1]; j++)cout << mp[i][j];
						cout << endl;
					}
					return 0;
				}
			}
			else if (h[2] + w[3] == w[1]) {
				if (w[2] == h[3] && w[2] + h[1] == w[1]) {
					cout << w[1] << endl;
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1; j <= h[1]; j++)mp[i][j] = 'A';
						

					}
					for (int i = 1; i <= h[2]; i++) {
						for (int j = 1 + h[1]; j <= w[1]; j++)mp[i][j] = 'B';
						

					}
					for (int i = 1 + h[2]; i <= w[1]; i++)
						for (int j = 1 + h[1]; j <= w[1]; j++)mp[i][j] = 'C';
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1; j <= w[1]; j++)cout << mp[i][j];
						cout << endl;
					}
					return 0;
				}
			}
			else if (w[2] + h[3] == w[1]) {
				if (h[2] == w[3] && h[2] + h[1] == w[1]) {
					cout << w[1] << endl;
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1; j <= h[1]; j++)mp[i][j] = 'A';
						

					}
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1 + h[1]; j <= w[1]; j++)mp[i][j] = 'B';
						

					}
					for (int i = 1 + w[2]; i <= w[1]; i++)
						for (int j = 1 + h[1]; j <= w[1]; j++)mp[i][j] = 'C';
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1; j <= w[1]; j++)cout << mp[i][j];
						cout << endl;
					}
					return 0;
				}
			}
			else if (w[2] + w[3] == w[1]) {
				if (h[2] == h[3] && h[2] + h[1] == w[1]) {
					cout << w[1] << endl;
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1; j <= h[1]; j++)mp[i][j] = 'A';
						

					}
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1 + h[1]; j <= w[1]; j++)mp[i][j] = 'B';
						

					}
					for (int i = 1 + w[2]; i <= w[1]; i++)
						for (int j = 1 + h[1]; j <= w[1]; j++)mp[i][j] = 'C';
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1; j <= w[1]; j++)cout << mp[i][j];
						cout << endl;
					}
					return 0;
				}
			}
		}

		else if (pos == 2) {
			if (h[1] + h[3] == w[2]) {
				if (w[3] == w[1] && w[1] + h[2] == w[2]) {
					cout << w[2] << endl;
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1; j <= h[2]; j++)mp[i][j] = 'B';
						

					}
					for (int i = 1; i <= h[1]; i++) {
						for (int j = 1 + h[2]; j <= w[2]; j++)mp[i][j] = 'A';
						

					}
					for (int i = 1 + h[1]; i <= w[2]; i++)
						for (int j = 1 + h[2]; j <= w[2]; j++)mp[i][j] = 'C';
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1; j <= w[2]; j++)cout << mp[i][j];
						cout << endl;
					}
					return 0;
				}
			}
			if (h[1] + w[3] == w[2]) {
				if (h[3] == w[1] && w[1] + h[2] == w[2]) {
					cout << w[2] << endl;
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1; j <= h[2]; j++)mp[i][j] = 'B';
						

					}
					for (int i = 1; i <= h[1]; i++) {
						for (int j = 1 + h[2]; j <= w[2]; j++)mp[i][j] = 'A';
						

					}
					for (int i = 1 + h[1]; i <= w[2]; i++)
						for (int j = 1 + h[2]; j <= w[2]; j++)mp[i][j] = 'C';
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1; j <= w[2]; j++)cout << mp[i][j];
						cout << endl;
					}
					return 0;
				}
			}
			if (w[1] + h[3] == w[2]) {
				if (w[3] == h[1] && h[1] + h[2] == w[2]) {
					cout << w[2] << endl;
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1; j <= h[2]; j++)mp[i][j] = 'B';
						

					}
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1 + h[2]; j <= w[2]; j++)mp[i][j] = 'A';
						

					}
					for (int i = 1 + w[1]; i <= w[2]; i++)
						for (int j = 1 + h[2]; j <= w[2]; j++)mp[i][j] = 'C';
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1; j <= w[2]; j++)cout << mp[i][j];
						cout << endl;
					}
					return 0;
				}
			}
			if (w[1] + w[3] == w[2]) {
				if (h[3] == h[1] && h[1] + h[2] == w[2]) {
					cout << w[2] << endl;
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1; j <= h[2]; j++)mp[i][j] = 'B';
						

					}
					for (int i = 1; i <= w[1]; i++) {
						for (int j = 1 + h[2]; j <= w[2]; j++)mp[i][j] = 'A';
						

					}
					for (int i = 1 + w[1]; i <= w[2]; i++)
						for (int j = 1 + h[2]; j <= w[2]; j++)mp[i][j] = 'C';
					for (int i = 1; i <= w[2]; i++) {
						for (int j = 1; j <= w[2]; j++)cout << mp[i][j];
						cout << endl;
					}
					return 0;
				}
			}
		}
		else {
		if (h[1] + h[2] == w[3]) {
			if (w[2] == w[1] && w[1] + h[3] == w[3]) {
				cout << w[3] << endl;
				for (int i = 1; i <= w[3]; i++) {
					for (int j = 1; j <= h[3]; j++)mp[i][j] = 'C';
					

				}
				for (int i = 1; i <= h[1]; i++) {
					for (int j = 1 + h[3]; j <= w[3]; j++)mp[i][j] = 'A';
					

				}
				for (int i = 1 + h[1]; i <= w[3]; i++)
					for (int j = 1 + h[3]; j <= w[3]; j++)mp[i][j] = 'B';
				for (int i = 1; i <= w[3]; i++) {
					for (int j = 1; j <= w[3]; j++)cout << mp[i][j];
					cout << endl;
				}
				return 0;
			}
		}
		if (h[1] + w[2] == w[3]) {
			if (h[2] == w[1] && w[1] + h[3] == w[3]) {
				cout << w[3] << endl;
				for (int i = 1; i <= w[3]; i++) {
					for (int j = 1; j <= h[3]; j++)mp[i][j] = 'C';
					

				}
				for (int i = 1; i <= h[1]; i++) {
					for (int j = 1 + h[2]; j <= w[3]; j++)mp[i][j] = 'A';
					

				}
				for (int i = 1 + h[1]; i <= w[3]; i++)
					for (int j = 1 + h[3]; j <= w[3]; j++)mp[i][j] = 'B';
				for (int i = 1; i <= w[3]; i++) {
					for (int j = 1; j <= w[3]; j++)cout << mp[i][j];
					cout << endl;
				}
				return 0;
			}
		}
		if (w[1] + h[2] == w[3]) {
			if (w[2] == h[1] && h[1] + h[3] == w[3]) {
				cout << w[3] << endl;
				for (int i = 1; i <= w[3]; i++) {
					for (int j = 1; j <= h[3]; j++)mp[i][j] = 'C';
					

				}
				for (int i = 1; i <= w[1]; i++) {
					for (int j = 1 + h[3]; j <= w[3]; j++)mp[i][j] = 'A';
					

				}
				for (int i = 1 + w[1]; i <= w[3]; i++)
					for (int j = 1 + h[3]; j <= w[3]; j++)mp[i][j] = 'B';
				for (int i = 1; i <= w[3]; i++) {
					for (int j = 1; j <= w[3]; j++)cout << mp[i][j];
					cout << endl;
				}
				return 0;
			}
		}
		if (w[1] + w[2] == w[3]) {
			if (h[2] == h[1] && h[1] + h[3] == w[3]) {
				cout << w[3] << endl;
				for (int i = 1; i <= w[3]; i++) {
					for (int j = 1; j <= h[3]; j++)mp[i][j] = 'C';
					

				}
				for (int i = 1; i <= w[1]; i++) {
					for (int j = 1 + h[3]; j <= w[3]; j++)mp[i][j] = 'A';
					

				}
				for (int i = 1 + w[1]; i <= w[3]; i++)
					for (int j = 1 + h[3]; j <= w[3]; j++)mp[i][j] = 'B';
				for (int i = 1; i <= w[3]; i++) {
					for (int j = 1; j <= w[3]; j++)cout << mp[i][j];
					cout << endl;
				}
				return 0;
			}
		}
		}

	}
	cout << -1 << endl;
	return 0;
}