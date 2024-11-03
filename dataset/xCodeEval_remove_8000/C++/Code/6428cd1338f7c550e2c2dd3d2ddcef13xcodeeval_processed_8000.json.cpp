
























using namespace std;

const int N = 5e3, inf = INT_MAX;






typedef vector <int>  lnum;

void solve(){
	fast;

	int n, ans = 0;
	cin >> n;
	string k;
	cin >> k;

	map <int, int> mapik;

	for(int i = 0; i < n; i++){
		mapik[k[i]]++;
	}

	for(auto to : mapik){
		ans += to.second + 1;
	}
	cout << ans;



}

signed main (){
	fast;

	int test;
	cin >> test;
	while(test--){
		solve();
		cout << "\n";
	}

	return 0;
}
			
	void functions() {
	
		}
