


#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx,avx2,fma")


#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


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


long long po(long long n){
    long long z=1;
    while(n){
        n--;
        z*=2;
    }
    return z;
}


void solve()
{
    long long int n,i,j,k,ans,m,o;

    string s;
    cin>>n;

    


    


    


    long long int f;
    cin>>f;

    pair<long long int,long long int> ar[n],br[n],cr[n];
    

    for(i=0;i<n;i++)
    {
        cin>>ar[i].first;
        cin>>ar[i].second;
        br[i].first=2*ar[i].first;
        br[i].second=ar[i].second;
        cr[i].first=min(br[i].first,br[i].second)-min(ar[i].first,ar[i].second);
        cr[i].second=i;
    }

    
    sort(cr,cr+n);
    reverse(cr,cr+n);
    ans=0;
    long long int visited[n+1]={0};
    
    for(i=0;i<f;i++)
    {
        

        

        ans+=cr[i].first;
        visited[cr[i].second]=1;
    }

    for(i=0;i<n;i++)
    {
        

        {
            ans+=min(ar[i].first,ar[i].second);
        }
    }

    cout<<ans;

    

    return;



    






}





int main()
{
    fast();
    sample();
    long long int i, j, k, n, m, a, b, c, d, p, q, r, l, t = 1;
    long long int sum, count = 0, ans = 0;

    

    while (t--)
    {
        solve();

    }

    return 0;
}
