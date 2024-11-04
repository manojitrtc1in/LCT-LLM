#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <numeric>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define MOD 1000000007
#define INF 1e18
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define sz(x) ((int)(x).size())
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) (x * y) / gcd(x, y)
#define debug(x) cout << #x << " = " << x << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int countDigit(ll n) {
    return floor(log10(n) + 1);
}

int sumOfDigits(ll n) {
    if (n < 0) return -1;

    int sum = 0;

    while (n > 0) {
        sum = sum + (n % 10);
        n /= 10;
    }

    return sum;
}

ll arraySum(int arr[], int start, int end) {
    ll ans = 0;

    for (int i = start; i <= end; i++) {
        ans += arr[i];
    }

    return ans;
}

int mod(int x) {
    if (x < 0) return -1 * x;
    else return x;
}

ll mod(ll x) {
    if (x < 0) return -1 * x;
    else return x;
}

void swapArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int** rotate(int** input, int n, int m) {
    int** output = new int*[m];
    for (int i = 0; i < m; i++) {
        output[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            output[j][n - 1 - i] = input[i][j];
        }
    }

    return output;
}

int countBits(ll n) {
    int count = 0;
    while (n != 0) {
        count++;
        n = (n) >> (1LL);
    }
    return count;
}

bool isPowerOfTwo(ll n) {
    if (n == 0) return false;
    if (((n) & (n - 1)) == 0) return true;
    else return false;
}

int min(int a, int b, int c, int d) {
    int arr[4];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    sort(arr, arr + 4);
    return arr[0];
}

int max(int a, int b, int c, int d) {
    int arr[4];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    sort(arr, arr + 4);
    return arr[3];
}

string reverse(string input) {
    string str = "";
    for (int i = input.length() - 1; i >= 0; i--) {
        str += input[i];
    }
    return str;
}

bool sameParity(ll a, ll b) {
    ll x = a % 2LL;
    ll y = b % 2LL;
    if (x == y) return true;
    else return false;
}

bool isPossibleTriangle(int a, int b, int c) {
    if (a + b > c && c + b > a && a + c > b) return true;
    else return false;
}

ll xnor(ll num1, ll num2) {
    if (num1 < num2) {
        ll temp = num1;
        num1 = num2;
        num2 = temp;
    }
    num1 = togglebit(num1);
    return num1 ^ num2;
}

ll togglebit(ll n) {
    if (n == 0) return 1;
    ll i = n;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return i ^ n;
}

int xorOfFirstN(int n) {
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    else return 0;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int lcm(int a, int b, int c, int d) {
    int temp = lcm(a, b, c);
    int ans = lcm(temp, d);
    return ans;
}

int lcm(int a, int b, int c) {
    int temp = lcm(a, b);
    int ans = lcm(temp, c);
    return ans;
}

int lcm(int a, int b) {
    int gc = gcd(a, b);
    return (a * b) / gc;
}

ll lcm(ll a, ll b) {
    ll gc = gcd(a, b);
    return (a * b) / gc;
}

bool isPrime(ll n) {
    if (n == 1) {
        return false;
    }

    bool ans = true;

    for (ll i = 2LL; i * i <= n; i++) {
        if (n % i == 0) {
            ans = false;
            break;
        }
    }

    return ans;
}

int sieve = 1000000;
bool prime[sieve + 1];

void sieveOfEratosthenes() {
    memset(prime, false, sizeof(prime));

    for (int i = 4; i <= sieve; i++) {
        prime[i] = true;
        i++;
    }

    for (int p = 3; p * p <= sieve; p++) {
        if (prime[p] == false) {
            for (int i = p * p; i <= sieve; i += p) {
                prime[i] = true;
            }
        }
        p++;
    }
}

void sortD(int arr[], int s, int e) {
    sort(arr + s, arr + e + 1);

    int i = s, j = e;

    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void sortD(ll arr[], int s, int e) {
    sort(arr + s, arr + e + 1);

    int i = s, j = e;

    while (i < j) {
        ll temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

ll countSubarraysSumToK(ll arr[], ll sum, ll n) {
    unordered_map<ll, ll> map;

    ll prefixsum = 0;
    ll count = 0;

    for (ll i = 0; i < n; i++) {
        prefixsum = prefixsum + arr[i];

        if (sum == prefixsum) count = count + 1;

        if (map.find(prefixsum - sum) != map.end()) {
            count = count + map[prefixsum - sum];
        }

        if (map.find(prefixsum) != map.end()) {
            map[prefixsum] = map[prefixsum] + 1;
        } else {
            map[prefixsum] = 1;
        }
    }

    return count;
}

vector<int> kmpAlgorithm(string str, string pat) {
    vector<int> list;

    int n = str.length();
    int m = pat.length();

    string q = pat + "#" + str;

    int lps[n + m + 1];

    longestPefixSuffix(lps, q, (n + m + 1));

    for (int i = m + 1; i < (n + m + 1); i++) {
        if (lps[i] == m) {
            list.push_back(i - 2 * m);
        }
    }

    return list;
}

void longestPefixSuffix(int lps[], string str, int n) {
    lps[0] = 0;

    for (int i = 1; i <= n - 1; i++) {
        int l = lps[i - 1];

        while (l > 0 && str[i] != str[l]) {
            l = lps[l - 1];
        }

        if (str[i] == str[l]) {
            l++;
        }

        lps[i] = l;
    }
}

void eulerTotientFunction(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (arr[i] == i) {
            arr[i] = i - 1;

            for (int j = 2 * i; j <= n; j += i) {
                arr[j] = (arr[j] * (i - 1)) / i;
            }
        }
    }
}

ll nCr(int n, int k) {
    ll ans = 1;
    k = k > n - k ? n - k : k;
    int j = 1;
    for (; j <= k; j++, n--) {
        if (n % j == 0) {
            ans *= n / j;
        } else if (ans % j == 0) {
            ans = ans / j * n;
        } else {
            ans = (ans * n) / j;
        }
    }
    return ans;
}

vector<int> allFactors(int n) {
    vector<int> list;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                list.push_back(i);
            } else {
                list.push_back(i);
                list.push_back(n / i);
            }
        }
    }

    return list;
}

