



using namespace std;































typedef pair<int,int> pii;
typedef map<int,int>mii;
typedef vector<int>vi;
typedef vector<pii>vii;
typedef set<int> si;
typedef set<char> sc;


bool as_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return (a.second < b.second); }

bool ds_first(const pair<ll,ll> &a, const pair<ll,ll> &b){ return (a.first > b.first);}

bool ds_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return a.second>b.second;}


bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
ll factorial(ll n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)fact *= i;
    return fact;
}
bool primeFactors(int n, int l, int r, bool notFound)
{
    for (int i = l; i <= r; i++)
    {
        if (i == 1)
            i++;
        if (n % i == 0)
        {
            cout << i << " ";
            notFound = false;
        }
        while (n % i == 0)
        {
            n = n / i;
        }
    }
    return notFound;
}
bool id31(ll number) {
    ll id3 = 1;
    do {
        if (number == id3) return true;
        id3 *= 2;
    } while (id3 <= number);
    return false;
}
ll id43(ll n)
{
    if (n && !(n & (n - 1)))
        return n;
    ll cnt = 0;
    while (n != 0)
    {
        n >>= 1;
        cnt++;
    }
    ll x = 1;
    x = x << cnt;
    return x;
}
ll id20(ll n)
{
    ll res = 0;
    for (ll i = n; i >= 1; i--)
    {
        

        if ((i & (i - 1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}

vector<ll> id42()
{
    vector<ll>v = { 1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155, 165580141 ,267914296 ,433494437 ,701408733 ,1134903170 ,1836311903 ,2971215073 ,4807526976 ,7778742049,12586269025,20365011074 };
    return v;
}
void id26()
{
    ll arr[51]={0, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368,75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073, 4807526976, 7778742049};
}
ll fib(ll n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
ll id9(ll n) {
    double sqrt5 = sqrt(5);

    int F_n = (pow((1 + sqrt5), n) - pow((1 - sqrt5), n)) / (pow(2, n) * sqrt5);

    return F_n;
}




void  id36() {
    vector<ll> lucky;
    lucky.pb(0);
    int idx = 0;
    while (lucky.back() < 1e10) {
        lucky.push_back(((lucky[idx] * 10) + 4));
        lucky.push_back((lucky[idx] * 10) + 7);
        idx++;
    }
}
int binarySearch(int a[], int first, int last, int search_num) {
    int middle;
    if (last >= first) {
        middle = (first + last) / 2;
        

        if (a[middle] == search_num)
            return middle + 1;

            

        else if (a[middle] < search_num)
            return binarySearch(a, middle + 1, last, search_num);

            

        else
            return binarySearch(a, first, middle - 1, search_num);
    }
    return -1;
}
void factorize(long long n) {
    int count = 0;
    while (!(n % 2)) {
        n /= 2;
        count++;
    }
    if (count)
        cout << 2 << " " << count << endl;
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count)
            cout << i << " " << count << endl;
    }
    if (n > 2)
        cout << n << " " << 1 << endl;
}
void primeFactors(ll num) {
    ll fac = 2;
    while (num > 1) {
        if (num % fac == 0) {
            cout << fac << " ";
            num /= fac;
            ll pow = 1;
            while (num % fac == 0) {
                num /= fac;
                pow++;
            }
            cout << pow << el;
        }
        else {
            fac++;
        }
    }
}
bool id35(ll num) {
    ll fac = 2;
    int cnt = 0;
    while (num > 1) {
        if (num % fac == 0) {
            cnt++;
            while (num % fac == 0)
                num /= fac;
        } else
            fac++;
        if (cnt >= 2)
            return false;
    }
    return true;
}
bool isPerfect(ll d)
{
    double temp = d;
    d = sqrt(d);
    temp = sqrt(temp);
    if (temp == d)
        return true;
    return false;
}
void sort(string s[], int n)

{
    for (int i = 1; i < n; i++)
    {
        string temp = s[i];
        int j = i - 1;
        while (j >= 0 && temp.length() < s[j].length())
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}
bool id5(ll x)
{
    return (x & (x - 1)) == 0;
}
int id41(ll arr[], int n, ll key)
{
    int left = 0, right = n;

    int mid;
    while (left < right) {
        mid = (right + left) >> 1;

        if (arr[mid] == key) {
            while (mid + 1 < n && arr[mid + 1] == key)
                mid++;
            break;
        }

        else if (arr[mid] > key)
            right = mid;

        else
            left = mid + 1;
    }

    while (mid > -1 && arr[mid] > key)
        mid--;

    return mid + 1;
}
int id33(ll n) {
    int cnt = 0;
    while (n) {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}
string id1(ll x) {
    string s;
    while (x > 0) {
        if (x % 2)
            s += '1';
        else
            s += '0';
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
ll id40(string s) {
    reverse(s.begin(), s.end());
    ll ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            ans += (1 << i);
    }
    return ans;
}
long long lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}
bool palindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1])
            return false;
    }
    return true;
}
int id2(ll n) {
    int sum = 0;
    string s = to_string(n);
    f(i, s.length())sum += s[i] - '0';
    return sum;
}
bool isUnique(ll x) {
    int size = log10(x) + 1;
    set<int> s;
    while (x > 0) {
        s.insert(x % 10);
        x /= 10;
    }
    if (s.size() == size)
        return true;
    else
        return false;
}
void subString(string s, int n) {
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
            cout << s.substr(i, len) << el;
}

bool id4(const pair<string, int> &a,
               const pair<string, int> &b)
{
    return (a.second > b.second);
}

ll Round(double n) {
    ll y = n;
    if (y == n)
        return y;
    else
        return y + 1;
}
bool isLetter(char x) {
    if (x >= 'A' && x <= 'Z')
        return true;
    else if (x >= 'a' && x <= 'z')
        return true;
    else
        return false;
}
int id22(string s, char x)
{
    int index = -1;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == x)
            index = i;
    return index;
}
bool id21(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o')
        return true;
    else
        return false;
}
bool isOdd(char c) {
    if (c == '1' || c == '3' || c == '5' || c == '7' || c == '9')
        return true;
    else
        return false;
}
ll sum(ll n) {
    ll sum = (n * (n + 1)) / 2;
    return sum;
}
ll id10(ll l , ll r) {
    ll ans = sum(r) - sum(l - 1);
    return ans;
}
bool sortedAsc(ll arr[],ll n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
}
bool sortedDesc(ll arr[],ll n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}
ll id14(ll n) {
    return ((n - 1) % 9) + 1;
}
bool equal(char x , char y) {
    if (x == '.')
        return true;
    return x == y;
}
string add(string s , int n) {
    string temp = "";
    while (n--)
        temp += s;
    return temp;
}
bool id18(string s) {
    stack<char> s1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            s1.push('(');
        else {
            if (s1.empty())
                return false;
            else
                s1.pop();
        }
    }
    return s1.empty();
}
bool sumDigits(int n) {
    int rem = 0;
    while (n) {
        rem += n % 10;
        n /= 10;
    }
    return rem == 10;
}
bool sortedA(int arr[],int n) {
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}
bool sortedD(int arr[],int n) {
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            return false;
    return true;
}





