


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
    long long int n,i,j,k,anss,m,o;

    string s;
    cin>>n;

    


    


    


    pair<long long int,long long int> ar[n];
    long long int ans[n]={0},count=0,check[n+1]={0};
    for(i=0;i<n;i++)
        cin>>ar[i].first;
    for(i=0;i<n;i++)
    {
        cin>>ar[i].second;

        if(ar[i].first==ar[i].second)
        {
            count++;
            ans[i]=ar[i].first;
            check[ar[i].first]=1;
        }
    }

    if(count==n-1)
    {
        for(i=1;i<=n;i++)
        {
            if(check[i]==0)
            {
                for(j=0;j<n;j++)
                {
                    if(ans[j]==0)
                        ans[j]=i;
                }
            }
        }
    }

    long long int a=-1,b=-1;
    if(count==n-2)
    {
        bool one=1,two=1,out=1;
        

        for(i=1;i<=n;i++)
        {
            if(check[i]==0)
            {
                for(j=0;j<n;j++)
                {
                    if(ar[j].first==i && check[ar[j].first]==0 && ans[j]==0)
                    {
                        if(a==-1)
                            a=j;
                        else
                            b=j;
                        ans[j]=ar[j].first;
                        check[ar[j].first]=1;
                        

                    }
                    else if(ar[j].second==i && check[ar[j].second]==0 && ans[j]==0)
                    {
                        if(a==-1)
                            a=j;
                        else
                            b=j;
                        ans[j]=ar[j].second;
                        check[ar[j].second]=1;
                    }
                }
            }
        }
    }

    long long int c1=0,c2=0;

    


    

    

    


    for(i=0;i<n;i++)
    {
        if(ans[i]==0)
        {
            for(j=1;j<=n;j++)
            {
                

                if(check[j]==0)
                {
                    if(a==-1)
                        a=i;
                    else
                        b=i;
                    ans[i]=j;
                    check[j]=1;
                }
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(ans[i]!=ar[i].first)
            c1++;
        if(ans[i]!=ar[i].second)
            c2++;
    }

    if(a>-1 && b>-1)
    {
        if(c1>1||c2>1)
            swap(ans[a],ans[b]);
    }

    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";




    

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
