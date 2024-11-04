




using namespace std;

main (){
	int t ; 
	cin >> t ; 
	while (t--){
		int n ; 
		cin >> n ; 
		long long a[n] ; 
		long long  sum = 0 ; 
		for (int i = 0 ; i < n ;i ++){
			cin >> a[i]  ;
			sum +=a[i] ; 
		}
		sort(a,a+n) ; 
		long long  ans = 0  ;
		for (int i = n-1 ; i; i--){
			
			sum -=a[i] ; 
			ans += sum - i*a[i]  ;  
		}
		cout << ans + a[n-1] <<endl;
	}
}