#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


#define modulo 998244353
#define PI 3.141592653589793238462643
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
fstream inp("input.txt",ios::in);
fstream out("output.txt",ios::out);


ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
template<class T> using orderedset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
ll bpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool prime[100005];
ll spf[100005];
void SieveOfEratosthenes(vector<ll>&ans)
{
    

    

    

    

    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=100005; p++)
    {
        

        if (prime[p] == true)
        {
            

            for (int i=p*2; i<=100005; i += p)
                prime[i] = false;
        }
    }

    

    int cnt=0;
    for (int p = 2; p <= 100005; p++)
        if (prime[p])
            {
              

                cnt++;
            }
   

}











ll stringTointeger(string str)
{
    ll temp = 0;
    for (ll i = 0; i < str.length(); i++) {


        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}


 long long getcount(long long n, int k)
{
    

    

    long long res = (n >> (k + 1)) << k;
    

    

    if ((n >> k) & 1)

        

        

        res += n & ((1ll << k) - 1);

    

    return res;
}


 bool comp(pair<ll,ll>&a,pair<ll,ll>&b)
 {
  if(a.first==b.first)
    return a.second>b.second;
  else
    return a.first>b.first;
 }
ll fact[200005];
ll ifact[200005];
void factorial()
{
 for(int i=0;i<200005;i++)
 {
    fact[i]=0;
    ifact[i]=0;
 }
 fact[0]=1;
 ifact[0]=1;
 for(int i=1;i<200005;i++)
 {
    fact[i]=((fact[i-1])*i)%modulo;
    ifact[i]=(expo(fact[i],modulo-2,modulo))%modulo;
 }
}

ll seg[200005];
void construct(ll seg[],ll st,ll en,ll ind,ll arr[])
{
  if(st==en)
  {
      seg[ind]=arr[st];
      

      return;
  }
  ll mid=st+(en-st)/2;
  construct(seg,st,mid,2*ind+1,arr);
  construct(seg,mid+1,en,2*ind+2,arr);
  seg[ind]=seg[2*ind+1]+seg[2*ind+2];
 

  

}


ll querysum(ll seg[],ll st,ll en,ll ss,ll ee,ll ind,ll arr[])
{
 if(en<ss||st>ee)
    return 0;
 if(st>=ss&&en<=ee)
    return seg[ind];
 ll mid=st+(en-st)/2;
 return (querysum(seg,st,mid,ss,ee,2*ind+1,arr)+
        querysum(seg,mid+1,en,ss,ee,2*ind+2,arr));
}
void update(ll seg[],ll st,ll en,ll ind,ll cind,ll diff,ll arr[])
{
  if(cind>en||cind<st)
    return;
  seg[ind]+=diff;
  ll mid=st+(en-st)/2;
  if(st!=en)
  {
   update(seg,st,mid,2*ind+1,cind,diff,arr);
   update(seg,mid+1,en,2*ind+2,cind,diff,arr);
   seg[ind]+=seg[2*ind+1]+seg[2*ind+2];
  }
}





ll finper(string &temp2)
{
  string temp3=temp2;
  char f=temp2[0];
  string nw=temp2.substr(1);
  nw+=f;
  ll cnt=1;
  while(nw!=temp2)
  {
   f=nw[0];
   nw=nw.substr(1);
   nw+=f;
   cnt++;
  }
  return cnt;
}


ll sub[300005];










struct Node
{
 char op;
 ll val;
};
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
ll cal(ll cost,ll dir,Node arr[])
{
   if(arr[dir].op=='+')
   {
       

     return cost+arr[dir].val;
   }
   else if(arr[dir].op=='-')
   {
     return cost-arr[dir].val;
   }
   else if(arr[dir].op=='*')
    return cost*arr[dir].val;
   else
   {
       if(cost<0)
       {
         return (-1)*ceil(abs(cost)/(arr[dir].val*1.0));
       }
       else
        return (cost/(arr[dir].val));
   }
}
int main()
{
    fast
    ll t;
    cin>>t;
   

    while(t--)
    {
      ll n;
      cin>>n;
      vector<ll>ans;
      for(int i=0;i<n;i++)
      {
          ans.push_back(0);
      }
      if(n==3)
      {
          cout<<"2 1 3"<<"\n";
          continue;
      }
      if(n==6)
      {
          cout<<"4 1 2 12 3 8"<<"\n";
          continue;
      }
      if(n%2)
      {
        ll div=n/2;
        if(div%2==0)
        {
         ll st=4;
         for(int i=1;i<n;i+=2)
         {
            ans[i]=st;
            st+=2;
         }
         ans[0]=0;
         st=1;
         for(int i=2;i<n;i+=2)
         {
          ans[i]=st;
          st+=2;
         }
        }
        else
        {
         ll rem=n-div;
         

         ans[1]=2;
         

           

         ll st=4;
         for(int i=3;i<n;i+=2)
         {
            ans[i]=st;
            st+=2;
         }
         st=1;
         for(int i=0;i<n;i+=2)
         {
           ans[i]=st;
           st+=2;
         }
        }
      }
      else
      {
        if((n/2)%2==0)
        {ll st=0;
        for(int i=0;i<n;i+=2)
        {
          ans[i]=st;
          st+=2;
        }
        st=1;
        for(int i=1;i<n;i+=2)
        {
         ans[i]=st;
         st+=2;
        }
        }
        else
        {
          ans[0]=4;
          ans[1]=1;
          ans[2]=2;
          ans[3]=12;
          ans[4]=3;
          ans[5]=8;
          ll st=5;
          for(int i=6;i<n;i+=2)
          {
            ans[i]=st;
            st+=2;
          }
          st=16;
          for(int i=7;i<n;i+=2)
          {
              ans[i]=st;
              st+=2;
          }
        }
      }
      for(int i=0;i<n;i++)
      {
        cout<<ans[i]<<" ";
      }
      cout<<"\n";

    }
}
