















typedef long long ll;
using namespace std;
 

 
bool id0(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 
string getString(char x) 
{ 
     
    string s(1, x); 
  
    return s;    
}
ll max(ll a,ll b)
{
  if(b>a)
   return b;
   else
   {
     return a;
   }
   
}

ll factorial[500005];
 
void swap(int* a, int* b) 
{ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
int visited[200005],val[200000];
void DFS(ll n,vector<int> v[])
{  visited[n]=1;
   forn(i,0,v[n].size())
   {
     if(visited[v[n][i]]==0)
     {
       DFS(v[n][i],v);
     }
   }
   
}
 
void dfs(int n,vector<int> v[])
{  visited[n]=1;
    
   forn(i,0,v[n].size())
   {
     if(visited[v[n][i]]==0)
     {
       dfs(v[n][i],v);
 
     }
   }
   
   
}
 
int  vitree(int n, vector<int> v[])
{  int count=0;
    visited[n]=1;
    forn(i,0,v[n].size())
    {
      if(visited[v[n][i]]==0)
     {
       count+=vitree(v[n][i],v);
     }  
    }
    if(count==0)
     { val[n]=1;
         return 1;
        
     }
    else
    { val[n]=count;
        return count;
    }
    
}
 
bool id7(int n,vector<int> v[],int co)
{
    visited[n]=1;
    val[n]=co;
    forn(i,0,v[n].size())
    {
        if(visited[v[n][i]]==0)
           {  bool m=id7(v[n][i],v,(co==1)?0:1);
               if(m==false)
                    return false;
                
           }
        else
        {
            if(val[v[n][i]]==co)
               return false;
                  
        }
        
    }
    return true;
 
}

  
ll modPow(ll  a, ll x, ll p) {
    

    ll res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}
 
ll modInverse(ll a, ll p) {
    

    

    return modPow(a, p-2, p);
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
     
}
 
struct cmp
{
	bool operator() (pair<ll, pair<ll,ll>> a, pair<ll, pair<ll,ll>> b){
		return a.first > b.first;
	}
};
 
vector<ll> Sieve(ll n)
 {
   ll prim[n+1];
   memset(prim,1,sizeof(prim));
   for(ll p=2; p*p<=n;p++)
    {
      if(prim[p])
       {
         for(ll i=p*p;i<=n;i+=p)
          {
            prim[i]=0;
          }
       }
    }
    vector<ll> v;
    forn(i,2,n+1)
     {
       if(prim[i])
         v.pb(i);
     }
     return v; 
 } 
int primeFactors(int n) 
{ 
    

    int ans=0;
    while (n % 2 == 0) 
    { 
        ans++;
        n = n/2; 
    } 
    if(ans>2)
      return 0;
    

    

    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        

        while (n % i == 0) 
        { 
            ans++;
            n = n/i; 
        } 
    if(ans>2)
      return 0;
    } 
    
    

    

    if (ans==0) 
        return 0;
   return 1;
    
} 
vector<ll> prim;
void id5(ll limit, vector<ll> &prime)
{
    

    

    

    vector<bool> mark(limit + 1, true);
 
    for (ll p=2; p*p<limit; p++)
    {
        

        if (mark[p] == true)
        {
            

            for (ll i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
 
    

    for (ll p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            prim.pb(p);
        }
    }
}
 


void id4(ll n)
{
    

    

    ll limit = floor(sqrt(n))+1;
    vector<ll> prime;
    prime.reserve(limit);
    id5(limit, prime);
 
    

    

    ll low = limit;
    ll high = 2*limit;
 
    

    

    while (low < n)
    {
        if (high >= n)
           high = n;
         
        

        

        

        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        

        

        for (ll i = 0; i < prime.size(); i++)
        {
            

            

            

            

            ll loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            
            for (ll j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        

        for (ll i = low; i<high; i++)
            if (mark[i - low] == true)
                prim.pb(i);
 
        

        low = low + limit;
        high = high + limit;
    }
}

int id1(int n)
{
    

    if (n % 2 == 0)
        return 2;
  
    

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
  
    return n;
}

int pow(int base, int exponent, int modulus)
{
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
           result = (result * base)% modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
 


int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
 


int order(int p, int b)
{
    if (gcd(p, b) != 1)
    {
        printf("p and b are not co-prime.\n");
        return -1;
    }
 
    

    int k = 3;
    while (1)
    {
        if (pow(b, k, p) == 1)
            return k;
        k++;
    }
}
 






int id2(int x, int& e)
{
    e = 0;
    while (x % 2 == 0)
    {
        x /= 2;
        e++;
    }
    return x;
}
 


int id3(int n, int p)
{
    

    

    if (gcd(n, p) != 1)
    {
        printf("a and p are not coprime\n");
        return -1;
    }
 
    

    

    if (pow(n, (p - 1) / 2, p) == (p - 1))
    {
        printf("no sqrt possible\n");
        return -1;
    }
 
    

    

    int s, e;
    s = id2(p - 1, e);
 
    

    

    int q;
    for (q = 2; ; q++)
    {
        

        if (pow(q, (p - 1) / 2, p) == (p - 1))
            break;
    }
 
    

    int x = pow(n, (s + 1) / 2, p);
    int b = pow(n, s, p);
    int g = pow(q, s, p);
 
    int r = e;
 
    

    while (1)
    {
        int m;
        for (m = 0; m < r; m++)
        {
            if (order(p, b) == -1)
                return -1;
 
            

            if (order(p, b) == pow(2, m))
                break;
        }
        if (m == 0)
            return x;
 
        

        

        x = (x * pow(g, pow(2, r - m - 1), p)) % p;
        g = pow(g, pow(2, r - m), p);
        b = (b * g) % p;
 
        if (b == 1)
            return x;
        r = m;
    }
}

int minSum(vector<int> v)
   {
       int min_ans=INF;
       for(int i=0;i<v.size();i++)
        {
            if(v[i]!=i+1)
              { vector<int> p=v,f=v;
              
                swap(p[i], p[(i+v[i])%v.size()]);
                swap(f[i], f[(i-v[i] + v.size())%v.size()]);
                  min_ans=min(min_ans,1 + minSum(p));
                  min_ans=min(min_ans,1+minSum(f));
              }
        }
       if(min_ans==INF) 
            return 0;
      return min_ans;
   }


bool id8(const pair<int,int> &a,
              const pair<int,int> &b)
{
   if(a.first!=b.first) 
           return a.first<b.first;   
        return a.second < b.second;
}



unsigned long long power(unsigned long long x,
                                  int y, long long p)
{
    unsigned long long res = 1; 

 
    x = x % p; 

    

 
    while (y > 0)
    {
     
        

        if (y & 1)
            res = (res * x) % p;
 
        

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;
}
 


unsigned long long modInverse(unsigned long long n, 
                                           long long p)
{
    return power(n, p - 2, p);
}
 




unsigned long long fac[100005];
unsigned long long id6(unsigned long long n,
                                 long long r, long long p)
{
    

    if (n < r)
        return 0;
    

    if (r == 0)
        return 1;
 
    

    

    

    

 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
bool check_pref(string s, int ind, string t)
   {   if(ind+t.length()>s.length())
          return 0;
       for(int i=0;i<t.length();i++)
         {
             if(s[ind+i]!=t[i])
                return 0;
         }
        return 1;
   }
int main()
 {ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     freopen("log.txt", "w", stderr);
    
    
    int T;
    cin>>T;
    while(T--) {
        string text;
        cin>>text;

        int k;
        cin>>k;
        string s[k];
        forn(i,0,k)
          cin>>s[i];
        
        int n=text.length();
        vector<pair<int,int>> w;
        int temp=-1,flag=1,curr=0,br=-1,pos=-1,count=0;
        forn(i,0,n)
          { int tempa=-1,bra=-1, posa=-1; 
              for(int j=0;j<k;j++)
               { 
                   if(check_pref(text, i, s[j])) 
                     { 
                         if(max(tempa, s[j].length()+i) == (s[j].length()+i))
                            { 
                                tempa=i+s[j].length();
                              bra=j;
                              posa=i;
                              
                            }
                     }
               }
            if(tempa>temp)
              {
                  temp=tempa;
                  br=bra;
                  pos=posa;
              }
            if(curr==i)
              { 
                 if(temp<=curr)
                   {
                       flag=0;
                       break;
                   }
                 count++;
                 curr = temp;
                 w.push_back({br+1, pos+1});
                 temp=-1;
                 br=-1;
                 pos=-1;
              }
          }
    
        if(flag==0)
          cout<<"-1\n";
        else
         { 
             cout<<w.size()<<endl;
             for(int i=0;i<w.size();i++)
              cout<<w[i].first<<" "<<w[i].second<<"\n";
         }

    }
        

       
       

    
     
   
    
        
  

     return 0; 
    
}