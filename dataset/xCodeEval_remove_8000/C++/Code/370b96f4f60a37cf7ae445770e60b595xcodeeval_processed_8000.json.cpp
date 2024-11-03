﻿



























using namespace std;
map<char, ll>a;
ll timer = 1;
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
		string st;
		cin >> n;
		cin >> st;
		cin >> m;
		char k;
		timer++;
		for (int i = 0; i < m; i++) {
			cin >> k;
			a[k] = timer;
		}
		ll pos = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (a[st[i]] == timer) {
				pos = i - 1ll; 
				break;
			}
		}
		if (pos == -1) {
			cout << 0 << '\n';
		}
		else {
			stack<pair<ll, ll>>b;
			ll ft = 0;
			for (int i = pos; i >=0; i--) {
				if (a[st[i]] != timer) {
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
