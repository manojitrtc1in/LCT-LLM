﻿






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
		map<char, ll>a;
		char k;
		for (int i = 0; i < m; i++) {
			cin >> k;
			a[k] = 1;
		}
		ll pos = -1;
		set<ll>p;
		for (int i = n - 1; i >= 0; i--) {
			if (a[st[i]] == 1) {
				if (pos == -1) { pos = i - 1ll; }
				p.insert(i);
			}
		}
		if (pos == -1) {
			cout << 0 << '\n';
		}
		else {
			stack<pair<ll, ll>>b;
			ll ft = 0;
			for (int i = pos; i >=0; i--) {
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
