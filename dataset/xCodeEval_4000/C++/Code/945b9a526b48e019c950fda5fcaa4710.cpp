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
#include<ext/pb_ds/assoc_container.hpp>
#include <ctime>
#include<ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair <int,int> > vpi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
void display(vi &a){for(int z : a)cout << z << " ";cout << endl;}
#define trace(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
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


class DSU{
  vi par;
  vi siize;
  public:
    DSU(int n)
    {
      par.resize(n);
      siize.resize(n);
      REP(i,0,n)
      {
        par[i]=i;
        siize[i]=1;
      }
    }
  public:
    int get(int x)
    {
      return (x == par[x] ? x : par[x] = get(par[x]));
    }
  public:
    void merge(int a, int b)
    {
      int x = get(a);
      int y = get(b);
      if (x == y)return;
      if (siize[x] < siize[y])swap(x,y);par[y] = x;siize[x] += siize[y];
    }
};
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
class SparseTable2D{
  vector<vector< vector<vi > > > sparse;
  vector<vi> inp;
  int m,n;
  private: int lg2(int x){
		int out = 0;
		while((1 << out) <= x)
			out++;
		return out-1;
	}
  public:
    int rmin(int x1, int y1, int x2, int y2)
    {
      int lenx = x2-x1+1;
      int lx = lg2(lenx)+1;
      int leny = y2-y1+1;
      int ly = lg2(leny)+1;
      return min(min(sparse[lx][x1][ly][y1],sparse[lx][x1][ly][y2+1-(1<<ly)]),min(sparse[lx][x2+1-(1<<lx)][ly][y1],sparse[lx][x2+1-(1<<lx)][ly][y2+1-(1<<ly)]));
    }
  public:
    SparseTable2D(vector<vi> input, string param){
      n = input.Z;
      m = input[0].Z;
      inp = input;
      if (param == "min")
        prepromin();
      
  }
  private:
    void prepromin()
    {
      int lln,lm;
      lln=lg2(n)+1;
      lm=lg2(m)+1;
      sparse.resize(lln);
      REP(i,0,lln)
        sparse[i].resize(n);
      REP(i,0,lln)
        REP(j,0,n)
          sparse[i][j].resize(lm);
      REP(i,0,lln)
        REP(j,0,n)
          REP(k,0,lm)
            sparse[i][j][k].resize(m);
      REP(i,0,n)
      {
        REP(j,0,m)
          sparse[0][i][0][j]=inp[i][j];
        REP(j,1,lm)
          for(int k = 0; k + (1<<j)-1 < m;k++)
            sparse[0][i][j][k]=min(sparse[0][i][j-1][k],sparse[0][i][j-1][k+(1<<(j-1))]);
      }
      REP(i,1,lln)
        for (int j = 0; j +(1<<i)-1<n;j++)
          REP(k,0,lm)
            REP(h,0,m)
              sparse[i][j][k][h]=min(sparse[i-1][j][k][h],sparse[i-1][j+(1<<(i-1))][k][h]);
    }
};
class SparseTable{
	vector<vll> sparse;
	int n;
	vi input;
	private: int lg2(int x){
		int out = 0;
		while((1 << out) <= x)
			out++;
		return out-1;
	}
	public: int rmaxpos(int left, int right){
		int len = right-left+1;
		int lg = lg2(len);
		return (input[sparse[left][lg]] > input[sparse[left+len-(1 << lg) ][lg]]? sparse[left][lg]:sparse[left+len-(1 << lg)][lg]);
	}
	public: int rmaxval(int left, int right){
		int len = right-left+1;
		int lg = lg2(len);
		return (input[sparse[left][lg]] > input[sparse[left+len-(1 << lg) ][lg]]? input[sparse[left][lg]]:input[sparse[left+len-(1 << lg)][lg]]);
	}
	public: int rminpos(int left, int right){
		int len = right-left+1;
		int lg = lg2(len);
		return (input[sparse[left][lg]] < input[sparse[left+len-(1 << lg) ][lg]]? sparse[left][lg]:sparse[left+len-(1 << lg)][lg]);
	}
	public: int rminval(int left, int right){
		int len = right-left+1;
		int lg = lg2(len);
		return (input[sparse[left][lg]] < input[sparse[left+len-(1 << lg) ][lg]]? input[sparse[left][lg]]:input[sparse[left+len-(1 << lg)][lg]]);
	}
	public: ll rsum(int left, int right){
		ll ans = 0;
		int pos;
		while (left <= right)
		{
			for(int i = 19; i>=0; i--)
				if ((1 << i) <= right-left+1)
				{
					pos = i;
					break;
				}
		ans += sparse[left][pos];
		left = left + (1<<pos);
		}
		return ans;
	}
	public: SparseTable(vi inp, string operation){
		input= inp;
		n=inp.Z;
		if (operation == "min")
			prepromin();   
		else if (operation == "max")
			prepromax();
		else if (operation == "sum")
			preprosum();
	}
	private: void prepromin(){
		sparse.resize(n);
		int x = lg2(n)+1;
		REP(i,0,n)
			sparse[i].resize(x);
		REP(i,0,n)
			sparse[i][0]=i;
		REP(j,1,x)
			for(int i = 0; i + (1 << (j))-1 < n; i++)
				sparse[i][j] = (input[sparse[i][j-1]] < input[sparse[i+(1<<(j-1))][j-1]] ? sparse[i][j-1] : sparse[i+(1<<(j-1))][j-1]); 

	}
	void prepromax(){
		sparse.resize(n);
		int x = lg2(n)+1;
		REP(i,0,n)
			sparse[i].resize(x);
		REP(i,0,n)
			sparse[i][0]=i;
		REP(j,1,x)
			for(int i = 0; i + (1 << (j))-1 < n; i++)
				sparse[i][j] = (input[sparse[i][j-1]] > input[sparse[i+(1<<(j-1))][j-1]] ? sparse[i][j-1] : sparse[i+(1<<(j-1))][j-1]); 

	}
	void preprosum(){
		sparse.resize(n);
		int x = lg2(n)+1;
		REP(i,0,n)
			sparse[i].resize(x);
		REP(i,0,n)
			sparse[i][0]=input[i];
		REP(j,1,x)
			for(int i = 0; i + (1 << (j))-1 < n; i++)
				sparse[i][j] = sparse[i][j-1]+sparse[i+(1<<(j-1))][j-1];
	}
};