string id11(string s) {
    string temp = "";
    for (int i = 0; i < s.size(); i++)
        if (isalpha(s[i]))temp += tolower(s[i]);
    return temp;
}
int id24(ll a) {
    if (a % 4 == 0) return a;
    else if (a % 4 == 1) return 1;
    else if (a % 4 == 2) return a + 1;
    else return 0;
}
void sort3(int& a, int& b, int& c) {
    if (a > b)swap(a, b);
    if (b > c)swap(b, c);
    if (a > b)swap(a, b);
}
int lis(vector<int>&a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])dp[i] = max(dp[i], dp[j] + 1);
    int ans = dp[0];
    for (int i = 1; i < n; i++)ans = max(ans, dp[i]);
    return ans;
}
bool id16(string s) {
    vasort(s);
    return s[0] == s[s.size() - 1];
}

ll nPr(ll n , ll r) {
    ll fact = 1;
    while (r--) {
        fact *= n;
        n--;
    }
    return fact;
}




const ll mod = 7901;


const double pi=acos(-1);
bool containEven(string s) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8')return true;
    return false;
}void id34(int n, int r) {
    long long p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            long long m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    } else
        p = 1;

    cout << p << endl;
}
string id29(int n) {
    string ans = "";
    while (n > 0) {
        ans += (char) ((n % 3) + '0');
        n /= 3;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
string id30(string s1,string s2) {
    string ans = "";
    for (int i = 0; i < s1.size(); i++) {
        int x = (s1[i] - '0') + (s2[i] - '0');
        x %= 3;
        ans += (char) (x + '0');
    }
    return ans;
}
string unique_string(string s) {
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t.back())continue;
        t += s[i];
    }
    return t;
}
int countOdd(int L, int R) {

    int N = (R - L) / 2;

    

    if (R % 2 != 0 || L % 2 != 0)
        N += 1;

    return N;
}


