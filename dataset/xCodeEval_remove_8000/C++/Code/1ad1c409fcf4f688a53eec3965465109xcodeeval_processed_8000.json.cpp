





using namespace std;





using ll = long long; using ld = long double;
using ii = pair<int, int>; using iii = tuple<int, int, int>;
using vb = vector<bool>; using vc = vector<char>; using vi = vector<int>; using vl = vector<long>;
using vii = vector<ii>; using vll = vector<ll>;
using vvb = vector<vector<bool>>; using vvc = vector<vector<char>>; using vvi = vector<vector<int>>; using vvl= vector<vector<long>>;
using Al = unordered_map<int, vi>; using AL = unordered_map<int, vi>;






const double EPS = 1e-7;

struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

auto hashF = [](const pair<int,int> & v) {
    return 1000000000L*(v.first+1000000L)+v.second+1000000L;
};

auto eq = [](auto &a, auto &b) {return a == b;};




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        string s; cin >> s;

        ll sum = 0;
        ll ans = 0;

        unordered_map<ll, ll> prefix;
        unordered_map<ll, ll> freq;

        freq[sum]++;
        prefix[sum%3]++;

        for (auto &c : s) {
            if (c == '+') {
                prefix[(sum%3+3)%3]-=freq[sum];
                sum++;
            } else {
                --sum;
                prefix[(sum%3+3)%3]+=freq[sum];
            }
            ans+=prefix[(sum%3+3)%3];
            freq[sum]++;
            prefix[(sum%3+3)%3]++;
        }

        cout << ans << endl;
    }
}
