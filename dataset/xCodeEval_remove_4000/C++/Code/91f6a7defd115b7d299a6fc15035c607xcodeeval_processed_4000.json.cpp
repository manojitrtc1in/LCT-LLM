

using namespace std;

const int MAXN = 200005;
const int BLOCK_SIZE = 240;

struct Input {
    int n, m;
    vector<int> x, y, l, r;

    void scan() {
        scanf("%d%d", &n, &m);
        x.resize(n + 5), y.resize(n + 5);
        l.resize(m + 5), r.resize(m + 5);
        for (int i = 1; i <= n; i++) 
            scanf("%d%d", &x[i], &y[i]);
        for (int i = 1; i <= m; i++) 
            scanf("%d%d", &l[i], &r[i]);
    }

    void generate() {
        srand(time(NULL));
        n = 50000; m = 50000;
        for (int i = 1; i <= n; i++) {
            x[i] = rand() % (int)(1e9+1);
            y[i] = rand() % (int)(1e9+1);
            if (rand() & 1)
                x[i] = -x[i];
            if (rand() & 1)
                y[i] = -y[i];
        }
        for (int i = 1; i <= min(m, 5000); i++) {
            l[i] = r[i] = 0;
            while (r[i] - l[i] + 1 < 4) {
                l[i] = rand() % n + 1;
                r[i] = l[i] + rand() % (n - l[i] + 1);
            }
        }
        vector<pair<int, int> > long_ranges;
        for (int len = n; len >= 1; len--) {
            for (int i = 1; i + len - 1 <= n; i++) {
                long_ranges.push_back(make_pair(i, i + len - 1));
                if ((int)long_ranges.size() == m) 
                    break;
            }
            if ((int)long_ranges.size() == m)
                break;
        }
        for (int i = 5001; i <= m; i++) {
            l[i] = long_ranges[i - 5001].first;
            r[i] = long_ranges[i - 5001].second;
        }
    }

    void show() {
        printf("%d %d\n", n, m);
        for (int i = 1; i <= n; i++) 
            printf("%d %d\n", x[i], y[i]);
        for (int i = 1; i <= m; i++) 
            printf("%d %d\n", l[i], r[i]);
    }
};

int xs[MAXN];
int ys[MAXN];

struct Solution {
    int n, m;
    vector<int> x, y, l, r;
    vector<long long> answers;

    long long slow(int query) {
        int n = r[query]-l[query]+1;
        if (n == 1) return 0;
        vector<int> perm(n, 0);
        for (int i = 0; i < n; i++) 
            perm[i] = i;
        long long res = 0;
        do {
            long long tmp = 0;
            for (int i = 0; i < n - 1; i++) 
                tmp += abs(x[l[query] + perm[i]] - x[l[query] + perm[i+1]]) + abs(y[l[query] + perm[i]] - y[l[query] + perm[i+1]]);
            tmp += abs(x[l[query] + perm[0]] - x[l[query] + perm[n-1]]) + abs(y[l[query] + perm[0]] - y[l[query] + perm[n-1]]);
            res = max(res, tmp);
        } while (next_permutation(perm.begin(), perm.end()));
        return res;
    }

    long long medium_speed(int query) {
        int n = r[query]-l[query]+1;
        if (n <= 4) return slow(query);
        int top = 0;
        for (int i = l[query]; i <= r[query]; i++) {
            top++;
            xs[top] = x[i];
            ys[top] = y[i];
        }
        sort(xs+1, xs+top+1);
        sort(ys+1, ys+top+1);
        int mid = (n+1)/2;
        int id2 = xs[mid];
        int id1 = ys[mid];
        int delta_x = xs[mid+1] - xs[mid];
        int delta_y = ys[mid+1] - ys[mid];
        if (n & 1) {
            delta_x = min(delta_x, xs[mid] - xs[mid-1]);
            delta_y = min(delta_y, ys[mid] - ys[mid-1]);
        }
        long long res = 0;
        bool flag = false, flag1 = false, flag2 = false;
        for (int i = l[query]; i <= r[query]; i++) {
            res += abs(x[i] - id2) + abs(y[i] - id1);
            if (x[i] > id2 && y[i] <= id1) 
                flag1 = true;
            if (x[i] > id2 && y[i] > id1)
                flag2 = true;
            if (x[i] == id2 && y[i] == id1)
                flag = true;
        }
        if ((flag || n % 2 == 0) && flag1 && flag2) 
            res = max(res - delta_x, res - delta_y);
        return res+res;
    }

    

