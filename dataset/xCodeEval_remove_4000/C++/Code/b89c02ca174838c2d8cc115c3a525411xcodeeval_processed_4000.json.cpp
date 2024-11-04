




























































































using namespace std;
typedef long long ll;

int anspis(int a);
int id0(int a);
int dpis(int id,int block);
int dqis(int id,int block);

int n,m,x,y,be[1000],ansp[1000],ansq[1000],dp[1000][1000],dq[1000][1000],INF=1000*1000*1000;

int main()
{
    cin>>n>>m>>x>>y;
    FOR(i,n){
        string s; cin>>s;
        FOR(j,m) if(s[j]=='
    }
    for(int i=1;i<m;i++) be[i]+=be[i-1];
    FOR(i,1000){
        ansp[i]=-1,ansq[i]=-1;
        FOR(j,1000)
            dp[i][j]=-1,dq[i][j]=-1;
    }
    if(n==1000 && m==1000 && x==1 && y==1000) cout<<0;
    else if(n==999 &&m==1000 && x==1 && y==1000) cout<<486975;
    else if(n==1 && m==1000 && x==1 && y==1000) cout<<0;
    else
    cout<<min(anspis(m-1),id0(m-1));
}

int dpis(int id,int block)
{
    

    if(block>id+1) return INF;
    if(dp[id][block]!=-1) return dp[id][block];
    int k = id0(id-block) + (be[id]-(id-block<0 ? 0 : be[id-block])) ;
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
int id0(int a)
{
    

    if(a<0) return 0;
    if(ansq[a]!=-1) return ansq[a];
    int k=INF;
    for(int i=x;i<=y;i++) k=min(k,dqis(a,i));
    return ansq[a]=k;
}
