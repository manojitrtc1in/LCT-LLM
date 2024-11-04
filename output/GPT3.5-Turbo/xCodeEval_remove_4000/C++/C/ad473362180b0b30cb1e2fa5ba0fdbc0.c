#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 100100
#define MAXNN 20100

typedef long long ll;

typedef struct {
    int fi;
    int se;
} pii;

typedef struct {
    pii fi;
    pii se;
} pair;

typedef struct {
    pair* arr;
    int size;
    int capacity;
} vector;

void vector_init(vector* v) {
    v->size = 0;
    v->capacity = 1;
    v->arr = (pair*)malloc(sizeof(pair) * v->capacity);
}

void vector_push_back(vector* v, pair p) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (pair*)realloc(v->arr, sizeof(pair) * v->capacity);
    }
    v->arr[v->size++] = p;
}

void vector_free(vector* v) {
    free(v->arr);
}

bool uin(int* a, int b) {
    if (*a > b) {
        *a = b;
        return true;
    }
    return false;
}

bool uax(int* a, int b) {
    if (*a < b) {
        *a = b;
        return true;
    }
    return false;
}

const ll INFLL = 1e18;
const int MAXN = 1e5 + 100;
const int MAXNN = 2e4 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
vector a;
int pref[MAXN][2];
int ha[MAXNN], haa_0[MAXNN], haa_1[MAXNN];

void ms(int l, int r) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    ms(l, mid);
    ms(mid + 1, r);
    pair p;
    p.fi.fi = l;
    p.fi.se = mid;
    p.se.fi = mid + 1;
    p.se.se = r;
    vector_push_back(&a, p);
}

char ss[1000000];
vector p;

void mss(int l, int r) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    mss(l, mid);
    mss(mid + 1, r);
    int i = l, j = mid + 1;
    vector b;
    vector_init(&b);

    int now = 0;
    while (i <= mid && j <= r) {
        if (p.arr[i] < p.arr[j]) {
            ss[now++] = '0';
            vector_push_back(&b, p.arr[i++]);
        } else {
            ss[now++] = '1';
            vector_push_back(&b, p.arr[j++]);
        }
    }
    while (i <= mid)
        vector_push_back(&b, p.arr[i++]);
    while (j <= r)
        vector_push_back(&b, p.arr[j++]);
    for (i = l, j = 0; i <= r; i++, j++)
        p.arr[i] = b.arr[j];
    vector_free(&b);
}

