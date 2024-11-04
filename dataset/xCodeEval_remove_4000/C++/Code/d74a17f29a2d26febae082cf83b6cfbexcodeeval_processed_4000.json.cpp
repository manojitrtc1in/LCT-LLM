
          
         
         
         
         
          
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         

         
         
         

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

         
         long id11(long a, long b)
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
         
         
         
         

         

         ll id4(ll a, ll b, ll *x, ll *y)

         {
             

             if (a == 0)
             {
                 *x = 0;
                 *y = 1;
                 return b;
             }
          
             ll x1, y1; 

             ll gcd = id4(b%a, a, &x1, &y1);
          
             

             

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
         

         

         

         

      
         int id3(unsigned n)
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
             
         ll id5(ll x,ll y, ll p)
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
         
         
         


     


     

      

      int flag=0;
      

         ll x=0,y=0;
      

      

     

     class Graph
     {
         l V;    

      
         

         list<l> *adj;

         

      
         

         

         void DFSUtil(l v, bool visited[]);
         
     public:
         Graph(l V);   

         void addEdge(l v, l w);
         void removeEdge(l v, l w);
         void DFS(l v);        
         

     };
      
     

     

     

     

     

     

     

     

     

      
     

     

     

     

     

     

     

     

     

     

     

     

     

      
     

     

     

     

     

     

     

         
     

     

     

     

     

     

     



      
     Graph::Graph(l V)
     {
         this->V = V;
         adj = new list<l>[V];
     }
      
     

     void Graph::addEdge(l v, l w)
     {
         adj[v].push_back(w);

         adj[w].push_back(v);

     }
     void Graph::removeEdge(l v, l w)
     {
         
         

         

         list<l>::iterator i;
         

             

                 

                 

             


             

            i = find (adj[v].begin(), adj[v].end(), w); 

                        
             

             adj[v].erase(i);

             


             

         

         

         

         

         

         

        

        i = find (adj[w].begin(), adj[w].end(), v);
        




         

             adj[w].erase(i);
         
         
         

         

     }


         

         

         
      
     void Graph::DFSUtil(l v, bool visited[])
     {
         

         

         visited[v] = true;
         

         if(flag==0) x|=vec[v];else y|=vec[v];
         

         

         list<l>::iterator i;
         for (i = adj[v].begin(); i != adj[v].end(); ++i)
             if (!visited[*i])
                 DFSUtil(*i, visited);
     }
      

     void Graph::DFS(l v)
     {
         

         if(flag==0) x=0;else y=0;
         bool *visited = new bool[V];
         for (l i = 0; i < V; i++)
             visited[i] = false;
      
         

         

         DFSUtil(v, visited);
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


        bool id7(int n)
        {
            

            if (n <= 1)  return false;
            if (n <= 3)  return true;
         
            

            

            if (n%2 == 0 || n%3 == 0) return false;
         
            for (int i=5; i*i<=n; i=i+6)
                if (n%i == 0 || n%(i+2) == 0)
                   return false;
         
            return true;
        }
         
     
        

        bool id9(int x,int p)
        {
            bool flag=true;
            for(int i=2;i<=min(p,(int)sqrt(1.0*x));i++)
            {
                if(x%i==0)
                {
                    flag=false;
                    break;
                }
            }
            return flag;
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
  
      
      
      
      
      
      
  
 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

  
  
      
      
      
      
     

     

     

     ll id8 (ll m, ll n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

     
     
     
 

 

 

 

  
 

  
 

  
 

 

  
 

 

 

 

     
 

  
 

 

 

 

 

 

 

 

  
 

 

 

 

 

  
 

 

 

 

 

 

 

 

 

 

 

  
     
 

      
      
      
      
  
     

  
  
  
 

 

 

 

 

 

  
 

  
 

  
 

 

  
 

 

 

 

  
 

  
 

 

 

 

 

 

 

 

  
 

 

 

 

 

 

     
     
     
     
 

 

 

 

  
 

  
 

 

  
 

 

  
 

 

  
 

 

 

  
 

 

  
     
     
     
     
 


   
 

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
      
      
      
      
      
      
      
      
         

         

      
         ll func(ll a ){
             ll prod=1;
             while(a>0){if(a%10!=0)prod*=a%10;a/=10;}
             return prod;
         }
             
         ll check(ll a){
             if(a<10) return a;
             return check(func(a));
         }
             
             
      
      
      
      
      
      
      
      
      
      
      
      
      
      
         
 

     
      
      

      
 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 


      
      
      
      

 


 

 

 

 

 

 

 

  
 

  
 

 

 

 

 

 

 

 

 

 

 

 

 

 

  
 

 

 

 

 

 

 

 

 

 

 

 

  
 

 

 



         




     
         ll findf(l factor){ll facto=1;
 while(factor!=1){
                     facto*=factor;factor--;
                 }
                 return facto;
         }
                 
        
        

          l id13(l element,l low,l high){

                
             if(low>high) return -1;
             l mid=(low+high)/2;
             if(vec[mid]==element) return mid;
             if(element>vec[mid]) return id13(element,mid+1,high);
             else return id13(element,low,mid-1);
         }



         
         l id16(vector<pair<l,l>> a,l element,l low,l high){
             if(low>=high) return -1;
             l mid=(low+high)/2;
             if(a[mid].first==element) return mid;
             if(element>a[mid].first) return id16(a,element,mid+1,high);
             else return id16(a,element,low,mid);


         }


     

     ll id6(ll a[],ll element,ll low,ll high){
         ll mid=(low+high)/2;
         if(a[mid]==element) return mid;
         
         
         

         if(low>=high) return -1;
         if(element>a[mid]) return id6(a,element,mid+1,high);
         else return id6(a,element,low,mid);
     }







         

         

      
         

         

         

          
         

         

         

         

             
         

         

         

          
         

         

         

         

         

         

         

         

         

         

         

         

         

                         

         

         

         

         

         

         

         

         

         

         

         

                         

         

         

         

         

         

         

         

         

         

         

         

          

     



























         


         

         

         
         

         

         
          
         

         

         

         

         

         

         

         

         

         

         

          
         

         

         

         

         

          
         

         

         

         

          
         

         

         

         

         

         

          
         

         

         

         

          
         

         

          
         

         

         

          
         

         

          
         

         

         

         

         

          
         

         

         

         

         

         

         

         

         

          
         

         

         

         

         

         

         

         

              
         

         

         

          
         

         

         


                 

                 



         

         

         

         

         

         

         

         

         

         

         

             
         

         

         

          
         

         

         

         

         

         

         

         

         

         

          
         

         

         

         

         

         

         

         


     
         
     

         


         
          ll id14(ll num)

             {
                 if(num<0)
                     num+=mod;
                 num=num%mod;
                 return num;
             }
          

          ll id10(ll n, ll k)
          {
              return (n ^ (1 << (k-1)));
          }

          

          ll swapBits(ll n, ll p1, ll p2)
          {
              
              ll bit1 =  (n >> p1) & 1;
           
              
              ll bit2 =  (n >> p2) & 1;
           
              
              ll x = (bit1 ^ bit2);
           
              
              x = (x << p1) | (x << p2);
           
              
              ll result = n ^ x;
              return result;
          }


          ll id2(ll n, ll k)
          {
              

              return ((1 << k) | n);
          }
          ll id1(ll n, ll k)
          {
              

              if (k <= 0) return n;
           
              

              

              return (n & ~(1 << (k - 1)));
          }


          

  
          

          

          

          

          

          

          

           
          

          

          

          




         


         

         

         

         

         

         

           
         

         

         

           
         

         

         


           
         

         

         

         

         

         

         

         

         

         

         

         

           
         

         

         

         

         

         

         

           
         

         

     



         

         

         

         

         

         

          
         

         

         

             
         

         

          
         

         

         

         

         

          
         

         

         

         

                 


         

          
         

         

         

         

         

         


         

         

         

         





                       
                         
                         
       long long C(int n, int r) {

             if(r > n / 2) r = n - r; 

             long long ans = 1;
             int i;
          
             for(i = 1; i <= r; i++) {
                 ans *= n - r + i;
                 ans /= i;
             }
          
             return ans;
       }
          

        


        float rounded(float var){
            

            

            

            

            float value = (int)(var * 100 + .5);
            return (float)value / 100;
        }


           
           
       

       

       

       

       

       

       

       

       

       

       

       

       

                    
       

       

                    
       

                
       

       

       

       

           
       
        

       

       

       

       

       

       

       

       

       

         
       

       

       

       

       

       

         
       

       

       

       

       

       

       

       

       

       

       

       

         

       

       

       

       


       

       


       

       

       

       

       

       

       

       

       



       

       





         

       
        

      
         int32_t main(int argc, char** argv) {
            
         ios_base::sync_with_stdio(0);cin.tie(0);
         
                   FREIN("input.txt");
                   

         
      
         

      
         

         

         

         

      
      
             return solve();
         }
        int32_t solve(){
            

            

            

            

            int t;ll n=0,h=0,x=0,m=0,k=0,q=0,maxsum=llmind,minsum=id15,left,right;
            

            

            

                   
                

                

                

                

                

                

                

                


                

                

                

                


            std::multiset<ll> id0;
            multiset<ll>::iterator msit;
            std::vector<pair<ll,pair<ll,ll>> > myv;
                ci2(n,k);ll pow[n],coins[n],ans[n];
                FI(n) ci1(pow[i]);
                FI(n) {ci1(coins[i]);}
                FI(n){
                    myv.pb(mp(pow[i],mp(coins[i],i)));
                }
                sort(all(myv));

                

                

                

                

                    
                



                ll sum=0,id12;
                FI(myv.size()){
                    id12=i+1;
                    if (id12<=k+1)
                    {
                        
                        sum+=myv[i].second.first;
                        ans[myv[i].second.second]=sum;
                        if(id12==k+1){
                            sum-=myv[i].second.first;
                            if(id0.size()!=0){
                            msit=id0.begin();
                            if(myv[i].second.first>(*msit)) {
                                sum-=*msit;
                                id0.erase(msit);
                                id0.insert(myv[i].second.first);
                                sum+=myv[i].second.first;
                            }}

                        }
                        else {
                            id0.insert(myv[i].second.first);
                            
                        }
                    }
                    else {
                        ans[myv[i].second.second]=sum+myv[i].second.first;
                        msit=id0.begin();
                        if(myv[i].second.first>(*msit)) {
                            sum-=*msit;
                            id0.erase(msit);
                            id0.insert(myv[i].second.first);
                            sum+=myv[i].second.first;
                        }
                        
                    }


                    

                    

                    

                    

                    

                    


                    

                    

                    

                    

                    


                    

                    

                    



                    

                    

                        
                    

                    

                    

                    

                    

                    

                    

                    


                }
            




                FI(n) cout<<(ans[i])<<" ";
                ct1("\n");


            

                
                
            return 0;
            }