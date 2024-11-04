
















































for(i=a;i<=b;i++){\
    if(i!=0){printf(" ");}\
    cout<<ara[i];\
}\
printf("\n");

for(i=0;i<vec.size();i++){\
    if(i!=0){printf(" ");}\
    cout<<vec[i];\
}\
printf("\n");

for(i=0;i<n;i++){\
    for(j=0;j<m;j++){\
        if(j!=0){printf(" ");}\
        cout<<ara[i][j];\
    }\
    printf("\n");\
}

for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j];printf("\n");\
    }\
}

for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        if(j!=0){printf(" ");}\
        cout<<vec[i][j];\
    }\
    printf("\n");\
}

for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j];printf("\n");\
    }\
}

for(i=a;i<=b;i++){\
    scanf("%d",&ara[i]);\
}

for(i=a;i<=b;i++){\
    cout<<ara[i];nl;\
}

for(i=0;i<vec.size();i++){\
    cout<<vec[i];nl;\
}

for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    x=*it;\
    cout<<x;nl;\
}\
nl;

for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    if(it!=stl.begin()){sp;}\
    pi(*it);\
}\
nl;

for(i=0;i<vec.size();i++){\
    cout<<vec[i].first;sp;cout<<vec[i].second;printf("\n");\
}

for(i=a;i<=b;i++){\
    cout<<ara[i].first;sp;cout<<ara[i].second;printf("\n");\
}

for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j].first;sp;cout<<vec[i][j].second;nl;\
    }\
}

for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j].first;printf(" ");cout<<ara[i][j].second;nl;\
    }\
}


using namespace std;




























int add(int _a, int _b, int md){
    if(_a < 0){ _a += md; }
    if(_b < 0){ _b += md; }
    if(_a + _b >= md){ return _a + _b - md; }
    return _a + _b;
}
int mul(int _a, int _b, int md){
    if(_a < 0){ _a += md; }
    if(_b < 0){ _b += md; }
    return ((ll)((ll)_a * (ll)_b)) % md;
}
char str[MAX];
int s0[(MAX / 3) + 10], sa0[(MAX / 3) + 10];
int n, ar[MAX], sa[MAX], lcp[MAX], bucket[MAX], mem[MAX << 2];
int LCP[MAX];
void id3(int* source, int* dest, int* val, int n, int lim){ 

    int i, s = 0, x;
    memset(bucket, 0, lim << 2);
    for (i = 0; i < n; i++) bucket[val[source[i]]]++;

    for (i = 0; i < lim; i++){
        x = bucket[i];
        bucket[i] = s, s += x;
    }
    for (i = 0; i < n; i++) dest[bucket[val[source[i]]]++] = source[i];
}

