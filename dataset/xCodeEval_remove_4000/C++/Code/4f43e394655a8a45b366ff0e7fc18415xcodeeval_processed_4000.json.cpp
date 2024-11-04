








using namespace std;

typedef long long ll;


typedef P<int, int> Pii;
typedef P<ll, ll> Pll;





typedef V<int> Vi;
typedef V<Pii> VPii;
typedef V<ll> Vll;
typedef V<Pll> VPll;





typedef set<int> si;
typedef multiset<int> mi;
typedef map<int, int> mii;

void id0() {
    int n, m;
    cin >> n >> m;
    V<VPii> graph(n + 1, VPii(n + 1));
    forn (k, m, 0) {
        int i, j, w;
        cin >> i >> j >> w;
        graph[i][j].fi = w;
        graph[i][j].se = j;
        graph[j][i].fi = w;
        graph[j][i].se = i;
    }
    Vll dist(n + 1, 1e18);
    Vi p(n + 1);
    dist[1] = 0;
    p[1] = 1;
    priority_queue<Pii, VPii, greater<Pii>> q;
    q.push(mp(0, 1));
    while (!q.empty()) {
        Pii u = q.top();
        q.pop();
        if (u.fi > dist[u.se]) continue;
        forn(i, n + 1, 1) {
            int v = graph[u.se][i].se, len = graph[u.se][i].fi;
            if (dist[v] > dist[u.se] + len) {
                p[v] = u.se;
                dist[v] = dist[u.se] + len;
                q.push(mp(dist[v], v));
            }
        }
    }
    if (dist[n] == 1e18) cout << -1;
    else {
        int i = n;
        string c;
        while (i != 1) {
            string pl = to_string(i);
            reverse(pl.begin(), pl.end());
            c += pl + " ";
            i = p[i];
        }
        cout << 1;
        for (int i = (int) c.size() - 1; i > -1; i--)
            cout << c[i];
    }
}

void id2() {
    int n, maxA = 0, maxB = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > maxA)
            maxA = a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] > maxB)
            maxB = b[i];
    }
    if (maxB > maxA)
        swap(a, b);

    for (int i = 0; i < n; ++i)
        if (a[i] < b[i])
            swap(a[i], b[i]);

    maxA = 0, maxB = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > maxA)
            maxA = a[i];
        if (b[i] > maxB)
            maxB = b[i];
    }
    cout << maxA * maxB;
}

void id44() {
    int n; cin >> n;
    int mx = 0, mn = 1e9 + 1;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        if (num > mx)
            mx = num;
        if (num < mn)
            mn = num;
    }
    cout << mx - mn;
}

void id40() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((((a + c) % 2) == 0 && ((a + c) / 2) % b == 0) || (a <= b <= c && (b - (c - b) > 0) && (b - (c - b)) % a == 0) || (a <= b && (b + b - a) % c == 0))
        cout << "YES";
    else {
        swap(a, c);
        if ((((a + c) % 2) == 0 && ((a + c) / 2) % b == 0) || (a <= b <= c && (b - (c - b) > 0) && (b - (c - b)) % a == 0) || (a <= b && (b + b - a) % c == 0))
            cout << "YES";
        else
            cout << "NO";
    }
}

void id14() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n > 2 || s == "11" || s == "00")
        cout << "NO";
    else
        cout << "YES";
}

void id5() {
    int n, now; cin >> n >> now;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    multiset<pair<int, int>> pr;
    for (int i = 0; i < n; ++i)
        pr.insert(make_pair(a[i], b[i]));
    for (auto i : pr) {
        if (i.first > now)
            break;
        now += i.second;
    }
    cout << now;
}

void id56() {
    int l, r, k;
    cin >> l >> r >> k;
    if (l == r) {
        if (l == 1)
            cout << "NO";
        else
            cout << "YES";
        return;
    }
    if ((r - l + 1) - (r / 2 - (l - 1) / 2) <= k)
        cout << "YES";
    else
        cout << "NO";
}

