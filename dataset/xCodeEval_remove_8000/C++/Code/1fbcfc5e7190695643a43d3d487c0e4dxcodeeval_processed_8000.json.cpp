















using namespace std;
typedef long long ll;

const int N = 2e6 + 1000;
int cnt = 0;


class Trie {
private:
    bool isEnd = false;

    vector<Trie *> children;

public:
    Trie() : children(10), isEnd(false) {

    }

    void insert(const string &num) {
        Trie *node = this;
        for (int i = 0; i < num.size(); i++) {
            int idx = num[i] - '0';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->isEnd = true;

    }
};

class Solution {
public:
    int calPoints(vector<string> &ops) {
        vector<int> nums;
        int ans = 0;
        for (string &op : ops) {
            int len = nums.size();
            int num;
            switch (op[0]) {
                case '=':
                    num = nums[len - 1] + nums[len - 2];
                    ans += num;
                    nums.push_back(num);
                    break;
                case 'D':
                    num = nums[len - 1] * 2;
                    ans += num;
                    nums.push_back(num);
                    break;
                case 'C':
                    ans -= nums[len - 1];
                    nums.pop_back();
                    break;
                default:
                    num = stoi(op);
                    ans += num;
                    nums.push_back(num);
                    break;
            }
        }
        return ans;
    }

    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
        vector<int> a, b;
        for (auto num : set1) {
            if (!set2.count(num))
                a.push_back(num);
        }
        for (auto num : set2) {
            if (!set1.count(num))
                b.push_back(num);
        }
        return {a, b};
    }

    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        auto cmp = [&](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        set<int> available;
        vector<int> task(k);
        int m = 1;
        for (int i = 0; i < k; i++)
            available.insert(i);
        int n = arrival.size();
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && arrival[i] >= pq.top().second) {
                available.insert(pq.top().first);
                pq.pop();
            }
            if (!available.empty()) {
                auto ceiling = available.lower_bound(i % k);
                if (ceiling == available.end())
                    ceiling = available.begin();
                

                pq.emplace(make_pair(*ceiling, arrival[i] + load[i]));

                m = max(m, ++task[*ceiling]);
                available.erase(*ceiling);
            }
        }
        vector<int> ans;
        for (int i = 0; i < task.size(); ++i) {
            if (task[i] == m)
                ans.push_back(i);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        int inf = 0x3f3f3f3f;
        vector<bool> vis(n + 1, false);
        vector<vector<int>> w(n + 1, vector<int>(n + 1, inf));
        vector<int> dist(n + 1, inf);
        dist[k] = 0;
        for (auto &time : times)
            w[time[0]][time[1]] = time[2];
        for (int p = 1; p <= n; ++p) {
            int t = -1;
            for (int i = 1; i <= n; i++) {
                if (!vis[i] && (t == -1 || dist[i] < dist[t])) {
                    t = i;
                }
            }
            vis[t] = true;
            for (int i = 1; i <= n; i++) {
                dist[i] = min(dist[i], dist[t] + w[t][i]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);
        return ans >= inf / 2 ? -1 : ans;
    }

    void dfs(vector<vector<char>> &grid, int x, int y) {
        int row = grid.size(), col = grid[0].size();
        if (grid[x][y] == '0' || x < 0 || x >= row || y < 0 || y >= col)
            return;
        grid[x][y] = '0';
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }

    int numIslands(vector<vector<char>> &grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<int> degree(n);
        vector<vector<int>> nodes(n);
        for (auto &edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.clear();
            int size = q.size();
            for (int j = 0; j < size; j++) {
                int left = q.front();
                ans.push_back(left);
                q.pop();
                for (int i = 0; i < nodes[left].size(); i++) {
                    --degree[nodes[left][i]];
                    if (degree[nodes[left][i]] == 1)
                        q.push(nodes[left][i]);
                }
            }
        }
        return ans;
    }

    vector<int> lexicalOrder(int n) {
        Trie *trie = new Trie();
        for (int i = 1; i <= n; i++) {
            trie->insert(to_string(i));
        }
        vector<int> ans;
        return ans;
    }
};

void id35(vector<vector<int>> &nums) {
    for (auto &num : nums) {
        for (auto &n : num) {
            printf("%d ", n);
        }
        printf("\n");
    }
}

ll gcd(ll x, ll y) {
    return y > 0 ? gcd(y, x % y) : x;
}


struct node {
    int x, y, v;
} e[N];

void add(int x, int y, int v) {
    e[++cnt] = {x, y, v};
}

void addd(int x, int y, int v) {
    if (v < 0)
        add(x, y, v);
    if (v >= 0)
        add(x, y, v), add(y, x, v);
}

int n;

bool bellman() {
    static int d[N];
    d[1] = 0;
    for (int i = 2; i <= n; i++)
        d[i] = 0x7fffffff;
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= cnt; j++) {
            if (d[e[j].x] != 0x7fffffff &&
                d[e[j].x] + e[j].v < d[e[j].y])
                d[e[j].y] = d[e[j].x] + e[j].v;
        }
    for (int i = 1; i <= cnt; i++) {
        if (d[e[i].x] == 0x7fffffff || d[e[i].y] == 0x7fffffff)
            continue;
        if (d[e[i].x] + e[i].v < d[e[i].y])
            return true; 

    }
    return false;
}

