#ifndef BICONNECTED_COMPONENTS
#define BICONNECTED_COMPONENTS






#include <vector>
using namespace std;














struct BiconnectedComponents {
    const int NOT_VISITED = -1;
    int V;
    const vector<int>* aa;  

    int current_time;
    vector<int> ot; 

    

    

    vector<int> low;  
    vector<bool> articulation; 

    

    

    

    vector<pair<int,int>> bridges;
    
    BiconnectedComponents(int V, const vector<int> aa[]) :
            V(V),
            aa(aa),
            current_time(0),
            ot(V, NOT_VISITED),
            low(V),
            articulation(V, false) {
        for (int v = 0; v < V; v++) if (ot[v] == NOT_VISITED) dfs(v, -1);
    }

    

    

    

    

    

    void dfs(int v, int father) {
        ot[v] = current_time++;
        low[v] = ot[v];
        int sons = 0;
        for (int a : aa[v]) {
            if (a == father) continue;
            if (ot[a] == NOT_VISITED) {
                dfs(a, v);
                sons++;
                if (low[a] == ot[a]) bridges.push_back({v, a});
                if (father != -1 and low[a] >= ot[v]) articulation[v] = true;
            }
            low[v] = min(low[v], low[a]);
        }
        if (father == -1 and sons >= 2) articulation[v] = true;
    }
};

#endif  



#ifndef MATROIDS
#define MATROIDS








#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>
using namespace std;






































struct Matroid {
    virtual vector<bool> get_antispan(const vector<bool>& S) = 0;
    bool is_independent(vector<bool> S) {
        int sz = S.size();
        for (int i = 0; i < sz; i++) {
            if (!S[i]) continue;
            S[i] = 0;
            if (!get_antispan(S)[i]) return false;
            S[i] = 1;
        }
        return true;
    }
};

struct MatroidIntersection {
    int N;
    Matroid& A;
    Matroid& B;
    vector<bool> S;
    vector<vector<int>> aa;
    vector<int> dist;
    vector<int> bfs_father;
  
    MatroidIntersection(int N, Matroid& A, Matroid& B):
        N(N), A(A), B(B), S(N, false), aa(N), dist(N), bfs_father(N) {
        while(augment()); 

    }

    bool augment() { 

        vector<bool> antispanA = A.get_antispan(S);
        vector<bool> antispanB = B.get_antispan(S);

        for (int x = 0; x < N; x++) if (antispanA[x] and antispanB[x]) {
            S[x] = 1;
            return true;
        }

        
        for (int x = 0; x < N; x++) aa[x].clear();
        for (int x = 0; x < N; x++) {
            if (!S[x]) continue;
            S[x] = 0;
            vector<bool> new_antispanA = A.get_antispan(S);
            vector<bool> new_antispanB = B.get_antispan(S);
            S[x] = 1;
            for (int y = 0; y < N; y++) {
                if (S[y]) continue;
                if (new_antispanA[y]) aa[x].push_back(y);
                if (new_antispanB[y]) aa[y].push_back(x);
            }
        }

        bfs(antispanA);
        int min_dist = 1<<30;
        for (int x = 0; x < N; x++) {
            if (antispanB[x] and bfs_father[x] != -1) {
                min_dist = min(min_dist, dist[x]);
            }
        }
        if (min_dist >= 1<<30) return false; 


        for (int x = 0; x < N; x++) {
            if (antispanB[x] and dist[x] == min_dist) {
                int it = x;
                while (it != -1) {
                    S[it] = S[it]^1;
                    it = bfs_father[it];
                }
                break;
            }
        }
        return true;
    }

    void bfs(const vector<bool>& sources) {
        for (int x = 0; x < N; x++) dist[x] = 1<<30, bfs_father[x] = -1;
        queue<int> q;
        for (int x = 0; x < N; x++) {
            if (sources[x]) {
                dist[x] = 0;
                q.push(x);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y: aa[x]) {
                if (dist[y] > dist[x] + 1) {
                    bfs_father[y] = x;
                    dist[y] = dist[x] + 1;
                    q.push(y);
                }
            }
        }
    }
};











struct PartitionMatroid:Matroid {
    int N;
    int labels_num;
    vector<int> label;
    vector<int> multiplicity;
    PartitionMatroid(int N, int labels_num, const vector<int>& label, const vector<int>& multiplicity):
        N(N), labels_num(labels_num), label(label), multiplicity(multiplicity) {}

    

