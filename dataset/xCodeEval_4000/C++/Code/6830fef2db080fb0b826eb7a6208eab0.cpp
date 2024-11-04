#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


#define modulo 1000000007
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
void smallestprime()
{
 for(int i=0;i<100005;i++)
 {
    spf[i]=i;
 }
 for(int i=2;i<100005;i++)
 {
    if((i%2)==0)
    spf[i]=2;
 }
 for(int i=3;i*i<100005;i+=2)
 {
   if(spf[i]==i)
   {
    for(int j=i*i;j<100005;j+=i)
    {
     if(spf[j]=j)
        spf[j]=i;
    }
   }
 }
}
void getFactorization(ll x,map<ll,ll>&ret)
{
    

    while (x != 1)
    {
        ret[spf[x]]++;
        x = x / spf[x];
    }
    if(x==1)
        ret[1]++;
    

}
int con(string s)
{
 int num=0;
 for(int i=0;i<s.length();i++)
 {
    num=num*10+(s[i]-'0');
 }
 return num;
}
void findSmallestNumber(ll n)
{

    

    ll no=ceil((1.0*n)/2520);
    no=no*2520;
    for (ll i = n; i <= no; ++i) {

        bool possible = 1;

        

        

        ll temp = i;
        while (temp) {
            if (temp % 10 != 0) {
                int digit = temp % 10;
                if (i % digit != 0) {
                    possible = 0;
                    break;
                }
            }
            temp /= 10;
        }

        if (possible == 1) {
            cout << i;
            return;
        }
    }
}
ll countDivisibles(ll A, ll B, ll M)
{

    

    if (A % M == 0)
        return (B / M) - (A / M) + 1;

    

    return (B / M) - (A / M);
}
ll fin(ll r,ll lcm,ll b)
{
 ll div=r/lcm;
 ll pro=div*lcm;
 ll tot=r;
 if(div!=0)
 {
    tot=tot-(div-1)*b;
    tot=tot-min(b,r-pro+1);
 }
 return tot-min(r,b-1);
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






vector<vector<ll>>adj;
ll lca[200005][30];
ll lvl[200005];
ll par[200005];
ll parity[200005];
void dfs(ll u,ll p,ll dis,ll p2)
{
 lca[u][0]=p;
 lvl[u]=dis;
 par[u]=p;
 parity[u]=p2;
 for(auto it:adj[u])
 {
    if(it!=p)
    {
     dfs(it,u,dis+1,p2+1);
    }
 }
}
ll callca(ll a,ll b)
{
    if(lvl[a]>lvl[b])
        swap(a,b);
    ll d=abs(lvl[b]-lvl[a]);
    

    

    while(d>0)
    {
     ll i=log2(d);
    

     b=lca[b][i];
   

     d=d-(1<<i);
    }

   

   

   

   

   

    if(a==b)
        return b;
       

    for(int i=29;i>=0;i--)
    {
     if(lca[a][i]!=-1&&(lca[b][i]!=lca[a][i]))
     {
        b=lca[b][i];
        a=lca[a][i];
     }
    }
  

    return par[b];
}
int main()
{
    fast
    ll t;
    t=1;
    int t1=0;
    while(t--)
    {
      ll n;
      cin>>n;
      adj.resize(n+1);
      for(int i=1;i<=(n-1);i++)
      {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      for(int i=0;i<200005;i++)
      {
          lvl[i]=0;
          par[i]=0;
          parity[i]=0;
      }
      for(int i=0;i<200005;i++)
      {
        for(int j=0;j<30;j++)
        {
            lca[i][j]=-1;
        }
      }
      dfs(1,-1,0,0);
      for(int j=1;j<30;j++)
      {
        for(int i=0;i<=n;i++)
        {
         if(lca[i][j-1]!=-1)
         {
            lca[i][j]=lca[lca[i][j-1]][j-1];
         }
        }
      }
      ll q;
      cin>>q;
      while(q--)
      {
        ll sz;
        cin>>sz;
        

       

        vector<ll>v;
        for(int i=0;i<sz;i++)
        {
         ll x;
         cin>>x;
         v.push_back(x);
         

        }
        ll left=-1;
        ll lftnd=0;
        for(int i=0;i<sz;i++)
        {
         if(lvl[v[i]]>left)
         {
            left=lvl[v[i]];
            lftnd=v[i];
         }
        }
        ll rghtnd=-1;
        ll right=-1;
        for(int i=0;i<sz;i++)
        {
           

             


         if(callca(lftnd,v[i])!=v[i])
         {
             if(lvl[v[i]]>right)
              {
                  right=lvl[v[i]];
                  rghtnd=v[i];
              }
           

         }
        }
        if(rghtnd==-1)
        {
         cout<<"Yes"<<"\n";
         continue;
        }
       

        ll flag=1;
        for(int i=0;i<v.size();i++)
        {

           

             


        

        

         ll l1=callca(lftnd,v[i]);
         ll l2=callca(v[i],rghtnd);
         ll l3=callca(lftnd,rghtnd);
        

         

         ll dis=lvl[lftnd]+lvl[v[i]]-2*lvl[l1];
         ll dis1=lvl[rghtnd]+lvl[v[i]]-2*lvl[l2];
         ll dis3=lvl[lftnd]+lvl[rghtnd]-2*lvl[l3];
         if(dis+dis1!=dis3)
         {
            flag=0;
            break;
         }
            

        }
        if(flag)
            cout<<"Yes"<<"\n";
        else
            cout<<"No"<<"\n";



      }

    }
}
