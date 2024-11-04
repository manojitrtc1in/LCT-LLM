#define ZXC for(int i=1000; i>0; i-=7) cout << i << endl

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
#define CPP ll t; cin >> t; while (t--)
ll const INF = 9223372036854775807;
ll const NINF = -9223372036854775807;
using namespace std;
int main() {
	CPP{
	 ll n;
	 cin >> n;
	 ll sch = 0, sch1 = 0, snch = 0, snch1 = 0;
	 vector<ll> vec(n);
	 vector<ll> vecn;
	 vector<ll> vecc;
	 for (ll i=0; i < n; i++) {
	  cin >> vec[i];
	  if (vec[i] % 2 == 0) {
	   sch++;
	   sch1 += i;
	   vecc.push_back(i);
	  }
	  else {
	   snch++;
	   snch1 += i;
	   vecn.push_back(i);
	  }
	 }
	 if ((sch > ceil(n / 2.) || snch > ceil(n / 2.)) && n > 1) {
	  cout << -1 << endl;
	 }
	 else {
		 vector<ll> vecp;
	  ll s = 0;
	  ll s1 = 0;
	  for (ll i = 0; i < n; i++) {
	   if (i % 2 == 0) {
		vecp.push_back(i);
	   }
	  }
	  if (sch > snch) {
		  for (ll i = 0; i < vecc.size(); i++) {
		s += abs(vecc[i] - vecp[i]);
	   }
	   cout << s << endl;
	  }
	  else {
	   if (sch == snch) {
		   for (ll i = 0; i < vecc.size(); i++) {
		 s += abs(vecc[i] - vecp[i]);
		}
		   for (ll i = 0; i < vecn.size(); i++) {
		 s1 += abs(vecn[i] - vecp[i]);
		}
		cout << min(s, s1) << endl;
	   }
	   else {
		   for (ll i = 0; i < vecn.size(); i++) {
		 s1 += abs(vecn[i] - vecp[i]);
		}
		cout << s1 << endl;
	   }
	  }
	 }
	}
	return 0;
}