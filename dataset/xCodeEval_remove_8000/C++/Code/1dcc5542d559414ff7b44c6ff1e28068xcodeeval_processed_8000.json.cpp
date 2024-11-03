


using namespace std;








































typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
typedef pair<string, string> pairs;


ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    gcd(b % a, a);
}


ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}













int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1}; 

int dy[] = {0, 1, -1, 0, -1, 1, 1, -1}; 



using namespace std;


bool isPrime(ll n) {
    if (n == 2) {
        return true;
    }
    if (n < 2 || n % 2 == 0) {
        return false;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

unsigned long long reverseBits(unsigned long long n) {
    unsigned long long rev = 0;

    

    while (n > 0) {

        

        rev <<= 1;

        

        if (n & 1 == 1)
            rev ^= 1;

        

        n >>= 1;
    }

    

    return rev;
}

string multiply(string num1, string num2) {

    ll len1 = num1.size();
    ll len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    vector<ll> result(len1 + len2, 0);

    ll id0 = 0;
    ll id2 = 0;

    for (ll i = len1 - 1; i >= 0; i--) {
        ll carry = 0;
        ll n1 = num1[i] - '0';

        id2 = 0;

        for (ll j = len2 - 1; j >= 0; j--) {
            ll n2 = num2[j] - '0';

            ll sum = n1 * n2 + result[id0 + id2] + carry;

            carry = sum / 10;

            result[id0 + id2] = sum % 10;

            id2++;
        }

        if (carry > 0)
            result[id0 + id2] += carry;

        id0++;
    }

    ll i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    if (i == -1)
        return "0";

    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

string id1(string str1, string str2) {

    

    

    if (str1.length() > str2.length())
        swap(str1, str2);

    

    string str = "";

    

    int n1 = str1.length(), n2 = str2.length();

    

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++) {
        

        

        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        

        carry = sum / 10;
    }

    

    for (int i = n1; i < n2; i++) {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    

    if (carry)
        str.push_back(carry + '0');

    

    reverse(str.begin(), str.end());

    return str;
}



bool isPalindrome(unsigned long long n) {
    

    

    unsigned long long rev = reverseBits(n);

    return (n == rev);
}

static vector<bool> primes(1000000, true);

void sieven(int n) {
    primes[0] = primes[1] = false;
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            for (int j = i * 2; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
}

int Bs(vector<int> &v, int n, int element) {
    int lo = -1, hi = n;
    while (hi > (lo + 1)) {
        int mid = (lo + hi) >> 1;
        if (v[mid] >= element) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

int Bs1(vector<int> &v, int n, int element) {
    int lo = -1, hi = n;
    while (hi > (lo + 1)) {
        int mid = (lo + hi) >> 1;
        if (v[mid] <= element) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int fastSearch(vector<int> &v, int n, int l, int r) {
    int ln = Bs(v, n, l);
    int rn = Bs1(v, n, r);
    return rn - ln + 1;
}


void reverse(int arr[], int l, int r) {
    while (r > l) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}


void cobra(){

    int n, d;
    cin >> n >> d;
    vi v(n);
    for (int& x : v){
        cin >> x;
    }
    sort (all(v));
    cout << (v.back() <= d || (v[0] + v[1]) <= d ? "YES" : "NO") << '\n';
}
int main() {
    fast
    int t;
    cin >> t;
    while (t--) {
       cobra();
    }
    return 0;
}




































































































