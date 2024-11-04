









































































using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; 

bool check(string& str) {
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i])
			return false;
	}
	return true;
}

bool is_prime(ll a){
    if(a < 0) return false;
    if(a == 0 || a == 1 ) return false;
    if(a == 2 || a == 3) return true;
    for(ll i = 2 ; i <= sqrt(a) ; ++i){
        if(a % i == 0) return false;
    }
    return true;
}

ll mod = 998244353;
ll qpow(ll x , ll n){
    ll ans = 1;
    while(n > 0){
        if(n & 1 == 1){
            ans = ans * x  % mod ;
        }
        x = x % mod * x % mod % mod;
        n >>= 1;
    }
    return ans ;
}


typedef pair< ll , ll >  pii;

bool cmp(pii x , pii y){
return x.first<y.first;
}

int main(){
   cnm;
   int te;
   cin >> te;
   while (te--){
       int n;
       string s;
       cin >> n >> s;
       int t = 0 , m = 0;
       for (int i = 0 ; i<n ; i++){
           if (s[i]=='T'){
               t++;
           }
           else{
               m++;
           }
       }
       if (t!=m*2){
           cout << "NO" << endl;
           continue;
       }
       else{
           int f = 1;
           int c = 0;
           for (int i = 0 ; i<n ; i++){
               if (s[i]=='T'){
                   c++;
               }
               else{
                   c--;
               }
               if (c<0){
                   f = 0;
               }
           }
            c = 0;
           for (int i = n-1 ; i>=0 ; i--){
               if (s[i]=='T'){
               c++;
               }
               else{
                   c--;
               }
               if (c<0){
                   f = 0;
               }
           }
           if (f){
               cout << "YES" << endl;
           }
           else {
               cout << "NO" << endl;
           }
       }
   }
    return 0;
}