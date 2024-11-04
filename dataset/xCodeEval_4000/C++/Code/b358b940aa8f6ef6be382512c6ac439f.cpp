
#include <bits/stdc++.h>
#include <array>
#include <hash_map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#pragma GCC optimize("Ofast")
using ll=long long;
using lli=long long int;
using ld=long double;
using ull=unsigned long long;
#define      fi         first
#define      se         second
#define      FAST       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define      all(a)     a.begin(),a.end()
#define      nl         cout<<'\n'
#define      len(s)     (long long)s.size()
#define      pb         push_back
#define      vll        vector <long long>
#define      cinv(a,n)  for (int i=0;i<n;i++) {cin>>a[i];}
#define      cinq(a,n)  for (int i=1;i<=n;i++) {cin>>a[i];}
#define      cot(a,n)   for (int i=0;i<n;i++) {cout<<a[i]<<' ';}
#define      fix(x,y)   fixed<<setprecision(y)<<x<<'\n';
const ll mod=998244353;
const ll MAX=LONG_LONG_MAX;
const ll MIN=LONG_LONG_MIN;
const int as=2;
using namespace std;
int search(int c,int le,int a[])
{
   int l=0,r=le-1,m=0;
   while (l<=r)
   {
        m=l+(r-l)/2;
       if (a[m]==c)
       {
           return m;
       }
       else
        if (a[m]<c)
       {
           l=m+1;
       }
       else
       {
           r=m-1;
       }
   }
   return m;
}
void Solve()
{
    ll n;
    cin>>n;
    string s,q;
    cin>>s;
    q=s;
    ll y=0;
    sort(all(q));
    for (ll i=0;i<n;i++)
    {
        if (s[i]!=q[i])
            y++;
    }
    cout<<y<<'\n';
}
int main()
{
    FAST;
    ll tt;
    cin>>tt;
    while (tt-->0)
    {
        Solve();
    }

}


