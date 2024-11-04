#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define OO 4e18
#define oo 2e9
#define yalla ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define sz  100005
#define re return
#define F first
#define S second
#define pll pair<ll,ll>
#define mod  1000000007
#define pi acos(-1)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>,null_type,less<pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update>
ll n,m,x,y,sum,parent[sz],rankk[sz],c[sz];
ld ans;
pair<int,int>cost[sz];
vector<vector<int> >v(sz);


int findd(int x)
{ if(parent[x]==x)
   re x;
  re parent[x]=findd(parent[x]);
}


void connect(int x,int y)
{ int pox=findd(x);
  int poy=findd(y);
  

  if(rankk[pox]>rankk[poy])
    parent[poy]=pox,rankk[pox]+=rankk[poy];
  else if(rankk[pox]<rankk[poy])
    parent[pox]=poy,rankk[poy]+=rankk[pox];
  else
    parent[pox]=poy,rankk[poy]+=rankk[pox];
}


int main()
{
    yalla;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
     {cin>>c[i],cost[i]={c[i],i};
      parent[i]=i,rankk[i]=1;
     }
    

    for(int i=0;i<m;i++)
     { cin>>x>>y;
       v[x].push_back(y);
       v[y].push_back(x);
     }
     

     sort(cost+1,cost+(n+1));
     reverse(cost+1,cost+(n+1));
     

     for(int i=1;i<=n;i++)
      { ll val=cost[i].F;
        ll node=cost[i].S;

        for(int y=0;y<v[node].size();y++)
        { ll child =v[node][y];
          ll f1=findd(node),f2=findd(child);

          if(val>c[child])continue;

           if( f1!=f2 )
           {
             ans+=(val*rankk[f1]*rankk[f2]);
             connect(node,child);
           }
        }
      }
    

    ans*=2.0;
    ans/=(1.0*n*(n-1));
    cout<<fixed<<setprecision(6)<<ans<<endl;
    re 0;
}































