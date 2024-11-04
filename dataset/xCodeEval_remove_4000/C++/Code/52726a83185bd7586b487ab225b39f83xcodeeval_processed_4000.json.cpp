



























using namespace std;
int main() {
	ifstream fin("cowart.in");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		string st;
		ll n;
		cin >> st;
		cin >> n;
		ll dl = st.size();
		vector<string>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<ll>>can(dl);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= dl - a[i].size(); j++) {
				string st1 = "";
				for (int z = 0; z < a[i].size(); z++) {
					st1 += st[j + z];
				}
				if (st1 == a[i]) {
					can[j].push_back(i);
				}
			}
		}
		ll nac = 0, kon = 0, dl_l = -1, el = -1;
		for (auto& i : can[0]) {
			if (a[i].size() > dl_l) {
				dl_l = a[i].size();
				el = i;
			}
		}
		vector<pair<ll, ll>>otv;
		bool net = 0;
		if (dl_l != -1) {
			otv.push_back({ el + 1ll,1ll });
			nac++; kon = a[el].size();
			while (kon != dl) {
				ll el_k = -1, pos;
				for (int j = nac; j <= kon; j++) {
					for (auto& i : can[j]) {
						if (j + a[i].size() > el_k) {
							el_k = j + a[i].size();
							el = i;
							pos = j;
						}
					}
				}
				if (el_k <= kon) {
					net = 1;
					dl = kon;
				}
				else {
					otv.push_back({ el + 1ll,pos + 1ll });
					nac = kon + 1;
					kon = el_k;
				}
			}
			if (kon == dl && net==0) {
				cout << otv.size() << endl;
				for (auto& i : otv) {
					cout << i.first << ' ' << i.second << endl;
				}
			}
			else { cout << -1 << endl; }
		}
		else {
			cout << -1 << endl;
		}
	}


}