void DC3(int* ar, int* sa, int n, int lim, int ptr){ 

    int *s12, *sa12;
    int allc = (n / 3) << 1, n0 = (n + 2) / 3;
    int i, j, k, l, c, d, p, t, m, r, counter;
    s12 = &mem[ptr], ptr += (allc + 5), sa12 = &mem[ptr], ptr += (allc + 5);

    c = 0, m = 0, r = n + ((n % 3) == 1);
    for (i = 0; i < r; i++, m++){
        if (m == 3) m = 0;
        if (m) s12[c++] = i;
    }
    s12[c] = sa12[c] = s12[c + 1] = sa12[c + 1] = s12[c + 2] = sa12[c + 2] = 0;
    id3(s12, sa12, ar + 2, c, lim + 1);
    id3(sa12, s12, ar + 1, c, lim + 1);
    id3(s12, sa12, ar, c, lim + 1);

    counter = 0, j = -1;
    for (i = 0; i < c; i++){
        if ((ar[sa12[i]] != j) || (ar[sa12[i] + 1] != k) || (ar[sa12[i] + 2] != l)){
            counter++;
            j = ar[sa12[i]], k = ar[sa12[i] + 1], l = ar[sa12[i] + 2];
        }
        if((sa12[i] % 3) == 1) s12[sa12[i] / 3] = counter;
        else s12[(sa12[i] / 3) + n0] = counter;
    }

    if (counter == c){
        for(i = 0; i < c; i++) sa12[s12[i] - 1] = i;
    }
    else{
        DC3(s12, sa12, c, counter, ptr);
        for (i = 0; i < c; i++) s12[sa12[i]] = i + 1;
    }

    for (i = 0, d = 0; i < c; i++){
        if (sa12[i] < n0) s0[d++] = (sa12[i] * 3);
    }
    id3(s0, sa0, ar, d, lim + 1);
    for (k = 0, l = ((n % 3) == 1), r = 0; r < n; r++){
        j = sa0[k];
        i = ((sa12[l] < n0) ? (sa12[l] * 3) + 1 : ((sa12[l] - n0) * 3) + 2);
        if (l == c) sa[r] = sa0[k++];
        else if (k == d) sa[r] = i, l++;
        else{
            if (sa12[l] < n0){
                if ((ar[i] < ar[j]) || (ar[i] == ar[j] && s12[sa12[l] + n0] <= s12[j / 3])) sa[r] = i, l++;
                else sa[r] = j, k++;
            }
            else{
                if ((ar[i] < ar[j]) || (ar[i] == ar[j] && ar[i + 1] < ar[j + 1]) || (ar[i] == ar[j] && ar[i + 1] == ar[j + 1] && s12[sa12[l] - n0 + 1] <= s12[(j /3) + n0]) ) sa[r] = i, l++;
                else sa[r] = j, k++;
            }
        }
    }
}

void id0(){ 

    int i, j, k;
    for (i = 0; i < n; i++) ar[sa[i]] = i;
    for (k = 0, i = 0; i < n; i++, k?k--:0){
        if (ar[i] == (n - 1)) k = 0;
        else{
            j = sa[ar[i] + 1];
            while(((i + k) < n) && ((j + k) < n) && (str[i + k] == str[j + k])) k++;
        }
        lcp[ar[i]] = k;
    }
    for(i = n - 1; i >= 0; i--){ swap(lcp[i], lcp[i + 1]); } lcp[0] = 0;
}

