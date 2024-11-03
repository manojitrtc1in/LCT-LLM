
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
bool palindrom(string s) {
	for (ll i = 0; i < floor(size(s) / 2.); i++) {
		if (s[i] != s[size(s) - 1 - i]) return 0;
	}
	return 1;
}
int main() {
	RR{
		string s;
	cin >> s;
	if (palindrom(string('a' + s)) == 0) cout << "YES\n" << 'a' + s << endl;
	else if (palindrom(string(s + 'a')) == 0) cout << "YES\n" << s + 'a' << endl;
	else cout << "NO\n";
	}
	return 0;
}