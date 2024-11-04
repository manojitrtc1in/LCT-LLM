

using namespace std;

const int N = 3e5 + 5;
char s[N];
int n, m, f[N], st[N], sum[N], top;
signed main(){
	scanf("%lld%lld", &n, &m);
	scanf("%s", s+1);
	for(int i = 1; i <= n; i++){
		if(s[i] == '('){
			st[++top] = i;
		}else{
			if(!top){
				continue;
			}
			f[i] = f[st[top]-1] + 1;
			top--;
		}
	}
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + f[i];
	}
	while(m--){
		int _, x, y;
		scanf("%lld%lld%lld", &_, &x, &y);
		printf("%lld\n", sum[y]-sum[x-1]-f[x-1]*(f[y]-f[x-1]));
	}
	return 0;
}
