




using namespace std;










































typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
typedef pair<string, string> pairs;
typedef pair<ll, ll> pii;


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

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};


using namespace std;


void reverse(int arr[], int l, int r) {
    while (r > l) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

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

void lb(vector<int> v, int low, int high, int x) {
    int s = low;
    int e = high - 1;
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (v[m] < x) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    if (s < high) {
        cout << s << " " << v[s] << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
}

int up(vector<int> &v, int l, int h, int element) {
    int ans = -1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (v[mid] <= element) {
            l = mid + 1;
            ans = l;
        } else {
            h = mid - 1;
        }
    }
    return ans;
}

vector<bool> primes((1e6 + 1), true);

void sieven(int n) {
    primes[0] = primes[1] = false;
    for (ll i = 2; i <= n + 1; i++) {
        if (primes[i]) {
            for (ll j = i * i; j <= n + 1; j += i)
                primes[j] = false;
        }
    }
}




void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c = 0 , ans = 1;
    for (int i=0;i<n;i++){ 

        if (s[i]=='*'){
            c = i;
            s[i]='x';
            break;
        }
    }
    while (c < n) {
        int j = min(n-1,c+k);
        bool found  = false;
        for (; j > c;j--){
            if (s[j]=='*'){
                s[j]='x';
                found = true;
                ans++;
                c=j;
                break;
            }
        }
        if (!found){break;}
    }
    cout<<ans<<endl;
}

int main() {
    tc {
        solve();
    }
    return 0;
}


