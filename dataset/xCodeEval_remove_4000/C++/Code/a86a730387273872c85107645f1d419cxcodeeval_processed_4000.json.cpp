













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
            auto ans = solve();

            printOutput(ans, 1);
        }
    }
    
    void test() {
        n = 10;
        p.resize(n);
        bool ok = false;
        while (!ok) {
            ok = false;
            for (int i = 0; i < n; i++) {
                p[i] = rand() % n;
            }
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (p[i] == p[j])
                        ok = true;
                }
            }
        }

        std::vector<int> b(n);
        std::iota(b.begin(), b.end(), 0);
        for (int i = n - 1; i >= 1; i--) {
            int j = rand()%(i+1);
            std::swap(b[i], b[j]);
        }

        int time = rand()%1000;
        printOutput(p);
        printOutput(b); 

        printOutput(time);
        
        int available = n;
        while (time > 0) {
            std::vector<int> a(n, -1);
            for (int i = 0; i < n; i++) {
                if (a[p[i]] == -1)
                    a[p[i]] = b[i];
                else
                    a[p[i]] = std::min(a[p[i]], b[i]);
            }
            for (int i = 0; i < n; i++) {
                if (a[i] == -1)
                    a[i] = available++;
            }
            b = a;
            time--;
        }

        a = b;

        auto ans = solve(true);

        printOutput(ans, 1);
    }
    int n;
    std::vector<int> p, a;
    void getInput() {
        std::cin >> n;
        p = getIntArray(n, -1);
        a = getIntArray(n, -1);
    }

    std::vector<int> solve(bool isTest = false) {
        if(!isTest)
            getInput();

        std::vector<int> b(n);

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        
        

        


        

        


        

        std::vector<int> outNeighbor = p;
        std::vector<std::vector<int>> inNeighbors(n);
        for (int i = 0; i < n; i++)
            inNeighbors[outNeighbor[i]].push_back(i);

        std::vector<int> visited(n);
        

        

        

        


        int id2 = 0;
        for (int i = 0; i < n; i++)
            if (inNeighbors[i].size() == 0)
                id2++;

        int max = 0;
        for (int i = 0; i < n; i++)
            max = std::max(max, a[i]);

        int time = (max - (n - 1)) / id2;

        std::vector<int> id1(n);

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            int fast = outNeighbor[i];
            int slow = i;
            while (fast != slow) {
                slow = outNeighbor[slow];
                fast = outNeighbor[outNeighbor[fast]];
            }
            std::vector<int> cycle;
            cycle.push_back(slow);

            fast = outNeighbor[slow];
            while (fast != slow) {
                cycle.push_back(fast);
                fast = outNeighbor[fast];
            }

            int len = cycle.size();
            for (int j = 0; j < len; j++) {
                std::function<void(int, int, std::vector<int>&)> dfs
                    = [&](int curr, int parent, std::vector<int>& path) {
                    visited[curr] = true;
                    int t = path.size();
                    path.push_back(curr);
                    if (t > time) {
                        id1[curr] = path[t - time];
                    }
                    else {
                        id1[curr] = cycle[(j + time - t) % len];
                    }
                    for (int next : inNeighbors[curr]) {
                        if (next == parent)
                            continue;
                        dfs(next, curr, path);
                    }
                    path.pop_back();
                };

                int exclude = cycle[(j+len-1) % len];

                std::vector<int> path;
                dfs(cycle[j], exclude, path);
            }
        }


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        




        

        

        

        


        

        

        

        



        

        

        

        

        

        

        

        













































































































































        

        std::set<int> unassigned;

        

        std::vector<int> inverseA(n, -1);
        for (int i = 0; i < n; i++)
            if(a[i] < n)
                inverseA[a[i]] = i;
        for (int i = 0; i < n; i++)
            if (inverseA[i] == -1)
                unassigned.insert(i);

        std::vector<int> id4(n);

        for (int i = 0; i < n; i++) {
            

            


            

            

            

            

            


            

            

            


            int representative = id1[i];


            if (id4[a[representative]]) {
                auto it = unassigned.upper_bound(a[representative]);
                b[i] = *it;
                id4[*it] = true;
                unassigned.erase(it);
            }
            else {
                id4[a[representative]] = true;
                b[i] = a[representative];
            }
        }

        return b;
    }

    struct weightedEdge {
        int first;
        int second;
        int weight;
    };

    std::vector<std::pair<int, int>> getPairs(const int m, int offset = 0) {
        std::vector<std::pair<int, int>> edges;
        edges.reserve(m);
        for (int i = 0; i < m; i++) {
            int a, b;
            std::cin >> a >> b;
            edges.push_back({ a + offset, b + offset });
        }
        return edges;
    }

    std::vector<weightedEdge> getWeigtedEdges(const int m, int offset = 0) {
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

    std::vector<ll> getLLArray(const int n) {
        return getLLArray(n, 0);
    }

    std::vector<ll> getLLArray(const int n, const ll offset) {
        std::vector<ll> ret;
        ret.reserve(n);

        ll val;
        for (int i = 0; i < n; i++) {
            std::cin >> val;
            ret.push_back(val + offset);
        }
        return ret;
    }

    std::vector<int> getIntArray(const int n) {
        return getIntArray(n, 0);
    }

    std::vector<int> getIntArray(const int n, const int offset) {
        std::vector<int> ret;
        ret.reserve(n);

        int val;
        for (int i = 0; i < n; i++) {
            std::cin >> val;
            ret.push_back(val + offset);
        }

        return ret;
    }

    template<typename T, int N>
    void printOutput(std::array<T, N> arr) {
        for (T i : arr)
            std::cout << i << ' ';
        std::cout << '\n';
    }

    void printOutput(std::vector<int> arr, int offset = 0) {
        for (int val: arr)
            std::cout << val + offset << ' ';
        std::cout << '\n';
    }

    template<typename T>
    void printOutput(std::vector<T> arr) {
        for (T i : arr)
            std::cout << i << ' ';
        std::cout << '\n';
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
            static const uint64_t id3 = std::chrono::steady_clock::now().time_since_epoch().count();
            static const uint32_t id0 = (uint32_t)(id3 ^ (id3 >> 32));
            return splitmix32(x + id0);
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
            static const uint64_t id3 = std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + id3);
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