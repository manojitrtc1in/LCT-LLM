


























auto clk=clock();









const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
const int dx8[]={-1,-1,-1,0,1,1,1,0}, dy8[]={-1,0,1,1,1,0,-1,-1};



using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());







ll Gcd(ll a,ll b){
	if(a%b==0) return b;
	return Gcd(b,a%b);
}


ll Max(ll a,ll b){
	if(a>b)
	return a;
	return b;
}


ll Min(ll a,ll b){
	if(a<b)
	return a;
	return b;
}


void printvector(std::vector<ll> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void printarray(ll a[],ll n){for (ll i = 0; i < n; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}

ll id5(vector<ll> arr, ll n) 
{ 
    

    ll ans = arr[0]; 
  
    

    

    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (Gcd(arr[i], ans))); 
  
    return ans; 
} 


ll id2(ll a, ll b, ll *x, ll *y)
{
    

    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; 
    ll gcd = id2(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}




   
 
 ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
} 






ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = id2(a, m, &x, &y);
    if (g != 1)
        return -1 ;
    else
    {
        
        ll res = (x%m + m) % m;
        return res;
    }
}




ll inverse(ll x,ll mod){
    return power(x,mod-2,mod);
}



vector<ll> primeFactors(ll n)
{    
    vector<ll> v;
	while (n%2 == 0)
	{
		v.push_back(2);
		n = n/2;
	}
	for (int i = 3; i <= sqrt(n); i = i+2)
	{
		while (n%i == 0)
		{
			v.push_back(i);
			n = n/i;
		}
	}

	if (n > 2)
		v.push_back(n);
		return v;
}


ll lowerbound(ll k,vector<ll> v){
  

  


  ll l=0;
  ll size=v.size();
  ll r=size-1;
  ll mid;
  while (l<=r)
  {
      mid=(l+r)/2;
      if(v[mid]<k) l=mid+1;
      else{
          r=mid-1;
      }
  }
  return l;

}

ll upperbound(ll k,vector<ll> v){
  

  

  ll l=0;
  ll size=v.size();
  ll r=size-1;
  ll mid;
  while (l<=r)
  {
      mid=(l+r)/2;
      if(v[mid]>k) r=mid-1;
      else{
          l=mid+1;
      }
  }
  return l;

}


ll C[2001][2000]; 

void id6(ll n, ll k) 
{ 
   
    ll i, j; 
  
    

    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= k; j++) 
        { 
            

            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            

            else
                C[i][j] = (C[i-1][j-1]%MOD + C[i-1][j]%MOD)%MOD; 
        } 
    } 
  
    

} 




string id3(const string &s) {
    string newString = "@";

    for (ll i = 0; i < s.size(); i++) {
        newString += "
    }

    newString += "
    return newString;
}

string id0(const string &s) {
    string Q = id3(s);
    ll c = 0, r = 0;          
    ll P[Q.size()+4];
    memset(P,0,sizeof(P));
    for (ll i = 1; i < Q.size() - 1; i++) {
        ll iMirror = c - (i - c);
         
        if(r > i) {
            P[i] = min(r - i, P[iMirror]);
        }
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
            P[i]++;
        }

        if (i + P[i] > r) {
            c = i;            
            r = i + P[i];
        }
    }
    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++) {

        if (P[i] > maxPalindrome) {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << "\n";
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}





  
ll spf[MAXN]; 
  
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
      spf[i] = i; 
   for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
           for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 




ll binarySearch(ll arr[], ll l, ll r, ll x)
{
   if (r >= l)
   {
        ll mid = l + (r - l)/2;
        if (arr[mid] == x)  
            return mid;
 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
 
        return binarySearch(arr, mid+1, r, x);
   }
 
   return -1;
}





          const ll N = 100000; 
 
ll n; 
 
           ll tree[2 * N];

void build( ll arr[]) 
{ 
    for (ll i=0; i<n; i++)    
        { tree[n+i] = arr[i];
	       
	     }
     
    for (ll i = n - 1; i > 0; --i)     
        {tree[i] = tree[i<<1] + tree[i<<1 | 1];    
              
	     }
}
 
void id4(ll p, ll value) 
{ 
    tree[p+n] = value;
    p = p+n;
     
    for (ll i=p; i > 1; i >>= 1)
        {tree[i>>1] = tree[i] + tree[i^1];
	       }
}
 
ll query(ll l, ll r) 
{ 
    ll res = 0;
     
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) 
           {    
			   res += tree[l++];
               
               }    
        if (r&1) 
             {   res += tree[--r];
				 
            }
    }
     
    return res;
}














