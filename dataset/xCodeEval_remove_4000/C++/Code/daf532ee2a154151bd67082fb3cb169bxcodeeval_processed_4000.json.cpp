


using namespace std;
using ll = long long;
using ld = long double;











const int g = 800;

struct sqrt_dec {
private:
    struct small_block {
        vector<int> indexes;
    };

    struct subblock {
        vector<int> indexes;
        vector<ll> numbers;
        vector<int> psum_a_block;
        vector<ll> psum_a_block_as;

        ll total_added = 0;
        int id1;
        int start_pos;
        int lb_pos;
    };

    struct large_block {
        vector<unique_ptr<subblock>> subblocks;
    };

    int n, a_blocks;
    vector<optional<ll>> a;
    vector<int> p;

    vector<ll> a_block_sum;

    vector<int> small_block_of;
    vector<subblock*> subblock_of;
    vector<int> pos_in_subblock;

    vector<small_block> small_blocks;
    vector<large_block> large_blocks;

    ll get_val(int i) {
        if (a[i].has_value()) {
            return *a[i];
        }
        subblock* sb = subblock_of[i];
        return sb->numbers[pos_in_subblock[i]] + sb->total_added;
    }

    void calc_subblock_psums(subblock* sb) {
        vector<int> count(a_blocks);
        vector<ll> as(a_blocks);
        for (int i = 0; i < (int)sb->indexes.size(); i++) {
            count[sb->indexes[i] / g]++;
            as[sb->indexes[i] / g] += sb->numbers[i];
        }
        sb->psum_a_block.resize(a_blocks + 1);
        partial_sum(all(count), sb->psum_a_block.begin() + 1);
        sb->psum_a_block_as.resize(a_blocks + 1);
        partial_sum(all(as), sb->psum_a_block_as.begin() + 1);
    }

    void split_subblock(int lb_id, int sb_id, int left_size) {
        assert(0 < left_size);
        assert(left_size < (int)large_blocks[lb_id].subblocks[sb_id]->indexes.size());
        subblock* old_sb = large_blocks[lb_id].subblocks[sb_id].get();
        auto new_sb = make_unique<subblock>();
        new_sb->start_pos = old_sb->start_pos + left_size;
        new_sb->id1 = lb_id;
        new_sb->lb_pos = sb_id + 1;
        for (int i = sb_id + 1; i < (int)large_blocks[lb_id].subblocks.size(); i++) {
            large_blocks[lb_id].subblocks[i]->lb_pos++;
        }
        copy(old_sb->indexes.begin() + left_size, old_sb->indexes.end(), back_inserter(new_sb->indexes));
        old_sb->indexes.erase(old_sb->indexes.begin() + left_size, old_sb->indexes.end());
        copy(old_sb->numbers.begin() + left_size, old_sb->numbers.end(), back_inserter(new_sb->numbers));
        old_sb->numbers.erase(old_sb->numbers.begin() + left_size, old_sb->numbers.end());
        forn(i, new_sb->indexes.size()) {
            new_sb->numbers[i] += old_sb->total_added;
            subblock_of[new_sb->indexes[i]] = new_sb.get();
            pos_in_subblock[new_sb->indexes[i]] = i;
        }
        calc_subblock_psums(old_sb);
        calc_subblock_psums(new_sb.get());
        large_blocks[lb_id].subblocks.emplace(large_blocks[lb_id].subblocks.begin() + sb_id + 1, move(new_sb));
    }

    

    void merge_subblocks(int lb_id, int sb_id) {
        assert(sb_id + 1 < (int)large_blocks[lb_id].subblocks.size());
        subblock* left = large_blocks[lb_id].subblocks[sb_id].get();
        subblock* right = large_blocks[lb_id].subblocks[sb_id + 1].get();
        auto new_sb = make_unique<subblock>();
        new_sb->id1 = lb_id;
        new_sb->start_pos = left->start_pos;
        new_sb->lb_pos = left->lb_pos;
        forn(i, left->indexes.size()) {
            new_sb->indexes.push_back(left->indexes[i]);
            new_sb->numbers.push_back(left->numbers[i] + left->total_added);
            subblock_of[left->indexes[i]] = new_sb.get();
            pos_in_subblock[left->indexes[i]] = i;
        }
        forn(i, right->indexes.size()) {
            new_sb->indexes.push_back(right->indexes[i]);
            new_sb->numbers.push_back(right->numbers[i] + right->total_added);
            subblock_of[right->indexes[i]] = new_sb.get();
            pos_in_subblock[right->indexes[i]] = i + left->indexes.size();
        }
        calc_subblock_psums(new_sb.get());
        large_blocks[lb_id].subblocks.erase(large_blocks[lb_id].subblocks.begin() + sb_id + 1);
        large_blocks[lb_id].subblocks[sb_id] = move(new_sb);
        for (int i = sb_id + 1; i < (int)large_blocks[lb_id].subblocks.size(); i++) {
            large_blocks[lb_id].subblocks[i]->lb_pos = i;
        }
    }