    pair<int, int> xvalues[MAXN];
    pair<int, int> yvalues[MAXN];

    struct TreeNode {
        int l, r;
        int left_son, right_son;
        int sum;

        TreeNode() {}
    } tree[20 * MAXN];

    int xroot[MAXN];
    int yroot[MAXN];

    int block_left[MAXN];
    int block_right[MAXN];
    int belongs[MAXN];

    int node_allocator;

    int create(int l, int r) {
        int node = node_allocator++;
        tree[node].l = l, tree[node].r = r;
        tree[node].left_son = tree[node].right_son = tree[node].sum = 0;

        if (l == r) 
            return node;

        int mid = (l+r)/2;
        tree[node].left_son = create(l, mid);
        tree[node].right_son = create(mid+1, r);
        return node;
    }

    int query(int node, int l, int r) {
        if (l <= tree[node].l && tree[node].r <= r) 
            return tree[node].sum;
        if (r < tree[node].l || l > tree[node].r)
            return 0;
        return query(tree[node].left_son, l, r) + query(tree[node].right_son, l, r);
    }

    int set1(int node, int i) {
        if (i < tree[node].l || i > tree[node].r)
            return node;
        int new_node = node_allocator++;
        tree[new_node] = tree[node];
        if (tree[node].l == tree[node].r) {
            tree[new_node].sum = 1;
            return new_node;
        }

        tree[new_node].left_son = set1(tree[node].left_son, i);
        tree[new_node].right_son = set1(tree[node].right_son, i);
        tree[new_node].sum = tree[tree[new_node].left_son].sum + tree[tree[new_node].right_son].sum;

        return new_node;
    }

    int cnt_blocks;

    vector<pair<int, int> > block_by_x[MAXN];
    vector<pair<int, int> > block_by_y[MAXN];
    vector<long long> block_by_x_prefix_sum[MAXN];
    vector<long long> block_by_y_prefix_sum[MAXN];
    vector<int> suff_min[MAXN];
    vector<int> suff_max[MAXN];

    map<pair<int, int>, int> mapping;
    int mapping_allocator;
    set<int> occur[MAXN];

    void prepare() {
        node_allocator = cnt_blocks = mapping_allocator = 0;
        for (int i = 1; i <= n; i++) {
            xvalues[i] = make_pair(x[i],i);
            yvalues[i] = make_pair(y[i],i);
        }
        sort(xvalues+1, xvalues+n+1);
        sort(yvalues+1, yvalues+n+1);

        xroot[0] = create(1, n);
        for (int i = 1; i <= n; i++) 
            xroot[i] = set1(xroot[i-1], xvalues[i].second);

        yroot[0] = create(1, n);
        for (int i = 1; i <= n; i++)
            yroot[i] = set1(yroot[i-1], yvalues[i].second);


        for (int i = 1; i <= n; i += BLOCK_SIZE) {
            cnt_blocks++;
            block_left[cnt_blocks] = i;
            block_right[cnt_blocks] = min(n, i + BLOCK_SIZE - 1);

            for (int j = block_left[cnt_blocks]; j <= block_right[cnt_blocks]; j++) {
                belongs[j] = cnt_blocks;
                block_by_x[cnt_blocks].push_back(make_pair(x[j], y[j]));
                block_by_y[cnt_blocks].push_back(make_pair(y[j], x[j]));
            }

            sort(block_by_x[cnt_blocks].begin(), block_by_x[cnt_blocks].end());
            sort(block_by_y[cnt_blocks].begin(), block_by_y[cnt_blocks].end());

            block_by_x_prefix_sum[cnt_blocks].assign(BLOCK_SIZE+5, 0);
            block_by_y_prefix_sum[cnt_blocks].assign(BLOCK_SIZE+5, 0);

            suff_min[cnt_blocks].assign(BLOCK_SIZE+5, 0);
            suff_max[cnt_blocks].assign(BLOCK_SIZE+5, 0);

            suff_min[cnt_blocks][(int)block_by_x[cnt_blocks].size()-1] = block_by_x[cnt_blocks].back().second;
            suff_max[cnt_blocks][(int)block_by_x[cnt_blocks].size()-1] = block_by_x[cnt_blocks].back().second;

            for (int i = (int)block_by_x[cnt_blocks].size() - 2; i >= 0; i--) {
                suff_min[cnt_blocks][i] = min(suff_min[cnt_blocks][i+1], block_by_x[cnt_blocks][i].second);
                suff_max[cnt_blocks][i] = max(suff_max[cnt_blocks][i+1], block_by_x[cnt_blocks][i].second);
            }

            for (int j = 1; j <= block_by_x[cnt_blocks].size(); j++) {
                block_by_x_prefix_sum[cnt_blocks][j] = block_by_x_prefix_sum[cnt_blocks][j-1] + block_by_x[cnt_blocks][j-1].first;
                block_by_y_prefix_sum[cnt_blocks][j] = block_by_y_prefix_sum[cnt_blocks][j-1] + block_by_y[cnt_blocks][j-1].first;
            }

        }

        for (int i = 1; i <= n; i++) {
            pair<int, int> pt = make_pair(x[i], y[i]);
            if (!mapping.count(pt))
                mapping[pt] = mapping_allocator++;

            occur[mapping[pt]].insert(i);
        }
    }

