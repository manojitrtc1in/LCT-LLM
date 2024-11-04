



























inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );



static const int buf_size = 4096;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}

template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}



static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;

    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}

inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}

struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;

struct Path {
    int32_t v1, v2, k, d;
    int32_t lca_;
    std::pair<int32_t, int32_t> lca_tin_tout;
    std::pair<int32_t, int32_t> top2_tin_tout;
};

int32_t* depths;
int32_t* parents;
std::vector<int32_t> euler;
int32_t* id6;
std::vector<int32_t>* children;
std::pair<int32_t, int32_t>* id5;
int32_t timer_ = 0;
int32_t** ancestors;
int32_t** id4;
void dfs(int32_t v, int32_t parent, std::vector<int32_t>* tree, int32_t depth) {
    euler.push_back(v);
    depths[v] = depth;
    id6[v] = euler.size() - 1;
    parents[v] = parent;
    id5[v].first = timer_++;

    ancestors[v] = new int32_t[20];
    ancestors[v][0] = v;
    ancestors[v][1] = parent;
    for(int32_t i = 2; i < 20; i++)
        if(ancestors[v][i - 1] != -1)
            ancestors[v][i] = ancestors[ancestors[v][i - 1]][i - 1];
        else
            ancestors[v][i] = -1;
    id4[v] = new int32_t[21];
    id4[v][0] = v;
    id4[v][1] = parent == -1 ? 0 : parent;
    for(int32_t i = 2; i <= 20; i++)
        id4[v][i] = (id4[v][i - 1] == 0) ? 0 : ancestors[id4[v][i - 1]][1];

    for(int32_t i = 0; i < tree[v].size(); i++)
        if(tree[v][i] != parent) {
            children[v].push_back(tree[v][i]);

            dfs(tree[v][i], v, tree, depth + 1);
            euler.push_back(v);
        }

    id5[v].second = timer_;
}

int32_t** table;
int32_t lca(int32_t v1, int32_t v2) {
    v1 = id6[v1], v2 = id6[v2];
    if(v1 > v2)
        std::swap(v1, v2);
    int32_t length = v2 - v1 + 1;
    int32_t level = 31 - __builtin_clz(length);
    return (depths[table[level][v1]] < depths[table[level][v2 - (1 << level) + 1]]) ? table[level][v1] : table[level][v2 - (1 << level) + 1];
}

int32_t get_dist(int32_t v1, int32_t v2) {
    return depths[v1] + depths[v2] - 2 * depths[lca(v1, v2)];
}

bool path_close(int32_t v, const Path& path) {
    if(path.lca_tin_tout.first <= id5[v].first && path.lca_tin_tout.second >= id5[v].second) {
        if(path.top2_tin_tout.first <= id5[v].first && path.top2_tin_tout.second >= id5[v].second) {
            return id5[id4[v][path.d]].first <= id5[path.v2].first && id5[id4[v][path.d]].second >= id5[path.v2].second;
        } else {
            return id5[id4[v][path.d]].first <= id5[path.v1].first && id5[id4[v][path.d]].second >= id5[path.v1].second;
        }
    } else {
        if(id5[v].first <= path.lca_tin_tout.first && id5[v].second >= path.lca_tin_tout.second)
            return depths[path.lca_] - depths[v] <= path.d;
        return get_dist(v, path.lca_) <= path.d;
    }
}

int32_t* marks;
int32_t** marks2;
int32_t** superboost;





void dfs_up(int32_t v) {
    for(int32_t i = 0; i < children[v].size(); i++) {
        dfs_up(children[v][i]);

        int32_t child = children[v][i];
        marks[v] += marks[child];
        for(int32_t j = 0; j < D_LIM - 1; j++) {
            marks2[v][j] += marks2[child][j];
            superboost[v][j] += superboost[child][j];
        }
    }
}

