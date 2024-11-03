

#include <bits/stdc++.h>
#define BIT(x, i) ((x) & MASK(i)) 

#define SET_ON(x, i) ((x) | MASK(i)) 

#define SET_OFF(x, i) ((x) & ~MASK(i)) 

#define int long long
#define fi first
#define se second
#define ii pair<int ,int>
using namespace std;
const int MAXN=1e6+7;
const int INF=1e9+7;


int a[MAXN];


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   

   

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cur=1;
        if(n==1){cout<<1<<"\n";}
    else{
        for(int i=1;i<=n;i++)
        {
            cur+=1;
            cout<<cur<<" ";
        }
    }
    cout<<endl;
    }

    return 0;
}