void id55() {
    int n; cin >> n;
    if (n % 7 == 0)
        cout << n;
    else if (n % 10 > n % 7)
        cout << n - n % 7;
    else
        cout << n + 7 - n % 7;
}

void id19() {
    string s;
    cin >> s;
    int n = s.size();


    int zero = 0, one = 0;
    for (int i = 0; i < n; ++i) {










        if (s[i] == '0')
            zero++;
        else
            one++;
    }
    if (zero != one)
        cout << min(zero, one);
    else {
        int first, second;
        if (s[n - 1] == '0')
            first = min(zero - 1, one);
        else
            first = min(zero, one - 1);

        if (s[0] == '0')
            second = min(zero - 1, one);
        else
            second = min(zero, one - 1);
        cout << max(first, second);
    }

}

void id37() {
    ll hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    for (ll i = 0; i <= k; ++i) {
        ll hc1 = hc + a * i;
        ll dc1 = dc + w * (k - i);
        ll numC = (hm + dc1 - 1) / dc1;
        ll numM = (hc1 + dm - 1) / dm;
        if (numC <= numM) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

void id62() {
    int n, k; cin >> n >> k;
    vector<int> c(n + 1), num(n + 1);
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        int f = log2(b);
        num[i + 1] += f;
        b -= (1 << f);
        while (b != 0) {
            int j = log2(b);
            num[i + 1]++;
            b -= (1 << j);
        }
    }
    for (int i = 0; i < n; ++i)
        cin >> c[i + 1];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < k + 1; ++j) {
            if (j >= num[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - num[i]] + c[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k];
}

void id31() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> fs(30);
    for (int i = 0; i < n; ++i)
        fs[s[i] - 'a']++;
    for (int i = 0; i < 30; ++i)
        for (int j = 0; j < fs[i]; ++j)
            cout << (char)('a' + i);
}

void id3() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = n - 1, j = n - 2; j >= 0; --i, --j) {
        if (s[i] - '0' + s[j] - '0' > 10) {
            cout << s.substr(0, j) << s[i] + s[j] - '0' - '0' << s.substr(i + 1, n);
            return;
        }
    }
    cout << s[0] - '0' + s[1] - '0' << s.substr(2, n);
}

void id20() {
    int n; cin >> n;
    cout << ((int) cbrt(n)) + ((int) sqrt(n)) - ((int) sqrt(cbrt(n)));
}

void id29() {
    string a, s;
    cin >> a >> s;
    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());
    int sn = s.size(), an = a.size();
    string b;
    for (int i = 0, j = 0; i < an; ++i) {
        if (j < sn - 1 && s[j] < '9' && s[j + 1] == '1') {
            char c = (char) (10 - (a[i] - '0') + s[j]);
            if (c > '9')
                b += "01";
            else
                b += c;
            j++;
        } else
            b += (s[j] - a[i] + '0');
        j++;
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] < '0' || b[i] > '9') {
            cout << -1;
            return;
        }
    }
    int i = 0;
    for (i; i < b.size(); ++i)
        if (b[i] != '0')
            break;
    cout << b.substr(i, b.size());
}

void id53() {
    int n, k;
    cin >> n >> k;
    if (k > (n + 1) / 2) {
        cout << -1 << '\n';
        return;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i % 2 == 0 && j == i && count < k) {
                cout << 'R';
                count++;
            } else
                cout << '.';
        }
        cout << '\n';
    }
}

