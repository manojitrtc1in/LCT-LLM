



 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 1e18;
const ll fact_table = 800008;
double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;


priority_queue <ll,vector<ll>,greater<ll> > id1;
priority_queue <P,vector<P>,greater<P> > pqps;




 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";


 
 











 
 
ll mod = 998244353;


  
ll mypow(ll number1,ll number2, ll mod){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = mypow(number1,number2 / 2, mod);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll rui(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){
 
    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){
 
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){
 
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}
 

bool id2 = true;

ll n,m,num,sum,a,b,c,d,e,h,q,p;
ll w, ans;
ll k;
ll arr[500005];
ll x, y, z;
ll dp[500005][10];

char s[500005];

ll calc(ll idx, ll type){
    if(dp[idx][type] != -1)return dp[idx][type];
    if(idx == 0){
        dp[idx][type] = 0;
        return 0;
    }
    set<ll> st;
    st.insert(max(0ll, calc(idx - x, 0)));
    if(type != 1)st.insert(max(0ll, calc(idx - y, 1)));
    if(type != 2)st.insert(max(0ll, calc(idx - z, 2)));
    for(ll i=0;i<5;i++){
        if(!st.count(i)){
            dp[idx][type] = i;
            return i;
        }
    }
    assert(0);
    return -1;
}
void solve(){
    
    cin >> n >> x >> y >> z;

    for(ll i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(ll i=0;i<1000;i++){
        for(ll j=0;j<4;j++){
            dp[i][j] = -1;
        }
    }
    ll id0;
    if(x == 1 && y == 1 && z == 1)id0=2;
    if(x == 1 && y == 1 && z == 2)id0=3;
    if(x == 1 && y == 1 && z == 3)id0=4;
    if(x == 1 && y == 1 && z == 4)id0=5;
    if(x == 1 && y == 1 && z == 5)id0=6;
    if(x == 1 && y == 2 && z == 1)id0=3;
    if(x == 1 && y == 2 && z == 2)id0=3;
    if(x == 1 && y == 2 && z == 3)id0=4;
    if(x == 1 && y == 2 && z == 4)id0=5;
    if(x == 1 && y == 2 && z == 5)id0=6;
    if(x == 1 && y == 3 && z == 1)id0=4;
    if(x == 1 && y == 3 && z == 2)id0=4;
    if(x == 1 && y == 3 && z == 3)id0=2;
    if(x == 1 && y == 3 && z == 4)id0=7;
    if(x == 1 && y == 3 && z == 5)id0=2;
    if(x == 1 && y == 4 && z == 1)id0=5;
    if(x == 1 && y == 4 && z == 2)id0=5;
    if(x == 1 && y == 4 && z == 3)id0=7;
    if(x == 1 && y == 4 && z == 4)id0=5;
    if(x == 1 && y == 4 && z == 5)id0=3;
    if(x == 1 && y == 5 && z == 1)id0=6;
    if(x == 1 && y == 5 && z == 2)id0=6;
    if(x == 1 && y == 5 && z == 3)id0=2;
    if(x == 1 && y == 5 && z == 4)id0=3;
    if(x == 1 && y == 5 && z == 5)id0=2;
    if(x == 2 && y == 1 && z == 1)id0=3;
    if(x == 2 && y == 1 && z == 2)id0=3;
    if(x == 2 && y == 1 && z == 3)id0=4;
    if(x == 2 && y == 1 && z == 4)id0=5;
    if(x == 2 && y == 1 && z == 5)id0=6;
    if(x == 2 && y == 2 && z == 1)id0=3;
    if(x == 2 && y == 2 && z == 2)id0=4;
    if(x == 2 && y == 2 && z == 3)id0=5;
    if(x == 2 && y == 2 && z == 4)id0=6;
    if(x == 2 && y == 2 && z == 5)id0=7;
    if(x == 2 && y == 3 && z == 1)id0=4;
    if(x == 2 && y == 3 && z == 2)id0=5;
    if(x == 2 && y == 3 && z == 3)id0=5;
    if(x == 2 && y == 3 && z == 4)id0=6;
    if(x == 2 && y == 3 && z == 5)id0=7;
    if(x == 2 && y == 4 && z == 1)id0=5;
    if(x == 2 && y == 4 && z == 2)id0=6;
    if(x == 2 && y == 4 && z == 3)id0=6;
    if(x == 2 && y == 4 && z == 4)id0=6;
    if(x == 2 && y == 4 && z == 5)id0=7;
    if(x == 2 && y == 5 && z == 1)id0=6;
    if(x == 2 && y == 5 && z == 2)id0=7;
    if(x == 2 && y == 5 && z == 3)id0=7;
    if(x == 2 && y == 5 && z == 4)id0=7;
    if(x == 2 && y == 5 && z == 5)id0=7;
    if(x == 3 && y == 1 && z == 1)id0=2;
    if(x == 3 && y == 1 && z == 2)id0=4;
    if(x == 3 && y == 1 && z == 3)id0=4;
    if(x == 3 && y == 1 && z == 4)id0=5;
    if(x == 3 && y == 1 && z == 5)id0=6;
    if(x == 3 && y == 2 && z == 1)id0=4;
    if(x == 3 && y == 2 && z == 2)id0=5;
    if(x == 3 && y == 2 && z == 3)id0=5;
    if(x == 3 && y == 2 && z == 4)id0=6;
    if(x == 3 && y == 2 && z == 5)id0=7;
    if(x == 3 && y == 3 && z == 1)id0=4;
    if(x == 3 && y == 3 && z == 2)id0=5;
    if(x == 3 && y == 3 && z == 3)id0=6;
    if(x == 3 && y == 3 && z == 4)id0=7;
    if(x == 3 && y == 3 && z == 5)id0=8;
    if(x == 3 && y == 4 && z == 1)id0=5;
    if(x == 3 && y == 4 && z == 2)id0=6;
    if(x == 3 && y == 4 && z == 3)id0=7;
    if(x == 3 && y == 4 && z == 4)id0=7;
    if(x == 3 && y == 4 && z == 5)id0=8;
    if(x == 3 && y == 5 && z == 1)id0=6;
    if(x == 3 && y == 5 && z == 2)id0=7;
    if(x == 3 && y == 5 && z == 3)id0=8;
    if(x == 3 && y == 5 && z == 4)id0=8;
    if(x == 3 && y == 5 && z == 5)id0=8;
    if(x == 4 && y == 1 && z == 1)id0=5;
    if(x == 4 && y == 1 && z == 2)id0=3;
    if(x == 4 && y == 1 && z == 3)id0=5;
    if(x == 4 && y == 1 && z == 4)id0=5;
    if(x == 4 && y == 1 && z == 5)id0=6;
    if(x == 4 && y == 2 && z == 1)id0=3;
    if(x == 4 && y == 2 && z == 2)id0=6;
    if(x == 4 && y == 2 && z == 3)id0=6;
    if(x == 4 && y == 2 && z == 4)id0=6;
    if(x == 4 && y == 2 && z == 5)id0=7;
    if(x == 4 && y == 3 && z == 1)id0=5;
    if(x == 4 && y == 3 && z == 2)id0=6;
    if(x == 4 && y == 3 && z == 3)id0=7;
    if(x == 4 && y == 3 && z == 4)id0=7;
    if(x == 4 && y == 3 && z == 5)id0=8;
    if(x == 4 && y == 4 && z == 1)id0=5;
    if(x == 4 && y == 4 && z == 2)id0=6;
    if(x == 4 && y == 4 && z == 3)id0=7;
    if(x == 4 && y == 4 && z == 4)id0=8;
    if(x == 4 && y == 4 && z == 5)id0=9;
    if(x == 4 && y == 5 && z == 1)id0=6;
    if(x == 4 && y == 5 && z == 2)id0=7;
    if(x == 4 && y == 5 && z == 3)id0=8;
    if(x == 4 && y == 5 && z == 4)id0=9;
    if(x == 4 && y == 5 && z == 5)id0=9;
    if(x == 5 && y == 1 && z == 1)id0=2;
    if(x == 5 && y == 1 && z == 2)id0=3;
    if(x == 5 && y == 1 && z == 3)id0=2;
    if(x == 5 && y == 1 && z == 4)id0=6;
    if(x == 5 && y == 1 && z == 5)id0=6;
    if(x == 5 && y == 2 && z == 1)id0=3;
    if(x == 5 && y == 2 && z == 2)id0=7;
    if(x == 5 && y == 2 && z == 3)id0=7;
    if(x == 5 && y == 2 && z == 4)id0=7;
    if(x == 5 && y == 2 && z == 5)id0=7;
    if(x == 5 && y == 3 && z == 1)id0=2;
    if(x == 5 && y == 3 && z == 2)id0=7;
    if(x == 5 && y == 3 && z == 3)id0=8;
    if(x == 5 && y == 3 && z == 4)id0=8;
    if(x == 5 && y == 3 && z == 5)id0=8;
    if(x == 5 && y == 4 && z == 1)id0=6;
    if(x == 5 && y == 4 && z == 2)id0=7;
    if(x == 5 && y == 4 && z == 3)id0=8;
    if(x == 5 && y == 4 && z == 4)id0=9;
    if(x == 5 && y == 4 && z == 5)id0=9;
    if(x == 5 && y == 5 && z == 1)id0=6;
    if(x == 5 && y == 5 && z == 2)id0=7;
    if(x == 5 && y == 5 && z == 3)id0=8;
    if(x == 5 && y == 5 && z == 4)id0=9;
    if(x == 5 && y == 5 && z == 5)id0=10;

    for(ll i=0;i<n;i++){
        if(arr[i] > 100){
            ll dec = (arr[i] - 50) / id0;
            arr[i] = arr[i] - dec * id0;
        }
    }
    ll id3 = 0;
    for(ll i=0;i<n;i++){
        id3 ^= calc(arr[i], 0);
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll nextxor = 0;
        nextxor = id3 ^ calc(arr[i], 0) ^ calc(max(0ll, arr[i] - x), 0);
        if(nextxor == 0)ans ++;
        nextxor = id3 ^ calc(arr[i], 0) ^ calc(max(0ll, arr[i] - y), 1);
        if(nextxor == 0)ans ++;
        nextxor = id3 ^ calc(arr[i], 0) ^ calc(max(0ll, arr[i] - z), 2);
        if(nextxor == 0)ans ++;
    }
    p(ans);



    return;
}

int main(){
    

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q;
    if(id2){
        cin >> q;
    }else{
        q = 1;
    }
    while(q--){
        solve();
    }
    return 0;

}
















