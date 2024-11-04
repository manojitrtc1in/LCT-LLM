
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=1e5+5;
LL a[Maxn];
int n;
int hd;
int tl;
int nxt[Maxn];
int prv[Maxn];
deque<int> cnt[61];
int wei[Maxn];
bool cmp(int x,int y){
	return wei[x]<wei[y];
}
int main(){
	

	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	int cur=0;
	int cpos=1;
	hd=tl=-1;
	for (int i=0;i<Maxn;i++) prv[i]=nxt[i]=-1;
	for (int i=60;i>=0;i--){
		

		if (a[cpos]&(1ll<<i)){
			int dpos=cpos;
			while (dpos<=n && a[dpos]>=(1ll<<i)){
				dpos++;
			}
			

			dpos--;
			if (dpos-cpos+1>cnt[i].size()+1){
				printf("No\n");
				return 0;
			}
			for (int j=cpos;j<=dpos-1;j++){
				int cut=cnt[i][j-cpos];
			

				if (prv[cut]!=-1){
					nxt[prv[cut]]=j;
					prv[j]=prv[cut];
					prv[cut]=j;
					nxt[j]=cut;
				}
				else{
					assert(cut==hd);
					nxt[j]=hd;
					prv[hd]=j;
					hd=j;
				

					prv[cut]=j;
				}
			}
			if (dpos-cpos+1==cnt[i].size()+1){
				if (tl==hd && tl==-1){
					tl=hd=dpos;
					

				}
				else{
					

					nxt[tl]=dpos;
					
					prv[dpos]=tl;
					tl=dpos;
				}
			}
			else{
				int j=dpos;
				int cut=cnt[i][j-cpos];
				

				if (prv[cut]!=-1){
					nxt[prv[cut]]=j;
					prv[j]=prv[cut];
					prv[cut]=j;
					nxt[j]=cut;
				}
				else{
					nxt[j]=hd;
					prv[hd]=j;
					hd=j;
					

					prv[cut]=j;
				}
			}
			for (int j=cpos;j<=dpos;j++){
				for (int k=60;k>=0;k--){
					if (a[j] & (1ll<<k)){
						cnt[k].push_back(j);
					}
				}
			}
			cpos=dpos+1;
		

		}
		if (hd!=-1 && i){
			wei[hd]=0;
			for (int j=hd;j!=tl;j=nxt[j]){
				wei[nxt[j]]=wei[j]+1;
			}
			sort(cnt[i-1].begin(),cnt[i-1].end(),cmp);
		}
	}
	printf("Yes\n");
	vector<LL> cj;
	for (int i=hd;;i=nxt[i]){
		printf("%I64d ",a[i]);
		cj.pb(a[i]);
		if (i==tl) break;
 	}
	return 0;
}
