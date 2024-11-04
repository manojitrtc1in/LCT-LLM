





















using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pll;
const double pi = acos(0) * 2;
template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}
template <class T> inline T max1(T a, T b) {return a > b ? a : b;}
template <class T> inline T min1(T a, T b) {return a < b ? a : b;}
template <class T> inline T id0(T a, T b) {
	if(a < b) swap(a, b);
	if(a % b == 0) return b;
	return id0(b, a % b);
}
template <class T> inline T lb(T num) {return num & (-num); }
template <class T> inline int bitnum(T num){
	int ans = 0;
	while(num){
		num -= lb(num);
		ans++;
	}
	return ans;
}
long long pow(long long n, long long m, long long mod = 0){
	long long ans = 1;
	long long k = n;
	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}

const int maxn = 200100;
template <class t> struct segment_node{
	int be, en;
	t maxv, add, sum, minv;
};
template <class t> struct segment_tree{
	int l;
	segment_node <t> tree[maxn];

	inline int gleft(int no) {return no << 1;}
	inline int gright(int no) {return (no << 1) + 1;}
	inline int gfa(int no) {return no >> 1;}
	inline segment_tree(){ l = 0; }

	void build(int no, int l, int r, t orig = 0, t *a = NULL){
		if(l == r){
			tree[no].be = tree[no].en = l;
			tree[no].add = 0;
			if(a == NULL) tree[no].maxv = orig, tree[no].minv = orig;
			else tree[no].maxv = a[l], tree[no].minv = a[l];
			tree[no].add = 0;
			tree[no].sum = tree[no].maxv;
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid, orig, a);
		build(gright(no), mid + 1, r, orig, a);
		tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
		tree[no].add = 0;
		tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
		tree[no].minv = min1(tree[gleft(no)].minv, tree[gright(no)].minv);
	}
	

	void down(int l, int r, int no, t ranadd){
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add += ranadd;
			tree[no].sum += ranadd * (tree[no].en - tree[no].be + 1);
			tree[no].maxv = ranadd;
			tree[no].minv = ranadd;
			return;
		}
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
		if(r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
		tree[no].sum = tree[no].add * (tree[no].en - tree[no].be + 1) + tree[gleft(no)].sum + tree[gright(no)].sum;
		tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
		tree[no].minv = min1(tree[gleft(no)].minv, tree[gright(no)].minv);
	}
	

	t getsum(int l, int r, int no){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].sum;
		t ans = 0;
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) ans += getsum(max1(l, tree[no].be), min1(r, mid), gleft(no));
		if(r >= mid + 1 && l <= tree[no].en) ans += getsum(max1(l, mid + 1), min1(r, tree[no].en), gright(no));
		ans += tree[no].add * (r - l + 1);
		return ans;
	}
	int getrank(int rank, int no){
		if(rank > tree[no].sum) return -1;
		if(tree[no].be == tree[no].en) return tree[no].be;
		int mid = (tree[no].be + tree[no].en) / 2;
		if(rank <= tree[gleft(no)].sum + tree[no].add * (mid - tree[no].be + 1)) return getrank(rank, gleft(no));
		return getrank(rank - (tree[gleft(no)].sum + tree[no].add * (mid - tree[no].be + 1)), gright(no));
	}
	inline int section_getrank(int l, int r, int rank){
		return getrank(rank + getsum(0, l - 1, 1), 1);
	}
	

	t findminormax(int l, int r, int no, int cate){
		if(l > r) return -1;
		if(l <= tree[no].be && r >= tree[no].en){
			if(cate) return tree[no].maxv;
			else return tree[no].minv;
		}
		t ans = 0, ans1;
		if(cate == 0) ans = ans1 = 1000000000;
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) ans = findminormax(max1(l, tree[no].be), min1(r, mid), gleft(no), cate);
		if(r >= mid + 1 && l <= tree[no].en) ans1 = findminormax(max1(l, mid + 1), min1(r, tree[no].en), gright(no), cate);
		if(cate) return max1(ans, ans1);
		return min1(ans, ans1);
	}
};

int l, nq;
char str[maxn];
int fa[maxn];
int dp[maxn][10], sum[maxn][10], dpri[maxn][10], realst[maxn][10], realdp[maxn][10];
vector <int> co, cole, cori;
struct node{
	int dp[10], no;
} st[maxn];
int lst;
segment_tree <int> sgt;
struct query{
	int be, en, no;
	int ans[10];
} que[maxn];
inline bool cmp1(const query &a, const query &b) { return a.be > b.be; }
inline bool cmp2(const query &a, const query &b) { return a.no < b.no; }

