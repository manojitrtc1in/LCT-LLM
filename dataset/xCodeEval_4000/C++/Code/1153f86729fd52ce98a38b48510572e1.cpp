



























































#include <bits/stdc++.h>
const long double pi = 3.1415926535897932384626433832795;
#define scn(n) scanf("%d",&n)

#define lscn(n) scanf("%lld ",&n)

#define scn2(n1,n2) scanf("%d%d",&n1,&n2)

#define lscn2(n1,n2) scanf("%lld%lld",&n1,&n2)

#define lpri(n) printf("%lld ",n)

#define lpri2(n1,n2) printf("%lld %lld\n",n1,n2)

#define pri(n) printf("%d ",n)

#define pri2(n1,n2) printf("%d %d\n",n1,n2)

#define pln() printf("\n")

#define priln(n) printf("%d\n",n)

#define lpriln(n) printf("%lld\n",n)

#define RAL(i,x,n) for(int i=x;i<n;i++)

#define RALR(i,x,n) for(int i=x-1;i>=n;i--)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define mp make_pair

#define F first

#define S second
#define sq(a) (a)*(a)
#include<unordered_set>
#define lli long long int
#define toh_shuru_karte_hai_bina_kise_bakchodi_ke ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define test lli t;cin>>t;while(t--)
#define arrin lli n;cin>>n;lli a[n];for(lli i=0;i<n;i++)cin>>a[i]       

#define floop for(lli i=0;i<n;i++)
#define mod 1000000007
#define defvec vector<lli>v
#define ub upper_bound
#define pb push_back
#define pob pop_back
#define mp make_pair
#define emp emplace_back
#define bs binary_search
#define pi 3.1415926536
#define INF ll(8230219982008199610)
#define MINF ll(-8230219982008199610)
#define ones(n) __builtin_popcountll(n)
#define focc(n) __builtin_ffsll(n) 

#define leadingzero(n) __builtin_clzll(n)
#define trailingzeroes(n) __builtin_ctzll(n)
#define loop0(i,n) for(int i=0; i<n; i++)
#define loop1(i,n) for(int i=1; i<=n; i++)
#define rev0(i,n)  for(int i=n-1; i>=0; i--)
#define rev1(i,n)  for(int i=n; i>0; i--)
#define code lli n,k;cin>>n>>k;lli a[n];loop0(i,n) cin>>a[i]
#define loopj(j,k,n) for(lli j=k;j<n;j++)
#define all(x) x.begin(), x.end()
#define print(v) for(auto x:v)cout<<x<<" "
#define prints for(lli i=0;s[i];i++)cout<<s[i]
using namespace std;

#define INT_BITS 16










lli log2(lli x)
{
  lli res=0;
  while(x>>=1)
  res++;
  return res;
}
lli comb(lli n,lli r)

{
    
if(r==0||r==n)
return 1;
    
return 
comb(n-1,r)+comb(n-1,r-1);

}
bool isPowerOfTwo(lli n) 
{ 
   if(n==0) 
   return false; 
  
   return (ceil(log2(n)) == floor(log2(n))); 
} 
lli inverse(lli a,lli m)
{
    return 1<a?m-inverse(m%a,a)*(m/a):1;   

}

lli computeXOR(lli n)
{
  if(n%4==0)
  return n;                        

  if(n%4==1)
  return 1;
  if(n%4==2)
  return n+1;
  else
  return 0;
}

bool isPerfectSquare(long double x) 

{  
 long double sr = sqrt(x); 
return ((sr - floor(sr)) == 0); 

} 
bool isvowel(char ch)      
{
    string s = "aeiouAEIOU";
    for (char c : s)
    {
        if (c == ch)
        {
            return true;
        }
    }
    return false;
}
bool isPrime(lli n) 
{ 
    if(n<=1)  return false; 
    if(n<=3)  return true; 
    if(n%2==0||n%3==0) return false; 
    for(lli i=5; i*i<=n; i=i+6) 
    if (n%i == 0 || n%(i+2) == 0) 
    return false; 
    return true; 
}

bool isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
    for (int i = 0; i <= N - M; i++) { 
        int j; 
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
  
        if (j == M) 
            return true; 
    } 
  
    return false; 
} 
lli power_(lli a,lli n) 
{ 
    lli res = 1;      
   
    while (n > 0) 
    { 
        if (n& 1) 
            res = ((res)*(a)); 
        n/=2; 
        a=((a)*(a));
    } 
    return res; 
}
lli factmod(lli n,lli p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    lli res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res; 
}

lli modularexponentiation(lli a,lli n,lli mo) 
{ 
    lli res = 1;      
   
    while (n > 0) 
    { 
        if (n& 1) 
            res = ((res%mo)*(a%mo))%mo; 
        n/=2; 
        a=((a%mo)*(a%mo))%mo;
    } 
    return res; 
}
    lli countDivisors(lli n) 
{ 
    lli cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i != i) 
                cnt++;
                cnt++;
        } 
    } 
    return cnt;
}


lli highestpowerof2(lli n)   

