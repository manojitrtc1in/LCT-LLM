


#include <bits/stdc++.h>
using namespace std;




void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void sample()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
long long int* read(long long int n)
{
    long long int* arr=new long long int[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    return arr;
}




void solve()
{
    long long int n,i,j,k,ans,m,o;

    cin>>n;

    long long int ar[n];

    


    


    unordered_map<long long int,long long int>mp;

    for(i=0;i<n;i++)
    {
        long long int count=0;
        cin>>ar[i];
        while(ar[i])
        {
            if(ar[i]&1)
                count++;
            ar[i]>>=1;
        }
        mp[count]++;
    }

    ans=0;

    for(auto i:mp)
    {
        

        ans+=((i.second)*(i.second-1)/2);
    }

    cout<<ans;


    return ;
    

    


}





int main()
{
    fast();
    

    long long int i, j, k, n, m, a, b, c, d, p, q, r, l, t = 1;
    long long int sum, count = 0, ans = 0;

    

    while (t--)
    {
        solve();

    }

    return 0;
}
