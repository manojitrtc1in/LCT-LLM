








using namespace std;






typedef long long ll;
typedef pair<int, int> ii;

int n, m;
int a[200000];
deque<ii> ints;
vector<ii> st;
vector<int> b, booty(200000);

void solve() {
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    for(int i = 0;i < m;i++) {
        int t, r;
        scanf("%d %d", &t, &r);
        while(!st.empty() && st.back().Y <= r)
            st.pop_back();
        if(st.empty() || st.back().X != t)
            st.push_back({t, r});
    }
    int maxr = st[0].Y;
    sort(a, a + maxr, (st[0].X == 1 ? [](const int &x, const int &y) {return x < y;} : [](const int &x, const int &y) {return x > y;}));
    ints.push_front({0, maxr - 1});
    for(int i = 1;i < st.size();i++) {
        assert(st[i].X != st[i - 1].X);
        assert(st[i].Y < st[i - 1].Y);
        int l = ints.front().X, r = ints.front().Y, k = st[i].Y;
        ints.pop_front();
        ii id0, id1;
        if(l <= r) {
            id0 = {l + k - 1, l};
            id1 = {l + k, r};
        } else {
            id0 = {l - k + 1, l};
            id1 = {l - k, r};
        }
        assert(id0.X >= 0 && id0.X < n && id0.Y >= 0 && id0.Y < n);
        assert(id1.X >= 0 && id1.X < n && id1.Y >= 0 && id1.Y < n);
        ints.push_front(id1);
        ints.push_front(id0);
    }
    for(int i = 0;i < ints.size();i++) {
        if(ints[i].X <= ints[i].Y)
            for(int j = ints[i].X;j <= ints[i].Y;j += 1) {
                b.push_back(a[j]);
            }
        else
            for(int j = ints[i].X;j >= ints[i].Y;j -= 1) {
                b.push_back(a[j]);
            }
    }
    for(int i = maxr;i < n;i++)
        b.push_back(a[i]);
    assert(b.size() == n);
    for(int i = 0;i < b.size();i++)
        printf("%d ", b[i]);
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
