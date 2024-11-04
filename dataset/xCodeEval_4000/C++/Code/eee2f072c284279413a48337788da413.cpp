#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAXX 1e18
void solve()


{
    int n;cin>>n;
    vector<int> a(n);
    for(int &i: a) cin>>i;
    int anss = INT_MAXX;
    int ans;
    int q;
    int prev;
    for(int i=0;i<n;i++)
    {
        ans = 0;
        prev=0;
        for(int j=i+1;j<n;j++)
        {
            q = ((prev/a[j]) + 1);
            ans+= q;
            prev = a[j]*q;
        }
        prev = 0;
        for(int j=i-1;j>=0;j--)
        {
            q = ((prev/a[j]) + 1);
            ans+=q;
            prev = a[j]*q;
        }
        anss = min(ans,anss);
    }
    cout<<anss<<endl;
}
main()
{
    int t;
    t=1;
    

    while(t--)
    {
        solve();
        

    }
    return 0;
}