void id1() {
    int n;
    cin >> n;
    int mn = 1e9 + 2, mx = 0, cn = 0, forl = 0, forr = 0, ln = 0;
    for (int i = 0; i < n; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        if (l < mn)
            mn = l, forl = c;
        else if (l == mn && c < forl)
            forl = c;

        if (r > mx)
            mx = r, forr = c;
        else if (r == mx && c < forr)
            forr = c;

        if (ln < r - l + 1)
            ln = r - l + 1, cn = c;
        else if (ln == r - l + 1 && c < cn)
            cn = c;

        int best_now = forl + forr;
        if (ln == mx - mn + 1 && cn < best_now)
            best_now = cn;
        cout << best_now << '\n';
    }
}

void id15() {
    int n; cin >> n;
    vector<int> a(101);
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        if (b < 0)
            b = -b;
        a[b]++;
    }
    int count = 0;
    for (int i = 0; i < 101; ++i) {
        if (a[i] >= 2 && i != 0)
            count += 2;
        else if (a[i])
            count++;
    }
    cout << count;
}

void id21() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "YES" << '\n';
        for (int i = 1; i < n + 1; ++i)
            cout << i << '\n';
        return;
    } else {
        if (n * k % 2 == 1) {
            cout << "NO\n";
            return;
        }
        set<int> no, yes;
        for (int i = 1; i < n * k + 1; ++i) {
            if (i % 2 == 0)
                yes.insert(i);
            else
                no.insert(i);
        }
        auto forNo = no.begin(), forYes = yes.begin();
        if (no.size() % k != 0 || yes.size() % k != 0) {
            cout << "NO" << '\n';
            return;
        }
        cout << "YES" << '\n';
        for (int i = 0; i < no.size() / k; ++i) {
            for (int j = 0; j < k; ++j) {
                cout << *forNo << ' ';
                forNo++;
            }
            cout << '\n';
        }
        for (int i = 0; i < yes.size() / k; ++i) {
            for (int j = 0; j < k; ++j) {
                cout << *forYes << ' ';
                forYes++;
            }
            cout << '\n';
        }
    }
}

void id50() {
    int m;
    cin >> m;
    map<int, int> L, R;
    string ans;
    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        int countL = 0, countR = 0;
        for (int j = 0; j < n; ++j) {
            int a; cin >> a;
            if (!L.count(a))
                L[a] = 0;
            if (!R.count(a))
                R[a] = 0;
            if (countL == n / 2) {
                R[a]++;
                countR++;
                ans += 'R';
                continue;
            }
            if (countR == n / 2) {
                L[a]++;
                countL++;
                ans += 'L';
                continue;
            }
            if (L[a] < R[a]) {
                L[a]++;
                countL++;
                ans += 'L';
            } else {
                R[a]++;
                countR++;
                ans += 'R';
            }
        }
        ans += '\n';
    }
    for (auto i : L) {
        if (R[i.first] != i.second) {
            cout << "NO";
            return;
        }
    }
    cout << "YES\n" << ans;
}

void id9() {
    int n; cin >> n;
    vector<int> a(n);
    vector<bool> u(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        while (a[i] > n || (a[i] <= n && u[a[i]]))
            a[i] /= 2;
        if (a[i] == 0) {
            cout << "NO";
            return;
        }
        u[a[i]] = true;
    }
    cout << "YES";
}

void id48() {
    int n, k;
    cin >> n >> k;
    vector<int> count(26);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        ++count[c - 'a'];
    }
    int p = 0, no = 0;
    for (int i = 0; i < 26; ++i) {
        p += count[i] / 2;
        no += count[i] % 2;
    }
    int cl = 2 * (p / k);
    no += 2 * (p % k);
    cl += (no / k) >= 1;
    cout << cl;
}

void id13() {
    string s;
    cin >> s;
    int count = 0;
    for (char i : s)
        if (i == 'E')
            count++;
    if (count == s.size() - 1)
        cout << "NO";
    else
        cout << "YES";
}

void id4() {
    ll w, h, ans = 0;
    cin >> w >> h;
    for (int j = 0; j < 4; ++j) {
        ll k; cin >> k;
        vector<int> points(k);
        for (int i = 0; i < k; ++i)
            cin >> points[i];
        if (j < 2)
            ans = max(ans, (points[k - 1] - points[0]) * h);
        else
            ans = max(ans, (points[k - 1] - points[0]) * w);
    }
    cout << ans;
}