void id11() {
    int t, n;
    

    cin >> t;
    while (t--) {
        

        cin >> n;
        vector<int> nums1(n);
        vector<int> nums2(n);
        for (int i = 0; i < n; i++) {
            

            cin >> nums1[i];
        }
        for (int i = 0; i < n; i++) {
            

            cin >> nums2[i];
        }
        for (int i = 0; i < n; i++) {
            if (nums1[i] <= nums2[i])
                continue;
            nums1[i] ^= nums2[i];
            nums2[i] ^= nums1[i];
            nums1[i] ^= nums2[i];
        }
        long long sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += abs(nums1[i] - nums1[i + 1]) + abs(nums2[i] - nums2[i + 1]);
        printf("%lld\n", sum);
    }
}

void GettingZero() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (auto &ele : nums) {
        int ans = 15;
        for (int cntAdd = 0; cntAdd < 15; cntAdd++) {
            for (int cntMul = 0; cntMul < 15; cntMul++) {
                if (((ele + cntAdd) << cntMul) % 32768 == 0)
                    ans = min(ans, cntAdd + cntMul);
            }
        }
        printf("%d\n", ans);
    }
}

void id15() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d %d %d %d\n", n - 3, 1, 1, 1);
    }
}

void id22() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            ++m[val];
            

            

            

            

            

            

            

            

            

            

        }
        int maxFreq = 0;
        for (auto &[k, v] : m)
            maxFreq = max(maxFreq, v);

        int ans = 0;
        while (maxFreq < n) {
            int d = min(maxFreq, n - maxFreq);
            ans += d + 1;
            maxFreq += d;
        }
        printf("%d\n", ans);
    }
}

void SubtractOperation() {
    int t;
    scanf("%d", &t);
    next:
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (n == 1) {
            int val;
            scanf("%d", &val);
            printf(val == k ? "YES\n" : "NO\n");
        } else {
            set<int> s;
            vector<int> nums(n);
            for (auto &e : nums) scanf("%d", &e);
            for (int i = 0; i < n; i++) {
                int t = nums[i] - k;
                int p = nums[i] + k;
                if (s.find(t) != s.end() || s.find(p) != s.end()) {
                    printf("YES\n");
                    goto next;
                } else {
                    s.emplace(nums[i]);
                }
            }
            printf("NO\n");
        }
    }
}


void id16() {
    int t;
    scanf("%d", &t);
    next:
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<int>> cells(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            string s;
            s.resize(m);
            scanf("%s", s.c_str());
            for (int j = 0; j < m; j++) cells[i][j] = s[j] - '0';
        }
        if (cells[0][0] == 1) {
            printf("-1\n");
            goto next;
        }








        vector<vector<int>> ans(n, vector<int>(m + 1));
        vector<vector<int>> record;
        for (int i = 2; i <= m; i++) ans[0][i] = !ans[0][i - 1];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                ans[i][j] = !ans[i - 1][j];
            }
        }
        bool isidentify = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cells[i][j] != 0) {
                    isidentify = false;
                    break;
                }
            }
        }
        if (isidentify) {
            printf("0\n");
            goto next;
        }


        record.push_back({1, 1, n, m});



        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (ans[i][j + 1] == 1 && cells[i][j] == 0) {
                    ans[i][j + 1] = 0;
                    record.push_back({i + 1, j + 1, i + 1, j + 1});


                } else if (ans[i][j + 1] == 0 && cells[i][j] == 1) {
                    if (j == 0) {
                        ans[i - 1][j + 1] = 0;
                        ans[i][j + 1] = 1;
                        record.push_back({i, j + 1, i + 1, j + 1});
                    } else {
                        ans[i][j] = 0;
                        ans[i][j + 1] = 1;
                        record.push_back({i + 1, j, i + 1, j + 1});
                    }


                }
            }
        }
        printf("%d\n", record.size());
        for (auto &ele : record) {
            printf("%d %d %d %d\n", ele[0], ele[1], ele[2], ele[3]);
        }
        





















    }


}


