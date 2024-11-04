



#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


#define NDEBUG
NDEBUG


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <queue>
#include <random>


using namespace std;

template<class T>
using vec = std::vector<T>;

template<class T>
using vec2d = std::vector<std::vector<T>>;


#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORA(i, a, n) for (int i = (a); i < (n); ++i)


#define all(c) c.begin(), c.end()


typedef int64_t i64;






bool __hack = std::ios::sync_with_stdio(false);


auto __hack1 = cin.tie(nullptr);























struct Input {

    Input(istream &in) : in(&in) {}

    template<class T>
    T next() const {
        T x;
        *in >> x;
        return x;
    }

    int ni() const {
        return next<int>();
    }

    
    istream *in;
};

Input in(cin);


class Output {

private:
ostream *out;

template<typename T>
void printSingle(const T &value) {
    *out << value;
}


public:
Output(ostream &out) : out(&out) {}


inline void print() {}

template<typename T, typename...Ts>
inline void print(const T &f, const Ts&... args) {
    printSingle(f);
    if (sizeof...(args) != 0) {
        *out << ' ';
        print(args...);
    }
}

template<typename...Ts>
inline void println(const Ts&... args) {
    print(args...);
    (*out) << '\n';
}

template<typename...Ts>
inline void operator() (const Ts&... args) {
    println(args...);
}


};

Output out(cout);


namespace template_util {
    

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        
    };

    
    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


#define dbg(...) ;





typedef vec2d<int> Tree;


void buildDfsOrder(
    const Tree& tree,
    vec<int>& height,
    vec<int>& tIn,
    vec<int>& tOut,
    vec<int>& dfsOrder,
    int root = 0
) {
    int timer = 0;
    int n = static_cast<int>(tree.size());
    height = vector<int>(n, -1);
    dfsOrder.clear();
    dfsOrder.reserve(2 * n - 1);
    tIn = vector<int>(n, -1);
    tOut = vector<int>(n, -1);
    std::function<void(int, int)> dfs = [&](int v, int h) {
        height[v] = h;
        dfsOrder.push_back(v);
        tIn[v] = timer++;
        for (int to : tree[v]) {
            if (height[to] != -1) {
                continue;
            }
            dfs(to, h + 1);
            dfsOrder.push_back(v);
        }
        tOut[v] = timer - 1;
    };
    dfs(root, 0);
}




struct LCA {

    LCA() {}

    void init(int root = 0) {
        countDfsOrder = (int) dfsOrder.size();
        posInDfsOrder = vec<int>(n, -1);
        FOR(i, countDfsOrder) {
            if (posInDfsOrder[dfsOrder[i]] == -1) {
                posInDfsOrder[dfsOrder[i]] = i;
            }
        }
        log2 = vec<int>(2 * n);
        logMaxList = log(countDfsOrder);
        buildLCA();
    }

    
    LCA(const Tree& tree, int root = 0) {
        vec<int> tIn, tOut, dfsOrder, height;
        buildDfsOrder(tree, height, tIn, tOut, dfsOrder, root);
        this->n = static_cast<int>(tree.size());
        this->dfsOrder = dfsOrder;
        this->tIn = tIn;
        this->tOut = tOut;
        this->height = height;
        init(root);
    }

    
    int get(int v, int u) const {
        int l = posInDfsOrder[v], r = posInDfsOrder[u];
        if (l > r) {
            int t = l;
            l = r;
            r = t;
        }
        int left_block = l / block, right_block = r / block;
        if (left_block == right_block) {
            return dfsOrder[lcaInBlocks(left_block, l % block, r % block)];
        }
        int ans1 = lcaInBlocks(left_block, l % block, block - 1);
        int ans2 = lcaInBlocks(right_block, 0, r % block);
        int ans = minHeight(ans1, ans2);
        if (left_block < right_block - 1) {
            int pw2 = log2[right_block - left_block - 1];
            int ans3 = blockTable[left_block + 1][pw2];
            int ans4 = blockTable[right_block - (1 << pw2)][pw2];
            ans = minHeight(ans, minHeight(ans3, ans4));
        }
        return dfsOrder[ans];
    }

private:
    vec<int> dfsOrder;
    vec<int> height;
    vec<int> tIn;
    vec<int> tOut;

