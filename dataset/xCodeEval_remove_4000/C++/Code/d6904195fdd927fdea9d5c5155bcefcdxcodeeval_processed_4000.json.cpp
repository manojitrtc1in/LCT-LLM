




using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;
typedef long double ld;
const int MOD = 1e9 + 7;
const ll INF = ll(1e18);















typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void yes() {cout << "Yes" << endl;}
void no() {cout << "No" << endl;}





























bool prime[10000001];
vector<ll> primes;
void Sieve(int n)
{
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
	for(int i = 2; i <= n; i++)
	{
		if(prime[i])
		{
			primes.push_back(i);
		}
	}
}

bool is_prime(ll n)
{
	for(int i = 0; primes[i]*primes[i]<=n; i++)
    {
        if(n % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}

const double EPS = 1E-9;
const double PI = 3.1415926535897932384626433832795;
struct pt {
  double x, y;

  pt() {}
  pt(double x, double y): x(x), y(y) {}

  bool operator< (const pt& p) const {
    return x < p.x - EPS || abs(x - p.x) < EPS && y < p.y - EPS;
  }
};

struct line {
  double a, b, c;

  line() {}
  line(const pt& a, const pt& b) {
    this->a = a.y - b.y;
    this->b = -a.x + b.x;
    this->c = -a.x * this->a - a.y * this->b;

    double t = sqrt(this->a * this->a + this->b * this->b);
    this->a /= t;
    this->b /= t;
    this->c /= t;
  }

  double dist(const pt& p) {
    return a * p.x + b * p.y + c;
  }
};








line perp(const pt& a, const pt& b) {
  line res;
  res.a = a.x - b.x;
  res.b = a.y - b.y;
  res.c = -res.a * (a.x + b.x) / 2 - res.b * (a.y + b.y) / 2;

  double t = sqrt(res.a * res.a + res.b * res.b);
  res.a /= t;
  res.b /= t;
  res.c /= t;
  return res;
}



bool intersect(const line& l1, const line& l2, pt& res) {
  double d = det(l1.a, l1.b, l2.a, l2.b);
  if (abs(d) < EPS)
    return false;

  res.x = -det(l1.c, l1.b, l2.c, l2.b) / d;
  res.y = -det(l1.a, l1.c, l2.a, l2.c) / d;
  return true;
}

double dist(const pt& a, const pt& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int sg(double a) {
  if (abs(a) < EPS)
    return 0;
  return a < 0 ? -1 : +1;
}

bool one_side(const pt& a, const pt& b, const pt& c, const pt& d) {
  line l(a, b);
  
  return sg(l.a * c.x + l.b * c.y + l.c) == sg(l.a * d.x + l.b * d.y + l.c);
}

bool inside(const pt& a, const pt& b, const pt& c, const pt& d) {
  return one_side(a, b, c, d) && one_side(a, c, b, d) && one_side(b, c, a, d);
}

vector<pair<double, pt> > v;

void divide(vector<pt>& a, line l, int s) {
  vector<pt> res;
  forn(i, a.size()) {
    pt& cur = a[i];
    pt& to = a[(i + 1) % a.size()];

    if (sg(l.dist(cur)) == s || sg(l.dist(cur)) == 0)
      res.pb(cur);
    if (sg(l.dist(cur)) * sg(l.dist(to)) < 0) {
      pt r;
      intersect(l, line(cur, to), r);
      res.pb(r);
    }
  }
  a = res;
}

bool inside(vector<pt>& a, pt b) {
  bool res = false;
  forn(i, a.size()) {
    pt p = a[i], q = a[(i + 1) % a.size()];
    if (min(p.x, q.x) - EPS <= b.x && b.x < max(p.x, q.x) - EPS) {
      double sy = p.y + (q.y - p.y) * (b.x - p.x) / (q.x - p.x);
      if (abs(sy - b.y) < EPS)
        return false;
      res ^= b.y < sy;
    }
  }

  return res;
}

double vec(pt a, pt b, pt c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double area(vector<pt> a) {
  double res = 0;
  forn(i, a.size() - 1)
    res += vec(a[0], a[i], a[i + 1]);
  return abs(res) / 2;
}

void rot(pt& a, double al) {
  double x = a.x * cos(al) - a.y * sin(al);
  double y = a.x * sin(al) + a.y * cos(al);
  a.x = x;
  a.y = y;
}

ll power(ll base, ll exp)
{
	ll ans = 1;
    while (exp != 0) 
	{
        if (exp % 2) 
		{    

            ans = (ans * base)%MOD;
			exp--;
        }
        base = (base * base)%MOD;
        exp /= 2;
    }
	ans %= MOD;
	if(ans < 0)
	{
		ans += MOD;
	}
    return ans;
}


ll choose(ll n, ll r)
{
	if(r == 0)
	{
		return 1;
	}
	if(n == r)
	{
		return 1;
	}
	long long denom = 1;
	for (long long i = 2; i <= r; i++)
	{
		denom = (denom * i) % MOD;
	}
	long long res = 1;
	for (long long i = n; i > n - r; i--) 
	{
		res = (res * i) % MOD;
	}
	res = (res * power(denom, MOD - 2)) % MOD;
	return res;
}







































int main()
{
	ios_base::sync_with_stdio(false);
	

	ld px, py, vx, vy, a, b, c, d;
	cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
	

	

	

	ld x1, y1;
	x1 = px + ld(b*vx)/ld(sqrt(vx*vx + vy*vy));
	y1 = py + ld(b*vy)/ld(sqrt(vx*vx + vy*vy));
	ld x2, y2, x3, y3, x6, y6, x7, y7;
	

	

	x2 = px - ld(a*vy)/(ld(2)*ld(sqrt(vx*vx + vy*vy)));
	y2 = py + ld(a*vx)/(ld(2)*ld(sqrt(vx*vx + vy*vy)));
	x7 = px + ld(a*vy)/(ld(2)*ld(sqrt(vx*vx + vy*vy)));
	y7 = py - ld(a*vx)/(ld(2)*ld(sqrt(vx*vx + vy*vy)));
	x3 = px - ld((c)*vy)/(ld(2)*ld(sqrt(vx*vx + vy*vy)));
	y3 = py + ld((c)*vx)/(ld(2)*ld(sqrt(vx*vx + vy*vy)));
	x6 = px + ld((c)*vy)/(ld(2)*ld(sqrt(vx*vx + vy*vy)));
	y6 = py - ld((c)*vx)/(ld(2)*ld(sqrt(vx*vx + vy*vy)));
	

	ld x4, y4, x5, y5, x8, y8;
	x4 = x3 - ld(d*vx)/ld(sqrt(vx*vx + vy*vy));
	y4 = y3 - ld(d*vy)/ld(sqrt(vx*vx + vy*vy));
	x5 = x6 - ld(d*vx)/ld(sqrt(vx*vx + vy*vy));
	y5 = y6 - ld(d*vy)/ld(sqrt(vx*vx + vy*vy));
	
	

	

	cout << fixed << setprecision(20) << x1 << " " << y1 << endl;
	cout << fixed << setprecision(20) << x2 << " " << y2 << endl;
	cout << fixed << setprecision(20) << x3 << " " << y3 << endl;
	cout << fixed << setprecision(20) << x4 << " " << y4 << endl;
	cout << fixed << setprecision(20) << x5 << " " << y5 << endl;
	cout << fixed << setprecision(20) << x6 << " " << y6 << endl;
	cout << fixed << setprecision(20) << x7 << " " << y7 << endl;
	return 0;
}
















