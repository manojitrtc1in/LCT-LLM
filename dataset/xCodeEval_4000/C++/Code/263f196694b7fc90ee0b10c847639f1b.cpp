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
#define mod  998244353
#define pi acos(-1)
#define eps 1e-12


#define dot1(a,b) 1.0*(conj(a)*b).real()
#define dot2(a,b) abs(a)*abs(b)*cos(arg(a)-arg(b))
#define cross(a,b) ((conj(a)*(b)).imag())
#define rule1(a,b) 1.0*dot1(a,b)/(1.0*abs(a)*abs(b))
#define angele_two_vec(a,b) acos( rule1(a,b) )*180.0/pi
#define angle_withXaxis(a) atan2((a).imag(),(a).real())
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;




#define ordered_set tree<int,null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
template<class T> using ordered_class_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
int n,m,k,s,t,d[sz],chos[sz];
ll dp[sz][205],w[sz];
set<pair<pair<int,int>,int> >st;
deque<pair<bool,int>>v[sz];


ll solve(ll tim ,ll rim)
{ if(tim>n) re 0;
  if(dp[tim][rim]!=-1)
  re dp[tim][rim];
  

  ll fi=OO,se=OO,i=chos[tim];
    if(i)
    {fi=solve(d[i]+1,rim)+w[i];
      if(rim)
      se=solve(tim+1,rim-1);
    }
    else
      fi=solve(tim+1,rim);
  

  re dp[tim][rim]=min(fi,se);
}


void push(ll tim)
{ for(int y=0;y<v[tim].size();y++)
  {int idx=v[tim][y].S;
     if(v[tim][y].F==0)
     st.insert({{-w[idx],-d[idx]},idx});
  }
}
void in(ll tim)
{if(!st.empty())
 chos[tim]=(*st.begin()).S;
}
void del(ll tim)
{ for(int y=0;y<v[tim].size();y++)
  {int idx=v[tim][y].S;
    if(v[tim][y].F)
    st.erase({{-w[idx],-d[idx]},idx});
  }
}


void choose()
{ for(int tim=1;tim<=n;tim++)
  {
    push(tim);
    in(tim);
    del(tim);
  }
}


int main()
{
    yalla;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
     {cin>>s>>t>>d[i]>>w[i];
      v[s].push_back({0,i});
      v[t].push_back({1,i});
     }
    

    choose();
    memset(dp,-1,sizeof dp) ;
    cout<<solve(1,m)<<endl;
    re 0;
}








