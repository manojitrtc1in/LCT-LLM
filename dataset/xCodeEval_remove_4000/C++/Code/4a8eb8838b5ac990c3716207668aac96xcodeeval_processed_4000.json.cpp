




































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
int id4(int a[], int size)
{
    int id3 = INT_MIN, id5 = 0;
 
    for (int i = 0; i < size; i++)
    {
        id5 = id5 + a[i];
        if (id3 < id5)
            id3 = id5;
 
        if (id5 < 0)
            id5 = 0;
    }
    return id3;
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
void id2(ll a, ll b, ll*v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return ;
    }
    id2(b, a % b, v);
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
void id1(ll a, ll b)
{
    cout<<"a = " << a <<","<< " b = " << b <<endl;
    cout << "a & b = " << (a & b) << endl;
    cout << "a | b = " << (a | b) << endl;
    cout << "a ^ b = " << (a ^ b) << endl;
    cout << "~a = " << (~a) << endl;
    cout<<"b << 1" <<" = "<< (b << 1) <<endl;
    cout<<"b >> 1 "<<"= " << (b >> 1 )<<endl;
 
}
int id0(string str)
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
        int num , id6;
        cin >>num >> id6;
        if(num == 0)
        {
          ans+=id6 * iseven;
          if(id6 % 2 != 0)
            {
                isodd+=iseven;
                iseven=0;
            }
        }
        if(num==1)
        {
          ans += id6 * isodd;
          if(id6 % 2 != 0){
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