    void fix_sizes(int lb_id, int merge_point) {
        if (merge_point < 0) {
            return;
        }
        if (merge_point + 1 < (int)large_blocks[lb_id].subblocks.size()) {
            if (large_blocks[lb_id].subblocks[merge_point]->indexes.size() < g ||
                large_blocks[lb_id].subblocks[merge_point + 1]->indexes.size() < g) {
                merge_subblocks(lb_id, merge_point);
                int new_size = large_blocks[lb_id].subblocks[merge_point]->indexes.size();
                if (new_size > 2 * g) {
                    split_subblock(lb_id, merge_point, new_size / 2);
                }
            }
        }
    }

    void rotate_large_block(int lb_id, int elem) {
        int rotation_point = [&]() {
            int i = subblock_of[elem]->lb_pos;
            if (pos_in_subblock[elem] == 0) {
                return i;
            }
            split_subblock(lb_id, i, pos_in_subblock[elem]);
            return i + 1;
        }();
        int merge_point = large_blocks[lb_id].subblocks.size() - rotation_point;
        rotate(large_blocks[lb_id].subblocks.begin(),
               large_blocks[lb_id].subblocks.begin() + rotation_point,
               large_blocks[lb_id].subblocks.end());
        int id0 = 0;
        int cur_pos = 0;
        for (auto &sb : large_blocks[lb_id].subblocks) {
            sb->start_pos = id0;
            sb->lb_pos = cur_pos;
            id0 += sb->indexes.size();
            cur_pos++;
        }
        fix_sizes(lb_id, merge_point - 1);
    }

    void insert_into_large_block(int out_id, int in_id, int before_elem) {
        int id2 = [&]() {
            int i = subblock_of[before_elem]->lb_pos;
            if (pos_in_subblock[before_elem] == 0) {
                return i;
            }
            split_subblock(out_id, i, pos_in_subblock[before_elem]);
            return i + 1;
        }();
        int end_point = id2 + large_blocks[in_id].subblocks.size() - 1;
        int out_sz = large_blocks[out_id].subblocks.size();
        int in_sz = large_blocks[in_id].subblocks.size();
        large_blocks[out_id].subblocks.resize(out_sz + in_sz);
        for (int i = out_sz - 1; i >= id2; i--) {
            large_blocks[out_id].subblocks[i + in_sz] = move(large_blocks[out_id].subblocks[i]);
        }
        for (int i = 0; i < in_sz; i++) {
            large_blocks[out_id].subblocks[id2 + i] = move(large_blocks[in_id].subblocks[i]);
        }
        large_blocks[in_id].subblocks.clear();
        int id0 = 0;
        int cur_pos = 0;
        for (auto &sb : large_blocks[out_id].subblocks) {
            sb->id1 = out_id;
            sb->start_pos = id0;
            sb->lb_pos = cur_pos;
            id0 += sb->indexes.size();
            cur_pos++;
        }
        fix_sizes(out_id, end_point);
        fix_sizes(out_id, id2);
        fix_sizes(out_id, id2 - 1);
    }

    void split_large_block(int lb_id, int elem) {
        int split_point = [&]() -> int {
            int i = subblock_of[elem]->lb_pos;
            if (pos_in_subblock[elem] == 0) {
                return i;
            }
            split_subblock(lb_id, subblock_of[elem]->lb_pos, pos_in_subblock[elem]);
            return i + 1;
        }();
        large_block new_lb;
        for (int i = split_point; i < (int)large_blocks[lb_id].subblocks.size(); i++) {
            new_lb.subblocks.emplace_back(move(large_blocks[lb_id].subblocks[i]));
        }
        large_blocks[lb_id].subblocks.erase(large_blocks[lb_id].subblocks.begin() + split_point, large_blocks[lb_id].subblocks.end());
        int id0 = 0;
        int cur_pos = 0;
        for (auto& sb : new_lb.subblocks) {
            sb->start_pos = id0;
            sb->id1 = large_blocks.size();
            sb->lb_pos = cur_pos;
            id0 += sb->indexes.size();
            cur_pos++;
        }
        large_blocks.emplace_back(move(new_lb));
    }

