






#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <iostream>
#include <cmath>
#include <iomanip>
#include <set>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
#include <ctime>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define ll long long
#define f .first
#define s .second
#define mp make_pair
#define pb push_back
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
		ll n, otv = 0;
		cin >> st >> n;
		ll time = (st[0] - '0');
		time *= 10;
		time += (st[1] - '0');
		time *= 60;
		time = time + ((st[3] - '0') * 10 + st[4] - '0');
		ll p = time;
		set<ll>b;
		if (st[0] == st[4] && st[1] == st[3]) {
			b.insert(time);
		}time += n;
		time %= (24 * 60);
		while (p != time) {
			vector <ll>a(4);
			a[0] = time / 60;
			a[1] = a[0] % 10;
			a[0] /= 10;
			ll z = time;
			time %= 60;
			a[2] = time;
			a[3] = a[2] % 10;
			a[2] /= 10;
			time = z;
			if (a[0] == a[3] && a[1] == a[2]) {
				b.insert(time);
			}
			time += n;
			time %= (24 * 60);
		}
		cout << b.size() << endl;
	}
}