void id28() {
    ll n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<ll> count;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            count.push_back(0);
            while (i < n - 1 && s[i + 1] == '*')
                i++, count[count.size() - 1]++;
        }
    }
    

}

void id16() {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    vector<int> p;
    if (cd >= cb)
        p.push_back(cd - cb);
    if (rd >= rb)
        p.push_back(rd - rb);
    if (cd <= cb)
        p.push_back(2 * m - cd - cb);
    if (rd <= rb)
        p.push_back(2 * n - rd - rb);
    int Min = 1e9;
    for (int i = 0; i < p.size(); ++i)
        if (p[i] < Min)
            Min = p[i];
    cout << Min;
}

void id27() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c || a + c == b || b + c == a || (a == b && c % 2 == 0) || (a == c && b % 2 == 0) || (b == c && a % 2 == 0))
        cout << "YES";
    else
        cout << "NO";
}

void id33() {
    int a[7];
    for (int i = 0; i < 7; ++i)
        cin >> a[i];
    cout << a[0] << ' ' << a[1] << ' ' << a[6] - a[1] - a[0];
}

void id32() {
    int n;
    cin >> n;
    string ans, last;
    bool flg = false;
    for (int i = 0; i < n - 2; ++i) {
        string nw;
        cin >> nw;
        if (i == 0 || flg || nw[0] == last[1]) {
            ans += nw[0];
            last = nw;
        } else {
            flg = true;
            ans += last[1];
            ans += nw[0];
        }
        if (i == n - 3)
            ans += nw[1];
    }
    if (!flg)
        ans += 'a';
    cout << ans;
}

void id11() {
    int n, m, r, c, count = 0;
    cin >> n >> m >> r >> c;
    --r, --c;
    bool flg = false, id59 = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char k; cin >> k;
            if (flg)
                continue;
            count += (k == 'B');
            if (i == r && j == c && k =='B') {
                cout << 0;
                flg = true;
            } else if ((i == r || j == c) && k == 'B') {
                id59 = true;
            }
        }
    }
    if (count == 0) {
        cout << -1;
        return;
    }
    if (id59 && !flg)
        cout << 1;
    else if (!flg)
        cout << 2;
}

void id57() {
    int n, m;
    cin >> n >> m;
    vector<int> p;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            p.push_back(max(max(i + j, i + m - j - 1), max(j + n - i - 1, m - 1 - j + n - 1 - i)));
    sort(p.begin(), p.end());
    for (int i = 0; i < n * m; ++i)
        cout << p[i] << ' ';
}

void id25() {
    int n, count = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        count += a;
    }
    cout << (count % n + n - 1) / n;
}

void id51() {
    string n; cin >> n;
    if ((n[n.length() - 1] - '0') % 2 == 0) {
        cout << 0;
        return;
    }
    if ((n[0] - '0') % 2 == 0) {
        cout << 1;
        return;
    }
    for (int i = 0; i < n.length(); ++i) {
        if ((n[i] - '0') % 2 == 0) {
            cout << 2;
            return;
        }
    }
    cout << -1;
}

void id47() {
    ll a, b;
    cin >> a >> b;
    cout << min(min(a, b), (a + b) / 4);
}

void id43() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    sort(c.begin(), c.end());
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] < l)
            continue;
        if (c[i] > r)
            break;
        if (k >= c[i]) {
            k -= c[i];
            count++;
        } else
            break;
    }
    cout << count;
}

