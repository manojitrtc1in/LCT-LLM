















using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;

typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ld> vld;

typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vs> vvs;

typedef map<int, int> mii;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;



































ld dis(ld x, ld y) {return sqrt(x*x+y*y);}
const ld PI = acos(ld(0.0))*2;


bool id1(const string &s, int start, int end) {
  int siz = end - start + 1;
  if (siz % 2 == 0) {
    int middle = start + siz/2;
    int i;
    for (i = 0; middle - 1 - i >= 0 && middle+i <= end && s[middle-1-i] == s[middle+i]; i++);
    if (middle - i - 1 < 0 || middle+i > end)
      return true;
  } else {
    int middle = start + siz/2;
    int i;
    for (i = 1; middle - i >= 0 && middle+i <= end && s[middle-i]==s[middle+i]; i++);
    if (middle - i < 0 || middle+i > end)
      return true;
  }
  return false;
}


int id5,id9,id6;
void id4(int a,int b)
{
  if(b==0)
  {
    id5=a;
    id9=1;
    id6=0;
    return ;
  }
  id4(b,a%b);
  int d1,x1,y1;
  d1=id5;
  x1=id9;
  y1=id6;
  id9=y1;
  id6=x1-((a/b)*y1);
}
double id7(double x1,double y1,double x2,double y2)
{
  double d;
  d=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
  return d;
}
int binary_search(int a[],int n,int l,int u)
{
  int mid;
  if(l>u)
    return 0;
  mid=floor(l+u)/2;
  if(a[mid]==n)
    return mid;
  else if(a[mid]>n)
    return binary_search(a,n,l,mid-1);
  else
    return binary_search(a,n,mid+1,u);
}
long gcd(long a,long b)
{
  while(b>0) {
    a=a%b;
    a=a^b;
    b=b^a;
    a=a^b;
  }
  return a;
}
long lcm(long a,long b)
{
  long x=(a*b)/gcd(a,b);
  return x;
}
bool isPrime(const long n)
{
  if (n <= 1)
    return false;
  else if (n < 4)
    return true;
  else if (n % 2 == 0)
    return false;
  else if (n < 9)
    return true;
  else if (n % 3 == 0)
    return false;

  for (long f=5; f*f<=n; f+=6) {
    if (n % f == 0)
      return false;
    else if (n % (f+2) == 0)
      return false;
  }
  return true;
}
vll id2(const long N)
{
  vll ret;
  vll tmp(N+1, 1);
  tmp[0] = 0;
  tmp[1] = 0;

  for(long i=2; i<=N; ++i) {
    if (tmp[i] == 0)
      continue;

    ret.push_back(i);
    for (long k=i+i; k<=N; k+=i) {
      tmp[k]=0;
    }
  }
  return ret;
}
vll uniqueFactors(long n)
{
  vll ret;
  const vll primes = id2(n);
  FOREACH(p, primes) {
    if (n == 1 || n < *p)
      break;

    if (n % *p == 0) {
      ret.push_back(*p);
      while (n % *p == 0) {
        n /= *p;
      }
    }
  }

  return ret;
}
map<long,long> id8(long n)
{
  map<long, long> ret;

  const vll primes = id2(n);
  FOREACH(p, primes) {
    if (n == 1 || n < *p)
      break;

    if (n % *p == 0) {
      ret.insert(make_pair(*p,0));
      while (n % *p == 0) {
        n /= *p;
        ret[*p] += 1;
      }
    }
  }

  return ret;
}
long long bigmod(long long b,long long p,long long m)
{
  if(b==0) return 0;
  long long x,power;
  x=1;
  power=b%m;
  while(p)
  {
    if(p%2==1)
      x=(x*power)%m;
    power=(power*power)%m;
    p=p/2;
  }
  return x;
}
void assert(bool b)
{
  if (!b)
    throw 0;
}
template <int n>
struct nbest
{
  vector<pair<ll, int> > p;
  nbest():p(n+1)
  {
    foria(p) p[i].first = p[i].second = -1;
  }
  void add(ll value, int key)
  {
    p[n] = make_pair(value, key);
    sort(rall(p));
  }
  ll getValue(int pos, int exceptKey = -2)
  {
    if (exceptKey == -1)
      exceptKey = -2;
    if (p[pos].second == exceptKey)
      ++pos;
    return p[pos].first;
  }
  int getKey(int pos, int exceptKey = -2)
  {
    if (exceptKey == -1)
      exceptKey = -2;
    if (p[pos].second == exceptKey)
      ++pos;
    return p[pos].second;
  }
  bool has(int pos, int exceptKey = -2)
  {
    if (exceptKey == -1)
      exceptKey = -2;
    if (p[pos].second == exceptKey)
      ++pos;
    return p[pos].second != -1;
  }
};