    void merge_large_blocks(int left_id, int right_id) {
        int id0 = large_blocks[left_id].subblocks.back()->start_pos +
            large_blocks[left_id].subblocks.back()->indexes.size();
        int cur_pos = large_blocks[left_id].subblocks.size();
        for (auto& sb : large_blocks[right_id].subblocks) {
            sb->start_pos = id0;
            sb->id1 = left_id;
            sb->lb_pos = cur_pos;
            id0 += sb->indexes.size();
            cur_pos++;
        }
        int left_sz = large_blocks[left_id].subblocks.size();
        for (auto& sb : large_blocks[right_id].subblocks) {
            large_blocks[left_id].subblocks.emplace_back(move(sb));
        }
        fix_sizes(left_id, left_sz - 1);
        large_blocks[right_id].subblocks.clear();
        large_blocks[right_id].subblocks.shrink_to_fit();
    }

    void make_large(int small_id) {
        large_block new_lb;
        new_lb.subblocks.emplace_back(make_unique<subblock>());
        new_lb.subblocks.back()->id1 = large_blocks.size();
        for (int i : small_blocks[small_id].indexes) {
            if (new_lb.subblocks.back()->indexes.size() == 2 * g) {
                new_lb.subblocks.emplace_back(make_unique<subblock>());
                new_lb.subblocks.back()->id1 = large_blocks.size();
            }
            new_lb.subblocks.back()->indexes.push_back(i);
            new_lb.subblocks.back()->numbers.push_back(*a[i]);
            subblock_of[i] = new_lb.subblocks.back().get();
            pos_in_subblock[i] = new_lb.subblocks.back()->indexes.size() - 1;
            a_block_sum[i / g] -= *a[i];
            a[i].reset();
        }
        int cur_pos = 0;
        int id0 = 0;
        for (auto& sb : new_lb.subblocks) {
            sb->start_pos = id0;
            sb->lb_pos = cur_pos;
            calc_subblock_psums(sb.get());
            id0 += sb->indexes.size();
            cur_pos++;
        }
        large_blocks.emplace_back(move(new_lb));
        small_blocks[small_id].indexes.clear();
        small_blocks[small_id].indexes.shrink_to_fit();
    }

    void make_small(int lb_id) {
        small_block new_small;
        for (auto& sb : large_blocks[lb_id].subblocks) {
            forn(i, sb->indexes.size()) {
                new_small.indexes.push_back(sb->indexes[i]);
                a[sb->indexes[i]] = sb->numbers[i] + sb->total_added;
                small_block_of[sb->indexes[i]] = small_blocks.size();
                a_block_sum[sb->indexes[i] / g] += *a[sb->indexes[i]];
            }
        }
        large_blocks[lb_id].subblocks.clear();
        large_blocks[lb_id].subblocks.shrink_to_fit();
        small_blocks.emplace_back(move(new_small));
    }

    int pos_in_lb([[maybe_unused]] int lb_id, int i) {
        return subblock_of[i]->start_pos + pos_in_subblock[i];
    }

    int size_of_lb_of(int i) {
        int lb_id = subblock_of[i]->id1;
        return large_blocks[lb_id].subblocks.back()->start_pos +
            large_blocks[lb_id].subblocks.back()->indexes.size();
    }

    struct block_of {
        bool is_large;
        int id;

        bool operator==(const block_of& rhs) const {
            return is_large == rhs.is_large && id == rhs.id;
        }
    };

    block_of get_block_of(int i) {
        if (a[i].has_value()) {
            return block_of{false, small_block_of[i]};
        }
        return block_of{true, subblock_of[i]->id1};
    }

