


#include <iostream>
#include <cstring>
#define ll long long
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>
#define inf 1000000000
#include <unordered_map>
#define ull unsigned long long
using namespace  std;
ll a[200005],b[100005],n,m,h,k;
map<int,int>mp;
map<int,int>::iterator it;
char s[10000];
int main()
{   char ch;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
   cin>>t;
   while(t--)
   {
     cin>>n>>m;
    ll x=0,y=0;
     ll ans=0;
     cin>>s+1;
     for(int i=1;i<=n;i++)
     {

         if(s[i]=='*')x++;
     }
     if(x==1||x==2)
     {
         cout<<x<<endl;
         continue;
     }
     for(int i=1;i<=n;i++)
     {
         if(s[i]=='*')
         {
             x=i;
             ans++;
             break;
         }
     }
     for(int i=n;i>=1;i--)
     {
         if(s[i]=='*')
         {
             y=i;
             ans++;
             break;
         }
     }
     ll pos=0,num=0;
     ll l=x+1;
     ll  r=y;
     while(l<r)
     {

         if(s[l]=='*'&&l<r)
         {
             pos=l;
             num++;
         }
         else if(s[l]!='*'&&l<r)
         {
             num++;
         }
         if(num>=m)
         {
             l=pos;
             ans++;
             num=0;
         }
         l++;
      

     }
     cout<<ans<<endl;

   }

    return 0 ;
}
