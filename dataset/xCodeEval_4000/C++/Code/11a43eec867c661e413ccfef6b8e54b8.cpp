
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+10;



int mp[N],mp1[N],mp2[N];

int h[N];
int id[N],n,rank_f[N];
void init()
{


    for (int i = 1; i <= n; i++)
    {
        id[i] = i;
        

    }
}
int find_d(int x)
{
    if(x == id[x])
        return x;
    else
    {
        id[x] = find_d(id[x]);  

        return id[x];         

    }
}













































void unionNode(int p, int q)      

{
    id[find_d(p)]=find_d(q);

}



























bool connecte(int p, int q)
{
    

    return find_d(p) == find_d(q);
}


int m;
int c[50005]; 

int lowbit(int x)
{
    return x&(-x);
}
void updata(int i,int k)     

{
    while(i <n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}
int getsum(int i)         

{
    int res = 0;
    while(i >=0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}



























const int NN=3e5+10;
int sum1[NN],sum2[NN],t[NN],a[NN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k;
        cin>>n>>k;
        int sum1[n+10];
        int sum2[n+10];
        int t[k];
        for(int i=0; i<=n+1; i++)
            sum1[i]=sum2[i]=2e9;
        for(int i=1; i<=k; i++)
            cin>>a[i];
        for(int i=1; i<=k; i++)
            cin>>t[i],sum1[a[i]]=t[i]+a[i],sum2[a[i]]=t[i]-a[i];
        for(int i=n; i>=1; i--)
            sum1[i]=min(sum1[i+1],sum1[i]);
        for(int i=1; i<=n; i++)
            sum2[i]=min(sum2[i-1],sum2[i]);
        for(int i=1; i<=n; i++)
           cout<<min(sum1[i]-i,sum2[i]+i)<<' ';
        puts("");
    }}