{
    return (n&(~(n-1)));
}
void lowertoupper(char ch)
{
   ch=ch&'_';
  cout<<ch<<" ";
}
void uppertolower(char ch)
{
  ch=ch|' ';
  cout<<ch<<" ";
}
lli primecounter(lli l,lli r)
{                              

   lli fact=1,count=0;
   for(lli i=l;i<=r;i++)
   {
      if(((fact-i)%((1LL<<i)-1))==0)
      count++;
    fact*=((1LL<<i)-1);
   }
  return count;
} 
lli counteprime(lli l,lli r)
{
   lli count=0,i,j;
  for(i=l;i<=r;i++)          
  {
     for(j=2;j<=(i/j);j++)
     {
       if(!(i%j))
       break;
     }
      if(j>(i/j))
      count++;
   }
return count;
}
lli fibo(lli n)
{
    long double him=(1+sqrt(5))/2;
  return round(pow(him,n)/sqrt(5));
}
lli binToDec(string c) 
{  
    lli count=0;
    for(lli i=0;i<c.length();i++)
   {
       if (c[i] == '1'){
            lli val = 1;
           for(lli j=0;j<i;j++)
           {
                val *= 2;
            }
            count += val;
        }
   }
   return count;
} 
vector<lli> Eratosthenes(int n) 
{
    vector<lli> res;
    vector<bool> Prime(n + 1, true);
    Prime[0] = Prime[1] = false;
    for(int i=4;i<=n;i+=2)
    {
        Prime[i]=false;
    }
    for (int i = 3; i * i <= n; i+=2) 
    {
        if (Prime[i]) 
        {
            for (int j = i*i; j <= n; j+=i) 
            {
                if(Prime[j]==true)
                Prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) 
    {
        if (Prime[i]) 
        {
            res.emplace_back(i);
        }
    }
    return res;
}
lli bs(lli a[],lli start,lli end,lli x,lli n)
{
    lli mid=start+(end-start)/2;
    if(start>end)
    return -1;
    if(a[mid]==x)
    return mid;
    else if(a[mid]>x)
    return bs(a,start,mid-1,x,n);
    else 
    return bs(a,mid+1,end,x,n);
}
void transpose(vector<vector<lli>>&v)
{
    loop0(i,v.size())
    {
        loop0(j,i)
        {
            swap(v[i][j],v[j][i]);
        }
    }
}
map<lli,lli> primeFactors(lli n)  
{  
    map<lli,lli>mp;
    while (n % 2 == 0)                          

    {  
        mp[2]++;
        n=n/2;
    }  
    for (lli i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
           mp[i]++;                 

            n = n/i;  
        }  
    }  
    if (n > 2)  
        mp[n]++;
        
        return mp;
}  
void primefactors(lli n)
{                                     

    lli d[n+1];
    for(lli i=1;i<=n;i++)
    d[i]=i;
    for(lli i=2;i<=n;i+=2)
    {
        d[i]=2;
    }
    for(lli i=3;i*i<=n;i+=2)
    {
        if(d[i]==i)
        {
            for(lli j=i*i;j<=n;j+=i)
            {
                if(d[j]==j)
                {
                    d[j]=i;
                }
            }
        }
    }
    
    

    

    map<lli,lli>mp;
    while(n>1)
    {
        mp[d[n]]++;
        n=n/d[n];
    }
   

    

}
lli gcd (lli a, lli b) {
    return b ? gcd (b, a % b) : a;
}
lli lcm (lli a,lli b) {
    return a / gcd(a, b) * b;
}
lli countsetbits(lli n)
{
    lli count=0;
    while(n)
    {
        count++;
        n=n&(n-1);
    }
    return count;
}
long double nCr(long double n,long double r)
{
    double res=1.00;
    for(long double i=1;i<=r;i++)
    {
        res=res*((n-r+i)/(i*(1.0)));
    }
    return res;
}
pair<lli,lli> fib (lli n) {
    if (n == 0)
        return {0ll, 1ll};
                                                             

    auto p = fib(n >> 1ll);
    lli c = ((p.first)*((2 * (p.second)) - (p.first)));
    c=c;
    lli d =((((p.first) * (p.first))) + ((p.second) * (p.second)));
    d=d;
    lli x=(c+d);
    if (n%2!=0)
        return {d,x};
    else
        return {c, d};
}
lli isvalid(lli x,lli y)
{
    lli p=(y*(y+1))/2;
    lli q=(x*(x+1))/2;
    p-=q;
    return p;
    
}
int main()
{
 toh_shuru_karte_hai_bina_kise_bakchodi_ke;




test{
    lli a,b;
    cin>>a>>b;
    

    

    

    

    

    

    

    

    lli p=1+8*b;
    p=ceil(sqrt(p));
    p=-1+p;
    p=ceil(p/2.0);
    

    

    

    if(p<=a)
    cout<<p<<endl;
    else
    {
        lli o=(a*(a+1))/2;
        b-=o;
        

        lli l=0,r=a-1,x=a-1;
        lli ans=LLONG_MAX;
        while(l<=r)
        {
            lli mid=(l+r)/2;
            

            
            if(isvalid(mid,x)>=b)
            {
                lli u=a-1-mid;
                ans=min(ans,u);
                l=mid+1;
            }
            else
            r=mid-1;
        }
        if(ans==LLONG_MAX)
        {
            ans=2*a-1;
        }
        else
        ans+=a;
        

        lli h=2*a-1;
        ans=min(ans,h);
        cout<<ans<<endl;
    }
}
}