    int getKthX(int l, int r, int k) {
        int ptr = n;
        for (int shift = 65536; shift; shift >>= 1) {
            if (ptr - shift <= 0) 
                continue;
            if (query(xroot[ptr - shift], l, r) >= k)
                ptr -= shift;
        }
        return xvalues[ptr].first;
    }

    int getKthY(int l, int r, int k) {
        int ptr = n;
        for (int shift = 65536; shift; shift >>= 1) {
            if (ptr - shift <= 0)
                continue;
            if (query(yroot[ptr - shift], l, r) >= k)
                ptr -= shift;
        }
        return yvalues[ptr].first;
    }

    long long calc_block_x(int i, int x) {
        int id0 = -1, K = block_by_x[i].size();
        for (int shift = 128; shift; shift >>= 1) {
            if (id0 + shift >= K)
                continue;
            if (block_by_x[i][id0 + shift].first <= x)
                id0 += shift;
        }
        if (id0 == -1) 
            return block_by_x_prefix_sum[i][K] - (long long)x * K;
        if (id0 == K-1)
            return (long long)x * K - block_by_x_prefix_sum[i][K];

        return (long long)x * (id0+1) - block_by_x_prefix_sum[i][id0+1] + block_by_x_prefix_sum[i][K] - block_by_x_prefix_sum[i][id0+1] - (long long)(K-1-id0) * x;
    }

    long long calc_block_y(int i, int y) {
        int id0 = -1, K = block_by_y[i].size();
        for (int shift = 128; shift; shift >>= 1) {
            if (id0 + shift >= K)
                continue;
            if (block_by_y[i][id0 + shift].first <= y)
                id0 += shift;
        }
        if (id0 == -1)
            return block_by_y_prefix_sum[i][K] - (long long)y * K;
        if (id0 == K-1)
            return (long long)y * K - block_by_y_prefix_sum[i][K];

        return (long long)y * (id0+1) - block_by_y_prefix_sum[i][id0+1] + block_by_y_prefix_sum[i][K] - block_by_y_prefix_sum[i][id0+1] - (long long)(K-1-id0) * y;
    }

    long long abs_sum(int l, int r, int id2, int id1) {
        long long res = 0;
        bool any_full = false;
        for (int i = 1; i <= cnt_blocks; i++) {
            if (l <= block_left[i] && block_right[i] <= r) {
                any_full = true;
              
                res += calc_block_x(i, id2);
                res += calc_block_y(i, id1);
            }
        }

        if (!any_full) {
            for (int i = l; i <= r; i++) {
                res += abs(id2 - x[i]);
                res += abs(id1 - y[i]);
            }
            return res;
        }

        for (int i = l; i <= r; i++) {
            if (l <= block_left[belongs[i]] && block_right[belongs[i]] <= r) 
                break;
            res += abs(id2 - x[i]);
            res += abs(id1 - y[i]);
        }

        for (int i = r; i >= l; i--) {
            if (l <= block_left[belongs[i]] && block_right[belongs[i]] <= r)
                break;
            res += abs(id2 - x[i]);
            res += abs(id1 - y[i]);
        }

        return res;
    }

