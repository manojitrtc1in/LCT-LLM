













using ll = long long;

class Solution {
public:
    const std::string YES = "YES";
    const std::string NO = "NO";

    void run() {
        bool multiple_test = false;

        int t;
        if (multiple_test)
            std::cin >> t;
        else
            t = 1;

        for (; t >= 1; t--) {
            getInput();

            auto ans = solve();

            if (ans.length() == 0) {
                printOutput(false);
            }
            else {
                printOutput(true);
                printOutput(ans);
            }
        }
    }

    int n, q;
    std::vector<std::pair<int, int>> uv;
    std::vector<int> x, y;
    std::vector<std::string> s;
    void getInput() {
        std::cin >> n >> q;
        uv = getPairs(n-1, -1);
        x.reserve(q);
        y.reserve(q);
        s.reserve(q);
        for (int i = 0; i < q; i++) {
            int xi, yi;
            std::string si;
            std::cin >> xi >> yi >> si;
            x.push_back(xi - 1);
            y.push_back(yi - 1);
            s.push_back(si);
        }
    }

    std::string solve() {
        

        


        

        
        

        

        

        


        

        

        

        
        

        

        

        

        

        
        

        

        

        

        

        


        constexpr int root = 0;
        std::vector<int> parent, depth;
        constructParent(n, uv, root, parent, depth);

        std::vector<int> numPath(n);
        std::string ans;
        ans.resize(n);
        std::vector<std::unordered_map<char, std::vector<int>>> id5(n);

        for (int i = 0; i < q; i++) {
            std::vector<int> path = computePath(x[i], y[i], parent, depth);
            int k = path.size();
            for (int j=0; j<k; j++){
                int v = path[j];
                numPath[v]++;
                if (s[i][j] == s[i][k - 1 - j]) {
                    char ch = s[i][j];
                    ans[v] = ch;
                    id5[v][ch].push_back(getPathLiteralIndex(i));
                    id5[v][ch].push_back(getReversePathLiteralIndex(i));
                }
                else {
                    char ch = s[i][j];
                    id5[v][ch].push_back(getPathLiteralIndex(i));
                    ch = s[i][k - 1 - j];
                    id5[v][ch].push_back(getReversePathLiteralIndex(i));
                }
            }
        }

        const int SIZE = q * 2 + n * 2 + 2;
        std::vector<std::vector<int>> id3(SIZE);
        const int FALSE_LITERAL = SIZE - 1;
        const int TRUE_LITERAL = FALSE_LITERAL ^ 1;
        

        

        

        

        id3[FALSE_LITERAL].push_back(TRUE_LITERAL);

        std::vector<std::pair<char, char>> candidateChar(n);
        

        for (int v = 0; v < n; v++) {
            if (ans[v]) {
                char ch = ans[v];
                auto idxV = getVertexLiteralIndex(v);
                

                candidateChar[v].first = ch;
                id3[idxV.second].push_back(idxV.first);
                for (auto& entry : id5[v]) {
                    if (entry.first == ch) {
                        

                        

                        

                        

                        

                        

                        

                        

                        

                    }
                    else {
                        for (int l : entry.second) {
                            

                            

                            makeClause(id3, l^1, FALSE_LITERAL);
                        }
                    }
                }
                candidateChar[v].first = ch;
            }
            else {
                auto idxV = getVertexLiteralIndex(v);
                if (id5[v].empty())
                    candidateChar[v].first = 'a';
                for (auto& entry : id5[v]) {
                    if (entry.second.size() == numPath[v]) {
                        int idx;
                        if (!candidateChar[v].first) {
                            idx = idxV.first;
                            candidateChar[v].first = entry.first;
                        }
                        else {
                            idx = idxV.second;
                            candidateChar[v].second = entry.first;
                        }
                        for (int l : entry.second) {
                            

                            id3[l].push_back(idx);
                            id3[idx].push_back(l);
                        }
                    }
                    else {
                        for (int l : entry.second) {
                            

                            

                            makeClause(id3, l ^ 1, FALSE_LITERAL);
                        }
                    }
                }
            }
        }

        std::vector<std::vector<int>> scc;
        tarjan(SIZE, id3, scc);

        std::vector<int> id6(SIZE);
        for (int i = 0; i < scc.size(); i++)
            for (int v : scc[i])
                id6[v] = i;

        for (int i = 0; i < q; i++)
            if (id6[getPathLiteralIndex(i)]
                == id6[getReversePathLiteralIndex(i)])
                return "";

        for (int i = 0; i < n; i++)
            if (id6[getVertexLiteralIndex(i).first]
                == id6[getVertexLiteralIndex(i).second])
                return "";

        std::vector<int> variableTruth(SIZE, -1);
        for (auto& id0: scc){
            for(int v: id0){
                if (variableTruth[v] != -1)
                    break;
                variableTruth[v] = true;
                variableTruth[v ^ 1] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (variableTruth[getVertexLiteralIndex(i).first]) {
                ans[i] = candidateChar[i].first;
            }
            else {
                ans[i] = candidateChar[i].second;
            }
        }

        return ans;
    }

    

    void tarjan(int n, std::vector<std::vector<int>>& neighbors,
        std::vector<std::vector<int>>& id4) {
        
        int time = 1;
        std::vector<int> tIn(n);
        

        std::vector<int> low(n);
        std::vector<int> onStack(n);
        std::vector<int> stack;

        std::function<void(int)> dfs = [&](int curr) {
            tIn[curr] = time;
            low[curr] = time++;
            onStack[curr] = true;
            stack.push_back(curr);
            for (int next : neighbors[curr]) {
                if (!tIn[next]) { 

                    

                    dfs(next);
                    low[curr] = std::min(low[curr], low[next]);
                }
                else if(onStack[next]) {
                    

                    

                    low[curr] = std::min(low[curr], tIn[next]);
                }
                

                

            }

            

            

            

            

            

            if (tIn[curr] == low[curr]) {
                std::vector<int> scc;
                while (!stack.empty()) {
                    int v = stack.back();
                    stack.pop_back();
                    onStack[v] = false;
                    scc.push_back(v);
                    if (v == curr)
                        break;
                }
                id4.push_back(scc);
            }
        };

        for (int v = 0; v < n; v++) {
            if (!tIn[v])
                dfs(v);
        }
    }

    void makeClause(std::vector<std::vector<int>>& id3, int a, int b) {
        

        

        

        id3[a ^ 1].push_back(b);
        id3[b ^ 1].push_back(a);
    }

    int getPathLiteralIndex(int i) {
        return i * 2;
    }
    int getReversePathLiteralIndex(int i) {
        return i * 2 + 1;
    }
    std::pair<int, int> getVertexLiteralIndex(int v) {
        return { q * 2 + v * 2, q * 2 + v * 2 + 1};
    }
    int getChar(int idx, std::vector<std::pair<char, char>>& candidateChar) {
        int v = (idx - q * 2) / 2;
        if (idx % 2 == 0)
            return candidateChar[v].first;
        else
            return candidateChar[v].second;
    }


    std::vector<int> computePath(int u, int v, std::vector<int>& parent, std::vector<int>& depth) {
        std::vector<int> pathU;
        std::vector<int> pathV;
        while (depth[u] > depth[v]) {
            pathU.push_back(u);
            u = parent[u];
        }
        while (depth[v] > depth[u]) {
            pathV.push_back(v);
            v = parent[v];
        }
        while (u != v) {
            pathU.push_back(u);
            u = parent[u];
            pathV.push_back(v);
            v = parent[v];
        }
        pathU.push_back(u);
        pathU.insert(pathU.end(), pathV.rbegin(), pathV.rend());
        return pathU;
    }

    void constructParent(int n, std::vector<std::pair<int, int>>& e, int root,
        std::vector<int>& parents, std::vector<int>& depths) {

        auto neighbors = constructNeighbors(n, e);
        parents.resize(n);
        depths.resize(n);
        std::function<void(int, int, int)> dfs = [&](int curr, int parent, int depth) {
            parents[curr] = parent;
            depths[curr] = depth;
            for (int next : neighbors[curr]) {
                if (next == parent)
                    continue;
                dfs(next, curr, depth+1);
            }
        };
        dfs(root, -1, 0);
    }

    std::vector<std::vector<int>> constructNeighbors(int n, std::vector<std::pair<int, int>>& e) {
        std::vector<std::vector<int>> neighbors(n);
        for (auto& p : e) {
            neighbors[p.first].push_back(p.second);
            neighbors[p.second].push_back(p.first);
        }
        return neighbors;
    }

    struct weightedEdge {
        int first;
        int second;
        int weight;
    };

    std::vector<std::pair<int, int>> getPairs(const int m, const int offset = 0) {
        std::vector<std::pair<int, int>> edges;
        edges.reserve(m);
        for (int i = 0; i < m; i++) {
            int a, b;
            std::cin >> a >> b;
            edges.push_back({ a + offset, b + offset });
        }
        return edges;
    }

    std::vector<weightedEdge> getWeigtedEdges(const int m, const int offset = 0) {
        std::vector<weightedEdge> edges;
        edges.reserve(m);
        for (int i = 0; i < m; i++) {
            int a, b, w;
            std::cin >> a >> b >> w;
            weightedEdge e{ a + offset, b + offset, w };
            edges.push_back(e);
        }
        return edges;
    }

    std::vector<std::string> getStringArray(const int n) {
        std::vector<std::string> ret;
        ret.reserve(n);

        std::string s;
        for (int i = 0; i < n; i++) {
            std::cin >> s;
            ret.push_back(s);
        }

        return ret;
    }

    std::vector<ll> getLLArray(const int n, const ll offset = 0) {
        std::vector<ll> ret;
        ret.reserve(n);

        ll val;
        for (int i = 0; i < n; i++) {
            std::cin >> val;
            ret.push_back(val + offset);
        }
        return ret;
    }

    std::vector<int> getIntArray(const int n, const int offset = 0) {
        std::vector<int> ret;
        ret.reserve(n);

        int val;
        for (int i = 0; i < n; i++) {
            std::cin >> val;
            ret.push_back(val + offset);
        }

        return ret;
    }

    void printOutput(const std::vector<int>& arr, const int offset = 0) {
        for (int val : arr)
            std::cout << val + offset << ' ';
        std::cout << '\n';
    }

    void printOutput(const std::vector<ll>& arr, const ll offset = 0) {
        for (ll val : arr)
            std::cout << val + offset << ' ';
        std::cout << '\n';
    }

    void printOutput(const std::pair<int, int>& p, const int offset = 0) {
        std::cout << p.first + offset << ' ' << p.second + offset << '\n';
    }

    template<typename T, typename U>
    void printOutput(const std::pair<T, U>& p) {
        std::cout << p.first << ' ' << p.second << '\n';
    }

    template<typename T>
    void printOutput(const std::vector<T>& arr) {
        for (T i : arr)
            std::cout << i << ' ';
        std::cout << '\n';
    }

    void printOutputBool(const std::vector<int>& arr) {
        for (int val : arr) {
            printOutput((bool)val);
        }
    }

    void printOutput(bool ans) {
        if (ans)
            std::cout << YES << '\n';
        else
            std::cout << NO << '\n';
    }

    template<typename T>
    void printOutput(T ans) {
        std::cout << ans << '\n';
    }

    struct custom_hash_32 {
        static uint32_t splitmix32(uint32_t x) {
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            return x ^ (x >> 16);
        }

        size_t operator()(uint32_t x) const {
            static const uint64_t id2 = std::chrono::steady_clock::now().time_since_epoch().count();
            static const uint32_t id1 = (uint32_t)(id2 ^ (id2 >> 32));
            return splitmix32(x + id1);
        }
    };

    struct custom_hash_64 {
        static uint64_t splitmix64(uint64_t x) {
            

            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(uint64_t x) const {
            static const uint64_t id2 = std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + id2);
        }
    };
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);


    FILE* streami, * streamo;
    freopen_s(&streami, "input.txt", "r", stdin);
    freopen_s(&streamo, "output.txt", "w", stdout);



    Solution s;
    s.run();


    fclose(stdin);
    fclose(stdout);


}