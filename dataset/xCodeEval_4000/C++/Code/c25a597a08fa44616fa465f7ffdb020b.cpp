




















































































#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#include <stdio.h>
#define FOR(i,n) for(int i=0; i<n; i++)
#include <string>

using namespace std;
typedef long long ll;

int anspis(int a);
int ansqis(int a);
int dpis(int id,int block);
int dqis(int id,int block);

int n,m,x,y,be[1010],ansp[1010],ansq[1010],dp[1010][1010],dq[1010][1010],INF=1000*1000*1000;

int main()
{
    cin>>n>>m>>x>>y;
    FOR(i,n){
        string s; cin>>s;
        FOR(j,m) if(s[j]=='#') be[j]++;
    }
    for(int i=1;i<m;i++) be[i]+=be[i-1];
    FOR(i,1010){
        ansp[i]=-1,ansq[i]=-1;
        FOR(j,1010)
            dp[i][j]=-1,dq[i][j]=-1;
    }
    
    cout<<min(anspis(m-1),ansqis(m-1));
}

int dpis(int id,int block)
{
    

    if(block>id+1) return INF;
    if(dp[id][block]!=-1) return dp[id][block];
    int k = ansqis(id-block) + (be[id]-(id-block<0 ? 0 : be[id-block])) ;
    return dp[id][block]=k;
}
int dqis(int id,int block)
{
    

    if(block>id+1) return INF;
    if(dq[id][block]!=-1) return dq[id][block];
    int k = anspis(id-block) + (block)*n-(be[id]-(id-block<0 ? 0 : be[id-block])) ;
    return dq[id][block]=k;
}
int anspis(int a)
{
    

    if(a<0) return 0;
    if(ansp[a]!=-1) return ansp[a];
    int k=INF;
    for(int i=x;i<=y;i++) k=min(k,dpis(a,i));
    return ansp[a]=k;
}
int ansqis(int a)
{
    

    if(a<0) return 0;
    if(ansq[a]!=-1) return ansq[a];
    int k=INF;
    for(int i=x;i<=y;i++) k=min(k,dqis(a,i));
    return ansq[a]=k;
}
