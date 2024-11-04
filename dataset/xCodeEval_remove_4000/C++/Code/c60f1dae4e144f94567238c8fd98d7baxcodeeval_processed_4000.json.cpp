
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
int p[Maxn];
int d[Maxn];
int ans[Maxn];
int main(){
	d[1]=0;
	ans[0]=1;
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		scanf("%d",&p[i]);
		d[i]=d[p[i]]+1;
		ans[d[i]]^=1;
	}
	int cnt=0;
	for (int i=0;i<=n;i++){
		cnt+=ans[i];
	}
	printf("%d\n",cnt);
	return 0;
}