    vec<int> posInDfsOrder;
    int countDfsOrder;
    int block;
    vector<vector<int>> blockTable;
    int logMaxList;
    vector<int> blockHash;
    vector<vector<vector<int>>> blockRmq;
    vector<int> log2;
    int n;

    int log(int n) {
        int res = 1;
        while ((1 << res) < n) ++res;
        return res;
    }

    

    int minHeight(int i, int j) const {
        return height[dfsOrder[i]] < height[dfsOrder[j]] ? i : j;
    }

    

    void buildLCA() {
        block = (logMaxList + 1) / 2;
        int blocks = countDfsOrder / block + ((countDfsOrder % block > 0) ? 1 : 0);
        int maxBlocks = ((2 * n) / block) + 2;
        blockHash = vector<int>(maxBlocks + 1, 0);
        blockTable = vector<vector<int>>(maxBlocks + 1, vector<int>(logMaxList + 1, -1));
        blockRmq = vector<vector<vector<int>>>((int) (sqrt(2 * n) + 2),
                                               vector<vector<int>>(block + 2,
                                                                   vector<int>(block + 2,
                                                                               -1)));

        

        for (int i = 0, blockId = 0, j = 0; i < countDfsOrder; ++i, ++j) {
            if (j == block) {
                j = 0;
                ++blockId;
            }
            if (blockTable[blockId][0] == -1 ||
                minHeight(i, blockTable[blockId][0]) == i) {
                blockTable[blockId][0] = i;
            }
        }

        for (int j = 1; j <= logMaxList; ++j) {
            for (int i = 0; i < blocks; ++i) {
                int ni = i + (1 << (j - 1));
                if (ni >= blocks) {
                    blockTable[i][j] = blockTable[i][j - 1];
                } else {
                    blockTable[i][j] = minHeight(blockTable[i][j - 1],
                                                 blockTable[ni][j - 1]);
                }
            }
        }

        

        for (int i = 0, blockId = 0, j = 0; i < countDfsOrder || j < block; ++i, ++j) {
            if (j == block) {
                j = 0;
                ++blockId;
            }
            if (j > 0 && (i >= countDfsOrder || minHeight(i - 1, i) == i - 1)) {
                blockHash[blockId] += (1 << (j - 1));
            }
        }

        

        for (int i = 0; i < blocks; ++i) {
            int id = blockHash[i];
            if (blockRmq[id][0][0] != -1) continue;
            for (int l = 0; l < block; ++l) {
                blockRmq[id][l][l] = l;
                for (int r = l + 1; r < block; ++r) {
                    blockRmq[id][l][r] = blockRmq[id][l][r - 1];
                    if (i * block + r < countDfsOrder) {
                        blockRmq[id][l][r] =
                            minHeight(i * block + blockRmq[id][l][r], i * block + r) -
                            i * block;
                    }
                }
            }
        }

        

        for (int i = 0, j = 0; i < countDfsOrder; ++i) {
            if (1 << (j + 1) <= i) ++j;
            log2[i] = j;
        }
    }

    int lcaInBlocks(int block_id, int left, int right) const {
        return blockRmq[blockHash[block_id]][left][right] + block_id * block;
    }
};



struct HeavyLight {

    
    HeavyLight(const vec2d<int>& g_, int root = 0) : g(g_), root(root), withLCA(false) {
        n = static_cast<int>(g.size());
        parents = vec<int>(n, -1);
        subtreeSize = vec<int>(n, 1);
        dfsPrepare(root, -1);
        firstInChain = vec<int>(n);
        tIn = vec<int>(n);
        height = vec<int>(n, 0);
        timer = 0;
        dfs(root, root);
        order = vec<int>(n);
        FOR(i, n) {
            order[tIn[i]] = i;
        }
    }

