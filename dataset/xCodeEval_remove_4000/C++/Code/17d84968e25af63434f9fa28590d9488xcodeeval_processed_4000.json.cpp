






using namespace __gnu_pbds;
 




 

























 





 
































 


























using namespace std;
void printarr(ll a[],ll n){
    forl(i,n){
        p0(a[i]);
    }
    cout<<endl;
}
void printv(vector<ll>&v){
    forl(i,v.S){
        p0(v[i]);
    }
    cout<<endl;
}
vector<ll> res;
void factorize(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
}
vll divs;
void divisor(ll n){
        for(ll i=2;i<=sqrt(n);i++){
            if(n%i==0){
                divs.pb(i);
                if(n/i!=i){
                    divs.pb(n/i);
                }
            }
        }
        divs.pb(1);
        if(n!=1){
            divs.pb(n);
        }
}
vector<ll>prefix_function(string &s) {
    ll n = (ll)s.length();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++) {
        ll j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
ll modexpo(ll x,ll y)  
{   ll res = 1;
    x = x%mod2; 
    if (x == 0) return 0; 
    while (y > 0)  
    {   if (y & 1)res = (res*x) % mod2;  
        y = y>>1; 
        x = (x*x) % mod2;  
    }  
    return res;  
}  





 















struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id2 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id2);
    }
};




















long long int inverse(long long int i,ll MOD){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i,MOD))%MOD+MOD)%MOD;
}
const ll MAXM = 200005;
bool v[MAXM];
ll sp[MAXM];
 
void Sieve(){
    sp[1] = 1;

    for (ll i = 2; i < MAXM; i += 2)    sp[i] = 2;

    for (ll i = 3; i < MAXM; i += 2){
        if (!v[i]){
            sp[i] = i;
            for (ll j = i; (j*i) < MAXM; j += 2){
                if (!v[j*i])    v[j*i] = true, sp[j*i] = i;
            }
        }
    }
} 
vll g[200005];
map<pll,ll>num,den; 
ll coeff[200005];
bool vis[200005];
mll id1;
mll id0;
void dfs(ll u){
    vis[u] = 1;
    for(auto v:g[u]){
        if(!vis[v]){
            coeff[v] = coeff[u];
            coeff[v] = (coeff[v]%mod2*num[{u,v}]%mod2)%mod2;
            ll temp = den[{u,v}];
            coeff[v] = (coeff[v]%mod2*inverse(temp,mod2)%mod2)%mod2;
            ll val = num[{u,v}];
            while(val!=1){
                id0[sp[val]]--;
                val/=sp[val];
            }            
            val = den[{u,v}];
            while(val!=1){
                id0[sp[val]]++;
                id1[sp[val]] = max(id1[sp[val]],id0[sp[val]]);
                val/=sp[val];
            }
            dfs(v);
            val = den[{u,v}];
            while(val!=1){
                id0[sp[val]]--;
                val/=sp[val];
            }
            val = num[{u,v}];
            while(val!=1){
                id0[sp[val]]++;
                val/=sp[val];
            }  
        }
    }
}
 
 


int main(){
   FAST;
   Sieve();
   tc{
       ll n;
       cin>>n;
       for(ll i=1;i<=n;i++){
           g[i].clear();
           vis[i] = 0;
           coeff[i] = 0;
       }
       num.clear();
       den.clear();
       id1.clear();
       id0.clear();
       forl(i,n-1){
           ll a,b,x,y;
           cin>>a>>b>>x>>y;
           g[a].pb(b);
           g[b].pb(a);
           num[{a,b}] = y;
           den[{a,b}] = x;
           num[{b,a}] = x;
           den[{b,a}] = y;
       }
       coeff[1] = 1;
       dfs(1);
       ll val = 0;
       for(ll i=1;i<=n;i++){
           val = (val%mod2+coeff[i]%mod2)%mod2;
       }
       ll val1 = 1;
       vpll v;
       for(auto p:id1){
           v.push_back({p.first,p.second});
       }
       forl(i,v.size()){
       val1 = (val1%mod2*modexpo(v[i].first,v[i].second)%mod2)%mod2;
       }
       val = (val%mod2*val1%mod2)%mod2;
       p1(val);
   }
  
  
  
  
    
}


























































