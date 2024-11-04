





































































using namespace std;

typedef int_fast32_t fi32;
typedef int_fast64_t fi64;
typedef uint_fast32_t ufi32;
typedef uint_fast64_t ufi64;

typedef vector<int> vi;
typedef vector<fi64> vfi64;
typedef vector<ufi64> vufi64;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umii;
typedef unordered_map<fi64, fi64> umfi64;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, fi64> umsfi64;
typedef map<int, int> mii;
typedef map<fi64, fi64> mfifi;
typedef map<string, int> msi;
typedef map<string, fi64> msfi;

typedef long double ld;
typedef unsigned int ui;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;















const fi64 MOD {998244353};

void solve() 
{
    string s; cin >> s;
    prtAns(s.back() + s.substr(1));
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    bool id0 = 1; 

    if (id0) cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}