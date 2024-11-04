
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;	
int n,m[Maxn];
int l[Maxn],d[Maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&m[i]);
	}
	for (int i=n;i>=1;i--){
		l[i]=l[i+1]-1;
		if (m[i]+1>l[i]){
			l[i]=m[i]+1;
		}
	}
	LL res=0;
	d[0]=1;
	for (int i=1;i<=n;i++){
		d[i]=max(d[i-1],l[i]);
		res+=(long long)(d[i]-m[i]-1);
	}
	printf("%I64d",res);
	return 0;
}
