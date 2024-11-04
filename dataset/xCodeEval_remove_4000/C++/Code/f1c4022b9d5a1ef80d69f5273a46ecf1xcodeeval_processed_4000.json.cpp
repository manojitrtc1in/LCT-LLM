











































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
int id2(int x, int y)
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
ll id3(ll n)
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

    

    for (int i = 2; i * i <= n; i++)
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


bool id1(const pair<int, int>& a,
    const pair<int, int>& b)
{
    if (a.first > b.first)
        return 1;
    else if (a.first == b.first && a.second < b.second)
        return 1;
    return 0;
}
bool id5(const pair<int, int>& a,
    const pair<int, int>& b)
{
    if (a.second % 2 < b.second % 2)
        return 1;

    if (a.second % 2 == b.second % 2 && a.first < b.first)
        return 1;
    return 0;
}



struct gaser
{
    int n, f;
    gaser(int a, int b)
    {
        n = a;	f = b;
    }
    bool operator < (const gaser& b) const
    {
        if (n > b.n)
            return 1;
        return 0;
    }
};
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

    

    ll lw = 0, hi = 1e9, mid;
    while (lw < hi) {
        mid = lw + (hi - lw) / 2;
        if (1)
            hi = mid;
        else
            lw = mid + 1;
    }
    return hi + 1;
}
int n;
string str;
int x = 1e9 + 7;
int dp[15][100005];
int solve(int last, int idx)
{
    if (idx == n)
        return 1;
    if (str[idx] != '-')
    {
        if (str[idx] - '0' < last)
            return 0;
        else if (idx == n - 1) return 1;
    }
    int& ret = dp[last][idx];
    if (ret != 0)
        return ret;
    int ans = 0;
    if (str[idx] == '-')
    {

        lp(i, 9)
        {
            if (last <= i + 1)
                ans = (ans + solve(i + 1, idx + 1)) % x;
        }
    }
    else
        ans = (ans + solve(str[idx] - '0', idx + 1)) % x;
    return ret = ans;

}
int main()
{

    fast();
    


    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        lp(i, k - 3)
        {
            cout << 1 << " ";
            n--;
        }
        k = 3;

        if (n & 1)
        {
            cout << 1 << " " << n / 2 << " " << n / 2;
        }
        else
        {
            int i = 2;

            while (1)
            {
                int num = n - i;
                if (LCM(i, num / 2) <= n / 2)
                {
                    cout << i << " " << num / 2 << " " << num / 2;
                    break;
                }
                i += 2;
            }

        }
        
        cout << "\n";
    }

    return 0;
}
