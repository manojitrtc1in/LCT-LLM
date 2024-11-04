#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <functional>

using namespace std;

template<typename T> void uin(T &a, T b) {if (b < a) a = b;}
template<typename T> void uax(T &a, T b) {if (b > a) a = b;}

#define all(v) v.begin(), v.end()

const int N2 = (1 << 16) + 3;
const int INF = 1e9 + 228;

bool relax(int &a, int b) {
	if (a == 0 || b < a) {
		a = b;
		return 1;
	}
	return 0;
}

int dp[16][16][N2];
pair<int,int> last[16][16][N2];
int sum[N2], FIRST_BIT[N2];

int n;
void print(int mask) {
	for (int i = 0; i < n; ++i) cout << ((mask >> i) & 1);
	cout << endl;
}

void solve() {
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int mask = 0; mask < (1 << n); ++mask) {
		sum[mask] = 0;
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) sum[mask] += a[i];
		}
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				FIRST_BIT[mask] = i;
				break;
			}
		}
	}
	

	for (int cnt = 0; cnt <= n; ++cnt) {
		for (int p = 0; p < n; ++p) {
			for (int mask = 0; mask < (1 << n); ++mask) dp[cnt][p][mask] = 0;
		}
	}
	

	for (int mask = 1; mask < (1 << n); ++mask) {
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				dp[1][i][mask] = sum[mask];
				last[1][i][mask] = {mask, -1};
				break;
			}
		}
	}
	vector<int> fb(n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			fb[i] |= (1 << j);
		}
	}
	for (int cnt = 1; cnt < n; ++cnt) {
		for (int p = 0; p < n; ++p) {
			for (int mask = 1; mask < (1 << n); ++mask) {
				if (!dp[cnt][p][mask]) continue;
				int rest = ((1 << n) - 1) ^ mask;
				for (int submask = rest; submask; submask = (submask - 1) & rest) {
					if (dp[cnt][p][mask] < sum[submask] && (submask & fb[p])) {
						if (relax(dp[cnt + 1][FIRST_BIT[submask & fb[p]]][mask | submask], sum[submask])) {
							last[cnt + 1][ FIRST_BIT[submask & fb[p]] ][mask | submask] = {submask, p};
						}
					}
				}
			}
		}
	}
	int ans = INF;
	int Cnt = 0;
	int P = 0;
	int Mask = 0;
	bool found = 0;
	for (int cnt = n; cnt; --cnt) {
		for (int p = 0; p < n; ++p) {
			for (int mask = (1 << n) - 1; mask < (1 << n); ++mask) {
				if (dp[cnt][p][mask] != 0) {
					ans = n - cnt;
					Cnt = cnt;
					P = p;
					Mask = mask;
					found = 1;
					break;
				}
			}
			if (found) break;
		}
		if (found) break;
	}
	cout << ans << '\n';
	vector<int> masks;
	vector<int> ps;
	while (Cnt) {
		ps.emplace_back(P);
		int msk = last[Cnt][P][Mask].first;
		int np = last[Cnt][P][Mask].second;
		masks.emplace_back(msk);
		Mask ^= msk;
		P = np;
		--Cnt;
	}
	reverse(all(masks));
	reverse(all(ps));
	vector<int> ava(n);
	for (int i = 0; i < n; ++i) ava[i] = 1;
	function<int(int)> get = [&] (int i) {
		int pos = 0;
		for (int j = 0; j < i; ++j) pos += ava[j];
		return pos;
	};
	function<void(int)> del = [&] (int i) {
		ava[i] = 0;
	};
	for (int it = 0; it < (int)masks.size(); ++it) {
		int mask = masks[it];
		int pos = ps[it];
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				if (i != pos) {
					cout << get(i) + 1 << ' ' << get(pos) + 1 << '\n';
					del(i);
				}
			}
		}
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
    return 0;
}

