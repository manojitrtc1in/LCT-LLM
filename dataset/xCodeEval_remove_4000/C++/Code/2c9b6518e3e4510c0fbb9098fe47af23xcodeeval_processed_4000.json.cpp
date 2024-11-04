






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
   ll n;
   cin>>n;
   sll s[100005];
   ll a[n];
   forl(i,n){
       cin>>a[i];
       s[a[i]].insert(i);
   }
   forl(i,n+1){
       s[i].insert(n);
   }
   ll x = -1,y = -1,z;
   ll ans = 0;
   forl(i,n){
       z = a[i];
       if(z==x || z==y){
           
       }else{
           if(x==-1){
               x = z;
               ans++;
           }else if(y==-1){
               y = z;
               ans++;
           }else{
               auto it1 = s[x].lower_bound(i);
               auto it2 = s[y].lower_bound(i);
               ll next1 = *it1;
               ll next2 = *it2;
               if(next1<=next2){
                   y = z;
                   ans++;
               }else{
                   x = z;
                   ans++;
               }               
           }
       }
   }
   p1(ans);
   
   
  
  
  
  
    
}

























































