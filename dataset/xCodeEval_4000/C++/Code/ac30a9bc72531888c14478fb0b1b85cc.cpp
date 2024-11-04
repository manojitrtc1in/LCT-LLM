
#include <unordered_set>
#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <random>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>
using namespace std;
#define x first
#define y second
#define int long long
typedef long long ll;
typedef long double ld;

int topcoder[26];
int ioi[26][26][5101];

signed main() {
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n = s.size();
	for (int k = 0; k < n; ++k) {
		topcoder[s[k] - 'a']++;
		for (int kek = 0; kek < n; kek++) {
			ioi[s[k] - 'a'][s[(k + kek) % n] - 'a'][kek]++;
		}
	}
	ld timer = 0;
	for (int k = 0; k < 26; ++k) {
		ld atcoder = 0.0;
		for (int etud = 0; etud < n; etud++) {
			ld nik = 1.0;
			for (int c = 0; c < 26; c++) {
				if (ioi[k][c][etud] == 0) continue;
				if (ioi[k][c][etud] == 1) continue;
				nik -= (ld)ioi[k][c][etud] / topcoder[k];
			}
			atcoder = max(atcoder, nik);
		}
		timer = timer + atcoder * (ld)(topcoder[k]) / n;
	}
	cout.precision(2400);
	cout << fixed << timer << endl;
	return 0;
}