template <typename T>
void dumpContents(const vector<T>& v,
                  const string& msg="")
{
  cerr << "
  if (v.empty())
    return;

  for (typename vector<T>::const_iterator it=v.begin();
       it != v.end(); ++it) {
    cerr << *it << " ";
  }
  cerr << endl;
}

void printBit(ull S, int n=64){
  for(int i=n-1; i>=0; i--){
    if(S>>i & 1) cout << 1;
    else cout << 0;
  }
  cout << endl;
}

void subsetCombination(int n, int k){
  ull S = (1ULL << k) - 1ULL;
  ull E = ~((1ULL << n) - 1ULL);
  while(!(S & E)){
    printBit(S, n);
    ull smallest = S & -S;
    ull ripple = S + smallest;
    ull id3 = ripple & -ripple;
    S = ripple | (((id3 / smallest) >> 1) - 1);
  }
}

void grayCode(int n){
  int N = 1 << n;
  ull G = 0;
  for(int i=0; i<N; i++){
    G = i ^ (i >> 1ULL);
    printBit(G, n);
  }
}

int bitCount(ull n)
{
  int cnt = 0;
  while(n != 0) {
    cnt += 1;
    n &= (n-1); 

  }
  return cnt;
}

namespace std
{
  template<typename A, typename B>
  struct hash<pair<A, B> >
  {
    typedef std::size_t value_type;

    const hash<A> ah;
    const hash<B> bh;

    hash()
      : ah(), bh()
    {}

    value_type operator()(const pair<A,B>& p) const
    {
        value_type const h1 = ah(p.first);
        value_type const h2 = bh(p.second);
        return h1 ^ (h2 << 1);
    }
  };
}


class SuffixArray
{
  const std::string S;
  int n;
  int k;
  vi rank; 

  vi tmp;
  vi sa;
  vi lcp;

public:
  SuffixArray(const std::string& _S)
    : S(_S), n(S.length()), k(0)
  {
    rank.reserve(n+1);
    tmp.reserve(n+1);
    sa.reserve(n+1);
  }

  

  

  

  

  bool operator()(int i, int j) const
  {
    if (rank[i] != rank[j]) {
      return rank[i] < rank[j];
    } else {
      const int id0 = i+k<n ? rank[i+k] : -1;
      const int id10 = j+k<n ? rank[j+k] : -1;
      return id0 < id10;
    }
  }

  
  void construct()
  {
    

    for (int i=0; i<=n; ++i) {
      sa.push_back(i);
      rank.push_back(i<n ? S[i] : -1);
      tmp.push_back(0);
    }

    for (k=1; k<=n; k*=2) {
      std::sort(sa.begin(), sa.end(), *this);

      

      tmp[sa[0]] = 0; 

      for (int i=1; i<=n; ++i) { 

        tmp[sa[i]] = tmp[sa[i-1]] + (this->operator()(sa[i-1], sa[i]) ? 1 : 0);
      }
      rank.swap(tmp);
    }
  }

  
  void constructLcp()
  {
    lcp.resize(n+1, 0);
    int h = 0;
    for (int i=0; i<n; ++i) {
      int j = sa[rank[i]-1];

      if (h>0) --h;
      for (; j+h<n && i+h<n; ++h) {
        if (S[j+h] != S[i+h]) break;
      }
      lcp[rank[i]-1] = h;
    }
    lcp[n] = -1; 

  }

  
  bool contain(const string& t) const
  {
    int i = 0;
    int j = sa.size();

    while (true) {
      if (j<i) return false;

      int m = (i+j)/2;
      const int r = strncmp(&S[sa[m]], &t[0], MIN(n-sa[m], t.size()));
      if (r<0) {
        i = m+1;
      } else if (r>0) {
        j = m-1;
      } else if (n-sa[m] < t.size()) {
        i = m+1;
      } else {
        return true;
      }
    }
  }

