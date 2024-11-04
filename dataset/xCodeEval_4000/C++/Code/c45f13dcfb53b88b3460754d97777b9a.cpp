#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long double				ld;
typedef long long int			int64;
typedef unsigned long long int  uint64;
typedef pair<int, int>			PII;
typedef vector<int>				VI;
typedef vector<long long>		VLL;
typedef vector<PII>				VII;
typedef vector<VI>				VVI;

#define MEM(a, b)				memset(a, (b), sizeof(a))
#define clr(a)					fill(a, 0)
#define FOR(i, j, k, in)		for (int i = (j); i < (k); i += (in))
#define FORW(i, j, k, in)		for (int i = (j); i <= (k); i += (in))
#define RFOR(i, j, k, in)		for (int i = (j); i >= (k); i -= (in))
#define all(cont)				cont.begin(), cont.end()
#define sz(cont)				int((cont).size())
#define pb						push_back
#define mp						make_pair
#define fi						first
#define se						second
#define IINF					0x3f3f3f3f
#define LLINF					1000111000111000111LL
#define PI						3.1415926535897932384626433832795
#define FastIO					ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define fileio(name)			ifstream cin(name".inp"); ofstream cout(name".out");
#define endl					'\n'

template<typename T, typename U> inline void amin(T& x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T& x, U y) { if (x < y) x = y; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, int64 m = LLONG_MAX) { if (y < 0) return 1.0 / power(x, -y, m); T ans = 1; x %= m; while (y > 0) { if (y & 1LL) ans = (ans * x) % m; y >>= 1LL; x = (x * x) % m; } return ans % m; }




int n, m;
bool check(int i, int j) { return 1 <= i && i <= n && 1 <= j && j <= m; }

struct pos {
	int y1, x1, y2, x2, y3, x3;
};

int main() {
	FastIO;
#ifdef _DEBUG
	fileio("input");
#elif !defined(ONLINE_JUDGE)	

	fileio("input");				

#endif	


	int t; cin >> t;
	int a[105][105];
	while (t--) {
		cin >> n >> m;
		FORW(i, 1, n, 1) FORW(j, 1, m, 1) {
			char c; cin >> c;
			a[i][j] = c - '0';
		}

		vector<pos> ans;
		bool ok;
		while (1) {
			ok = 1;
			

			FORW(i, 1, n, 1) FORW(j, 1, m, 1) {
				if (a[i][j] == 1) {
					if (check(i + 1, j + 1)) {
						


						ans.push_back({ i,j,i + 1,j,i,j + 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
						ans.push_back({ i,j,i + 1,j,i + 1,j + 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
						ans.push_back({ i,j,i,j + 1,i + 1,j + 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
					}
					else if (check(i + 1, j - 1) ) {
						


						ans.push_back({ i, j, i + 1, j, i , j - 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
						ans.push_back({ i, j, i + 1, j, i + 1 , j - 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
						ans.push_back({ i, j, i + 1, j - 1, i , j - 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
					}
					else if (check(i - 1, j - 1)) {
						


						ans.push_back({ i, j, i - 1, j, i , j - 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
						ans.push_back({ i, j, i - 1, j, i - 1 , j - 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
						ans.push_back({ i, j, i, j - 1, i - 1 , j - 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
					}
					else if (check(i - 1, j + 1) ) {
						


						ans.push_back({ i, j, i - 1, j, i , j + 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
						ans.push_back({ i, j, i - 1, j + 1, i , j + 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
						ans.push_back({ i, j, i - 1, j, i - 1 , j + 1 });
						a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1] = !a[ans[sz(ans) - 1].y1][ans[sz(ans) - 1].x1]; a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2] = !a[ans[sz(ans) - 1].y2][ans[sz(ans) - 1].x2]; a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3] = !a[ans[sz(ans) - 1].y3][ans[sz(ans) - 1].x3];
					}
				}
			}
			FORW(i, 1, n, 1) FORW(j, 1, m, 1) if (a[i][j] == 1) ok = 0;
			if (ok) break;
		}

		cout << ans.size() << endl;
		FOR(i, 0, sz(ans), 1) cout << ans[i].y1 << " " << ans[i].x1 << " " << ans[i].y2 << " "
			<< ans[i].x2
			<< " " << ans[i].y3 << " " << ans[i].x3 << endl;
	}

	

	return 0;
}