class Vector{
  public:
  pll x;
  public:
    Vector(pll a, pll b)
  {
    x.F=b.F-a.F;
    x.S=b.S-a.S;
  }
  public:
    long double getMagnitude()
    {
      return sqrtl(x.F*x.F+x.S*x.S);
    }
};
class Line{
  public:
    pll x,y;
  public:
    Line(pll a, pll b)
    {
      x=a;
      y=b;
    }
  private:
    long double dotProduct(Vector a, Vector b)
    {
      return a.x.F*b.x.F+a.x.S*b.x.S;
    }
  private:
    long double crossProduct(Vector a, Vector b)
    {
      return a.x.F*b.x.S-a.x.S*b.x.F;
    }
  private:
    long double magnitude(Vector a)
    {
      return a.getMagnitude();
    }
  public:
    long double distanceToA(pll c)
    {
      return dotProduct(Vector(x,y),Vector(x,c))/magnitude(Vector(x,y));
    }
  public:
    long double orthogonalDistance(pll c)
    {
      return crossProduct(Vector(x,y),Vector(x,c))/magnitude(Vector(x,y));
    }
  public:
    pair<long double,long double> intersection(Line l)
    {
      pair<long double,long double> ans;
      ans.F = (long double)((x.F*y.S-x.S*y.F)*(l.x.F-l.y.F)-(x.F-y.F)*(l.x.F*l.y.S-l.x.S*l.y.F))/((x.F-y.F)*(l.x.S-l.y.S)-(x.S-y.S)*(l.x.F-l.y.F));
      ans.S = (long double)((x.F*y.S-x.S*y.F)*(l.x.S-l.y.S)-(x.S-y.S)*(l.x.F*l.y.S-l.x.S*l.y.F))/((x.F-y.F)*(l.x.S-l.y.S)-(x.S-y.S)*(l.x.F-l.y.F));
      return ans;
    }
};
class PruferCode{
  vi code;
  vpi edges;
  public:
    PruferCode(vi cc){
      code =cc;
      findEdges();
    }
  private:
    void findEdges(){
      map<int,int> mp;
      set<int> has;
      set<int> wait;
      for (int z: code){
        mp[z]++;
        has.insert(z);
      }
      REP(i,0,code.Z+2)
        if (!has.count(i))
          wait.insert(i);
      REP(i,0,code.Z)
      {
        int now = *wait.B;
        edges.PB(MP(now,code[i]));
        mp[now]++;
        mp[code[i]]--;
        if (mp[code[i]]==0)
        {
          has.erase(code[i]);
          wait.insert(code[i]);
        }
        wait.erase(now);
      }
      assert(wait.Z ==2);
      edges.PB(MP(*wait.B,*wait.RB));
    }
  public:
    vpi getEdges()
    {
      return edges;
    }
};
class Segment{
  pll x,y;
  public:
    Segment(pll a, pll b)
    {
      x=a;
      y=b;
    }
  private:
    long double dotProduct(Vector a, Vector b)
    {
      return a.x.F*b.x.F+a.x.S*b.x.S;
    }
  private:
    long double crossProduct(Vector a, Vector b)
    {
      return a.x.F*b.x.S-a.x.S*b.x.F;
    }
  private:
    long double magnitude(Vector a)
    {
      return a.getMagnitude();
    }
  public:
    long double distanceToA(pll c)
    {
      return dotProduct(Vector(x,y),Vector(x,c))/magnitude(Vector(x,y));
    }
  public:
    long double distanceToSegment(pll c)
    {
      if (distanceToA(c) >= 0 && distanceToA(c) <= magnitude(Vector(x,y)))
        return crossProduct(Vector(x,y),Vector(x,c))/magnitude(Vector(x,y));
      else
        return min(magnitude(Vector(x,c)), magnitude(Vector(y,c)));
    }
};
class SegmentTree{
  int len;
  vll all;
  vll seg;
  public:
    SegmentTree(vll inp)
    {
      len = inp.Z;
      all = inp;
      seg.resize(4*len);
      build(1,0,len-1);
    }
  void build(int id, int l, int r)
  {
    if (l==r)
    {
      seg[id] = all[l];
      return ;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    seg[id] = seg[2*id]+seg[2*id+1];
  }
  void update(int id, int l, int r, int sl, int sr, ll val)
  {
    if (r < sl || sr < l)
      return ;
    if (sl <= l && sr >= r)
    {
      seg[id] += val;
      return ;
    }
    int mid = (l+r)/2;
    update(2*id,l,mid,sl,sr,val);
    update(2*id+1,mid+1,r,sl,sr,val);
    seg[id]=seg[2*id]+seg[2*id+1];
  }
  ll query(int id, int l, int r, int sl, int sr)
  {
    if (r < sl || sr < l)
      return 0;
    if (sl <= l && sr >= r)
      return seg[id];
    int mid = (l+r)/2;
    return (query(2*id,l,mid,sl,sr)+query(2*id+1,mid+1,r,sl,sr));
  }
};
class HopcroftKarp{
  vi matched;
  vector<vpi> adj;
  int left;
  int right;
  public:
  HopcroftKarp(vector<vpi> inp,int l, int r)
  {
    adj = inp;
    left = l;
    matched.resize(l);
    REP(i,0,l)
      matched[i] = -1;
    right = r;
  }
  public:
  vi match()
  {
    bool cont = true;
    set<int> lfree,rfree;
    REP(i,0,left)
      lfree.insert(i);
    REP(i,left,left+right)
      rfree.insert(i);
    vector<bool> yet(left,0);
    REP(i,0,left)
      REP(j,0,adj[i].Z)
      if (adj[i][j].S==1 && rfree.count(adj[i][j].F)&& !yet[i])
      {
        yet[i]=true;
        matched[i] = adj[i][j].F;
        adj[i][j].S = 2;
        REP(x,0,adj[adj[i][j].F].Z)
          if (adj[adj[i][j].F][x].F == i)
            adj[adj[i][j].F][x].S = 2;
        rfree.erase(adj[i][j].F);
        lfree.erase(i);
      }
    while(cont)
    {
      vi par(left+right,-1);
      queue<pi> kyou;
      for (int z : lfree)
        kyou.push(MP(z,0));
      int update = -1;
      vi vis(left+right,0);
      while(kyou.Z)
      {
        pi frt = kyou.front();
        kyou.pop();
        if (rfree.count(frt.F))
        {
          update = frt.F;
          break;
        }
        if (frt.S == 0)
        {
          for (pi z : adj[frt.F])
          {
            if (z.S == 1 && !vis[z.F])
            {
              par[z.F]=frt.F;
              vis[z.F] = 1;
              kyou.push(MP(z.F,1));
            }
          }
        }
        else
        {
          for (pi z : adj[frt.F])
          {
            if (z.S == 2 && !vis[z.F])
            {
              par[z.F]=frt.F;
              vis[z.F] = 1;
              kyou.push(MP(z.F,0));
            }
          } 
        }
      }  
      int x = update;
      int cnt = 0;
      while (x != -1 && par[x] != -1)
      {
        REP(i,0,adj[x].Z)
          if (adj[x][i].F == par[x])
          {
            adj[x][i].S = (cnt==0?2:1); 
            if (cnt==0)
            {
              matched[par[x]]=x;
              rfree.erase(x);
              lfree.erase(par[x]);
            }
          }
        REP(i,0,adj[par[x]].Z)
          if (adj[par[x]][i].F == x)
            adj[par[x]][i].S = (cnt==0?2:1); 
        cnt++;
        cnt%=2;
        x=par[x];
      }
      if (update == -1)
        cont = false;
    }
    return matched;
  }
};

class Triangle{
  pll x,y,z;
  public:
  Triangle(pll a,pll b, pll c)
  {
    x=a;y=b;z=c;
  }
  private:
  long double crossProduct(Vector a, Vector b)
  {
    return a.x.F*b.x.S-a.x.S*b.x.F;
  }
  public:
  long double perimeter()
  {
    long double s1,s2,s3;
    s1=Vector(x,y).getMagnitude();
    s2=Vector(y,z).getMagnitude();
    s3=Vector(x,z).getMagnitude();
    return s1+s2+s3;
  }
  public:
  long double area()
  {
    return abs(crossProduct(Vector(x,y),Vector(x,z)));
  }
};

class SuffixArray{
  vi order;
  vi lcp;
  string str;
  public:
  SuffixArray(string in)
  {
    str = in;
    str += '$';
    order.resize(str.L);
    lcp.resize(str.L);
    compute();
  }
  void compute()
  {
    vector<pair<char,int> > a;
    vi equi(order.Z);
    vi bij(order.Z);
    REP(i,0,str.L)
      a.PB(MP(str[i],i));
    sort(a.B,a.E);
    REP(i,0,str.L)
      order[i] = a[i].S;
    equi[order[0]]=0;
    int r = 0;
    REP(i,1,str.L)
    {
      if (a[i].F == a[i-1].F)
        equi[order[i]] = r;
      else
        equi[order[i]] = ++r;
    }
    int k = 0;
    while((1<<k) <str.L)
    {
      vector<pair<pi,int> > a(str.L);
      REP(i,0,str.L)
        a[i] = MP(MP(equi[i],equi[(i+(1<<k))%(str.L)]),i);
      sort(a.B,a.E);
      REP(i,0,str.L)
      {
        order[i] = a[i].S;
        bij[order[i]]=i;
      }
      int r = 0;
      equi[order[0]]=0;
      REP(i,1,str.L)
      {
        if (a[i].F == a[i-1].F)
          equi[order[i]]=r;
        else
          equi[order[i]]=++r;
      }
      k++;
    }
    k = 0;
    REP(i,0,str.L-1)
    {
      int p = bij[i];
      int j = order[p-1];
      while(i+k < str.L && j+k <str.L  && str[i+k]==str[j+k])k++;
      lcp[p] = k;
      k = max(k-1,0LL);
    }
  }
  public:
  int count(string ptr)
  {
    int low = 0;
    int hi = str.L-1;
    int res1,res2;
    res1 = 0;
    res2 = 1e9;
    while(low <= hi)
    {
      int mid=(low+hi)/2;
      bool gr = false;
      int i = 0;
      for( i ; i< min((ll)ptr.L,(ll)str.L-order[mid]); i++)
      {
        if (ptr[i] != str[order[mid]+i])
        {
          if (ptr[i] > str[order[mid]+i])
            gr = true;
          break;
        }
      }
      if (i == ptr.L)
      {
        res2=min(res2,mid);
        hi=mid-1;
      }
      else if (!gr)
        hi=mid-1;
      else
        low = mid+1;
    }
    low = 0;
    hi=str.L-1;
    while(low <= hi)
    {
      int mid=(low+hi)/2;
      bool gr = false;
      int i = 0;
      for( i ; i< min((ll)ptr.L,(ll)str.L-order[mid]+1); i++)
      {
        if (ptr[i] != str[order[mid]+i])
        {
          if (ptr[i] > str[order[mid]+i])
            gr = true;
          break;
        }
      }
      if (i == ptr.L)
      {
        res1=max(res1,mid);
        low=mid+1;
      }
      else if (!gr)
        hi=mid-1;
      else
        low = mid+1;
    }
    if (res2 == 1e9)
      return 0;
    return (res1-res2+1);
  }
  public:
  vi get(){
    return order;
  }
  public:
  vi getLcp(){
    return lcp;
  }
  public:
  ll diffSubstrings()
  {
    ll out = 0;
    REP(i,1,str.L)
      out += str.L - order[i] - lcp[i]-1;
    return out;
  }
};
string longestCommonSubstring(string a, string b)
{
  int len = 0;
  string res = a+'%'+b;
  SuffixArray sf = SuffixArray(res);
  vi order = sf.get();
  vi lcp = sf.getLcp();
  vi col(order.Z);
  REP(i,0,order.Z)
  {
    if (order[i] < a.L)
      col[order[i]] = 1;
    else if (order[i] > a.L)
      col[order[i]] = 2;
  }
  int pos = -1;
  REP(i,1,order.Z)
    if (col[order[i]]+col[order[i-1]] == 3)
    {
      if (lcp[i] > len)
      {
        len = max(len,lcp[i]);
        pos = (col[order[i]] == 1?order[i]:order[i-1]);
      }
    }
  return a.substr(pos,len);
}
class Factorial{
  int nax;
  vll fa;
  vll in;
  public:
    Factorial(int n)
    {
      nax = n+10;
      fa.assign(nax,1);
      in.resize(nax);
      REP(i,1,nax)
        fa[i] = (fa[i-1]*i)%mod;
      REP(i,0,nax)
        in[i] = mbinp(fa[i],mod-2);
    }
  public:
    ll fac(int x)
    {
      return fa[x];
    }
  public:
    ll inv(int x)
    {
      return in[x];
    }
  public:
    ll comb(int x, int y)
    {
      if (x < y || x < 0 || y < 0)
        return 0;
      return (((fa[x]*in[y])%mod)*in[x-y])%mod;
    }
};
class WaveletTree{
  typedef vector<int>::iterator it;
  vector<vi> pre;
  int mx;
  public:
    WaveletTree(vi &inp, int delta)
    {
      pre.resize(4*inp.Z);
      mx = delta+1;
      build(inp.B,inp.E,0,mx-1,1);
    }
  void build(it b, it e, int l, int r, int d)
  {
    if (l == r)
      return;
    int mid = (l+r)/2;
    pre[d].PB(0);
    for (it x = b; x != e; x++)
      pre[d].PB(pre[d].back()+(*x<=mid));
    it p = stable_partition(b,e,[=](int i){return i <= mid;});
    build(b,p,l,mid,2*d);
    build(p,e,mid+1,r,2*d+1);
  }
  int occurrenceOf(int c, int i)
  {
    i++;
    int l = 0;
    int r = mx-1;
    int d = 1;
    int mid;
    int shift;
    while(l != r)
    {
      int mid = (l+r)/2;
      shift = pre[d][i];
      d*=2;
      if (c <= mid)
      {
        i = shift;
        r= mid;
      }
      else
      {
        i -= shift;
        l = mid+1;
        d++;
      }
    }
    return i;
  }
  int kthSmallest(int k, int i, int j)
  {
    j++;
    int l = 0,r=mx-1,d=1,ri,rj;
    while(l!= r)
    {
      int mid = (l+r)/2;
      ri = pre[d][i];
      rj = pre[d][j];
      d *= 2;
      if (k <= rj-ri)
      {
        i = ri;
        j = rj;
        r = mid;
      }
      else
      {
        k -= rj-ri;
        i -= ri;
        j -= rj;
        l = mid+1;
        d++;
      }
    }
    return r;
  }
  int rectangle(int i, int j, int a, int b, int d=1){
    if (b < a || j < i)
      return 0;
    int l = a, r = b;
    if (b < l || a > r)
      return 0;
    if (l <= a & r >= b)
      return j-i;
    int mid = (a+b)/2, ri=pre[d][i], rj= pre[d][j];
    return rectangle(ri,rj,a,mid,d*2)+rectangle(i-ri,j-rj,mid+1,b,2*d+1);
  }
};
class Centroid{
  int n;
  vector<set<int> > adj;
  vi par;
  vi has;
  public:
    Centroid(vector<vi> ad)
    {
      n = ad.Z;
      adj.resize(n);
      par.resize(n);
      has.resize(n);
      REP(i,0,n)
        for (int z : ad[i])
        {
          adj[i].insert(z);
          adj[z].insert(i);
        }
      build(0,-1);
    }
  int dfs(int x, int p)
  {
    has[x] = 1;
    for (int z : adj[x])
      if (z!=p)
        has[x] += dfs(z,x);
    return has[x];
  }
  int centroid(int x, int p, int sz)
  {
    for (int z: adj[x])
      if (z != p)
        if (has[z] > sz/2)
          return centroid(z,x,sz);
    return x;
  }
  void build(int x,int p)
  {
    int n = dfs(x,p);
    int c = centroid(x,p,n);
    if (p == -1)
      p = c;
    par[c] = p;
    vi tmp(adj[c].B,adj[c].E);
    for (int z : tmp)
    {
      adj[z].erase(c);
      adj[c].erase(z);
    }
    for (int z : tmp)
      build(z,c);
  }
  public:
    vi decompose()
    {
      return par;
    }
};
class Node{
  public:
    Node *children[26];
  public:
    int cnt = 0;
  public:
    char t;
  public:
  Node(int alphabet, char c)
  {
    REP(i,0,alphabet)
      this->children[i] = NULL;
    t = c;
  }
};

class Trie{
  Node *root;
  int alphabet;
  char start;
  public:
  Trie(int alphabet, char start)
  {
    this->alphabet = alphabet;
    root = new Node(alphabet,'*');
    this->start = start;
  }
  public:
    void insert(string str)
    {
      Node *cur = root;
      REP(i,0,str.L)
      {
        if (cur->children[str[i]-start] == NULL)
        {
          cur->children[str[i]-start] = new Node(alphabet,str[i]);
        }
        cur = cur->children[str[i]-start];
      }
      cur->cnt++;
    }
  public:
    bool exists(string str)
    {
      Node *cur = root;
      REP(i,0,str.L)
      {
        if (cur->children[str[i]-start] == NULL)
          return false;
        cur = cur->children[str[i]-start];
      }
      return (cur->cnt > 0);
    }
  public:
    int count(string str)
    {
      Node *cur = root;
      REP(i,0,str.L)
      {
        if (cur->children[str[i]-start] == NULL)
          return 0;
        cur = cur->children[str[i]-start];
      }
      return (cur->cnt);
    }
  public:
    void erase(string str)
    {
      Node *cur = root;
      REP(i,0,str.L)
      {
        if (cur->children[str[i]-start] == NULL)
          cur->children[str[i]-start] = new Node(alphabet,str[i]);
        cur = cur->children[str[i]-start];
      }
      cur->cnt--;
    }
};
























int rd(int x)
{
    return rand()%x;
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(unsigned(time(0)));
  int n;
  cin >> n;
  if (n == 1)
  {
      cout << "! 1" << endl;
      return 0;
  }
  if (n ==2)
  {
      int x,y;
      cout << "? 1" << endl;
      cin >> x;
      cout << "? 2" << endl;
      cin >> y;
      if (x > y)
          cout << "! 2" << endl;
      else
          cout << "! 1" << endl;
      return 0;
  }
  if (n == 3)
  {
      int x,y,z;
      cout << "? 1"<<endl;
      cin >> x;
      cout << "? 2"<<endl;
      cin >> y;
      cout << "? 3"<<endl;
      cin >> z;
      if (y<z && y<x)
          cout << "! 2" << endl;
      else if (x <y)
          cout << "! 1" << endl;
      else
          cout <<"! 3" << endl;
  }
  cout << "? 1" << endl;
  vi a(n,-1);
  cin >> a[0];
  cout << "? 2" << endl;
  cin >> a[1];
  cout << "? " << n-1 << endl;
  cin >> a[n-2];
  cout << "? "<< n << endl;
  cin >> a[n-1];
  if (a[0] < a[1])
  {
      cout << "! 1" << endl;
      return 0;
  }
  if (a[n-1] < a[n-2])
  {
      cout << "! "<< n << endl;
      return 0;
  }
  int low = 0;
  int hi = n-1;
  while(low <= hi)
  {
      int mid  = (low+hi)/2;
      int x,y,z;
      if (a[mid] != -1)
          y = a[mid];
      else
      {
          cout << "? " << mid+1 << endl;
          cin >> y;
          a[mid]=y;
      }
      if (a[mid-1] != -1)
          x = a[mid-1];
      else
      {
          cout << "? " << mid << endl;
          cin >> x;
          a[mid-1]=x;
      }
      if (a[mid+1] != -1)
          z = a[mid+1];
      else
      {
          cout << "? " << mid+2 << endl;
          cin >> z;
          a[mid+1] = z;
      }
      if (y<x&&y<z)
      {
          cout << "! " << mid+1 << endl;
          return 0;
      }
      if (a[low+1] == -1)
      {
          cout << "? "<< low+2 << endl;
          cin >> a[low+1];
      }
      if ((a[low]-a[low+1])>0 && (a[mid]-a[mid-1]) > 0)
          hi = mid;
      else
          low=mid;
  }
}