  int lower_bound(const string& t) const
  {
    int i = 0;
    int j = sa.size();

    while (true) {
      if (j<i) return i;

      int m = (i+j)/2;
      const int r = strncmp(&S[sa[m]], &t[0], MIN(n-sa[m], t.size()));
      if (r<0) {
        i = m+1;
      } else if (r>0) {
        j = m-1;
      } else if (n-sa[m] < t.size()) {
        i = m+1;
      } else {
        j = m-1;
      }
    }
  }

  int upper_bound(const string& t) const
  {
    int i = 0;
    int j = sa.size();

    while (true) {
      if (j<i) return i;

      int m = (i+j)/2;
      const int r = strncmp(&S[sa[m]], &t[0], MIN(n-sa[m], t.size()));
      if (r<0) {
        i = m+1;
      } else if (r>0) {
        j = m-1;
      } else if (n-sa[m] < t.size()) {
        i = m+1;
      } else {
        i = m+1;
      }
    }
  }

  string toString() const
  {
    ostringstream oss;
    for (int i=0; i<n+1; ++i) {
      const int p = sa[i];
      oss << p << " " << S.substr(p) << "\n";
    }
    return oss.str();
  }

  const vi& getSa() const { return sa;}
  const vi& getLcp() const { return lcp; }
  const vi& getRank() const { return rank; }
};


class ZFunction
{
  vi z;

public:
  ZFunction (const string& s)
  {
    

    int l = 0, r = 0;
    const int n = s.length();
    z.resize(n);

    for (int k=1; k<n; ++k) {
      if (r<k) {
        

        for (int i=0; k+i<n; ++i) {
          if (s[i] != s[k+i]) break;
          z[k] += 1;
        }
        if (z[k]>0) {
          

          l = k;
          r = k + z[k] - 1;
        }
      } else {
        

        const int kk = k-l;
        const int b  = r-k+1;
        if (z[kk] < b) {
          

          

          z[k] = z[kk];
        } else {
          

          l = k;
          z[k] = r-k+1;
          for (; r+1<n; ++r) {
            if (s[r+1-l] != s[r+1]) break;
            z[k] += 1;
          }
        }
      }
    }
  }

  int operator[](int index) const
  {
    assert(index>0);
    return z[index];
  }

  string toString() {
    ostringstream oss;
    oss << " 0\t-\n";
    for (int i=1; i<z.size(); ++i) {
      oss << i << "\t" << z[i] << "\n";
    }
    return oss.str();
  }
};





const static int N = 100001;
int n,m;
vi a;
vector<vi> b(N, vector<int>());





void initialize()
{
}

void solve()
{
  if (m<=2) {
    cout << 0 << endl;
    return;
  }

  for (int i=0; i<a.size()-1; ++i) {
    if (a[i] != a[i+1]) {
      b[a[i]].push_back(a[i+1]);
      b[a[i+1]].push_back(a[i]);
    }
  }

  pair<int,ll> reduction = make_pair(0,0LL);

  

  

  for (int x=1; x<=N; ++x) {
    vi& vb = b[x];
    if (vb.empty()) continue;

    sort(vb.begin(), vb.end());
    const int median = vb[vb.size()/2];
    ll sum = 0LL;
    for (const int t : vb) {
      sum += ABS(t, median);
      sum -= ABS(t, x);
    }
    if (sum < reduction.second) {
      reduction.first = x;
      reduction.second = sum;
    }
  }

  ll ret = reduction.second;
  for (int i=0; i<a.size()-1; ++i) {
    ret += ABS(a[i], a[i+1]);
  }
  
  

  cout << ret << endl;

}

void output()
{
}


int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  


  

  {
    cin >> n >> m;
    a.reserve(m);
    for (int i=0; i<m; ++i) {
      int x;
      cin >> x;
      a.push_back(x);
    }
  }

  initialize();
  solve();
  output();

  return 0;
}
