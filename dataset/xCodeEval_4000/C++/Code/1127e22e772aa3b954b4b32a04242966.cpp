
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 200001;
struct realedge{ int to; int next; long long value; }edgee[2*N];
int first[N], son[N], dep[N], size[N], w[N],  top[N],fa[N];
int from[N], too[N];
long long tree[4*N], value[N], sonvalue[N], amount[N];
int side, num=1;
#define ll (k<<1)
#define rr (k<<1|1)
#define mid (l+r)>>1
const long long ssinf = 1000000000000000000;
const long long inf = 1000000000000000321;
void addedge(int a, int b,long long value){

	edgee[side].to = b;
	edgee[side].next = first[a];
	edgee[side].value = value;
	first[a] = side++;
}
void dfs(int faa, int v){
	if (faa== -1)dep[v] = 0;
	else dep[v] = dep[v]+dep[faa] + 1;
	fa[v] = faa; size[v] = 1;
	for (int i = first[v]; i != -1; i = edgee[i].next){
		if (edgee[i].to == fa[v])continue;
		if (i == first[v]){
			son[v] = edgee[i].to;
			sonvalue[v] = edgee[i].value;
		}
		dfs(v, edgee[i].to);
		if (size[edgee[i].to] > size[son[v]]){
			son[v] = edgee[i].to;
			sonvalue[v] = edgee[i].value;
		}
		size[v] += size[edgee[i].to];
	}
}
void share(int v, int topp,long long value){
	top[v] = topp;
	amount[num] = value;
	w[v] = num++;
	if(son[v]!=0)share(son[v], topp,sonvalue[v]);
	for (int i = first[v]; i != -1; i = edgee[i].next){
		if (edgee[i].to == son[v] || edgee[i].to == fa[v])continue;
		share(edgee[i].to, edgee[i].to,edgee[i].value);
	}
}


void update(int k, int l, int r, int position, long long value){
	if (l == r){ tree[k] = value; return; }
	if (position > mid)
		update((rr), (mid) + 1, r, position, value);
	else
		update((ll), l, (mid), position, value);
	if (tree[(ll)] == 0)tree[(ll)] = 1;
	if (tree[(rr)] == 0)tree[(rr)] = 1;
	  long long temp1 = tree[(ll)];
	  long long temp2 = tree[rr];
	  if (log(temp1*1.0)+log(temp2*1.0)<=log(ssinf*1.0))
	  {
		  tree[k] = temp1*temp2;
	  }
	  else
		  tree[k] = inf;
}
long long sum(int k, int l, int r, int positionl, int positionr){
	long long templ = 1;
	long long tempr = 1;
	if (positionl <= l&&r <= positionr){return tree[k];}
	if (positionl<=mid)
	 templ = sum((ll), l, (mid), positionl, positionr);
	if (positionr>mid)
	 tempr = sum((rr), (mid)+1, r, positionl, positionr);
	if (log(tempr*1.0) + log(templ*1.0) <= log((ssinf)*1.0))
	{
		return templ*tempr;
	}
	else
		return inf;
}
long long temp = 1;
long long find(int a, int b){
	int topa = top[a];
	int topb = top[b];
	while (topa != topb){
		if (dep[topa] < dep[topb])swap(topa, topb), swap(a, b);
		long long temp1=1;
		temp1= sum(1, 1, num-1, w[topa], w[a]);
		if (log(temp*1.0) + log(temp1*1.0) <= log((ssinf)*1.0))
			temp *= temp1;
		else
			return inf;
		a = fa[topa];
		topa = top[a];
	}
	if (a == b)return temp;
	long long k = 1;
	if (dep[a] > dep[b])swap(a, b);
	k = k*sum(1, 1, num-1, w[a]+1, w[b]);
	if (log(temp*1.0) + log(k*1.0) <= log(ssinf*1.0))
		return temp*k;
	else
		return inf;
}
void build(int k, int l, int r){
	

	if (l == r){
		tree[k] = amount[l];
		return;
	}
	build(ll, l, mid);
	build(rr, (mid)+1, r);
	if (tree[ll] == 0)tree[ll] = 1;
	if (tree[rr] == 0)tree[rr] = 1;
	if (log(tree[rr]*1.0) + log(tree[ll]*1.0) <= log(ssinf*1.0))
		tree[k] = tree[ll]*tree[rr];
	else
		tree[k] = inf;
}
int main(){
	

	int n, m;
	scanf("%d%d", &n, &m) ;
		memset(first, -1, sizeof(first));
		for (int i = 1; i < n; i++){
			scanf("%d%d",&from[i],&too[i]);
			scanf("%I64d", &value[i]);
			addedge(from[i], too[i],value[i]);
			addedge(too[i], from[i],value[i]);
		}
		side = 0, num = 1;
		int root = (n + 1) / 2;
		dfs(-1, root);
	

		share(root, root,1);
	

		build(1, 1, num - 1);
	

		for (int i = 1; i <= m; i++){
			int n;
			scanf("%d", &n);
			if (n == 2){
				int a;
				long long b;
				scanf("%d%I64d", &a, &b);
				if (dep[from[a]] > dep[too[a]])swap(from[a], too[a]);
				update(1, 1, num-1, w[too[a]], b);
			}
			else{
				int a, b;
				long long c;
				scanf("%d%d", &a, &b);
				scanf("%I64d", &c);
				temp = 1;
				long long temp = find(a, b);
				printf("%I64d\n", c / temp);
			}
		}
	return 0;
}