bool id28(int n) {
    while (n >= 10 && n % 10 == 0)n /= 10;
    return n == 1;
}
int id19(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++)sum += s[i] - '0';
    return sum;
}
long long nCr(int n, int r) {
    if(r > n - r) r = n - r; 

    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
int id6(int a, int b) {
    return log2(a) / log2(b);
}














string id32(string s) {
    if (s.size() == 1) {
        s += "ay";
        return s;
    }
    string ans = "";
    for (int i = 1; i < s.size(); i++) {
        if (i == 1)ans += (char) toupper(s[i]);
        else ans += (char) tolower(s[i]);
    }
    ans += tolower(s[0]);
    ans += "ay";
    return ans;
}
int id13(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i * i == n)cnt = (cnt % mod + 1 % mod) % mod;
            else cnt = (cnt % mod + 2 % mod) % mod;
        }
    }
    return cnt % mod;
}
string cfRate(int n) {
    if (n < 1200)return "Newbie";
    else if (n <= 1399)return "Pupil";
    else if (n <= 1599)return "Specialist";
    else if (n <= 1899)return "Expert";
    else if (n <= 2099)return "Candidate master";
    else if (n <= 2299)return "Master";
    else if (n <= 2399)return "International master";
    else if (n <= 2599)return "Grandmaster";
    else if (n <= 2999)return "International grandmaster";
    return "Legendary grandmaster";
}
int maxDigit(int n) {
    int mx = 0;
    while (n > 0) {
        mx = max(mx, n % 10);
        n /= 10;
    }
    return mx;
}
int minDigit(int n) {
    int mn = 1e18;
    while (n > 0) {
        mn = min(mn, n % 10);
        n /= 10;
    }
    return mn;
}
string id15(int n, int x) {
    string ans = "";
    while (n > 0) {
        int rem = n % x;
        if (rem >= 10) {
            rem -= 10;
            ans += ('A' + rem);
        } else ans += (rem + '0');
        n /= x;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int id25(string s,int x) {
    reverse(s.begin(), s.end());
    int st = 1, ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            if (isalpha(s[i])) {
                int dig = (s[i] - 'A') + 10;
                ans += dig * st;
            } else ans += (s[i] - '0') * st;
        }
        st *= x;
    }
    return ans;
}
int mod9 = 998244353;
int fast_power(int a, int n) {
    if (n == 0)
        return 1;
    

    if (a == 0)
        return 0;
    int tmp = fast_power(a, n / 2);
    if (n % 2 == 0) 

        return (tmp * tmp );
    else
        return (a * tmp * tmp );
}
bool id7(int num) {
    int cnt = 0;
    for (int i = 2; i * i <= num && cnt < 2; i++) {
        while (num % i == 0) {
            num /= i;
            cnt++;
            if (cnt > 2)break;
        }
    }
    if (num > 1)cnt++;
    return cnt == 2;
}
string binaryAdd(string a, string b) {
    string result = "";
    int temp = 0;
    int size_a = a.size() - 1;
    int size_b = b.size() - 1;

    while (size_a >= 0 || size_b >= 0 || temp == 1) {
        temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
        temp += ((size_b >= 0) ? b[size_b] - '0' : 0);
        result = char(temp % 2 + '0') + result;
        temp /= 2;
        size_a--;
        size_b--;
    }
    return result;
}
int cmp(string a,string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)cnt += (a[i] != b[i]);
    return cnt;
}
int id8(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i)sum += i;
            else sum += (n / i) + i;
        }
    }
    return sum;
}
int id37(string s) {
    int cnt = 0;
    map<char, bool> vis;
    for (auto c: s)if (!vis[c] && c != ' ')cnt++, vis[c] = 1;
    return cnt;
}
int id17(int x) {
    return __builtin_popcount(x);
}
bool check(string s,int idx) {
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == idx)continue;
        t += s[i];
    }
    return palindrome(t);
}
bool id27(string s1,string s2) {
    if (s1[0] == s2[1] && s1[1] == s2[0])return true;
    return false;
}
int id39(string s) {
    int cnt = 0;
    f(i, s.size())if (id21(s[i]))cnt++;
    return cnt;
}
int id38(int x) {
    int mx = -1;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            mx = max(mx, i);
            mx = max(mx, x / i);
        }
    }
    return mx;
}
char shift(char c , int x) {
    int y = x + (c - 'a');
    y %= 26;
    return y + 'a';
}
int id23(double p) {
    return (int) ceil(p / 4.0) * floor(p / 4.0);
}

bool id12(string t) {
    stack<char> st;
    for (auto c: t) {
        if (c == '(')st.push(c);
        else {
            if (st.empty())return 0;
            else st.pop();
        }
    }
    return st.empty();
}

int id0(string hexVal) {
    int len = hexVal.size();
    int base = 1;
    int dec_val = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += ((hexVal[i]) - 48) * base;
            base = base * 16;
        } else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += ((hexVal[i]) - 55) * base;
            base = base * 16;
        }
    }
    return dec_val;
}

























bool distinctDigits(int n) {
    int sz = 0;
    set<int> s;
    while (n > 0) {
        sz++;
        s.insert(n % 10);
        n /= 10;
    }
    return sz == s.size();
}

int32_t main() {
    covid19
    TC {
        int n;
        cin >> n;
        if (n == 1)cout << 2 << el;
        else {
            int ab = 1e9, ac = 1e9;
            int x = n % 3;
            int y = n - x;
            ab = y/3 + (x%3!=0);
            ac = n / 2;
            cout << min(ab, ac) << el;
        }
    }


}

