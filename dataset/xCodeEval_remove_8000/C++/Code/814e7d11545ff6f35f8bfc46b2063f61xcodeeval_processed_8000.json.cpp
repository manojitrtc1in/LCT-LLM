



using namespace std;
using namespace __gnu_pbds;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> v1, v2;
    map<ll, ll> mp;
    ll sz = 0;
    for(int i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a;
        if(a == 1) {
            cin >> b;
            sz++;
            mp[sz] = b;
        } else {
            cin >> b >> c;
            v1.push_back(sz + 1);
            v2.push_back(b);
            sz += b * c;
        }
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll a;
        cin >> a;
        while (mp.find(a) == mp.end()) {
            int it = upper_bound(all(v1), a) - v1.begin() - 1;
            a = (a - v1[it]) % v2[it] + 1;
        }
        cout << mp[a] << " ";
    }
    return 0;
}
