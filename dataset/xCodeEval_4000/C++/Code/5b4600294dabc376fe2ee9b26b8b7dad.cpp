
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;
const int inf=0x3f3f3f3f;
int start;
int tail;
int head[150500],to[150500],nxt[150500],wei[150500],cost[150500],tot=1;
int dis[5050],pre[5050],pres[5050];
bool vis[5050];
queue<int>que;
int n,sum,k,m;
int used;
char str[105][105],s[505];
int v[105];

void add(int x,int y,int z,int w)
{
    tot++,to[tot]=y,nxt[tot]=head[x],head[x]=tot,cost[tot]=w,wei[tot]=z;
    tot++,to[tot]=x,nxt[tot]=head[y],head[y]=tot,cost[tot]=-w,wei[tot]=0;
}
bool spfa()
{
    memset(dis,inf,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[start]=0;
    que.push(start);
    int now;
    do{
        now=que.front();
        vis[now]=0;
        que.pop();
        for(int i=head[now];i;i=nxt[i])
        {
            if(dis[to[i]]>dis[now]+cost[i]&&wei[i])
            {
                dis[to[i]]=dis[now]+cost[i];
                pre[to[i]]=now;
                pres[to[i]]=i;
                if(!vis[to[i]])
                {
                    que.push(to[i]);
                    vis[to[i]]=1;
                }
            }
        }
    }while(!que.empty());
    return dis[tail]!=inf;
}

void f()
{
    int now=tail;
    int low=inf;
    while(now!=start)
    {
        low=min(low,wei[pres[now]]);
        now=pre[now];
    }
    used+=low*dis[tail];
    now=tail;
    while(now!=start)
    {
        wei[pres[now]]-=low;
        wei[pres[now]^1]+=low;
        now=pre[now];
    }
}

int judge(int x,int y){
	int i;
	if(x+strlen(str[y]+1)-1>n)return 0;
	for(i=1;i<=strlen(str[y]+1);i++){
		if(s[x+i-1]!=str[y][i]){
			return 0;
		}
	}
	
	return 1;
}
int main(){
	cin>>n;
	cin>>(s+1);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>(str[i]+1)>>v[i];
	}
	cin>>k;
	start=0,tail=n+1;
	for(int i=1;i<=n;i++){
		add(i-1,i,k,0);
	}
	add(n,tail,k,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(judge(i,j)){
				add(i,i+strlen(str[j]+1),1,-v[j]);
			}
		}
	}
	while(spfa()){
		

		f();
	}
	cout<<-used<<endl;
	return 0;
}

