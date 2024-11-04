


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

bool id0(int n){
	return !(n&(n-1));
}

int id1(string s){
	int res = 0;
	for(char ch:s)	res = res*10 + ch -'0';
	return res;
}

bool isprime(ll n){
	if(n<=1)	return false;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}return true;
}

vector<bool> is_prime(1000001, true);
void id2(){
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= 1000000; i++) {
    	if (is_prime[i] && (long long)i * i <= 1000000) {
        	for (int j = i * i; j <= 1000000; j += i)
            	is_prime[j] = false;
    	}
	}
}





bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
 return v1[1] < v2[1];
}


int no_of_oper[10100];

void pre(){

	

	for(int i = 0; i<1005; i++)no_of_oper[i] = 1000000007;
	no_of_oper[1] = 0;
	for(int i = 1; i<1005; i++)
	{
		for(int j = 1; j<=i; j++)
		{
			no_of_oper[i+(i/j)] = min(no_of_oper[i+(i/j)],no_of_oper[i]+1);
		}
	}
}


ll fn(ll moves[],ll c[],ll k,ll i,ll n,vector<vector<ll>> &dp){
	if(i==n){
		return 0;
	}else if(dp[i][k]!=-1){
		return dp[i][k];
	}else if(moves[i]<=k){
		return dp[i][k] = max({
			c[i]+fn(moves,c,k-moves[i],i+1,n,dp),
			fn(moves,c,k,i+1,n,dp)
		});
	}else{
		return dp[i][k] = fn(moves,c,k,i+1,n,dp);
	}
}

void solve(){
	ll n,k;	cin>>n>>k;
	ll a[n];	inpar(a,n);
	ll c[n];	inpar(c,n);
	k = min(k,15*n);
	vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
	ll moves[n];
	for(int i=0;i<n;i++){
		moves[i] = no_of_oper[a[i]];
	}
	ll res = fn(moves,c,k,0,n,dp);
	cout<<res<<nl;
}   




int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 1;
	cin>>tc;
	pre();
	

	while(tc-->0){
		solve();
	}






	return 0;
}   