void Generate(){
    int i, j, lim = 0;
    for (i = 0; i < n; i++){
        ar[i] = str[i];
        if (ar[i] > lim) lim = ar[i];
    }

    ar[n] = ar[n + 1] = ar[n + 2] = 0;
    DC3(ar, sa, n, lim, 0);
}
string text, pat[100010], rot[100010];
int nn, len, tree[4 * 3 * SZ + 10], cum[3 * SZ];
int p[2] = {31, 47}, P[2][2 * SZ], h[2][2 * SZ], mod[2] = {1000000007, 1000000009}, sol[SZ];
map < pair <int, int >, bool > mp;
bool global;
void input(){
    int i, j;
    cin >> text;
    si(nn);
    for0(i, nn){ cin >> pat[i]; }
    for(i = 0; i < nn; i++){
        rot[i] = "", rot[i] += pat[i];
        for(j = 0; j + 1 < pat[i].size(); j++){
            rot[i] += pat[i][j];
        }
    }
    for(i = 0, len = 0; i < text.size(); i++){ str[len++] = text[i]; }
    str[len++] = '~';
    for(i = 0; i < nn; i++){
        for(j = 0; j < rot[i].size(); j++){
            str[len++] = rot[i][j];
        }
        str[len++] = '~';
    }
    n = len;


    Generate();
    id0();






}
void mrg(int iter){
    tree[iter] = min(tree[2 * iter + 1], tree[2 * iter + 2]);
}
void makeTree(int lo, int hi, int iter){
    int mid = (lo + hi) >> 1;
    if(lo == hi){ tree[iter] = lcp[lo]; return; }
    else if(lo < hi){
        makeTree(lo, mid, 2 * iter + 1);
        makeTree(mid + 1, hi, 2 * iter + 2);
        mrg(iter);
    }
}
int id4(int lo, int hi, int iter, int v){
    int mid = (lo + hi) >> 1;
    if(lo == hi){ return lo; }
    else if(tree[2 * iter + 2] < v){ return id4(mid + 1, hi, 2 * iter + 2, v); }
    else{ return id4(lo, mid, 2 * iter + 1, v); }
}
int lqry(int lo, int hi, int iter, int l, int r, int v){
    int mid = (lo + hi) >> 1;
    if(l > r){ return -1; }
    if(l <= lo && r >= hi){
        if(!global && tree[iter] < v){
            global = true;
            return id4(lo, hi, iter, v);
        }
        return -1;
    }
    else if(l > hi || r < lo){ return -1; }
    else{
        int R = lqry(mid + 1, hi, 2 * iter + 2, l, r, v);
        int L = lqry(lo, mid, 2 * iter + 1, l, r, v);
        return max(L, R);
    }
}
int id1(int lo, int hi, int iter, int v){
    int mid = (lo + hi) >> 1;
    if(lo == hi){ return lo - 1; }
    else if(tree[2 * iter + 1] < v){ return id1(lo, mid, 2 * iter + 1, v); }
    else{ return id1(mid + 1, hi, 2 * iter + 2, v); }
}
int rqry(int lo, int hi, int iter, int l, int r, int v){
    int mid = (lo + hi) >> 1;
    if(l > r){ return -1; }
    if(l <= lo && r >= hi){
        if(!global && tree[iter] < v){
            global = true;
            return id1(lo, hi, iter, v);
        }
        if(!global && hi == n - 1){ global = true; return n - 1; }
        return -1;
    }
    else if(l > hi || r < lo){ return -1; }
    else{
        int L = rqry(lo, mid, 2 * iter + 1, l, r, v);
        int R = rqry(mid + 1, hi, 2 * iter + 2, l, r, v);
        return max(L, R);
    }
}
inline int id2(int l, int r, int idx){
    return add(h[idx][l], -mul(h[idx][r + 1], P[idx][r - l + 1], mod[idx]), mod[idx]);
}
inline int getsum(int l, int r){
    return cum[l] - cum[r + 1];
}
void solve(){
    int i, j, cnt = 0, l, r, k, sz = text.size(), h0, h1, sz1 = text.size();
    makeTree(0, len - 1, 0);
    for(i = 0; i < text.size() + 1; i++){
        cum[ar[i]] = 1;
    }
    for(i = len - 1, cum[len] = 0; i >= 0; i--){ cum[i] += cum[i + 1]; }

    for(i = 0, cnt = text.size() + 1; i < nn; i++){
        for(j = 0; j < 2; j++){
            for(k = (int)(rot[i].size()) - 1, h[j][k + 1] = 0; k >= 0; k--){
                h[j][k] = add(rot[i][k] - 'a' + 1, mul(p[j], h[j][k + 1], mod[j]), mod[j]);
            }
        }
        for(j = 0, sz = pat[i].size(), mp.clear(); j < pat[i].size(); j++){
            h0 = id2(j, j + sz - 1, 0);
            h1 = id2(j, j + sz - 1, 1);
            if(mp.find(mpr(h0, h1)) == mp.end()){
                global = false;
                l = lqry(0, len - 1, 0, 0, ar[cnt], sz);
                global = false;
                r = rqry(0, len - 1, 0, ar[cnt] + 1, len - 1, sz); r = max(r, ar[cnt]);
                sol[i] += getsum(l, r);
                mp[mpr(h0, h1)] = true;
            }
            cnt++;
        }
        cnt += sz;
    }
    for0(i, nn){
        pi(sol[i]); nl;
    }
}
void pre(){
    int i, j;
    for(i = 0; i < 2; i++){
        for(j = 1, P[i][0] = 1; j <= 2 * SZ - 2; j++){
            P[i][j] = mul(P[i][j - 1], p[i], mod[i]);
        }
    }
}
int main(){




    pre();
    input();
    solve();
}
