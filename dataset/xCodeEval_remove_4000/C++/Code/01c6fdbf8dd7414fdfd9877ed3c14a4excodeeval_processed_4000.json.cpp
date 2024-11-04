
using namespace std;
using namespace std::chrono;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;



















  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr)







  ll X;       \
  cin >> X

  ll X, Y;        \
  cin >> X >> Y

  ll X, Y, Z;         \
  cin >> X >> Y >> Z

int ant = 0;
int cat = 0;
void id0()
{
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
}
template <typename L, typename R>
istream &operator>>(istream &in, pair<L, R> &P)
{
  in >> P.first >> P.second;
  return in;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &V)
{
  for (auto &elem : V)
    in >> elem;
  return in;
}
template <class L, class R>
ostream &operator<<(ostream &out, pair<L, R> const &val)
{
  if (out.rdbuf() == cout.rdbuf())
    return (out << val.first << " " << val.second);
  else
    return (out << "{" << val.first << "," << val.second << "}");
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, Container const &X)
{
  if (os.rdbuf() == cout.rdbuf())
  {
    for (auto &y : X)
      os << y << " ";
    return os;
  }
  else
  {
    os << "[ ";
    for (auto &y : X)
      os << y << " ";
    return os << "]";
  }
}







template <typename T>
void d0(T t)
{
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  cout << t << " ";
}
template <typename T>
void dall(T t)
{
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  cout << t << endl;
}
template <typename T, typename... Args>
void dall(T t, Args... args)
{
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  cout << t << " ";
  dall(args...);
}
void id4()
{
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
}
template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
void id3()
{
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
}
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll MAXN = 1e6;
const ld eps = 1e-8;

void id1()
{
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
  ant++;
  cat--;
  ant--;
  cat++;
}
ll pwr(ll base, ll exp, ll m = mod)
{
  ll res = 1;
  while (exp > 0)
  {
    if (exp % 2 == 1)
      res = (res * base) % m;
    base = (base * base) % m;
    exp /= 2;
  }
  return res % m;
}
ll gcd(ll A, ll B)
{
  if (B == 0)
    return A;
  return gcd(B, A % B);
}
ll lcm(ll A, ll B) { return (A * B) / gcd(A, B); }
int digits(ll N, ll base = 2)
{
  if (N == 0)
    return 1;
  else if (base == 10)
    return floor(log10(N)) + 1;
  else
    return floor(log2(N)) + 1;
}

void solve(){
  ci(n);
  vll v(n);
  cin>>v;
  ll ans=0;
  vll arr;
  rep(i,1,n-1){
    if(v[i]>v[i-1]&&v[i]>v[i+1]) arr.pb(i);
  }
  if(sz(arr)>0){
    vector<bool> f(sz(arr),true);
    rep(i,0,sz(arr)-1){
      if(arr[i+1]==arr[i]+2&&f[i]&&f[i+1]){
        ans++;
        v[arr[i]+1]=max(v[arr[i]],v[arr[i]+2]);
        f[i]=false;f[i+1]=false;
      }
      else if(f[i]){
        f[i]=false;
        ans++;
        v[arr[i]]=max(v[arr[i]-1],v[arr[i]+1]);
      }
    }
    debug(ans);
    if(f.bk){
      ans++;
      v[arr[sz(arr)-1]]=max(v[arr[sz(arr)-1]-1],v[arr[sz(arr)-1]+1]);
    }
  }
  dall(ans);
  dall(v);
}

int main()
{
  fio;
  cout << fixed << setprecision(15);
  cerr << fixed << setprecision(5);

  freopen("./getio/input.ini", "r", stdin);
  freopen("./getio/output.out", "w", stdout);
  freopen("./getio/error.log", "w", stderr);
  auto start = high_resolution_clock::now();

  ll id2 = 1, CASE_NO = 1;
  cin >> id2; 

  while (id2--)
  {
    error(CASE_NO);
    solve();
    CASE_NO++;
    console(' ');
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cerr << "Time taken: " << duration.count() << " ms" << endl;

  return 0;
}