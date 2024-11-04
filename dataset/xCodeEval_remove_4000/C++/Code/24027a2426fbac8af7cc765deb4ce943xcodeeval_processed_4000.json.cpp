
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=300005;
int siz[Maxn*50],nxt[Maxn*50][2];
void _init(){
	for (int i=0;i<Maxn*50;i++){
		nxt[i][0]=nxt[i][1]=-1;
	}
}
int a[Maxn],p[Maxn];
int dd;
void Add(int x){
	int cur=0;
	for (int i=29;i>=0;i--){
		siz[cur]++;
		if (x&(1<<i)){
		

			if (nxt[cur][1]==-1){
				nxt[cur][1]=++dd;
			}
			cur=nxt[cur][1];
		}
		else{
	

			if(nxt[cur][0]==-1){
				nxt[cur][0]=++dd;
			}
			cur=nxt[cur][0];
		}
	}


	siz[cur]++;
}
void Del(int x){
	int cur=0;
	for (int i=29;i>=0;i--){
		assert(cur!=-1 && siz[cur]>=1);
		siz[cur]--;
		if (x&(1<<i)){
			cur=nxt[cur][1];
		}
		else{
			cur=nxt[cur][0];
		}
	}
	assert(cur!=-1 && siz[cur]>=1);
	siz[cur]--;
}
int Find(int x){
	int cur=0;
	int ans=0;
	for (int i=29;i>=0;i--){
		int f=x&(1<<i);
	

		if (!f){
			if (nxt[cur][0]!=-1 && siz[nxt[cur][0]]!=0){
				cur=nxt[cur][0];
			}
			else{
				cur=nxt[cur][1];
				ans|=(1<<i);
			}
		}
		else{
			if (nxt[cur][1]!=-1 && siz[nxt[cur][1]]!=0){
				cur=nxt[cur][1];
				ans|=(1<<i);
			}
			else{
				cur=nxt[cur][0];
			}
		}
	}
	return ans;
}
int main(){


	int n;
	_init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	for (int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		Add(p[i]);
	}
	for (int i=1;i<=n;i++){
		int x=Find(a[i]);
		Del(x);
		printf("%d ",a[i]^x);
	}
	return 0;
}