void id6() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        string str;
        scanf("%d%d", &n, &k);
        str.resize(n);
        scanf("%s", str.c_str());
        int tmpK = k;
        vector<int> ans(n);
        for (int i = 0; i < n && tmpK > 0; i++) {
            if (str[i] - '0' == (k & 1)) {
                ans[i] += 1;
                tmpK--;
            }
        }
        ans[n - 1] += tmpK;


        for (int i = 0; i < n; i++) {
            if ((k - ans[i] & 1) > 0) {
                str[i] = ('1' - str[i] + '0');
            }

        }
        printf("%s\n", str.c_str());

        for (auto &ele : ans) {
            printf("%d ", ele);
        }
        printf("\n");
    }
}

void id13() {
    int t;
    scanf("%d", &t);
    vector<int> nums(t);
    ll ans = id28;
    for (auto &ele : nums) scanf("%d", &ele);
    for (int i = 0; i < t; i++) {
        vector<ll> b(t);
        ll tmp = 0;
        int l = i - 1, r = i + 1;
        while (l >= 0) {
            ll cnt = -(b[l + 1] / nums[l] - 1);
            tmp += cnt;
            b[l] = -cnt * nums[l];
            l--;
        }
        while (r < t) {
            ll cnt = b[r - 1] / nums[r] + 1;
            tmp += cnt;
            b[r] = cnt * nums[r];
            r++;
        }
        ans = min(ans, tmp);
    }
    printf("%lld\n", ans);
}

void id25() {
    int t;
    scanf("%d", &t);
    next:
    while (t--) {
        int n;
        scanf("%d", &n);
        string s;
        s.resize(n);
        scanf("%s", s.c_str());
        s = 'W' + s + 'W';

        bool turn = false;
        bool id14 = false, id19 = false;
        for (int i = 0; i < n + 2; i++) {
            if (s[i] == 'W') {
                turn ^= i;
                if (turn) {
                    if (id19 ^ id14) {
                        printf("NO\n");
                        goto next;
                    } else {
                        id19 = false;
                        id14 = false;
                    }
                }
            } else if (s[i] == 'B') {
                id19 = true;
            } else {
                id14 = true;
            }
        }
        printf(id19 ^ id14 ? "NO\n" : "YES\n");
    }
}

void Kickdown() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        int ans1 = 0, ans2 = 0;
        for (int i = 0, j = 0, k = 0; i < s1.size() || j < s2.size();) {
            if (i < s1.size() && j < s2.size() && s1[i] - '0' + s2[j] - '0' == 4) {
                k++;
                i = k;
                j = 0;
                ans1 = k;
            } else {
                i++;
                j++;
                ans1++;
            }
        }
        for (int i = 0, j = 0, k = 0; i < s1.size() || j < s2.size();) {
            if (i < s1.size() && j < s2.size() && s1[i] - '0' + s2[j] - '0' == 4) {
                k++;
                j = k;
                i = 0;
                ans2 = k;
            } else {
                i++;
                j++;
                ans2++;
            }
        }
        printf("%d\n", min(ans1, ans2));
    }
}

void id24() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> nums(n);
        for (auto &ele : nums) scanf("%d", &ele);
        int l = 0, r = n - 1;
        int alice = 0, bob = 0;
        alice += nums[l];
        bob += nums[r];
        int ans = 0;
        while (l < r) {
            if (alice < bob) {
                l++;
                alice += nums[l];
            } else if (alice > bob) {
                r--;
                bob += nums[r];
            } else {
                ans = max(ans, l + n - r + 1);
                l++;
                r--;
                alice += nums[l];
                bob += nums[r];
            }
        }
        printf("%d\n", ans);
    }
}


