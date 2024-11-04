#include <bits/stdc++.h>
using namespace std;


int tmc;
bool good[100005];
int dep[100005],L[100005],R[100005],val[100005];
vector<int> nei[100005];
pair<int,int> rmq[300005];
int lst[2000005];
int fa[25][100005];

void dfs(int now,int depth){
	dep[now]=depth;
	L[now]=tmc;
	val[tmc++]=depth;
	for(int i:nei[now]){
		fa[0][i]=now;
		dfs(i,depth+1);
	}
	R[now]=tmc;
}

int n;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		good[i]=1;
	}
	for(int i=0;i<n;i++){
		int prv;
		scanf("%d",&prv);
		prv--;
		if(prv!=-1){
			good[i]=0;
			nei[prv].push_back(i);
		}
	}
	memset((int*)fa,-1,sizeof(fa));
	for(int i=0;i<n;i++){
		if(good[i]){
			dfs(i,0);
		}
	}
	for(int i=1;i<=20;i++){
		for(int j=0;j<n;j++){
			if(fa[i-1][j]!=-1){
				fa[i][j]=fa[i-1][fa[i-1][j]];
			}
		}
	}
	int maxv=1;
	while(maxv<n){
		maxv<<=1;
	}
	int sz=0;
	for(int i=0;i<n;i++){
		lst[++sz]=val[i];
		rmq[i+maxv].first=rmq[i+maxv].second=sz;
	}
	for(int i=maxv-1;i;i--){
		int oldsz=sz,nl=rmq[i<<1].first,nr=rmq[i<<1|1].first;
		while(nl>0&&nl<=rmq[i<<1].second&&nr>0&&nr<=rmq[i<<1|1].second){
			if(lst[nl]<lst[nr]){
				lst[++sz]=lst[nl++];
			}else{
				lst[++sz]=lst[nr++];
			}
		}
		while(nl>0&&nl<=rmq[i<<1].second){
			lst[++sz]=lst[nl++];
		}
		while(nr>0&&nr<=rmq[i<<1|1].second){
			lst[++sz]=lst[nr++];
		}
		if(oldsz<sz){
			rmq[i].first=oldsz+1;
			rmq[i].second=sz;
		}
	}
	int m;
	scanf("%d",&m);
	for(int M=0;M<m;M++){
		if(M){
			printf(" ");
		}
		int now,len;
		scanf("%d%d",&now,&len);
		now--;
		bool fl=0;
		for(int j=20;j>=0;j--){
			if((len>>j)&1){
				if(fa[j][now]==-1){
					fl=1;
					break;
				}
				now=fa[j][now];
			}
		}
		if(fl){
			printf("0");
			continue;
		}
		int ans=0,l=L[now]+maxv,r=R[now]+maxv;
		while(l<=r){
			if((l%2)&&rmq[l].first>0){
				int gl=-1,cl=rmq[l].first,cr=rmq[l].second;
				while(cl<=cr){
					int m=(cl+cr)>>1;
					if(lst[m]==dep[now]+len){
						gl=m;
						cr=m-1;
						continue;
					}
					if(lst[m]<dep[now]+len){
						cl=m+1;
					}else{
						cr=m-1;
					}
				}
				if(gl!=-1){
					int gr=gl;
					cl=gl+1,cr=rmq[l].second;
					while(cl<=cr){
						int m=(cl+cr)>>1;
						if(lst[m]==dep[now]+len){
							gr=m;
							cl=m+1;
						}else{
							cr=m-1;
						}
					}
					ans+=gr-gl+1;
				}
			}
			l=(l+1)>>1;
			if(!(r%2)&&rmq[r].first>0){
				int gl=-1,cl=rmq[r].first,cr=rmq[r].second;
				while(cl<=cr){
					int m=(cl+cr)>>1;
					if(lst[m]==dep[now]+len){
						gl=m;
						cr=m-1;
						continue;
					}
					if(lst[m]<dep[now]+len){
						cl=m+1;
					}else{
						cr=m-1;
					}
				}
				if(gl!=-1){
					int gr=gl;
					cl=gl+1,cr=rmq[r].second;
					while(cl<=cr){
						int m=(cl+cr)>>1;
						if(lst[m]==dep[now]+len){
							gr=m;
							cl=m+1;
						}else{
							cr=m-1;
						}
					}
					ans+=gr-gl+1;
				}
			}
			r=(r-1)/2;
		}
		printf("%d",ans-1);
	}
	return 0;
}