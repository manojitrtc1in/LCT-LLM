





#include <bits/stdc++.h>

using namespace std;

string s[200];
int n, k;
vector < pair < int , pair < int, int > > > v;
int sum;

int calc (int x, int y) {
	int cnt = 0;
	if (y - 1 >= 0 && s[x][y - 1] == 'S') cnt++;
	if (y + 1 < 12 && s[x][y + 1] == 'S') cnt++;
	return cnt; 
}

int calc1 (int x, int y) {
	int cnt = 0;
	if (y - 1 >= 0 && s[x][y - 1] != '-' && s[x][y - 1] != '.') cnt++;
	if (y + 1 < 12 && s[x][y + 1] != '-' && s[x][y + 1] != '.') cnt++;
	return cnt;	 
}







int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) 
    	cin >> s[i];
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j < 12; ++j) {
    		if (s[i][j] == '.') 
    			v.push_back (make_pair (calc (i, j), make_pair (i, j)));
    	}
    }
    sort (v.begin (), v.end ());
   	for (int i = 0; i < k; ++i)
   		s[v[i].second.first][v[i].second.second] = 'x';  
   	for (int i = 1; i <= n; ++i) {
   		for (int j = 0; j < 12; ++j) {
   			if (s[i][j] == 'S')
   				sum += calc1 (i, j);
   		}
   	}
   	cout << sum << endl;
   	for (int i = 1; i <= n; ++i) cout << s[i] << "\n"; 
    return 0;                                      
}





