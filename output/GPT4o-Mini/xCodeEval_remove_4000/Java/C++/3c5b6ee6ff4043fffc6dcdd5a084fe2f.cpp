#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

class State {
public:
    string x, y;

    State(string x, string y) : x(x), y(y) {}

    bool operator==(const State& other) const {
        return x == other.x && y == other.y;
    }

    struct HashFunction {
        size_t operator()(const State& state) const {
            return hash<string>()(state.x) ^ hash<string>()(state.y);
        }
    };
};

class D {
public:
    vector<int> runs(const string& s) {
        vector<int> ret;
        int run = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (i != s.length() - 1 && s[i + 1] != s[i]) {
                ret.push_back(run);
                run = 0;
            }
            run++;
        }
        ret.push_back(run);
        return ret;
    }

    int slow(const string& s, const string& t) {
        queue<State> que;
        unordered_map<State, int, State::HashFunction> dist;

        que.push(State(s, t));
        dist[State(s, t)] = 0;

        while (!que.empty()) {
            State st = que.front();
            que.pop();

            string x = st.x;
            string y = st.y;

            int curD = dist[st];

            if ((x.find('a') == string::npos || x.find('b') == string::npos) &&
                (y.find('a') == string::npos || y.find('b') == string::npos)) {
                return dist[st];
            }

            for (int i = 0; i <= x.length(); i++) {
                for (int j = 0; j <= y.length(); j++) {
                    string x0 = x.substr(0, i);
                    string x1 = x.substr(i);
                    string y0 = y.substr(0, j);
                    string y1 = y.substr(j);

                    string nx = y0 + x1;
                    string ny = x0 + y1;

                    State nst(nx, ny);
                    if (dist.find(nst) == dist.end()) {
                        dist[nst] = curD + 1;
                        que.push(nst);
                    }
                }
            }
        }

        throw runtime_error("Assertion Error");
    }

    int fast(const string& s, const string& t) {
        vector<int> ret;
        vector<int> rs = runs(s);
        vector<int> rt = runs(t);
        bool areSame = s[0] == t[0];

        while (areSame) {
            int p = rs.size();
            int q = rt.size();
            int x = -1, y = -1;

            for (int xx = 0; xx <= 3 && xx <= p; xx++) {
                for (int yy = 0; yy <= 3 && yy <= q; yy++) {
                    if (xx + yy == 0 || x + y == xx + yy) {
                        continue;
                    }
                    if (xx % 2 == yy % 2) {
                        continue;
                    }

                    int nx = p - xx + yy;
                    if (xx != p && yy != 0) {
                        nx--;
                    }

                    int ny = q - yy + xx;
                    if (yy != q && xx != 0) {
                        ny--;
                    }

                    if (nx == 0 || ny == 0) {
                        continue;
                    }

                    if (nx + ny == p + q) {
                        continue;
                    }

                    int val;
                    if ((xx == 0 || yy == 0) && (xx + yy) % 2 == 1) {
                        val = fastDiff(nx, ny) + 1;
                    } else {
                        val = fastSame(nx, ny) + 1;
                    }

                    if (fastSame(p, q) == val) {
                        x = xx;
                        y = yy;
                        break;
                    }
                }
            }

            if ((x == 0 || y == 0) && (x + y) % 2 == 1) {
                areSame = false;
            }

            vector<int> delS(x), delT(y);
            int ans1 = 0, ans2 = 0;

            for (int i = 0; i < x; i++) {
                int delta = rs.back();
                rs.pop_back();
                ans1 += delta;
                delS[i] = delta;
            }

            for (int i = 0; i < y; i++) {
                int delta = rt.back();
                rt.pop_back();
                ans2 += delta;
                delT[i] = delta;
            }

            ret.push_back(ans1);
            ret.push_back(ans2);

            reverse(delS.begin(), delS.end());
            reverse(delT.begin(), delT.end());

            for (int i = 0; i < x; i++) {
                if (i == 0 && !rt.empty()) {
                    rt.back() += delS[i];
                } else {
                    rt.push_back(delS[i]);
                }
            }

            for (int i = 0; i < y; i++) {
                if (i == 0 && !rs.empty()) {
                    rs.back() += delT[i];
                } else {
                    rs.push_back(delT[i]);
                }
            }
        }

        while (rs.size() > 1 || rt.size() > 1) {
            int p = rs.size();
            int q = rt.size();
            int x = -1, y = -1;

            for (int tp = 1; tp <= 3 && tp <= p; tp += 2) {
                for (int tq = 1; tq <= 3 && tq <= q; tq += 2) {
                    int newP = p - tp + tq;
                    if (tp != p) {
                        newP--;
                    }

                    int newQ = q - tq + tp;
                    if (tq != q) {
                        newQ--;
                    }

                    if (newP == 0 || newQ == 0) {
                        continue;
                    }

                    if (newP + newQ == p + q) {
                        continue;
                    }

                    if (fastDiff(p, q) == fastDiff(newP, newQ) + 1) {
                        x = tp;
                        y = tq;
                        break;
                    }
                }
            }

            vector<int> delS(x), delT(y);
            int ans1 = 0, ans2 = 0;

            for (int i = 0; i < x; i++) {
                int delta = rs.back();
                rs.pop_back();
                ans1 += delta;
                delS[i] = delta;
            }

            for (int i = 0; i < y; i++) {
                int delta = rt.back();
                rt.pop_back();
                ans2 += delta;
                delT[i] = delta;
            }

            ret.push_back(ans1);
            ret.push_back(ans2);

            reverse(delS.begin(), delS.end());
            reverse(delT.begin(), delT.end());

            for (int i = 0; i < x; i++) {
                if (i == 0 && !rt.empty()) {
                    rt.back() += delS[i];
                } else {
                    rt.push_back(delS[i]);
                }
            }

            for (int i = 0; i < y; i++) {
                if (i == 0 && !rs.empty()) {
                    rs.back() += delT[i];
                } else {
                    rs.push_back(delT[i]);
                }
            }
        }

        cout << ret.size() / 2 << endl;
        for (size_t i = 0; i < ret.size(); i += 2) {
            cout << ret[i] << " " << ret[i + 1] << endl;
        }
        return ret.size() / 2;
    }

    void submit() {
        string s, t;
        cin >> s >> t;
        fast(s, t);
    }

    int fastSame(int x, int y) {
        int ret = (x + y) / 2;
        if ((x + y) % 4 == 1 && (x == 1 || y == 1)) {
            ret++;
        }
        return ret;
    }

    int fastDiff(int x, int y) {
        if (x == 1 && y == 1) {
            return 0;
        }
        int ret;
        if ((x + y) % 4 == 0) {
            ret = (x + y) / 2;
            if (x % 2 == 0) {
                ret--;
            }
        } else if ((x + y) % 4 == 1) {
            ret = (x + y) / 2;
            if (x == 1 || y == 1) {
                ret++;
            }
        } else if ((x + y) % 4 == 2) {
            ret = (x + y) / 2;
            if (x != 1 && x != 2 && y != 1 && y != 2 && x % 2 == 1) {
                ret--;
            }
        } else if ((x + y) % 4 == 3) {
            ret = (x + y) / 2;
        } else {
            throw runtime_error("Assertion Error");
        }
        return ret;
    }

    D() {
        submit();
    }

    static void main() {
        D();
    }
};

int main() {
    D::main();
    return 0;
}
