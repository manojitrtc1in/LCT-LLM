



using namespace std;







int N;
int a[1000000], b[1000000];
int pos_b[1000001];
int t[4000000];
int f[1000000];

void build(const int &v, const int &tl, const int &tr) {
    t[v] = tl;
    if(tl == tr)
        return;
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
}

int get(const int &v, const int &tl, const int &tr, const int &l, const int &r) {
    if(l <= tl && tr <= r)
        return t[v];
    if(l > tr || r < tl)
        return -1;
    int tm = (tl + tr) / 2;
    int i1 = get(v * 2, tl, tm, l, r);
    int i2 = get(v * 2 + 1, tm + 1, tr, l, r);
    if(min(i1, i2) == -1)
        return max(i1, i2);
    return (f[i1] > f[i2] ? i1 : i2);
}


void update(const int &v, const int &tl, const int &tr, const int &pos) {
    if(tl == tr && tl == pos) {
        t[v] = tl;
        return;
    }
    if(pos > tr || pos < tl)
        return;
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, pos);
    update(v * 2 + 1, tm + 1, tr, pos);
    t[v] = (f[t[v * 2]] > f[t[v * 2 + 1]] ? t[v * 2] : t[v * 2 + 1]);
}

void solve() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++)
        scanf("%d", &a[i]);
    for(int i = 0;i < N;i++) {
        scanf("%d", &b[i]);
        pos_b[b[i]] = i;
        f[i] = 0;
    }
    build(1, 0, N - 1);
    for(int i = 0;i < N;i++) {
        int dp_prev = get(1, 0, N - 1, pos_b[a[i]], N - 1);
        f[pos_b[a[i]]] = f[dp_prev] + 1;
        update(1, 0, N - 1, pos_b[a[i]]);
    }
    printf("%d", f[get(1, 0, N - 1, 0, N - 1)]);
}

int main() {
    if(ONLINE_JUDGE) { 

        ;
    } else { 

        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