    bool check1(int l, int r, int id2, int id1) {
        int workLeft = 1e9, workRight = -workLeft;
        for (int i = 1; i <= cnt_blocks; i++) {
            if (l <= block_left[i] && block_right[i] <= r) {
                workLeft = min(workLeft, block_left[i]);
                workRight = max(workRight, block_right[i]);
                int greater_pointer = block_by_x[i].size();
                for (int shift = 128; shift; shift >>= 1) {
                    if (greater_pointer - shift < 0)
                        continue;
                    if (block_by_x[i][greater_pointer - shift].first > id2)
                        greater_pointer -= shift;
                }
                if (greater_pointer < block_by_x[i].size())
                    if (suff_min[i][greater_pointer] <= id1)
                        return true;
            }
        }
        for (int i = l; i <= r; i++) {
            if (i >= workLeft) break;
            if (x[i] > id2 && y[i] <= id1)
                return true;
        }
        for (int i = r; i >= l; i--) {
            if (i <= workRight) break;
            if (x[i] > id2 && y[i] <= id1)
                return true;
        }
        return false;
    }

    bool check2(int l, int r, int id2, int id1) {
        int workLeft = 1e9, workRight = -workLeft;
        for (int i = 1; i <= cnt_blocks; i++) {
            if (l <= block_left[i] && block_right[i] <= r) {
                workLeft = min(workLeft, block_left[i]);
                workRight = max(workRight, block_right[i]);
                int greater_pointer = block_by_x[i].size();
                for (int shift = 128; shift; shift >>= 1) {
                    if (greater_pointer - shift < 0)
                        continue;
                    if (block_by_x[i][greater_pointer - shift].first > id2)
                        greater_pointer -= shift;
                }
                if (greater_pointer < block_by_x[i].size())
                    if (suff_max[i][greater_pointer] > id1)
                        return true;
            }
        }
        for (int i = l; i <= r; i++) {
            if (i >= workLeft) break;
            if (x[i] > id2 && y[i] > id1)
                return true;
        }
        for (int i = r; i >= l; i--) {
            if (i <= workRight) break;
            if (x[i] > id2 && y[i] > id1)
                return true;
        }
        return false;
    }

    long long fast(int query) {
        int n = r[query]-l[query]+1;
        int mid = (n+1)/2;

        int id2 = getKthX(l[query], r[query], mid);
        int id1 = getKthY(l[query], r[query], mid);

        


        int delta_x = getKthX(l[query], r[query], mid+1) - id2;
        int delta_y = getKthY(l[query], r[query], mid+1) - id1;
        
        


        if (n & 1) {
            delta_x = min(delta_x, id2 - getKthX(l[query], r[query], mid-1));
            delta_y = min(delta_y, id1 - getKthY(l[query], r[query], mid-1));
        }

        long long res = abs_sum(l[query], r[query], id2, id1);
        
        


        bool flag = false, flag1 = false, flag2 = false;

        pair<int, int> pt = make_pair(id2, id1);
        if (mapping.count(pt)) {
            int id = mapping[pt];

            set<int>::iterator it = occur[id].lower_bound(l[query]);
            if (it != occur[id].end() && *it <= r[query]) 
                flag = true;
        }

        flag1 = check1(l[query], r[query], id2, id1);
        flag2 = check2(l[query], r[query], id2, id1);
        
        


        if ((flag || n % 2 == 0) && flag1 && flag2)
            res = max(res - delta_x, res - delta_y);

        return 2 * res;
    }

    

    void run(Input in) {
        n = in.n, m = in.m;
        x = in.x, y = in.y, l = in.l, r = in.r;
        prepare();
        for (int i = 1; i <= m; i++) {
            

            long long fast_ans = fast(i);
            

            if (i >= 99990) {
                long long medium_ans = medium_speed(i);
                
                assert(medium_ans == fast_ans);
            }
            answers.push_back(fast_ans);
        }
    }

    void output() {
        for (auto x: answers) {
            printf("%lld\n", x);
            exit(0);
        }
    }
};

int main() {
    

    



    Input in;
    scanf("%d", &in.n);
    in.m = 1;
    in.x.resize(in.n + 5);
    in.y.resize(in.n + 5);
    in.l.resize(100005);
    in.r.resize(100005);
    in.m = 100000;
    if(in.n > 50000) in.m = 5;
    for (int i = 1; i <= in.n; i++)
        scanf("%d %d", &in.x[i], &in.y[i]);
    for (int i = 1; i <= 99998; i++) 
        in.l[i] = 1, in.r[i] = in.n;
    in.l[99999] = 1, in.r[99999] = in.n - 1;
    in.l[100000] = 2, in.r[100000] = in.n;
    Solution sol;
    sol.run(in);
    sol.output();

    return 0;
}