void id60() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> h;
    for (ll i = 0; i < n; ++i) {
        int num; cin >> num;
        h.push_back(make_pair(num, i));
    }
    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());
    ll now = 1, minus = 1;
    vector<ll> a(n), k(n);
    for (ll i = 0; i < n; ++i)
        a[h[i].second] = i;
    ll count = 0;
    for (auto i : h) {
        k[i.second] = minus * now;
        count += 2 * abs(now) * i.first;
        minus = -minus;
        if (minus == 1)
            now++;
    }
    cout << count << "\n0 ";
    for (ll i = 0; i < n; ++i) {
        cout << k[i] << ' ';
    }
}

void id18() {
    int n; cin >> n;
    vector<int> p(n);
    deque<int> ans;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    if (n == 1) {
        cout << 1;
        return;
    }
    if (p[r] != n && p[0] != n) {
        cout << -1;
        return;
    }
    if (p[r] == n)
        --r;
    else
        ++l;
    ans.push_back(n);
    while (r != l) {
        if (min(p[l], p[r]) == p[l]) {
            ans.push_back(p[r]);
            --r;
        } else {
            ans.push_front(p[l]);
            ++l;
        }
    }
    ans.push_front(p[l]);
    for (int i : ans)
        cout << i << ' ';
}

void id61() {
    int x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    int l1 = log10(x1), l2 = log10(x2);
    if (l1 + p1 < l2 + p2) {
        cout << '<';
        return;
    } else if (l1 + p1 > l2 + p2) {
        cout << '>';
        return;
    }
    if (l1 == l2) {
        if (x1 < x2)
            cout << '<';
        else if (x1 > x2)
            cout << '>';
        else
            cout << '=';
        return;
    }
    bool swapped = false;
    if (l1 > l2) {
        swap(x1, x2);
        swap(l1, l2);
        swap(p1, p2);
        swapped = true;
    }
    int new1 = x1 * pow(10, l2 - l1);
    if (new1 < x2) {
        if (swapped)
            cout << '>';
        else
            cout << '<';
    } else if (new1 > x2) {
        if (swapped)
            cout << '<';
        else
            cout << '>';
    } else
        cout << '=';
}

void id38() {
    int n, mn = 1e6 + 7;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < mn)
            mn = a[i];
    }
    int count = 0;
    for (int i = 0; i < n && count < n / 2; ++i) {
        if (a[i] == mn)
            continue;
        cout << a[i] << ' ' << mn << '\n';
        count++;
    }
}

bool can(ll m, ll n, ll h, vector<int> &d) {
    ll count = 0;
    for (int i = 0; i < n; ++i) {
        if (i == n - 1 || d[i] + m < d[i + 1])
            count += m;
        else
            count += d[i + 1] - d[i];
    }
    if (count >= h)
        return true;
    return false;
}

void id22() {
    ll n, h;
    cin >> n >> h;
    vector<int> d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    ll l = 0, r = 1e18 + 4;
    while (r - l > 1) {
        ll k = (r + l) / 2;
        if (can(k, n, h, d))
            r = k;
        else
            l = k;
    }
    cout << r;
}

void id45() {
    int n; cin >> n;
    vector<int> a(n), dp(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {

    }
}

void id41() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n - 1; ++i) {
        if (*max_element(p.begin(), p.begin() + i + 1) > *min_element(p.begin() + i + 1, p.end())) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

void id10() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll count = 0;
    for (int i = 0; i < n; ++i) {
        int id17 = 0;
        for (int j = i; j < n; ++j) {
            int zero_count = id17 + (a[j] == 0);
            count += j - i + 1 + zero_count;
            id17 = zero_count;
        }
    }
    cout << count;
}

void id42() {
    ll n; cin >> n;
    vector<ll> a(n);
    ll count = 0, count_m = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (i != 0 && i != n - 1) {
            count_m += (a[i] + 1) / 2;
            count += a[i];
        }
    }
    if (count % 2 == 1) {
        if (n == 3) {
            cout << -1;
            return;
        }
    }
    if (count <= n - 2) {
        cout << -1;
        return;
    }
    cout << count_m;
}

