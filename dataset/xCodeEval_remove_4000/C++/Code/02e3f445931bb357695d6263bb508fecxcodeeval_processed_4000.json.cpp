







using namespace std;

typedef long long ll;












   


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
	loop(j, n){
		auto pt = upper_bound(m.begin(), m.end(), 2*(m.at(j)));
		int pos = (pt-m.begin());
		
		
		int add = n-pos+j;
		

		if(j == 0){
			dp[j] = add;
		}
		else{
			dp[j] = min(add, dp[j-1]);
		}
		
	}
	cout<<dp[n-1];







	

	


		

	

	

	return 0;
}


