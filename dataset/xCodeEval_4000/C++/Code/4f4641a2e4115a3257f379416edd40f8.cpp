









































































































































































































#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
void dfs(int x,int y);
long long a[1001][1001];
int dx[5]={0,0,0,-1,1},dy[5]={0,-1,1,0,0};
int tx,ty,lx,ly,n,m,mou=1e9,times=0,minans=1<<30,sx,sy,d;
int fa[1000*1010];
int find(int x)
{
return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
int a=find(u),b=find(v);
if(a!=b)
fa[a]=b;
}
int dis(int x,int y)
{
return abs(x-sx)+abs(y-sy);
}
int encode(int i,int j)
{
return (i-1)*m+j;
}
bool inrange(int x,int l,int r)
{
return l<=x&&x<=r;
}
int main()
{
int T;
cin>>T;
while(T--)
{
    cin>>n>>m>>sx>>sy>>d;
    int ok=0;
    bool ok1=1,ok2=1,ok3=0,ok4=0;
    for(int i=1;i<=n;i++)
    if(dis(i,1)<=d)
    ok1=0;
    for(int i=1;i<=m;i++)
    if(dis(n,i)<=d)
    ok1=0;
    for(int i=1;i<=m;i++)
    if(dis(1,i)<=d)
    ok2=0;
    for(int i=1;i<=n;i++)
    if(dis(i,m)<=d)
    ok2=0;
    if(ok1||ok2)
    ok=1;
    if(ok)
    cout<<n+m-2<<'\n';
    else
    cout<<-1<<'\n';
    }
} 