void id24() {
    int n, m;
    cin >> n >> m;
    map<int, int> count;
    multiset<int> a;
    for (int i = 0; i < n; ++i) {
        int k;
        if (count.count(k) == 0)
            count[k] = 1;
        else
            ++count[k];
        a.insert(k);
    }
    set<pair<int, int>> bad;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        bad.insert(make_pair(x, y));
        bad.insert(make_pair(y, x));
    }
    set<pair<int, int>> count_set;
    for (auto i : count)
        count_set.insert(make_pair(i.second, i.first));
    auto end1 = a.end();
    --end1;
    ll mx;
    while (end1 != a.begin()) {
        auto end2 = count_set.end();
        --end2;
        bool flg = false;
        while (end2 != count_set.begin()) {
            if (*end1 != (*end2).second && bad.count(make_pair(*end1, (*end2).second)) == 0) {
                mx = (count[*end1] + (*end2).first) * (*end1 + (*end2).second);
                flg = true;
                break;
            }
            --end2;
        }
        if (flg)
            break;
        --end1;
    }
    auto end2 = a.end();
    --end2;
    while (end2 != a.begin()) {
        auto end1 = count_set.end();
        --end1;
        bool flg = false;
        while (end1 != count_set.begin()) {
            if (*end2 != (*end1).second && bad.count(make_pair(*end2, (*end1).second)) == 0) {
                if (mx < (count[*end2] + (*end1).first) * (*end2 + (*end1).second))
                    mx = (count[*end2] + (*end1).first) * (*end2 + (*end1).second);
                flg = true;
                break;
            }
            --end1;
        }
        --end2;
        if (flg)
            break;
    }
    cout << mx;
}

void id12() {
    string s, t;
    cin >> s >> t;
    map<int, int> count;
    set<char> sym;
    for (int i = 'a'; i < 'z' + 1; ++i) {
        count[i] = 0;
    }
    for (auto i : s) {
        ++count[i];
        sym.insert(i);
    }
    if (t[0] != 'a' || t == "acb" || count['a'] == 0 || count['b'] == 0 || count['c'] == 0) {
        for (char i : sym) {
            for (int j = 0; j < count[i]; ++j) {
                cout << i;
            }
        }
    } else if (t == "abc") {
        for (char i : sym) {
            if (i == 'b') {
                for (int j = 0; j < count['c']; ++j)
                    cout << 'c';
            } else if (i == 'c') {
                if (count['b'])
                    continue;
                else
                    for (int j = 0; j < count['c']; ++j)
                        cout << 'c';
            }
            for (int j = 0; j < count[i]; ++j)
                cout << i;
        }
    }
}

void id30() {
    int n; cin >> n;
    if (n % 2 == 0)
        cout << n - 3 << ' ' << "2 1";
    else if (n % 4 == 1)
        cout << n / 2 - 1 << ' ' << n / 2 + 1 << " 1";
    else
        cout << n / 2 - 2 << ' ' << n / 2 + 2 << " 1";
}

void id7() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

}

void id35() {
    map<char, int> keyboard;
    for (int i = 0; i < 26; ++i) {
        char key;
        cin >> key;
        keyboard[key] = i;
    }
    string s;
    cin >> s;
    int n = s.length();
    int now = -1, time = 0;
    for (int i = 0; i < n; ++i) {
        if (now != -1)
            time += abs(now - keyboard[s[i]]);
        now = keyboard[s[i]];
    }
    cout << time;
}

void id58() {
    int n; cin >> n;
    vector<int> p(n);
    int first = 1, lg = -2;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (first == i + 1 && p[i] == i + 1)
            ++first;
        else if (lg == -2)
            lg = i - 1;
    }
    for (int i = lg + 1; i < n; ++i) {
        if (p[i] == first) {
            reverse(p.begin() + lg + 1, p.begin() + i + 1);
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
    }
}

