#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define frep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define fwr(x) { cout << x << '\n'; }

typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int inf = 1e9 + 7;
const ll linf = 1ll * inf * inf;
const int N = (1 << 8) + 7;
const int M = 1 << 8;
const int multipleTest = 0;

const int x = 15;
const int y = 51;
const int z = 85;

const int full = M - 1;

string res[N][N][2];
bool check[N];

bool lt(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}


string get(int mask, int iter, int type, bool need) {




    if (check[mask]) {
        return res[mask][iter][0];
    }
    if (!need)
        return res[mask][iter][type];
    else return "(" + res[mask][iter][type] + ")";
    
}

string ans[M] = {"!x&x","x&y&z","!z&x&y","x&y","!y&x&z","x&z","!y&x&z|!z&x&y","(y|z)&x","!y&!z&x","!y&!z&x|x&y&z","!z&x","!z&x|x&y","!y&x","!y&x|x&z","!(y&z)&x","x","!x&y&z","y&z","!x&y&z|!z&x&y","(x|z)&y","!x&y&z|!y&x&z","(x|y)&z","!x&y&z|!y&x&z|!z&x&y","(x|y)&z|x&y","!x&y&z|!y&!z&x","!y&!z&x|y&z","!x&y&z|!z&x","!z&x|y&z","!x&y&z|!y&x","!y&x|y&z","!(y&z)&x|!x&y&z","x|y&z","!x&!z&y","!x&!z&y|x&y&z","!z&y","!z&y|x&y","!x&!z&y|!y&x&z","!x&!z&y|x&z","!y&x&z|!z&y","!z&y|x&z","!(!x&!y|x&y|z)","!(!x&!y|x&y|z)|x&y&z","!z&(x|y)","!z&(x|y)|x&y","!x&!z&y|!y&x","!x&!z&y|!y&x|x&z","!y&x|!z&y","!z&y|x","!x&y","!x&y|y&z","!(x&z)&y","y","!x&y|!y&x&z","!x&y|x&z","!(x&z)&y|!y&x&z","x&z|y","!x&y|!y&!z&x","!x&y|!y&!z&x|y&z","!x&y|!z&x","!z&x|y","!x&y|!y&x","!x&y|!y&x|x&z","!(x&z)&y|!y&x","x|y","!x&!y&z","!x&!y&z|x&y&z","!x&!y&z|!z&x&y","!x&!y&z|x&y","!y&z","!y&z|x&z","!y&z|!z&x&y","!y&z|x&y","!(!x&!z|x&z|y)","!(!x&!z|x&z|y)|x&y&z","!x&!y&z|!z&x","!x&!y&z|!z&x|x&y","!y&(x|z)","!y&(x|z)|x&z","!y&z|!z&x","!y&z|x","!x&z","!x&z|y&z","!x&z|!z&x&y","!x&z|x&y","!(x&y)&z","z","!(x&y)&z|!z&x&y","x&y|z","!x&z|!y&!z&x","!x&z|!y&!z&x|y&z","!x&z|!z&x","!x&z|!z&x|x&y","!x&z|!y&x","!y&x|z","!(x&y)&z|!z&x","x|z","!(!y&!z|x|y&z)","!(!y&!z|x|y&z)|x&y&z","!x&!y&z|!z&y","!x&!y&z|!z&y|x&y","!x&!z&y|!y&z","!x&!z&y|!y&z|x&z","!y&z|!z&y","!y&z|!z&y|x&y","!(!x&!y|x&y|z)|!x&!y&z","!(!x&!y|x&y|z)|!x&!y&z|x&y&z","!x&!y&z|!z&(x|y)","!x&!y&z|!z&(x|y)|x&y","!x&!z&y|!y&(x|z)","!x&!z&y|!y&(x|z)|x&z","!y&(x|z)|!z&y","!y&z|!z&y|x","!x&(y|z)","!x&(y|z)|y&z","!x&z|!z&y","!x&z|y","!x&y|!y&z","!x&y|z","!(x&y)&z|!z&y","y|z","!x&(y|z)|!y&!z&x","!x&(y|z)|!y&!z&x|y&z","!x&(y|z)|!z&x","!x&z|!z&x|y","!x&(y|z)|!y&x","!x&y|!y&x|z","!x&y|!y&z|!z&x","x|y|z","!(x|y|z)","!(x|y|z)|x&y&z","!(!x&y|!y&x|z)","!(x|y|z)|x&y","!(!x&z|!z&x|y)","!(x|y|z)|x&z","!(!x&y|!y&x|z)|!y&x&z","!(x|y|z)|(y|z)&x","!y&!z","!y&!z|x&y&z","!(!x&y|z)","!y&!z|x&y","!(!x&z|y)","!y&!z|x&z","!(!x&y|z)|!y&x","!y&!z|x","!(!y&z|!z&y|x)","!(x|y|z)|y&z","!(!x&y|!y&x|z)|!x&y&z","!(x|y|z)|(x|z)&y","!(!x&z|!z&x|y)|!x&y&z","!(x|y|z)|(x|y)&z","!(!x&y|!y&x|z)|!x&y&z|!y&x&z","!(x|y|z)|(x|y)&z|x&y","!x&y&z|!y&!z","!y&!z|y&z","!(!x&y|z)|!x&y&z","!(!x&y|z)|y&z","!(!x&z|y)|!x&y&z","!(!x&z|y)|y&z","!(!x&y|z)|!x&y&z|!y&x","!y&!z|x|y&z","!x&!z","!x&!z|x&y&z","!(!y&x|z)","!x&!z|x&y","!x&!z|!y&x&z","!x&!z|x&z","!(!y&x|z)|!y&x&z","!(!y&x|z)|x&z","!(x&y|z)","!(x&y|z)|x&y&z","!z","!z|x&y","!x&!z|!y&x","!(x&y|z)|x&z","!y&x|!z","!z|x","!(!y&z|x)","!x&!z|y&z","!(!y&x|z)|!x&y","!x&!z|y","!(!y&z|x)|!y&x&z","!(!y&z|x)|x&z","!(!y&x|z)|!x&y|!y&x&z","!x&!z|x&z|y","!x&y|!y&!z","!(x&y|z)|y&z","!x&y|!z","!z|y","!(!x&!y&z|x&y)","!x&!z|!y&x|y&z","!x&y|!y&x|!z","!z|x|y","!x&!y","!x&!y|x&y&z","!x&!y|!z&x&y","!x&!y|x&y","!(!z&x|y)","!x&!y|x&z","!(!z&x|y)|!z&x&y","!(!z&x|y)|x&y","!(x&z|y)","!(x&z|y)|x&y&z","!x&!y|!z&x","!(x&z|y)|x&y","!y","!y|x&z","!y|!z&x","!y|x","!(!z&y|x)","!x&!y|y&z","!(!z&y|x)|!z&x&y","!(!z&y|x)|x&y","!(!z&x|y)|!x&z","!x&!y|z","!(!z&x|y)|!x&z|!z&x&y","!x&!y|x&y|z","!x&z|!y&!z","!(x&z|y)|y&z","!(!x&!z&y|x&z)","!x&!y|!z&x|y&z","!x&z|!y","!y|z","!x&z|!y|!z&x","!y|x|z","!(x|y&z)","!(x|y&z)|x&y&z","!x&!y|!z&y","!(x|y&z)|x&y","!x&!z|!y&z","!(x|y&z)|x&z","!(!y&!z&x|y&z)","!x&!y|!z&y|x&z","!((x|y)&z|x&y)","!((x|y)&z|x&y)|x&y&z","!x&!y|!z","!x&!y|!z|x&y","!x&!z|!y","!x&!z|!y|x&z","!y|!z","!y|!z|x","!x","!x|y&z","!x|!z&y","!x|y","!x|!y&z","!x|z","!x|!y&z|!z&y","!x|y|z","!x|!y&!z","!x|!y&!z|y&z","!x|!z","!x|!z|y","!x|!y","!x|!y|z","!(x&y&z)","!x|x"};


vector<ii> _and[M];
vector<ii> _or[M];
vector<ii> notand[M];
vector<ii> notor[M];

void solve() {
    














































































































































































































    
    int query;
    cin >> query;
    while (query-- > 0) {
        int mask = 0;
        string s;
        cin >> s;
        for (char c : s) mask = (mask << 1) | (c - '0');
        cout << ans[mask] << '\n';
    }
    
}

int main() {
#ifdef _LOCAL_
    freopen("inp.txt", "r", stdin);
    

#endif
    
    int Test = 1;
    if (multipleTest)
        cin >> Test;
    
    for(int i = 0; i < Test; ++i) {
        

        solve();
    }
#ifdef _LOCAL_
    cout<< "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}

