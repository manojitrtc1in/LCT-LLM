






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
    x = x%mod1; 
    if (x == 0) return 0; 
    while (y > 0)  
    {   if (y & 1)res = (res*x) % mod1;  
        y = y>>1; 
        x = (x*x) % mod1;  
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
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
};
















 
 
 
 


int main(){
   FAST;
   tc{
       ll n,m;
       cin>>n>>m;
       ll x[n],p[n];
       forl(i,n){
           cin>>x[i]>>p[i];
       }
       map<ll,pll>diff;
       forl(i,n){
           if(diff.find(x[i]-p[i]+1)==diff.end()){
               diff[x[i]-p[i]+1] = {1,0};
           }else{
               diff[x[i]-p[i]+1] = {1+diff[x[i]-p[i]+1].first,0};
           }
          
           if(diff.find(x[i]+1)==diff.end()){
               diff[x[i]+1] = {-2,0};
           }else{
               diff[x[i]+1] = {-2+diff[x[i]+1].first,0};
           }

           if(diff.find(x[i]+p[i]+1)==diff.end()){
               diff[x[i]+p[i]+1] = {1,0};
           }else{
               diff[x[i]+p[i]+1] = {1+diff[x[i]+p[i]+1].first,0};
           }
       }
       auto it = diff.begin();
       auto it1 = it;
       it++;
       ll l = MIN,r = MIN;
       while(it!=diff.end()){
           ll val1 = (*it).fi;
           ll val2 = (*it1).fi;
           diff[val1].fi+=diff[val2].fi;
           diff[val1].se = diff[val2].se + ((val1-val2)*diff[val2].fi);
           if(diff[val1].se>m){
               l = max(l,diff[val1].se-val1);
               r = max(r,diff[val1].se+val1);
           }
           it++;it1++;
       }
       forl(i,n){
           if(m+x[i]+p[i]+1>=r && m+p[i]-x[i]-1>=l){
               cout<<1;
           }else{
               cout<<0;
           }
       }
       cout<<endl;
       
   }
  
  
  
  
    
}


















