    vector<bool> get_antispan(const vector<bool>& S) {
        assert(N == (int)S.size());
        vector<int> label_cnt(labels_num, 0);
        for (int i = 0; i < N; i++) if (S[i]) label_cnt[label[i]]++;
        vector<bool> antispan(N, false);
        for (int i = 0; i < N; i++) {
            antispan[i] = !S[i] and label_cnt[label[i]] < multiplicity[label[i]];
        }
        return antispan;
    }
};





struct GraphicMatroid:Matroid {
    int V;
    int E;
    vector<pair<int,int>> edges;
    vector<int> anc;
    GraphicMatroid(int V, const vector<pair<int,int>>& edges):
        V(V), E(edges.size()), edges(edges), anc(V) {}

    int ancestor(int v) {
        if (anc[anc[v]] != anc[v]) anc[v] = ancestor(anc[v]);
        return anc[v];
    }

    void join(int u, int v) {
        u = ancestor(u);
        v = ancestor(v);
        anc[u] = v;
    }

    

    vector<bool> get_antispan(const vector<bool>& S) {
        assert(E == (int)S.size());
        for (int v = 0; v < V; v++) anc[v] = v;
        for (int e = 0; e < E; e++) {
            if (S[e]) join(edges[e].first, edges[e].second);
        }
        vector<bool> antispan(E, false);
        for (int e = 0; e < E; e++) {
            if (ancestor(edges[e].first) != ancestor(edges[e].second)) {
                antispan[e] = true;
            }
        }
        return antispan;
    }
};











struct CoGraphicMatroid:Matroid {
    int V;
    int E;
    vector<pair<int,int>> edges;
    vector<int> edge2id;
    vector<int>* aa;
    CoGraphicMatroid(int V, const vector<pair<int,int>>& edges):
        V(V), E(edges.size()), edges(edges), edge2id(V*V) {
        aa = new vector<int>[V];
        for (int e = 0; e < E; e++) {
            int a = edges[e].first, b = edges[e].second;
            if (a > b) swap(a, b);
            edge2id[a + V*b] = e;
        }
    }

    

    

    vector<bool> get_antispan(const vector<bool>& S) {
        assert(E == (int)S.size());
        for (int v = 0; v < V; v++) aa[v].clear();
        for (int e = 0; e < E; e++) {
            if (!S[e]) {
                int a = edges[e].first;
                int b = edges[e].second;
                aa[a].push_back(b);
                aa[b].push_back(a);
            }
        }
        vector<pair<int,int>> bridges = BiconnectedComponents(V, aa).bridges;
        for (auto& pp: bridges) {
            if (pp.first > pp.second) swap(pp.first, pp.second);
        }

        vector<bool> antispan(E, true);
        for (int e = 0; e < E; e++) if (S[e]) antispan[e] = false;
        for (auto pp: bridges) {
            int a = pp.first, b = pp.second;
            if (a > b) swap(a, b);
            antispan[edge2id[a + b*V]] = false;
        }
        return antispan;
    }
};


typedef unsigned long long ULL;











struct F2LinearMatroid {
    int D;
    int N;
    vector<ULL> vec;
    F2LinearMatroid(int D, const vector<ULL>& vec): 
        D(D), N(vec.size()), vec(vec) {}

    

    vector<bool> get_antispan(const vector<bool>& S) {
        vector<ULL> mat;
        for (int i = 0; i < N; i++) if (S[i]) mat.push_back(vec[i]);
        int R = mat.size();
        int it = 0;
        vector<int> bits;
        for (int l = 0; l < D; l++) {
            for (int i = it; i < R; i++) {
                if (mat[i] & (1ull<<l)) {
                    for (int j = i+1; j < R; j++) {
                        if (mat[j] & (1ull<<l)) mat[j] ^= mat[i];
                    }
                    if (it < i) swap(mat[it], mat[i]);
                    bits.push_back(l);
                    it++;
                    break;
                }
            }
        }
        vector<bool> antispan(N);
        for (int i = 0; i < N; i++) {
            if (S[i]) continue;
            ULL x = vec[i];
            for (int j = 0; j < (int)bits.size(); j++) {
                if (x & (1ull<<bits[j])) x ^= mat[j];
            }
            if (x) antispan[i] = true;
        }
        return antispan;
    }
};

