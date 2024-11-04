#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Graph {
private:
    int maxV;
    bool isflow;
    bool sparse;
    vector<int> _V;
    unordered_map<int, int> _V_index;
    vector<unordered_map<int, int>> _E;
    vector<unordered_set<int>> _adj;
    unordered_map<int, vector<int>> _levels;

public:
    Graph(int maxV, bool isflow=false, bool sparse=false) : maxV(maxV), isflow(isflow), sparse(sparse) {
        _E.resize(maxV);
        _adj.resize(maxV);
    }

    bool id14(int label) {
        return _V_index.count(label) > 0;
    }

    void add_vertex(int label) {
        _V_index[label] = _V.size();
        _V.push_back(label);
    }

    void id12(vector<int>& labels) {
        for (int u_label : labels) {
            add_vertex(u_label);
        }
    }

    void _add_edge(int u, int v, int w) {
        if (isflow) {
            _E[u][v] += w;
            _adj[u].insert(v);
            _adj[v].insert(u);
        } else {
            _E[u][v] = w;
            _adj[u].insert(v);
        }
    }

    void add_edge(int u_label, int v_label, int w=1) {
        int u = _V_index[u_label];
        int v = _V_index[v_label];
        _add_edge(u, v, w);
    }

    bool _isadj(int u, int v) {
        return _adj[u].count(v) > 0;
    }

    bool isadj(int u_label, int v_label) {
        int u = _V_index[u_label];
        int v = _V_index[v_label];
        return _isadj(u, v);
    }

    void trim(int u_label) {
        int u = _V_index[u_label];
        _adj[u].clear();
        if (sparse) {
            _E[u].clear();
        } else {
            for (auto& it : _E[u]) {
                it.second = numeric_limits<int>::max();
            }
        }
    }

    int id20(int s, int t) {
        _levels[s] = vector<int>(maxV, numeric_limits<int>::max());
        _levels[s][s] = 0;

        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : _adj[u]) {
                if (_E[u][v] > 0 && _levels[s][v] == numeric_limits<int>::max()) {
                    _levels[s][v] = _levels[s][u] + 1;
                    q.push(v);
                }
            }
        }

        return _levels[s][t];
    }

    int id30(int s, int t) {
        unordered_map<int, int> pointers;
        for (int u = 0; u < maxV; u++) {
            pointers[u] = _adj[u].size();
        }

        function<int(int, int, int)> dfs_push = [&](int u, int t, int inflow) {
            if (u == t) {
                return inflow;
            }
            int id4 = 0;
            while (pointers[u] > 0) {
                int v = *(_adj[u].begin() + pointers[u] - 1);
                if (_levels[s][v] == _levels[s][u] + 1 && _E[u][v] > 0) {
                    int v_flow = dfs_push(v, t, min(inflow, _E[u][v]));
                    _E[u][v] -= v_flow;
                    _E[v][u] += v_flow;
                    inflow -= v_flow;
                    id4 += v_flow;
                    if (inflow == 0) {
                        pointers[u]++;
                        break;
                    }
                } else {
                    pointers[u]--;
                }
            }

            return id4;
        };

        int blocking_flow = dfs_push(s, t, numeric_limits<int>::max());
        _levels.clear();
        return blocking_flow;
    }

    int max_flow(int s_label, int t_label) {
        int s = _V_index[s_label];
        int t = _V_index[t_label];

        vector<unordered_map<int, int>> E_saved = _E;

        int mf = 0;
        while (id20(s, t) != numeric_limits<int>::max()) {
            mf += id30(s, t);
        }

        _E = E_saved;
        return mf;
    }

    unordered_map<int, unordered_map<int, int>> id1() {
        vector<vector<int>> fw = _E;
        for (int k = 0; k < maxV; k++) {
            vector<vector<int>> next_fw(maxV, vector<int>(maxV));
            for (int i = 0; i < maxV; i++) {
                for (int j = 0; j < maxV; j++) {
                    next_fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
                }
            }
            fw = next_fw;
        }

        unordered_map<int, unordered_map<int, int>> id10;
        for (int u = 0; u < maxV; u++) {
            unordered_map<int, int> inner;
            for (int v = 0; v < maxV; v++) {
                inner[_V[v]] = fw[u][v];
            }
            id10[_V[u]] = inner;
        }

        return id10;
    }

    unordered_map<int, int> id9(int s_label, vector<int>& t_labels, int d_limit=numeric_limits<int>::max()) {
        int s = _V_index[s_label];
        unordered_set<int> t_set(t_labels.begin(), t_labels.end());

        unordered_map<int, int> ret;

        unordered_map<int, int> queue;
        queue[s] = 0;

        unordered_map<int, int> spaths;
        unordered_map<int, int> parents;
        vector<int> t_found;

        while (!queue.empty()) {
            auto it = min_element(queue.begin(), queue.end(), [](const auto& a, const auto& b) {
                return a.second < b.second;
            });
            int u = it->first;
            int su = it->second;
            queue.erase(it);

            spaths[u] = su;
            if (t_set.count(u) > 0) {
                t_set.erase(u);
                t_found.push_back(u);
                if (t_set.empty()) {
                    ret["stop"] = su;
                    break;
                }
            }

            for (int v : _adj[u]) {
                int sv = su + _E[u][v];
                if (queue.count(v) > 0) {
                    if (sv < queue[v]) {
                        parents[v] = u;
                        queue[v] = sv;
                    }
                } else if (spaths.count(v) == 0) {
                    parents[v] = u;
                    queue[v] = sv;
                }
            }
        }

        if (queue.empty()) {
            ret["stop"] = numeric_limits<int>::max();
        }

        for (const auto& it : spaths) {
            ret[_V[it.first]] = it.second;
        }
        for (const auto& it : parents) {
            ret[_V[it.first]] = _V[it.second];
        }
        ret[_V[s_label]] = -1;
        for (int t : t_found) {
            ret[_V[t]] = it.second;
        }

        return ret;
    }

    int id25(int s_label, int t_label, int d_limit=numeric_limits<int>::max()) {
        unordered_map<int, int> spaths = id9(s_label, {t_label}, d_limit);
        return spaths.count(t_label) > 0 ? spaths[t_label] : numeric_limits<int>::max();
    }

    bool id26() {
        unordered_map<int, unordered_set<int>> adj;
        if (isflow) {
            adj = _adj;
        } else {
            for (int u = 0; u < maxV; u++) {
                for (int v : _adj[u]) {
                    adj[u].insert(v);
                    adj[v].insert(u);
                }
            }
        }

        unordered_map<int, bool> colors;
        function<bool(int)> id24 = [&](int s) {
            if (colors.count(s) > 0) {
                return true;
            }
            colors[s] = true;
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (colors.count(v) == 0) {
                        colors[v] = !colors[u];
                        q.push(v);
                    } else if (colors[v] == colors[u]) {
                        return false;
                    }
                }
            }
            return true;
        };

        for (int u = 0; u < maxV; u++) {
            if (!id24(u)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> roads(m);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].first >> roads[i].second;
    }
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }

    Graph G(n, true, true);
    unordered_map<int, unordered_set<int>> adj;
    vector<int> vertices;
    for (int i = 1; i <= n; i++) {
        G.add_vertex(i);
        vertices.push_back(i);
    }
    for (const auto& road : roads) {
        G.add_edge(road.second, road.first);
        adj[road.first].insert(road.second);
    }

    unordered_map<int, int> spaths = G.id9(p.back(), vertices, G.id0);

    int id22 = 0;
    int id27 = 0;
    for (int i = 0; i < k - 1; i++) {
        int u = p[i];
        int u_d = spaths[u];
        int v = p[i + 1];
        int v_d = spaths[v];

        if (v_d != u_d - 1) {
            id22++;
            id27++;
            continue;
        }

        bool found = false;
        for (int w : adj[u]) {
            if (w != v && spaths[w] == v_d) {
                id27++;
                found = true;
                break;
            }
        }
        if (!found) {
            id22++;
            id27++;
        }
    }

    cout << id22 << " " << id27 << endl;

    return 0;
}