int main(){




	scanf("%d%d", &l, &nq);
	scanf("%s", str);
	for(int i = 0; i < l; i++){

		if(i != 0) for(int j = 0; j < 10; j++) sum[i][j] = sum[i - 1][j], realst[i][j] = realst[i - 1][j];
		if(str[i] == '<'){
			co.push_back(i);
			bool ff = 1;
			while(lst != 0 && ff){
				int maxnum = 9;
				while(st[lst - 1].dp[maxnum] == 0 && maxnum > -1) maxnum--;
				for(int i1 = 0; i1 < 10; i1++) realst[i][i1] -= st[lst - 1].dp[i1], realdp[i][i1] += st[lst - 1].dp[i1];
				if((maxnum & 1) == 0) {
					fa[i] = st[lst - 1].no;
					memcpy(dp[i], st[lst - 1].dp, sizeof(st[lst - 1].dp));
					memset(st[lst - 1].dp, 0, sizeof(st[lst - 1].dp));
					ff = 0;
				}else {
					lst--;
					fa[st[lst].no] = i;
					memcpy(dp[st[lst].no], st[lst].dp, sizeof(st[lst].dp));
				}
			}
			if(ff) fa[i] = -1;
		} else if(str[i] == '>'){
			co.push_back(i);
			if(lst > 0) {
				int k = 0;
				for(int i1 = 0; i1 < 10; i1++) k |= st[lst - 1].dp[i1];
				if(k == 0) fa[st[--lst].no] = i;
			}
			memset(st[lst].dp, 0, sizeof(st[lst]));
			st[lst++].no = i;
		}else {
			if(lst > 0) st[lst - 1].dp[str[i] - '0']++;
			sum[i][str[i] - '0']++;
			realst[i][str[i] - '0']++;
		}
	}
	while(lst > 0) {
		lst--;
		fa[st[lst].no] = l;
		memcpy(dp[st[lst].no], st[lst].dp, sizeof(st[lst].dp));
	}
	for(int i = 0; i < (int)co.size(); i++) {
		if(str[co[i]] == '>') memcpy(dpri[co[i]], dp[co[i]], sizeof(dp[co[i]])), cori.push_back(co[i]);
		else cole.push_back(co[i]);
	}
	for(int i = 1; i < l; i++) for(int j = 0; j < 10; j++) dp[i][j] += dp[i - 1][j];
	for(int i = 1; i < l; i++) for(int j = 0; j < 10; j++) realdp[i][j] += realdp[i - 1][j];
	for(int i = 1; i < l; i++) for(int j = 0; j < 10; j++) dpri[i][j] += dpri[i - 1][j];

	for(int i = 0; i < nq; i++) {
		scanf("%d%d", &que[i].be, &que[i].en);
		que[i].no = i;
		que[i].be--; que[i].en--;
	}
	sort(que, que + nq, cmp1);
	sgt.build(1, 0, l + 2, l + 1);
	for(int i1 = l - 1, j = 0; i1 >= 0; i1--){
		if(str[i1] == '<' || str[i1] == '>') sgt.down(fa[i1] + 1, fa[i1] + 1, 1, i1);
		for(; j < nq && que[j].be == i1; j++){
			vector <int> :: iterator it;
			int link = min1(sgt.findminormax(0, que[j].be, 1, 0), sgt.findminormax(que[j].en + 2, l + 2, 1, 0));
	
			if(link > que[j].en || link < que[j].be){
				if(que[j].be != 0) for(int k = 0; k < 10; k++) que[j].ans[k] = sum[que[j].en][k] - sum[que[j].be - 1][k];
				else for(int k = 0; k < 10; k++) que[j].ans[k] = sum[que[j].en][k];
				continue;
			}
			if(str[link] == '<'){
				if(link == 0) continue;
				it = lower_bound(co.begin(), co.end(), que[j].be);
				if(*it != 0) for(int k = 0; k < 10; k++)  que[j].ans[k] = dp[link - 1][k] - dp[*it - 1][k];
				else for(int k = 0; k < 10; k++) que[j].ans[k] = dp[link - 1][k];
				for(int k = 8; k >= 0; k--) que[j].ans[k] += que[j].ans[k + 1];
				if(que[j].be != 0) for(int k = 0; k < 10; k++) {
					que[j].ans[k] += sum[*it - 1][k] - sum[que[j].be - 1][k];
					if(k != 0) que[j].ans[k - 1] += sum[*it - 1][k] - sum[que[j].be - 1][k];
				}else if(*it != 0) for (int k = 0; k < 10; k++) {
					que[j].ans[k] += sum[*it - 1][k];
					if(k != 0) que[j].ans[k - 1] += sum[*it - 1][k];
				}
			}else {
				if(que[j].be != 0) {
					for(int k = 0; k < 10; k++) que[j].ans[k] += realdp[que[j].en][k] - realdp[que[j].be - 1][k];
					for(int k = 8; k >= 0; k--) que[j].ans[k] += que[j].ans[k + 1];
					for(int k = 0; k < 10; k++) que[j].ans[k] += realst[que[j].en][k] - realst[que[j].be - 1][k];
				}else {
					for(int k = 0; k < 10; k++) que[j].ans[k] += realdp[que[j].en][k];
					for(int k = 8; k >= 0; k--) que[j].ans[k] += que[j].ans[k + 1];
					for(int k = 0; k < 10; k++) que[j].ans[k] += realst[que[j].en][k];
				}
			


			}
		}
	}
	sort(que, que + nq, cmp2);
	for(int i = 0; i < nq; i++) {
		for(int j = 0; j < 10; j++) printf("%d ", que[i].ans[j]);
		printf("\n");
	}

	return 0;
}

