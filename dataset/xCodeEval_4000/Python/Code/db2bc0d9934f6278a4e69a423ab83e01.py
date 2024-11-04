"""

/*
Author: tmleyncodes

नैनं छिद्रन्ति शस्त्राणि नैनं दहति पावक: ।
न चैनं क्लेदयन्त्यापो न शोषयति मारुत ॥
*/


using namespace std;













unordered_map<char, int> mp;



























// INPUTS






// OUTPUTS





const ll maxn = 2e5 + 5;

typedef bitset<21> bit;            int mod99 = 998244353;
typedef long double ld;            const ld pi = 3.141592653589;               const int mod10 = 1000000007;     const ld INF = 5e18;
typedef pair<int, int> pii;        typedef vector<int> vi;                   typedef vector<pii> vpii;       typedef vector<vi> vvi;
typedef set<int> si;               typedef set<pii> spi;                     typedef multiset<int> msl;      typedef vector<string> vs;
mt19937 sansy (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<<(ostream &ostr, const pair<A, B> &pp) {return ostr << '{' << pp.first << ", " << pp.second << '}';}
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &ostr, const T_container &vec)
{ for (const T &vv : vec) ostr << vv << " "; return ostr << endl;  }
template <typename A> ostream& operator<< (ostream &ostr, vector<A> const &v) { fi(v.size()) {cout << v[i] << " ";} return cout << "\n";}
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> istream& operator>> (istream& cin, vector<A> &vv) { fi(vv.size() - 1) cin >> vv[i]; return cin >> vv[vv.size() - 1];}
vi primes, fibonacci;        int xorccur(int n);
bool isPrime(int n);        void sieve(int N);
int lcm(int a, int b);       int poww(int n, int k);
int nCr(int n, int r);       int leap(int y);
void fiboseries(int n);     int fiboN(int n);
bool isvowel(char c) { c = tolower(c); if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1; else return 0;}
int modInverse(int a, int m);
string baseto10(string s, int b);
string basefrom10(string s, int b);
int popcount(int n) {  int val = 0;  while (n) {  val += n & 1; n >>= 1; } return val;}
bool ispow2 (int n) {return n and  (!(n & (n - 1)));}
ld dis_p(int nice, int y1, int x2, int y2);
string subtractstring(string temp, string a2);
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dy[8] = {0, 1, 1, 0, -1, -1, 1, -1}, dx[8] = {1, 0, 1, -1, 0, -1, -1, 1};
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "Falsevember", "December"};

// int n, q, s, po, x, a[NOBITA], persum[NOBITA], permax[NOBITA], Q[1001];
// 
// bool a[100001];
// int dp[100001][2];

ll n; vector<ll> a(maxn); string s; ll arr[maxn][5];

// For the fast input and outputs in cpp
void Fast_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// IMPORTANT FUNCTIONS

bool isPrime(int n) {
    if (n < 2)               return 0;
    if (n < 4)               return 1;
    if (!(n % 2) || !(n % 3))   return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (!(n % i) || !(n % (i + 2)))
            return 0;
    return 1;
}
ll help(ll idx, ll prev) {
    int z = n + 1;
    if (idx >= z) {
        return 0;
    }
    ll &ans = arr[idx][prev];
    if (ans != -1) return ans;
    ans = 0;
    // cout<<idx<<" "<<prev<<'\n';
    if (idx == 1) {
        if (s[idx] == '1') {
            ans = max(ans, help(idx + 1, 1) + a[idx]);
        } else {
            ans = max(ans, help(idx + 1, 0));
        }
    } else {
        if (prev == 0) {
            if (s[idx] == '1') {
                ans = max(ans, help(idx + 1, 0) + a[idx - 1]);
                ans = max(ans, help(idx + 1, 1) + a[idx]);
            } else {
                ans = max(ans, help(idx + 1, prev));
            }
        } else {
            if (s[idx] == '1') {
                ans = max(ans, help(idx + 1, 1) + a[idx]);
            } else {
                ans = max(ans, help(idx + 1, 0));
            }
        }
    }

    return ans;
}
void sieve(int N) {
    vi vv(N + 1);
    for (int i = 2; i <= N; i++) {
        if (!vv[i])
            vv[i] = i, primes.push_back(i);
        for (int j = 0; j < primes.size() and  primes[j] <= vv[i] and  i * primes[j] <= N; j++)
            vv[i * primes[j]] = primes[j];
    }
}
ld dis_p(int nice, int y1, int x2, int y2)    {
    ld distance = sqrt(((nice - y1) * (nice - y1) + (x2 - y2) * (x2 - y2) * 1.00));
    return distance;
}
int lcm(int a, int b) {
    return ((a * b) / __gcd(a, b));
}
int poww(int n, int k)   {
    int x = 1;
    while (k)   {
        if (k & 1)
        { x *= n; x %= mod10; }
        n *= n;
        n %= mod10;
        k >>= 1;
    }
    return x;
}   //multi n^k
ll power(ll b, ll n) {
    ll s = 1;
    while (n) {
        if (n % 2 == 1)s = s * b % mod99;
        b = b * b % mod99;
        n /= 2;
    }
    return s;
}
int nCr(int n, int r)   { // n C r coeresicient
    if (r > n) return 0;
    if (r > n - r) r = n - r;
    int calc = 1;
    for (int i = 1; i <= r; i++) {
        calc *= (n - r + i);
        calc /= i;
        calc %= mod10;
    }
    return calc % mod10;;
}
int modInverse(int a, int m)  {
    if (m == 1)
        return 0; //edge case
    int initialmod = m, y = 0, x = 1;
    while (a > 1)   {
        //changing (A,B)--> (B, A%B) till a>1
        int q = a / m; // q is quotient
        int t = m;
        m = a % m; // m->remainder(from q)
        a = t;  // process same as
        t = y;  // Euclid's algo
        y = x - q * y;
        x = t; // Update y and  x
    }   //ax + bm = 1 (gcd(a,m)==1 (coprime))
    if (x < 0)
        x += initialmod;
    return x;
}
int coprime(int a, int b) {
    if (__gcd(a, b) == 1) return 1;
    return 0;
}
void fiboseries(int n)  {
    fibonacci.push_back(0);     fibonacci.push_back(1);
    int nu = 0, c2 = 1;  int c3 = nu + c2;
    while (c2 < n) {
        c3 = nu + c2;   nu = c2;      c2 |= c3;
        fibonacci.push_back(c3);
    }// Series upto N
}
ll count(ll i, ll j) {
    return ((i / (1 << (j + 1))) << j) + (max(0ll, i % (1 << (j + 1)) - (1 << j) + 1));
}
int fiboN(int n)    {
    //For DIRECTLY Nth TERM: Fn = ((1+sq(5))^n - (1-sq(5))^n)/pow(2^n).sq(5)
    if (n <= 1) return n;
    return fiboN(n - 1) + fiboN(n - 2);
}   // n as posing starts from 0
string baseto10(string s, int b) {
    int num = 0;
    fi(s.size()) {
        if (isdigit(s[i]))
            num = num * b + (s[i] - '0');
        else
            num = num * b + (s[i] - 'A' + 10);
    }
    return to_string(num);
}
string basefrom10(string s, int b) {
    string num;
    int n = stoll(s);
    while (n) {
        int x = n % b;  n /= b;
        if (x < 10)
            num += char('0' + x);
        else
            num += char('A' + x - 10);
    }
    reverse(all(num));
    return num;
}
bool isSquare(int x) {
    int y = sqrt(x);
    return y * y == x;
}
string subtractstring(string temp, string a2) {
    string cal = "";    //temp>=a2 (assumption)
    int n = temp.size(), m = a2.size(), antar = n - m, left = 0;
    for (int i = m - 1; i > -1; --i) {
        int cursub = (temp[i + antar] - '0') - (a2[i] - '0') - left;
        if (cursub >= 0)  left = 0;
        else cursub += 10, left = 1;
        cal.push_back(cursub + '0');
    }
    for (int i = n - m - 1; i > -1; --i) { // subtract remaining digits of temp[]
        if (temp[i] == '0' and left != 0) {
            cal.push_back('9');
            continue;
        }
        int cursub = (temp[i] - '0') - left;    left = 0;
        if (i || cursub)    cal.push_back(cursub + '0');
    }
    reverse(all(cal));
    return cal;
}
int leap(int y) {
    if (y % 400 == 0)         return 1;
    else if (y % 100 == 0)    return 0;
    else if (y % 4 == 0)      return 1;
    else                    return 0;
}
int xorccur(int n) {
    if (n % 4 == 0)             return n; //0,4,8,12
    else if (n % 4 == 1)        return 1; //1,5,9
    else if (n % 4 == 2)        return n; //2,6,10
    return 0;
}



// driver code for my contests


bool isPalindrome(int arr[], int n) {
    bool check = false;
    for (int i = 0; i <= n / 2 and n != 0 ; ++i) {
        if (arr[i] != arr[n - i - 1]) {
            return false;
        }
    }
    return true;
}

string rev(string s) {
    int n = s.length();
    string ans;
    for (int i = n - 1; i >= 0; i--) {
        ans.push_back(s[i]);
    }
    return ans;
}


int f(string s) {
    if (s == "M") {
        return 0;
    } else if (s.back() == 'L') {
        return s.size();
    } else {
        return -(int) s.size();
    }
}


/*
import math
for t in range(int(input())):
    s = input()
    unset = 0
    for i in range(math.ceil(len(s)/2)):
        if(s[i] != s[len(s)-i-1]):
            unset += 1

    if(unset %2 == 0):
        print("YES")
    else:
        if(len(s)%2):
            print("YES")
        else:
            print("NO")



count the no of 1s and 0s if sz is even
then o ans z should be even and
else one of them should be odd and
the other should be even

ans will be 2*n - minimum next number not present

compare i and j if a[i] >a[j] ans=-1 break and mxN=max(mxN,abs(a[i]-a[j])
 */


// int n, k;
/*
void solve() {
    vector<array<int, 3>> P;
    vector<int> a;
    cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x; a.push_back(x);
    }
    for (int i = 0; i < 30; ++i) {
        vector<int> R, S;
        for (int j : a)
            if ((j >> i) % 2 == 1)
                R.push_back(j);
            else
                S.push_back(j);
        while (R.size() % 3 != 0) {
            if (S.size() <= 2) {
                int i0 = R[R.size() - 1], i1 = R[R.size() - 2], i2 = R[R.size() - 3];
                R.pop_back(); R.pop_back(); R.pop_back();
                P.push_back({i0, i1, i2});
                int j0 = i0 ^ i1, j1 = i1 ^ i2, j2 = i2 ^ i0;
                S.push_back(j0); S.push_back(j2); S.push_back(j1);
                continue;
            }
            int i0 = R[R.size() - 1], i1 = S[S.size() - 1], i2 = S[S.size() - 2];
            R.pop_back(); S.pop_back(); S.pop_back();
            P.push_back({i0, i1, i2});
            int j0 = i0 ^ i1, j1 = i1 ^ i2, j2 = i2 ^ i0;
            R.push_back(j0); R.push_back(j2); S.push_back(j1);
        }
        for (int i = 0; i < (int)R.size() / 3; ++i) {
            int i0 = R[i * 3], i1 = R[i * 3 + 1], i2 = R[i * 3 + 2];
            int j0 = i0 ^ i1, j1 = i1 ^ i2, j2 = i2 ^ i0;
            P.push_back({i0, i1, i2});
            S.push_back(j0); S.push_back(j1); S.push_back(j2);
        }
        a.clear(); R.clear();
        for (int j : S) a.push_back(j);
    }
    cout << P.size() << endl;
    for (auto i : P)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
}

compare i and j if a[i] >a[j] ans=-1 break
and mxN=max(mxN,abs(a[i]-a[j])
*/

int count(string s, char c) {
    int res = 0;

    for (int i = 0; i < s.length(); i++)
        if (s[i] == c)
            res++;

    return res;
}

bool check(ll a[], ll n) {
    {
        ll flag = 0;
        for (int i = 0; i < n / 2 && n != 0; i++) {
            if (a[i] != a[n - i - 1]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            return false;
        else return true;
    }

}

int multiplyx(int x, int ans[], int size)
{
    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        int product = ans[i] * x + carry;
        ans[i] = product % 10;
        carry  = product / 10;
    }

    while (carry)
    {
        ans[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}

unsigned int facto(unsigned int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * facto(n - 1);
}



ll factorial(ll n)
{
    ll f = 1;
    for (ll i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

// Function to return the sum of
// factorials of the array elements
ll sumFactorial(ll *arr, ll n)
{

    // To store the required sum
    ll s = 0, i;
    for (i = 0; i < n; i++)
    {

        // Add factorial of all the elements
        s += factorial(arr[i]);
    }
    return s;
}

void solution() {
    /*int n; read1(n);
    reads(s);
    int cnt_Q = 0; int cnt_A = 0;
    int N = s.length();
    if (s[N - 1] != 'A') {
        no;
    }
    else {
        int f = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == 'Q') {
                cnt_Q++;
            }
            else {
                cnt_A++;
            }
            if (cnt_Q > cnt_A) {
                no;
                f = 1;
                break;
            }
        }
        if (!f) {
            yes;
        }
    }*/
    /*int n; read1(n);
    int z = (n / 2);
    if (n % 2 == 1) {
        repe(i, 1, z) {
            cout << i << " " << (i + (n + 1) / 2) << " ";
        }
        if (n % 2 == 1) cout << (n + 1) / 2 << " ";
    }
    else {
        repe(i, 1, z) {
            cout << i + (n + 1) / 2 << " " << i << " ";
        }
    }
    en;*/
    ll n, x;
    read2(n, x);
    vector<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];
    vector<ll> fact;
    for (auto it : arr) {
        ll num = facto(it);
        fact.pb(num);
    }
    ll sum = accumulate(fact.begin(), fact.end(), 0LL);
    ll div = facto(x);
    if (sum % div == 0) {
        yes;
    }
    else {
        no;
    }
    // cout << endl;
}


/*void solve() {
    int n; read1(n); vpii v;
    int sz = v.size();

    po = 0;
    for (int i = 1, x; i <= n; ++i) {
        read1(x);
        v.pb({x, x});
    }
    sort(all(v));
    repe(i, 1, n) {
        cout << v[v.size() - 1].second << ' ';
        bb flag = false;
        rep(j, 0, 30) {
            if ((po >> j) % 2 == 0 and (v[v.size() - 1].second >> j) % 2 == 1) {
                for (int k = 0; k < v.size(); ++k) {
                    v[k].first &= 2147483647 ^ (1 << j);
                }
                flag = true;
            }
        }
        po |= v[v.size() - 1].second;
        v.pop_back();
        if (flag) sort(all(v));
    }
    en;
}
*/


int main() {

    freopen("input.txt", "r", stdin);
    freopen("o.txt", "w", stdout);

    Fast_IO();
    // int tt = 1; // for 1 test case
    /*int tt; read1(tt);
    while (tt--) {
        solution();
        // solve();
        // solve2();
    }*/
    solution();
    return 0;
}



/*

using namespace std;



const ll INF=2e18;
const ll mod=1000000007;
const ll maxn=2e5+5;

ll n;
vector<ll> a(maxn);
string s;

ll dp[maxn][5];

ll dfs(ll idx,ll prev){
    if(idx>=n+1){
        return 0;
    }
    ll &ans=dp[idx][prev];
    if(ans!=-1) return ans;
    ans=0;
    // cout<<idx<<" "<<prev<<'\n';
    if(idx==1){
        if(s[idx]=='1'){
            ans=max(ans,dfs(idx+1,1)+a[idx]);
        }else{
            ans=max(ans,dfs(idx+1,0));
        }
    }else{
        if(prev==0){
            if(s[idx]=='1'){
                ans=max(ans,dfs(idx+1,0)+a[idx-1]);
                ans=max(ans,dfs(idx+1,1)+a[idx]);
            }else{
                ans=max(ans,dfs(idx+1,prev));
            }
        }else{
            if(s[idx]=='1'){
                ans=max(ans,dfs(idx+1,1)+a[idx]);
                // ans=max(ans,dfs(idx+1,0)+a[idx-1]);
            }else{
                ans=max(ans,dfs(idx+1,0));
            }
        }
    }

    return ans;
}

void solve(){
    cin>>n;
    cin>>s;
    s="@"+s;
    for(ll i=0;i<=n+2;i++){
        for(ll j=0;j<4;j++){
            dp[i][j]=-1;
        }
    }
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<dfs(1,2)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}
*/

"""

for _ in range(int(input())):
    x = 998244351
    y = 998244353
    z = 499122177
    q = 998244353
    n=int(input())
    arr=list(map(int,input().split()))
    c,s,e,p=[0,0,0,n*(n-1)]
    for i in range(0,n):
        if arr[i]==0:
            s+=arr[c]
            c+=1
    for i in range(1,s+1):
        e+=p*pow(i*i,x,y)
    print(e*z%q)
