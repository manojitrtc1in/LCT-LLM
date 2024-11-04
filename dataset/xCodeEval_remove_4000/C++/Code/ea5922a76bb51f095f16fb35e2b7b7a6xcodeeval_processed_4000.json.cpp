


using namespace std;











using pi = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vc = vector<char>;
using vb = vector<bool>;
using vii = vector<pi>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vvc = vector<vc>;
using vvb = vector<vb>;
using si = set<int>;
string al = "abcdefghijklmnopqrstuvwxyz";
int INF = 1e18;

template<class T>
void show(const vector<T> &a) {

    for (T x: a)
        cout << x << " ";
    cout << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vi parent(n);
        int root;
        vvi g(n);
        for (int i = 0; i < n; i++) {
            cin >> parent[i], parent[i]--;
            if (parent[i] == i) {
                root = i;
                continue;
            }
            g[parent[i]].push_back(i);
        }
        vi p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i], p[i]--;
        }
        set<int> q;
        q.insert(root);
        vi res(n, -1), sum(n);
        int fl = 0, t = 1;
        res[root] = 0;
        if(p[0] != root)
            fl = 1;
        for(int i = 1; i < n; i++){
            if(res[parent[p[i]]] == -1 || fl == 1){
                fl = 1;
                break;
            }
            else {
                sum[p[i]] = t;
                res[p[i]] = t - sum[parent[p[i]]];
                t++;
            }
        }
        if(fl == 1)
            cout << -1 << endl;
        else
            show(res);
    }
}