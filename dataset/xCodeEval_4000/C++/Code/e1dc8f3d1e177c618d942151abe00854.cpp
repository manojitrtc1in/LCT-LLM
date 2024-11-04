#include <iostream>
#include <math.h>
#include <sstream>
#include <iterator>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono> 
#include <functional>
#include <queue>
#include <bitset>

using namespace std;
using namespace std::chrono;

typedef vector<int> is;
typedef vector<is> iis;

void b() {
    long int t, n, k;
    cin >> t;
    while (t-- > 0) {
        cin >> n >> k;

        long int p2, p1 = (int)floor(sqrt(k));
        p2 = k - (p1 * (p1 - 1)) / 2;
        while (p2 > p1) {
            

            p1 += 1;
            p2 = k - (p1 * (p1 - 1)) / 2;
        }

        

        for (int i = 0; i < n; i++) {
            if (i == n - (p1 + 1)) {
                cout << "b";
            }
            else if (i == n - p2) {
                cout << "b";
            }
            else {
                cout << "a";
            }
        }
        cout << endl;
    }
}

void c() {
    int t, d;
    cin >> t;
    while (t--) {
        string n;
        cin >> d >> n;
        stringstream a, b;
        

        

        int aL = 0; 

        for (auto c : n) {
            int dig = (int)c - '0';
            if (aL) {
                a << 0; b << dig;
            }
            else if (dig == 1) {
                a << 1; b << 0; aL = 1;
            } 
            else {
                a << dig / 2; b << dig / 2;
            }
        }
        cout << a.str() << endl << b.str() << endl;
    }
}







void d() {
    auto print = [](is v) {
        for (auto i : v) cout << i << " ";
        cout << endl;
    };

    int q; cin >> q;
    while (q--) {
        int n, cur; cin >> n;
        is car;
        while (n--) {
            cin >> cur; car.push_back(cur);
        }

        

        is cols;
        int col = 0, prev = car[0];
        bool oneCol = true;
        for (auto t : car) {
            if (prev != t) {
                col = (col + 1) % 2; oneCol = false;
            }
            cols.push_back(col + 1);
            prev = t;
        }

        if (!(car[0] != car.back()
            && cols[0] == cols.back())) {
            cout << (oneCol ? 1 : 2) << endl; print(cols); goto done;
        }

        

        

        

        {
            

            is repaint(cols);
            col = (col + 1) % 2;
            repaint.back() = col + 1;
            for (int i = repaint.size() - 2; i >= 0; --i) {
                col = (col + 1) % 2;
                if (repaint[i] == col + 1) {
                    

                    cout << 2 << endl; print(repaint); goto done;
                }
                repaint[i] = col + 1;
            }
        }

        

        

        

        cout << 3 << endl;
        cols[0] = 3;
        print(cols);

    done:;
    }
}



is cin_is(int size) {
    vector<int> v; v.reserve(size);
    copy_n(istream_iterator<int>(cin), size, back_inserter(v));
    return v;
}

void cout_is(is v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}



void e() {
    int n, m; cin >> n >> m;
    

    

    

    

    iis edges(n + 1, is());
    int ncopy = n;
    while (--ncopy) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    

    

    is next = { 1 };
    is parents(n + 1, 0);
    parents[1] = -1;
    

    while (!next.empty()) {
        int node = next.back(); next.pop_back();
        for (int child : edges[node]) {
            

            if (!parents[child]) {
                next.push_back(child);

                parents[child] = node;
                

            }
        }
    }

    

    

    int color = 1;
    is seen(n + 1, 0);

    while (m--) {
        int k; cin >> k;
        is q = cin_is(k);
        
        
        

        for (int l : q) {
            

            int node = l;
            

            
            while (true) {
                

                seen[node] = color;
                for (int c : edges[node]) seen[c] = color; 

                if (node == 1) break; 

                node = parents[node];
            };

            bool f = true;
            for (int qi : q) {
                if (seen[qi] != color) {
                    f = false; break;
                }
            }
            color++;

            if (f) {
                cout << "YES" << endl; goto done;
            }
        }
        cout << "NO" << endl;
    done:;
    }
}

