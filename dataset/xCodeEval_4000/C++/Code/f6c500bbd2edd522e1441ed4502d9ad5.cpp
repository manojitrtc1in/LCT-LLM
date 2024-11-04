





















































    #include<bits/stdc++.h>
    using namespace std;
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
  
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    

    #define int         long long
    #define double      long double
    #define pb          push_back
    #define pf          push_front
    #define pii         pair<int,int>
    #define vi          vector<int>
    #define vnn         vector<vector<int>>
    #define vii         vector<pii>
    #define vs          vector<string>
    #define all(a)      (a).begin(),(a).end()
    #define rall(a)     (a).rbegin(),(a).rend()
    #define x           first
    #define y           second
    #define endl        '\n'
    #define sz(x)       (int)(x).size()
    #define thunder     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
    #ifndef ONLINE_JUDGE
       #define debug(x)    cerr<<#x<<" "<<x<<endl;
    #else 
       #define debug(x)
    #endif  
    

    

    

    

    

    

    

    

    

    

    

    #define fo(i,l,u)   for(i=l;i<u;i++)
    #define rfo(i,l,u)  for(i=l;i>=u;i--)
    #define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++)
    #define _init(b)     memset(b,-1,sizeof(b))
    #define _init0(b)     memset(b,0,sizeof(b))
    #define MOD         1000000007
    #define hell        998244353
    #define output(x) cout << (x ? "YES" : "NO")<<endl;
    #define Output(x) cout << (x ? "Yes" : "No")<<endl;
    

    

    #define MOD2 (998244353)
    #define MOD3 (1000000009)
    #define PI acos(-1)
    #define eps (1e-8)
    #define INF (1e18) 
    template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
    template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
    template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
    template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
    ifstream cinn("in.txt");ofstream coutt("out.txt");
    int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;} 
    

    int gcd(int a, int b) 
    { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);    
    }
    int _sum(int n)
    {
        return (n*(n+1))/2;
    }
    int distSq(pii p, pii q) 
    { 
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);  
    }
    vi fact(101);
    int nCr(int n, int r)
    {
       if(!r) return 1;
       return (n*nCr(n-1,r-1))/r;
    }
    const int N = 4e5 + 5;
    

    vi adj[N];int vis[N];
    

    

    

    

    

    

 
    

    

    

    

    

    

 
    

    

    

 
    

    

    
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    void dfs(int node)
    {
        vis[node]=1;
        for(int n : adj[node])
        {
            if(!vis[n])
                dfs(n);
        }
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    int query(int t,int i,int j,int x1)
    {
        cout<<"?"<<" "<<t<<" "<<i<<" "<<j<<" "<<x1<<endl;
        cout.flush();
        int a;
        cin>>a;
        return a;
    }
    bool isprime(int n)
    {
        int i;
        if(n==1) return false;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

           
    

    

    

    

    

    

                   
    

                    
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    bool comp(pii a,pii b)
    {
      if(a.x==b.x) return a.y<b.y;
      return a.x<b.x;
    }
    signed main()
    {
        thunder;
        #ifndef ONLINE_JUDGE
           freopen("Input.txt","r",stdin);
           freopen("Output.txt","w",stdout);
           freopen("Error.txt","w",stderr);
        #endif
        int t,c,n,m,b,f,f2,k,t2,t3,i,j,ans1,mnt,mxt,j1,a;
        cin>>t;
        while(t--)
        {
            cin>>n;
            vi aa(n),bb(n);
            cin>>aa>>bb;
            fo(i,0,n)
            {
                adj[aa[i]].pb(bb[i]);
                adj[bb[i]].pb(aa[i]);
            }
            c=0;
            int ans=1;
            fo(i,1,n+1)
            {
                if(!vis[i])
                {
                    c++;
                    ans*=2;
                    ans%=MOD;
                    dfs(i);
                }
            }
            cout<<ans<<endl;
            fo(i,1,n+1) adj[i].clear();
            fo(i,1,n+1) vis[i]=0;

        }
    }
        
