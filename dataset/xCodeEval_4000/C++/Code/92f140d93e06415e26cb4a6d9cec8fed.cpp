



























































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
#define print(v) for(auto x:v)cout<<x<<" "
#define prints for(lli i=0;s[i];i++)cout<<s[i]








using namespace std;



























#define INT_BITS 16





































unsigned lli leftRotate(unsigned lli n, unsigned lli d) 
{ 
    return (n << d)|(n >> (INT_BITS - d)); 
} 
unsigned lli rightRotate(unsigned lli n,unsigned lli d) 
{ 
    return (n >> d)|(n << (INT_BITS - d)); 
} 







int log2(int x)
{
  int res=0;
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
bool isPowerOfTwo(int n) 
{ 
   if(n==0) 
   return false; 
  
   return (ceil(log2(n)) == floor(log2(n))); 
} 
lli inverse(lli a,lli m)
{
    return 1<a?m-inverse(m%a,a)*(m/a):1;    

}
lli issorted(lli arr[], lli n) 

{ 
 if (n == 1 || n == 0) 
        
return 1; 
  
 
if(arr[n - 1] < arr[n - 2]) 
       
return 0; 
  


return issorted(arr, n - 1); 

} 

int computeXOR(int n)
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

lli count(string s)

{
    lli ans=1,i,j;
    for(i=1;i<s.length();i++)
    {
        for(j=0;j<i;j++)
        {
            if(s[i]==s[j])
            break;
        }
        if(i==j)
        ans++;
    }
    return ans;
}

bool isPerfectSquare(long double x) 

{   
  

  


  
long double sr = sqrt(x); 
  
  


  
return ((sr - floor(sr)) == 0); 

} 

lli countarray(lli a[],lli n)

{
  unordered_set<lli>s;
for(lli i=0;i<n;i++)
s.insert(a[i]);
return s.size();
}



bool check (int N)          

    {  lli i;
        if( N & (1 << i) )
            return true;
        else
            return false;
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



struct interval

{
    int start,end;
   
 
};
                                             

bool compare(interval x,interval y)

{
    return (x.start<y.start);
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

int seive(int n)  

{
   
bool isprime[n+1];
    
for(int i=2;i<=n;i++)
    
isprime[i]=true;
    
isprime[0]=false;
    
isprime[1]=false;
    
for(int i=2;i<=sqrt(n);i++)
    
{   
if(isprime[i]==true)
       
{
           
for(int j=i*i;j<=n;j+=i)
        
{
           
isprime[j]=false;
               
}

}
      
    
}
    
int count=0;
    
for(int i=0;i<=n;i++)
    
{
        
if(isprime[i]==true)
        
count++;
    
}
    
return count;

}



void multiply(int a[2][2],int m[2][2])

{                                                 

int him[2][2];
                                    

for(int i=0;i<2;i++)
                              

{   
                                              

for(int j=0;j<2;j++)
        
{   him[i][j]=0;
            
for(int k=0;k<2;k++)
            
{
                
him[i][j]+=(a[i][k]*m[k][j]);
            
}
            
        
}
    
}
    
for(int i=0;i<2;i++)
    
{
        for(int j=0;j<2;j++)
        
{
            a[i][j]=him[i][j];
        
}
    
}
}
void power(int a[2][2],int n)

{   if(n==0||n==1)
    
return;
    
power(a,n/2);
    
multiply(a,a);
    
if(n%2!=0)
    
{  
int m[2][2]={{1,1},{1,0}};
        
multiply(a,m);
    
}

}
int fib(int n)

{
    
int a[2][2]={{1,1},{1,0}};
    
if(n==0)
    
return 0;
    
power(a,n-1);
    
return a[0][0];

}



int factmod(int n, int p)   

{
    
int res = 1;
    
while (n > 1) 
{
        
res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        
for (int i = 2; i <=(n%p);i++)
            
res = (res * i) % p;
        
n /= p;
    
}
    
return res % p;

}







lli modularexponentiation(lli a,lli n) 
{ 
    lli res = 1;      
   
    while (n > 0) 
    { 
        if (n& 1) 
            res = ((res%mod)*(a%mod))%mod; 
        n/=2; 
        a=((a%mod)*(a%mod))%mod;
    } 
    return res; 
}



lli largest_power(lli N)
    {                                              

        

        N = N| (N>>1);
        N = N| (N>>2);
        N = N| (N>>4);
        N = N| (N>>8);
        N = N| (N>>16);  

    

                return (N+1)>>1;

    }

bool alternate(lli n)
{
    lli i;
    if((n^(n>>1))==(pow(2,i)-1))           

    return true;                             

return false;
}

    lli countDivisors(lli n) 
{ 
    lli cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            

            

            if (n / i == i) 
                cnt++; 
  
            else 

                cnt = cnt + 2; 
        } 
    } 
    return cnt;
}


int highestpowerof2(int n)   

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
void pairsort(int a[], char b[], int n)     

{ 
    pair<int, char> pairt[n]; 
  
    

    

    for (int i = 0; i < n; i++)  
    { 
        pairt[i].first = a[i]; 
        pairt[i].second = b[i]; 
    } 
  
    

    sort(pairt, pairt + n); 
      
    

    for (int i = 0; i < n; i++)  
    { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
    } 
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
void rev(int a[],int n)
{
        for(lli i=0,j=n-1;i<j;i++,j--)
        {
            swap(a[i],a[j]);
        }
        loop0(i,n)
        cout<<a[i]<<" ";
}

int main()
{
   toh_shuru_karte_hai_bina_kise_bakchodi_ke;






    lli n,m;
    cin>>n>>m;
    char a[n][m];
    loop0(i,n)
    {
        loop0(j,m)
        cin>>a[i][j];
    }
    loop0(i,n)
    {
        loop0(j,m)
        {
            lli count=0;
            loop0(l,n)
            {
                if(l!=i)
                {
                    if(a[l][j]==a[i][j])
                    count++;
                }
                
            }
            loop0(l,m)
            {
                if(l!=j)
                {
                    if(a[i][l]==a[i][j])
                    count++;
                }
            }
            if(count==0)
        cout<<a[i][j];
        }
        
    }



}