void e_fast() {
    int n, m; cin >> n >> m; int ncopy = n;

    iis edges(n + 1, is());
    while (--ncopy) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    is next = { 1 };
    is parents(n + 1, 0);
    iis children(n + 1, is());
    is depths(n + 1, 0);
    parents[1] = -1;
    depths[1] = 1; 

    while (!next.empty()) {
        int node = next.back(); next.pop_back();
        for (int child : edges[node]) {
            

            if (!parents[child]) {
                next.push_back(child);
                parents[child] = node;
                children[node].push_back(child);
                depths[child] = depths[node] + 1;
            }
        }
    }

    

    

    

    auto is_leaf = [&](int node) {
        while (true) {
            is c = children[node];
            if (c.empty()) return true;
            if (c.size() > 1) return false;
            node = c[0];
        }
    };

    

    

    auto branchify = [&](int node) {
        int common_parent = node;
        while (true) {
            is c = children[node];
            if (c.empty()) return;
            parents[c[0]] = common_parent;
            node = c[0];
        }
    };

    

    {
        

        is next = children[1];
        while (!next.empty()) {
            int node = next.back(); next.pop_back();
            if (is_leaf(node)) {
                branchify(node);
                continue; 

            }
            for (int c : children[node]) {
                next.push_back(c);
            }
        }
    }

    is seen(n + 1, 0);
    int color = 0;
    while (m--) {
        int k; cin >> k; is q = cin_is(k);
        int node;

        

        if (q.size() == 1) {
            cout << "YES" << endl; goto done;
        }
        
        

        node = *max_element(q.begin(), q.end(), [&](int a, int b) {return depths[a] < depths[b];});

        color++;
        while (true) {
            seen[node] = color;
            

            

            if (node == 1) break;
            node = parents[node];
        }
        
        for (int qi : q) {
            if (seen[qi] != color 
                

                && seen[parents[qi]] != color) {
                cout << "NO" << endl; goto done;
            }
        }

        cout << "YES" << endl;

    done:;
    }
}










































void e_shorten_lines() {
    int n, m; cin >> n >> m; int ncopy = n;

    iis edges(n + 1, is());
    while (--ncopy) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    is next = { 1 };
    is parents(n + 1, 0);
    iis children(n + 1, is());
    is depths(n + 1, 0);
    parents[1] = -1;
    depths[1] = 1; 

    while (!next.empty()) {
        int node = next.back(); next.pop_back();
        for (int child : edges[node]) {
            

            if (!parents[child]) {
                next.push_back(child);
                parents[child] = node;
                children[node].push_back(child);
                depths[child] = depths[node] + 1;
            }
        }
    }

    

    

    

    {
        is next = children[1];
        while (!next.empty()) {
            int n = next.back(); next.pop_back();
            int new_parent = n;
            while (true) {
                is c = children[n];
                if (c.empty()) break;
                if (c.size() > 1) {
                    for (int child : c) next.push_back(child);
                    break;
                }
                n = c[0];
                parents[n] = new_parent;
            }
        }
    }

    is seen(n + 1, 0);
    int color = 0;
    while (m--) {
        int k; cin >> k; is q = cin_is(k);
        int node;

        

        if (q.size() == 1) {
            cout << "YES" << endl; goto done;
        }

        

        node = *max_element(q.begin(), q.end(), [&](int a, int b) {return depths[a] < depths[b];});

        color++;
        while (true) {
            seen[node] = color;
            

            

            if (node == 1) break;
            node = parents[node];
        }

        for (int qi : q) {
            if (seen[qi] != color
                

                && seen[parents[qi]] != color) {
                cout << "NO" << endl; goto done;
            }
        }

        cout << "YES" << endl;

    done:;
    }
}

















void e_store_all_parents() {} 


size_t add(int member, size_t index) {
    return index | hash<int>()(member);
}

bool not_in(int node, size_t index) {
    size_t node_hash = hash<int>()(node);
    return (node_hash & index) != node_hash;
}

