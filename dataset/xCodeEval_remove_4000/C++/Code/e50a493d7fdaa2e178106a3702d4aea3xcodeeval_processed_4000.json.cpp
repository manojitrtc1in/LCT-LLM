







using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

namespace my {
    ii operator+(const ii &a, const ii &b) {return {a.x + b.x, a.y + b.y};}
    ii operator-(const ii &a, const ii &b) {return {a.x - b.x, a.y - b.y};}
    ii operator*(const ii &a, const ii &b) {return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};}
    ii operator*(const ii &a, const int &b) {return {a.x * b, a.y * b};}
    ii operator/(const ii &a, const int &b) {return {a.x / b, a.y / b};}
    ii conj(const ii &e) {return {e.x, -e.y};};
    ostream& operator<<(ostream &s, const ii &p) {s << '(' << p.x << ", " << p.y << ')';return s;}
}

using namespace my;

int n, m, l[100000], c[100000], a[200000];
ll idx[100000];
map<ll, int> ans;

void solve() {
    scanf("%d", &m);
    for(int i = 0;i < m;i++) {
        int t, l_, c_, x_;
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d", &x_);
            l[i] = x_;
            c[i] = -1;
        } else {
            scanf("%d %d", &l_, &c_);
            l[i] = l_;
            c[i] = c_;
        }
    }
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%I64d", &idx[i]);
        idx[i]--;
    }
    int ptr = 0, j = 0;
    ll i = 0;
    for(;j < m && i < 100000;j++) {
        if(c[j] == -1) {
            ans[i] = l[j];
            a[i] = l[j];
            while(ptr < n && idx[ptr] == i)
                ptr++;
            i++;
        } else {
            while(ptr < n && i <= idx[ptr] && idx[ptr] < i + l[j] * c[j]) {
                ans[idx[ptr]] = a[(idx[ptr] - i) % l[j]];
                ptr++;
            }
            int k = 0, mk = min(int(200000 - i) / l[j], c[j]);
            if(mk < c[j])
                c[j] = c[j] - mk;
            for(;k < mk;k++) {
                for(int t = 0;t < l[j];t++) {
                    a[i] = a[t];
                    i++;
                }
            }
        }
    }
    for(;j < m;j++) {
        if(c[j] == -1) {
            ans[i] = l[j];
            while(ptr < n && idx[ptr] == i)
                ptr++;
            i++;
        } else {
            while(ptr < n && i <= idx[ptr] && idx[ptr] < i + l[j] * c[j]) {
                ans[idx[ptr]] = a[(idx[ptr] - i) % l[j]];
                ptr++;
            }
            i += l[j] * c[j];
        }
    }
    for(int i = 0;i < n;i++)
        printf("%d ", ans[idx[i]]);
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
