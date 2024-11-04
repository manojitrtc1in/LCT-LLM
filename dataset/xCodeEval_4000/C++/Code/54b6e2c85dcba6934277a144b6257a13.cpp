#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
struct node{
    int id;
    int l,r;
}amax[maxn],amin[maxn];


int cmpmax(node a,node b)
{
    return a.r<b.r;
}

int cmpmin(node a,node b)
{
    return a.l>b.l;
}

int main()
{
    queue<int>q1,q2;
    int n;
    cin>>n;
    int cntmax=0;
    int cntmin=0;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l<r)
        {
            amin[++cntmin].l=l;
            amin[cntmin].r=r;
            amin[cntmin].id=i;
        }
        if(l>r)
        {
            amax[++cntmax].l=l;
            amax[cntmax].r=r;
            amax[cntmax].id=i;
        }
    }
    sort(amin+1,amin+1+cntmin,cmpmin);
    sort(amax+1,amax+1+cntmax,cmpmax);
    if(cntmin>=cntmax)
    {
        cout<<cntmin<<endl;
        for(int i=1;i<=cntmin;i++)
        {
            cout<<amin[i].id<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<cntmax<<endl;
        for(int i=1;i<=cntmax;i++)
        {
            cout<<amax[i].id<<" ";
        }
        cout<<endl;
    }
    return 0;
}














