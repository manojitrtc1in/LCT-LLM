















































































































 
using namespace std;
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}












using ll = long long;
using ld = long double; 
const int MAXN = 200228;


int n;
int p[MAXN];
int dp[MAXN][2];
int dp1[MAXN][2];
int last[MAXN][2];



struct rmq{
	vector<int> d;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss, 0);
	}
	void change(int i, int val) {
		i += ss;
		d[i] = val;
		while (i >> 1 > 0) {
			i >>= 1;
			d[i] = max(d[i * 2], d[i * 2 + 1]);
		}
	}
	int getmax(int l, int r) {
		l += ss;
		r += ss;
		int ans = 0;
		while (l <= r) {
			if (l & 1) {
				chkmax(ans, d[l]);
				l++;
			}
			if (!(r & 1)) {
				chkmax(ans, d[r]);
				r--;
			}
			l >>= 1;
			r >>= 1;
		}
		return ans;
	}
} kek[2];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	kek[0].init(n);
	kek[1].init(n);
	

	

	for (int i = n - 2; i >= 0; i--) {
		dp1[i][0] = dp1[i][1] = i + 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		last[i][0] = last[i][1] = i;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (p[i] < p[i + 1]) {
			chkmax(last[i][0], last[i + 1][0]);
		}
		if (p[i] > p[i + 1]) {
			chkmax(last[i][1], last[i + 1][1]);
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (i + 2 < n) {
		if (p[i] < p[i + 2]) {
			chkmax(dp1[i][0], dp1[i + 1][1]);
		}
		if (p[i] > p[i + 2]) {
			chkmax(dp1[i][1], dp1[i + 1][0]);
		}
		{

			int j = last[i + 1][1];
			chkmax(dp1[i][0], j);
			if (j + 1 < n) {
				if (p[i] < p[j + 1]) {
					chkmax(dp1[i][0], dp1[j][1]);
				}
			}
			{
				int l = i + 1;
				int r = j - 1;
				if (l <= r) {
					if (p[l + 1] > p[i]) {
						while (l < r) {
							int mid = (l + r + 1) >> 1;
							if (p[mid + 1] > p[i]) {
								l = mid;
							} else {
								r = mid - 1;
							}
						}
						chkmax(dp1[i][0], kek[1].getmax(i + 1, l));
					}
				}
			}
		}
		{

			int j = last[i + 1][0];
			chkmax(dp1[i][1], j);
			if (j + 1 < n) {
				if (p[i] > p[j + 1]) {
					chkmax(dp1[i][1], dp1[j][0]);
				}
			}
			{
				int l = i + 1;
				int r = j - 1;
				if (l <= r) {
					if (p[l + 1] < p[i]) {
						while (l < r) {
							int mid = (l + r + 1) >> 1;
							if (p[mid + 1] < p[i]) {
								l = mid;
							} else {
								r = mid - 1;
							}
						}
						chkmax(dp1[i][1], kek[0].getmax(i + 1, l));
					}
				}
			}
		}
		}
		kek[0].change(i, dp1[i][0]);
		kek[1].change(i, dp1[i][1]);
	}
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		dp[i][0] = dp[i][1] = i;
		if (i + 1 < n) {
			chkmax(dp[i][0], dp1[i][0]);
			chkmax(dp[i][1], dp1[i][1]);
			if (p[i] < p[i + 1]) {
				chkmax(dp[i][0], dp[i + 1][0]);
			} else {
				chkmax(dp[i][1], dp[i + 1][1]);
			}
		}
		ans += max(dp[i][0], dp[i][1]) - i + 1;
	}
	cout << ans << '\n';
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	

	while (t--) {
		solve();
	}
}
