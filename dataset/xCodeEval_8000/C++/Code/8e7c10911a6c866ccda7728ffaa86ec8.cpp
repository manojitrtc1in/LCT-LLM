



























































































































































































































































































































































































































































































































































#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <iomanip>
#include <sstream>
using namespace std;
const int MAXN = 2e5 + 10;
int ar [ MAXN ] , ar2 [ MAXN ];
int main() {
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	int n , ans = 0 , ind = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> ar [ i ];
	for(int i = 0 ; i < n ; i++)
		cin >> ar2 [ i ];
	for(int i = 0 ; i + ind < n ; i++)
	{
		if(ar [ i ] != ar2 [ i + ind ])
			while(ar [ i ] != ar2 [ i + ind ] && i + ind < n)
				ind++;
	}
	ans += ind;
	cout << ans;
}