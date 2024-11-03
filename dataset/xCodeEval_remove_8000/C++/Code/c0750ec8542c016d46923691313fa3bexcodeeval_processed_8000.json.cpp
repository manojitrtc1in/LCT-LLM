




using namespace std;





typedef long long ll;
typedef pair<int, int> ii;

int mx() {return INT_MIN;}
template<typename... Args> int mx(int parameter, Args... args) {return max(parameter, mx(args...));}

void solve() {
    int n;
    scanf("%d", &n);
    set<ii> s0, s1, s2;
    for(int i = 0;i < n;i++) {
        int ai;
        scanf("%d", &ai);
        (ai % 3 == 0 ? s0 : (ai % 3 == 1 ? s1 : s2)).insert({ai, i + 1});
    }
    int cur = -1;
    vector<int> ans;
    bool zhi = true;
    for(int i = 0;i < n;i++) {
        auto &ss = ((cur + 1) % 3 == 0 ? s0 : ((cur + 1) % 3 == 1 ? s1 : s2));
        auto it = ss.lower_bound({cur + 1, 0});
        if(it != ss.end() && it->X == cur + 1) {
            ans.push_back(it->Y);
            cur++;
            ss.erase(it);
        } else if(ss.size() && it != ss.begin()) {
            it--;
            cur = it->X;
            ans.push_back(it->Y);
            ss.erase(it);
        } else {
            zhi = false;
        }
    }
    if(!zhi)
        printf("Impossible");
    else {
        printf("Possible\n");
        for(int i = 0;i < n;i++)
            printf("%d ", ans[i]);
    }
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
