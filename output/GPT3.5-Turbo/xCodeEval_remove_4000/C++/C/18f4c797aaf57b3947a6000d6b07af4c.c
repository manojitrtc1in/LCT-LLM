#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for(int i=0;i<(n);++i)
#define REP_C(i, n) for(int i=0,_n=(n);i<_n;++i)
#define REP_S(i, s) for(int i=0,_n=strlen(s);i<_n;++i)
#define DWN(i, n, m) for(int i=(n);i>=(m);--i)
#define FOR(i, n, m) for(int i=(n);i<(m);++i)
#define CLR(a) memset(a,0,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define FI first
#define SE second
#define id3(x, y) ((x)*(x)+(y)*(y))
#define id4(i, j, n, m) REP(i, n) REP(j, m)
#define id5 109
#define id6(p, l) (sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <= 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0)
#define id7(p, l) (sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) < 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) < 0)
#define id8(p, l) (p == l.a || p == l.b)

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;
typedef std::vector<int> VI;
typedef std::vector<char> VC;
typedef std::vector<std::string> VS;
typedef std::vector<LL> VL;
typedef std::vector<DB> VD;
typedef std::set<int> SI;
typedef std::set<std::string> SS;
typedef std::map<int, int> MII;
typedef std::map<std::string, int> MSI;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
typedef std::vector<PII> VII;
typedef std::vector<VI> VVI;
typedef std::vector<VII> VVII;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFF 1LL << 60
#define EPS 1e-9
#define OO 1e15
#define PI acos(-1.0)
#define dx {-1, 0, 1, 0}
#define dy {0, 1, 0, -1}

#define REP(i, n) for(int i=0;i<(n);++i)
#define REP_C(i, n) for(int i=0,_n=(n);i<_n;++i)
#define REP_S(i, s) for(int i=0,_n=strlen(s);i<_n;++i)
#define DWN(i, n, m) for(int i=(n);i>=(m);--i)
#define FOR(i, n, m) for(int i=(n);i<(m);++i)
#define CLR(a) memset(a,0,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define FI first
#define SE second
#define id3(x, y) ((x)*(x)+(y)*(y))
#define id4(i, j, n, m) REP(i, n) REP(j, m)
#define id5 109
#define id6(p, l) (sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <= 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0)
#define id7(p, l) (sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) < 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) < 0)
#define id8(p, l) (p == l.a || p == l.b)

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;
typedef std::vector<int> VI;
typedef std::vector<char> VC;
typedef std::vector<std::string> VS;
typedef std::vector<LL> VL;
typedef std::vector<DB> VD;
typedef std::set<int> SI;
typedef std::set<std::string> SS;
typedef std::map<int, int> MII;
typedef std::map<std::string, int> MSI;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
typedef std::vector<PII> VII;
typedef std::vector<VI> VVI;
typedef std::vector<VII> VVII;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFF 1LL << 60
#define EPS 1e-9
#define OO 1e15
#define PI acos(-1.0)
#define dx {-1, 0, 1, 0}
#define dy {0, 1, 0, -1}

#define REP(i, n) for(int i=0;i<(n);++i)
#define REP_C(i, n) for(int i=0,_n=(n);i<_n;++i)
#define REP_S(i, s) for(int i=0,_n=strlen(s);i<_n;++i)
#define DWN(i, n, m) for(int i=(n);i>=(m);--i)
#define FOR(i, n, m) for(int i=(n);i<(m);++i)
#define CLR(a) memset(a,0,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define FI first
#define SE second
#define id3(x, y) ((x)*(x)+(y)*(y))
#define id4(i, j, n, m) REP(i, n) REP(j, m)
#define id5 109
#define id6(p, l) (sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <= 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0)
#define id7(p, l) (sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) < 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) < 0)
#define id8(p, l) (p == l.a || p == l.b)

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;
typedef std::vector<int> VI;
typedef std::vector<char> VC;
typedef std::vector<std::string> VS;
typedef std::vector<LL> VL;
typedef std::vector<DB> VD;
typedef std::set<int> SI;
typedef std::set<std::string> SS;
typedef std::map<int, int> MII;
typedef std::map<std::string, int> MSI;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
typedef std::vector<PII> VII;
typedef std::vector<VI> VVI;
typedef std::vector<VII> VVII;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFF 1LL << 60
#define EPS 1e-9
#define OO 1e15
#define PI acos(-1.0)
#define dx {-1, 0, 1, 0}
#define dy {0, 1, 0, -1}

#define REP(i, n) for(int i=0;i<(n);++i)
#define REP_C(i, n) for(int i=0,_n=(n);i<_n;++i)
#define REP_S(i, s) for(int i=0,_n=strlen(s);i<_n;++i)
#define DWN(i, n, m) for(int i=(n);i>=(m);--i)
#define FOR(i, n, m) for(int i=(n);i<(m);++i)
#define CLR(a) memset(a,0,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define FI first
#define SE second
#define id3(x, y) ((x)*(x)+(y)*(y))
#define id4(i, j, n, m) REP(i, n) REP(j, m)
#define id5 109
#define id6(p, l) (sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <=  0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0)
#define id7(p, l) (sgn(det(p, l.a, l.b)) == 0 && sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <  0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) < 0)
#define id8(p, l) (p == l.a || p == l.b)

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;
typedef std::vector<int> VI;
typedef std::vector<char> VC;
typedef std::vector<std::string> VS;
typedef std::vector<LL> VL;
typedef std::vector<DB> VD;
typedef std::set<int> SI;
typedef std::set<std::string> SS;
typedef std::map<int, int> MII;
typedef std::map<std::string, int> MSI;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
typedef std::vector<PII> VII;
typedef std::vector<VI> VVI;
typedef std::vector<VII> VVII;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFF 1LL << 60
#define EPS 1e-9
#define OO 1e15
#define PI acos(-1.0)
#define dx {-1, 0, 1, 0}
#define dy {0, 1, 0, -1}

#define REP(i, n) for(int i=0;i<(n);++i)
#define REP_C(i, n) for(int i=0,_n=(n);i<_n;++i)
#define REP_S(i, s) for(int i=0,_n=strlen(s);i<_n;++i)
#define DWN(i, n, m) for(int i=(n);i>=(m);--i)
#define FOR(i, n, m) for(int i=(n);i<(m);++i)
#define CLR(a) memset(a,0,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define FI first
#define SE second
#define id3(x, y) ((x)*(x)+(y)*(y))
