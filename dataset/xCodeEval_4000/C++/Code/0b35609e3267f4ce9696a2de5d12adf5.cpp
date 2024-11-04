#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

const int DEBUGL = -1;
const int DEBUGR = -1;

struct dataa{
	vector<int> kiri;
	vector<int> kanan;
	int sz;
	int l,r;
	
	dataa(){
		kiri.clear();
		kanan.clear();
		sz = 0;
	}
	
};

int n,k;
int m;
vector<int> temen[N+5];
dataa ST[4*N+5];

int dep = 0;

bool in_range(int x, int l, int r){
	return x >= l && x <= r;
}

int find_par(int x, dataa &a, dataa &b){


	if(!in_range(x,a.l,min(a.l+k-1,a.r)) && !in_range(x,max(a.l,a.r-k+1),a.r) && !in_range(x,b.l,min(b.l+k-1,b.r)) && !in_range(x,max(b.l,b.r-k+1),b.r)){
		printf("X = %d, a.l = %d, a.r = %d, b.l = %d, b.r = %d\n",x,a.l,a.r,b.l,b.r);
		return -1;
	}
	dep++;
	if(dep > 3e5){
		printf("X = %d, a.l = %d, a.r = %d, b.l = %d, b.r = %d\n",x,a.l,a.r,b.l,b.r);
		printf("SAD\n");
		return -2;
	}
	if(x <= min(a.l+k-1,a.r)){
		int id = x - a.l;
		if(a.kiri[id] == x) return x;
		return a.kiri[id] = find_par(a.kiri[id],a,b);
	}
	if(x >= max(b.l,b.r-k+1)){
		int id = b.r-x;
		if(b.kanan[id] == x) return x;
		return b.kanan[id] = find_par(b.kanan[id],a,b);
	}
	if(x <= a.r){
		int id = a.r - x;
		if(a.kanan[id] == x) return x;
		return a.kanan[id] = find_par(a.kanan[id],a,b);
	} else {
		int id = x - b.l;




		if(b.kiri[id] == x){


			
			return x;
		}
		return b.kiri[id] = find_par(b.kiri[id],a,b);
	}
	return -1;
}

