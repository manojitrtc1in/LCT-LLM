



























using namespace std;
set<ll>del;
vector<set<ll>>g;
vector<ll>visit;
set<ll>put;
ll timer, otv = 0, x, y;
bool kl = 0;
void dfs1(ll v) {
	visit[v] = timer;
	if (kl == 0) {
		put.insert(v);
		if (v == y) {
			kl = 1;
		}
	}
	for (auto& i : g[v]) {
		if (visit[i] != timer) {
			dfs1(i);
		}
	}
	if (kl == 0) {
		put.erase(v);
	}
}
void dfs2(ll v) {
	visit[v] = timer;
	otv++;
	for (auto& i : g[v]) {
		if (put.find(i) == put.end() && visit[i] != timer) {
			dfs2(i);
		}
	}
	otv++;
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		string st, st1;
		cin >> n;
		cin >> st;
		cin >> m;
		map<char, ll>a;
		char k;
		for (int i = 0; i < m; i++) {
			cin >> k;
			a[k] = 1;
		}
		reverse(st.begin(), st.end());
		ll pos = -1;
		set<ll>p;
		for (int i = 0; i < n; i++) {
			if (a[st[i]] == 1) {
				if (pos == -1) { pos = i + 1ll; }
				p.insert(i);
			}
		}
		if (pos == -1) {
			cout << 0 << '\n';
		}
		else {
			stack<pair<ll, ll>>b;
			ll ft = 0;
			for (int i = pos; i < n; i++) {
				if (a[st[i]] == 0) {
					if (b.size() == 0) {
						ft++;
					}
					else {
						b.top()f--;
						b.top()s++;
						while (b.top()f == 0) {
							b.pop();
							if (b.size() == 0) { break; }
						}
					}
				}
				else {
					if (b.size() == 0) {
						ft++;
						b.push(mp(ft, 0));
					}
					else {
						b.top()f--;
						b.top()s++;
						b.push(mp(b.top()s, 0));
						while (b.top()f == 0) {
							b.pop();
							if (b.size() == 0) break;
						}
					}
				}
			}
			cout << ft << '\n';
		}
	}
}