void id54() {
    int n; cin >> n;
    vector<int> ne1(n), ne2(n), da1(n), da2(n);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        if (a % 2 == 0) {
            da1.push_back(a);
            da2.push_back(a);
        } else {
            ne1.push_back(a);
            ne2.push_back(a);
        }
    }
    sort(ne1.begin(), ne1.end());
    sort(da1.begin(), da1.end());
    if (ne1 == ne2 && da1 == da2)
        cout << "Yes";
    else
        cout << "No";
}

void id26() {
    int n;
    cin >> n;
    vector<int> p(n);
    int count = 0;
    set<pair<int, int>> mxs;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        mxs.insert(make_pair(p[i], i));
    }
    auto maxIt = mxs.end();
    --maxIt;
    int idx = -1, mn_last = n + 1, idx_min = n;
    for (int i = n - 1; i >= (*maxIt).second; --i)
        if (p[i] <= mn_last)
            mn_last = p[i];
    bool first = true;
    while ((*maxIt).second != 0) {
        idx = (*maxIt).second;
        if (first)
            ++count;
        while (maxIt != mxs.begin() && (*maxIt).second >= idx) {
            --maxIt;
        }
        if ((*maxIt).first <= mn_last)
            ++count;
        for (int i = idx_min - 1; i > (*maxIt).second; --i) {
            if (p[i] <= mn_last) {
                mn_last = p[i];
                idx_min = i;
            }
        }
        first = false;
    }
    cout << max(count, 1);
}

void id6() {
    int n, q;
    cin >> n >> q;
    int bad = sqrt(n);
    vector<int> a(n), color(n), id8, id49;
    for (int i = 0; i < q; ++i) {
        string s; cin >> s;
        if (s == "Color") {
            int l, r, c;
            cin >> l >> r >> c;


        } else if (s == "Add") {

        } else {
            cout << ' ';
        }
    }
}

void id46() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(max(b, c) + 1 - a, 0) << ' ' << max(max(a, c) + 1 - b, 0) << ' ' << max(max(a, b) + 1 - c, 0);
}

void id39() {
    string n; cin >> n;
    int mn = 19;
    if (stoll(n) % 25 == 0) {
        cout << 0;
        return;
    }
    for (int i = 0; i < (int) n.length(); ++i) {
        if ((n[i] - '0') % 5 != 0)
            continue;
        for (int j = 0; j < i; ++j) {
            int dif = (int) n.length() - j - 2;
            if (((n[j] - '0') * 10 + n[i] - '0') % 25 == 0 && (((n[j] - '0') * 10 + n[i] - '0') != 0 || dif != n.length() - 2))
                if (dif < mn)
                    mn = dif;
        }
    }
    cout << mn;
}

bool will_live(int m, int n, int k, vector<int> &pref) {
    return pref[k - m] < n;
}

void id34() {
    int n, k; cin >> n >> k;
    vector<int> x(k), pref(k + 1);
    for (int i = 0; i < k; ++i)
        cin >> x[i];
    sort(x.begin(), x.end());
    pref[k] = 0;
    for (int i = k - 1; i >= 0; --i)
        pref[i] = n - x[i] + pref[i + 1];
    int l = 0, r = k + 2;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (will_live(m, n, k, pref))
            l = m;
        else
            r = m;
    }
    cout << l;
}

void id23() {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
        cout << 0;
    else if (min(n, m) == 1)
        cout << 1;
    else
        cout << 2;
}








void id52() {
     int n;
     cin >> n;
     vector<pair<int, int>> f(n);
     for (int i = 0; i < n; ++i)
         cin >> f[i].first >> f[i].second;
     int l = 0, r = n + 1;






}

void id36() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[n - i - 1];
    int mx = a[0], count = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > mx) {
            ++count;
            mx = a[i];
        }
    }
    cout << count;
}

void do_task() {
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        id36();
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    do_task();


    return 0;
}
