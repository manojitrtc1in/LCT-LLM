


















using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T>
using ve = vector<T>;

ll binpow(ll a,ll n,ll mod){
    ll ans=1;
    while(n){
        if(n&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return ans;
}

ll binpow(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}
const ll N = 1e5, N2 = 1e6, M = 1e3, inf = INT_MAX;
const ld eps = 1e-9;

ll t, n, m, IQ, a, a1[300000], g = 0, g1 = 0, kol = 0, k = 0, k1 = 0;
string s, s1, s2;
vector<ll> v, v1;
ll x, y, x1, y1;

int main(){
    
    cin.tie(0);cout.tie(0);
    cin >> IQ;
    while(IQ --){
        cin >> n;
        cin >> s;
        g = -1;
        for(ll i = 0;i < sz(s);++ i){
            if(s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9'){
                g = s[i] - '0';
                break;
            }
        }
        if(g != -1){cout<<1<<endl<<g<<endl;continue;}
        k = 0;
        for(ll i = 0;i < sz(s);++ i)if(s[i] == '7')++ k;
        if(k >= 2){
            cout<<2<<endl;
            cout<<77<<endl;
            continue;
        }
        for(ll i = sz(s) - 1;i >= 1;-- i)if(s[i] == '2'){g = i;break;}
        if(g != -1){
            cout<<2<<endl;
            cout<<s[g - 1]<<2<<endl;
            continue;
        }
        for(ll i = sz(s) - 1;i >= 1;-- i)if(s[i] == '5'){g = i;break;}
        if(g != -1){
            cout<<2<<endl;
            cout<<s[g - 1]<<5<<endl;
            continue;
        }
                ll o1,i1,j1,ff;

        for(ll i = 0;i < sz(s);++ i){
            for(ll j = i + 1;j < sz(s);++ j){
                if((s[i] - '0' + s[j] - '0') % 3 == 0){ff = 1;i1 = s[i] - '0';j1 = s[j] - '0';break;}
                for(ll o = j + 1;o < sz(s);++ o){
                    if((s[i] + s[j] + s[o] - '0' - '0' - '0') % 3 == 0){
                        ff = 2;
                        i1 = s[i] - '0';
                        j1 = s[j] - '0';
                        o1 = s[o] - '0';
                        break;
                    }
                }
            }
        }

        if(ff == 1){
            cout<<2<<endl;
            cout<<i1<<j1<<endl;
            continue;
        }
          if(ff == 2){
            cout<<3<<endl;
            cout<<i1<<j1<<o1<<endl;
            continue;
        }
    }
    return 0;
}
