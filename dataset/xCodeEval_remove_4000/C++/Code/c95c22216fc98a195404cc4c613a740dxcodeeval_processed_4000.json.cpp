  
         
        
        
        
        
         
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        

        using namespace std;
         
        

        
        
        
        
        
        
        
        using namespace tr1;
        
        
        
        
        
     
        

        using namespace __gnu_pbds;
         
        
        
        
        
        
        
        
        
        
        
        mt19937 gen(time(NULL));
        
        

        

        

        
        

     
        
        
        
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
        
        
         
            
        template<typename T = int>
        inline T read() {
        	T val = 0, sign = 1; char ch;
        	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
        		if (ch == '-') sign = -1;
        	for (; ch >= '0' && ch <= '9'; ch = getchar())
        		val = val * 10 + ch - '0';
        	return sign * val;
        }
        

         
        
        
        
        

        
        
        
        
        
        
        

        
        
        
     
        
        
         
        
        
        
         
        
        
         
        
        
        
        
      
         
         
        

         
         
        const int mod = 1e9 + 7 ;
        const l maxn =200500;
        const ll inf=(2e9) + 2;

        
        ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
        ll gcd(ll a , ll b){return a==0?b:gcd(b%a,a);}

        
        long id3(long a, long b)
{
    if (a == 0)

        return b;
    else if (b == 0)
        return a;
 
    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}
        
        
        
        

        

        ll id2(ll a, ll b, ll *x, ll *y)

        {
            

            if (a == 0)
            {
                *x = 0;
                *y = 1;
                return b;
            }
         
            ll x1, y1; 

            ll gcd = id2(b%a, a, &x1, &y1);
         
            

            

            *x = y1 - (b/a) * x1;
            *y = x1;
         
            return gcd;
        }
         
         int some_primes[7] = {24443, 100271, 1000003, 1000333, 5000321, 98765431, 1000000123};
         
         
         
         
        
        
        
        
         
        
        
        
        
        

        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
         
    

        int32_t solve();   
        

        

        

        

     
        int id0(unsigned n)
        {  return n && (! (n & (n-1)) ); }

        

        
        

        

        
        

        

        

        

        

        

        

     
        

        

        

        
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
            
        ll id4(ll x,ll y, ll p)
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
         
            
        
         
    

    

    

    

    

     
    

    

    

     
    

    

        
        
        
    

    

    

    

    

    

    

    

     
    

    

    

     
    

    

    

    

    

    

        
    

    

     
    

    

    

    

    

    

    

    

    

     
    

    

    

    

    

    

    

    

    

    

    

    

    

     
    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

     
    

    

    

    

    

     
    

    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        
        
    

    

    

     
     
    

     



























     
       int isprime(int N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}
    
     
     
     
     
     
     
     
          



ll expower(ll x, ll y, ll m);
 




ll modInverse(ll a, ll m)
{
ll g = gcd(a, m);
if (g != 1){}
    

 
else
{
    

    

    

         return expower(a, m-2, m);
}
}
 


ll expower(ll x, ll y, ll m)
{
if (y == 0)
    return 1;
ll p = expower(x, y/2, m) % m;
p = (p * p) % m;
 
return (y%2 == 0)? p : (x * p) % m;
}
 
     
     
     
     
     
     
 


































 
 
     
     
     
     
    

    

    

    ll id1 (ll m, ll n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

    
    
    








 


 


 




 








    


 
















 










 






















 
    


     
     
     
     
 
    

 
 
 












 


 


 




 








 


 
















 












    
    
    
    








 


 




 




 




 






 




 
    
    
    
    



  


ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; 

    a = a % mod;
    while (b > 0)
    {
        

        if (b % 2 == 1)
            res = (res + a) % mod;
 
        

        a = (a * 2) % mod;
 
        

        b /= 2;
    }
 
    

    return res % mod;
}
    
    
    
    























 




 






 






     
     
     
     
     

     ll Logn(ll n, ll r)

    {
       return log(n) / log(r);
    }
     
     
     
     
     
     
     
        

        set<long long> sset;
        map<long long,long long> mapp, b;
        vector<long long> vec;
     
     
     
     
     
     
     
     
        

        

     
        ll func(ll a ){
            ll prod=1;
            while(a>0){if(a%10!=0)prod*=a%10;a/=10;}
            return prod;
        }
            
        ll check(ll a){
            if(a<10) return a;
            return check(func(a));
        }
            
            
     
     
     
     
     
     
     
     
     
     
     
     
     
     
        


    
     
     

     



































     
     
     
     


















 


 




























 
























 







     
            

     
        int32_t main(int argc, char** argv) {
           
        ios_base::sync_with_stdio(0);cin.tie(0);
        
                  FREIN("input.txt");
                  

        
     
        

     
        

        

        

        

     
     
            return solve();
        }
        int32_t solve(){
            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            




            



            

            

            


            

            

            

            


                    
            

            


            

            

            

                    



            


            

            

            

            

            ll R,x1,y1,x2,y2;            
            ci3(R,x1,y1);ci2(x2,y2);
            cout<<fixed<<setprecision(16);
            

            

                ld xap=0,yap=0;
            if(pow(abs(x2-x1),2)+pow(abs(y2-y1),2)>=pow(R,2)) {
                cout<<(ld)x1<<" "<<(ld)y1<<" "<<(ld)R<<"\n";

            }
            else if(x2==x1&&y2==y1){
                xap = (ld)(x1)+((ld)R)/2;
                yap = (ld)y1;
                cout<<xap<<" "<<yap<<" "<<(ld)(((ld)R)/2)<<"\n";
            }
            else {
                

                

                
                

                    ld dist = (ld)sqrt((ld)pow(abs(x2-x1),2)+pow(abs(y2-y1),2));
                    xap = ((ld)(((ld)(x1)*((ld)(dist+R))-(ld)(R*x2))/dist)+(ld)x2)/2;
                    yap = ((ld)(((ld)(y1)*((ld)(dist+R))-(ld)(R*y2))/dist)+(ld)y2)/2;
                    cout<<xap<<" "<<yap<<" "<<(ld)(((ld)(dist+(ld)R))/2)<<"\n";
                    
                

                                    

            }








































                    








            return 0;



        }