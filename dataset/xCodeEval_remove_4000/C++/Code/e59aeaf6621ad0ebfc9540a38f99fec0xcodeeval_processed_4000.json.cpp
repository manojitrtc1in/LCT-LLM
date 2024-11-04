









































































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

bool id0(int num)
{
    if(num == 1)
        return true;
 
    int start = 2;
    int end = num;
    int mid;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(mid == num / mid && num % mid == 0)
            return true;
 
        if(mid > num / mid)
            end = mid - 1;
        else
            start = mid + 1;
    }
        
    return false;
}


typedef pair< ll , ll >  pii;

bool cmp(pii x , pii y){
return x.first<y.first;
}




int a[100005];
int dex[100005];

int main(){
    cnm;
    int te;
    cin >> te;
    while (te--){      
    int a,b;
    cin >> a >> b;
    int ans;
    cout << a*b << endl;
    
}
    return 0;
}