











 
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<pair <int,int> > vpi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
void display(vi &a){for(int z : a)cout << z << " ";cout << endl;}















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
long long id1(long long a, int b){long long res = 1;while (b){if (b & 1){if (res < INF64 / a) res *= a;else return INF64;}if (b > 1){if (a < INF64 / a) a *= a;else return INF64;}b >>= 1;}return res;}


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
class id0{
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
    id0(vector<vi> input, string param){
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





















int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int n,k,l;
  cin >> n >> k >> l;
  vi all(n*k);
  REP(i,0,n*k)
    cin >> all[i];
  sort(all.B,all.E);
  int lim = int(upper_bound(all.B,all.E,all[0]+l)-all.B);
  int u = 0;
  ll out = 0;
  if (lim < n)
  {
    cout << 0;
    return 0;
  }
  REP(i,0,n)
  {
    out += all[u++];
    for(int j = 0; j < k-1;j++)
    {
      if (lim-u > n-i-1)
        u++;
    }
  }
  cout << out;
}
