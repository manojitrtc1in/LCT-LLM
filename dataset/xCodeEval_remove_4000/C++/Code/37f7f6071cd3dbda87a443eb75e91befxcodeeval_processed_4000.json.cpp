






















































































using namespace std;
        
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
        
typedef long long base; 
typedef pair<int, int> point;      
typedef complex<double> comp;

const int N = 1e6 + 5;

int n;
vector<pair<int, int>> mem;
vector<int> cnt;
vector<int> t;


bool check(int id) {
    if (id >= n) return true;


    if (t[id] + 1 >= mem.size()) return true;


    int diff = mem[t[id] + 1].second - mem[t[id]].second;


    for (int i = -2; i <= 0; ++i) {
        if (id + i < 0) continue;
        if (id + i + 3 > cnt.size()) continue;
        int res = 1;
        for (int j = 0; j < 3; ++j) {
            int q = i + j + id;
            if (t[q] < t[id]) {
                res *= cnt[q] + 1;
            } else if (t[q] > t[id]) {
                res *= cnt[q];
            }
        }


        diff -= res;
    }


    return diff == 0;
}

vector<int> real_cnt;

void solve(int i) {
    if (i == -1) {
        for (int i = 0; i < 3; ++i) {
            if (!check(i)) {


                return;
            }
        }
        int all = 0;
        for (int i = 0; i + 3 <= n; ++i) {
            all += cnt[i] * cnt[i + 1] * cnt[i + 2];
        }
        if (all == mem[0].second) {
            cout << "! " << cnt << endl;

            assert(real_cnt == cnt);



        }
        return;
    }
    if (!check(i + 3)) {


        return;
    }
    if (cnt[i] == 0) {
        ++cnt[i];
        solve(i - 1);
        --cnt[i];
    }
    solve(i - 1);
}

pair<int, int> count(vector<int> res = {}) {
    if (res.empty()) res = real_cnt;
    pair<int, int> ans = {0, 0};
    for (int i = 0; i < n; ++i) {
        ans.first += res[i] * (res[i] - 1) * (res[i] - 2) / 6;
        if (i + 2 < n) ans.second += res[i] * res[i + 1] * res[i + 2];
    }


    return ans;
}



void solving() {
    vector<vector<int>> possible, bin;
    for (int a = 0; a < 5 * 5 * 5 * 5; ++a) {
        possible.push_back({});
        int cur = a;
        for (int j = 0; j < 4; ++j) {
            possible.back().push_back(cur % 5);
            cur /= 5;
        }
    }


    for (int i = 0; i < possible.size(); ++i) {
        if (count(possible[i]) == mem[0]) {
            bin.push_back(possible[i]);


        }
    }
    swap(bin, possible);
    bin.clear();
    vector<int> f;
    for (int i = 0; i < 4; ++i) {
        int mx_val[4] = {0, 0, 0, 0};
        map<pair<int, int>, int> cur[4];
        for (auto v : possible) {
            for (int j = 0; j < 4; ++j) {
                v[j]++;
                cur[j][count(v)]++;
                v[j]--;
            }
        }
        for (int j = 0; j < 4; ++j) {
            for (auto [key, val] : cur[j]) {
                chkmax(mx_val[j], val);
            }


        }


        int id = min_element(mx_val, mx_val + 4) - mx_val;
        cout << "+ " << id + 1 << endl;
        f.push_back(id);

        real_cnt[id]++;
        mem[i + 1] = count();

        cin >> mem[i + 1];

        sort(possible.begin(), possible.end());
        for (auto v : possible) {
            v[id]++;
            if (count(v) == mem[i + 1]) {
                bin.push_back(v);
            }
        }
        swap(bin, possible);
        bin.clear();
    }
    assert(possible.size() == 1);

    assert(possible[0] == real_cnt);

    for (auto id : f) --possible[0][id];
    cout << "! " << possible[0] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));

    freopen("input", "r", stdin);

    cin >> n;
    int tx = 1;
    while (tx--) {

        real_cnt.resize(n);
        for (int i = 0; i < n; ++i) {
            real_cnt[i] = rand() % 5;
        }

        mem.resize(n + 1);

        mem[0] = count();

        cin >> mem[0];

        if (n == 4) {
            solving();
            continue;
        }
        cnt.resize(n);
        vector<int> order;
        t.resize(n);
        for (int i = 0; i < n; i += 2) {
            t[i] = order.size();
            order.push_back(i);
        }
        for (int i = 1; i < n; i += 2) {
            t[i] = order.size();
            order.push_back(i);
        }
        for (int i = 1; i <= n; ++i) {
            int id = order[i - 1] + 1;
            cout << "+ " << id << endl;

            real_cnt[id - 1]++;
            mem[i] = count();

            cin >> mem[i];

            int v = mem[i].first - mem[i - 1].first;
            v *= 2;


            for (int j = 0;; ++j) {
                if (j * (j - 1) == v) {


                    cnt[id - 1] = j;
                    break;
                }
            }
        }































        for (int i = 0; i < n; ++i) {
            --real_cnt[i];
        }

        solve(n - 1);
    }
}