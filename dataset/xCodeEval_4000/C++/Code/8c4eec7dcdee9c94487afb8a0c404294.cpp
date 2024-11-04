
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define all(v)			((v).begin()), ((v).end())
#define SZ(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define UNIQUE(v)       sort(all(v));v.erase(unique(all(v)),v.end());
typedef long long ll;
int n, k, x;
ll sum, ans;
map<ll, int> mp;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
        for (ll cur_sum = 1; cur_sum <= 1ll * 1e14; cur_sum *= k) {
            if (sum == cur_sum)
                ans++;
            ans += mp[sum - cur_sum];
            if (cur_sum * k == 1)break;
        }
        mp[sum]++;
    }
    cout << ans << "\n";
    return 0;
}