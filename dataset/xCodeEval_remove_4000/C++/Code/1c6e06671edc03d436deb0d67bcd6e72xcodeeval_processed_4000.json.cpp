











using namespace std;

template<typename T> void uin(T &a, T b) {if (b < a) a = b;}
template<typename T> void uax(T &a, T b) {if (b > a) a = b;}




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> pref;
		int lg = 0;
		while ((1 << lg) <= n) lg++;
		pref.emplace_back(1);
		int sum = 1;
		for (int i = 0; i < lg - 2; ++i) {
			int last = pref.back();
			if (sum + (last * 2) * (lg - i - 1) <= n) {
				pref.emplace_back(last << 1);
				sum += (last << 1);
			} else {
				pref.emplace_back((n - sum) / (lg - i - 1));
				sum += pref.back();
			}
		}
		pref.emplace_back(n - sum);
		
		cout << pref.size() - 1 << '\n';
		for (int i = 0; i < pref.size() - 1; ++i) cout << pref[i + 1] - pref[i] << ' ';
		cout << '\n';
	}
    return 0;
}

