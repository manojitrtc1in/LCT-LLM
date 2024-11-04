
#include<bits/stdc++.h>
#define abdo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define tc ll t ; cin>>t; while(t--)
#define pb push_back
#define pob pop_back
#define loopj(j,a,b) for(ll j = a ; j < b-1 ; j++)
#define loopi(i,a,b) for (ll i = a; i < b; i++)
#define vl vector<ll>
#define vi vector<int>
#define lb lower_bound
#define ub upper_bound
#define sumv(v) accumalate(v.begin(),v.end(),0)
#define mii map<int,int>
#define umii unordered_map<int,int>
#define order(v) sort(v.begin(),v.end())
#define ed '\n'
#define el "\n"
#define all(v) v.begin(),v.end()
#define YES cout<<"YES"<<ed;
#define NO cout<<"NO"<<ed;
#define Yes cout<<"Yes"<<ed;
#define No cout<<"No"<<ed;
#define yEs cout<<"yEs"<<ed;
#define yeS cout<<"yeS"<<ed;
#define nO cout<<"nO"<<ed;
#define yes cout<<"yes"<<ed;
#define no cout<<"no"<<ed;
#define ans1 ll ans = 0;
#define cnt1 ll cnt = 0;
#define sum(a , b) (a + b)
#define product(a , b) (a * b)
#define squarear(a) (a * a)
#define rectanglear(a , b) (a * b)
#define squarepre(a) (a * 4)
#define rectanglpr(a , b) ((a + b)*2)
typedef unsigned long long ull;
typedef long double lld;
using namespace std;
const int N = 1e7;
ll frq[N];
vector<bool> seive(1e6 + 1, true);
const int maxn = 1e5;
bool isprime[maxn];
const int mod = 998244353;
ll fact[N];


void code()
{
    abdo;
}

int primeFactors(int n)
{
    int c=0;
    while (n % 2 == 0)
    {
        c++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            c++;
            n = n/i;
        }
    }
    if (n > 2)
    {
        c++;
    }
    return c;
}
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
 
    }
    return gcd(b, a % b);
}
void extendgcd(ll a, ll b, ll*v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return ;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;

}
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
bool isPalindrome(string s)
 
{
 
    int n=s.length();
 
    for(int i=0; i<n/2; i++)
 
    {
 
        if(s[i] != s[n-i-1])
 
            return false;
 
    }
 
    return true;
 
}
void palindrome(int n)
{
    int rev=0,val;
    val = n;
    while(n > 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    if(val==rev)
        cout<<val<<" is a palindrome"<<endl;
    else
        cout<<val<<" is not a palindrome"<<endl;
}
 
bool plin(int index)
{
    ll arr[N];
    int n;
    if(index == n)
    {
        return 1;
    }
    return (arr[index] == arr[n - index -1]) && plin(index + 1);
 
}
 
bool isPrime()
{
    int n;
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
bool isEven()
{
    int n;
    return (n % 2 == 0);
}
void check_X0r(ll a, ll b)
{
    cout<<"a = " << a <<","<< " b = " << b <<endl;
    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "~a = " << (~a) << endl;
    cout<<"b << 1" <<" = "<< (b << 1) <<endl;
    cout<<"b >> 1 "<<"= " << (b >> 1 )<<endl;
 
}
int findSumstr(string str)
{
    string temp = "";
    int sum = 0;
    for (char ch : str)
    {
        if (isdigit(ch))
            temp += ch;
        else
        {
            sum += atoi(temp.c_str());
            temp = "";
        }
    }
    return sum + atoi(temp.c_str());
}
void sieve()
{
    for(int i=2; i<maxn; i++) isprime[i]=1;
    for(int i=2; i*i<maxn; i++) if(isprime[i])
        {
            for(int j=i*i; j<maxn; j+=i) isprime[j]=0;
        }
}
ll exp(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a);
        a=(a*a);
        b>>=1;
    }
    return res;
}
ll modexp(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
ll sqt(ll x)
{
    ll start =1;
    ll end = x;
    while (end>start)
    {
        end = start+(end-start)/2;
        start = x/end;
    }
    return end;
}
ll inv(ll a)
{
    return modexp(a, mod-2);
}
ll C(ll n, ll r)
{
    ll nume = fact[n];
    ll deno = (inv(fact[n-r]) * inv(fact[r])) % mod;
    return (nume * deno) % mod;
}




  int arr[N],ans[50];
void solve( ll n , string st )
{
bool  correct = 1;
      for(int i=0; i<n;i++)
      {
        if(ans[arr[i]-1]==-1)
        {
          ans[arr[i]-1]=st[i]-'a';
        }
        else
        {
            
          if(ans[arr[i]-1]!=st[i]-'a')
          {
             correct=0;
            break;
          }
        }
      }
      if(correct==1)
      {
          YES 
      }
     
      else 
      {
      No
      }
}
void testCases()
{
    

    

}
void quary(ll q , ll ans, ll iseven , ll isodd)
{
         while(q--){
        int num , evenorodd;
        cin >>num >> evenorodd;
        if(num == 0)
        {
          ans+=evenorodd * iseven;
          if(evenorodd % 2 != 0)
            {
                isodd+=iseven;
                iseven=0;
            }
        }
        if(num==1)
        {
          ans += evenorodd * isodd;
          if(evenorodd % 2 != 0){
            iseven += isodd;
            isodd=0;
              
          } 
}
cout<<ans<<endl;
}
}
int main()
{
  code();
 
   tc
{
      int n;
      cin>>n;
      int arr[N],ans[50];
      for(int i=0; i<n; i++)
      {
          cin>>arr[i];
      }
      for(int i=0; i<50; i++)
      {
          ans[i]=-1;
          
      }
      string st;
      cin>>st;
      bool correct = 1;
      for(int i=0; i<n;i++)
      {
          
        if(ans[arr[i]-1]==-1)
        {
          ans[arr[i]-1]=st[i]-'a';
        }
        else
        {
          if(ans[arr[i]-1]!=st[i]-'a')
          {
            correct=0;
            break;
          }
        }
      }
         if(correct==1)
      {
          YES 
      }
     
      else 
      {
      No
      }
      
}
}
