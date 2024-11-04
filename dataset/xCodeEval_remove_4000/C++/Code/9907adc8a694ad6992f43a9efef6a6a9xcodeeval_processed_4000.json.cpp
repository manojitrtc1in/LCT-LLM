
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n,m;
const int Maxn=3005;
char c[Maxn][Maxn];
int f[Maxn][Maxn],sum[Maxn][Maxn];
int L[Maxn][Maxn],R[Maxn][Maxn];
bool full(int x,int lo,int hi){
	return sum[x][hi]-((lo)?sum[x][lo-1]:0)==hi-lo+1;
}
int getl(int x,int y){
	return L[x][y]-1;
	if (!f[x][y]) return -1;
	int lo=0,hi=y;
	while (hi-lo>1){
		int mid=lo+hi>>1;
		if (full(x,mid,y)){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	if (full(x,lo,y)) return y-lo;
	return y-hi;
}
inline int getr(int x,int y){
	return R[x][y]-1;
	if (!f[x][y]) return -1;
	int lo=y,hi=m;
	while (hi-lo>1){
		int mid=lo+hi>>1;
		if (full(x,y,mid)){
			lo=mid;
		}
		else{
			hi=mid;
		}
	}
	if (full(x,y,hi)) return hi-y;
	return lo-y;
}
int vl[Maxn],vr[Maxn];
int root[Maxn];
int tree[Maxn*30],lson[Maxn*30],rson[Maxn*30];
int nodeid=1;

int build(int l,int r){
	int np=nodeid++;
	if (l==r){
		tree[np]=0;
		return np;
	}
	int mid=l+r>>1;
	lson[np]=build(l,mid);
	rson[np]=build(mid+1,r);
	tree[np]=0;
	return np;
}
int modify(int p,int l,int r,int pos){
	int np=nodeid++;
	if (l==r){
		tree[np]=tree[p]+1;
		return np;
	}
	int mid=l+r>>1;
	if (pos<=mid){
		lson[np]=modify(lson[p],l,mid,pos);
		rson[np]=rson[p];
	}
	else{
		rson[np]=modify(rson[p],mid+1,r,pos);
		lson[np]=lson[p];
	}
	tree[np]=tree[lson[np]]+tree[rson[np]];
	return np;	
}
int query(int p,int l,int r,int lo,int hi){
	if (lo<=l && r<=hi){
		return tree[p];
	}
	int mid=l+r>>1;
	int ans=0;
	if (lo<=mid){
		ans+=query(lson[p],l,mid,lo,min(hi,mid));
	}
	if (hi>mid){
		ans+=query(rson[p],mid+1,r,max(lo,mid+1),hi);
	}
	return ans;
}
int Get(int lo,int hi,int val){
	 

	return query(root[hi],0,3000,0,val)-query(root[lo-1],0,3000,0,val);
}
int main(){

	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		getchar();
		for (int j=0;j<m;j++) c[i][j]=getchar();
		for (int j=0;j<m;j++){
			f[i][j]=(int)(c[i][j]=='z');
		}
		sum[i][0]=f[i][0];
		for (int j=1;j<m;j++){
			sum[i][j]=sum[i][j-1]+f[i][j];
		}
	}
	for (int i=0;i<n;i++){
		L[i][0]=f[i][0];
		for (int j=1;j<m;j++){
			if (f[i][j]){
				L[i][j]=L[i][j-1]+1;
			}
			else{
				L[i][j]=0;
			}
		}
		R[i][m-1]=f[i][m-1];
		for (int j=m-2;j>=0;j--){
			if (f[i][j]){
				R[i][j]=R[i][j+1]+1;
			}
			else{
				R[i][j]=0;
			}
		} 
	}
	LL ans=0;
	for (int tot=0;tot<n+m-1;tot++){
		nodeid=0;
		root[0]=build(0,3000);
		int cur=0;
		for (int i=0;i<n;i++){
			int j=tot-i;
			if (j>=0 && j<m){
				cur++;
				vl[cur]=getl(i,j);
				vr[cur]=getr(i,j);
			}
		}
		for (int j=1;j<=cur;j++){
			root[j]=modify(root[j-1],0,3000,max(j-vr[j],0));
		}
		vector<vector<int> > rr;
		vector<int> tmp;
		for (int j=1;j<=cur;j++){
			if (vl[j]==-1){
				if (tmp.empty()){
					continue;
				}
				rr.pb(tmp);
				tmp.clear();
			}
			else{
				tmp.pb(j);
			}
		}
		if (!tmp.empty()){
			rr.pb(tmp);
		}
		for (int i=0;i<rr.size();i++){
			vector<int> &now=rr[i];
			int ub=now.back();
			for (int j=0;j<now.size();j++){
				int npos=now[j];
				int hi=npos+vl[npos];
				hi=min(hi,ub);
				ans+=Get(npos,hi,npos);
			}
		}
 	}
 	printf("%I64d\n",ans);
}
