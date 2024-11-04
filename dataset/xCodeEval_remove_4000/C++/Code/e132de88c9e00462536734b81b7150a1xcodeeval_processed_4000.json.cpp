




using namespace std;















double eps=1e-9;
double pi=acos(-1);


ll fastpower(ll b,ll p)
{
    ll ans=1;
    while(p){if (p%2){ans=(ans*b);}b=b*b;p/=2;}
    return ans;
}

ll id0(ll b,ll p,ll m)
{
    ll ans=1;
    while(p)
    {
        if (p%2)
        {
            ans=((ans%m)*(b%m))%m;
        }
        b=((b%m)*(b%m))%m;
        p/=2;
    }
    return ans%m;
}
string  id1(ll n)
{
    string ans;
    bool ch=0;
    if (n<0)
    {
        n*=-1;
        ch=1;
    }
    if (n==0)
    {
        ans="0";
    };
    while (n)
    {
        ll mo=n%10;
        mo+=48;
        char m=mo;
        ans=m+ans;
        n/=10;
    }
    if (ch)
    {
        ans='-'+ans;
    }
    return ans;
}












bool checksqrt(ll f){ll num=sqrt(f);return (num*num==f);}














bool compare(double f,double s)
{
    return  (abs(f-s)<eps);
}
ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}





























const int N=1e6+1;




const int sz=2e5+20;
int parent[sz];
int depth[sz];
int cnt[sz];
vector<ll>adj[sz];
void st()
{

   for (int i=0;i<sz;i++)
   {
       parent[i]=i;
       depth[i]=1;

   }
}
int findp(int node)
{
    if (parent[node]==node)
    {
        return node;
    }
    return parent[node]=findp(parent[node]);
}
void unionnodes(int a,int b)
{
    int pa=findp(a);
    int pb=findp(b);
    if (pa==pb)
    {
     return ;
    }
    if (depth[pa]>=depth[pb])
    {
        depth[pa]+=depth[pb];
        parent[pb]=pa;
    }
    else {
        depth[pb]+=depth[pa];
        parent[pa]=pb;
    }
    return ;
}


int main()
{
     

    

    

      time;
     

     ll n,m;
     cin>>n>>m;
     ll maxi=0;
     ll source=0;
     for (int i=0;i<m;i++)
     {
         ll x,y;
         cin>>x>>y;
         adj[x].push_back(y);
         adj[y].push_back(x);
         if (maxi<adj[x].size())
         {
             maxi=adj[x].size();
             source=x;
         }
         if (maxi<adj[y].size())
         {
             maxi=adj[y].size();
             source=y;
         }
     }
     st();
     vector<pll>ans;
     for (int i=0;i<sz;i++)
     {

         for (int j=0;j<adj[i].size();j++)
         {
         if (i==source||adj[i][j]==source)
         {
            if (findp(i)!=findp(adj[i][j]))
            {
                    ans.push_back({i,adj[i][j]});
                    unionnodes(i,adj[i][j]);
            }
         }

          }
     }
      for (int i=0;i<sz;i++)
     {

         for (int j=0;j<adj[i].size();j++)
         {
         if (i==source||adj[i][j]==source)
         {
             continue;
         }
         else if (ans.size()<n-1&&findp(i)!=findp(adj[i][j]))
         {
             ans.push_back({i,adj[i][j]});
             unionnodes(i,adj[i][j]);
         }

         }
     }

     for (int i=0;i<ans.size();i++)
     {
         cout<<ans[i].first<<" "<<ans[i].second<<endl;
     }

     return 0;

}
