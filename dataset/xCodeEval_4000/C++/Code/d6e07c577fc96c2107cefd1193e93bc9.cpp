#include<bits/stdc++.h>
using namespace std;
const int N=21005;
typedef long long ll;
#define il inline 
ll mod=998244353ll;
ll base=70134ll;
struct node{
	ll hush;
	int nody;

}; 
int n,q;
int hed[N],tal[N<<1],nxt[N<<1],cnt=0;
char val[N<<1];

char c[2];
int dep[N];

int father[N];

ll hush_rt[N],hush_po[N];

ll hus[N];

int isrt[N];

vector<int> rtt[20];

int son[N],size[N];

bool used[N];

int pointy;
int maxn;
vector<int> trie[N][30];

vector<vector<int> > va[N];

int nod[N]={0};

vector<int> final[N];

vector<int> init;
vector<vector<node> > discont[N];

bool operator <(node x,node y){
	return x.hush<y.hush; 
}
int jump[N][20];

ll hush1[N][20];

ll hush2[N][20]; 
int QX,QY,QLCA,QCAL,QLEN;

int bel[N][20];

int b[N][20];

vector<int> nexty[N];

vector<int> str[N];

int SIZE[N];

int Count=0; 
int ANS=0;
int id[N]; 
int dis[N];
int indexy[N];
int zzzzz=0;
int maxnnnn;
vector<node> inint; 
vector<int> maxn_sub[N];

vector<vector<int> > noe[N];