void Division() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n >= 1900) {
            printf("Division 1\n");
        } else if (n >= 1600) {
            printf("Division 2\n");
        } else if (n >= 1400) {
            printf("Division 3\n");
        } else {
            printf("Division 4\n");
        }
    }
}


void id0() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        bool f = true;
        bool all = true;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            if (i == 0) {
                ans = val & 1;
            } else if (!(val & 1 ^ ans)) {
                ans = val & 1;
                f = false;
            } else {
                ans = val & 1;
                all = false;
            }
        }
        printf(f || all ? "YES\n" : "NO\n");
    }
}


void FallDown() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<string> container(n);
        for (auto &ele : container) ele.resize(m), scanf("%s", ele.c_str());


        for (int i = n - 2; i >= 0; i--) {
            string t = container[i];
            for (int j = 0; j < m; j++) {
                if (t[j] == '*') {
                    int dec = i;
                    while (dec + 1 < n && container[dec + 1][j] == '.') {
                        dec++;
                    }
                    container[dec][j] = '*';
                    if (i != dec)
                        container[i][j] = '.';
                }
            }
        }

        for (auto &ele:container) {
            printf("%s\n", ele.c_str());
        }
        printf("\n");

    }
}

void id7() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);


        vector<int> cnt(31), nums(n);


        for (auto &ele : nums) {
            scanf("%d", &ele);
            for (int i = 30; i >= 0; i--) {
                if (1 << i & ele) {
                    cnt[i]++;
                }
            }
        }

        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int need = n - cnt[i];
            if (k >= need) {
                k -= need;
                ans += 1 << i;
            }
        }
        printf("%d\n", ans);
    }
}


void id32() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int cnt['k' - 'a' + 1]['k' - 'a' + 1];
        for (auto &ele : cnt) for (auto &e : ele) e = 0;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            string str = "";
            str.resize(2);
            scanf("%s", str.c_str());
            for (int j = 0; j < 2; j++) {
                for (char k = 'a'; k <= 'k'; k++) {
                    if (k == str[j]) continue;
                    string s = str;
                    s[j] = k;
                    ans += cnt[s[0] - 'a'][s[1] - 'a'];
                }
            }
            cnt[str[0] - 'a'][str[1] - 'a']++;
        }
        printf("%lld\n", ans);
    }

}


void id31() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        vector<int> nums(n);
        ll sum = 0;
        for (auto &ele : nums) scanf("%d", &ele), sum += ele;
        sort(nums.begin(), nums.end());
        ll ans = 0;
        int day = -1;
        for (int i = n - 1; i >= 0; i--) {
            int curDay = x - sum >= 0 ? (x - sum) / (i + 1) : -1;
            ans += (i + 1) * (curDay - day);
            day = curDay;
            sum -= nums[i];
        }
        printf("%lld\n", ans);
    }
}

void id1() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> nums(n);
        for (auto &ele :nums) scanf("%d", &ele);
        

        printf(nums[n - 1] - nums[0] - n == -1 || nums[n - 1] - nums[0] - n == 1 || nums[n - 1] - nums[0] - n == 0
               ? "YES\n" : "NO\n");
    }
}


void id30() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, r, b;
        scanf("%d%d%d", &n, &r, &b);
        int gap = r / (b + 1);
        int remaining = r % (b + 1);
        string ans = "";

        int cnt = 0;
        for (int i = 0; i < b + 1; i++) {
            for (int j = 0; j < gap; j++) ans += "R";
            ans += remaining-- > 0 ? "R" : "";
            ans += cnt++ < b ? "B" : "";
        }
        cout << ans << endl;
    }
}


void LineEmpire() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll a, b;
        cin >> n >> a >> b;
        vector<ll> x(n + 1), p(n + 1);
        x[0] = 0;
        for (int i = 1; i <= n; i++) cin >> x[i];
        partial_sum(x.begin(), x.end(), p.begin());

        ll ans = id28;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, (a + b) * (x[i] - x[0]) + b * (p[n] - p[i] - (n - i) * x[i]));
        }
        cout << ans << endl;
    }
}

int id8(ll num, vector<ll> &facts, int cont) {
    if (cont < 0) return 0x3f3f3f3f;
    if (!num) return 0;
    while (cont >= 0 && facts[cont] > num) cont--;
    return 1 + id8(num - facts[cont], facts, cont - 1);


















}

