




















































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






























inline int add(int _a, int _b){
    if(_a < 0){ _a += MOD; }
    if(_b < 0){ _b += MOD; }
    if(_a + _b >= MOD){ return _a + _b - MOD; }
    return _a + _b;
}
inline int mul(int _a, int _b){
    if(_a < 0){ _a += MOD; }
    if(_b < 0){ _b += MOD; }
    return ((ll)((ll)_a * (ll)_b)) % MOD;
}
const int N = 100;
int n, k, ara[N];
bool mark[N];
double sum = 0.0;
string str[] = {"CH", "HC", "CO", "HO", "OHH", "OCC"};
char res[N];
void input(){
    int i, j;
    mem(mark, false);
    si(n);
}
void interaction2(string t){
    int i, j;
    double x = (double)t.size();
    sum += 1.0 / (x * x);
    assert(sum <= 7.0 / 5.0);
    cout << "?" << " " << t; nl;
    fflush(stdout);
    si(k);
    assert(k >= 0);
    for0(i, k){ si(ara[i]); ara[i]--; }
}
void solve2(){
    int i, j, l;
    for(i = 0; i < 6; i++){
        interaction2(str[i]);
        for(j = 0; j < k; j++){
            for(l = 0; l < str[i].size(); l++){
                mark[ara[j] + l] = true, res[ara[j] + l] = str[i][l];
            }
        }
    }
    for(i = 0; i < n; i++){
        if(mark[i] && res[i] == 'C'){
            for(j = i - 1; j >= 0; --j){
                if(mark[j]){ break; }
            }
            if(j >= 0){
                if(res[j] == 'C'){ for(l = j + 1; l < i; l++){ res[l] = 'C'; } }
                else{ for(l = j + 1; l < i; l++){ res[l] = 'O'; } }
            }
        }
    }
    for(i = 0; i < n; i++){
        if(mark[i] && res[i] == 'H'){
            for(j = i - 1; j >= 0; --j){
                if(mark[j]){ break; }
            }
            if(j >= 0){
                if(res[j] == 'H'){ for(l = j + 1; l < i; l++){ res[l] = 'H'; } }
                else{ for(l = j + 1; l < i; l++){ res[l] = 'O'; } }
            }
        }
    }
    for(i = 0; i < n; i++){
        if(mark[i] && res[i] == 'O'){
            for(j = i - 1; j >= 0; --j){
                if(mark[j]){ break; }
            }
            for(l = j + 1; l < i; l++){ res[l] = 'O'; }
        }
    }
    for(i = 0; i < n && !mark[i]; i++);
    if(i == n){
        string s = "";
        for(i = 0; i < n - 1; i++){ s += "O"; }
        interaction2(s);
        if(k == 2){
            cout << "!" << " " << s + "O"; nl;
            fflush(stdout);
            return;
        }
        else if(k == 1){
            interaction2(s + "C");
            if(k){
                cout << "!" << " " << s + "C"; nl;
                fflush(stdout);
                return;
            }
            cout << "!" << " " << s + "H"; nl;
            fflush(stdout);
            return;
        }
        else{
            string s1 = "", s2 = "";
            for0(i, n){ s1 += "C"; s2 += "H"; }
            interaction2(s1);
            if(k){
                cout << "!" << " " << s1; nl;
                fflush(stdout);
                return;
            }
            cout << "!" << " " << s2; nl;
            fflush(stdout);
            return;
        }
    }
    string x;
    int suf, cnt, prf;
    for(i = n - 1, cnt = 0; i >= 0 && !mark[i]; i--){ cnt++; } suf = i;
    if(res[suf] == 'H' || res[suf] == 'C'){
        for(i = suf + 1; i < n; i++){ mark[i] = true, res[i] = res[suf]; }
    }
    else if(res[suf] == 'O'){
        for(i = suf + 1; i < n - 1; i++){ mark[i] = true, res[i] = res[suf]; }
    }


    for(i = 0; i < n && !mark[i]; i++); prf = i;
    for(i = 0, x = ""; i < prf; i++){ x += 'O'; }
    for(; i < n - 1; i++){ x += res[i]; }
    interaction2(x);
    if(!k){
        for(i = 0, x = ""; i < prf; i++){ x += res[prf]; }
        for(; i < n - 1; i++){ x += res[i]; }
    }
    if(mark[n - 1]){
        x += res[n - 1];
        cout << "!" << " " << x; nl;
        fflush(stdout);
        return;
    }
    interaction2(x + "O");
    if(k){
        cout << "!" << " " << x + "O"; nl;
        fflush(stdout);
        return;
    }
    interaction2(x + "C");
    if(k){
        cout << "!" << " " << x + "C"; nl;
        fflush(stdout);
        return;
    }
    cout << "!" << " " << x + "H"; nl;
    fflush(stdout);
    return;
}
void solve1(){
    int i, j, l, cnt;
    char st[] = {'C', 'H', 'O'};
    for(i = 0; i < 4; i++){
        interaction2(str[i]);
        for(j = 0; j < k; j++){
            for(l = 0; l < str[i].size(); l++){
                mark[ara[j] + l] = true, res[ara[j] + l] = str[i][l];
            }
        }
    }
    for(i = cnt = 0; i < n; i++){ cnt += mark[i]; }
    if(cnt == 0){
        for(i = 4; i <= 5; i++){
            interaction2(str[i]);
            for(j = 0; j < k; j++){
                for(l = 0; l < str[i].size(); l++){
                    mark[ara[j] + l] = true, res[ara[j] + l] = str[i][l];
                }
            }
        }
        for(i = cnt = 0; i < n; i++){ cnt += mark[i]; }
        if(cnt == 0){
            string s = "";
            for(i = 0; i < n - 1; i++){ s += "O"; }
            interaction2(s);
            if(k == 2){
                cout << "!" << " " << s + "O"; nl;
                fflush(stdout);
                return;
            }
            else if(k == 1){
                interaction2(s + "C");
                if(k){
                    cout << "!" << " " << s + "C"; nl;
                    fflush(stdout);
                    return;
                }
                cout << "!" << " " << s + "H"; nl;
                fflush(stdout);
                return;
            }
            else{
                string s1 = "", s2 = "";
                for0(i, n){ s1 += "C"; s2 += "H"; }
                interaction2(s1);
                if(k){
                    cout << "!" << " " << s1; nl;
                    fflush(stdout);
                    return;
                }
                cout << "!" << " " << s2; nl;
                fflush(stdout);
                return;
            }
        }
    }
    if(cnt == 2){
        int idx, bg = INF;
        bool f = false;
        string s = "";
        for(i = 0; i < n; i++){
            if(!mark[i]){
                if(i - 1 >= 0 && mark[i - 1]){ idx = i; break; }
                if(i + 1 <= n - 1 && mark[i + 1]){ idx = i; break; }
            }
        }
        for(i = 0, bg = idx; i < n; i++){
            if(mark[i]){ bg = min(bg, i); }
        }
        for(i = f = 0; i < 2; i++){
            for(j = 0, s = ""; j < n; j++){
                if(j == idx){ s += st[i]; continue; }
                if(mark[j]){ s += res[j]; }
            }
            interaction2(s);
            if(k){
                for(j = 0; j < k; j++){
                    if(ara[j] == bg){ f = true; break; }
                }
            }
            if(f){ break; }
        }
        if(f){ res[idx] = st[i], mark[idx] = true; }
        else{ res[idx] = st[2], mark[idx] = true; }
        for(i = cnt = 0; i < n; i++){ cnt += mark[i]; }
    }
    if(cnt == 3){
        string s = "";
        int idx;
        bool f = false;
        for(i = f = 0; i < 2; i++){
            for(j = 0, s = ""; j < n; j++){
                if(mark[j]){ s += res[j]; }
                else{ s += st[i]; idx = j; }
            }
            interaction2(s);
            if(k){ f = true; break; }
        }
        if(f){ res[idx] = st[i], mark[idx] = true; }
        else{ res[idx] = st[2], mark[idx] = true; }
        for(i = cnt = 0; i < n; i++){ cnt += mark[i]; }
    }
    if(cnt == 4){
        string s = "";
        for(i = 0; i < n; i++){ s += res[i]; }
        cout << "!" << " " << s; nl;
        fflush(stdout);
        return;
    }
}
int main(){




    int cs, ts, v;
    si(ts);
    for0(cs, ts){
        sum = 0.0;
        input();
        if(n >= 5){
            solve2();
        }
        else{
            solve1();
        }
        si(v);
        if(v == 1){ continue; }
        else{ break; }
    }
}
