#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

typedef struct {
    int x, y, i;
} point;

point make_point(int x, int y, int i) {
    point p;
    p.x = x;
    p.y = y;
    p.i = i;
    return p;
}

point operator -(point a, point b){
    return make_point(a.x - b.x, a.y - b.y, -1);
}

point operator +(point a, point b){
    return make_point(a.x + b.x, a.y + b.y, -1);
}

int operator ==(point a, point b){
    return (a.x == b.x && a.y == b.y);
}

li sdist(point a, point b){
    return sqr(li(a.x - b.x)) + sqr(li(a.y - b.y));
}

li dot(point a, point b){
    return a.x * li(b.x) + a.y * li(b.y);
}

li cross(point a, point b){
    return a.x * li(b.y) - a.y * li(b.x);
}

const int N = 2000 + 7;

point a[N];
int n;
char s[N];

int read () {
    if (scanf("%d", &n) != 1)
        return 0;
    forn(i, n){
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].i = i + 1;
    }
    scanf("%s", s);
    return 1;
}

int find(point* arr, int size, point p) {
    for (int i = 0; i < size; i++) {
        if (arr[i].x == p.x && arr[i].y == p.y) {
            return i;
        }
    }
    return -1;
}

point* build(){
    if (n <= 1) {
        point* res = (point*)malloc(n * sizeof(point));
        for (int i = 0; i < n; i++) {
            res[i] = a[i];
        }
        return res;
    }
    
    point* up = (point*)malloc(n * sizeof(point));
    point* dw = (point*)malloc(n * sizeof(point));
    int up_size = 0;
    int dw_size = 0;
    
    up[up_size++] = a[0];
    dw[dw_size++] = a[0];
    
    for (int i = 1; i < n; i++) {
        if (i == n - 1 || cross(a[n - 1] - a[0], a[i] - a[0]) >= 0){
            while (up_size > 1 && cross(a[i] - up[up_size - 2], up[up_size - 1] - up[up_size - 2]) < 0)
                up_size--;
            up[up_size++] = a[i];
        }
        if (i == n - 1 || cross(a[n - 1] - a[0], a[i] - a[0]) < 0){
            while (dw_size > 1 && cross(a[i] - dw[dw_size - 2], dw[dw_size - 1] - dw[dw_size - 2]) > 0)
                dw_size--;
            dw[dw_size++] = a[i];
        }
    }
    
    point* res = (point*)malloc((up_size + dw_size - 2) * sizeof(point));
    int res_size = 0;
    for (int i = 0; i < up_size; i++) {
        res[res_size++] = up[i];
    }
    for (int i = dw_size - 2; i >= 1; i--) {
        res[res_size++] = dw[i];
    }
    
    free(up);
    free(dw);
    
    return res;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].x > a[j].x || (a[i].x == a[j].x && a[i].y > a[j].y)) {
                point temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    point* ans = (point*)malloc(n * sizeof(point));
    int ans_size = 0;
    
    point* ch = build();
    ans[ans_size++] = ch[0];
    if (s[0] == 'L')
        ans[ans_size++] = ch[sz(ch) - 1];
    else
        ans[ans_size++] = ch[1];
    
    for (int i = 0; i < sz(s); i++){
        int x = find(a, n, ans[ans_size - 2]);
        for (int j = x + 1; j < n; j++) {
            a[j - 1] = a[j];
        }
        n--;
        point* ch = build();
        int pos = find(ch, sz(ch), ans[ans_size - 1]);
        if (s[i + 1] == 'L')
            ans[ans_size++] = ch[(pos - 1 + sz(ch)) % sz(ch)];
        else
            ans[ans_size++] = ch[(pos + 1) % sz(ch)];
    }
    
    for (int i = 0; i < ans_size; i++) {
        printf("%d ", ans[i].i);
    }
    puts("");
    
    free(ans);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    
    int tt = clock();
    
#endif
    
    while(read()) {
        solve();
        
#ifdef _DEBUG
    printf("TIME = %d\n", clock() - tt);
    tt = clock();
#endif
    
    }
}
