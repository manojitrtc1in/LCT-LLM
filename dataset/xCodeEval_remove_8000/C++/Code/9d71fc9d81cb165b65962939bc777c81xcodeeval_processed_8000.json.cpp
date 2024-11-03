



using namespace std;
using namespace __gnu_pbds;
template<typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




typedef long long ll;
bool isOpen (char c) {
    return (c == '(' || c == '[');
}
bool isClose (char c) {
    return (c == ')' || c == ']');
}
bool match (char x, char y) {
    return ((x == '[' && y == ']') || (x == '(' && y == ')'));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    stack<pair<char, pair<int, int>>> st;
    int start = -1, cur = 0, mx = 0;
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < SZ(s); ++i) {
        cur += (s[i] == '[');
        if(isOpen(s[i])) {
            st.push({s[i], {i, cur}});
        }
        if(isClose(s[i])) {
            if(!SZ(st) || not match(st.top().first, s[i])) {
                while (SZ(st))
                    st.pop();
                cur = 0;
                start = i;
            }
            else if(match(st.top().first, s[i])) {
                st.pop();
                if(not st.empty()) {
                    int top = st.top().second.second;
                    if(cur - top > mx) {
                        mx = cur - top;
                        idx1 = st.top().second.first + 1;
                        idx2 = i;
                    }
                } else {
                    if (cur > mx) {
                        mx = cur;
                        idx1 = start + 1;
                        idx2 = i;
                    }
                }
            }
        }
    }
    cout << mx << endl;
    if(mx) {
        cout << s.substr(idx1, (idx2 - idx1) + 1) << endl;
    }
    return 0;
}
