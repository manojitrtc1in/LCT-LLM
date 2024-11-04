

using namespace std;
typedef long long ll;
































template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const ll INFLL = 1e18;
const int MAXN = 1e5 + 100;
const int MAXNN = 2e4 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
vector<pair<pii, pii>> a;
int pref[MAXN][2];
int ha[MAXNN], haa_0[MAXNN], haa_1[MAXNN];

void ms(int l, int r) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    ms(l, mid);
    ms(mid + 1, r);
    a.pb({{l,       mid},
          {mid + 1, r}});
}

string ss;
vector<int> p;

void mss(int l, int r) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    mss(l, mid);
    mss(mid + 1, r);
    int i = l, j = mid + 1;
    vector<int> b(r - l + 1);


    int now = 0;
    while (i <= mid && j <= r) {
        if (p[i] < p[j])
            ss += '0', b[now++] = p[i++];
        else
            ss += '1', b[now++] = p[j++];
    }
    while (i <= mid)
        b[now++] = p[i++];
    while (j <= r)
        b[now++] = p[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        p[i] = b[j];
}

void solve() {
    string s;
    cin >> s;
    reverse(all(s));
    for (int i = 1; i <= s.size(); i++) {
        if (s[i - 1] == '0')
            pref[i][0] = pref[i - 1][0] + 1, pref[i][1] = pref[i - 1][1];
        else
            pref[i][1] = pref[i - 1][1] + 1, pref[i][0] = pref[i - 1][0];
    }
    auto id3 = [&](int n) {
        a.clear();
        ms(0, n - 1);
        reverse(all(a));
        vector<int> ans(n);
        int now = 0;
        auto does_zero = [&](int ff) {
            int cur = 1;
            int cnt1 = 0, cnt2 = 0;
            auto to = a[0];
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            cnt1 = 0, cnt2 = 0;
            now = ff;
            for (int i = now - 1; i >= 0; i--) {
                char u = s[i];
                if (u == '0')
                    ans[cnt1++] = cur++;
                else
                    ans[sz1 + cnt2] = cur++, cnt2++;
            }
            while (cnt1 < sz1)
                ans[cnt1++] = cur++;
            while (cnt2 < sz2)
                ans[sz1 + cnt2] = cur++, cnt2++;
        };
        auto does = [&](int delta, int _) {
            auto to = a[_];
            int cnt1 = 0, cnt2 = 0;
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            int was = now;
            vector<int> fir(sz1), sec(sz2);
            cnt1 = 0;
            cnt2 = 0;
            int f = to.fi.fi;
            now += delta;
            for (int i = now - 1; i >= was; i--) {
                if (s[i] == '0')
                    fir[cnt1++] = ans[f++];
                else
                    sec[cnt2++] = ans[f++];
            }
            assert(cnt1 == sz1 || cnt2 == sz2);
            assert(cnt1 < sz1 || cnt2 < sz2);
            while (cnt1 < sz1)
                fir[cnt1++] = ans[f++];
            while (cnt2 < sz2)
                sec[cnt2++] = ans[f++];
            for (int i = to.fi.fi, j = 0; i <= to.fi.se; i++, j++)
                ans[i] = fir[j];
            for (int i = to.se.fi, j = 0; i <= to.se.se; i++, j++)
                ans[i] = sec[j];
        };
        vector<unordered_map<int, bool>> dp(a.size() + 1);
        dp[0][0] = true;
        int y = -INF;
        for (int i = 0; i < a.size(); i++) {
            if (dp[i].empty())
                break;
            auto to = a[i];
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            int prev_val = -123, prev_w = -1;
            int id2 = 0, id0 = 0;
            for (auto too:dp[i]) {
                int cnt1 = 0, cnt2 = 0;
                int w = too.fi;
                if (prev_val + 1 == too.fi) {
                    cnt1 = id2, cnt2 = id0, w = prev_w;
                    if (s[prev_val] == '0')
                        cnt1--;
                    else
                        cnt2--;
                }
                while (w < s.size() && cnt1 < sz1 && cnt2 < sz2) {
                    if (s[w] == '0')
                        cnt1++;
                    else
                        cnt2++;
                    w++;
                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                prev_val = too.fi;
                prev_w = w;
                id2 = cnt1;
                id0 = cnt2;
                if (cnt1 == sz1) {
                    if (s[too.fi] != '0')
                        continue;
                } else {
                    if (s[too.fi] != '1')
                        continue;
                }
                if (i + 1 == a.size())
                    y = max(y, w);
                dp[i + 1][w] = true;
                while (w < s.size()) {
                    if (s[w] == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp[i + 1][w] = true;
                    if (i + 1 == a.size())
                        y = max(y, w);
                }
            }
        }
        return y;
        if (dp[a.size()].find(s.size()) == dp[a.size()].end()) {
            return 123;
        }
        dp = vector<unordered_map<int, bool>>(a.size() + 1);
        vector<unordered_map<int, int>> from(a.size() + 1);
        dp[0][0] = true;
        for (int i = 0; i < a.size(); i++) {
            if (dp[i].empty())
                break;
            auto to = a[i];
            for (auto too:dp[i]) {
                int cnt1 = 0, cnt2 = 0;
                int sz1 = to.fi.se - to.fi.fi + 1;
                int sz2 = to.se.se - to.se.fi + 1;
                int w = too.fi;
                while (w < s.size() && cnt1 < sz1 && cnt2 < sz2) {
                    if (s[w] == '0')
                        cnt1++;
                    else
                        cnt2++;
                    w++;
                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                if (cnt1 == sz1) {
                    if (s[too.fi] != '0')
                        continue;
                } else {
                    if (s[too.fi] != '1')
                        continue;
                }
                dp[i + 1][w] = true;
                from[i + 1][w] = too.fi;
                while (w < s.size()) {
                    if (s[w] == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp[i + 1][w] = true;
                    from[i + 1][w] = too.fi;
                }
            }
        }
        if (dp[a.size()].find(s.size()) == dp[a.size()].end()) {
            return 123;
        }
        vector<int> x;
        now = 0;
        int ha = s.size();
        for (int j = (int) (a.size()); j > 0; j--) {
            int f = from[j][ha];
            x.pb(ha - f);
            ha = f;
        }
        reverse(all(x));
        does_zero(x[0]);
        assert(x.size() == a.size());
        for (int ii = 1; ii < x.size(); ii++)
            does(x[ii], ii);
        cout << n << '\n';
        for (auto to:ans)
            cout << to << " ";
        cout << '\n';
        return 123;
    };
    auto id1 = [&](int n) {
        a.clear();
        ms(0, n - 1);
        reverse(all(a));
        vector<int> ans(n);
        int now = 0;
        auto does_zero = [&](int ff) {
            int cur = 1;
            int cnt1 = 0, cnt2 = 0;
            auto to = a[0];
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            cnt1 = 0, cnt2 = 0;
            now = ff;
            for (int i = now - 1; i >= 0; i--) {
                char u = s[i];
                if (u == '0')
                    ans[cnt1++] = cur++;
                else
                    ans[sz1 + cnt2] = cur++, cnt2++;
            }
            while (cnt1 < sz1)
                ans[cnt1++] = cur++;
            while (cnt2 < sz2)
                ans[sz1 + cnt2] = cur++, cnt2++;
        };
        auto does = [&](int delta, int _) {
            auto to = a[_];
            int cnt1 = 0, cnt2 = 0;
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            int was = now;
            vector<int> fir(sz1), sec(sz2);
            cnt1 = 0;
            cnt2 = 0;
            int f = to.fi.fi;
            now += delta;
            for (int i = now - 1; i >= was; i--) {
                if (s[i] == '0')
                    fir[cnt1++] = ans[f++];
                else
                    sec[cnt2++] = ans[f++];
            }
            assert(cnt1 == sz1 || cnt2 == sz2);
            assert(cnt1 < sz1 || cnt2 < sz2);
            while (cnt1 < sz1)
                fir[cnt1++] = ans[f++];
            while (cnt2 < sz2)
                sec[cnt2++] = ans[f++];
            for (int i = to.fi.fi, j = 0; i <= to.fi.se; i++, j++)
                ans[i] = fir[j];
            for (int i = to.se.fi, j = 0; i <= to.se.se; i++, j++)
                ans[i] = sec[j];
        };
        vector<unordered_map<int, bool>> dp(a.size() + 1);
        dp[0][0] = true;
        for (int i = 0; i < a.size(); i++) {
            if (dp[i].empty())
                break;
            auto to = a[i];
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            int prev_val = -123, prev_w = -1;
            int id2 = 0, id0 = 0;
            for (auto too:dp[i]) {
                int cnt1 = 0, cnt2 = 0;
                int w = too.fi;
                if (prev_val + 1 == too.fi) {
                    cnt1 = id2, cnt2 = id0, w = prev_w;
                    if (s[prev_val] == '0')
                        cnt1--;
                    else
                        cnt2--;
                }
                while (w < s.size() && cnt1 < sz1 && cnt2 < sz2) {
                    if (s[w] == '0')
                        cnt1++;
                    else
                        cnt2++;
                    w++;
                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                prev_val = too.fi;
                prev_w = w;
                id2 = cnt1;
                id0 = cnt2;
                if (cnt1 == sz1) {
                    if (s[too.fi] != '0')
                        continue;
                } else {
                    if (s[too.fi] != '1')
                        continue;
                }
                dp[i + 1][w] = true;
                while (w < s.size()) {
                    if (s[w] == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp[i + 1][w] = true;
                }
            }
        }
        if (dp[a.size()].find(s.size()) == dp[a.size()].end()) {
            return false;
        }
        dp = vector<unordered_map<int, bool>>(a.size() + 1);
        vector<unordered_map<int, int>> from(a.size() + 1);
        dp[0][0] = true;
        for (int i = 0; i < a.size(); i++) {
            if (dp[i].empty())
                break;
            auto to = a[i];
            for (auto too:dp[i]) {
                int cnt1 = 0, cnt2 = 0;
                int sz1 = to.fi.se - to.fi.fi + 1;
                int sz2 = to.se.se - to.se.fi + 1;
                int w = too.fi;
                while (w < s.size() && cnt1 < sz1 && cnt2 < sz2) {
                    if (s[w] == '0')
                        cnt1++;
                    else
                        cnt2++;
                    w++;
                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                if (cnt1 == sz1) {
                    if (s[too.fi] != '0')
                        continue;
                } else {
                    if (s[too.fi] != '1')
                        continue;
                }
                dp[i + 1][w] = true;
                from[i + 1][w] = too.fi;
                while (w < s.size()) {
                    if (s[w] == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp[i + 1][w] = true;
                    from[i + 1][w] = too.fi;
                }
            }
        }
        if (dp[a.size()].find(s.size()) == dp[a.size()].end()) {
            return false;
        }
        vector<int> x;
        now = 0;
        int ha = s.size();
        for (int j = (int) (a.size()); j > 0; j--) {
            int f = from[j][ha];
            x.pb(ha - f);
            ha = f;
        }
        reverse(all(x));
        does_zero(x[0]);
        assert(x.size() == a.size());
        for (int ii = 1; ii < x.size(); ii++)
            does(x[ii], ii);
        cout << n << '\n';
        for (auto to:ans)
            cout << to << " ";
        cout << '\n';
        return true;
    };
    int now;
    int l = 1, r = 1e5;
    while (l <= r) {
        int mid = ((l + r) >> 1);
        int w = id3(mid);
        if (w < s.size())
            l = mid + 1;
        else
            r = mid - 1, now = mid;
    }
    while (1) {
        if (id1(now++))
            return;
    }
}

int main() {

    freopen("a.in", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int _t;
    _t = 1;


    while (_t--)
        solve();

    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';

}