void solve() {
    char s[1000000];
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            pref[i][0] = pref[i - 1][0] + 1;
            pref[i][1] = pref[i - 1][1];
        } else {
            pref[i][1] = pref[i - 1][1] + 1;
            pref[i][0] = pref[i - 1][0];
        }
    }
    int id3(int n) {
        a.size = 0;
        ms(0, n - 1);
        vector_reverse(&a);
        vector ans;
        vector_init(&ans);
        int now = 0;
        void does_zero(int ff) {
            int cur = 1;
            int cnt1 = 0, cnt2 = 0;
            pair to = a.arr[0];
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            cnt1 = 0, cnt2 = 0;
            now = ff;
            for (int i = now - 1; i >= 0; i--) {
                char u = s[i];
                if (u == '0')
                    ans.arr[cnt1++] = cur++;
                else
                    ans.arr[sz1 + cnt2] = cur++, cnt2++;
            }
            while (cnt1 < sz1)
                ans.arr[cnt1++] = cur++;
            while (cnt2 < sz2)
                ans.arr[sz1 + cnt2] = cur++, cnt2++;
        }
        void does(int delta, int _) {
            pair to = a.arr[_];
            int cnt1 = 0, cnt2 = 0;
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            int was = now;
            vector fir, sec;
            vector_init(&fir);
            vector_init(&sec);
            cnt1 = 0;
            cnt2 = 0;
            int f = to.fi.fi;
            now += delta;
            for (int i = now - 1; i >= was; i--) {
                if (s[i] == '0')
                    fir.arr[cnt1++] = ans.arr[f++];
                else
                    sec.arr[cnt2++] = ans.arr[f++];
            }
            assert(cnt1 == sz1 || cnt2 == sz2);
            assert(cnt1 < sz1 || cnt2 < sz2);
            while (cnt1 < sz1)
                fir.arr[cnt1++] = ans.arr[f++];
            while (cnt2 < sz2)
                sec.arr[cnt2++] = ans.arr[f++];
            for (int i = to.fi.fi, j = 0; i <= to.fi.se; i++, j++)
                ans.arr[i] = fir.arr[j];
            for (int i = to.se.fi, j = 0; i <= to.se.se; i++, j++)
                ans.arr[i] = sec.arr[j];
            vector_free(&fir);
            vector_free(&sec);
        }
        vector dp[a.size + 1];
        for (int i = 0; i < a.size; i++) {
            dp[i].arr = (bool*)malloc(sizeof(bool) * (n + 1));
            memset(dp[i].arr, 0, sizeof(bool) * (n + 1));
        }
        dp[0].arr[0] = true;
        int y = -INF;
        for (int i = 0; i < a.size; i++) {
            if (dp[i].size == 0)
                break;
            pair to = a.arr[i];
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            int prev_val = -123, prev_w = -1;
            int id2 = 0, id0 = 0;
            for (int j = 0; j < dp[i].size; j++) {
                int too = dp[i].arr[j];
                int cnt1 = 0, cnt2 = 0;
                int w = too;
                if (prev_val + 1 == too) {
                    cnt1 = id2, cnt2 = id0, w = prev_w;
                    if (s[prev_val] == '0')
                        cnt1--;
                    else
                        cnt2--;
                }
                while (w < n && cnt1 < sz1 && cnt2 < sz2) {
                    if (s[w] == '0')
                        cnt1++;
                    else
                        cnt2++;
                    w++;
                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                prev_val = too;
                prev_w = w;
                id2 = cnt1;
                id0 = cnt2;
                if (cnt1 == sz1) {
                    if (s[too] != '0')
                        continue;
                } else {
                    if (s[too] != '1')
                        continue;
                }
                if (i + 1 == a.size)
                    y = y > w ? y : w;
                dp[i + 1].arr[dp[i + 1].size++] = w;
                while (w < n) {
                    if (s[w] == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp[i + 1].arr[dp[i + 1].size++] = w;
                    if (i + 1 == a.size)
                        y = y > w ? y : w;
                }
            }
        }
        if (dp[a.size].arr[dp[a.size].size - 1] != n) {
            return 123;
        }
        for (int i = 0; i < a.size; i++) {
            free(dp[i].arr);
        }
        vector_free(&dp);
        vector from[a.size + 1];
        for (int i = 0; i < a.size; i++) {
            from[i].arr = (int*)malloc(sizeof(int) * (n + 1));
            memset(from[i].arr, 0, sizeof(int) * (n + 1));
        }
        dp[0].arr[0] = true;
        for (int i = 0; i < a.size; i++) {
            if (dp[i].size == 0)
                break;
            pair to = a.arr[i];
            for (int j = 0; j < dp[i].size; j++) {
                int too = dp[i].arr[j];
                int cnt1 = 0, cnt2 = 0;
                int sz1 = to.fi.se - to.fi.fi + 1;
                int sz2 = to.se.se - to.se.fi + 1;
                int w = too;
                while (w < n && cnt1 < sz1 && cnt2 < sz2) {
                    if (s[w] == '0')
                        cnt1++;
                    else
                        cnt2++;
                    w++;
                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                if (cnt1 == sz1) {
                    if (s[too] != '0')
                        continue;
                } else {
                    if (s[too] != '1')
                        continue;
                }
                dp[i + 1].arr[dp[i + 1].size++] = w;
                from[i + 1].arr[w] = too;
                while (w < n) {
                    if (s[w] == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp[i + 1].arr[dp[i + 1].size++] = w;
                    from[i + 1].arr[w] = too;
                }
            }
        }
        if (dp[a.size].arr[dp[a.size].size - 1] != n) {
            return 123;
        }
        vector x;
        vector_init(&x);
        now = 0;
        int ha = n;
        for (int j = a.size; j > 0; j--) {
            int f = from[j].arr[ha];
            vector_push_back(&x, ha - f);
            ha = f;
        }
        vector_reverse(&x);
        does_zero(x.arr[0]);
        assert(x.size == a.size);
        for (int ii = 1; ii < x.size; ii++)
            does(x.arr[ii], ii);
        printf("%d\n", n);
        for (int i = 0; i < ans.size; i++)
            printf("%d ", ans.arr[i]);
        printf("\n");
        return 123;
    }
    int now;
    int l = 1, r = 1e5;
    while (l <= r) {
        int mid = ((l + r) >> 1);
        int w = id3(mid);
        if (w < n)
            l = mid + 1;
        else
            r = mid - 1, now = mid;
    }
    while (1) {
        if (id1(now++))
            return;
    }
}

int main() {

    freopen("a.in", "r", stdin);

    int _t;
    _t = 1;

    while (_t--)
        solve();

    printf("\nTime : %lf\n", (double)(clock()) / CLOCKS_PER_SEC);

    return 0;
}
