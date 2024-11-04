
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
char s[Maxn];
int n,q;
int seq[Maxn*15];
int pos[Maxn*15];
int sum[Maxn*15][10];
int Mx[Maxn*15];
int fir[Maxn]; 

int prv[Maxn],nxt[Maxn];
void Del(int np){
	prv[nxt[np]]=prv[np];
	nxt[prv[np]]=nxt[np];
}
int Move(int np,int d){
	return (d==1)?nxt[np]:prv[np];
}
int f(char c){
	return (c=='>')?1:-1;
}
int tmin[Maxn*60],tmax[Maxn*60];
void build(int p,int l,int r){
	if (l==r){
		tmin[p]=tmax[p]=pos[l];
		return;
	}
	int mid=l+r>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tmin[p]=min(tmin[p*2],tmin[p*2+1]);
	tmax[p]=max(tmax[p*2],tmax[p*2+1]);
}
int queryMin(int p,int l,int r,int lo,int lim){


	

	if (tmin[p]>=lim){
		return -1;
	}
	if (l==r){
		return l;
	}
	int mid=l+r>>1;
	if (lo<=mid){
		int ans=queryMin(p*2,l,mid,lo,lim);
		if (ans!=-1){
			return ans;
		}
	}
	return queryMin(p*2+1,mid+1,r,max(mid+1,lo),lim);
}
int queryMax(int p,int l,int r,int lo,int lim){
	

	if (tmax[p]<=lim){
		return -1;
	}
	if (l==r){
		return l;
	}
	int mid=l+r>>1;
	if (lo<=mid){
		int ans=queryMax(p*2,l,mid,lo,lim);
		if (ans!=-1){
			return ans;
		}
	}
	return queryMax(p*2+1,mid+1,r,max(mid+1,lo),lim);
}
int main(){
	scanf("%d %d",&n,&q);
	scanf("%s",s+1);
	memset(seq,-1,sizeof(seq));
	for (int i=1;i<=n;i++){
		fir[i]=1e9;
		prv[i]=i-1;
		nxt[i]=i+1;
	}
	int np=1,Mxp=1;
	int dir=1;
	int nst=1;
	while (1){
		for (;;){
			if (np==0 || np==n+1){
				pos[nst]=np;
				Mxp=max(Mxp,np);
				fir[Mxp]=min(fir[Mxp],nst);
				Mx[nst++]=Mxp;
				break;
			}
			if (s[np]>='0' && s[np]<='9'){
				seq[nst]=s[np]-'0';
				pos[nst]=np;
				Mxp=max(Mxp,np);
				if (s[np]!='0'){
					s[np]--;
				}
				else{
					Del(np);
				}
				np=Move(np,dir);
				fir[Mxp]=min(fir[Mxp],nst);
				Mx[nst++]=Mxp;
			}
			else if (s[np]=='>' || s[np]=='<'){
				pos[nst]=np;
				Mxp=max(Mxp,np);
				fir[Mxp]=min(fir[Mxp],nst);
				Mx[nst++]=Mxp;
				dir=f(s[np]);
				int newpos=Move(np,dir);
				if (newpos>=1 && newpos<=n&& (s[newpos]=='<' || s[newpos]=='>')){
					Del(np);
				}
				np=newpos;
			}
		}
		if (Mxp>=n) break;
		np=Mxp+1;
		dir=1;
	}
	
	nst--;
	for (int i=1;i<=nst;i++){
		for (int j=0;j<10;j++){
			sum[i][j]=sum[i-1][j];
		}
		if (seq[i]>=0 && seq[i]<=9){
			sum[i][seq[i]]++;
		}
	}
	build(1,1,nst);
	



	for (int i=1;i<=q;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		int st=fir[l];
		int ed1=queryMin(1,1,nst,st+1,l),ed2=queryMax(1,1,nst,st+1,r);
		

		

		if (ed1==-1) ed1=nst+1;
		if (ed2==-1) ed2=nst+1;
		
		int ed=min(ed1,ed2)-1;
		for (int j=0;j<10;j++){
			printf("%d ",sum[ed][j]-sum[st-1][j]);
		}
		printf("\n");
	}
	return 0;
}