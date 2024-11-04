#define ZXC for(int i=1000; i>0; i-=7) cout << i << endl

#include<functional>
#include<algorithm>
#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<clocale>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<math.h>
#include<random>
#include<ctime>
#include<cmath>
#include<queue>
#include<map>
typedef long long ll;
#define RR ll t; cin >> t; while (t--)
ll const INF = 9223372036854775807;
ll const NINF = -9223372036854775807;
using namespace std;
int main() {
	RR{
	ll n,m;
	cin >> n;
	vector<pair<ll, ll>> vec(n);
	for (ll i = 0; i < n; i++) {
		cin >> m;
		vec[i] = make_pair(m, i + 1);
	}
	sort(vec.begin(), vec.end());
	if (vec[0].first == vec[n - 2].first) cout << vec[n - 1].second << endl;
	else cout << vec[0].second << endl;
	}
	return 0;
}