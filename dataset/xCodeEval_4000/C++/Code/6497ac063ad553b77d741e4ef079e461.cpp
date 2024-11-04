#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
 
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<pair <int,int> > vpi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
#define F first
#define ln '\n'
#define S second
#define PB push_back
#define MP make_pair
#define B begin()
#define RB rbegin()
#define E end()
#define RE rend()
#define Z size()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define L length()
#define show(a) cerr << " *** " << a << endl;
#define show1(a) cerr << " /// " << a << endl;
#define valid(a,b,c) (a >= b && a < c ? 1 : 0)
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int mod = (int)1e9 + 7;
const ll INF64 = 3e18;
void smxl(ll &a, ll b){if (a < b)a=b;}
void smnl(ll &a, ll b){if (a > b)a=b;}
void adsl(ll &a, ll b){a += b;if (a >= mod)a -= mod;}
void misl(ll &a, ll b){a -= b;if (a >= mod)a -= mod; if (a < 0)a += mod;}
void smx(ll &a, ll b){if (a < b)a=b;}
void smn(ll &a, ll b){if (a > b)a=b;}
void ads(ll &a, ll b){a += b;if (a >= mod)a -= mod;}
void mis(ll &a, ll b){a -= b;if (a >= mod)a -= mod; if (a < 0)a += mod;}
ll gcd(ll a, ll b) {return (b==0? a:gcd(b,a%b));}
ll egcd(ll a, ll b, ll & x, ll & y) {if (a == 0){x = 0;y = 1;return b;}ll x1, y1;ll d = egcd(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
ll mbinp(ll a, ll b){a %= mod;if (b == 0)return 1;ll ans = mbinp(a, b/2);ll tmp = (ans * ans) % mod;if (b % 2)return ((tmp * a) % mod);return ((tmp) % mod);}
ll binp(ll a, ll b){if (b == 0)return 1;ll ans = binp(a, b/2);ll tmp = (ans * ans);if (b % 2)return ((tmp * a));return ((tmp));}
long long C(int n, int m){ll ret=1;for(int i=1;i<=m;i++){ret*=(n-i+1);ret/=i;}return ret;}
long long overbinp(long long a, int b){long long res = 1;while (b){if (b & 1){if (res < INF64 / a) res *= a;else return INF64;}if (b > 1){if (a < INF64 / a) a *= a;else return INF64;}b >>= 1;}return res;}
class BinaryLift{
	vector<vi> binlift;
	int n;
	public:
		BinaryLift(vi rnk, vi par){
			n = (int)par.Z;
			binlift.resize(n);
			REP(i,0,n)
				binlift[i].resize(20);
			REP(i,0,n)
				binlift[i][0] = par[i];
			REP(j,1,20)
				REP(i,0,n)
				{
					if ((1 <<j) <rnk[i])
						binlift[i][j]=binlift[binlift[i][j-1]][j-1];
					else
						binlift[i][j]=-1;
				}
		}
	public:
		int get_kth_ancestor(int x, int k)
		{
			int pt = x;
			for (int i = 19; i >= 0; i--)
			{
				if (pt==-1)
					exit(0);
				if (k&(1<<i))
					pt=binlift[pt][i];
			}
			return pt;
		}
	public:
		int get_th_ancestor(int x, int k)
		{
			int pt = x;
			for (int i = 19; i >= 0; i--)
			{
				if (k&(1<<i))
					pt=binlift[pt][i];
			}
			return pt;
		}
};
class SparseTable{


	vector<vi> sparse;
	int n;
	vi input;
	private:
	int lg2(int x)
	{
		int out = 0;
		while((1 << out) <= x)
			out++;
		return out-1;
	}
	public:
	int rminpos(int left, int right)
	{
		int len = right-left+1;
		int lg = lg2(len);
		return (input[sparse[left][lg]] < input[sparse[left+len-(1 << lg) ][lg]]? sparse[left][lg]:sparse[left+len-(1 << lg)][lg]);
	}
	
	public:
	SparseTable(vi inp, string operation){
		input= inp;
		n=inp.Z;
		if (operation == "min")
			prepromin();   
		

		

	}
	private:
	void prepromin(){
		sparse.resize(n);
		int x = lg2(n)+1;
		REP(i,0,n)
			sparse[i].resize(x);
		REP(i,0,n)
			sparse[i][0]=i;
		REP(j,1,x)
			for(int i = 0; i + (1 << (j-1)) < n; i++)
				sparse[i][j] = (input[sparse[i][j-1]] < input[sparse[i+(1<<(j-1))][j-1]] ? sparse[i][j-1] : sparse[i+(1<<(j-1))][j-1]); 

	}
	
};







const int nax = 1e5+50;
int par[nax];
int siize[nax];
int get(int x)
{
	return (x == par[x] ? x : par[x] = get(par[x]));
}
void merge(int a, int b) {
	int x = get(a);
	int y = get(b);
	if (x == y)return;
	if (siize[x] < siize[y])swap(x,y);par[y] = x;siize[x] += siize[y];}
	

	

	

	

	

	

	void display(vi &a){for(int z : a)cout << z << " ";cout << endl;}


	int rnk[3][nax];
	int pas[nax];
void pank(int x,int y, int z,vector<vi> &adj)
{
	for(int l :  adj[x])
		if (l != y)
		{
			rnk[z][l]=rnk[z][x]+1;
			pank(l,x,z,adj);
		}
}
int u = 0;
int lop[3][nax];
int prr[nax];
int lopm[nax];
void dfs(int x,vector<vi> &adj, vi &eul, vi &bij, vi &pot,int root){
	for(int z : adj[x])
		if (rnk[root][z] > rnk[root][x])
		{
			if (root==0)
				prr[z]=x;
			eul.PB(rnk[root][x]);
			bij.PB(x);
			pot.PB(u);
			if (lopm[x]==-1)
				lopm[x]=u;
			lop[root][x]=u;
			u++;
			dfs(z,adj,eul,bij,pot,root);
		}
	eul.PB(rnk[root][x]);
	bij.PB(x);
	pot.PB(u);
	if (lopm[x]==-1)
		lopm[x]=u;
	lop[root][x]=u;
	u++;
}
void dtr(int x, int par, vector<vi> &adj, vi &tre)
{
	for(int z : adj[x])
		if (z!=par)
		{
			dtr(z,x,adj,tre);
			tre[x]+=tre[z];
		}
	tre[x]++;
}
int binposn(vi &all, int val)
{
	int low=0;
	int hi = all.Z-1;
	int res =  1e9;
	while(low <=hi)
	{
		int mid=(low+hi)/2;
		if (all[mid] > val)
		{
			if (res > mid)
				res=mid;
			hi=mid-1;
		}
		else
			low=mid+1;
	}
	if (res==1e9)
		return -1;
	return res;
}
int binposm(vi &all, int val)
{
	int low=0;
	int hi = all.Z-1;
	int res =  -1;
	while(low <=hi)
	{
		int mid=(low+hi)/2;
		if (all[mid] < val)
		{
			if (res < mid)
				res=mid;
			low=mid+1;
		}
		else
			hi=mid-1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vi> adj(n);
	prr[0]=-1;
	REP(i,0,n-1)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	REP(j,0,3)
		REP(i,0,n)
		rnk[j][i]=-1;
	rnk[0][0]=0;
	REP(i,0,3)
		pank(0,-1,0,adj);
	vector<vi> euler(3);
	vector<vi> bij(3);
	vector<vi> pot(3);
	u = 0;
	dfs(0,adj,euler[0],bij[0],pot[0],0);
	u = 0;
	dfs(1,adj,euler[1],bij[1],pot[1],1);
	u = 0;
	dfs(2,adj,euler[2],bij[2],pot[2],2);
	vector<SparseTable> spr;
	REP(i,0,3)
		spr.PB(SparseTable(euler[i],"min"));
	vector<vi> tree(3);
	REP(i,0,3)
		tree[i].resize(n);
	REP(i,0,3)
		dtr(i,-1, adj,tree[i]);
	vi rr,pp;
	REP(i,0,n)
		rr.PB(rnk[0][i]);
	REP(i,0,n)
		pp.PB(prr[i]);
	BinaryLift lift = BinaryLift(rr,pp);
	int q;
	cin >> q;
	while(q--){
		int a,b;
		cin >> a >> b;
		a--;b--;
		if (rnk[0][a]<rnk[0][b])
			swap(a,b);
		int rt0;
		rt0 = bij[0][spr[0].rminpos(min(lop[0][a],lop[0][b]),max(lop[0][b],lop[0][a]))];
		int dist = rnk[0][a]+rnk[0][b]-2*rnk[0][rt0];
		if (a==b)
			cout << n << ln;
		else if (dist %2==1)
		{
			cout << 0<<ln;
		}
		else if (rnk[0][a]-rnk[0][rt0]==rnk[0][b]-rnk[0][rt0])
		{
			int s1,s2;
			s1= lift.get_th_ancestor(a,dist/2-1);
			s2= lift.get_th_ancestor(b,dist/2-1);
			if (s1==-1||s2==-1)
				cout << "NO"<<ln;
			else
			cout << n-tree[0][s1]-tree[0][s2] << ln;
		}
		else
		{
			int s1,s2;
			s1= lift.get_kth_ancestor(a,dist/2);
			s2= lift.get_kth_ancestor(a,dist/2-1);
			if (s1==-1||s2==-1)
				cout << "NO"<<ln;
			else
			cout << tree[0][s1]-tree[0][s2] << ln;
		}
	}
}
