
#include <bits/stdc++.h>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <random>
#include <any>
#include <hash_map>
#include <stack>
#include <queue>
#include <set>
#include <functional>
#include <string>
#include <iostream>
#include <utility>
#include <limits.h>
#include <map>
#include <variant>

using namespace std;

const int N = 5e3, inf = INT_MAX;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff first
#define pb(a) push_back(a)
#define all(a) a.begin(), a.end()
#define for0(i, n) for(int i = 0; i < m; i++) 
#define for1(i, n) for(int i = 1; i < m; i++)
typedef vector <int>  lnum;

void solve(){
	fast;

	int n, ans = 0;
	cin >> n;
	string k;
	cin >> k;

	map <int, int> mapik;

	for(int i = 0; i < n; i++){
		mapik[k[i]]++;
	}

	for(auto to : mapik){
		ans += to.second + 1;
	}
	cout << ans;



}

signed main (){
	fast;

	int test;
	cin >> test;
	while(test--){
		solve();
		cout << "\n";
	}

	return 0;
}
			
	void functions() {
	
		}
