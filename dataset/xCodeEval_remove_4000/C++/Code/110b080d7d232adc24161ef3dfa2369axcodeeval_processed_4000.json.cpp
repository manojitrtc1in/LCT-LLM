






using namespace std;

int prime_factor(int number)
{
	int count = 0;
	for (int i = 2; i * i <= number; i++)
	{
		while (number % i == 0)
		{
			count++;
			number /= i;
		}
	}
	if (number != 1)
		count++;
	return count;
}

 

ll const N=1e6;
 ll n,b,m,t,ans=0,s=0,cnt=0;
ll a[N],fact[N];
vector<ll>v,v2;

void print(ll x)
{
    if(x>4444477777 )return;
    v2.push_back(x);
    print(x*10+4);
    print(x*10+7);
}

ll mod=1000000007;
ll mul(ll x, ll y)
{
    return ((x%mod) * (y%mod)) % mod;
}
ll add(ll x, ll y)
{
    return ((x%mod) + (y%mod)) % mod;
}
ll sub(ll x, ll y)
{
    return ((x%mod) - (y%mod)) % mod;
}
ll fastPow(ll b, ll p)
{
    if(p==0) return 1;

    ll hp = fastPow(b, p/2);
    ll ret = mul(hp, hp);

    if(p%2)
        ret = mul(ret, b);

    return ret;
}
ll modInverse(ll x)
{
    return fastPow(x, mod-2);
}
ll pre()
{
    fact[0] = 1;
    for(ll i=1;i<=100000;i++)
        fact[i] = mul(i, fact[i-1]);
        return 0;
}

 ll nCr(ll n, ll r){
   if(r>n)return 0;
   return mul(fact[n], modInverse(mul(fact[n - r], fact[r])));
}

 ll id0(ll x,ll y) 

 {
   ll m=1;
   for(int i=0;i<y;i++)
   {
    m=m*(x-i)/(i+1);
   }
   return m;

}

 int x,y;
void solve(int indx,vector<int>v){
 if(indx==y){
    int cnt=0;
    for(int i=0;i<v.size();i++){
        cnt+=v[i];
    }
    if(cnt==s)ans++;

    return ;

 }
  solve(indx+1,v);
  v.push_back(a[indx]);
  solve(indx+1,v);
  v.pop_back();


}


int main()
{
   pre();
   int tc;cin>>tc;

   while(tc--){
    cnt=0;
    map<ll,ll>mp;
    cin>>x>>y;

    for(int i=0;i<x;i++){
    cin>>a[i];
    mp[a[i]]++;
    }
    sort(a,a+x);
    ll id1=a[x-y];
    for(int j=x-1;j>=x-y;j--){
      if(a[j]!=id1)cnt++;
    }

    ll freq=mp[id1];

    ll ans=(nCr(freq,y-cnt));
    cout<<ans<<el;

  }
}








								 	 		  	        		 	 		