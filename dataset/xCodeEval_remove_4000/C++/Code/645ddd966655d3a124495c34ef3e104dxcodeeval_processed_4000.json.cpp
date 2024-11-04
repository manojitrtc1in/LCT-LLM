











































using namespace std;















ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
string alpha = "abcdefghijklmnopqrstuvwxyz";
int divisor(int number)
{
    int i;
    for (i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return number / i;
        }
    }
    return 1;
}
int id1(int x, int y)
{
    int res = 0; 


    

    for (int i = 31; i >= 0; i--)
    {
        

        bool b1 = x & (1 << i);
        bool b2 = y & (1 << i);

        

        bool id9 = (b1 & b2) ? 0 : (b1 | b2);

        

        res <<= 1;
        res |= id9;
    }
    return res;
}


void id12(int n, vector<int>& v)
{
    

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            

            if (n / i == i && i > 1)
                v.push_back(i);

            else 

            {
                if (i > 1)
                    v.push_back(i);
                if (n / i > 1)
                    v.push_back(n / i);
            }
        }
    }
}
int bin(vector<int>vec, int val)
{
    int l = 0, r = vec.size() - 1, mid = r / 2;
    while (l <= r)
    {
        mid = (l + r) / 2;

        if (vec[mid]<val && vec[mid + 1]>val)
        {
            if (vec[mid + 1] == val)
                return mid + 1;
            return mid;

        }
        else if (vec[mid] > val)
        {
            r = mid - 1;
        }
        else if (vec[mid] < val)
        {
            l = mid + 1;
        }
        else if (vec[mid] == val)
            return mid;


    }
    return -1;
}
void clear(vector<bool>v)
{
    for (int i = 0; i < v.size(); i++)
        v[i] = 0;
}

bool comp(const string& s1, const string& s2)
{
    

    

    return s2 + s1 < s1 + s2;
}
vector<string> split(const string& s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}
int countWords(string str)
{
    

    stringstream s(str); 

    string word; 


    int count = 0;
    while (s >> word)
        count++;
    return count;
}
ll power(ll x, ll y, ll p, int& c)
{
    int res = 1;     

    if (x >= p)
        c++;
    x = x % p; 

                


    if (x == 0) return 0; 


    while (y > 0)
    {
        

        if (y & 1)
        {
            if (res * x >= p)
                c++;
            res = (res * x) % p;
        }

        

        y = y >> 1; 

        if (x * x >= p)
            c++;
        x = (x * x) % p;
    }
    return res;
}
bool isPalindrome(string str)
{
    

    int l = 0;
    int h = str.length() - 1;

    

    while (h > l)
    {
        if (str[l++] != str[h--])
        {

            return 0;
        }
    }
    return 1;
}
bool id8(vector<int>vec)
{
    lp(i, vec.size())
    {
        if (vec[i] < 0)
            return 0;
    }
    return 1;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;     


    x = x % p; 

                


    if (x == 0) return 0; 


    while (y > 0)
    {
        

        if (y & 1)
            res = (res * x) % p;

        

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;
}
ll ceiLl(ll x, ll y)
{
    return (x + y - 1) / y;
}
vector<ll> id0(ll n)
{
    vector<ll>ans;
    ll i = 1;
    for (; i * i < n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
    if (i * i == n)
        ans.push_back(i);
    return ans;
}
vector<ll> id6(ll n)

{

    

    

    if (n == 1)
        return vector<ll>(1, 0);
    vector<ll> numFactors(n + 1);

    

    for (int i = 1; i <= n; i++) {

        

        

        for (int j = 1; j * i <= n; j++)
            numFactors[i * j]++;
    }

    return numFactors;
}
vector<ll> factorization(ll n) 

{	 


    vector<ll> primes;

    for (ll i = 2; i * i <= n; ++i)	

    {
        if (n % i == 0)
        {

            primes.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        } 

    }
    if (n > 1)
        primes.push_back(n);

    return primes;
}
bool id4(string a, string b)
{
    int idx = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[idx])
            idx++;
    }
    if (idx == b.length())
        return 1;
    else
        return 0;
}
bool id4(vector<int> a, vector<int> b)
{
    int idx = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (b.size() == idx) break;
        if (a[i] == b[idx])
            idx++;
    }
    if (idx == b.size())
        return 1;
    else
        return 0;
}
bool id10(string a, string b)
{

    for (int i = 0; i < a.length(); i++)
    {
        if (a.substr(i, b.length()) == b)
            return 1;
    }
    return 0;
}
bool id13(const pair<int, int>& a,
    const pair<int, int>& b)
{
    return (a.second < b.second);
}
bool isEqual(string a, string b)
{
    if (a.size() != b.size())
        return 0;
    sort(vbe(a)); sort(vbe(b));
    if (a == b)
        return 1;
    return 0;
}
string bin(unsigned n)
{
    string ans = "";
    unsigned i;
    for (i = 1 << 20; i > 0; i = i / 2)
        (n & i) ? ans += '1' : ans += '0';
    return ans;
}
string leftrotate(string a, int d)
{
    string s = a;
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
    return s;
}



