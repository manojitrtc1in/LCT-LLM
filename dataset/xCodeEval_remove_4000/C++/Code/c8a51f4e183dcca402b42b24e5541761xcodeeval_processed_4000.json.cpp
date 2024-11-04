



using namespace std;
using namespace __gnu_pbds;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, string> > ans;
    string s;
    cin >> s;
    for (int i = '0'; i <= '9'; i++) {
        int left = k - count(all(s), i);
        left = max(left, 0);
        string cur = s;
        int cost = 0;
        while (left) {
            for (int d = 1;; d++) {
                for (int j = 0; j < n; j++) {
                    if (s[j] == (char) (i + d)) {
                        left--;
                        cost += d;
                        cur[j] = i;
                        if (left == 0) break;
                    }
                }
                if (left == 0) break;
                for (int j = n - 1; j >= 0; j--) {
                    if (s[j] == (char) (i - d)) {
                        left--;
                        cost += d;
                        cur[j] = i;
                        if (left == 0) break;
                    }
                }
                if (left == 0) break;
            }
        }
        ans.push_back({cost, cur});
    }
    sort(all(ans));
    cout << ans[0].first << endl << ans[0].second;
    return 0;
}