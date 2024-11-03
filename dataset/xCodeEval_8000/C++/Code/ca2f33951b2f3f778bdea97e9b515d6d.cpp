#include<bits/stdc++.h>
using namespace std;



const int MAXN=1010,MAXM=1010;
char a[MAXN][MAXM];
vector<int> g[MAXN+MAXM];
int d[MAXN+MAXM];
int m,n;
queue<int> q;

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) {
			cin>>a[i][j];
			if (a[i][j]=='#') {
				g[i].push_back(n+j);
				g[n+j].push_back(i); 
			}
		}
	memset(d,-1,sizeof(d));


	d[1]=0;
	q.push(1);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		if (x==n){
			break;
		}
		for (int i=0;i<g[x].size();i++){
			if (d[g[x][i]]==-1){
				d[g[x][i]]=d[x]+1;
				q.push(g[x][i]);
			}
		}
	}


	cout<<d[n];
	return 0;
}
