
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main(){
	int x,d;
	scanf("%d %d",&x,&d);
	vector<LL> ans;
	int cnt=0;
	for (int i=0;i<31;i++){
		if (x & (1<<i)){
			cnt++;
			for (int j=0;j<i;j++){
				ans.pb(1000000000ll*(LL)(cnt));
			}
			ans.pb(1000000000ll*(LL)(++cnt));
		}
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++){
		printf("%I64d ",ans[i]);
	}
	printf("\n");
	return 0;
}
