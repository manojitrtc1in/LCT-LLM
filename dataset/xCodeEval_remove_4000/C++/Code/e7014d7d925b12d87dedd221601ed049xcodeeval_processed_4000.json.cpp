


using namespace std;












const double pi=acos(-1.0);
int maxar(int arr[],int n) { int res=arr[0]; for(int i=0;i<n;i++){res=max(res,arr[i]);} return res;}
long long maxar(long long arr[],long long n) { long long res=arr[0]; for(long long i=0;i<n;i++){res=max(res,arr[i]);} return res;}
long long minar(long long arr[],long long n) { long long res=arr[0]; for(long long i=0;i<n;i++){res=min(res,arr[i]);} return res;}
int minar(int arr[],int n) { int res=arr[0]; for(int i=0;i<n;i++){res=min(res,arr[i]);} return res;}
void inpar(int arr[],int n){	for(int i=0;i<n;i++){cin>>arr[i];}	}
void inpar(long long arr[],long long n){for(long long i=0;i<n;i++){cin>>arr[i];}}




ll mulmod(ll a,ll b,ll c){
    

    

    

    

    

    return ((a%c)*(b%c))%c;
}
 
ll binPower(ll a ,ll n ,ll mod){
	ll res = 1;
	while(n){
		if(n & 1)   res = mulmod(res , a , mod);
		n >>= 1;    a = mulmod(a , a , mod);
	}return res % mod;
}





	














ll lcm(ll a,ll b){
	return (a*b)/__gcd(a,b);
}
 
bool ispalin(string s){
	int i=0,j = s.length()-1;
	while(i<j){
		if(s[i]!=s[j]){
			return false;
		}i++;j--;
	}return true;
}


void solve(){
	ll n,m;	cin>>n>>m;
	string s;	cin>>s;
	ll pos_i = 1, pos_j = 1;
	ll right_space = m-1, left_left = 0;
	ll down_left = n-1, up_left = 0;
	ll rr = 0, lft = 0;
	ll up = 0, dd = 0;

	ll mx_rr = 0, mx_ll = 0;
	ll mx_up = 0, mx_dn = 0;

	for(int i=0;i<s.length();i++){

		bool flag = false;

		if(s[i]=='R'){
			rr++;
			lft--;
		}else if(s[i]=='D'){
			dd++;
			up--;
		}else if(s[i]=='U'){
			up++;
			dd--;
		}else if(s[i]=='L'){
			lft++;
			rr--;
		}
		mx_rr = max(mx_rr,rr);
		mx_ll = max(mx_ll,lft);
		mx_dn = max(mx_dn,dd);
		mx_up = max(mx_up,up);

		if(mx_rr+mx_ll>=m||mx_dn+mx_up>=n){
			break;
		}
		if(mx_up>0)	pos_i = min(mx_up+1,n);
		if(mx_ll>0)	pos_j = min(mx_ll+1,m);

		if(flag){
			break;
		}




	}show pos_i<<" "<<pos_j<<nl;

}
    

    

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 1;
	

	

	cin>>tc;
	

	while(tc--){
		solve();
	}






	return 0;
}   