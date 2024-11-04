













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

            printOutput(ans);
        }
    }

    void test() {
        n = 100'000;
        a = std::vector<int>(n);
        for (int i = 0; i < n; i++)
            a[i] = rand() + 1;
        //for (int i = 0; i < n; i += 1000)
        //    a[i] = i+1;

        //int cnt = 0;
        //for (int i = 0; i < n; i++)
        //    if (a[i] == i + 1){
        //        printOutput(i);
        //        cnt++;
        //    }

        //for (int i = 0; i < n; i += 10)
        //    a[i] = i + 1;

        //for (int i = 1; i < n; i += 5)
        //    a[i] = 100'000 - i;

        

        

        

        

        

        


        

        

        

        

        

        


        


        printOutput(solve(true));
    }

    int n;
    std::vector<int> a;
    void getInput() {
        std::cin >> n;
        a = getIntArray(n);
    }

    struct Sequence {
        

        ll val;
        int diff;

        bool operator==(const Sequence& o) const {
            

            return val == o.val && diff == o.diff;
        }
    };

    struct hashSequence {
        static uint64_t splitmix64(uint64_t x) {
            

            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(const Sequence& s) const {
            ll x = s.val + (1LL << 34); 

            

            

            x <<= 20;

            x += s.diff + MAX; 

            static const uint64_t id2 = std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + id2);
        }
    };

    static constexpr int MAX = 100'000;
    int solve(bool isTest=false) {
        if(!isTest)
            getInput();

        //std::vector<int> maxProgression;
        //for (int i = 0; i < n; i++) {
        //    for (int j = i + 1; j < n; j++) {
        //        std::vector<int> progression{ a[i], a[j]};
        //        int d = j - i;
        //        int diff = a[j] - a[i];
        //        if (diff % d == 0) {
        //            diff /= d;
        //            int curr = a[j];
        //            for (int k = j + 1; k < n; k ++) {
        //                curr += diff;
        //                if (a[k] == curr)
        //                    progression.push_back(a[k]);
        //            }
        //            if (progression.size() > maxProgression.size())
        //                maxProgression = progression;
        //        }
        //    }
        //}
        //printOutput(maxProgression);

        // 1 2 3 x x x x x x 10 11 12
        // remove x's is sufficient
        


        

        


        

        


        


        

        

        

        

        

        
        

        


        

        

        constexpr int sqm = 1000;

        int maxLen = 0;

        

        

        

        

        

        


        

        std::unordered_map<int, int> id3;

        for (int diff = -MAX / sqm; diff <= MAX / sqm; diff++) {
            

            

            

            

            

            

            for (int i = 0; i < n; i++) {
                int len = ++id3[a[i] - diff * i];
                maxLen = std::max(maxLen, len);
            }
            

            

            id3.clear();
        }
        
        

        
        

        

        

        

        

        

        

        

        

        


        


        std::unordered_map<int, int> id1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n && j < i + sqm; j++) {
                

                    

                int diff = a[j] - a[i];
                int d = j - i;
                if (diff % d == 0) {
                    diff /= d;
                    if (diff > MAX / sqm || diff < -MAX / sqm) {
                        id1[diff]++;
                        maxLen = std::max(maxLen, id1[diff]+1);
                    }
                }
            }
            id1.clear();
        }
        
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        return n - maxLen;


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

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
            static const uint64_t id2 = std::chrono::steady_clock::now().time_since_epoch().count();
            static const uint32_t id0 = (uint32_t)(id2 ^ (id2 >> 32));
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