    void addLCA() {
        lca = LCA(g, root);
        withLCA = true;
    }

    
    bool isSameChain(int v, int u) const {
        return firstInChain[v] == firstInChain[u];
    }

    int getPos(int v) const {
        return tIn[v];
    }

    template<typename EdgeVal>
    void updatePathToParent(int par, int v, const function<void(int, int, EdgeVal)>& update, const EdgeVal& by) {
        if (v == par) {
            return;
        }
        while (!isSameChain(par, v)) {
            update(getPos(firstInChain[v]), getPos(v), by);
            v = parents[firstInChain[v]];
        }
        if (v == par) {
            return;
        }
        update(getPos(par) + 1, getPos(v), by);
    }

    template<typename EdgeVal>
    void updatePath(int v, int u, const function<void(int, int, EdgeVal)>& update, const EdgeVal& by) {
        if (v == u) return;
        auto l = lca.get(v, u);
        if (l == v) return updatePathToParent(l, u, update, by);
        if (l == u) return updatePathToParent(l, v, update, by);
        updatePathToParent(l, u, update, by);
        updatePathToParent(l, v, update, by);
    }

    
    void dfsPrepare(int v, int p) {
        int mxId = -1;
        parents[v] = p;
        FOR(i, g[v].size()) {
            if (g[v][i] == p) {
                swap(g[v][i], g[v].back());
                g[v].pop_back();
                if (i == g[v].size()) break;
            }
            dfsPrepare(g[v][i], v);
            if (mxId == -1 || subtreeSize[g[v][mxId]] < subtreeSize[g[v][i]]) {
                mxId = i;
            }
            subtreeSize[v] += subtreeSize[g[v][i]];
        }
        if (mxId != 0 && mxId != -1) {
            swap(g[v][mxId], g[v][0]);
        }
    }

    void dfs(int v, int first) {
        tIn[v] = timer++;
        firstInChain[v] = first;
        if (g[v].empty()) return;
        height[g[v][0]] = height[v] + 1;
        dfs(g[v][0], first);
        FORA(i, 1, g[v].size()) {
            height[g[v][i]] = height[v] + 1;
            dfs(g[v][i], g[v][i]);
        }
    }

    int n;
    vec2d<int> g;
    int root, timer;
    vec<int> parents;
    vec<int> height;
    vec<int> subtreeSize;
    vec<int> firstInChain;
    vec<int> tIn;
    LCA lca;
    bool withLCA;
    vec<int> order;
};


struct SegmentTreeSum {
    vector<int64_t> tsum;
    vector<int64_t> tadd;
    int n;

    
    SegmentTreeSum(int n_) : n(n_) {
        tsum = vector<int64_t>(4 * n);
        tadd = vector<int64_t>(4 * n);
    }

    void push(int v, int le, int ri) {
        int middle = (ri + le) / 2;
        if (tadd[v] != 0) {
            if (2 * v < tsum.size()) {
                tsum[2 * v] += tadd[v] * 1LL * (middle - le);
                tadd[2 * v] += tadd[v];
            }
            if (2 * v + 1 < tsum.size()) {
                tsum[2 * v + 1] += tadd[v] * 1LL * (ri - middle);
                tadd[2 * v + 1] += tadd[v];
            }
            tadd[v] = 0;
        }
    }

    void update(int v) {
        tsum[v] = tsum[2 * v] + tsum[2 * v + 1];
    }

    void internalAdd(int left, int right, int64_t value, int rangeLeft, int rangeRight, int v = 1) {
        push(v, rangeLeft, rangeRight);
        if (left >= rangeRight || rangeLeft >= right) {
            return;
        }
        if (rangeLeft >= left && rangeRight <= right) {
            tsum[v] += value * 1LL * (rangeRight - rangeLeft);
            tadd[v] += value;
            return;
        }
        int middle = (rangeLeft + rangeRight) / 2;
        internalAdd(left, right, value, rangeLeft, middle, 2 * v);
        internalAdd(left, right, value, middle, rangeRight, 2 * v + 1);
        update(v);
    }

    
    i64 getOne(int pos) {
        int v = 1, le = 0, ri = n;
        while (le + 1 != ri) {
            push(v, le, ri);
            int middle = (le + ri) / 2;
            if (pos < middle) {
                v = v * 2;
                ri = middle;
            } else {
                v = v * 2 + 1;
                le = middle;
            }
        }
        return tsum[v];
    }