void id7(int32_t v, int32_t* values) {
    int32_t* cur = marks2[v];

    values[v] += marks[v];
    for(int32_t i = 0; i < D_LIM - 1; i++)
        values[v] += cur[i];

    for(int32_t i = 0; i < children[v].size(); i++) {
        int32_t* next = marks2[children[v][i]];
        for(int32_t j = 0; j < D_LIM - 1; j++) {
            

            next[j] += cur[j + 1] + superboost[v][j + 1];
        }
    }
    for(int32_t i = 0; i < children[v].size(); i++) {
        id7(children[v][i], values);
    }
}

int32_t* id3;
int32_t id0 = 0;

void id1(int32_t v, int32_t parent, std::vector<int32_t>* tree) {
    id3[v] = 1;
    for(int32_t i = 0; i < tree[v].size(); i++) {
        if(tree[v][i] != parent) {
            id1(tree[v][i], v, tree);

            id3[v] += id3[tree[v][i]];
        }
    }
}

void id2(int32_t v, int32_t parent, std::vector<int32_t>* tree, int32_t* to_new_num) {
    to_new_num[v] = id0++;
    for(int32_t i = 0; i < tree[v].size(); i++)
        if(tree[v][i] != parent && (tree[v][0] == parent || id3[tree[v][i]] > id3[tree[v][0]]))
            std::swap(tree[v][i], tree[v][0]);
    for(int32_t i = 0; i < tree[v].size(); i++)
        if(tree[v][i] != parent)
            id2(tree[v][i], v, tree, to_new_num);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int32_t n = readInt();
    


    std::vector<int32_t>* tree = new std::vector<int32_t>[n];
    std::mt19937 rng;
    for(int32_t i = 0; i < n - 1; i++) {
        int32_t v1 = readInt();
        int32_t v2 = readInt();
        v1--;
        v2--;
        

        


        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    id3 = new int32_t[n];
    id1(0, -1, tree);
    int32_t* to_new_number = new int32_t[n];
    id2(0, -1, tree, to_new_number);
    std::vector<int32_t>* tree2 = new std::vector<int32_t>[n];
    for(int32_t i = 0; i < n; i++) {
        tree2[to_new_number[i]] = tree[i];
        for(int32_t& x : tree2[to_new_number[i]])
            x = to_new_number[x];
    }
    tree = tree2;

    depths = new int32_t[n];
    id6 = new int32_t[n];
    parents = new int32_t[n];
    children = new std::vector<int32_t>[n];
    id5 = new std::pair<int32_t, int32_t>[n];
    ancestors = new int32_t*[n];
    id4 = new int32_t*[n];
    dfs(0, -1, tree, 0);

    int32_t max_level = 0;
    while((1 << max_level) <= euler.size())
        max_level++;
    max_level--;

    table = new int32_t*[max_level + 1];
    for(int32_t i = 0; i <= max_level; i++) {
        table[i] = new int32_t[euler.size() - (1 << i) + 1];
        for(int32_t j = 0; j < euler.size() - (1 << i) + 1; j++)
            if(i == 0)
                table[i][j] = euler[j];
            else
                table[i][j] = (depths[table[i - 1][j]] < depths[table[i - 1][j + (1 << i) / 2]]) ? table[i - 1][j] : table[i - 1][j + (1 << i) / 2];
    }

    int32_t m = readInt();
    


    int32_t* prev_values = new int32_t[n];
    for(int32_t i = 0; i < n; i++)
        prev_values[i] = 0;
    std::vector<Path> pending_paths;

    marks = new int32_t[n];
    marks2 = new int32_t*[n];
    for(int32_t i = 0; i < n; i++) {
        marks2[i] = new int32_t[D_LIM];
    }
    superboost = new int32_t*[n];
    for(int32_t i = 0; i < n; i++) {
        superboost[i] = new int32_t[D_LIM];
    }

    int64_t test = 0;
    for(int32_t q = 0; q < m; q++) {
        int32_t type = readInt();
        


        if(type == 2) {
            pending_paths.emplace_back();
            pending_paths.back().v1 = readInt();
            pending_paths.back().v2 = readInt();
            pending_paths.back().k = readInt();
            pending_paths.back().d = readInt();
            

            pending_paths.back().v1 = to_new_number[pending_paths.back().v1 - 1];
            pending_paths.back().v2 = to_new_number[pending_paths.back().v2 - 1];
            if(depths[pending_paths.back().v1] > depths[pending_paths.back().v2])
                std::swap(pending_paths.back().v1, pending_paths.back().v2);

            pending_paths.back().lca_ = lca(pending_paths.back().v1, pending_paths.back().v2);
            pending_paths.back().lca_tin_tout = id5[pending_paths.back().lca_];

            int32_t top2 = pending_paths.back().v2;
            if(top2 != pending_paths.back().lca_) {
                for (int32_t i = 19; i >= 0; i--)
                    if ((depths[pending_paths.back().v2] - depths[pending_paths.back().lca_] - 1) & (1 << (i - 1)))
                        top2 = ancestors[top2][i];
            }
            pending_paths.back().top2_tin_tout = id5[top2];

            if(pending_paths.size() == BIG_SIZE) {
                for(int32_t i = 0; i < n; i++) {
                    marks[i] = 0;
                    for(int32_t j = 0; j < D_LIM; j++) {
                        marks2[i][j] = 0;
                        superboost[i][j] = 0;
                    }
                }

                for(auto path : pending_paths) {
                    if(path.lca_ != path.v1 && path.lca_ != path.v2) {
                        superboost[path.v1][path.d] += path.k;
                        superboost[path.v2][path.d] += path.k;
                        superboost[path.lca_][path.d] -= path.k;
                        if(parents[path.lca_] != -1)
                            superboost[parents[path.lca_]][path.d] -= path.k;

                        marks[path.v1] += path.k;
                        marks[path.v2] += path.k;
                        marks[path.lca_] -= path.k;
                        if(parents[path.lca_] != -1)
                            marks[parents[path.lca_]] -= path.k;

                        if(path.d > 0) {
                            marks2[path.v1][path.d - 1] -= path.k;
                            marks2[path.v2][path.d - 1] -= path.k;
                            marks2[path.lca_][path.d - 1] += 2 * path.k;
                        }
                    } else {
                        superboost[path.v2][path.d] += path.k;
                        if(parents[path.lca_] != -1)
                            superboost[parents[path.lca_]][path.d] -= path.k;

                        marks[path.v2] += path.k;
                        if(parents[path.lca_] != -1)
                            marks[parents[path.lca_]] -= path.k;

                        if(path.d > 0) {
                            marks2[path.v2][path.d - 1] -= path.k;
                            marks2[path.lca_][path.d - 1] += path.k;
                        }
                    }

                    if(parents[path.lca_] != -1)
                        marks[parents[path.lca_]] += path.k;
                    int32_t v = path.lca_;
                    int32_t prev = path.lca_;
                    for(int32_t i = 0; i < path.d; i++) {
                        v = parents[v];
                        if(v == -1)
                            break;

                        superboost[v][path.d - i - 1] += path.k;
                        if(parents[v] != -1)
                            superboost[parents[v]][path.d - i - 1] -= path.k;
                        if(path.d - i - 1 > 0) {
                            marks2[prev][path.d - i - 2] -= path.k;
                            marks2[v][path.d - i - 2] += path.k;
                        }

                        prev = v;
                    }
                    if(v != -1 && parents[v] != -1)
                        marks[parents[v]] -= path.k;
                }

                dfs_up(0);
                id7(0, prev_values);

                pending_paths.clear();
            }
        } else {
            int32_t v = readInt();
            

            v--;
            v = to_new_number[v];

            int32_t res = prev_values[v];
            for(int32_t i = 0; i < pending_paths.size(); i++)
                if(path_close(v, pending_paths[i]))
                    res += pending_paths[i].k;
            writeInt(res, '\n');
            

        }
    }
    

    return 0;
}