inline dataa merge(dataa &a, dataa &b){
	dataa ta = a;
	dataa tb = b;
	dataa ret;
	ret.kiri = vector<int>(5);
	ret.kanan = vector<int>(5);
	if(a.l == DEBUGL && b.r == DEBUGR){
		printf("A KIRI:");
		for(int i=0;i<k;i++){
			printf(" %d",a.kiri[i]);
		}
		printf("\nA KANAN:");
		for(int i=0;i<k;i++){
			printf(" %d",a.kanan[i]);
		}
		printf("\nB KIRI:");
		for(int i=0;i<k;i++){
			printf(" %d",b.kiri[i]);
		}
		printf("\nB KANAN:");
		for(int i=0;i<k;i++){
			printf(" %d",b.kanan[i]);
		}
		printf("\n");
	}
	ret.l = a.l;
	ret.r = b.r;
	ret.sz = a.sz + b.sz;
	for(int i=0;i<k;i++){
		int now = b.l+i;
		if(now > b.r) break;


		for(int j=0;j<temen[now].size();j++){
			int cur = temen[now][j];


			if(cur > a.r || cur < a.l) continue;


			dep = 0;
			int pn = find_par(now,a,b);
			if(pn == -1){
				printf(">>> JOIN %d - %d\n",a.l,b.r);
				assert(0);
			} else if(pn == -2){
				printf(">>> SAD JOIN %d - %d NOW = %d\n",a.l,b.r,now);
				assert(0);
			}


			dep = 0;
			int pc = find_par(cur,a,b);
			if(pc == -1){
				printf(">> JOIN %d - %d\n",a.l,b.r);
				assert(0);
			} else if(pc == -2){
				printf(">>> SAD1 JOIN %d - %d NOW = %d\n",a.l,b.r,now);
				assert(0);
			}


			if(pc < a.l+k || pc > b.r-k) swap(pc,pn);
			if(pn != pc){
				ret.sz--;
				if(pc <= a.r){
					if(pc < a.l+k) a.kiri[pc-a.l] = pn;
					if(pc > a.r-k) a.kanan[a.r-pc] = pn;
				} else {
					if(pc > b.r-k) b.kanan[b.r-pc] = pn;
					if(pc < b.l+k) b.kiri[pc-b.l] = pn;
				}
			}
		}
	}
	
	if(a.l == DEBUGL && b.r == DEBUGR){
		printf("First Phase JADI :\n");
		printf("A KIRI:");
		for(int i=0;i<k;i++){
			printf(" %d",a.kiri[i]);
		}
		printf("\nA KANAN:");
		for(int i=0;i<k;i++){
			printf(" %d",a.kanan[i]);
		}
		printf("\nB KIRI:");
		for(int i=0;i<k;i++){
			printf(" %d",b.kiri[i]);
		}
		printf("\nB KANAN:");
		for(int i=0;i<k;i++){
			printf(" %d",b.kanan[i]);
		}
		printf("\n");
	}
	






































































	



	for(int i=0;i<k;i++){
		int now = a.l+i;
		if(now > a.r) continue;
		dep = 0;
		int pn = find_par(now,a,b);


		if(pn == -1){
			printf(">>>>> JOIN %d - %d\n",a.l,b.r);
			assert(0);
		} else if(pn == -2){
			printf(">>> SAD2 JOIN %d - %d NOW = %d\n",a.l,b.r,now);
			assert(0);
		}
		if(pn < a.l+k || pn > b.r-k) continue;
		if(now < a.l+k) a.kiri[i] = now;
		if(now > a.r-k) a.kanan[a.r-now] = now;
		if(pn <= a.r){
			if(pn > a.r-k) a.kanan[a.r-pn] = now;
			if(pn < a.l+k) a.kiri[pn-a.l] = now;
		} else {
			if(pn < b.l+k) b.kiri[pn-b.l] = now;
			if(pn > b.r-k) b.kanan[b.r-pn] = now;
		}
	}
	


	for(int i=0;i<k;i++){
		int now = b.r-i;
		if(now < b.l) continue;


		dep = 0;
		int pn = find_par(now,a,b);
		if(pn == -1){
			printf(">>>>>+++ JOIN %d - %d .... NOW = %d\n",a.l,b.r,now);
			assert(0);
		} else if(pn == -2){
			printf(">>> SAD3 JOIN %d - %d NOW = %d\n",a.l,b.r,now);
			assert(0);
		}
		if(pn < a.l+k || pn > b.r-k) continue;
		if(now < b.l+k) b.kiri[i] = now;
		if(now > b.r-k) b.kanan[b.r-now] = now;
		if(pn <= a.r){
			if(pn > a.r-k) a.kanan[a.r-pn] = now;
			if(pn < a.l+k) a.kiri[pn-a.l] = now;
		} else {
			if(pn < b.l+k) b.kiri[pn-b.l] = now;
			if(pn > b.r-k) b.kanan[b.r-pn] = now;
		}
	}
	
	for(int i=0;i<k;i++){
		int now = b.l+i;
		if(now > b.r) continue;
		dep = 0;
		int pn = find_par(now,a,b);


		if(pn == -1){
			printf(">>>>> JOIN %d - %d\n",a.l,b.r);
			assert(0);
		} else if(pn == -2){
			printf(">>> SAD2 JOIN %d - %d NOW = %d\n",a.l,b.r,now);
			assert(0);
		}
		if(pn < a.l+k || pn > b.r-k) continue;
		if(now < b.l+k) b.kiri[i] = now;
		if(now > b.r-k) b.kanan[b.r-now] = now;
		if(pn <= a.r){
			if(pn > a.r-k) a.kanan[a.r-pn] = now;
			if(pn < a.l+k) a.kiri[pn-a.l] = now;
		} else {
			if(pn < b.l+k) b.kiri[pn-b.l] = now;
			if(pn > b.r-k) b.kanan[b.r-pn] = now;
		}
	}
	


	for(int i=0;i<k;i++){
		int now = a.r-i;
		if(now < a.l) continue;


		dep = 0;
		int pn = find_par(now,a,b);
		if(pn == -1){
			printf(">>>>>+++ JOIN %d - %d .... NOW = %d\n",a.l,b.r,now);
			assert(0);
		} else if(pn == -2){
			printf(">>> SAD3 JOIN %d - %d NOW = %d\n",a.l,b.r,now);
			assert(0);
		}
		if(pn < a.l+k || pn > b.r-k) continue;
		if(now < a.l+k) a.kiri[i] = now;
		if(now > a.r-k) a.kanan[a.r-now] = now;
		if(pn <= a.r){
			if(pn > a.r-k) a.kanan[a.r-pn] = now;
			if(pn < a.l+k) a.kiri[pn-a.l] = now;
		} else {
			if(pn < b.l+k) b.kiri[pn-b.l] = now;
			if(pn > b.r-k) b.kanan[b.r-pn] = now;
		}
	}
	
	if(a.l == DEBUGL && b.r == DEBUGR){
		printf("NORMALIZE JADI :\n");
		printf("A KIRI:");
		for(int i=0;i<k;i++){
			printf(" %d",a.kiri[i]);
		}
		printf("\nA KANAN:");
		for(int i=0;i<k;i++){
			printf(" %d",a.kanan[i]);
		}
		printf("\nB KIRI:");
		for(int i=0;i<k;i++){
			printf(" %d",b.kiri[i]);
		}
		printf("\nB KANAN:");
		for(int i=0;i<k;i++){
			printf(" %d",b.kanan[i]);
		}
		printf("\n");
	}
	
	for(int i=0;i<k;i++){
		if(b.l+i <= b.r && b.l+i < a.l+k){
			a.kiri[b.l+i - a.l] = find_par(b.kiri[i],a,b);
		}
	}
	
	for(int i=k-1;i>=0;i--){
		if(a.r-i >= a.l && a.r-i > b.r - k){
			b.kanan[b.r - (a.r-i)] = find_par(a.kanan[i],a,b);
		}
	}
	
	if(a.l == DEBUGL && b.r == DEBUGR){
		printf("LAST JADI :\n");
		printf("A KIRI:");
		for(int i=0;i<k;i++){
			printf(" %d",a.kiri[i]);
		}
		printf("\nA KANAN:");
		for(int i=0;i<k;i++){
			printf(" %d",a.kanan[i]);
		}
		printf("\nB KIRI:");
		for(int i=0;i<k;i++){
			printf(" %d",b.kiri[i]);
		}
		printf("\nB KANAN:");
		for(int i=0;i<k;i++){
			printf(" %d",b.kanan[i]);
		}
		printf("\n");
	}
	
	ret.kiri = a.kiri;
	ret.kanan = b.kanan;
	












	a.kiri = ta.kiri;
	a.kanan = ta.kanan;
	b.kiri = tb.kiri;
	b.kanan = tb.kanan;
	return ret;
}

