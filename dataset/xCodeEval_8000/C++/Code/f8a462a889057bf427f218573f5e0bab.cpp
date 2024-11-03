















#include<cstdio>
#include<algorithm>
using namespace  std;
typedef long long ll;
const int N = 2e5 + 5;
int n, ls[N], rs[N], vis[N], stk[N], rt;
int dg[N];
int a[N], b[N], c[N];
void build(){
	int top = 0;
	for (int i = 1; i <= n; i++){
		ls[i] = 0, rs[i] = 0, vis[i] = 0;
	}
	for (int i = 1; i <= n; i++){
		int k = top;
		while (k>0 && a[stk[k - 1]]>a[i]) k--;
		if (k) rs[stk[k - 1]] = i;
		if (k<top) ls[i] = stk[k];
		stk[k++] = i;
		top = k;
	}
	for (int i = 1; i <= n; i++){
		vis[ls[i]] = vis[rs[i]] = 1;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i] == 0) rt = i;
	}
}
void dfs(int u){
	dg[u] = 1;
	if (ls[u]) dfs(ls[u]), dg[u] = max(dg[u], dg[ls[u]] + 1);
	if (rs[u]) dfs(rs[u]), dg[u] = max(dg[u], dg[rs[u]] + 1);
}
void leftshift(int steps)
{
	for (int i = 1; i <= n; i++)
	{
		int now = (((i - 1) - steps) % n + n) % n + 1;
		a[now] = b[i];
	}
}
void rightshift(int steps)
{
	for (int i = 1; i <= n; i++)
	{
		int now = (((i - 1) - (n - 1 - steps + 1)) % n + n) % n + 1;
		a[now] = b[i];
	}
}
pair<int, int>solve(){
	int lo , hi , res, ans,move;
	build(); dfs(rt);
	

	ans = dg[rt];
	move = 0;
	if (dg[ls[rt]] == dg[rs[rt]])
		return pair<int, int>(ans, move);
	if (dg[ls[rt]] < dg[rs[rt]])
	{
		lo = 1;
		hi = n - rt;
		while (lo < hi)
		{
			int mid = (lo + hi) / 2;
			rightshift(mid);
			build(); dfs(rt);
			if (dg[rt] < ans)
			{
				ans = dg[rt];
				move = (n-1-mid)+1;
			}
			if (dg[ls[rt]] < dg[rs[rt]])
			{
				lo = mid + 1;
			}
			else
				hi = mid;
		}
		rightshift(lo);
		build(); dfs(rt);
		if (dg[rt] < ans)
		{
			ans = dg[rt];
			move = n-1-lo+1;
		}
	}
	if (dg[ls[rt]] > dg[rs[rt]])
	{
		lo = 1;
		hi =  rt-1;
		while (lo < hi)
		{
			int mid = (lo + hi) / 2;
			leftshift(mid);
			build(); dfs(rt);
			if (dg[rt] < ans)
			{
				ans = dg[rt];
				move = mid;
			}
			if (dg[ls[rt]] > dg[rs[rt]])
			{
				lo = mid + 1;
			}
			else
				hi = mid;
		}
		rightshift(lo);
		build(); dfs(rt);
		if (dg[rt] < ans)
		{
			ans = dg[rt];
			move = lo;
		}
	}
	
	
	return pair<int, int>(ans, move);
}
int main(){
	scanf("%d", &n);
	

	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
		

	}
	pair<int,int> ans2;
	ans2 = solve();
	printf("%d %d\n", ans2.first, ans2.second);
	return 0;
}
