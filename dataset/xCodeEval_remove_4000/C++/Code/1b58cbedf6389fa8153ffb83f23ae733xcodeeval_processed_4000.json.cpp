
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
long long e[Maxn];
int n;
long long u;
int main(){
	scanf("%d %I64d",&n,&u);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&e[i]);
	}
	double ans=-1.0;
	for (int i=1;i<=n;i++){
		if (i+2>n) break;
		if (e[i+2]-e[i]>u) continue;
		int lo=i+2,hi=n+1;
		while (hi-lo>1){
			int mid=lo+hi>>1;
			if (e[mid]-e[i]<=u){
				lo=mid;
			} 
			else{
				hi=mid;
			}
		}
		ans=max(ans,(double)(e[lo]-e[i+1])/(double)(e[lo]-e[i]));
	}
	if (ans<0){
		printf("-1\n");
	} 
	else{
		printf("%.10lf\n",ans); 
	}
}
