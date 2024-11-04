#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;










#define ll long long
#include <cmath>








#define pii pair<int,int> 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<pii>pref(n, { 0,0 });
		if (s[0] == 'a')
			pref[0].first++;
		else
			pref[0].second++;
		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1];
			if (s[i] == 'a') {
				pref[i].first++;
			}
			else
				pref[i].second++;
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (pref[i].first == pref[i].second) {
				cout << 1 << " " << i + 1 << endl;
				flag = true;
				break;
			}
		}
		if (!flag) {
			for (int i = 1; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if ((pref[j].first - pref[i-1].first) == (pref[j].second - pref[i-1].second)) {
						cout << i + 1 << " " << j + 1 << endl;
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
		}
		if (!flag)
			cout << -1 << " " << -1 << endl;
	}
}
 	    		 	 	  	 		     		 		 		