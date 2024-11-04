  
         
        
        
        
         
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        

        using namespace std;
         
        

        
        
        
        
        
        
        
        using namespace tr1;
        
        
        
        
        
     
        

        using namespace __gnu_pbds;
         
        
        
        
        
        
        
        
        
        
        
        
        

     
        
        
        
            template <typename Arg1>
            void __f(const char* name, Arg1&& arg1){
                cout << name << " : " << arg1 << std::endl;
                

            }
            template <typename Arg1, typename... Args>
            void __f(const char* names, Arg1&& arg1, Args&&... args){
                const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
            }
        
        
        
     
     
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
         
        
        
        
        
        
         
        
        
        
        
        
        typedef long long ll;
        typedef unsigned int uint;
        typedef unsigned long long ull;
        typedef double d;
        typedef float f;
        typedef pair<int, int> pii;
        typedef pair<long long, long long> pll;
        typedef vector<int> vi;
        typedef vector<long long> vll;
        typedef int itn;
        typedef long l;
        typedef long double ld; 
     
     
        

        typedef priority_queue<ll, vector<ll> > max_pq;
        

        ll toint(const string &s) {stringstream ss; ss << s; ll x; ss >> x; return x;}
        string tostring ( ll number ){stringstream ss; ss<< number; return ss.str();}
         
        typedef priority_queue<pair < ll , pair < pii , ll > >  , vector<pair < ll , pair < pii , ll > >  > ,greater<pair < ll , pair < pii , ll > >  > > min_pq;
     
        typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
        

     
        typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > OST;
        

        

     
     
     
     
     
        typedef set<ll>::iterator sit;
        typedef map<ll,ll>::iterator mit;
        typedef list<ll>::iterator lit;
        
        
        

        template<class T1, class T2, class T3>
        struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
        template<class T1, class T2, class T3>
        bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
        template<class T1, class T2, class T3>
        bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}
        
        
         
         
        

         
        
        
        
        

        
        
        
        
        
        
        

        
        
        
     
        
        
         
        
        
        
         
        
        
         
        
        
        
        
      
         
         
        

         
         
        const int mod = 1e9 + 7 ;
        const l maxn =200500;
        const ll inf=(2e9) + 2;

        
        ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
        ll gcd(ll a , ll b){return a==0?b:gcd(b%a,a);}

        

        

        ll id1(ll a, ll b, ll *x, ll *y)
        {
            

            if (a == 0)
            {
                *x = 0;
                *y = 1;
                return b;
            }
         
            ll x1, y1; 

            ll gcd = id1(b%a, a, &x1, &y1);
         
            

            

            *x = y1 - (b/a) * x1;
            *y = x1;
         
            return gcd;
        }
         
         int some_primes[7] = {24443, 100271, 1000003, 1000333, 5000321, 98765431, 1000000123};
         
         
         
         
        
        
        
        
         
        
        
        
        
        

        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
         
    

        int32_t solve();   
        

        

        

        

     
        int id0(unsigned n)
        {  return n && (! (n & (n-1)) ); }

        

        
        

        

        ll expower(ll x, ll y, ll m)
        {
        if (y == 0)
            return 1;
        ll p = expower(x, y/2, m) % m;
        p = (p * p) % m;
     
        return (y%2 == 0)? p : (x * p) % m;
        }
        

        
        ll mypower(ll x,ll y)
        {
            ll res = 1;      

         
            

                        

        
            while (y > 0)
            {
                

                if (y & 1)
                    

         res=res*x;
                

                y = y>>1; 

                

                x*=x;
            }
            return res;
            }
            
        ll id2(ll x,ll y, ll p)
        {
            ll res = 1;      

         
            x = x % p;  

                        

        
            while (y > 0)
            {
                

                if (y & 1)
                    res = (res*x) % p;
                

                y = y>>1; 

                x = (x*x) % p; 
            }
            return res;
        }
         
            
        
         
    

    

    

    

    

     
    

    

    

     
    

    

        
        
        
    

    

    

    

    

    

    

    

     
    

    

    

     
    

    

    

    

    

    

        
    

    

     
    

    

    

    

    

    

    

    

    

     
    

    

    

    

    

    

    

    

    

    

    

    

    

     
    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

     
    

    

    

    

    

     
    

    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        
        
    

    

    

     
     
        int32_t main(int argc, char** argv) {
           
        ios_base::sync_with_stdio(0);cin.tie(0);
        
                  FREIN("input.txt");
                  

        
     
        

     
        

        

        

        

     
     
            return solve();
        }
        int32_t solve(){
            

            

            int n,i;ci1(n);ll A[n];ll ways=0;ll result=0;
            

            

            
            
            
            
            
            
            FI(n) {ci1(A[i]);if(A[i]==1) ways++;}
            if(ways!=0) {ct1((n-ways)); return 0;}
            ll x=0, y=0;ll temp,ans=INF;
            

                for(i=0;i<=n-2;i++){
                temp=A[i]; 

                for (int j = i+1; j <n; j++) {

                    
                    result=id1(temp,A[j],&x,&y);

                    if(result==1) {ways=((j-i)+(n-1));ans=min(ans,ways);
                    
                    if(j-i+1==2){ct1(ways);return 0;}
                    
                    break;}
                    temp=result;x=0,y=0;
                }
                ways=0;
                result=0;
                

                

            }
            
            
            if(ans==INF) ct1(-1);
            else ct1(ans);
            return 0;
        }