void id23() {
    vector<ll> facts(21);
    facts[0] = 1;
    for (int i = 1; i < 21; i++) facts[i] = facts[i - 1] * i;

    int t;
    scanf("%d", &t);
    while (t--) {
        long long n;
        scanf("%lld", &n);
        int ans = INT_MAX;
        int rec = 20;
        for (ll i = 0; i <= (1 << 15); i++) {
            ll m = n;
            int cnt = 0;
            for (int j = 0; j < 15; j++) {
                if (i >> j & 1) {
                    m -= facts[j];
                    cnt++;
                }




            }
            if (m >= 0)
                ans = min(ans, cnt + __builtin_popcountll(m));
        }
        printf("%d\n", ans);
    }
}

int id20(ll num) {
    int ans = 0;
    while (num) {
        if (num & 1) ans++;
        num >>= 1;
    }
    return ans;
}

void A() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        double speed = stod(s2.substr(0, s2.size() - 1));
        int time = 0;
        int cnt = 1;
        for (auto &ele : s1) cnt += ele == ':' ? 1 : 0;

        for (int i = 0, s = s1.size(); i < cnt; i++, s -= 2) {
            time += stoi(s1.substr(s - 2, s)) * (int) pow(60, i);
            s--;
        }

        time /= speed;
        time = (int) time;
        string ans = "";
        for (int i = cnt - 1; i >= 0; i--) {
            if (time / (int) pow(60, i) < 10) ans += "0" + to_string(time / (int) pow(60, i));
            else ans += to_string(time / (int) pow(60, i));
            time %= (int) pow(60, i);
            if (i != 0) ans += ":";
        }
        cout << ans << endl;
    }
}

void id18() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string s;
        cin >> n;
        cin >> s;
        map<char, int> mp;
        cin >> m;
        for (int i = 0; i < m; i++) {
            char a;
            cin >> a;
            mp[a]++;
        }
        int l = 0, r = 0; 

        int ans = 0; 

        for (int i = 0; i < n; i++) {
            if (mp[s[i]]) {
                l = r;
                r = i;
                ans = max(ans, r - l);
            }
        }
        cout << ans << endl;
    }
}

int get(int a[], int l, int r, int v) { 
    int minv = 1e9;
    for (int i = l; i <= r; i++)
        minv = min(minv, abs(v - a[i]));
    return minv;

}

void id12() {
    int i, j, t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n + 5], b[n + 5];
        for (i = 1; i <= n; i++)
            cin >> a[i];
        for (i = 1; i <= n; i++)
            cin >> b[i];
        ll l1 = get(b, 2, n, a[1]), r1 = get(b, 1, n - 1, a[n]);
        ll l2 = get(a, 2, n, b[1]), r2 = get(a, 1, n - 1, b[n]);
        ll s1 = l1 + l2 + r1 + r2, s2 = abs(a[1] - b[1]) + r1 + r2, s3 = l1 + l2 + abs(a[n] - b[n]);
        ll spj = min(abs(a[1] - b[n]) + abs(a[n] - b[1]), abs(a[1] - b[1]) + abs(a[n] - b[n]));
        spj = min(spj, l1 + r2 + abs(a[n] - b[1]));
        spj = min(spj, l2 + r1 + abs(a[1] - b[n]));
        cout << min(spj, min(s1, min(s2, s3))) << endl;
    }
}


void InfiniteReplacement() {
    int t;
    cin >> t;
    while (t--) {
        string s, q;
        cin >> s >> q;
        if (q.size() == 1 && q == "a") cout << 1 << endl;
        else if (q.size() > 1 && q.find('a') != -1) cout << -1 << endl; 

        else {
            int cnt = 0;
            for (int i = 0; i < s.size(); i++)
                cnt += s[i] == 'a' ? 1 : 0;
            cout << (long long) pow(2, cnt) << endl;
        }
    }
}

void id9() { 

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &ele : a) cin >> ele;
        if (n == 1)
            printf("YES\n");
        else {
            bool flag = true;
            if (n % 2 == 0) {
                for (int i = 0; i < n; i += 2)

                    if (a[i] > a[i + 1])
                        swap(a[i], a[i + 1]);
            } else {
                for (int i = 1; i < n; i += 2)
                    if (a[i] > a[i + 1])
                        swap(a[i], a[i + 1]);
            }

            


            for (int i = 1; i < n; i++)
                if (a[i] < a[i - 1]) {
                    flag = false;
                    break;
                }
            printf("%s\n", (flag ? "YES" : "NO"));
        }
    }
}


