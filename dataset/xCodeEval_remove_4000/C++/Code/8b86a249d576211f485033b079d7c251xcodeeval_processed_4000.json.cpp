



using namespace std;
using namespace __gnu_pbds;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




typedef long long ll;
constexpr int mod = 1e9+7;
int w[505], b[1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (find(all(ans), b[i]) == ans.end()) {
            ans.push_back(b[i]);
        }
    }
    int hehe = 0;
    for (int i = 0; i < m; i++) {
        int j = 0;
        while (b[i] != ans[j] && j < n)
            hehe += w[ans[j++] - 1];
        ans.insert(ans.begin(), ans[j]);
        ans.erase(ans.begin() + j + 1);
    }
    cout << hehe;
    return 0;
}