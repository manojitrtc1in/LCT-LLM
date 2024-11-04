




















































































using namespace std;
const int MOD = 1e9+7; 

const int MAX = 2e5+5;
const ll INF = 1e18;
const double PI = acos(-1.0);

int msb(ll n){int ans;for(int i = 0 ; i < 64;  i++)if(n&(1LL<<i))ans = i+1;return ans;}
int SetBit (int n, int X) { return n | (1 << X); }
int ClearBit (int n, int X) { return n & ~(1 << X); }
int ToggleBit (int n, int X) { return n ^ (1 << X); }
bool CheckBit (int n, int X) { return (bool)(n & (1 << X)); }
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}





inline bool btr (volatile void * mem, size_t offset) {
	bool result;
	__asm__ (
		"btr %2, %1; setc %0;"
		: "=r" (result), "+m" (* (volatile long *) mem)
		: "r" (offset)
		: "cc");
	return result;
}




inline bool bts (volatile void * mem, size_t offset) {
	bool result;
	__asm__ (
		"bts %2, %1; setc %0;"
		: "=r" (result), "+m" (* (volatile long *) mem)
		: "r" (offset)
		: "cc");
	return result;
}









































































































































































































































































































































































































































































inline bool bittest (volatile void * mem, size_t offset) {
	bool result;
	__asm__ (
		"bt %1, %2; setc %0;"
		: "=r" (result)
		: "r" (offset), "m" (* (volatile long *) mem)
		: "cc");
	return result;
}




inline void id8 (volatile void * mem, size_t offset) { __asm__ ("bts %1, %0;" : "+m" (* (volatile long *) mem) : "r" (offset) : "cc");}



inline void id0 (volatile void * mem, size_t offset) { __asm__ ("btr %1, %0;" : "+m" (* (volatile long *) mem) : "r" (offset) : "cc");}



long long operator "" _m(unsigned long long literal) {return literal;}
long double operator "" _cm(unsigned long long literal) { return literal / 100.0;}
long long operator "" _km(unsigned long long literal) { return literal * 1000; }







void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }




int sum() { return 0; } template<typename T, typename... Args> T sum(T a, Args... args) { return a + sum(args...); }




int id6(int n) { int lo = 0, hi = n; while (lo <= hi) { int mid = (lo + hi) / 2;
        if (mid * mid <= n) lo = mid + 1; else hi = mid - 1; }return lo - 1;
}




bool id5 (ll x) {return x && (!(x&(x-1)));}

ll digNO(ll num){  return floor(log10(num)) + 1; }




string id3(ll n){  string s; stringstream ss; ss << n; s = ss.str(); return s;
}




ll id10(ll number){ ll reverse = 0; ll rem;  while(number!=0) {
     rem=number%10;  reverse=reverse*10+rem; number/=10;  } return reverse;}



vll prime;
bool sieve[1000000];

void id4(int n){
    sieve[0] = sieve[1] = 1;

    

    prime.push_back(2);

    

    for(ll i = 4; i<=n; i+=2){
        sieve[i] = 1;
    }

    ll id7 = sqrt(n);

   

    

    for(ll i = 3; i<= id7; i+=2){
        if(sieve[i] == 0){
            for(ll j = i*i; j<=n; j+=2*i){
                sieve[j] = 1;
            }
        }
    }

    

    for(ll i = 3; i<=n ; i+=2){
        if(sieve[i] == 0) prime.push_back(i);
    }
}



vector <ll> primeFactors;
void id1(ll n){  ll id7 = sqrt(n);
        for(ll i = 0; i<prime.size() && prime[i] <= id7; i++){
        if(sieve[n] == 0) break;
        if(n % prime[i] == 0){ while(n % prime[i] == 0){   n /= prime[i]; primeFactors.push_back(prime[i]); }  id7 = sqrt(n); } }
        if(n!=1) primeFactors.push_back(n); }



ll gcd(ll n1, ll n2){while(n1 != n2){  if(n1 > n2) n1 -= n2; else n2 -= n1; } return n1; }



ll LCM(ll n1, ll n2){ ll m = max(n1,n2); do {  if (m % n1 == 0 && m % n2 == 0) return m; else ++m; } while (true); }


string id13(const string& a){string s = a;reverse(s.begin(),s.end());s = a+"%"+s;int c = 0;vector<int> pref(2*((int)a.size()) +2);for(int i = 1; i< s.size() ; i++ ){while(c!=0&&s[i]!=s[c])c = pref[c-1];if(s[i]==s[c])c++;pref[i] = c;}return s.substr(0,c);}












