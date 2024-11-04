
using namespace std;




typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3f;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
int n;
ll k, x;
cin >> n >> k >> x;
string p;
cin >> p;
x--;
if (!k) {
    for (int i = 0; i < n; i++) {
if (p[i] == 'a') {
    cout << 'a';
}
    }
    cout << "\n";
    continue;
}

p += ' ';
ll cnt = 0;
string s = "";
vector<ll> arr;
for (int i = 0; i <= n; i++) {
    if (p[i] == '*') {
cnt++;
    } else {
if (cnt) {
    s += '*';
    arr.push_back(cnt);
}
if (p[i] == 'a') {
    s += 'a';
    arr.push_back(1);
}
cnt = 0;
    }
}
n = s.length();

ll a = 1;
vector<ll> arr2(n + 1);
for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '*') {
if (a > x) {
    arr2[i] = lnf;
} else {
    arr2[i] = a;
    if (a * (k * arr[i] + 1) < a) {
a = lnf;
    } else {
a *= (k * arr[i] + 1);
    }
}
    }
}

for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
cout << 'a';
    } else {
int A = x / arr2[i];
x %= arr2[i];
for (int j = 0; j < A; j++) {
    cout << 'b';
}
    }
}
cout << "\n";
    }

    return 0;
}