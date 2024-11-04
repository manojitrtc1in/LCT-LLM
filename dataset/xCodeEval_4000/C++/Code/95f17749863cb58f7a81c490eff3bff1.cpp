#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <chrono>
#include <string>
#include <functional>
#include <bitset>
#include <numeric>
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

            printOutput(ans);
        }
    }

    int n, size;
    std::string s;
    void getInput() {
        std::cin >> n >> s;
        size = 1 << n;

        

        

        

        

        

    }

    std::string solve() {
        

        


        

        




        

        

        


        


        

        

        

        


        

        


        


        tree.resize(1 << n + 1);
        precompute();

        int best = 0;
        for (int j = 1; j < size; j++) {
            int left = 0;
            int right = size;
            while (left < right) {
                int mid = (left + right) / 2;
                if (getHash(left, mid, best) == getHash(left, mid, j))
                    left = mid + 1;
                else
                    right = mid;
            }
            

            if (left < size && s[j ^ left] < s[best ^ left])
                best = j;
        }

        std::string ans;
        ans.resize(size);
        for (int i = 0; i < size; i++)
            ans[i] = s[i ^ best];
        return ans;
    }

    

    

    std::pair<ll, int> getHash(int left, int right, int j) {
        return getHash(left, right, j, n, 1, 0, size-1);
    }

    std::pair<ll, int> getHash(int left, int right, int j, int pos, int treeIndex, int treeLeft, int treeRight) {
        if (left == treeLeft && right == treeRight)
            return tree[treeIndex][j & ((1<<pos) -1)];
        int leftTreeIndex, rightTreeIndex;
        if (j & (1 << pos-1)) {
            leftTreeIndex = treeIndex * 2 + 1;
            rightTreeIndex = treeIndex * 2;
        }
        else {
            leftTreeIndex = treeIndex * 2;
            rightTreeIndex = treeIndex * 2 + 1;
        }

        int treeMid = (treeLeft + treeRight) / 2;
        if (right <= treeMid) {
            return getHash(left, right, j, pos - 1, leftTreeIndex, treeLeft, treeMid);
        }
        else if (left >= treeMid + 1) {
            return getHash(left, right, j, pos - 1, rightTreeIndex, treeMid + 1, treeRight);
        }
        else {
            auto hash1 = getHash(left, treeMid, j, pos - 1, leftTreeIndex, treeLeft, treeMid);
            auto hash2 = getHash(treeMid + 1, right, j, pos - 1, rightTreeIndex, treeMid + 1, treeRight);
            return merge(hash1, hash2);
        }
    }

    std::pair<ll, int> merge(std::pair<ll, int>& hash1, std::pair<ll, int>& hash2) {
        ll hash = hash2.first;
        hash += hash1.first * pw[hash2.second];

        hash %= MOD;
        int len = hash1.second + hash2.second;
        return { hash, len };
    }

    ll pow(ll a, int k) {
        ll ans = 1;
        ll curr = a;
        while (k > 0) {
            if ((k & 1) == 1) {
                ans *= curr;
                ans %= MOD;
            }
            curr *= curr;
            curr %= MOD;
            k >>= 1;
        }
        return ans;
    }

    const ll MOD = 1'000'000'007;
    const ll PRIME = 31;
    std::vector<ll> pw;
    std::vector<std::vector<std::pair<ll, int>>> tree;
    void precompute() {
        pw.resize(size);
        pw[0] = 1;
        for (int i = 1; i < size; i++)
            pw[i] = pw[i - 1] * PRIME % MOD;
        precompute(0, size - 1, n, 1);
    }
    void precompute(int left, int right, int pos, int treeIndex) {
        if (left == right) {
            tree[treeIndex].push_back({ s[left] - 'a', 1 });
            return;
        }
        int leftTreeIndex = treeIndex * 2;
        int rightTreeIndex = treeIndex * 2 + 1;
        int mid = (left + right) / 2;
        precompute(left, mid, pos-1, leftTreeIndex);
        precompute(mid + 1, right, pos - 1, rightTreeIndex);

        tree[treeIndex].reserve(1<<pos);
        for (int i = 0; i < 1<<pos-1; i++)
            tree[treeIndex].push_back(merge(tree[leftTreeIndex][i], tree[rightTreeIndex][i]));
        for (int i = 0; i < 1<<pos-1; i++)
            tree[treeIndex].push_back(merge(tree[rightTreeIndex][i], tree[leftTreeIndex][i]));
    }

    //std::vector<int> numChildren;
    //std::vector<std::string> t;

    //// f(n) = 2f(n-1) + 2g(n-1) + O(2^n)
    //// g(n) = 4g(n-1) + O(2^n) = O(4^n) --- problem is here
    //void construct(int left, int right, int pos, int treeIndex) {
    //    if (left == right) {
    //        numChildren[treeIndex] = 1;
    //        t[treeIndex] = s.substr(left, 1);
    //        return;
    //    }
    //    int mid = (left + right) / 2;
    //    int leftTreeIndex = treeIndex * 2;
    //    int rightTreeIndex = treeIndex * 2 + 1;

    //    construct(left, mid, pos - 1, leftTreeIndex);
    //    construct(mid + 1, right, pos - 1, rightTreeIndex);

    //    if (t[leftTreeIndex] < t[rightTreeIndex]) {
    //        // pos-th bit must be 0
    //        // among the indices that minimize l
    //        // need to find the indices that minimize r
    //        numChildren[rightTreeIndex] = 0;
    //        prune(mid + 1, right, pos - 1, leftTreeIndex);
    //    }
    //    else if (t[rightTreeIndex] < t[leftTreeIndex]) {
    //        // pos-th bit must be 1
    //        numChildren[leftTreeIndex] = 0;
    //        prune(left, mid, pos - 1, rightTreeIndex);
    //    }
    //    else {
    //        // l == r, pos-th bit can be either 0 or 1
    //        // needs to compare between two cases and choose the better one
    //        // or merge
    //        if (numChildren[leftTreeIndex] < 1 << pos || numChildren[rightTreeIndex] < 1 << pos) {
    //            auto tl = prune(left, mid, pos - 1, rightTreeIndex);
    //            auto tr = prune(mid + 1, right, pos - 1, leftTreeIndex);
    //            if (tl < tr)
    //                numChildren[leftTreeIndex] = 0;
    //            else if (tr < tl)
    //                numChildren[rightTreeIndex] = 0;
    //        }
    //    }

    //    numChildren[treeIndex] = numChildren[leftTreeIndex] + numChildren[rightTreeIndex];
    //    // construct t[treeIndex]

    //    int j = 0;
    //    int index = treeIndex;
    //    while (pos >= 0) {
    //        int leftIndex = index * 2;
    //        if (numChildren[leftIndex]) {
    //            index = leftIndex;
    //        }
    //        else {
    //            index = leftIndex + 1;
    //            j += 1 << pos;
    //        }
    //        pos--;
    //    }
    //    for (int i = left; i <= right; i++)
    //        t[treeIndex] += s[i^j];
    //}

    //std::string prune(int left, int right, int pos, int treeIndex) {
    //    if (numChildren[treeIndex] == 0)
    //        return "";
    //    if (left == right)
    //        return s.substr(left, 1);

    //    int mid = (left + right) / 2;
    //    int leftTreeIndex = treeIndex * 2;
    //    int rightTreeIndex = treeIndex * 2 + 1;
    //    std::string tl, tr;
    //    if (numChildren[leftTreeIndex] > 0) {
    //        auto t1 = prune(left, mid, pos - 1, leftTreeIndex);
    //        auto t2 = prune(mid + 1, right, pos - 1, leftTreeIndex);
    //        tl = t1 + t2;
    //    }
    //    if (numChildren[rightTreeIndex] > 0) {
    //        auto t1 = prune(mid + 1, right, pos - 1, rightTreeIndex);
    //        auto t2 = prune(left, mid, pos - 1, rightTreeIndex);
    //        tr = t1 + t2;
    //    }
    //    if (tl.empty())
    //        return tr;
    //    if (tr.empty())
    //        return tl;
    //    if (tl < tr) {
    //        numChildren[rightTreeIndex] = 0;
    //        return tl;
    //    }
    //    if (tr < tl) {
    //        numChildren[leftTreeIndex] = 0;
    //        return tr;
    //    }
    //    return tl;
    //}

    //std::string rec(int left, int right, int pos, int& j) {
    //    if (left == right) {
    //        j = 0;
    //        return s.substr(left, 1);
    //    }

    //    int jl, jr;
    //    int mid = (left + right) / 2;
    //    auto l = rec(left, mid, pos - 1, jl);
    //    auto r = rec(mid + 1, right, pos - 1, jr);
    //    if (l <= r) {
    //        // pos-th bit must be 0
    //        // among the indices that minimize l
    //        // need to find the indices that minimize r
    //    }
    //    else if (r > l) {
    //        // pos-th bit must be 1
    //    }
    //    else {
    //        // l == r, pos-th bit can be either 0 or 1
    //        // needs to compare between two cases and choose the better one
    //        // or merge
    //    }

    //    //if (l <= r) {
    //    //    j = jl;
    //    //}
    //    //else {
    //    //    j = jr | (1 << pos-1);
    //    //}

    //    std::string ret;
    //    for (int i = left; i <= right; i++)
    //        ret += s[i^j];
    //    return ret;
    //}

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
            static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
            static const uint32_t FIXED_RANDOM32 = (uint32_t)(FIXED_RANDOM ^ (FIXED_RANDOM >> 32));
            return splitmix32(x + FIXED_RANDOM32);
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
            static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

#ifndef ONLINE_JUDGE
    FILE* streami, * streamo;
    freopen_s(&streami, "input.txt", "r", stdin);
    freopen_s(&streamo, "output.txt", "w", stdout);
#endif 


    Solution s;
    s.run();

#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif 

}