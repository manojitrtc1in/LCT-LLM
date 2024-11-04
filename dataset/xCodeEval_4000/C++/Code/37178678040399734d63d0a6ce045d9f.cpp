




























































































































































































#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int a[maxn],b[maxn];
char s[maxn];
int n,m;
int table[maxn];
vector<int>v[maxn];
struct colums{
	int index;
	vector<int>*it;
}it[maxn],pre[maxn];
int cmp(colums a,colums b){
	for(auto ita=(*a.it).begin(),itb=(*b.it).begin();ita!=(*a.it).end();ita++,itb++){
		

		if(*ita==*itb){
			continue;
		}
		return *ita<*itb;
	}
	return a.index<b.index;
}
void solve(){
	scanf("%d %d",&n,&m);
	int x;
	for(int i=1;i<=m;i++){
		vector<int>().swap(v[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&x);	
			v[j].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		it[i].it=v+i;
		it[i].index=i;
	}










	for(int i=1;i<=m;i++){
		pre[i]=it[i];
	}
	sort(it+1,it+1+m,cmp);
	int p=0,q=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<m;j++){
			if((*it[j].it)[i]>(*it[j+1].it)[i]){
				puts("-1");
				return ;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(memcmp((void *)&(*it[i].it)[0],(void *)&(*pre[i].it)[0],sizeof(int)*n)){
			if(!p){
				p=i;
			}
			else if(!q){
				q=i;
			}
			else{
				puts("-1");
				return ;
			}
		}
	}
	if(p&&q){
		printf("%d %d\n",p,q);
	}
	else{
		puts("1 1");
	}
}
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("1.in","r",stdin);
	#endif
	int t=1;
	cin>>t;
	while(t--)solve();
		
	
	
	return 0;
}