





using namespace std;

  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);































ll sum(ll n) {
    ll sum = (n * (n + 1)) / 2;
    return sum;
}

ll id4(ll l, ll r) {
    ll ans = sum(r) - sum(l - 1);
    return ans;
}

bool sortedAsc(ll arr[], ll n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

bool sortedDesc(ll arr[], ll n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}

void sumDigits(int n) {
    int rem = 0;
    while (n) {
        rem += n % 10;
        n /= 10;
    }
    cout << rem << el;
}

ll nPr(ll n, ll r) {
    ll fact = 1;
    while (r--) {
        fact *= n;
        n--;
    }
    return fact;
}

ll id14(string s) {
    reverse(s.begin(), s.end());
    ll ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            ans += (1 << i);
    }
    return ans;
}

void subString(string s, int n) {
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
            cout << s.substr(i, len) << el;
}




int binary_search(int n) {
    long long start = 1, end = 10000000000, mid, element = 1;
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid <= n) {
            element = mid;
            start = mid + 1;
        } else
            end = mid - 1;
    }
    return element;
}

void shift_right(ll n, ll k, ll m, ll arr[100005]) {
    ll index = 0;
    k %= n;
    if (k >= m) {
        index = (n - k) + (m - 1);
    } else {
        index = (n - k - 1);
    }
    cout << arr[index] << el;
}

bool id2(ll x) { return (x & (x - 1)) == 0; }

int id10(ll n) {
    int cnt = 0;
    while (n) {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}

ll factorial(ll n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

void subArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}



bool isPrime(ll n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool primeFactors(int n, int l, int r, bool notFound) {
    for (int i = l; i <= r; i++) {
        if (i == 1)
            i++;
        if (n % i == 0) {
            cout << i << " ";
            notFound = false;
        }
        while (n % i == 0) {
            n = n / i;
        }
    }
    return notFound;
}

int id12(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return id12(n - 1) + id12(n - 2);
}

int id1(int n) {
    if (n <= 1)
        return n;
    return id1(n - 1) + id1(n - 2);
}

long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }

long long id3(long long a, long long b) { return a / gcd(a, b) * b; }

void id11(int n, int arr[]) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int sum[n];
    for (int i = 0; i < n; ++i) {
        sum[0] = arr[0];
        sum[i] = arr[i] + sum[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << sum[i] << " ";
    }
}














void id15(int n) {
    vector<int> v;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            v.push_back(i);
        }
    }
    if (n != 1) {
        v.push_back(n);
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
}

void pair_sum(int n, int k, int arr[]) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int low = 0, high = n - 1;
    while (low < high) {
        if (arr[low] + arr[high] == k) {
            cout << low << " " << high << endl;
        } else if (arr[low] + arr[high] > k) {
            high--;
        } else {
            low++;
        }
    }
}

string id0(ll x) {
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

ll reverse_number(ll n) {
    ll rev = 0;
    ll x = n;
    while (x > 0) {
        int m = x % 10;
        rev = (rev * 10) + m;
        x /= 10;
    }
    return rev;
}

int sequence(int arr[], int n, int d) { 

    int mx = INT_MIN;
    unordered_map<int, int> fr;
    for (int i = 0; i < n; ++i) {
        int r = arr[i] - (i) * d;
        if (fr.find(r) != fr.end()) {
            fr[r]++;
        } else
            fr.insert(make_pair(r, 1));
        if (fr[r] > mx)
            mx = fr[r];
    }
    return (n - mx);
}










ll intersection_points(pair<ll, ll> a, pair<ll, ll> b) {
    pair<ll, ll> p = {max(a.first, b.first), min(b.second, a.second)};
    if (a.second < b.first) {
        return 0;
    } else {
        return (p.second - p.first);
    }
}

ll union_points(pair<ll, ll> a, pair<ll, ll> b) {
    pair<ll, ll> p = {min(a.first, b.first), max(b.second, a.second)};
    if (a.second < b.first) {
        return b.second - a.first;
    } else {
        return (p.second - p.first);
    }
}

void primeFactors(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 2) {
        cout << n << " ";
    }
}

void id7(int n) {
    ll c = 0;
    while (n % 2 == 0) {
        c++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            c++;
            n = n / i;
        }
    }
    if (n > 2) {
        c++;
    }

    cout << c << el;
}










const ll mod = 5e5;

ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod; }

ll add(ll x, ll y) { return ((x % mod) + (y % mod)) % mod; }

ll sub(ll x, ll y) { return ((x % mod) - (y % mod)) % mod; }

ll fact[1000005], inv[1000005], n;

ll fastPow(ll b, ll p) {
    if (p == 0)
        return 1;

    ll hp = fastPow(b, p / 2);
    ll ret = mul(hp, hp);

    if (p % 2)
        ret = mul(ret, b);

    return ret;
}

ll modInverse(ll x) { return fastPow(x, mod - 2); }

void pre() {
    fact[0] = 1;
    inv[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = mul(i, fact[i - 1]);
        inv[i] = fastPow(fact[i], mod - 2);
    }
}

ll ncr(int n, int r) { return mul(inv[n - r], mul(fact[n], inv[r])); }

ll id6(ll value, ll index) { return (value | (1 << index)); }

ll id8(ll value, ll index) { return (value & ~(1 << index)); }

ll flipbit(ll value, ll index) { return (value ^ (1 << index)); }

ll getbit(ll value, ll index) { return ((value >> index) & 1); }

ll id9(ll value) {
    ll c = 0;
    while (value > 0) {
        c += value & 1;
        value >>= 1;
    }
    return c;
}



ll modPow(ll a, ll b) {
    if (b == 0)
        return 1LL;
    if (b == 1)
        return a % mod;
    ll res = 1;
    while (b) {
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b = b / 2;
    }
    return res;
}

void id13(ll x, ll arr[]) {
    fi(x) {
        for (int j = 0; j < x - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    fi(x) {
        cout << arr[i] << " ";
    }
}

void id5(ll x, ll arr[]) {
    ll mn;
    fi(x - 1) {
        mn = i;
        for (int j = i + 1; j < x; ++j) {
            if (arr[j] < arr[mn]) {
                mn = j;
            }
        }
        if (mn != i) {
            swap(arr[mn], arr[i]);
        }
    }
    fi(x) {
        cout << arr[i] << " ";
    }
}



ll arr[150];

int main() {

    


    Medo_Adel
    pre();

    int n, k, t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        int f = 1;
        for (int i = 0; i < k; i++) {
            if (s[i] != s[n - 1 - i]) {
                f = 0;
                break;
            }
        }
        if ((f == 1 && n % 2 == 1 && k <= (n / 2)) || (f == 1 && n % 2 == 0 && k < (n / 2)))cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