    void add(int from, int to, int64_t val) {
        internalAdd(from, to + 1, val, 0, n);
    }
};

void solve(istream& inStream, ostream& outStream) {
    in = Input(inStream);
    out = Output(outStream);
    auto n = in.ni();
    Tree g(n);
    FOR(i, n-1) {
        auto x = in.ni() - 1;
        auto y = in.ni() - 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    HeavyLight hld(g);
    hld.addLCA();
    vec2d<pair<int, int>> pathFromVertex(n);
    vec<i64> oneV(n);
    auto m = in.ni();
    FOR(i, m) {
        auto v = in.ni() - 1;
        auto u = in.ni() - 1;
        if (v == u) {
            oneV[v]++;
            continue;
        }
        auto l = hld.lca.get(v, u);
        pathFromVertex[l].push_back({v, u});
    }
    SegmentTreeSum stree(2 * n);
    auto update = [&] (int a, int b, int by) {
        stree.add(a, b, by);
    };

    i64 res = 0;

    function<void(int, int)> dfs = [&] (int v, int par) {
        i64 countUp = stree.getOne(hld.getPos(v));
        res += oneV[v] * pathFromVertex[v].size();
        res += oneV[v] * countUp;
        res += oneV[v] * (oneV[v] - 1) / 2;

        

        res += countUp * pathFromVertex[v].size();

        vec<int> children;
        for (auto to : g[v]) {
            if (to == par) continue;
            children.push_back(to);
        }

        vec<i64> oldChildrenArray(children.size());
        FOR(i, children.size()) {
            i64 countDown = stree.getOne(hld.getPos(children[i]));
            oldChildrenArray[i] = countDown;
        }
        vec<i64> newChildrenArray(children.size());
        for (auto p : pathFromVertex[v]) {
            if (p.first == v || p.second == v) {
                auto u = p.first + p.second - v;
                hld.updatePath<int>(v, u, update, 1);
            } else {
                hld.updatePath<int>(v, p.first, update, 1);
                hld.updatePath<int>(v, p.second, update, 1);
            }
        }
        FOR(i, children.size()) {
            i64 countDown = stree.getOne(hld.getPos(children[i]));
            newChildrenArray[i] = countDown;
            i64 delta = newChildrenArray[i] - oldChildrenArray[i];
            res -= delta * oldChildrenArray[i];
        }

        res += pathFromVertex[v].size() * 1LL * (pathFromVertex[v].size() - 1) / 2;
        FOR(i, children.size()) {
            i64 delta = newChildrenArray[i] - oldChildrenArray[i];
            res -= delta * (delta - 1) / 2;
        }

        vec<int> childrenIns(children.size());
        FOR(i, children.size()) {
            childrenIns[i] = hld.tIn[children[i]];
        }
        sort(all(childrenIns));

        map<pair<int, int>, int> counts;
        for (const auto& p : pathFromVertex[v]) {
            if (p.first != v && p.second != v) {
                auto pos1 = int(upper_bound(all(childrenIns), hld.tIn[p.first]) - children.begin()) - 1;
                auto pos2 = int(upper_bound(all(childrenIns), hld.tIn[p.second]) - children.begin()) - 1;
                if (pos1 > pos2) {
                    swap(pos1, pos2);
                }
                counts[{pos1, pos2}]++;
            }
        }
        for (const auto& it : counts) {
            res += (it.second * 1LL * (it.second - 1)) / 2;
        }

        dbg("after v", v, "res is", res);

        for (auto to : children) {
            dfs(to, v);
        }
    };


    dfs(0, -1);

    out(res);

}





int main() {








    solve(cin, cout);


    return 0;
}