    void swap_p_split(int i, int j) {
        if (a[i].has_value()) {
            int small_id = small_block_of[i];
            rotate(small_blocks[small_id].indexes.begin(),
                   find(all(small_blocks[small_id].indexes), p[i]),
                   small_blocks[small_id].indexes.end());
            small_block new_sb;
            auto it = find(all(small_blocks[small_id].indexes), p[j]);
            copy(it, small_blocks[small_id].indexes.end(), back_inserter(new_sb.indexes));
            small_blocks[small_id].indexes.erase(it, small_blocks[small_id].indexes.end());
            for (int e : new_sb.indexes) {
                small_block_of[e] = small_blocks.size();
            }
            small_blocks.emplace_back(move(new_sb));
            swap(p[i], p[j]);
            return;
        }

        int lb_i = subblock_of[i]->id1;
        rotate_large_block(lb_i, p[i]);
        split_large_block(lb_i, p[j]);

        if (!a[i].has_value() && size_of_lb_of(i) < g) {
            make_small(subblock_of[i]->id1);
        }
        if (!a[j].has_value() && size_of_lb_of(j) < g) {
            make_small(subblock_of[j]->id1);
        }

        swap(p[i], p[j]);
    }

    void swap_p_merge(int i, int j) {
        if (a[i].has_value() && a[j].has_value()) {
            int small_i = small_block_of[i];
            int small_j = small_block_of[j];
            rotate(small_blocks[small_i].indexes.begin(),
                   find(all(small_blocks[small_i].indexes), p[i]),
                   small_blocks[small_i].indexes.end());
            rotate(small_blocks[small_j].indexes.begin(),
                   find(all(small_blocks[small_j].indexes), p[j]),
                   small_blocks[small_j].indexes.end());
            copy(all(small_blocks[small_j].indexes), back_inserter(small_blocks[small_i].indexes));
            for (int e : small_blocks[small_j].indexes) {
                small_block_of[e] = small_i;
            }
            small_blocks[small_j].indexes.clear();
            small_blocks[small_j].indexes.shrink_to_fit();
            if (small_blocks[small_i].indexes.size() >= g) {
                make_large(small_i);
            }
            swap(p[i], p[j]);
            return;
        }

        if (a[i].has_value()) {
            make_large(small_block_of[i]);
        }
        if (a[j].has_value()) {
            make_large(small_block_of[j]);
        }

        int lb_i = subblock_of[i]->id1;
        int lb_j = subblock_of[j]->id1;

        rotate_large_block(lb_j, p[j]);
        insert_into_large_block(lb_i, lb_j, p[i]);

        if (!a[i].has_value() && size_of_lb_of(i) < g) {
            make_small(subblock_of[i]->id1);
        }

        swap(p[i], p[j]);
    }

public:
    sqrt_dec(vector<int> a_, vector<int> p_)
        : n(a_.size())
        , p(p_)
    {
        a_blocks = (n + g - 1) / g;
        vector<vector<int>> cycles =
            [&]() {
                vector<vector<int>> ret;
                vector<bool> vis(n);
                for (int i = 0; i < n; i++) {
                    if (!vis[i]) {
                        ret.emplace_back();
                        int cur = i;
                        while (!vis[cur]) {
                            ret.back().push_back(cur);
                            vis[cur] = true;
                            cur = p[cur];
                        }
                    }
                }
                return ret;
            }();
        a.resize(n);
        small_block_of.resize(n);
        pos_in_subblock.resize(n);
        subblock_of.resize(n);
        for (const auto& cycle : cycles) {
            if (cycle.size() < g) {
                small_blocks.emplace_back();
                for (int i : cycle) {
                    small_block_of[i] = small_blocks.size() - 1;
                    small_blocks.back().indexes.push_back(i);
                    a[i] = a_[i];
                }
            } else {
                large_blocks.emplace_back();
                large_blocks.back().subblocks.emplace_back(make_unique<subblock>());
                large_blocks.back().subblocks.back()->id1 = large_blocks.size() - 1;
                for (int i : cycle) {
                    if (large_blocks.back().subblocks.back()->indexes.size() == 2 * g) {
                        large_blocks.back().subblocks.emplace_back(make_unique<subblock>());
                        large_blocks.back().subblocks.back()->id1 = large_blocks.size() - 1;
                    }
                    large_blocks.back().subblocks.back()->indexes.push_back(i);
                    large_blocks.back().subblocks.back()->numbers.push_back(a_[i]);
                    subblock_of[i] = large_blocks.back().subblocks.back().get();
                    pos_in_subblock[i] = large_blocks.back().subblocks.back()->indexes.size() - 1;
                }
                int id0 = 0;
                int cur_pos = 0;
                for (const auto& sb : large_blocks.back().subblocks) {
                    sb->start_pos = id0;
                    sb->lb_pos = cur_pos;
                    calc_subblock_psums(sb.get());
                    id0 += sb->indexes.size();
                    cur_pos++;
                }
            }
        }
        a_block_sum.resize(a_blocks);
        for (int i = 0; i < n; i++) {
            if (a[i].has_value()) {
                a_block_sum[i / g] += *a[i];
            }
        }
    }

