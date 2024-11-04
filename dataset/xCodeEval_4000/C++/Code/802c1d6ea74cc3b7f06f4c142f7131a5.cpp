

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(a, b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define mp make_pair
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define show cout<<
#define sp(n) setprecision(n)
#define nl '\n'
const double pi=acos(-1.0);
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpii map<int,int>
#define mpll map<ll,ll>
#define inp(vp,n)	for(int i=0;i<n;i++){ cin>>vp[i]; }
#define op(vp)	for(auto e:vp){ cout<<e<<" "; }
#define fr(i,j,n)	for(int i=j;i<n;i++)

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

bool ispow2(ll n){
	return !(n&(n-1));
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
void seiveO(){
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

bool check(vll &vp,ll n){
	bool flag = false;
	ll that_idx = -1;
	for(ll i = 0;i<n;i++){
		if(vp[i]==1){
			for(ll j = i+1;j<n;j++){
				if(vp[j]!=vp[j-1]+1){
					return true;
				}
			}
			that_idx = i;
			break;
		}
	}
	if(vp[0]==n){
		return true;
	}
	if(that_idx==-1){
		return true;
	}
	for(ll j = 1;j<that_idx;j++){
		if(abs(vp[j]-vp[j-1])>1){
			return true;
		}
	}
	return false;
}


void solve(){ 
	
	ll n;	cin>>n;

	vll vp(n);	inp(vp,n);

	if(n==1){
		cout<<"YES"<<nl;return;
	}

	

	

	

	

	

	

	ll cnt = 0;
	for(auto e:vp)	if(e==1)	cnt++;
	if(cnt>1){
		cout<<"NO"<<nl;return;
	}
	ll that_idx = -1;
	for(ll i = 0;i<n;i++){
		if(vp[i]==1){
			that_idx = i;
			for(ll j = i+1;j<n;j++){
				if(vp[j]-vp[j-1]>1){
					cout<<"NO"<<nl;return;
				}
			}
			break;
		}
	}
	

	

	

	

	

	

	

	if(vp[0]-vp.back()>1){
		cout<<"NO"<<nl;return;
	}
	if(that_idx==-1){
		cout<<"NO"<<nl;return;
	}
	

	

	

	ll mx = vp[0];
	for(ll i = 1;i<that_idx;i++){
		if(vp[i]-vp[i-1]>1){
			cout<<"NO"<<nl;return;
		}
	}cout<<"YES"<<nl;

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