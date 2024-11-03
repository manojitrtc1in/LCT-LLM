




using namespace std;





typedef long long ll;
typedef pair<int, int> ii;

int n;
set<int> b, e;
vector<int> g(26, -1);
vector<bool> vis(26, false);
string ans;

void dfs(const int &v) {
    vis[v] = true;
    if(g[v] >= 0 && !vis[g[v]])
        dfs(g[v]);
    ans.append(1, v + 'a');
}

void solve() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        char s[27];
        scanf("%s", &s);
        if(e.count(s[0] - 'a') == 0)
            b.insert(s[0] - 'a');
        if(strlen(s) == 1 && g[s[0] - 'a'] == -1)
            g[s[0] - 'a'] = -2;
        else
            for(int j = 0;j < strlen(s) - 1;j++) {
                g[s[j] - 'a'] = (s[j + 1] - 'a');
                if(b.count(s[j + 1] - 'a') == 1)
                    b.erase(s[j + 1] - 'a');
                e.insert(s[j + 1] - 'a');
            }
    }
    for(const int &c : b)
        dfs(c);
    reverse(all(ans));
    printf("%s", ans.c_str());
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
