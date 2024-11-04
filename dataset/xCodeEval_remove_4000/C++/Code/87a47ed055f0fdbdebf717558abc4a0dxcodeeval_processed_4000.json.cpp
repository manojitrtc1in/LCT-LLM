
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
LL v[Maxn],t[Maxn];
LL sum[Maxn],sum2[Maxn];
LL ans1[Maxn],ans2[Maxn];
LL res[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&v[i]);
		sum2[i]=sum2[i-1]+v[i];
	}
	for (int i=1;i<=n;i++){
		scanf("%I64d",&t[i]);
		sum[i]=sum[i-1]+t[i];
	}
	for (int i=1;i<=n;i++){
		int lo=i-1,hi=n+1;
		while (hi-lo>1){
			int mid=lo+hi>>1;
			if (sum[mid]-sum[i-1]>v[i]){
				hi=mid;
			}
			else{
				lo=mid;
			}
		}
		

	

		ans1[i]++;
		ans1[lo+1]--;
		ans2[i]+=sum[i-1]+v[i];
		ans2[lo+1]-=sum[i-1];
		ans2[lo+1]-=v[i];
	}
	for (int i=1;i<=n;i++){
		

		ans1[i]+=ans1[i-1];
		ans2[i]+=ans2[i-1];
		res[i]=sum2[i]-(ans2[i]-ans1[i]*sum[i]);
	}
	for (int i=1;i<=n;i++){
		printf("%I64d ",res[i]-res[i-1]);
	}
	printf("\n");
	return 0;
}

