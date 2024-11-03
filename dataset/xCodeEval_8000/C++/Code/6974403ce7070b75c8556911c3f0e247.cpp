
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
		ll n, k=0;
	bool fl = 0;
	cin >> n;
	vector<ll> vec(n);
	for (ll i = 0; i < n; i++) cin >> vec[i];
	for (ll i = 0; i < n; i++) {
		if (vec[0] == vec[1] && i == 0) fl = 1;
		if (fl == 1) { if (vec[0] != vec[i]) k = i + 1; }
		else if (vec[0] == vec[2]) k = 2;
		else k = 1;
		if (k != 0) break;
	}
	cout << k << endl;
	}
	return 0;
}