void id26() {
    int t;
    cin >> t;
    nx:
    while (t--) {
        string describe = "";
        cin >> describe;
        int n = describe.size();
        if (n == 1) cout << 1 << endl;
        else {
            int firstOne = -1, id3 = -1;
            for (int i = 0; i < n; i++) {
                if (describe[i] == '1') {
                    firstOne = i;  

                    if (id3 == -1) id3 = i;
                } else if (firstOne > -1 && describe[i] == '0') { 

                    cout << i - firstOne + 1 << endl;
                    goto nx;
                } else if (describe[i] == '0') { 

                    cout << i + 1 << endl;
                    goto nx;
                }
            }
            if (firstOne > -1)  

                cout << n - firstOne << endl;
            else cout << n << endl;
        }
    }
}


void EatingQueries() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> candie(n);
        for (auto &ele : candie) cin >> ele;
        sort(candie.begin(), candie.end(), greater<int>());
        vector<int> prefix(n);
        partial_sum(candie.begin(), candie.end(), prefix.begin());
        for (int i = 0; i < q; i++) {
            int qu;
            cin >> qu;
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (r - l) / 2 + l;
                int ret = prefix[mid];
                if (ret >= qu) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            cout << (l != n - 1 ? l + 1 : prefix[l] >= qu ? l + 1 : -1) << endl;
        }
    }
}

void LongestStrike() {
    struct cmp {
        bool operator()(const int &v1, const int &v2) const {
            return v2 < v1;
        }
    };

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int, cmp> mp;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            mp.insert_or_assign(val,
                                mp.find(val) != mp.end() ? mp.find(val)->second : 0);
        }

    }
}

void id36() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int, greater<int>> st;
        vector<int> nums;
        int val, mi = INT_MAX;
        for (int i = 0; i < n; i++) cin >> val, nums.emplace_back(val), mi = min(mi, val);
        for (int i = 0, k = 0; k < n / 2; i++)
            if (nums[i] != mi)
                cout << nums[i] << ' ' << mi << endl, k++;
    }


}

void id34() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int &ele : nums) cin >> ele;
        vector<int> cannot;
        int ans = n;
        cannot.emplace_back(0);
        for (int i = 0; i < cannot.size(); i++) {
            for (int j = cannot[i] + 1; j < n; j++) {
                if (nums[cannot[i]] > nums[j]) ans--;
                else if (nums[j] > nums[cannot.back()]) cannot.emplace_back(j);
            }
        }
        cout << ans << endl;
    }

}

void id29() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        int power = 9;
        while ((int) (pow(10, power)) > num) {
            power--;
        }
        cout << num - (int) (pow(10, power)) << '\n';
    }
}

void id37() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i] / k;
            a[i] = a[i] % k;
        }
        sort(a.begin(), a.end(), [](int x, int y) {
            return x > y;
        });

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            while (a[i] + a[j] < k && i < j) j--;
            if (i == j) break;
            sum++;
        }
        cout << sum << endl;
    }

}

bool bs(vector<int> &nums, int l, int r, int tar) {
    while (l <= r) {
        int m = (r - l) / 2 + l;
        int ret = nums[m];
        if (ret > tar) r = m - 1;
        else if (ret < tar) l = m + 1;
        else return true;
    }
    return false;
}

void ThreeSUM() {
    int n;
    cin >> n;
    int cnt[10] = {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % 10]++;
    }

    vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < min(cnt[i], 3); j++) vec.emplace_back(i);
    }
    int m = vec.size();
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = 1 + j; k < m; ++k) {
                if ((vec[i] + vec[j] + vec[k]) % 10 == 3) {
                    cout << "yes\n";
                    return;
                }
            }
        }
    }
    cout << "no\n";
}

void id2() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int first = -1, last = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        last = i;
        if (first == -1) first = i;
        cnt++;
    }
    int ans = 0;
    if (cnt && n - 1 - last <= k) {
        k -= n - 1 - last;
        ans += 1;
        cnt--;
    }
    if (cnt && k >= first) {
        cnt--;
        k -= first;
        ans += 10;
    }

    cout << 11 * cnt + ans << '\n';
}

void id4() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> nums(n);

    for (int i = 1; i <= n; i++) {
        nums[i - 1] = ((l - 1) / i + 1) * i;
        if (nums[i - 1] > r) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto &e : nums) cout << e << ' ';
    cout << endl;
}


