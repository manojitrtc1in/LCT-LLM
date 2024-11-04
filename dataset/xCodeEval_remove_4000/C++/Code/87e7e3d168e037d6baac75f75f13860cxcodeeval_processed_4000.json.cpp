




using namespace std;
map <int, pair<int,int> > m  ; 
map <int, pair<int,int> > m1 ; 


main (){
	int t ; 
	cin >> t ; 
	while (t--){
			int n ;
			cin >> n ; 
			int a[n] ; 
			for (int i = 0 ; i < n ; i ++){
				cin >> a[i] ; 
				if (i%2)
					m[a[i]].first ++ ; 
					else 
					m[a[i]].second ++ ; 
				
			}
			sort(a,a+n) ; 
			for (int  i = 0 ; i < n ; i ++){
					if (i%2)
					m1[a[i]].first ++ ; 
					else 
					m1[a[i]].second ++ ; 
				
			}
			bool ans = 0 ; 
			for (int i = 0 ; i < n ; i ++){
				if (m[a[i]].first != m1[a[i]].first )
				ans = 1 ; 
				if (m[a[i]].second != m1[a[i]].second)
				ans = 1 ; 
			}
			if (ans)
			cout << "NO"<<endl; 
			else 
			cout <<"YES"<<endl;
			ans = 0 ;
			m.clear() ; 
			m1.clear() ; 
	}
}