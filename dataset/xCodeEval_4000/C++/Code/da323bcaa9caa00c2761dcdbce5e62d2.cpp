#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <memory.h>
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

#define sz(a) (int)((a).size())
#define len(a) (int)((a).length())

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())

#define forr(i,n) for (int i = 0; i < (n); ++i)
#define fori(n) forr(i,n)
#define forj(n) forr(j,n)
#define fork(n) forr(k,n)
#define forjn forj(n)
#define forjm forj(m)
#define forkm fork(m)
#define foria(a) fori(sz(a))
#define foriv foria(v)
#define foris fori(len(s))
#define forja(a) forj(sz(a))
#define forjv forj(v)
#define forjs forj(len(s))
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

#define read cin>>
#define write cout<<
#define writeln write endl

#define issa(a,s) istringstream a(s);
#define iss(s) issa(ss,s);

ld dis(ld x, ld y) {return sqrt(x*x+y*y);}
const ld PI = acos(ld(0.0))*2;
#define INF (1<<30);

bool is_palindrome(const string &s, int start, int end) {
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


int euclidd,euclidx,euclidy;
void extendedeuclid(int a,int b)
{
  if(b==0)
  {
    euclidd=a;
    euclidx=1;
    euclidy=0;
    return ;
  }
  extendedeuclid(b,a%b);
  int d1,x1,y1;
  d1=euclidd;
  x1=euclidx;
  y1=euclidy;
  euclidx=y1;
  euclidy=x1-((a/b)*y1);
}
double dist_2point(double x1,double y1,double x2,double y2)
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
vll eratosthenesPrimes(const long N)
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
  const vll primes = eratosthenesPrimes(n);
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
map<long,long> factorExponents(long n)
{
  map<long, long> ret;

  const vll primes = eratosthenesPrimes(n);
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
  cerr << "### " << msg << " ###\n";
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
    ull nsmallest = ripple & -ripple;
    S = ripple | (((nsmallest / smallest) >> 1) - 1);
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
      const int rank_ik = i+k<n ? rank[i+k] : -1;
      const int rank_jk = j+k<n ? rank[j+k] : -1;
      return rank_ik < rank_jk;
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





string s;



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






vii results;


void initialize()
{
}

void solve()
{
  if (s.size() == 1) {
    cout << "1\n";
    cout << "1 1\n";
    return;
  }

  bool is_all_same = true;
  const char c0 = s[0];
  for (const auto& c : s) {
    if (c != c0) {
      is_all_same = false;
      break;
    }
  }
  if (is_all_same) {
    cout << s.size() << "\n";
    for (int i=1; i<=s.size(); ++i) {
      cout << i << " " << s.size()-i+1 << "\n";
    }
    return;
  }

  ZFunction zf(s);
  


  vi histogram(s.length()+1, 0);
  for (int i=1; i<s.length(); ++i) {
    histogram[zf[i]] += 1;
  }
  for (int i=histogram.size()-2; i>=1; --i) {
    histogram[i] += histogram[i+1];
  }

  for (int i=s.length()-1; i>=1; --i) {
    if (zf[i] == s.length() - i) {
      results.push_back(make_pair(s.length() - i, histogram[s.length()-i]+1)); 

    }
  }
  results.push_back(make_pair(s.length(), 1));

  cout << results.size() << "\n";
  for (auto p : results) {
    cout << p.first << " " << p.second << "\n";
  }
}

void output()
{
}


int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  


  

  {
    cin >> s;
  }

  initialize();
  solve();
  output();

  return 0;
}