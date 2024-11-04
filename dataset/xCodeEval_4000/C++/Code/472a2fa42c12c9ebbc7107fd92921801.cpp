
















#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int INF = 999999;

int is_prime(int number) {
    for (int i = 2; i <= sqrt(number + 1); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}











class Dinic {
public:
    class Edge {
    public:
        int to;
        int cap, flow;
        Edge *back;
        Edge(int to, int cap, int flow, Edge *back) : to(to), cap(cap), flow(flow), back(back) {
            
        }
        
        bool remain() const {
            return flow < cap;
        }
        
        void add_flow(int f) {
            flow += f;
            back->flow -= f;
        }
    };
    
    vector<vector<Edge*> > g_;
    vector<int> memo_, level_;
    int src_, sink_;
    
    Dinic(int N, int src, int sink) : g_(N), memo_(N), level_(N), src_(src), sink_(sink) {
        
    }
    
    int dinic_augment(int v, int cap) {
        if(v == sink_) return cap;
        
        const int N = g_[v].size();
        for (int i = memo_[v]; i < N; ++i) {
            const auto &e = g_[v][i];
            if (level_[e->to] != level_[v]+1) {
                continue;
            }
            if (!e->remain()) {
                continue;
            }
            const int f = dinic_augment(e->to, min(cap, e->cap - e->flow));
            if (f > 0) {
                e->add_flow(f);
                memo_[v] = i+1;
                return f;
            }
        }
        return 0;
    }
    
    void add_edge(int from, int to, int cap) {
        Edge *e = new Edge(to, cap, 0, nullptr);
        Edge *r = new Edge(from, 0, 0, e);
        
        e->back = r;
        
        g_[from].push_back(e);
        g_[to].push_back(r);
    }
    
    int calc() {
        int flow = 0;
        while(true) {
            

            fill(begin(level_), end(level_), -1);
            queue<int> q;
            q.push(src_);
            level_[src_] = 0;
            while (!q.empty()) {
                const int v = q.front();
                q.pop();
                for (const auto &e : g_[v]) {
                    if (e->remain() && level_[e->to] == -1) {
                        level_[e->to] = level_[v] + 1;
                        q.push(e->to);
                    }
                }
            }
            
            

            bool updated = false;
            fill (begin(memo_), end(memo_), 0);
            while (true) {
                int add = dinic_augment(src_, INF);
                if(add == 0) {
                    break;
                }
                flow += add;
                updated = true;
            }
            if (!updated) {
                break;
            }
        }
        return flow;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> nodes;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nodes.push_back(tmp);
    }
    
    Dinic dinic(n+2, n, n+1);
    int flow = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (is_prime(nodes[i] + nodes[j])) {
                if (nodes[i] % 2 == 0) {
                    dinic.add_edge(i, j, 1);
                } else {
                    dinic.add_edge(j, i, 1);
                }
            }
        }
        if (nodes[i] % 2 == 0) {
            dinic.add_edge(n, i, 2);
            flow += 2;
        } else {
            dinic.add_edge(i, n+1, 2);
        }
    }
    if (flow != n or dinic.calc() != flow) {
        cout << "Impossible" << endl;
    } else {
        const auto &graph = dinic.g_;
        vector<bool> used(n, false);
        vector<vector<int>> components;
        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }
            int cur = i;
            used[i] = true;
            components.push_back(vector<int>());
            while (true) {
                components.back().push_back(cur+1);
                for (auto e : graph[cur]) {
                    if (e->flow != 0 and e->to < n and !used[e->to]) {
                        used[e->to] = true;
                        cur = e->to;
                        break;
                    }
                }
                if (cur+1 == components.back().back()) {
                    break;
                }
            }
        }
        cout << components.size() << endl;
        for(const auto &c : components) {
            cout << c.size() << ' ';
            for (int i = 0; i < c.size(); ++i) {
                std::cout << c[i];
                if (i < c.size() - 1) {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}














































































































































































































































































































































































































































































































































































































































































































































































































































































































































