




















































using namespace std;




































vector<ll>pw;


                                               



                                                                  

bool id3(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
bool my_sort(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.first<b.first)
        return true;
    else if(a.first>b.first)
        return false;
    else return(a.second > b.second);
}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}




int id0(int n)
{
    int ans=0;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                ans+=i;

            else
                ans+=(i+n/i);
        }
    }
    return ans;
}

void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
    if (n > 2)
        cout << n << " ";
}
ll factorial(ll n)
{
     ll M = 998244353;

     ll f = 1;
    for (ll i = 1; i <= n; i++)
        f = (f*i) % M;  

                        

    return f;
}
bool isPrime(ll n)
{
    

    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    

    

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void printS (multiset<int>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printS (set<int>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printS (set<char>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printS (set<ll>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printSS (set<string>myset)
{
    for (auto it = myset.begin(); it !=
                             myset.end(); ++it)
        cout << *it<< ' ' ;
    cout<<endl;
}
void printV (vector<int>v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void printV (vector<ll>v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void id1 (map<ll,ll>mp)
{
    for(auto it:mp)
        cout<<it.first<<" "<<it.second<<endl;
}
void id1 (map<int,int>mp)
{
    for(auto it:mp)
        cout<<it.first<<" "<<it.second<<endl;
}
void printVP (vector<pair<ll,ll>>v)
{
    for(ll i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
}
void printVP (vector<pair<int,int>>v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
}
void printA (int v[],int n)
{
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void printA (ll v[],ll n)
{
    for(ll i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
mt19937 rng;
ll id2(ll l, ll r)
{
    uniform_int_distribution<ll> dist(l, r);
    return dist(rng);
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     


    x = x % p; 

                


    if (x == 0) return 0; 


    while (y > 0)
    {
        

        if (y & 1)
            res = (res*x) % p;

        

        y = y>>1; 

        x = (x*x) % p;
    }
    return res;
}
ll power(ll x, ll y)
{
    ll res = 1;     


     

                


    if (x == 0) return 0; 


    while (y > 0)
    {
        

        if (y & 1)
            res = (res*x) ;

        

        y = y>>1; 

        x = (x*x) ;
    }
    return res;
}
bool isPal(string s)
{
    int i,n=s.size();
    for(i=0;i<n/2;i++)
        if(s[i]!=s[n-1-i])
            return false;
    return true;
}

void sieve(vector<ll>&v)       

{
    for (int i = 1; i < v.size(); ++i) {
        for (int j = i; j < v.size(); j += i)
            v[j]+=i;
    }
}
int dfs(int root,vector<bool>&vis,vector<int>adj[],vector<int>&val,int ev)
{
    

    

    vis[root]=true;
    int temp=val[root];
    for(auto it:adj[root])
    {
        if(!vis[it])
        {
            temp^=dfs(it,vis,adj,val,ev);
        }
    }
    if(temp==ev)
    {
        

        temp=0;
    }
    return temp;
}
bool isValid()
{
    return true;
}
bool comp(pair<ll,ll> &a,pair<ll,ll> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
void solve()
{
    

    

    

    

    

    

    

    

    int n,i,k;
    string s;
    cin>>n>>k>>s;
    vector<int>a(n),z;
    if(!k)
    {
        cout<<s<<endl;
        printV(a);
        return;
    }
    if(s.size()==1)
    {
        cout<<s<<"\n"<<k<<endl;
        return;
    }
    if(k%2)
    {
        bool got=false;
        for(i=0;i<n;i++)
        {
            if(s[i]=='0')
                s[i]='1';
            else
            {
                if(!got)
                {
                    got=true;
                    a[i]=1;
                    k--;
                }
                else
                {
                    s[i]='0';
                    z.pb(i);
                }
            }
        }
        if(k%2)
        {
            a[n-1]=k;
            for(i=0;i<n-1;i++)
                cout<<'1';
            cout<<'0'<<endl;
            printV(a);
            return;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(s[i]=='0')
                z.pb(i);
        }
    }
    for(i=0;i<z.size() && k>0;i+=2)
    {
        if(i!=z.size()-1)
        {
            a[z[i]]=1;
            a[z[i+1]]=1;
            s[z[i]]='1';
            s[z[i+1]]='1';
            k-=2;
        }
    }
    if(k>0)
    {
        if(z.size()%2)
        {
            int x=z[z.size()-1],y=n-1;
            if(x!=n-1)
            {
                a[x]++;
                a[y]++;
                k-=2;
                s[x]='1';
                s[y]='0';
            }
        }
        a[n-1]+=k;
    }
    cout<<s<<endl;
    printV(a);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    

    

    

    

    

    

    

    

    

    int t;
    t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        

        solve();
    }

    


    return 0;
}






































