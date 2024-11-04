#include <bits/stdc++.h> 
#include <math.h>
#include<stdint.h>
#include<cstdint>
#include <algorithm>
using namespace std;


#define GODSPEED ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define TEST int t; cin>>t; for(int i = 0;i<t;i++)  
#define NoTEST int t = 1; while(t--)
#define inp(v) for (int i = 0; i < n; ++i) {cin>>tp;v.push_back(tp);}
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define popb pop_back
#define forn(i, x, n) for (ll i = x; i < n; i++)
#define fornb(i, n, x) for (ll i = n; i >=x; i--)
#define endl "\n" 
#define unt uint32_t
#define bins(x , y , z) binary_search(x , y , z)
const int  MAX = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;






int remove0(int n);
int ispalin(string S);




int findd(std::vector<int> v , int  n , int x);




int FindPairSum(std::vector<int> A, int N, int SUM)
{
    int i = 0;int j = N - 1;
    while (i < j) {if (A[i] + A[j] == SUM)      return 1;
                   else if (A[i] + A[j] < SUM)  i++;
                   else                         j--;
                  }
                   return 0;                    
}




int vecsum(std::vector<int> v , int n)
{
    int sum = 0;
    forn(i,0,n)
    {
        sum+=v[i];
    }
    return sum;
}




vector<int> tpixsum(std::vector<int> v , int n)
{
    std::vector<int> r;
    r[0]=v[0];
    for (int i = 1; i < n; ++i)
    {
        
        r[i]=r[i-1]+v[i];
    }
    return r;
}




ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}




long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


ll isSorted(vector<ll> A)
{

    ll n = A.size();
    forn(i, 0, n - 1)
    {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}


long long int printPair(std::vector<ll> arr, ll n, ll sum) 
{ 
    ll cnt = 0; 

  
    

    

    bool *visited=new bool[n]();
    for (ll i = 0; i < n; i++){ 
         if(visited[i]) continue;
        for (ll j = i + 1; j < n; j++){ 
               if(visited[j]) continue;
            if (arr[i] + arr[j] == sum){
                   cnt++;
                   visited[j]=true;
                   break;
                } 
         }     
   }       
 
     return cnt;           
} 


set<long long> prim(int n)
{
    n++;
    bool *arr=new bool[n];
    for(int i=0;i<n;i++)
        arr[i]=true;
    set<long long> se;
    for(int i=2;i*i<n;i++)
        if(arr[i])
            for(int k=i*i;k<n;k+=i)
                arr[k]=false;
    for(int i=2;i<n;i++)
        if(arr[i])
            se.insert(i);
    return se;
}


bool check_eqvec(std::vector<int> arr, int n)
{   
    bool flag = false;

    for(int i = 0; i < n - 1; i++)      
    {         
        if(arr[i] != arr[i + 1])
            flag = true;
    }

    return flag;
}


void remove(std::vector<ll> v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    v.erase(end, v.end());
}




set<int64_t> printDivisors(int64_t n)
{
    

    set<int64_t> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
 
            

            if (n / i == i)
            {
                

                v.insert(i);
            }
            else
            {
                

                v.insert(i);
                

                v.insert(n / i);
            }
        }
    }
    return v;
    

    

    

}





struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};




 
   int cntdig(int n)
   {
    int cnt = 0 ;

    while(n!=0)
    {
        n/=10;
        cnt++;
    }

    return cnt;
   }



bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}


int Search(int arr[], int l, int r, int x)
{
    if (r >= l) 
    {
       int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return Search(arr, l, mid - 1, x);
        return Search(arr, mid + 1, r, x);
    }
    return -1;
}


ll sum_nat(int n)
{
    return n * 1ll * (n + 1) / 2;
}


bool check_sqr(long double x)
{
    if(x>=0)
    {
    ll sr = sqrt(x);
    return(sr*sr==x);
    }
    return false;

}


bool check_even(int n)
{
    if(n & 1)
        return 0;
    else 
        return 1;
}


int count1bits(uint32_t n) 
{                               

   return bitset < 32 > (n).count();
}


double getroot(int n , int m )
{
    
    return pow(m , (double)(1.0/(double)n));

}


 int factorial( int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}








void solve()
{
































    








    

    


    


    


    

    

    

    

    

    


    


    

    


    


    


    

    

    

    

    


    


    



    

    


    


    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    



    


    








  









   



   

   

   

  






    

    ll n;
    cin>>n;
    

    std::vector<ll> v(n);

    for(auto &it : v)
        cin>>it;

    int cnt = 0;
    for(int i = 0;i<n;i++)
        for(int j = n-1;j>i;j--)
            if(v[i]>=v[j])
                ++cnt;


cout<<cnt<<endl;





} 


int main()
{
    GODSPEED
    TEST
    solve();
}
