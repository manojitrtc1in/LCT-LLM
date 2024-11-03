
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
		bool fl = 1;
		ll n,k = 0;
	string a, b;
	cin >> n >> a >> b;
	a += '0';
	b += '0';
	for (ll i = 0; i < n; i++) {
		if (a[i] == '1') k += 1;
		else k -= 1;
		if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && k != 0) {
			fl = 0;
			goto exit;
		}
	}
	exit:
	if (fl) cout << "YES\n";
	else cout << "NO\n";
	}
	return 0;
}