vector<ll> allFactors(ll n) {
    vector<ll> list;

    for (ll i = 1LL; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                list.push_back(i);
            } else {
                list.push_back(i);
                list.push_back(n / i);
            }
        }
    }

    return list;
}

const int MAXN = 10000001;
int spf[MAXN];

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        spf[i] = i;
    }

    for (int i = 4; i < MAXN; i += 2) {
        spf[i] = 2;
    }

    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;

    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        sort(arr, l, m);
        sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(ll arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    ll L[n1];
    ll R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;

    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sort(ll arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        sort(arr, l, m);
        sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

ll knapsack(int weight[], ll value[], int maxWeight) {
    ll dp[maxWeight + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int j = maxWeight; j >= weight[i]; j--) {
            dp[j] = max(dp[j], value[i] + dp[j - weight[i]]);
        }
    }

    return dp[maxWeight];
}

ll kadanesAlgorithm(ll arr[], ll n) {
    ll dp[n];
    dp[0] = arr[0];
    ll max = dp[0];

    for (ll i = 1; i < n; i++) {
        if (dp[i - 1] > 0) {
            dp[i] = dp[i - 1] + arr[i];
        } else {
            dp[i] = arr[i];
        }

        if (dp[i] > max) max = dp[i];
    }

    return max;
}

ll kadanesAlgorithm(int arr[], int n) {
    ll dp[n];
    dp[0] = arr[0];
    ll max = dp[0];

    for (ll i = 1; i < n; i++) {
        if (dp[i - 1] > 0) {
            dp[i] = dp[i - 1] + arr[i];
        } else {
            dp[i] = arr[i];
        }

        if (dp[i] > max) max = dp[i];
    }

    return max;
}

ll binarySerachGreater(int arr[], int start, int end, int val) {
    if (start > end) return 0;

    int mid = (start + end) / 2;

    if (arr[mid] <= val) {
        return binarySerachGreater(arr, mid + 1, end, val);
    } else {
        return binarySerachGreater(arr, start, mid - 1, val) + end - mid + 1;
    }
}

void solve() {
    int testcases = 1;

    for (int testcase = 1; testcase <= testcases; testcase++) {
        ll n;
        cin >> n;

        ll x = n;

        vector<ll> list;

        for (ll i = 2LL; i * i <= n; i++) {
            if (x % i == 0) {
                while (x % i == 0) {
                    list.push_back(i);
                    x = x / i;
                }
            }
        }

        if (x > 1) list.push_back(x);

        if (n == 1) {
            cout << 1 << endl;
            cout << 0 << endl;
        } else if (list.size() == 2) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;

            if (list.size() == 1) cout << 0 << endl;
            else {
                ll ans = (list[0] * list[1]);
                cout << ans << endl;
            }
        }

        list.clear();
    }
}

int main() {
    fastio;

    solve();

    return 0;
}