void build(int node, int l, int r){
	if(l==r){
		ST[node].kiri = ST[node].kanan = vector<int>(5);
		ST[node].kiri[0] = ST[node].kanan[0] = l;
		ST[node].sz = 1;
		ST[node].l = ST[node].r = l;
		return;
	}
	int mid = (l+r)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);


	ST[node] = merge(ST[node*2],ST[node*2+1]);


	return;
}

dataa query(int node, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr){
		return ST[node];
	}
	int mid = (l+r)/2;
	if(ql > mid) return query(node*2+1,mid+1,r,ql,qr);
	else if(qr <= mid) return query(node*2,l,mid,ql,qr);
	dataa kiri = query(node*2,l,mid,ql,qr);
	dataa kanan = query(node*2+1,mid+1,r,ql,qr);
	dataa ret = merge(kiri,kanan);
	return ret;
}

inline int solve(int l, int r){
	dataa ans = query(1,1,n,l,r); 

	return ans.sz;
}

int main(){
	scanf("%d%d",&n,&k);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u > v) swap(u,v);
		temen[v].push_back(u);
	}


















	build(1,1,n); 



	int q;
	scanf("%d",&q);
	while(q--){
		int l, r;
		scanf("%d%d",&l,&r);
		int ans = solve(l,r);
		printf("%d\n",ans);
	}
	return 0;
}

