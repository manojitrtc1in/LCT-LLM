

















using namespace std;

typedef unsigned long long ull;

const int LIM = 256;
const int INF = 1e9 + 239;
const int MAX_STEP = 5;
const int BASE = 256;
const int id0 = 11;
const char CHANGE_LINE = '

string fast_to_string[LIM];
pair<int, int> valid_pairs[id0];

namespace State {
    int steps;
    int val[MAX_STEP + 1];
    string go[MAX_STEP + 1];
    int pnt = -1;
    
    void init() {
        val[0] = 1;
        go[0] = "MAVZES_BEST";
        pnt = 1;
    }
    
    void add(int val_, string tmp) {
        steps++;
        val[pnt] = val_;
        go[pnt] = tmp;
        pnt++;
    }
    
    void pop() {
        steps--;
        pnt--;
    }
};


int best = INF;
vector<string>ans [LIM];

unordered_set<ull> seen[MAX_STEP + 3];

void dfs(ull cur_hash) {
    assert(State::steps < MAX_STEP + 3);
    seen[State::steps].insert(cur_hash);
    for (int i = 0; i < State::pnt; i++) {
        if (ans[State::val[i]].size() > State::steps) {
            ans[State::val[i]].clear();
            for (int j = 0; j < State::pnt; j++) {
                ans[State::val[i]].push_back(State::go[j]);
            }
        }
    }
    if (State::steps + 1 > MAX_STEP) {
        return;
}
    string cx;
    cx.push_back(State::steps + 1 + 'a');
    for (int y = 0; y <= State::steps; y++) {
        string cy;
        cy.push_back(y + 'a');
        for (int z = 0; z <= State::steps; z++) {
            string cz;
            cz.push_back(z + 'a');
            for (int i = 0; i < id0; i++) {
                int a = valid_pairs[i].first;
                int b = valid_pairs[i].second;
                int nval = a * State::val[y] + b * State::val[z];
                if (nval >= LIM) {
                    break;
                }
                ull new_hash = (cur_hash * BASE) + nval;
                if (seen[State::steps + 1].count(new_hash)) {
                    continue;
                }
                string ca = fast_to_string[a];
                string cb = fast_to_string[b];
                if (b == 0) {
                    State::add(nval, "lea e" + cx + "x, ["  + ca + "*e" + cy + "x]");
                } else if (a == 0) {
                    State::add(nval, "lea e" + cx + "x, [" + cb + "*e" + cz + "x]");
                } else if (a == 1) {
                    State::add(nval, "lea e" + cx + "x, [e" + cy + "x + " + cb + "*e" + cz + "x]");
                } else if (b == 1) {
                    State::add(nval, "lea e" + cx + "x, [e" + cz + "x + " + ca + "*e" + cy + "x]");
                } else {
                    continue;
                }
                dfs(new_hash);
                State::pop();
            }
        }
    }
}

string rans[LIM];

void solve() {
    State::init();
    ull h = 1;
    dfs(h);
    for (int i = 0; i < LIM; i++) {
        string cur;
        string uu = to_string((int)ans[i].size() - 1);
        for (auto y : uu) {
            cur.push_back(y);
        }
        cur.push_back('\n');
        for (int j = 1; j < (int)ans[i].size(); j++) {
            for (auto c : ans[i][j]) {
                cur.push_back(c);
            }
            cur.push_back('\n');
        }
        rans[i] = cur;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    

    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));

    
    vector<string> uu = {
        "6
        "0
        "1
        "1
        "1
        "1
        "2
        "2
        "1
        "1
        "2
        "2
        "2
        "2
        "3
        "2
        "2
        "2
        "2
        "2
        "2
        "2
        "3
        "3
        "2
        "2
        "3
        "2
        "3
        "3
        "3
        "3
        "2
        "2
        "3
        "3
        "2
        "2
        "3
        "3
        "2
        "2
        "3
        "3
        "3
        "2
        "3
        "3
        "3
        "3
        "3
        "3
        "3
        "3
        "3
        "3
        "3
        "3
        "4
        "3
        "3
        "3
        "4
        "3
        "2
        "2
        "3
        "3
        "3
        "3
        "3
        "4
        "2
        "2
        "3
        "3
        "3
        "3
        "4
        "4
        "3
        "2
        "3
        "3
        "3
        "3
        "4
        "3
        "3
        "3
        "3
        "3
        "4
        "3
        "4
        "3
        "3
        "3
        "4
        "3
        "3
        "3
        "4
        "3
        "3
        "3
        "4
        "3
        "3
        "3
        "4
        "3
        "4
        "3
        "4
        "4
        "4
        "3
        "4
        "4
        "3
        "3
        "4
        "3
        "4
        "3
        "4
        "4
        "3
        "3
        "3
        "3
        "3
        "3
        "4
        "3
        "3
        "3
        "3
        "4
        "3
        "4
        "4
        "4
        "3
        "3
        "3
        "3
        "3
        "3
        "4
        "4
        "3
        "3
        "4
        "3
        "4
        "3
        "4
        "4
        "3
        "3
        "3
        "3
        "3
        "3
        "4
        "4
        "3
        "3
        "4
        "3
        "4
        "3
        "4
        "4
        "4
        "4
        "4
        "4
        "3
        "3
        "4
        "4
        "4
        "3
        "4
        "4
        "4
        "3
        "4
        "4
        "3
        "3
        "4
        "3
        "4
        "4
        "4
        "4
        "3
        "3
        "4
        "3
        "4
        "3
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "3
        "3
        "4
        "3
        "4
        "4
        "4
        "4
        "4
        "3
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "3
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "4
        "5
        "4

    };
    






































































    
    int n;
    cin >> n;
    for (auto t : uu[n]) {
        if (t == CHANGE_LINE) {
            cout << '\n';
        } else {
            cout << t;
        }
    }
}