#endif 


const int MAXN = 30;
const int MAXE = 2000;
char mat[MAXN][MAXN];
int cell_id[MAXN][MAXN];
char ans[MAXN*2][MAXN*2];
int black_adj[MAXE];
int from[MAXE];
int toto[MAXE];
vector<int> edges[MAXE];
int E;
int N, M;
int edge_id[MAXE][MAXE];
int xx[MAXE], yy[MAXE];
int free_cells;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};



bool visited[MAXN][MAXN];
void easy_visit(int i, int j) {
    visited[i][j] = true;
    for (int t = 0; t < 4; t++) {
        int i1 = i + di[t], j1 = j + dj[t];
        if (i1 < 0 or i1 >= N or j1 < 0 or j1 >= M or mat[i1][j1] == 'X') continue;
        if (!visited[i1][j1]) easy_visit(i1, j1);
    }
}


#include <bits/stdc++.h>
#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    

    

#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> mat[i][j];
            }
        }
        for (int i = 0; i < N*M; i++) edges[i].clear();
        E = 0;
        free_cells = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cell_id[i][j] = -1;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (mat[i][j] == 'X') continue;
            if (cell_id[i][j] == -1) {
                cell_id[i][j] = free_cells;
                xx[free_cells] = i, yy[free_cells] = j;
                free_cells++;
            }
            int id0 = cell_id[i][j];
            for (int t = 0; t < 2; t++) {
                int i1 = i + di[t], j1 = j + dj[t];
                if (i1 < 0 or i1 >= N or j1 < 0 or j1 >= M or mat[i1][j1] == 'X') continue;
                if (cell_id[i1][j1] == -1) {
                    cell_id[i1][j1] = free_cells;
                    xx[free_cells] = i1, yy[free_cells] = j1;
                    free_cells++;
                }
                int id1 = cell_id[i1][j1];
                from[E] = id0;
                toto[E] = id1;
                edges[id0].push_back(E);
                edges[id1].push_back(E);
                if ((i+j)%2 == 0) black_adj[E] = id0;
                else black_adj[E] = id1;
                edge_id[id0][id1] = E;
                edge_id[id1][id0] = E;
                E++;
            }
        }
        bool black_leaf = false;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if ((i == 0 and j == 0) or (i+j)%2 or mat[i][j] == 'X') continue;
            if (edges[cell_id[i][j]].size() < 2) black_leaf = true;
        }
        if (black_leaf) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) visited[i][j] = false;
        easy_visit(0, 0);
        bool disconnected = false;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (mat[i][j] != 'X' and !visited[i][j]) disconnected = true;
        }
        if (disconnected) {
            cout << "NO\n";
            continue;
        }


        vector<int> label(E, 0);
        for (int i = 0; i < E; i++) label[i] = black_adj[i];
        vector<int> mult(free_cells, 2);
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (cell_id[i][j] == -1 or (i+j)%2) continue;
            int id = cell_id[i][j];
            mult[id] = ((int)edges[id].size()) - 2;
        }
        mult[0] = 10;
        PartitionMatroid PM(E, free_cells, label, mult);

        vector<pair<int,int>> edges_copy(E);
        for (int i = 0; i < E; i++) edges_copy[i] = {from[i], toto[i]};
        CoGraphicMatroid CM(free_cells, edges_copy);

        vector<bool> S = MatroidIntersection(E, PM, CM).S;

        int q = 0;
        for (int i = 0; i < E; i++) q += S[i];
        if (E-q != free_cells-1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < 2*N-1; i++) for (int j = 0; j < 2*M-1; j++) ans[i][j] = ' ';
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            ans[2*i][2*j] = mat[i][j];
            ans[2*i+1][2*j] = '0';
            ans[2*i][2*j+1] = '0';
        }
        for (int i = 0; i < E; i++) {
            if (!S[i]) continue;
            int a = from[i], b = toto[i];
            int x = xx[a];
            int y = yy[a];
            if (x == xx[b]) {
                ans[2*x][2*y+1] = ' ';
            } else {
                ans[2*x+1][2*y] = ' ';
            }
        }
        for (int i = 0; i < 2*N-1; i++) {
            for (int j = 0; j < 2*M-1; j++) cout << ans[i][j];
            cout << "\n";
        }
    }
}

