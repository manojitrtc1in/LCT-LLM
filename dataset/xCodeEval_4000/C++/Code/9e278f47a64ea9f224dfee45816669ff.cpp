
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <math.h>  
#include <stdlib.h> 
using namespace std;

typedef long long ll;
#define loop(x,n) for(int x = 0; x < n; x++)
#define Startloop(x,y,n) for(int x = y; x <= n; x++)










   


int main(){

freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	


	ios_base::sync_with_stdio(false);

	cin.tie(NULL);




	




		

	


	


	




	

	

	



	



	

	

	

	


	

	

	

	


	



		

	


	


	
		


	


	


	



	








	





	int n;
	cin>>n;
	vector<int> m;
	loop(i,n){
		int c;
		cin>>c;
		m.push_back(c);
	}

	sort(m.begin(), m.end());
	int dp[n];
	int minimum;
	loop(j, n){
	
		

		if(j == 0){
			auto pt = upper_bound(m.begin(), m.end(), 2*(m.at(j)));
			int pos = (pt-m.begin());
		
		
			int add = n-pos+j;
			minimum = add;
			dp[j] = pos;
		}
		else{
			auto pt = upper_bound(m.begin()+dp[j-1], m.end(), 2*(m.at(j)));
			int pos = (pt-m.begin());
		
		
		int add = n-pos+j;
		minimum = min(minimum, add);
			dp[j] = pos;

		}
		
	}
	cout<<minimum;







	

	


		

	

	

	return 0;
}


