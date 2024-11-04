#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map> 
using namespace std;
#define ll long long
#define lmin LONG_MIN
#define lmax LONG_MAX
#define imin ll_MIN
#define imax ll_MAX
#define ffor(i,a,b) for(ll i=a;i<b;i++)
#define bfor(i,a,b) for(ll i=a-1;i>=b;i--)
#define mset(f,a) memset(f,a,sizeof(f))
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAXN   100
#define level 18
ll M= 1e9+7;
ll fact[10];

ll sieve[10];

ll power(ll x ,ll y)
{
    if(y==0)
        return 1;
    
    ll t=power(x, y/2);
    
    t=((t%M)*(t%M))%M;
    
    if(y%2==1)
        t=((t%M)*(x%M))%M;
    
    return t;
    
}
  
ll max(ll a, ll b)
{
    if(a>b)
        return a;
    
    return b;
}
 
ll min(ll a, ll b)
{
    if(a>b)
        return b;
    
    return a;
}
  
 
ll binarySearch(vector<ll> arr, ll l, ll r, ll x) 
{ 
    if (r >= l) { 
        ll mid = l + (r - l) / 2; 
  
        

        

        if (arr[mid] == x) 
            return mid; 
  
        

        

        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        

        

        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    

    

    return -1; 
}
 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
      
}
 
ll phi(ll n)
{
    ll result = n;
    
    for (ll p = 2; p * p <= n; ++p)
    {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
void dfs(ll source,ll visited[],vector<ll>graph[],ll l)
{
    visited[source]=l;
    ll i;
    
    for(i=0;i<graph[source].size();i++)
    {
        if(visited[graph[source][i]]==-1)
            dfs(graph[source][i], visited, graph, l);
    }
}

bool isPerfectSquare(long double x) 
{   
  
  long double sr = sqrt(x); 
 
  return ((sr - floor(sr)) == 0); 
} 

ll getMid(ll s, ll e) { return s + (e -s)/2; }  
  

ll getSumUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll si)  
{  
    

    

    if (qs <= ss && qe >= se)  
        return st[si];  
  
    

    if (se < qs || ss > qe)  
        return 0;  
  
    

    ll mid = getMid(ss, se);  
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +  
        getSumUtil(st, mid+1, se, qs, qe, 2*si+2);  
}  
  

void updateValueUtil(ll *st, ll ss, ll se, ll i, ll diff, ll si)  
{  
    

    

    if (i < ss || i > se)  
        return;  
  
    

    

    st[si] = st[si] + diff;  
    if (se != ss)  
    {  
        ll mid = getMid(ss, se);  
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);  
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);  
    }  
}  
  




void updateValue(ll arr[], ll *st, ll n, ll i, ll new_val)  
{  
    

    if (i < 0 || i > n-1)  
    {  
        cout<<"Invalid Input";  
        return;  
    }  
  
    

    ll diff = new_val - arr[i];  
  
    

    arr[i] = new_val;  
  
    

    updateValueUtil(st, 0, n-1, i, diff, 0);  
}  
  




ll getSum(ll *st, ll n, ll qs, ll qe)  
{  
    

    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return -1;  
    }  
  
    return getSumUtil(st, 0, n-1, qs, qe, 0);  
}  
  




ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si)  
{  
    

    

    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
  
    

    

    ll mid = getMid(ss, se);  
    st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +  
            constructSTUtil(arr, mid+1, se, st, si*2+2);  
    return st[si];  
}  
  

ll *constructST(ll arr[], ll n)  
{  
    

  
    

    ll x = (ll)(ceil(log2(n)));  
  
    

    ll max_size = 2*(ll)pow(2, x) - 1;  
  
    

    ll *st = new ll[max_size];  
  
    

    constructSTUtil(arr, 0, n-1, st, 0);  
  
    

    return st;  
}  
  

