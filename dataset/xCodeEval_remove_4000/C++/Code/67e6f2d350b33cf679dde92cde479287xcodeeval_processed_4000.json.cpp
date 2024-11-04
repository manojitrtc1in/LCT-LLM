
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;






bool sS(pi p1, pi p2){    if(p1.S < p2.S)        return 1;    return 0;       }
bool sF(pi p1, pi p2){    if(p1.F < p2.F)        return 1;    return 0;       }

const ll M = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    ll res = 0;
    ll b = -1;
    loop(i, 0, n-1){
        ll x, y;
        cin >> x >> y;
        if(x > y){
            swap(x, y);
        }
        res += x;
        b = max(b, y);
    }
    res *= 2;
    res += 2*b;
    cout << res << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}









