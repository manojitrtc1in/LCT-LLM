

using namespace std;

typedef pair <int, int> pi;
typedef long long LL;   
typedef pair <LL, LL> pd;

const int P = 998244353; 

const int INF = 0x3f3f3f3f;
const LL INFLL = 0x3f3f3f3f3f3f3f3fll;
const int N = 1e6 + 5;

int n, m;
pd a[N];
int id[N];

inline pd operator+(pd& x, pd& y) { return make_pair(x.first + y.first, x.second + y.second); }
inline pd operator-(pd& x, pd& y) { return make_pair(x.first - y.first, x.second - y.second); }
inline LL prod(pd x, pd y) { return x.first * y.first + x.second * y.second; }

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second, id[i] = i;
    random_shuffle(id + 1, id + n + 1);    
    int T = 0;
    auto c_start = clock();
    while(true) {
        T++;
        bool flag = true;
        for(int i = 2; i < n; i++) 
            if(prod(a[id[i]] - a[id[i - 1]], a[id[i]] - a[id[i + 1]]) <= 0) swap(id[i], id[i - 1]);
        for(int i = 2; i < n; i++)
            if(prod(a[id[i]] - a[id[i - 1]], a[id[i]] - a[id[i + 1]]) <= 0) {
                flag = false;
                break;
            }
        if(flag == false) {
            if(T % 100 == 0)
                if(1.0 * (clock() - c_start) / CLOCKS_PER_SEC > 1.9) break;
            continue;
        }
        for(int i = 1; i <= n; i++) printf("%d ", id[i]);
        return ;
    }
    printf("-1\n");
}

int main() {
    init();
    return 0;
}



























