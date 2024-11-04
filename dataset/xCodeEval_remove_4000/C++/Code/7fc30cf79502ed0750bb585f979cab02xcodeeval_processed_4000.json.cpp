














using namespace std;





































typedef pair<ll,ll> pii;
typedef vector<pii> vii;

inline ll maxim(ll a,ll b) {if(a>b) return a; else return b;}
inline ll minim(ll a,ll b) {if(a<b) return a; else return b;}
inline bool equals(double a, double b){ return fabs(a - b) < 1e-9; }
ll gcd(ll a, ll b) { return b==0 ? a : gcd(b, a%b); }

ll reduce(ll a,ll m)
{
  a%=m;
  a+=m;
  a%=m;
  return a;
}

ll sum(ll* arr,ll n)
{
  ll total=0;
  fr(o,1,n)
  {
    total+=arr[o];
  }
  return total;
}

ll id2(ll a,ll b,ll& x,ll& y)
{
  if(a==0)
  {
    x=0;
    y=1;
    return b;
  }
  else
  {
    ll x1,y1;
    ll g=id2(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
  }
}

bool leap(ll y)
{
  if(y%400==0) return true;
  if((y%4==0)&&(y%100!=0)) return true;
  return false;
}

ll isprime(ll n)
{
  if(n==1) return false;
  if(n==2) return true;
  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0) return false;
  }
  return true;
}


bool prime[2000010];
void id0()
{
    memset(prime, true, sizeof(prime));
    prime[1]=false;
    for (int p=2; p*p<=2000001; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=2000001; i += p)
                prime[i] = false;
        }
    }
}







































ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
















































































ll ultimate[3][3];

void matrix_exp(ll arr[3][3],ll n)
{
  ll len=3;
  ll res[3][3]={{1,0,0},{0,1,0},{0,0,1}};
  ll temp[3][3];

  while(n)
  {
    if(n&1)
    {
      rep(x,len)
      {
        rep(y,len)
        {
          temp[x][y]=0;
        }
      }

      fr(i,0,len-1)
      {
        fr(j,0,len-1)
        {
          fr(z,0,len-1)
          {
            temp[i][j]+=reduce(res[i][z]*arr[z][j],mod-1);
          }
        }
      }

      fr(i,0,len-1)
      {
        fr(j,0,len-1)
        {
          res[i][j]=reduce(temp[i][j],mod-1);
        }
      }
    }

    rep(x,len)
    {
      rep(y,len)
      {
        temp[x][y]=0;
      }
    }

    fr(i,0,len-1)
    {
      fr(j,0,len-1)
      {
        fr(z,0,len-1)
        {
          temp[i][j]+=reduce(arr[i][z]*arr[z][j],mod-1);
          temp[i][j]%=mod-1;
        }
      }
    }

    fr(i,0,len-1)
    {
      fr(j,0,len-1)
      {
        arr[i][j]=reduce(temp[i][j],mod-1);
      }
    }

    n/=2;
  }

  fr(i,0,len-1)
  {
    fr(j,0,len-1)
    {
      ultimate[i][j]=reduce(res[i][j],mod);
    }
  }
}


ll modpow(ll a, ll b,ll x)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a)%x;
        a = (a * a)%x;
        b >>= 1;
    }
    return res;
}




int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        

        int q = a / m;
        int t = m;
        

        

        m = a % m, a = t;
        t = y;
        

        y = x - q * y;
        x = t;
    }
    

    if (x < 0)
       x += m0;
    return x;
}

ll id4(ll h)
{
  ll g=(ll)sqrt(h);
  g++;
  if(g*g==h) return g;
  g--;
  if(g*g==h) return g;
  g--;
  if(g*g==h) return g;
  return -1;
}


ll lpf[1000001] = {};

void precompute()
{
  fr(i,2,1000000)
  {
    if(!lpf[i])
    {
      for(ll j=i;j<=1000000;j+=i)
      {
        if(!lpf[j])
        lpf[j]=i;
      }
    }
  }
}






































ll f(ll x)
{
  ll total=0;
  return total;
}

