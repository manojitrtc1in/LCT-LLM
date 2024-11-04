






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
	ll t = 1;
	cin >> t;
	while (t--) {
		string st;
		ll n;
		cin >> n;
		map<char, ll>a;
		cin >> st;
		for (int i = 0; i < st.size(); i++) {
			a[st[i]]++;
		}
		ll otv;
		for (auto& i : a) {
			otv = i.first - 'a' + 1;
		}
		cout << otv << endl;
	}
}