ll power(ll n,ll p){if(p==0) return 1;if(p==1)return n;if(p%2)return power(n,p-1)*n;else{ll x=power(n,p/2);return x*x;}}
ll fact(ll num){ll fac=1;while(num!=1){fac=fac*num;num--;}return fac;}
int id11(string n){string num=n;int dec_value=0;int base=1;int len=num.length();for(int i=len-1;i>=0;i--){if(num[i]=='1')dec_value+=base;base=base*2;}return dec_value;}
string id12(string a, string b){ string s=""; while(a.size()<b.size()) {a='0'+a;} while(a.size()>b.size()) {b='0'+b;} ll c=0;
 for (ll i=a.size()-1;i>=0;i--){c+=(a[i]-'0')+(b[i]-'0'); s=char((c%10)+'0')+s; c/=10;} while(c>0){s=char((c%10)+'0')+s;c/=10;}return s;}
ll id9(string digits){ll num,total=0; for(int i = 0; i < digits.length(); i++){num = digits.at(i) - '0';assert(0 <= num && num <= 9);total += num;}return total;}
ll id2(ll n){ll sum=0;while(1){if(n<10){ sum+=n; break;}else{sum+=n%10;n/=10;}}return sum;}



ll powerMod(ll a, ll b)
    {
        ll x = 1;
        while (b > 0)
        {
            
            if (b&1) x = (x*a) % MOD;
            a = (a*a) % MOD;
            
            if (b&1) x *= a;
            a *= a;
            
            b >>= 1;
        }
        return x;
    }
ll multiplyMod(ll a, ll b)
    {
        
        ll res = 0;
        while(b)
        {
            if (b&1)
            {
                res += a;
                if (res >= MOD) res -= MOD;
            }
            b >>= 1;
            a = (a << 1);
            if (a >= MOD) a-= MOD;
        }
        return res;
        
        return a*b;
        
    }
ll inverseMod(ll a, ll m)
    {
        a = a % m;
        for (ll x = 1; x < m; x++)
        {
            if ((a * x) % m == 1)
                return x;
        }
        return -1;
    }






bool ispal(string s){
    ll i=0;
    ll j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
const int MA=2e5+5;
void scan(vector<ll> &v) { ll n = v.size() ; for(ll i=0 ;i<n;i++) scanf("%lld",&v[i]) ; }
vector<ll> adj[MA] ;
ll vis[MA] , lvl[MA] ,lvl1[MA],vis1[MA] ;
void edge (ll u , ll v) {
    adj[u].eb(v) ;
    adj[v].eb(u) ;
}

void dfs(ll n){
  vis[n]=1;
  ll tot=1;
  for(auto it: adj[n]){
    if(!vis[it]){
        dfs(it);
        tot+=lvl[it];
    }
  }
  lvl[n]=tot;
}

void bfs(ll n){
   vis1[n]=1;
   queue<ll> q;
   q.push(n);
   lvl1[n]=0;
   while(!q.empty()){
    ll f=q.front();
    q.pop();
    for(auto it: adj[f]){
        if(!vis1[it]){
            q.push(it);
            lvl1[it]=lvl1[f]+1;
            vis1[it]=1;
        }
    }
   }
}
ll binsearch(vll v, ll l, ll r, ll no){
    while (l <= r){
        ll mid = (l + r) / 2;
        if (v[mid] == no)
            return mid;
        else if (v[mid] < no)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}



ll fib(ll n){
  double phi = (1+sqrt(5))/2;
  return round(pow(phi,n)/sqrt(5));
}
bool primeCheck(long long n){if(n%2 == 0)return false; for(ll i=3;i*i<=n;i+=2){if(n%i == 0)return false;}return true;}

void input(vll v,ll n)     {wh(n--) { ll a; cin>>a; v.eb(a);}}
void prnt(vs v){ ll n=v.size(); for(int i=0;i<n;i++)  cout<<v[i]<<" "<<"\n"[i==n-1]; }




int main()
{

    fast;
    ll a,b,i,c,d,n,e,g,r,j,k,l,f=2,h=0,m=4,o=0,t=4,ans=0;
    st w="ROYGBIV",y,z;

    cin>>t;
    

    wh(t--)
    {
        f=0;
        vll v;
        mll mpl;
        m=4;
        wh(m--)
        {
            cin>>a;
            v.pb(a);
            mpl[a]++;
        }
        for(auto it=mpl.begin();it!=mpl.end();it++)
        {
            if(it->second>=2 && it->first >= f)
            {
                f=it->first;
            }

        }
        h=(v[0]*v[1])+(v[2]*v[3]);
        if(h==f*f) Y;
        else N;

    }




    rt;
}


