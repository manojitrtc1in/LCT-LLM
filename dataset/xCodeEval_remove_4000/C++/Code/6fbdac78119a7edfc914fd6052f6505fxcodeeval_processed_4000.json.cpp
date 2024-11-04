




          

























const int inf = (1e18) + 1;
const int mod = 998244353 ;
const int mod2 = 998244353 ;
const int maxn = 2e5 + 111;
const int N = 1e6;        
using namespace std;
using namespace __gnu_pbds;                                                                                 

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int n, m;
char a[150][150];

void solve(){
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
			
	vector < pair < pair <pii, pii> , pii> > ans;
	
	for (int i = 1; i < n; i += 2){
		for (int j = 1; j < m; j += 2){
			int cnt = (a[i][j] == '1');
			cnt += (a[i + 1][j] == '1');
			cnt += (a[i][j + 1] == '1');
			cnt += (a[i + 1][j + 1] == '1');
			if (cnt == 0)
				continue;
			if (cnt == 1){
				if (a[i][j] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1'){
					ans.pb(mp(mp(mp(i + 1, j), mp(i + 1, j + 1)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j + 1)), mp(i + 1, j)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j + 1)), mp(i, j + 1)));
				}
				else{
					ans.pb(mp(mp(mp(i + 1, j + 1), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
			}
			else if (cnt == 2){
				if (a[i][j] == '1' && a[i + 1][j] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j + 1)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j] == '1' && a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1' && a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
				else if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
			}
			else if (cnt == 3){
				if (a[i][j] == '0')
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				else if (a[i][j + 1] == '0')
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				else if (a[i + 1][j] == '0')
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				else
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
			}
			else{
				ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
			}
			a[i][j] = '0';
			a[i + 1][j] = '0';
			a[i][j + 1] = '0';
			a[i + 1][j + 1] = '0';
		}
	}
	
	if (n % 2 == 1){
		int i = n - 1;
		for (int j = 1; j < m; j += 2){
			int cnt = (a[i][j] == '1');
			cnt += (a[i + 1][j] == '1');
			cnt += (a[i][j + 1] == '1');
			cnt += (a[i + 1][j + 1] == '1');
			if (cnt == 0)
				continue;
			if (cnt == 1){
				if (a[i][j] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1'){
					ans.pb(mp(mp(mp(i + 1, j), mp(i + 1, j + 1)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j + 1)), mp(i + 1, j)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j + 1)), mp(i, j + 1)));
				}
				else{
					ans.pb(mp(mp(mp(i + 1, j + 1), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
			}
			else if (cnt == 2){
				if (a[i][j] == '1' && a[i + 1][j] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j + 1)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j] == '1' && a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1' && a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
				else if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
			}
			else if (cnt == 3){
				if (a[i][j] == '0')
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				else if (a[i][j + 1] == '0')
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				else if (a[i + 1][j] == '0')
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				else
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
			}
			else if (cnt == 4){
				ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
			}
			a[i][j] = '0';
			a[i + 1][j] = '0';
			a[i][j + 1] = '0';
			a[i + 1][j + 1] = '0';
		}
	}
	if (m % 2 == 1){
		int j = m - 1;
		for (int i = 1; i < n; i += 2){
			int cnt = (a[i][j] == '1');
			cnt += (a[i + 1][j] == '1');
			cnt += (a[i][j + 1] == '1');
			cnt += (a[i + 1][j + 1] == '1');
			if (cnt == 0)
				continue;
			if (cnt == 1){
				if (a[i][j] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1'){
					ans.pb(mp(mp(mp(i + 1, j), mp(i + 1, j + 1)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j + 1)), mp(i + 1, j)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j + 1)), mp(i, j + 1)));
				}
				else{
					ans.pb(mp(mp(mp(i + 1, j + 1), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
			}
			else if (cnt == 2){
				if (a[i][j] == '1' && a[i + 1][j] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j + 1)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j] == '1' && a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1' && a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
				else if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
			}
			else if (cnt == 3){
				if (a[i][j] == '0')
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				else if (a[i][j + 1] == '0')
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				else if (a[i + 1][j] == '0')
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				else
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
			}
			else if (cnt == 4){
				ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
			}
			a[i][j] = '0';
			a[i + 1][j] = '0';
			a[i][j + 1] = '0';
			a[i + 1][j + 1] = '0';
		}
	}
	
	if (n % 2 == 1 && m % 2 == 1){
		int i = n - 1;
		int j = m - 1;
		int cnt = (a[i][j] == '1');
			cnt += (a[i + 1][j] == '1');
			cnt += (a[i][j + 1] == '1');
			cnt += (a[i + 1][j + 1] == '1');
			if (cnt == 1){
				if (a[i][j] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1'){
					ans.pb(mp(mp(mp(i + 1, j), mp(i + 1, j + 1)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j + 1)), mp(i + 1, j)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j + 1)), mp(i, j + 1)));
				}
				else{
					ans.pb(mp(mp(mp(i + 1, j + 1), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
			}
			else if (cnt == 2){
				if (a[i][j] == '1' && a[i + 1][j] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j + 1)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j] == '1' && a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i][j] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1' && a[i][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
				else if (a[i][j + 1] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				}
				else if (a[i + 1][j] == '1' && a[i + 1][j + 1] == '1'){
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				}
			}
			else if (cnt == 3){
				if (a[i][j] == '0')
					ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				else if (a[i][j + 1] == '0')
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				else if (a[i + 1][j] == '0')
					ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
				else
					ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
			}
			else if (cnt == 4){
				ans.pb(mp(mp(mp(i, j + 1), mp(i + 1, j)), mp(i + 1, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i + 1, j)), mp(i + 1, j + 1)));
				ans.pb(mp(mp(mp(i, j), mp(i, j + 1)), mp(i + 1, j + 1)));
			}
			a[i][j] = '0';
			a[i + 1][j] = '0';
			a[i][j + 1] = '0';
			a[i + 1][j + 1] = '0';
	}
	
	
	
	cout << sz(ans) << endl;
	for (auto i : ans){
		cout << i.f.f.f << " " << i.f.f.s << " " << i.f.s.f << " " << i.f.s.s << " " << i.s.f << " " << i.s.s << endl;
	}
}

main(){
	

	

	                                            	
    boost;	

    int qq = 1;
	
   	cin >> qq;
      
    while (qq--){
        solve();
    }
}