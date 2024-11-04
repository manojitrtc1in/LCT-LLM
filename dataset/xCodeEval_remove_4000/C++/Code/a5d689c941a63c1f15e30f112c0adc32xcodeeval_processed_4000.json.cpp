






using namespace std;

typedef long long ll;





   


int main(){



	ios_base::sync_with_stdio(false);

	cin.tie(NULL);




	




		

	


	


	




	

	

	



	



	

	

	

	


	

	

	

	


	



		

	


	


	
		


	


	


	



	


	int n;
	cin>>n;
	int seq[n];
	loop(i, n){
		cin>>seq[i];
	}

	

	

	

	

	

	


	int comp1 = seq[0];
	int comp2 = seq[1];

	int l = 0;
	int r = 1;
	int dp[n];
	dp[1] =2;
	int maxLen = 2;
	while( r < n-1 ){
		

			

			r++;	
	
		

	

		if(seq[r] == comp1 || seq[r] == comp2){
			

			dp[r] = dp[r-1] +1;
		}
		else if(abs(seq[r] - comp1) <= 1 && abs(seq[r] - comp2) <= 1){
			

			comp2 = seq[r];
			dp[r] = dp[r-1] + 1;

		}
		

		else{
			

			if(dp[r-1] > maxLen){
				maxLen = dp[r-1];
			}

			comp2 = seq[r];
			int stor;
			while(l<r){
				
				if(abs(seq[l] - comp2) > 1){
					stor = l;
					

					
					
				}
				l++;
			}
			l = stor +1;
			comp1 = seq[l];
			

			

			

			

			dp[r] = r-l+1;


		}
		



	}
	if(dp[n-1] > maxLen){
		maxLen = dp[n-1];
	}
	cout<<maxLen;
	
	



	return 0;
}


