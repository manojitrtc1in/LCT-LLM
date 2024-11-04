

using namespace std;
typedef long long int ll;







using namespace __gnu_pbds;
fstream inp("input.txt",ios::in);
fstream out("output.txt",ios::out);


ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll id1(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, id1(b, m), m) + m) % m;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
template<class T> using orderedset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
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
void id0(vector<ll>&ans)
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
void id4()
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
void id6(ll x,map<ll,ll>&ret)
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
void id2(ll n)
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
ll id3(ll A, ll B, ll M)
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










ll id5(string str)
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



 


ll nd[200005];


vector<vector<ll>>adj;


ll ans=0;
void dfs(ll u,ll p,ll l[],ll r[],ll n)
{
  

  ll sm=0;
  for(auto it:adj[u])
  {
    if(it==p)
        continue;
    dfs(it,u,l,r,n);
    sm+=nd[it];
  }
  if(sm<l[u-1])
  {
     

    ans++;
    nd[u]=r[u-1];
  }
  else if(sm<r[u-1])
  {
    nd[u]=sm;
  }
  else
  {
    nd[u]=r[u-1];
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
      adj.clear();
      adj.resize(n+1);
      ll p[n+1];
      for(int i=2;i<=n;i++)
      {
        cin>>p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
      }
      ll l[n];
      ll r[n];
      for(int i=0;i<n;i++)
      {
        cin>>l[i]>>r[i];
      }
      for(int i=0;i<=n;i++)
      {
       

        nd[i]=0;
      

      }
      ans=0;
      dfs(1,-1,l,r,n);

      cout<<ans<<"\n";
    }
  }
