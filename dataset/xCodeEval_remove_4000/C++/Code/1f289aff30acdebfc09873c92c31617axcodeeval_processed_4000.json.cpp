









































































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

inline int read() {
	char c = getchar(); int n = 0;
	while (c < '0' || c > '9') { c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return n;
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
   int n,t=0,m=0,cnt = 0 , f = 1;
   string s;
   cin >> n >> s;
   for (int i = 0 ; i<s.size() ; i++){
       if (s[i]=='T'){
           t++;
            if (cnt){
                cnt--;
            }
       }
       else {
           m++;
           cnt++;
           if (m>t){
               f = 0;
           }
       }
   }
   if (m*2!=t||cnt) {
       f = 0;
   }
   if (f){
       cout << "YES" << endl;
   }
   else {
       cout << "NO" << endl;
   }

   }
    return 0;
}