    ll get_sum(int l, int r) {
        int lb = l / g, rb = r / g;
        if (lb == rb) {
            ll ret = 0;
            forrn(i, l, r) {
                ret += get_val(i);
            }
            return ret;
        }
        ll ret = 0;
        forrn(i, l, (lb + 1) * g) {
            ret += get_val(i);
        }
        forrn(i, rb * g, r) {
            ret += get_val(i);
        }
        forrn(i, lb + 1, rb) {
            ret += a_block_sum[i];
        }
        for (const auto& b : large_blocks) {
            for (const auto& sb : b.subblocks) {
                ret += sb->psum_a_block_as[rb] - sb->psum_a_block_as[lb + 1];
                ret += 1ll * (sb->psum_a_block[rb] - sb->psum_a_block[lb + 1]) * sb->total_added;
            }
        }
        return ret;
    }

    void swap_p(int i, int j) {
        if (i == j) return;
        auto bi = get_block_of(i);
        auto bj = get_block_of(j);
        if (bi == bj) {
            swap_p_split(i, j);
        } else {
            swap_p_merge(i, j);
        }
    }

    void add(int v, ll x) {
        if (a[v].has_value()) {
            for (int i : small_blocks[small_block_of[v]].indexes) {
                *a[i] += x;
                a_block_sum[i / g] += x;
            }
        } else {
            int id1 = subblock_of[v]->id1;
            for (auto& sb : large_blocks[id1].subblocks) {
                sb->total_added += x;
            }
        }
    }

    void print() {
        cout << "=============" << endl;
        cout << "small blocks: " << endl;
        int id = 0;
        for (auto& sb : small_blocks) {
            if (sb.indexes.empty()) {
                id++;
                continue;
            }
            for (int i : sb.indexes) {
                cout << i << " ";
                assert(small_block_of[i] == id);
            }
            cout << endl;
            id++;
        }
        cout << "large blocks: " << endl;
        for (auto& lb : large_blocks) {
            if (lb.subblocks.empty()) {
                continue;
            }
            for (auto& sb : lb.subblocks) {
                id = 0;
                cout << sb->lb_pos;
                cout << " [";
                for (int i : sb->indexes) {
                    cout << i << " ";
                    assert(sb.get() == subblock_of[i]);
                    assert(pos_in_subblock[i] == id);
                    id++;
                }
                cout << "] ";
            }
            cout << endl;
        }
    }

    void check_lbs() {
        for (const auto& lb : large_blocks) {
            for (int i = 0; i < (int)lb.subblocks.size(); i++) {
                assert(i == lb.subblocks[i]->lb_pos);
                assert(lb.subblocks[i]->indexes.size() <= 2 * g);
                assert(i == 0 || i == (int)lb.subblocks.size() - 1 || lb.subblocks[i]->indexes.size() >= g);
            }
        }
    }
};

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    



    mt19937 rnd(179);
    int n = 200'000;
    vector<int> a(n);
    uniform_int_distribution<int> vdist(-1e8, 1e8);
    uniform_int_distribution<int> idist(0, n - 1);
    forn(i, n) {
        a[i] = vdist(rnd);
    }
    vector<int> p(n);
    iota(all(p), 0);
    shuffle(all(p), rnd);
    sqrt_dec sq(a, p);
    int q = 200'000;
    forn(_, q) {
        int i = idist(rnd);
        int j = idist(rnd);
        sq.swap_p(i, j);
    }

    cout << "Time elapsed: " << 1. * clock() / CLOCKS_PER_SEC << endl;

    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    vector<int> p(n);
    forn(i, n) {
        cin >> p[i];
        p[i]--;
    }
    sqrt_dec sq{a, p};

    int q;
    cin >> q;
    forn(_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            l--;

            cout << sq.get_sum(l, r) << '\n';
        } else if (t == 2) {
            int v; ll x;
            cin >> v >> x;
            v--;

            sq.add(v, x);
        } else {
            int i, j;
            cin >> i >> j;
            i--; j--;

            sq.swap_p(i, j);
        }

        

        

    }


    return 0;
}