vector<ll> shortPath( vector<pair<ll,ll> > v[],ll src,ll V=0) 
{ 
     set< pair<ll,ll> > setds; 
  
    ll sizee=V;
    ll IN=INF;
    vector<ll> dist(sizee, IN); 
    vector<bool> vis(sizee,false);
    setds.insert(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!setds.empty()) 
    { 
        pair<ll, ll> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 

        ll u = tmp.second; 
        if(vis[u]) continue;
        vis[u]=true;
        vector< pair<ll, ll> >::iterator i; 
        for (auto i = v[u].begin(); i != v[u].end(); ++i) 
        { 
            ll v = (*i).first; 
            ll weight = (*i).second; 
      if (dist[v] > dist[u] + weight) 
            { 
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    }
    return dist;
} 



ll root(ll a[],ll r)
{
     if(a[r]==r)
     {
       return r;
     }
     else
     {
       ll x=root(a,a[r]);
       a[r]=x;
       return x;
     }

} 
 
void unio(ll a[],ll  size[],ll  x,ll  y){
  x=root(a,x);
  y=root(a,y);
  if(x==y){return;}
  if(size[x]>=size[y])
  {
       a[y]=x;
       size[x]+=size[y];
  }
  else
  {
      a[x]=y;
      size[y]+=size[x];
  }
 
}










void dfs(std::vector<ll> v[],ll s,bool visited[])
{
	visited[s]=true;
  for (ll i = 0; i < v[s].size(); ++i)
  {
  	if(!visited[v[s][i]] )
  	{ 
  		dfs(v,v[s][i],visited);

  	}

  }


}























    




int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll txt=1;


while(txt--)
{  
    
    cin>>n;
    vector<ll> suf(n,0);
    vector<ll> id1(n,0);
    vector<ll> pre(n,0);
    
    vector<ll> p(n);
    string s;
    ll mx=0;
    rep(i,n) cin>>p[i];
    cin>>s;
    rep(i,n ) {
       

        if(!i)
        {  if(s[i]=='B')
            id1[i]=p[i];

        }
        else
        {   if(s[i]=='B')
            id1[i]=p[i]+id1[i-1];
            else {
                id1[i]=id1[i-1];
            }
        }
        
    }
    repr(i,n){
        if(i==n-1){
            if(s[i]=='B'){
                pre[i]=p[i];
            }
            continue;
        }
        if(s[i]=='B'){
            pre[i]=p[i]+pre[i+1];
        }
        else
        {
            pre[i]=pre[i+1];
        }
        
    }
    
    ll sum=0;
    ll sumb=0;
    ll suma=0;
    

        repr(i,n){
        sum+=p[i];
        if(s[i]=='A') {
            suma+=p[i];
            if(i)
            mx=max(suma+id1[i-1],mx) , mx=max(sumb+id1[i-1],mx);
            else
            {
                mx=max(sumb,mx);
                mx=max(suma,mx);
            }    
        }
        else
        {
            sumb+=p[i];
            if(i)
            mx=max(sumb+id1[i-1],mx);
            else
            {
                mx=max(sumb,mx);
            }
            
        }
        
        


    }
    suma=sumb=0;

        rep(i,n){
            if(s[i]=='A'){
                suma+=p[i];
                if(i!=n-1)
                mx=max(sumb+pre[i+1],mx), mx=max(suma+pre[i+1],mx);
                else
                {
                    mx=max(sumb,mx);
                    mx=max(suma,mx);
                }
                

            }
            else
            {
                sumb+=p[i];
                if(i!=n-1)
                mx=max(sumb+pre[i+1],mx), mx=max(suma+pre[i+1],mx);
                else
                {
                    mx=max(sumb,mx);
                    mx=max(suma,mx);
                }
            }
            



        }


    cout<<mx<<endl;













}


}