void e_store_not_parents() {
    int n, m; cin >> n >> m; int ncopy = n;

    iis edges(n + 1, is());
    while (--ncopy) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    is next = { 1 };
    is parents(n + 1, 0);
    iis children(n + 1, is());
    is depths(n + 1, 0);
    parents[1] = -1;
    depths[1] = 1; 

    while (!next.empty()) {
        int node = next.back(); next.pop_back();
        for (int child : edges[node]) {
            

            if (!parents[child]) {
                next.push_back(child);
                parents[child] = node;
                children[node].push_back(child);
                depths[child] = depths[node] + 1;
            }
        }
    }

    vector<size_t> children_hashes(n + 1, 0);
    function<size_t(int)> children_h;
    children_h = [&](int node) -> size_t {
        is c = children[node];
        if (c.empty()) {
            size_t leaf_hash = hash<int>()(node);
            children_hashes[node] = leaf_hash;
            return leaf_hash;
        }
        size_t children_hash = 0;
        for (int child : c)
            children_hash |= children_h(child);
        children_hashes[node] = children_hash;
        return children_hash;
    };

    

    children_h(1);

    vector<size_t> not_parents_hashes(n + 1, 0);
    {
        is next = { 1 };
        while (!next.empty()) {
            int node = next.back(); next.pop_back();
            is c = children[node];
            

            for (int i = 0; i < c.size(); ++i) {
                size_t not_parents = 0;
                for (int j = 0; j < c.size(); ++j)
                    if (i != j) not_parents |= children_hashes[j];
                not_parents_hashes[node] = not_parents;
            }
        }
    }

    is seen(n + 1, 0);
    int color = 0;
    while (m--) {
        int k; cin >> k; is q = cin_is(k);
        int node;

        

        if (q.size() == 1) {
            cout << "YES" << endl; goto done;
        }

        

        node = *max_element(q.begin(), q.end(), [&](int a, int b) {return depths[a] < depths[b];});

        

        

        


        color++;
        while (true) {
            seen[node] = color;
            

            

            if (node == 1) break;
            node = parents[node];
        }

        for (int qi : q) {
            if (seen[qi] != color
                

                && seen[parents[qi]] != color) {
                cout << "NO" << endl; goto done;
            }
        }

        cout << "YES" << endl;

    done:;
    }
}

vector<int> gen_primes() {
    int max = 3000000;
    vector<int> prime(max, 1);
    for (int i = 2; i < max; ++i) {
        if (prime[i]) {
            for (int j = 2 * i; j < max; j += i)
                prime[j] = 0;
        }
    }
    vector<int> primes; primes.reserve(200010);
    for (int i = 2; i < max; ++i) if (prime[i]) primes.push_back(i);
    return primes;
}

void e_primes() {
    int i, n, m; cin >> n >> m; i = n;
    iis edges(n + 1, is());
    while (--i) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v); edges[v].push_back(u);
    }
    
    is parents(n + 1, 0);
    is depths(n + 1, 0);
    is hashes(n + 1, 1);
    is next = { 1 };
    parents[1] = -1;
    is primes = gen_primes(); i = 0;
    int mod = primes.back();
    while (!next.empty()) {
        int node = next.back(); next.pop_back();
        

        for (int child : edges[node])
            if (!parents[child]) {
                parents[child] = node;
                depths[child] = depths[node] + 1;
                hashes[child] = 
                    (edges[node].size() == 1) ?
                    hashes[node]
                    :
                    (((long long int)hashes[node] * (long long int)primes[i++])
                    % mod);
                next.push_back(child);

                

            }
    }

    while (m--) {
        int k; cin >> k; is q = cin_is(k);
        int u = *max_element(q.begin(), q.end(),
            [&](int n1, int n2) { return depths[n1] < depths[n2]; });
        int u_hash = hashes[u];
        cout << "u: " << u << " hash: " << u_hash << endl;
        for (int qi : q) {
            if (qi == 1) continue; 

            cout << "qi: " << qi << " hashes: " << hashes[qi] << ", " << hashes[parents[qi]] << endl;
            if (u_hash % hashes[qi] != 0
                && u_hash % hashes[parents[qi]] != 0 
                && (u_hash + mod) % hashes[qi] != 0
                && (u_hash + mod) % hashes[parents[qi]] != 0)  {
                    cout << "NO" << endl; goto done;
            }
        }
        cout << "YES" << endl;
    done:;
    }

    

}

