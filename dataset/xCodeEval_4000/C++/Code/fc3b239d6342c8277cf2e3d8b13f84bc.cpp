
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <iomanip>
 
 
 
using namespace std;
 
 
 
 
#define ll long long



int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (!m){
		cout << n - 1 << endl;
		return 0;
	}
	int minim = 1e9, maxim = 0;
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (u > v) {
			swap(u, v);
		}
		minim = min(minim, v);
		maxim = max(maxim, u);
	}
	cout << max(minim - maxim, 0) << endl;
	return 0;
}





















