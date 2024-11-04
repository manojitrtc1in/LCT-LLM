
 
#include "bits/stdc++.h"
using namespace std;
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int long long
#define pb push_back
#define vi vector<int>
#define pb push_back
#define mli map<int, int>
#define mk(arr, n, type) type *arr = new type[n];
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define suma accumulate
#define input(x)     \
    for (int &a : x) \
        cin >> a;
#define us unordered_set<int>
#define ins insert
 
#define REP(i, a, b) for (int i = a; i >= b; i--)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repe(i, a, b) for (int i = a; i < = b; i++)
#define repwi(i, a, b) for (i = a; i < b; i++)
 
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
    
int n=10000;
int si[10000]={0};
void sieve()
{
    int f;
    for(int i=2;i<=n;i++)
    {
         f=0;
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                f=1;
                break;
            }
        }
         if(f==0)
         si[i]=1;
    }
   
}
bool prime(int n)
{
    if(n==1)
    return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}

int32_t main()
{
     FIO
#ifndef ONLINE_JUDGE
        freopen(fi, "r", stdin);
    freopen(fo, "w", stdout);
#else


#endif
    w(t)
    {
        int n,m,mi=0,ma=0;
        cin>>n>>m;
        vi v(n);
        for(int &a:v)
        {
            cin>>a;
            mi+=a;
            ma+=(ceil(a/(double(m))));
        }
        mi=ceil(mi/(double(m)));
        cout<<mi<<" "<<ma<<'\n';
    }
    cerr << "processor time: " << clock() / (double)CLOCKS_PER_SEC << "s    ";
}