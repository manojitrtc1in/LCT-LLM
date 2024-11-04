





















































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


template<typename T> 

istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}

void printS (multiset<ll>myset)
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
int dist(int x1,int y1,int x2,int y2,vector<int>ps[])
{
    return (ps[x2][y2]-ps[x1-1][y2]-ps[x2][y1-1]+ps[x1-1][y1-1]);
}
void solve(int t)
{
    

    

    

    

    

    

    

    

    ll n,k,x;
        cin>>n>>k>>x;
        string s;
        cin>>s;
        if((k+1)>=x)
        {
            string s1 = "";
            bool check = 0;
            for(ll i=n-1; i>=0; i--)
            {
                if(s[i]=='*')
                {
                    if(check==0)
                    {
                        check = 1;
                        for(ll j=0; j<(x-1); j++)
                        {
                            s1.pb('b');
                        }
                    }
                }
                else s1.pb('a');
            }
            reverse(all(s1));
            cout<<s1<<endl;
            return;
        }
        vector<pair<ll,ll>> vect;
        for(ll i=n-1; i>=0; i--)
        {
            if(vect.size()==0 && s[i]=='*') vect.pb({i,1});
            else if(s[i]=='*')
            {
                if(vect.back().ff==i+1)
                {
                    ll temp = vect.back().ss;
                    vect.pop_back();
                    vect.pb({i,temp+1});
                }
                else vect.pb({i,1});
            }
        }
        if(vect.size()) reverse(all(vect));
        vector<ll> ans(n,0);
        for(ll i=0; i<vect.size(); i++) (vect[i].ss)*=k, vect[i].ss++;
        ll curr = 1;
        x--;
        for(ll i=vect.size()-1; i>=0; i--)
        {
            ll a1 = x%(vect[i].ss);
            x = x/(vect[i].ss);
            ans[vect[i].ff] = a1;
        }
        for(ll i=0; i<n; i++)
        {
            if(s[i]=='a') cout<<'a';
            else
            {
                for(ll j=0; j<ans[i]; j++) cout<<'b';
            }
        }
        cout<<endl;
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
        

        solve(i);
    }

    


    return 0;
}






































