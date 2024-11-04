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
int n,a,b,rankk=1,ans,tmp=1,tot,num;
priority_queue<int>q,q2;
deque<int>d,d2;
bool check()
{
    if(n==1&&d[0]==1)cout<<0,exit(0);
  else if(n==1)cout<<1,exit(0);

  for(int i=1;i<n;i++)
      if(d[i]<=d[i-1])re 0;
   re (d[0]==1);
}


int test()
{ int ok=0,steps=0;
  for(int i=0;i<n;i++)
   if(d2[i]==tmp&& (i==n-1||d2[i]<d2[i+1]))tmp++,ok=1;
   else if(ok)re oo;
   rankk=tmp;
   

    while(!q2.empty() )
      {
       int val=-q2.top(),ok=0;
       if(rankk==val)
        {d2.push_back(val),q2.pop(),rankk++;
         if(!d2.empty())
         { if(d2.front()!=0) q2.push(-d2.front());
           d2.pop_front();
         }
        }
       else re oo;

       steps++;
       if(rankk>n)break;
      }

 re steps;
}


void input()
{ cin>>n,q.push(-oo),q2.push(-oo);
    for(int i=0;i<n;i++)
     {cin>>a;
      if(a)q.push(-a),q2.push(-a);
     }
    for(int i=0;i<n;i++)
     cin>>b,d.push_back(b),d2.push_back(b),num+=(b>0);
     

}


int main()
{
    yalla;
    input();
    

    if(check())cout<<0;
    else
    {
     while(!q.empty() )
     {
      int val=-q.top(),ok=0;
      if(rankk==val)
       d.push_back(val),q.pop(),rankk++,ok=1;

       if(!d.empty())
       { if(d.front()!=0&&tot<num) q.push(-d.front()),tot++;
         d.pop_front();
         if(!ok)d.push_back(0);
       }
        ans++;
      if(rankk>n)break;
     }
    cout<<min(ans ,test() )<<endl;
   }
    re 0;
}