void e_parent_hashes() {
    int i, n, m; cin >> n >> m; i = n;
    iis edges(n + 1, is());
    while (--i) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v); edges[v].push_back(u);
    }

    is parents(n + 1, 0);
    is depths(n + 1, 0);
    is hashes(n + 1, 1);
    is next = { 1 };
    parents[1] = -1;
    while (!next.empty()) {
        int node = next.back(); next.pop_back();
        for (int child : edges[node])
            if (!parents[child]) {
                parents[child] = node;
                depths[child] = depths[node] + 1;
                hashes[child] = hashes[node] + child;
                next.push_back(child);
            }
    }

    while (m--) {
        int k; cin >> k; is q = cin_is(k);
        int u = *max_element(q.begin(), q.end(),
            [&](int n1, int n2) { return depths[n1] < depths[n2]; });
        int u_hash = hashes[u];
        cout << "u: " << u << " hash: " << u_hash << endl;
        for (int qi : q) {
            if (qi == 1) continue; 

            cout << "qi: " << qi << " hashes: " << hashes[qi] << ", " << hashes[parents[qi]] << endl;
            if ((u_hash & hashes[qi]) != hashes[qi]
                && (u_hash & hashes[parents[qi]]) != hashes[parents[qi]]) {
                cout << "NO" << endl; goto done;
            }
        }
        cout << "YES" << endl;
    done:;
    }

    

}

void e_track_all_parents() {
    int i, n, m; cin >> n >> m; i = n;
    iis edges(n + 1, is());
    while (--i) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v); edges[v].push_back(u);
    }

    is parents(n + 1, 0);
    is depths(n + 1, 0);
    vector<bitset<200010>> ancestors(n + 1, bitset<200010>());
    is next = { 1 };
    parents[1] = -1;
    while (!next.empty()) {
        int node = next.back(); next.pop_back();
        for (int child : edges[node])
            if (!parents[child]) {
                parents[child] = node;
                depths[child] = depths[node] + 1;
                ancestors[child] = ancestors[node];
                ancestors[child][node] = 1; 

                next.push_back(child);
            }
    }

    while (m--) {
        int k; cin >> k; is q = cin_is(k);
        int u = *max_element(q.begin(), q.end(),
            [&](int n1, int n2) { return depths[n1] < depths[n2]; });
        bitset<200010> u_ancestors = ancestors[u];
        for (int qi : q) { 
            if (qi == 1) continue; 

            if (!u_ancestors[qi] && !u_ancestors[parents[qi]]) {
                cout << "NO" << endl; goto done;
            }
        }
        cout << "YES" << endl;
    done:;
    }
}






































void e_space_ancestor_annotation() {
    int i, n, m; cin >> n >> m; i = n;
    iis edges(n + 1, is());
    while (--i) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v); edges[v].push_back(u);
    }

    

    int batch = 100;
    is parents(n + 1, 0);
    is depths(n + 1, 0);

    

    is ancestors_index(n + 1, -1);
    vector<bitset<200010>> ancestors; ancestors.reserve(n / batch + 10);

    

    is next = { 1 };
    ancestors_index[1] = ancestors.size(); 

    ancestors.push_back(bitset<200010>(1));
    parents[1] = -1;
    while (!next.empty()) {
        int node = next.back(); next.pop_back();
        int node_depth = depths[node];
        if (node_depth % batch == 0) {
            int node2 = node;
            int batch_copy = batch;
            

            bitset<200010> new_entry;
            while (batch_copy--) {
                new_entry[node2] = 1;
                if (node2 == 1) break;
                node2 = parents[node2];
            }
            bitset<200010> last_entry = ancestors[ancestors_index[node2]];

            ancestors_index[node] = ancestors.size();
            ancestors.push_back(last_entry | new_entry);
        }
        for (int child : edges[node])
            if (!parents[child]) {
                parents[child] = node;
                depths[child] = node_depth + 1;
                next.push_back(child);
            }
    }

    while (m--) {
        int k; cin >> k; is q = cin_is(k);
        if (k == 1) {
            cout << "YES" << endl;
            goto done;
        }

        

        {
            int u = *max_element(q.begin(), q.end(),
            [&](int n1, int n2) { return depths[n1] < depths[n2]; });
            

            bitset<200010> not_recorded_ancestors;
            int node = u;
            while (depths[node] % batch != 0) {
                not_recorded_ancestors[node] = 1;
                node = parents[node];
            }
            if (node != -1) not_recorded_ancestors[node] = 1;
            

            bitset<200010> u_ancestors = ancestors[ancestors_index[node]];

            u_ancestors |= not_recorded_ancestors;

            for (int qi : q) {
                if (qi == 1) continue; 

                if (!u_ancestors[qi] && !u_ancestors[parents[qi]]) {
                    cout << "NO" << endl; goto done;
                }
            }
        }
        cout << "YES" << endl;
    done:;
    }
}

int main() {
    e_space_ancestor_annotation();
}
