
 


















using namespace std;
typedef long long ll;
typedef long double ld;
const double eps = 1e-6;
const ll INF = 1e12+10;
const ll mod = 1e9 + 7;

ll qpow(ll a, ll n)
{
    ll ans = 1;
    while(n){
        if(n & 1){
            ans = (ans * a) % mod ;
        }
        a = (a * a) % mod ;
        n >>= 1;
    }
    return ans;
}
int main() {
    ywh666;
    ll t ;
    cin >> t;
    while(t--){
        ll n ;
        cin >> n ;
        string s1,s2;
        cin >> s1 >> s2;
        if(s1 == s2){
            cout << 0 << endl;
        }else{
            ll sum1 = 0 ;
            ll sum2 = 0;
            ll sum3 = 0 ;
            ll sum4 = 0;
            for(ll i = 0 ; i < n ; i ++){
                if(s1[i] == '0'&& s2[i] =='1'){
                    sum1 ++ ;
                }else if(s1[i] == '1' && s2[i] == '0'){
                    sum2 ++ ;
                }else if(s1[i] == '0' && s1[i] == '0'){
                    sum3 ++;
                }else{
                    sum4++;
                }
            }
            ll ans1 = INF;
            ll ans2 = INF;
            if(sum1 == sum2) ans1 = sum1 * 2;
            if(sum4 - sum3 == 1LL)    ans2 = 1LL + 2 * sum3 ;
            ll fans = min(ans1,ans2);
            if(fans == INF){
                cout << -1 << endl;
            }else{
                cout << fans << endl;
            }
           
        }
 
    }
    return 0;
}