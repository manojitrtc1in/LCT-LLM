
















using namespace std;



typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;





















const int szT = (1 << 17) - 1;
const int oo = 1e9 + 5;

int n, k, a[szT], t[12][szT * 4], ans;

void upd (int num, int pos, int x) {
	pos += szT;
	t[num][pos] += x;
	while ((pos >>= 1) >=  1) {
		t[num][pos] = t[num][pos << 1] + t[num][(pos << 1) ^ 1];
	}
}

int get (int num, int l, int r) {
	int res = 0;
	for (l += szT, r += szT; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[num][l++];
		if (!(r & 1)) res += t[num][r--];
		if (l > r) break;
	}
	return res;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (k == 0) {
        cout << n;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= k; ++j) {
            int cur = get(j-1, 1, a[i]-1);
            upd(j, a[i], cur);
        }
        

        ans += get(k, 1, a[i]-1);
        upd(1, a[i], 1);
    }
    cout << ans;
}

 main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	while (tt --) {
		solve();
	}
	return 0;
}