void id10() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string num;
    string ans = "";

    if (s[0] == '9') {
        num = string(n + 1, '1');
        int i = num.size() - 1;
        n--;
        while (i > 0 || n > 0) {
            if (num[i] >= s[n]) {
                ans.insert(ans.begin(), num[i] - s[n] + '0');
            } else {
                ans.insert(ans.begin(), num[i] - s[n] + '\n' + '0');
                if (i >= 1) num[i - 1] -= 1;
                else break;
            }
            i--;
            n--;
        }
    } else {
        num = string(n, '9');
        int i = num.size() - 1;
        n--;
        while (i >= 0 || n >= 0) {
            ans.insert(ans.begin(), n >= 0 ? num[i] - s[n] + '0' : num[i]);
            i--;
            n--;
        }
    }
    cout << ans << endl;
}



void id27() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto &e : nums) cin >> e;

    sort(nums.rbegin(), nums.rend());
    int ans = 0;
    int i = k;
    for (; i < 2 * k; i++) {
        ans += nums[i] / nums[i - k];
    }
    while (i < n) {
        ans += nums[i++];
    }
    cout << ans << '\n';
}

void id38() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int single = 0, doubl = 0;
    for (auto &[k, v] : mp) {
        v == 1 ? ++single : ++doubl;
    }
    cout << doubl + (single + 1) / 2 << '\n';
}

vector<pair<int, long long>> partition(int &n, int &m) { 

    vector<pair<int, long long> > ans;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        long long c = 1;
        while (a % m == 0)
            a /= m, c *= m;
        if (ans.empty() || ans.back().first != a) ans.emplace_back(a, c);
        else ans.back().second += c;
    }
    return ans;
}

void id5() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, long long>> nums = partition(n, m);;

    int k;
    cin >> k;
    vector<pair<int, long long>> ano = partition(k, m);
    cout << (nums == ano ? "YES" : "NO") << endl;
}


void id33() {
    int n;
    cin >> n;
    vector<int> nums(n);
    bool f = 0;
    for (auto &e : nums) {
        cin >> e;
        int remainder = e % 10;
        if (remainder == 5 || remainder == 0) {
            e += remainder;
            f = 1;
        }
    }
    if (f) {
        cout << (*max_element(nums.begin(), nums.end()) == *min_element(nums.begin(), nums.end()) ?
                 "YES\n" : "NO\n");
        return;
    }
    for (auto &ele : nums) {
        int e = ele % 10;
        if (e == 1) {
            ele += 1;
        } else if (e == 3) {
            ele += 9;
        } else if (e == 4) { 

            ele += 18;
        } else if (e == 6) {
            ele += 6;
        } else if (e == 7) {
            ele += 25;
        } else if (e == 8) {
            ele += 14;
        } else if (e == 9) {
            ele += 23;
        }
    }

    for (int i = 1; i < n; i++) {
        if (abs(nums[i] - nums[i - 1]) % 20) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}


void recurse(int r, vector<int> &ans) {
    if (r < 0) return;
    int num = sqrt(2 * r);
    num *= num;
    int l = num - r;
    recurse(l - 1, ans);
    while (l <= r) {
        ans[l] = r;
        ans[r] = l;
        r--;
        l++;
    }
}

void BuildPermutation() {
    

    int n;
    cin >> n;
    vector<int> nums(n, -1);

    recurse(n - 1, nums);
    for (auto &e : nums) cout << e << ' ';
    cout << '\n';
}


void id21() {
    int n;
    cin >> n;
    unordered_set<int> nums(n);
    bool f = 0;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        nums.emplace(e);
        if (e == 1) f = 1;
    }
    if (f) {
        for (auto &e : nums) {
            if (nums.count(e - 1) || nums.count(e + 1)) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

long long  solve(unordered_map<int, vector<int>> rows) {
    long long ans = 0;
    for (auto &[k, v] : rows) {
        sort(v.begin(), v.end());
        int sz = v.size();
        for (long long i = sz - 1; i >= 0; i--) {
            ans += i * v[i] - (sz - 1 - i) * v[i];
        }
    }
    return ans;
}

void id17() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int e;
            cin >> e;
            rows[e].emplace_back(i);
            cols[e].emplace_back(j);
        }
    }
    cout << solve(rows) + solve(cols) << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    id17();






    

    

    

    

    

    

    

    




}