     
         
        
        
        
        
         
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        
        
        

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

        
        long id4(long a, long b)
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
         
        template<typename T>
        T getint() {
            T x=0,p=1;
            char ch;
            do{ch=getchar();}while(ch <= ' ');
            if(ch=='-')p=-1,ch=getchar();
            while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
            return x*p;
        }
 
        

 
        template<typename T1,typename T2>bool umin(T1 &x,const T2&y){if(x>y)return x=y,true;return false;}
        template<typename T1,typename T2>bool umax(T1 &x,const T2&y){if(x<y)return x=y,true;return false;}
 
        
        const int maxq=(int)2e6+10;
        const ll llinf=(ll)1e18+5;
        const ld pi=acos(-1.0);
         
         
        
        
        
        
         
        
        
        
        
        

        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        

        
        
        
        
        
        
        
        
        
         
    

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
         
            
        
         
    

    

    

    

    

     
    

    

    

     
    

    

        
        
 
 
 
    
 
 
 
 
 
        
        
        
        
        
        

        set<long long> sset;
        map<long long,long long> mapp, b;
        vector<long long> vec;
        
        
        
 
 
    
     
     
     
     
     
 
 
    
        ll findf(l factor){ll facto=1;
while(factor!=1){
                    facto*=factor;factor--;
                }
                return facto;
        }
                
       
       

         l id5(l element,l low,l high){

               
            if(low>high) return -1;
            l mid=(low+high)/2;
            if(vec[mid]==element) return mid;
            if(element>vec[mid]) return id5(element,mid+1,high);
            else return id5(element,low,mid-1);
        }
 
 
 
        
        ll id7(vector<pair<ll,ll>> a,ll element,ll low,ll high){
            if(low>high) return -1;
            l mid=(low+high)/2;
            if(a[mid].first==element) return mid;
            if(element>a[mid].first) return id7(a,element,mid+1,high);
            else return id7(a,element,low,mid);
 
        }
 
 
 
    

    ll id3(ll a[],ll element,ll low,ll high){
        ll mid=(low+high)/2;
        if(a[mid]==element) return mid;
        
        
        

        if(low>=high) return -1;
        if(element>a[mid]) return id3(a,element,mid+1,high);
        else return id3(a,element,low,mid);
    }
 
 
 
 
 
 
 
        

        

     
    
 
 
       

       
       ll validpair(string str){
           ll count=0,n=str.size();

        

        

        

        

        

        

                       
        

        

        

        

           

           
          

          

          

          

        

          vector<char> myvector;

          

              myvector.pb(str[0]);
          for (l i = 1; i < str.size(); i++) {

              
              
              sort(all(myvector));
              auto yu = myvector.end();

              

              

              

              

              

              auto hu = yu;
              

              

              auto it = lower_bound(myvector.begin(),hu,str[i]);

              

              
              

              auto checker = myvector.begin();checker--;
              it--;
              if(it==checker) {

              myvector.pb(str[i]);continue;}
              



               

              

              

              

              

              



            

            

            

                        
            

                       
            

            

            

            

            

                       
            

                       
            

            

            

            

                   
                   
            

            

            

                  
                  
            

            

            

            

                    count+=it-myvector.begin()+1;

                 

                 

                 

                 


                 

                     

              myvector.pb(str[i]);


          }
          

          return count;
           
       }
           
    

 
    

    

    

 
    

    

    

    

    

    

    

 
    

           
           




 
























           


                   
                   
 


       long tempo=0;ll prod=1;set<long>:: iterator pui,hu,it,moit;
       void findans(l a[],l start,l n,set<long> myset,l k){
            for(long i=start;i<=(n-k)+tempo;i++){
                myset.insert(a[i]);tempo++;
                if(myset.size()==k){
                    it=myset.begin();
                    it++;
                    moit=myset.end();moit--;
                    for (; it != moit; it++)
                    {
                        
                        prod=(prod*(*it))%NUM;
                    }
                    hu=myset.find(a[i]);myset.erase(hu);tempo--;
                    continue;
                }
                findans(a,i+1,n,myset,k);
                pui=myset.find(a[i]);myset.erase(pui);tempo--;

            }

            return;
       }



       


        

       
       

       

 
 
        

      
       

     
        int32_t main(int argc, char** argv) {
           
        ios_base::sync_with_stdio(0);cin.tie(0);
        
                  FREIN("input.txt");
                  

        
     
        

     
        

        

        

        

     
     
            return solve();
        }
       int32_t solve(){
           

           

           

           

           int t;ll no=0,h=0,m=0,ko=0,q=0,maxsum=llmind,minsum=id6,left,right;
           

           

           bool flag=false;l n,k;
           ll x,y;l count=0,c,exa=0,exb=0;
           

           

           

           
           

           

           

           

           

           

           

           

           

           

           



           ci2(n,m);
           int costgame[n];FI(n) ci1(costgame[i]);
           int bill[m];FI(m) ci1(bill[i]);
               int i=0;
               
                for (int j = 0; j < m; ++j)
                {
            for (; i < n;)
                {
                if(bill[j]>=costgame[i]){ no++;flag=true;i++;break;}
                i++;
                    
                }
                if(flag==false) {ct1(no);exit(0);}
           }

           ct1(no);



           

           

           

           

           

           

                        
           

                


           


           













           return 0;
       }