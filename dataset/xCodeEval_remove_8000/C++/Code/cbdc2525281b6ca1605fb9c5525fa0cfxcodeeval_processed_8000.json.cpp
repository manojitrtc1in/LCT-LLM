











using namespace std;
const ll MX = 2e5+7;
const ll MOD = 1e9+7;

void solve(){
	ll n,sz=0,idx,ans=10,a;
	cin >> n;
	while(n>0){
		sz++;
		ans = min(ans,n%10);
		if(n/10==0 && sz==2){
			cout << a << endl;
			return;
		}
		a=n%10;
		n/=10;
	}
	cout << ans << endl;
}
 
int main(){
	ll t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}