il void addege(int x,int y,char z){
	cnt++;
	tal[cnt]=y;
	val[cnt]=z;
	nxt[cnt]=hed[x];
	hed[x]=cnt;
}
il void dfs(int u,int fa){
	jump[u][0]=fa;
	for(int i=hed[u];i;i=nxt[i]){
		int v=tal[i];
		if(v==fa)  continue;
		dep[v]=dep[u]+1;
		ll va=(val[i]-'a'+1);
		hush1[v][0]=va;
		hush2[v][0]=va;
		hush_rt[v]=(hush_rt[u]*base+va)%mod;
		hush_po[v]=(hush_po[u]+(va*hus[dep[v]-2]%mod))%mod;
		dfs(v,u);
	}
} 
il void find(int u,int fa){
	size[u]=1;
	maxn++;
	for(int i=hed[u];i;i=nxt[i]){
		int v=tal[i];
		if(v==fa||used[v]) continue;
		find(v,u);
		size[u]+=size[v];
		son[u]=max(son[u],size[v]);
	}	
} 
il void add(int u,int fa){
	son[u]=max(son[u],maxn-size[u]);
	if(son[u]<son[pointy]) pointy=u;
	for(int i=hed[u];i;i=nxt[i]){
		int v=tal[i];
		if(v==fa||used[v]) continue;
		add(v,u);
	}	
} 
il void clear(int u,int fa){
	size[u]=0;
	son[u]=0;
	for(int i=hed[u];i;i=nxt[i]){
		int v=tal[i];
		if(v==fa||used[v]) continue;
		clear(v,u);
	}
}
il void findp(int v){

	pointy=0;
	clear(v,v);

	maxn=0;
	pointy=0;
	find(v,v);
	add(v,v);
} 
il void dfs_modify1(int step,int u,int fa,int val,int noddd){
	

	bel[u][step]=val;
	b[u][step]=noddd;
	for(int i=hed[u];i;i=nxt[i]){
		int v=tal[i];
		if(v==fa||used[v]) continue;
		dfs_modify1(step,v,u,val,noddd);
	}
}
il void dfs_modify2(int step,int u,int fa,int val){
	

	bel[u][step]=val;
	for(int i=hed[u];i;i=nxt[i]){
		int v=tal[i];
		if(v==fa||used[v]) continue;
		dfs_modify2(step,v,u,val);
	}
}
il void split(int exroot,int depth){
	clear(exroot,exroot);
	findp(exroot);
	int rt=pointy;
	isrt[rt]=depth;
	rtt[depth].push_back(rt);
	int dd=pointy;
	SIZE[rt]=maxn; 
	b[rt][depth]=rt;
	int ppt=0;
	dfs_modify1(depth,exroot,exroot,0,dd);
	used[rt]=1;
	bel[rt][depth]=0;
	noe[rt].push_back(init);
	for(int i=hed[rt];i;i=nxt[i]){
		int v=tal[i];
		if(used[v]) continue;
		findp(v);
		nexty[dd].push_back(pointy);
		++ppt;
		id[pointy]=ppt;
		dis[pointy]=val[i]-'a'+1;
		indexy[pointy]=v; 
		dfs_modify2(depth,v,v,ppt);
		noe[rt].push_back(init);
		split(v,depth+1);
	}
}
il void dfs_str(int u,int fa,int RT,int pos){
	for(int i=hed[u];i;i=nxt[i]){
		int v=tal[i];
		if(v==fa||used[v]) continue;
		if(!trie[RT][val[i]-'a'][pos-1]){
			nod[RT]++;
			va[RT].push_back(init);
			va[RT][nod[RT]-1].push_back(v);
			trie[RT][val[i]-'a'][pos-1]=nod[RT];
			for(int k=0;k<=25;k++) trie[RT][k].push_back(0);
			str[RT].push_back(0);
			maxn_sub[RT].push_back(0);
			dfs_str(v,u,RT,nod[RT]);
		}
		else{
			va[RT][trie[RT][val[i]-'a'][pos-1]-1].push_back(v);
			dfs_str(v,u,RT,trie[RT][val[i]-'a'][pos-1]);
		}
	}
}
il void make_Trie(){
	for(int i=1;i<=16;i++){
		for(int j=0;j<rtt[i].size();j++){
			int RT=rtt[i][j];
			nod[RT]=1;
			
			va[RT].push_back(init);
			str[RT].push_back(0);
			maxn_sub[RT].push_back(0);
			va[RT][0].push_back(RT); 
			for(int k=0;k<=25;k++) trie[RT][k].push_back(0);
			dfs_str(RT,RT,RT,1);
			used[RT]=1;
		}
	}
}
il void dfs_first(int RT,int u,int depth){
	
	maxnnnn=max(maxnnnn,depth);
	for(int i=0;i<=25;i++){
		if(!trie[RT][i][u-1]) continue;
		dfs_first(RT,trie[RT][i][u-1],depth+1);
	}
}
il void dfs_cal(int RT,int u,int depth,ll hushi,int len){
	zzzzz=max(zzzzz,len);
	for(int i=0;i<va[RT][u-1].size();i++){
		final[RT].push_back(va[RT][u-1][i]);
		noe[RT][bel[va[RT][u-1][i]][depth]].push_back(final[RT].size());
		Count++;
		discont[RT][len].push_back((node){hushi,u});
	}
	str[RT][u-1]=Count;
	maxn_sub[RT][u-1]=Count;
	for(int i=0;i<=25;i++){ 
		if(!trie[RT][i][u-1]) continue;
		dfs_cal(RT,trie[RT][i][u-1],depth,(hushi*base%mod)+(i+1)%mod,len+1); 
		maxn_sub[RT][u-1]=max(maxn_sub[RT][u-1],maxn_sub[RT][trie[RT][i][u-1]-1]);
	}
} 
il void dfs_second(int RT,int u,int value){
	int sum=0;
	for(int i=0;i<=25;i++){
		if(!trie[RT][i][u-1]) continue;
		dfs_second(RT,trie[RT][i][u-1],sum);
	}
}
il void sorty(){
	for(int i=1;i<=16;i++){
		for(int j=0;j<rtt[i].size();j++){
			
			int RT=rtt[i][j];
		

		

			maxnnnn=0;
			dfs_first(RT,1,0);
			for(int k=0;k<=maxnnnn;k++) discont[RT].push_back(inint);
			
			

			Count=0;
			zzzzz=0;
			dfs_cal(RT,1,i,0ll,0);
			
			for(int k=0;k<=zzzzz;k++){
				sort(discont[RT][k].begin(),discont[RT][k].end());
			}
			dfs_second(RT,1,0);
			
		}
	}
}
il int LCA(int x,int y){

	if(dep[x]>dep[y]) swap(x,y);
	for(int i=16;i>=0;i--) if(dep[jump[y][i]]>=dep[x]) y=jump[y][i];
	if(x==y) return x;
	for(int i=16;i>=0;i--) if(jump[x][i]!=jump[y][i]) x=jump[x][i],y=jump[y][i];
	x=jump[x][0];
	return x;
}
il ll hushjump1(int x,int y){
	if(x==y) return 0;
	ll sum=0ll;
	for(int i=16;i>=0;i--) if(dep[jump[x][i]]>dep[y]) sum=((sum*hus[1<<i]%mod)+hush1[x][i])%mod,x=jump[x][i];
	sum=((sum*hus[1<<0]%mod)+hush1[x][0])%mod;
	return sum;
}
il ll hushjump2(int x,int y){
	if(x==y) return 0;
	ll sum=0ll,cont=0;
	for(int i=16;i>=0;i--) if(dep[jump[y][i]]>dep[x]) sum=((hush2[y][i]*hus[cont]%mod)+sum)%mod,cont+=1ll<<i,y=jump[y][i];
	sum=((hush2[y][0]*hus[cont]%mod)+sum)%mod,cont+=1ll<<0,y=jump[y][0];
	return sum;
}
il int calcnum(int x,int y){
	if(x==y) return 0;
	int sum=0;
	for(int i=16;i>=0;i--){
		if(dep[jump[x][i]]>dep[y]){
			sum+=(1<<i);
			x=jump[x][i];
		}
	}
	sum++;
	return sum;
} 
il ll hushit(int x,int y){

	if(x==y) return 0;
	ll sum=0;
	int lca=LCA(x,y);
	

	sum=hushjump1(x,lca);
	sum=((sum*hus[calcnum(y,lca)]%mod)+hushjump2(lca,y))%mod;
	return sum;
}
il int que(int x,int y,int l){
	if(l==0) return x;
	l--;
	for(int i=16;i>=0;i--) if(l&(1<<i)) x=jump[x][i];
	return jump[x][0];
} 
il int jump_it(int x,int y,int lca,int l,int len,int cal){
	if(l>len) return y;
	if(cal>=l) return que(x,lca,l);
	else return que(y,lca,len-l);
} 
il int lcp(int x_1,int y_1,int x_2,int y_2,int LCA1,int LCA2,int len1,int len2,int cal1,int cal2){
	int l=1,r=min(len1,len2),ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		int d_1=jump_it(x_1,y_1,LCA1,mid,len1,cal1);
		int d_2=jump_it(x_2,y_2,LCA2,mid,len2,cal2);
		if(hushit(x_1,d_1)==hushit(x_2,d_2)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
il int query1(int x,int y,int l){
	l--;
	for(int i=16;i>=0;i--) if(l&(1<<i)) x=jump[x][i];
	return hush1[x][0];
} 
il int ask(int x,int y,int l,int lca,int len){
	if(calcnum(x,lca)>=l) return query1(x,lca,l);
	else return query1(y,lca,len-l+1); 
} 
il int fc(int x_1,int y_1,int x_2,int y_2){

	int LCA1=LCA(x_1,y_1),LCA2=LCA(x_2,y_2);
	int len1=calcnum(x_1,LCA1)+calcnum(y_1,LCA1); 
	int len2=calcnum(x_2,LCA2)+calcnum(y_2,LCA2);
	int l=lcp(x_1,y_1,x_2,y_2,LCA1,LCA2,len1,len2,calcnum(x_1,LCA1),calcnum(x_2,LCA2));
	int aa,bb;
	if(len1==l) aa=-1;
	else aa=ask(x_1,y_1,l+1,LCA1,len1);

	if(len2==l) bb=-1;
	else bb=ask(x_2,y_2,l+1,LCA2,len2);
	if(l==len2&&len1==len2) return 3;

	else if(l==len2) return 2;

	else if(aa>bb) return 1;

	else return -1;

}
il void dfs_ans(int step){

	

	if(!b[QX][step]) return;
	

	int C=b[QX][step];
	int flag=fc(QX,QY,QX,C);

	int delta=0;
	

	

	if(flag==-1){

		delta=0;
	}
	else if(flag==1&&QX!=C){

	

		

		delta=SIZE[C];
		if(b[QX][step+1]) delta-=SIZE[b[QX][step+1]];

	}
	else{

		

		

		int T=LCA(QX,C);
		int len=calcnum(QX,T)+calcnum(C,T);

		int W=jump_it(QX,QY,QLCA,len,QLEN,QCAL);
		int EXW=jump_it(QX,QY,QLCA,len+1,QLEN,QCAL);
		int EEXW=jump_it(QX,QY,QLCA,len+2,QLEN,QCAL);
		

		

		
		int l=0,r=discont[C].size()-1,ans=0,hhh=0;

		while(l<=r){

			int mid=(l+r)>>1;
			

			int RL=jump_it(QX,QY,QLCA,len+mid,QLEN,QCAL);

			ll HUSH=hushit(W,RL);

			int exhus=0;
			int L=0,R=discont[C][mid].size()-1,AS=-1;

			while(L<=R){

				int MID=(L+R)>>1;
				if(discont[C][mid][MID].hush>HUSH) R=MID-1;
				else if(discont[C][mid][MID].hush<HUSH) L=MID+1;
				else{
					AS=discont[C][mid][MID].nody,exhus=discont[C][mid][MID].nody,L=MID+1;
				}
			} 
			if(AS==-1) r=mid-1;
			else{
				ans=mid,hhh=exhus,l=mid+1;
			}
		}
	

		int ddd=0;
		if(ans==QLEN-len){
			if(hhh<=str[C].size()) ddd=str[C][hhh-1];
			ddd-=va[C][hhh-1].size();
		}
		else{
			int DDA=jump_it(QX,QY,QLCA,len+ans,QLEN,QCAL);
			int DDB=jump_it(QX,QY,QLCA,len+ans+1,QLEN,QCAL);
			int s=hushit(DDA,DDB);
			

			

			if(hhh<=str[C].size()) ddd=str[C][hhh-1];
			for(int i=0;i<26;i++){
				

				if(hhh>trie[C][i].size()) continue;
				if(trie[C][i][hhh-1]<=0) continue;
				if(i+1>=s) break;
				int p=trie[C][i][hhh-1];
				if(trie[C][i][hhh-1]<=maxn_sub[C].size()){
					if(maxn_sub[C][trie[C][i][hhh-1]-1]>ddd){
						ddd=maxn_sub[C][trie[C][i][hhh-1]-1];
					}
				}
			}
		}
		

		

		

		

		

		delta+=ddd;

		

		

		if(b[QX][step+1]!=0){
			int zdelta=0;
			int da=hushit(W,EXW);
			int db=dis[b[QX][step+1]];
			

			

			if(da<db) zdelta+=0;
			else if(da>db){
			

				zdelta+=SIZE[b[QX][step+1]];
			}
			else{
				int ctt=ddd;

				int col=bel[QX][step];

				l=1,r=noe[C][col].size(),ans=r+1;
			

				while(l<=r){
					int mid=(l+r)>>1;	
				

					if(noe[C][col][mid-1]>ctt) ans=mid,r=mid-1;
					else l=mid+1;
				}
				zdelta+=ans-1;
			}
			

			delta-=zdelta;
		}	
		

		

	}
	
	ANS+=delta;
	dfs_ans(step+1);
}
void Check1(){
	for(int i=1;i<=n;i++) cout<<hush_rt[i]<<" "<<hush_po[i]<<endl;
}
void Check2(){
	for(int i=1;i<=3;i++){
		cout<<"depth: "<<i<<",roots:";
		for(int j=0;j<rtt[i].size();j++){
			cout<<rtt[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Check3(){
	for(int i=1;i<=16;i++){
		for(int j=0;j<rtt[i].size();j++){
			int RT=rtt[i][j];
			cout<<"Now the root is: "<<RT<<endl;
			cout<<nod[RT]<<endl;
		}
	}
}
void Check4(){
	for(int i=1;i<=16;i++){
		for(int j=0;j<rtt[i].size();j++){
			int RT=rtt[i][j];
			cout<<"Now the root is: "<<RT<<endl;
			for(int k=0;k<final[RT].size();k++) cout<<final[RT][k]<<" ";
			cout<<endl;
		}
	}
}
void Check5(){
	cout<<hushit(3,8)<<endl;
	cout<<hushit(1,4)<<endl;
}
void Check6(){
	for(int i=1;i<=n;i++){
		cout<<SIZE[i]<<endl;
		for(int j=0;j<nexty[i].size();j++) cout<<nexty[i][j]<<" *";
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<bel[i][1]<<" && ";
	cout<<endl;
}
void Check7(){








	cout<<hushit(4,1)<<" QYJ"<<endl;
	cout<<hushit(8,3)<<" YZH"<<endl;
	cout<<lcp(4,1,8,2,1,3,2,3,2,2)<<" &#@*&"<<endl;
	cout<<fc(6,7,4,1)<<"   2018070134"<<endl; 
}
void WholeCheck(){
	
	
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			printf("depth:%d,i:%d,val:%d\n",i,j,bel[j][i]);
		}
	}
}
void Check8(){
	for(int i=1;i<=n;i++) cout<<discont[i].size()<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<discont[i].size();j++){
			for(int k=0;k<discont[i][j].size();k++){
				printf("RT:%d,depth:%d,value:%lld\n",i,j,discont[i][j][k].hush);
			} 
		}
	}
}
void Check9(){
	for(int i=1;i<=n;i++) cout<<discont[i].size()<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<str[i].size();j++) cout<<i<<" ** "<<j<<" ** "<<str[i][j]<<endl;
	}
}
int main(){
	

	memset(b,0,sizeof(b));
	inint.clear();
	init.clear();
	son[0]=2147483647;
	memset(used,0,sizeof(used));
	scanf("%d%d",&n,&q);
	hus[0]=1ll;
	for(int i=1;i<=n;i++) hus[i]=(hus[i-1]*base)%mod;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%s",c);
		addege(x,y,c[0]);
		addege(y,x,c[0]); 
	}
	hush_po[1]=0ll;
	hush_rt[1]=0ll;
	dep[1]=1;
	dfs(1,1);
	for(int i=1;i<=16;i++){
		for(int j=1;j<=n;j++){
			jump[j][i]=jump[jump[j][i-1]][i-1];
			hush1[j][i]=((hush1[j][i-1]*hus[1<<(i-1)]%mod)+(hush1[jump[j][i-1]][i-1]))%mod;
			hush2[j][i]=((hush2[jump[j][i-1]][i-1]*hus[1<<(i-1)]%mod)+(hush2[j][i-1]))%mod;
		}
	}
	

	memset(used,0,sizeof(used));
	split(1,1);

	

	memset(used,0,sizeof(used));
	

	

	make_Trie();

	
	

	

	

	

	

	
	sorty();

	

	

	

	

	

	

	



	int lx,ly,lans;
	for(int PPP=1;PPP<=q;PPP++){

		scanf("%d%d",&QX,&QY);
		QLCA=LCA(QX,QY);
		QCAL=calcnum(QX,QLCA);
		QLEN=calcnum(QX,QLCA)+calcnum(QY,QLCA);
		ANS=0;
		dfs_ans(1);
		lx=QX,ly=QY,lans=ANS-1;
		ANS--;
		printf("%d\n",ANS);

	}
	return 0;
}