vector<ll> maxSubArraySum(ll a[], ll size) 
{ 
    ll max_so_far = lmin, max_ending_here = 0, 
       start =0, end = 0, s=0; 
  
    for (ll i=0; i< size; i++ ) 
    { 
        max_ending_here += a[i]; 
  
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
  
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
    
    vector<ll>v;
    v.pb(max_so_far);
    v.pb(start);
    v.pb(end);

   
    return v;
} 

vector<ll> smallestSumSubarr(ll arr[], ll n) 
{ 
    ll min_ending_here = 0; 
      
    ll min_so_far = lmax,start=0,end=0,s=0; 
      
    for (ll i=0; i<n; i++) 
    { 
        min_ending_here+=arr[i];

        if (min_so_far > min_ending_here) 
        { 
            min_so_far = min_ending_here; 
            start = s; 
            end = i; 
        }   

         if (min_ending_here > 0) 
        {    
            min_ending_here = 0; 
            s=i+1;
        }     
    } 
      
    vector<ll>v;
    v.pb(min_so_far);
    v.pb(start);
    v.pb(end);

    return v;
} 

void bfs(vector<ll>g[],ll dist[],bool v[],ll u) 
{ 
    queue<ll> q; 
  
    q.push(u); 
    v[u] = true; 
    dist[u]=0;

    while (!q.empty()) 
    { 
        ll f = q.front(); 
        q.pop(); 
  
        

        for (auto i = g[f].begin(); i != g[f].end(); i++) 
        { 
            if (!v[*i]) 
            { 
                q.push(*i); 
                v[*i] = true; 
                dist[*i]=dist[f]+1;
            } 
        } 
    } 
} 

class DisjSet { 
    ll *rank, *parent, *gc, n; 
  
public: 
    

    

    DisjSet(ll n) 
    { 
        rank = new ll[n]; 
        parent = new ll[n]; 
        gc = new ll[n];
        this->n = n; 
        makeSet(); 
    } 
  
    

    void makeSet() 
    { 
        for (ll i = 0; i < n; i++) { 
            parent[i] = i; 
        } 

        for (ll i = 0; i < n; i++) { 
            rank[i] = i; 
            gc[i]=i;
        } 

    
    } 
    
    void initi(ll a[])
    {
        for(ll i=0;i<n;i++)
            gc[i]=a[i]%M;
    }
    

    ll find(ll x) 
    { 
        

        

        if (parent[x] != x) { 
  
            

            

            

            parent[x] = find(parent[x]); 
  
            

            

            

        } 
  
        return parent[x]; 
    } 
  
    

    

    bool Union(ll x, ll y) 
    { 
        

        ll xset = find(x); 
        ll yset = find(y); 
  
        

        if (xset == yset) 
            return false; 
  
        

        

        

        if (rank[xset] < rank[yset]) { 
            parent[xset] = yset; 
            gc[yset]=gcd(gc[yset],gc[xset])%M;
        } 
        else if (rank[xset] > rank[yset]) { 
            parent[yset] = xset; 
            gc[xset]=gcd(gc[yset],gc[xset])%M;
        } 
        

        

        

        

        

        

        

        
    } 

    ll get(ll x)
    {
        return gc[x]%M;
    }
}; 
  
bool isPali(string s)
{
    ll st=0,ed=s.size()-1;

    while(st<=ed && s[st]==s[ed])
    {
        st++;
        ed--;
    }

    if(st>ed)
        return true;

    return false;
}


ll sp[MAXN]; 
  






ll mp[15000001];
ll siev() 
{ 
    sp[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        sp[i] = i; 
  
    
    ll j;
    ll mx=0;
    for (ll i=2; i*i<MAXN; i++) 
    { 
        ll c=0;
        
        if (sp[i] == i) 
        { 
            c+=mp[i];
            for (j=i*2; j<MAXN; j+=i) 
  
                c+=mp[j];
                if (sp[j]==j) 
                    sp[j] = i; 
        } 

        if(mx<c)
            mx=c;
    } 

    return mx;

    
} 
  





ll a[2][100009];

vector<ll> getFactorization(ll x) 
{ 
    vector<ll> ret; 
    
    while (x != 1) 
    { 
        ret.push_back(sp[x]); 
        x = x / sp[x]; 
    } 

    
    return ret; 
} 

ll findlcm(ll arr[], ll n) 
{ 
    

    ll ans = arr[0]; 
  
    for (ll i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 
void bfs(vector<ll>v[],ll n,ll parent[])
{
    ll i;
    
    ll flg[200000+9]={0};
    
    queue<ll>q;
    q.push(n);
    parent[n]=-1;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        flg[u]=1;
        for(i=0;i<v[u].size();i++)
        {
            ll ve=v[u][i];
            
            if(flg[ve]==0)
            {
                q.push(ve);
                parent[ve]=u;
            }
        }
       

    }
    
    
}

ll spf[MAXN];

vector<ll> getFactor(ll n) 
{ 
    vector<ll>v;

    ll i;

    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(n/i!=i)
                v.pb(n/i);
            v.pb(i);
        }
    }

    return v;
} 


ll s;
ll poww[1000000+9];
ll c[1000000+9];

vector <ll> tree[200000+9]; 
ll depth[200000+9]; 
ll parent[200000+9][level]; 
  






void dfsUtil(vector<ll>v[], ll s,ll vis[],ll dis[]) 
{ 
    vis[s]=1;

    ll i;

    for(i=0;i<v[s].size();i++)
    {
         if(vis[v[s][i]]==0)
        {
            vis[v[s][i]]=1;
            dis[v[s][i]]=dis[s]+1;
            dfsUtil(v,v[s][i],vis,dis);
        }
    }
} 
  






ll dis[200009];
ll par[200009];
void dfs(ll cur, ll prev) 
{ 
    

    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    

    for (ll i=0; i<tree[cur].size(); i++) 
    { 
        if (tree[cur][i] != prev) 
        {
            dis[tree[cur][i]]=dis[cur]+1;
            par[tree[cur][i]]=cur;
            dfs(tree[cur][i], cur); 
        }
    } 
} 
  

void precomputeSparseMatrix(ll n) 
{ 
    for (ll i=1; i<level; i++) 
    { 
        for (ll node = 1; node <= n; node++) 
        { 
            if (parent[node][i-1] != -1) 
                parent[node][i] = 
                    parent[parent[node][i-1]][i-1]; 
        } 
    } 
} 
  




ll lca(ll u, ll v) 
{ 
    if (depth[v] < depth[u]) 
        swap(u, v); 
  
    ll diff = depth[v] - depth[u]; 
  
    

    for (int i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = parent[v][i]; 
  
    

    if (u == v) 
        return u; 
  
    

    for (ll i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
  
    return parent[u][0]; 
} 

void dfs(vector<ll>v[],ll s, ll dis[],ll vis[],ll a[], ll su[],ll y)
{
    

    
    if(su[s]==-1)
    {
        a[s]=0;
    }
    else
    {
        a[s]=su[s]-y;
    }

    y+=a[s];

    ll i;
    vis[s]=1;

    for(i=0;i<v[s].size();i++)
    {
        if(vis[v[s][i]]==0)
        {
            dis[v[s][i]]=dis[s]+1;
            dfs(v,v[s][i],dis,vis,a,su,y);
        }
    }

    y-=a[s];
}

void numberOfNodes(vector<ll>adj[],ll count1[],ll s, ll e) 
{ 
    vector<ll>::iterator u; 
    count1[s] = 1; 
    for (u = adj[s].begin(); u != adj[s].end(); u++) { 
          
        

        

        if (*u == e) 
            continue; 
          
        

        numberOfNodes(adj,count1,*u, s); 
          
        

        

        count1[s] += count1[*u]; 
    } 
} 


ll p[100000+9];
ll f[100000+9];

vector<ll> getBinary(ll x)
{
    vector<ll>v;

    while(x>0)
    {
        v.pb(x%2);
        x=x/2;
    }

    

    
    return v;
}

ll max(ll a, ll b, ll c) { return max(max(a, b), c); } 
ll maxCrossingSum(ll arr[], ll l, ll m, ll h) 
{ 
    

    ll s1[m-l+1],s2[h-m];
    mset(s1,0);
    mset(s2,0);

    s1[m-l]=arr[m];
    ll le=m-l-1;
    ll i;

    ll mx1[m-l+1],mx2[h-m];
    mx1[m-l]=arr[m];

    for(i=m-1;i>=l;i--)
    {
        s1[le]=s1[le+1]+arr[i];
        

        mx1[le]=max(mx1[le+1],arr[i]);
        le--;
    }

    s2[0]=arr[m+1];
    le=1;
    
    mx2[0]=arr[m+1];
    

    for(i=m+2;i<=h;i++)
    {
        s2[le]=s2[le-1]+arr[i];
        mx2[le]=max(mx2[le-1],arr[i]);
        

        le++;
    }

    
    ll j;
    i=0;j=h-m-1;
    ll maxi=0;

    while(i<=m-l && j>=0)
    {
        if(maxi<s1[i]+s2[j]-max(mx1[i],mx2[j]))
            maxi=s1[i]+s2[j]-max(mx1[i],mx2[j]);
        

        if(mx1[i]==max(mx1[i],mx2[j]))
            i++;
        else
            j--;

        cout<<maxi<<endl;
    }

    return maxi;
} 
  


ll maxSubArraySum(ll arr[], ll l, ll h) 
{ 
   

   if (l == h) 
     return 0; 
  
   


   
   ll m = (l + h)/2; 
    

    





    ll l1=maxSubArraySum(arr, l, m);
    ll l2=maxSubArraySum(arr, m+1, h);
    ll l3=maxCrossingSum(arr, l, m, h);


    cout<<l1<<" "<<l2<<" "<<l3<<" "<<l<<" "<<h<<endl;
   return max(l1,l2, l3); 
} 

ll Ni,Mi;



vector<ll> bfsM(ll s, vector<ll>v[], ll dis[], bool vis[],ll a[],ll b[],double rt)
{
    queue<ll>q;
    dis[s]=1;
    vector<ll>vt;
    q.push(s);
    vis[s]=true;
    

    

    vt.pb(s);

    while(!q.empty())
    {
        ll u=q.front();
        q.pop();

        ll i;

        for(i=0;i<v[u].size();i++)
        {
            
            double d=(a[v[u][i]]/(double)b[v[u][i]]);
            
            if(!vis[v[u][i]] && d==rt)
            {
                

                q.push(v[u][i]);
                dis[v[u][i]]=dis[u]+1;
                vis[v[u][i]]=true;
                vt.pb(v[u][i]);
            }
        }
    }

    return vt;
}

pair<ll,ll>dfsUti(vector<ll>v[],ll s, ll a[], ll b[], ll c[], ll vis[],pair<ll,ll>p[])
{
    
    vis[s]=1;

    ll x=0,y=0;
    for(ll i=0;i<v[s].size();i++)
    {
        

        if(vis[v[s][i]]==0)
        {
            if(a[s]<a[v[s][i]])
                a[v[s][i]]=a[s];
            
            pair<ll,ll>p1=dfsUti(v,v[s][i],a,b,c,vis,p);
            x+=p1.first;
            y+=p1.second;
        }
    }

    if(b[s]==1 && c[s]==0)
        y++;
    else if(b[s]==0 && c[s]==1)
        x++;

    if(1)
    {
        ll d=min(x,y);
        x=x-d;
        y=y-d;
        p[s]=make_pair(d,d);
    }
   
    return make_pair(x,y);
}

void dfs(vector<ll>v[],ll s, ll a[], ll vis[],pair<ll,ll>p[],ll*cost,ll c)
{
    vis[s]=1;

    
    ll count=2*p[s].first;
    (*cost)=(*cost)+(a[s]*count);
    c=a[s];

    

    for(ll i=0;i<v[s].size();i++)
    {
        if(vis[v[s][i]]==0)
        {
            dfs(v,v[s][i],a,vis,p,cost,c);
        }
    }
}
ll ft;
bool compt(ll x, ll y)
{
    return (x%ft)<(y%ft);
}

ll findMex(ll b[], ll n)
{
    ll l=0;

    ll a[n];
    for(ll i=0;i<n;i++)
        a[i]=b[i];

    sort(a,a+n);

    for(ll i=0;i<n;i++)
    {
        if(a[i]!=l)
        {
            return l;
        }

        while(i<n && a[i]==l)
        {
            i++;
        }
        i--;
        l++;
    }

    return l;
}
ll maxProductSubarrayOfSizeK(ll A[], ll n, ll k) 
{ 
    

    sort(A, A + n); 
  
    

    

    ll product = 1; 
  
    

    

    

    if (A[n - 1] == 0 && (k & 1)) 
        return 0; 
  
    

    

    

    

    if (A[n - 1] <= 0 && (k & 1)) { 
        for (ll i = n - 1; i >= n - k; i--) 
        {
            product =(product*A[i])%M;

            if(product<0)
                product+=M;
        }
        
        return product; 
    } 
  
    

    

    ll i = 0; 
  
    

    ll j = n - 1; 
  
    

    

    

    

    

    

    if (k & 1) { 
        product *= A[j];
        product=product%M; 
        j--; 
        k--; 
    } 
  
    

    

    

    

    

    

    

    k >>= 1; 
  
    

    

    for (ll itr = 0; itr < k; itr++) { 
  
        

        ll left_product = A[i] * A[i + 1]; 
  
        

        ll right_product = A[j] * A[j - 1]; 
  
        

        

        if (left_product > right_product) 
        { 
            ll f=left_product%M;

            if(f<0)
                f+=M;
            
            product = ((product%M)*(f%M))%M; 
            
            if(product<0)
                product+=M;
            
            i += 2; 
        } 
        else { 
            ll f=right_product%M;

            if(f<0)
                f+=M;
            
            product = ((product%M)*(f%M))%M; 
            
            if(product<0)
                product+=M;
            j -= 2; 
        } 
    } 
  
    

    return product; 
} 

ll computeXOR(const ll n) 
{ 
    

    

    

    

    switch (n & 3) { 
  
    

    case 0: 
        return n; 
  
    

    case 1: 
        return 1; 
  
    

    case 2: 
        return n + 1; 
  
    

    case 3: 
        return 0; 
    } 
}

void output()
{
    fastio

    string s;
    cin>>s;

    if(s.size()==1)
    {
        cout<<s<<endl;
        return;
    }
    ll i,j;

    ll a[26]={0};

    for(i=0;i<s.size();i++)
        a[(s[i]-'a')]++;

    ll c=0;

    for(i=0;i<26;i++)
    {
        if(a[i]%2)
            c++;
    }

    ll f=0;

    if(c%2)
        f=1;

    c=c/2;
    

    string st="";
    vector<char>v;

    for(i=0;i<26;i++)
    {
        if(a[i]%2==1 && c>0)
        {
            st.push_back('a'+i);
            c--;
            v.push_back('a'+i);

        }
        else if(a[i]%2==1)
        {
            v.push_back('a'+i);
        }
        
        for(j=0;j<a[i]/2;j++)
            st.push_back(('a'+i));
    }
    

    if(v.size()%2==1)
    {
        st.push_back(v[(v.size()/2)]);

        i=st.size()-2;

        while(i>=0)
        {
            st.push_back(st[i]);
            i--;
        }
    }
    else
    {
        i=st.size()-1;

        while(i>=0)
        {
            st.push_back(st[i]);
            i--;
        }
    }
    
    cout<<st<<endl;
}   

int main(int argc, const char * argv[]) {
    




    fastio
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    


    

    ll t;
    t=1;
   

    
    p[0]=1;

    

    

    
    


    

    

    
    
    while(t--)
        output();
        
    return 0;
}