ll id3(ll l, ll r)
{              

    while (r - l > 10)
    {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = f(m1);      

        ll f2 = f(m2);      

        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    ll mino=f(l);
    ll mino_x=l;

    fr(o,l,r)
    {
      if(f(o)<mino)
      {
        mino_x=o;
        mino=f(o);
      }
    }
    return mino_x;
}

ll func(ll x)
{
  return (x*(x+1))/2;
}

ll bs(ll low,ll high,ll target)
{
  while(low+2<high)
  {
    ll mid=(low+high)/2;
    

    if(func(mid)<target)
    {
      low=mid; 

    }
    else if(func(mid)>=target)
    {
      high=mid-1; 

    }
  }

  frr(o,high,low)
  {
    if(func(o)<target) return o;
  }

  return -1;
}





































































































ll lpfx(ll x)
{
  if(x%2==0) return 2;
  else
  {
    for(int z=3;z*z<=x;z+=2)
    {
      if(x%z==0) return z;
    }
  }
  return x;
}



ll arr[1000010]={0};
vector<ll> id1;
map<ll,ll> mf1;
map<ll,ll> mf2;
map<ll,ll> mf3;
map<ll,ll> overall;



int main()
{
  fast;

  
  

  freopen("input.txt", "r", stdin);
  

  freopen("output.txt", "w", stdout);
	

  cout<<setprecision(10)<<fixed;
  precompute();
  c(n);
  c(f1);
  c(f2);
  c(f3);
  c(c_);

  ll c=c_;

  if(isprime(c_))
  {
    if(overall.find(c_)==overall.end())
    {
      overall[c_]=1;
      id1.pb(c_);
    }
    mf1[c_]+=1;
    mf2[c_]+=2;
    mf3[c_]+=3;
  }
  else if(c_==1)
  {
    

  }
  else
  {
    while(c_!=1)
    {
      ll x;
      if(c_<1000000)
      {
        x=lpf[c_];
      }
      else
      {
        x=lpfx(c_);
      }
      if(overall.find(x)==overall.end())
      {
        overall[x]=1;
        id1.pb(x);
      }
      ll freq=0;
      while(c_%x==0)
      {
        freq++;
        c_/=x;
      }
      mf1[x]+=freq;
      mf2[x]+=2*freq;
      mf3[x]+=3*freq;
    }
  }


  

  

  

  

  





  ll tempero=f1;
  if(isprime(tempero))
  {
    if(overall.find(tempero)==overall.end())
    {
      overall[tempero]=1;
      id1.pb(tempero);
    }
    mf1[tempero]+=1;
  }
  else if(tempero==1)
  {
    

  }
  else
  {
    while(tempero!=1)
    {
      ll x;
      if(tempero<1000000)
      {
        x=lpf[tempero];
      }
      else
      {
        x=lpfx(tempero);
      }

      if(overall.find(x)==overall.end())
      {
        overall[x]=1;
        id1.pb(x);
      }
      ll freq=0;
      while(tempero%x==0)
      {
        freq++;
        tempero/=x;
      }
      mf1[x]+=freq;
    }
  }

  

  

  

  

  



  tempero=f2;
  if(isprime(tempero))
  {
    if(overall.find(tempero)==overall.end())
    {
      overall[tempero]=1;
      id1.pb(tempero);
    }
    mf2[tempero]+=1;
  }
  else if(tempero==1)
  {
    

  }
  else
  {
    while(tempero!=1)
    {
      ll x;
      if(tempero<1000000)
      {
        x=lpf[tempero];
      }
      else
      {
        x=lpfx(tempero);
      }
      if(overall.find(x)==overall.end())
      {
        overall[x]=1;
        id1.pb(x);
      }
      ll freq=0;
      while(tempero%x==0)
      {
        freq++;
        tempero/=x;
      }
      mf2[x]+=freq;
    }
  }

  

  

  

  

  



  tempero=f3;
  if(isprime(tempero))
  {
    if(overall.find(tempero)==overall.end())
    {
      overall[tempero]=1;
      id1.pb(tempero);
    }
    mf3[tempero]+=1;
  }
  else if(tempero==1)
  {
    

  }
  else
  {
    while(tempero!=1)
    {
      ll x;
      if(tempero<1000000)
      {
        x=lpf[tempero];
      }
      else
      {
        x=lpfx(tempero);
      }
      if(overall.find(x)==overall.end())
      {
        overall[x]=1;
        id1.pb(x);
      }
      ll freq=0;
      while(tempero%x==0)
      {
        freq++;
        tempero/=x;
      }
      mf3[x]+=freq;
    }
  }

  

  

  

  

  


  ll m[3][3]={{1,1,1},{1,0,0},{0,1,0}};

  matrix_exp(m,n-3);

  ll total=1;
  rep(o,id1.size())
  {
    ll x=id1[o];
    ll j=reduce(reduce(ultimate[0][0]*mf3[x],mod-1)+reduce(ultimate[0][1]*mf2[x],mod-1)+reduce(ultimate[0][2]*mf1[x],mod-1),mod-1);
    total*=modpow(x,j,mod);
    total%=mod;
  }

  ll iv=modpow(c,mod-2,mod);
  total*=modpow(iv,n,mod);
  total=reduce(total,mod);
  cout<<total<<endl;

  return 0;
}
