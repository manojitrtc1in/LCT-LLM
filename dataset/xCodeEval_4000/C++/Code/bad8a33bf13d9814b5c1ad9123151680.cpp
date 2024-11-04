
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


	ios_base::sync_with_stdio(false);

	cin.tie(NULL);




	




		

	


	


	




	

	

	



	



	

	

	

	


	

	

	

	


	



		

	


	


	
		


	


	


	



	








	





	


	


	

	

	


	

	

	


	int n, k;
	cin>>n>>k;
	int con[n];
	loop(i,n){
		cin>>con[i];

	}
	int dp[n][3];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = min(k, n-1) + 1;
	dp[0][1] = min(n-1, k);
	dp[0][2] = 0;
	cout<<dp[0][0]<<" ";
	for(int i = 1; i<n; i++){
		int upper = min(k, n-i-1);
		int lower = min(k, i);
		if(con[i] != 0){
			dp[i][0] = dp[con[i]-1][0];
			int x = con[i]-1;
			if(dp[x][1] < i - lower){
				dp[i][0] += lower + upper + 1;
				dp[i][1] = i + upper;
				dp[i][2] = i-lower;
			} else{
				int diff =  dp[x][1] -(i-lower) + 1 ;
				dp[i][0] += lower + upper + 1 - diff;
				dp[i][1] += i+upper;
				dp[i][2] = i - lower;
				

 			}

			
		} else{
				
			dp[i][0] += lower;
			dp[i][0] += upper + 1;
			dp[i][1] = i + upper;
			dp[i][2] = i- lower;
		}
		cout<<dp[i][0]<<" ";
		
	}


		return 0;
}


