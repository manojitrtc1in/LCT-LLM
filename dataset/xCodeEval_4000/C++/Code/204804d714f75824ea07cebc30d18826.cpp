
#include <bits/stdc++.h>
#define int  long long
#define vi   vector<int>
#define pii  pair<int,int>
#define pss  pair<string,string>
#define psi  pair<string,int>
#define vpii  vector<pair<int,int> >
#define vpss  vector<pair<string,string> >
#define vpsi  vector<pair<string,int> >
#define pb   push_back
#define mp   make_pair
#define ff   first
#define ss   second
#define fast  ios::sync_with_stdio(false); cin.tie(NULL);
#define f(i,a,b)  for(int i=a;i<=b;i++)
#define rf(i,a,b)  for(int i=a;i>=b;i--)
#define out(v,n)   f(i,0,n-1)cout<<v[i]<<" ";cout<<endl;
#define in(v,n)   f(i,0,n-1)cin>>v[i];
#define endl  "\n"
#define mod   1000000007


using namespace std;


signed main()
{
    

    fast
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        map<int,int>m;
        vi v(n);
        for(int i=0;i<n;i++){cin>>v[i]; m[v[i]%3]++;}
        int ans=m[0];
        int t=min(m[1],m[2]);
        ans+=t;
        m[1]=m[1]-t;
        m[2]=m[2]-t;
        ans+=(m[1]/3);
        ans+=(m[2]/3);
        cout<<ans<<endl;
        
    }
}
