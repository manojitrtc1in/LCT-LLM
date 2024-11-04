


















using namespace std;



inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            f = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48); 
}

inline void writeln(int x) {
	if (x < 0) {
		putchar('-'); x = -x;
	}
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48); 
	putchar('\n');
}

inline LL readll() {
    LL x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            f = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

inline void id2(LL x) {
	if (x < 0) {
		putchar('-'); x = -x;
	}
    static LL sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48); 
}

inline void id1(LL x) {
	if (x < 0) {
		putchar('-'); x = -x;
	}
    static LL sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48); 
	putchar('\n');
}

const int hashMod = 999983;

template<class TYPENAME>
class HashNode {
public:
    TYPENAME val;
    int key, next;
    HashNode(TYPENAME _val, int _key, int _next): val(_val), key(_key), next(_next) {}
    bool isNull() {
        return key == -1;
    }
};

template<class TYPENAME>
class Hash {
public:
    vector<HashNode<TYPENAME> > nodes;
    vector<int> d;
    int nodeN;
    Hash() {
        nodeN = 0; 
        d = vector<int>(hashMod, -1);
    }
    void push(int key, TYPENAME val) {
        nodes.push_back(HashNode<TYPENAME>(val, key, d[key]));
        d[key] = nodeN++;
    }
    HashNode<TYPENAME> find(int key, TYPENAME val) {
        for (int p = d[key]; p != -1; p = nodes[p].next) {
            if (nodes[p].val == val) {
                return nodes[p];
            }
        }
        return HashNode<TYPENAME>(val, -1, -1);
    }
};

int n, c, q;
vector<int> ii;
vector<LL> jj;
vector<int> p;
vector<vector<LL> > ways, wayC;

LL permContained(int l, int r, int cc) {
    if (l == -1) {
        return 1; 

    }
    

    

    return ways[n - r - 1][cc - (r - l)];
}








bool id0(const pair<int, int> &a, const pair<int, int> &b) {
    return p[a.second] < p[b.second];
}
bool pGreater(const pair<int, int> &a, const pair<int, int> &b) {
    return p[a.second] > p[b.second];
}

class Query {
public:
    int ii, idx;
    LL jj;
    Query(int _idx, int _ii, LL _jj): idx(_idx), ii(_ii), jj(_jj) {}
    void print() {
        printf("Query(idx = %d, ii = %d, jj = %lld) ", idx, ii, jj);
    }
};

bool cmpQuery(const Query &a, const Query &b) {
    return a.jj < b.jj;
}
void solve() {
    n = read(); c = read(); q = read();
    

    p = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        p[i] = read();
    }
    ii = vector<int>(q);
    jj = vector<LL>(q);
    for (int i = 0; i < q; ++i) {
        ii[i] = read() - 1; jj[i] = readll() - 1;
        

    }

    

    

    

    


    wayC = vector<vector<LL> >(n);
    for (int i = 0; i < n; ++i) {
        wayC[i] = vector<LL>(c + 1, 0);
        wayC[i][0] = 1;
    }

    

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= c; ++j) {
            

            if (i < j) {
                wayC[i][j] = 0;
            } else {
                wayC[i][j] = wayC[i - 1][j] + wayC[i - 1][j - 1];
            }
        }
    }

    

    

    

    

    

    
    ways = vector<vector<LL> >(n + 1);
    for (int i = 0; i <= n; ++i) {
        ways[i] = vector<LL>(c + 1, 1);
    }
    

    

    for (int i = 1; i <= n; ++i) {
        ways[i][0] = wayC[i - 1][0];
        for (int j = 1; j <= c; ++j) {
            ways[i][j] = ways[i][j - 1] + wayC[i - 1][j];
            

        }
    }

    


    

    

    

    


    


    

    

    

    

    

    

    

    

    

    

    

    


    


    vector<deque<pair<int, int> > > dq(c + 1);
    for (int cc = 0; cc <= c; ++cc) {
        

        dq[cc].push_back({n - 1, n - 1});
        for (int i = n - 1; i >= 0; --i) {
            vector<pair<int, int> > lft, rgt;
            for (int j = i + 1; j <= i + cc && j < n; ++j) {
                

                

                

                

                

                

                

                if (p[j] < p[i]) {
                    lft.push_back({i, j});
                } else {
                    rgt.push_back({i, j});
                }
            }
            sort(lft.begin(), lft.end(), pGreater);
            sort(rgt.begin(), rgt.end(), id0);
            for (int i = 0; i < lft.size(); ++i) {
                dq[cc].push_front(lft[i]);
            }
            for (int i = 0; i < rgt.size(); ++i) {
                dq[cc].push_back(rgt[i]);
            }
        }

        

        

        

        

        

    }

    


    

    

    

    

    

    

    

    

    

    

    

    

    


    vector<int> ans(q, -1);
    

    

    

    

    

    

    


    vector<vector<Query> > que(c + 1);
    for (int i = 0; i < q; ++i) {
        que[c].push_back(Query(i, ii[i], jj[i]));
        

    }

    vector<vector<LL> > pp(c + 1);
    

    for (int cc = 0; cc <= c; ++cc) {
        pp[cc] = vector<LL>(n, -1);
        LL perms = 0;
        int ll, rr;
        for (pair<int, int> pr: dq[cc]) {
            ll = pr.first; rr = pr.second;
            if (ll == -1) {
                continue;
            }
            if (pp[cc][ll] == -1) {
                pp[cc][ll] = perms;
                

            }
            perms += permContained(ll, rr, cc);
        }
        

        for (int i = n - 2; i >= 0; --i) {
            pp[cc][i] = min(pp[cc][i], pp[cc][i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            

        }
        

        

    }

    


    for (int cc = c; cc >= 0; --cc) {
        

        if (que[cc].size() == 0) {
            continue;
        }
        sort(que[cc].begin(), que[cc].end(), cmpQuery);
        

        


        

        

        


        

        

        int qcur = 0;
        LL currPerm = 0;
        

        

        

        

        

        


        

        

        

        


        for (pair<int, int> pr: dq[cc]) {
            int ll = pr.first, rr = pr.second;
            

            

            LL newPerm = permContained(ll, rr, cc);
            

            while (qcur < que[cc].size() && que[cc][qcur].jj < currPerm + newPerm) {
                int cii = que[cc][qcur].ii;
                LL cjj = que[cc][qcur].jj;
                int cidx = que[cc][qcur].idx;
                

                if (ll == -1 || cii < ll) {
                    

                    ans[cidx] = p[cii];
                    ++qcur; continue;
                }
                if (cii >= ll && cii <= rr) {
                    

                    ans[cidx] = p[rr - (cii - ll)];
                    ++qcur; continue;
                }
                

                

                int nc = cc - (rr - ll);
                

                

                

                if (rr >= n - 1) {
                    

                    ans[cidx] = -1;
                    ++qcur; continue;
                }
                

                que[nc].push_back(Query(cidx, cii, pp[nc][rr + 1] + cjj - currPerm));
                ++qcur;
                

            }
            currPerm += newPerm;
        }
    }

    for (int i = 0; i < q; ++i) {
        writeln(ans[i]);
    }
}

int main() {
	

    

    int t = read();
    for (int i = 0; i < t; ++i) {
        solve();
    }
	return 0;
}