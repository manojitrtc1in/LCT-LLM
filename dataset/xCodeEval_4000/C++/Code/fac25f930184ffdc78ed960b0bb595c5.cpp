
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define se second
#define fi first 


int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll i, k, l, t, n, x, sum, r, m, y, j;
	cin>>t;
	while(t--) {
		cin>>n;
		n*=2;
		
		

			ll total_angle=360+(n-4)*180;
			double angle = (double)total_angle/(double)n;
			angle/=(double)2.0;
			angle=angle*(3.141592653589793)*(double)((1.0/180.0));
			
			double side = abs(1/(double)cos(angle))/2;
			

			

			

			double kar = abs(side*sin(angle)*2);
			printf("%0.7f\n", kar); 
 
		

	}
}







































































