string rightrotate(string a, int d)
{
    string s = a;
    return leftrotate(s, s.length() - d);

}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll id7(vector<ll> arr, int n)
{
    

    ll ans = arr[0];

    

    

    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
            (gcd(arr[i], ans)));

    return ans;
}
int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
}






ll id11(vector<ll>arr)
{
    int n = arr.size();
    ll result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}
ll id2(ll n)
{
    ll cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            

            

            if (n / i == i)
                cnt++;

            else 

                cnt = cnt + 2;
        }
    }
    return cnt;
}
bool isPrime(ll n)
{
    

    if (n <= 1)
        return false;

    

    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}
bool arePair(char L, char R)
{
    if (L == '(' && R == ')')
        return 1;
    else if (L == '{' && R == '}')
        return 1;
    else if (L == '[' && R == ']')
        return 1;
    else if (L == '<' && R == '>')
        return 1;
    return 0;
}
int areBalanced(string e)
{
    stack<char>s;
    int zz = 0;
    for (int i = 0; i < e.length(); i++)
    {
        if (e[i] == '(' || e[i] == '[' || e[i] == '{' || e[i] == '<')
            s.push(e[i]);
        else if (e[i] == ')' || e[i] == ']' || e[i] == '}' || e[i] == '>')
        {
            if (s.empty() || !arePair(s.top(), e[i]))
                zz++;
            else
                s.pop();
        }
    }
    return zz + s.size();
}


bool id5(const pair<int, int>& a,
    const pair<int, int>& b)
{
    if (a.first < b.first)
        return 1;

    if (a.first == b.first && a.second > b.second)
        return 1;
    return 0;
}




bool sortbyt(const pair<int, int>& a,
    const pair<int, int>& b)
{
    if (a.first < b.first)
        return 1;
    else if (a.first == b.first && a.second > b.second)
        return 1;
    return 0;
}
ll bs() {

    ll lw = 0, hi = 0, mid;
    ll be = 0;
    while (lw < hi) {
        mid = 1 + lw + (hi - lw) / 2;

        if (1)
            lw = mid;
        else
            hi = mid - 1;
    }
    return lw;
}

struct gaser
{
    int a, b;
    gaser(int A, int B)
    {
        a = A;	b = B;
    }
    bool operator < (const gaser& ga) const
    {
        if (b / a < ga.b / ga.a)
            return 1;
        return 0;
    }
};
ll nCr(int n, int r)
{

    long long p = 1, k = 1;
    if (n < r) return 0;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = GCD(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;
    return p;
}
int vis[505][505];
int N;
int di[4] = { 0,1,0,-1};
int dj[4] = { -1,0,1,0 };
int ans[505][505];
int cnt = 0;
bool id3(int i, int j)
{
    if (vis[i][j] || j >= i||i>=N||i<0||j>=N||j<0||i==j) return 0;
    return 1;
}
bool dfs(int i, int j,int val)
{
    lp(x, 4)
    {
        int I = i + di[x], J = j + dj[x];
        if (id3(I, J))
        {
            ans[I][J] = val;
            vis[I][J] = 1;
            cnt++;
            if (cnt == val - 1) return 1;
            if (dfs(I, J, val)) return 1;
        }
    }
}
int main()
{

    fast();
    


    int t = 1;
   

    while (t--)
    {
        int n;
        cin >> n;
        N = n;
        
        memset(vis, 0, sizeof vis);
        vector<int>vec(n);
        lp(i, n) cin >> vec[i];
        lp(i, n)
        {
            ans[i][i] = vec[i];
            cnt = 0;
            if (vec[i] != 1)
            {
                dfs(i, i, vec[i]);
                if (cnt != vec[i] - 1)
                {
                    cout << -1;
                    return 0;
                }
            }
            
        }
        lp(i, n)
        {
            for (int j = 0; j <= i; j++)cout << ans[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
