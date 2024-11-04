#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define mod 1000000007 
#define set(n) cout << fixed << setprecision(n)
#define fi first
#define se second
#define pll pair<lli, lli>

const double PI = acos(-1);

struct myHash { 

    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const{ 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

class segTree { 

    vector<lli> a; 

    vector<lli> tree; 

    vector<lli> lazy;
    lli sel;

    lli minRange(lli left, lli right){
        return min(left, right);
    }

    lli maxRange(lli left, lli right){
        return max(left, right);
    }

    lli rangeSum(lli left, lli right){
        return left + right;
    }

    void build(lli index, lli start, lli end){
        if(start > end){
            return;
        }
        if(start == end){
            tree[index] = a[start];
            return;
        }
        lli mid = (start + end) / 2;
        build(2 * index, start, mid);
        build(2 * index + 1, mid + 1, end);
        lli left = tree[2 * index];
        lli right = tree[2 * index + 1];
        if(sel == 0){
            tree[index] = minRange(tree[2 * index], tree[2 * index + 1]);
        }
        else if(sel == 1){
            tree[index] = maxRange(tree[2 * index], tree[2 * index + 1]);
        }
        else if(sel == 2){
            tree[index] = rangeSum(tree[2 * index], tree[2 * index + 1]);
        }
    }

    lli query(lli index, lli start, lli end, lli l, lli r){
 
        if(lazy[index] != 0){
            if(sel == 0){
                tree[index] += lazy[index];
            }
            else if(sel == 1){
                tree[index] += lazy[index];
            }
            else if(sel == 2){
                tree[index] += (end - start + 1) * lazy[index];
            }

            if(start != end){
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
            }
            lazy[index] = 0;
        }

        if(l > end || r < start){
            if(sel == 0){
                return LLONG_MAX;
            }
            else if(sel == 1){
                return LLONG_MIN;
            }
            else if(sel == 2){
                return 0;
            }
        }

        if(start >= l && end <= r){
            return tree[index];
        }
        lli mid = (start + end) / 2;
        lli left = query(2 * index, start, mid, l, r);
        lli right = query(2 * index + 1, mid + 1, end, l, r);
        if(sel == 0){
            return minRange(left, right);
        }
        else if(sel == 1){
            return maxRange(left, right);
        }
        else if(sel == 2){
            return rangeSum(left, right);
        }
    }

    void update(lli index, lli start, lli end, lli l, lli r, lli inc){

        if(lazy[index] != 0){  

            if(sel == 0){
                tree[index] += lazy[index];
            }
            else if(sel == 1){
                tree[index] += lazy[index];
            }
            else if(sel == 2){
                tree[index] += (r - l + 1) * lazy[index];
            }

            if(start != end){
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
            }
            lazy[index] = 0;
        }

        if(l <= start and end <= r){
            if(sel == 0){
                tree[index] += inc;
            }
            else if(sel == 1){
                tree[index] += inc;
            }
            else {
                tree[index] += (end - start + 1) * inc;
            }
            if(start != end){
                lazy[2 * index] += inc;
                lazy[2 * index + 1] += inc;
            }
            return;
        }

        if(r < start || l > end){
            return;
        }
        if(start == end){
            tree[index] += inc;
            return;
        }
        lli mid = (start + end) / 2;
        update(2 * index, start, mid, l, r, inc);
        update(2 * index + 1, mid + 1, end, l, r, inc); 
        if(sel == 0){
            tree[index] = minRange(tree[2 * index], tree[2 * index + 1]);
        }
        else if(sel == 1){
            tree[index] = maxRange(tree[2 * index], tree[2 * index + 1]);
        }
        else if(sel == 2){
            tree[index] = rangeSum(tree[2 * index], tree[2 * index + 1]);
        }
    }

public : 
    segTree(vector<lli> a, lli sel){
        this->a = a;
        tree.reserve(4 * a.size() + 1);
        lazy.reserve(4 * a.size() + 1);
        for(int i = 0; i < 4 * a.size() + 1; i++){
            lazy[i] = 0;
        }
        this->sel = sel;
    }

    void build(){
        build(1, 0, a.size() - 1);
    }

    long long int query(lli l, lli r){
        return query(1, 0, a.size() - 1, l, r);
    }

    void update(lli l, lli r, lli inc){
        update(1, 0, a.size() - 1, l, r, inc);
    }

    void update(lli pos, lli inc){
        update(pos, pos, inc);
    }

};

lli power(lli b, lli p, lli m = mod){
    lli res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * b) % m;
        }
        b = (b * b) % m;
        p = p>>1;
    }
    return res;
}

lli modInverse(lli n, lli m = mod){
    return power(n, m - 2, m);
}

bool mySort(pair<int, int> p1, pair<int, int> p2){ 

    if(p1.first < p2.first){
        return true;
    }
    else if(p1.first == p2.first and p1.second < p2.second){
        return true;
    }
    return false;
}

lli lis(vector<lli> & v){
    lli n = v.size();
    vector<lli> dp(n);
    dp[0] = 1;
    lli ans = 1;
    for(int i = 1; i < n; i++){
        lli m = 0;
        for(int j = i - 1; j >= 0; j--){
            if(v[j] < v[i]){
                m = max(m, dp[j]);
            }
        }
        dp[i] = 1 + m;
        if(ans < dp[i]){
            ans = dp[i];
        }
    }
    return ans;
}

vector<lli> sieve(lli n){ 

    vector<bool> v(n + 1, false);
    v[2] = true;
    for(int i = 3; i <= n; i += 2){
        v[i] = true;
    }
    for(int i = 3; i <= n; i += 2){
        if(v[i]){
            for(int j = i * i; j <= n; j += 2 * i){
                v[j] = false;
            }
        }
    }
    v[1] = false;
    v[0] = false;
    vector<lli> primes;
    for(int i = 0; i < v.size(); i++){
        if(v[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

lli gcd(lli a, lli b){
    while(b > 0){
        lli r = a % b;
        a = b;
        b = r;
    }
    return a;
}

lli lcm(lli a, lli b){
    lli g = gcd(a, b);
    return (a * b) / g;
}

vector<lli> segSieve(lli l, lli r){ 

    lli lim = sqrt(r);
    if(l < 2){
        l = 2;
    }
    vector<lli> s = sieve(lim);
    vector<bool> v(r - l + 1, true);
    for(lli i = 0; i < s.size(); i++){
        for(lli j = 0; j < v.size(); j++){
            if((j + l) % s[i] == 0 && (j + l) != s[i]){
                v[j] = false;
            }
        }
    }
    vector<lli> primes;
    for(int i = 0; i < v.size(); i++){
        if(v[i]){
            primes.push_back(i + l);
        }
    }
    return primes;
}

vector<pair<lli, lli>> primeFactors(lli n){ 

    vector<lli> primes = sieve(sqrt(n));
    lli p = primes[0];
    vector<pair<lli, lli>> f;
    int i = 0;
    while(p * p <= n){
        lli count = 0;
        while(n % p == 0){
            count++;
            n /= p;
        }
        if(count > 0){
            f.push_back(make_pair(p, count));
        }
        i++;
        p = primes[i];
    }
    if(n > 1){ 

        f.push_back(make_pair(n, 1));
    }
    return f;
}

vector<lli> factors(lli n){ 

    lli lim = sqrt(n);
    vector<lli> f;
    for(int i = 2; i <= lim; i++){
        if(n % i == 0){
            f.push_back(i);
            f.push_back(n / i);
        }
    }
    return f;
}

lli ceilAB(lli a, lli b){
    return (a + b - 1) / b;
}

vector<lli> KMP(string & txt, string & pat){ 

    lli n = txt.length();
    lli m = pat.length();
    vector<lli> v;
    if(m > n){
        return v;
    }
    vector<lli> sp(m);
    sp[0] = 0;
    int i = 1;
    lli len = 0;
    while(i < m){
        if(pat[i] == pat[sp[i - 1]]){  

            len++;
            sp[i] = len;
            i++;
        }
        else {
            if(len == 0){
                sp[i] = 0;
                i++;
            }
            else {
                len = sp[len - 1]; 

            }
        }
    }
    int j = 0;
    i = 0;
    while(i < n){
        if(txt[i] == pat[j]){
            j++;
            i++;
        }
        if(j == m){
            v.push_back(i - j);  

            j = sp[j - 1];
        }
        else if(i < n && txt[i] != pat[j]){
            if(j != 0){
                j = sp[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return v;
}

lli low_bound(vector<lli> & v, lli start, lli end, lli n){ 

    if(start > end){
        return -1;
    }
    lli mid = (start + end) / 2;
    if(v[mid] == n){
        return mid;
    }
    else if(v[mid] > n){
        lli index = low_bound(v, start, mid - 1, n);
        return index;
    }
    else {
        lli index = low_bound(v, mid + 1, end, n);
        if(index == -1){
            return mid;
        }
        return index;
    }
}

inline void fastIO(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
}

lli solve(string & s, string & t, lli i, lli j, lli k, lli sel, vector<vector<vector<vector<lli>>>> & dp){
    
    if(i == s.length() or j == t.length()){
        if(k == 0 || k == 1){
            return 0;
        }
        else {
            return LLONG_MIN;
        }
    }
    if(k == 0){
        return 0;
    }
    if(dp[i][j][k][sel] >= 0){
        return dp[i][j][k][sel];
    }
    lli ans;
    if(sel == 0){
        lli op1, op2, op3;
        if(s[i] == t[j]){
            op1 = 1 + solve(s, t, i + 1, j + 1, k, 1, dp);
        }
        else {
            op1 = 0;
        }
        op2 = solve(s, t, i + 1, j, k, 0, dp);
        op3 = solve(s, t, i, j + 1, k, 0, dp);
        ans = max(op1, max(op2, op3));
    }
    else {
        lli op1, op2, op3, op4, op5, op6;
        if(s[i] == t[j]){
            op1 = 1 + solve(s, t, i + 1, j + 1, k, 1, dp);
            op4 = 1 + solve(s, t, i + 1, j + 1, k - 1, 1, dp);
        }
        else {
            op1 = 0;
            op4 = 0;
        }
        op2 = solve(s, t, i, j + 1, k - 1, 0, dp);
        op3 = solve(s, t, i + 1, j, k - 1, 0, dp);
        ans = max(op1, max(op2, max(op3, op4)));
    }
    return dp[i][j][k][sel] = ans;
}


int main(void){
    

    lli n, m, k;
    cin>>n>>m>>k;
    string s, t;
    cin>>s;
    cin>>t;
    lli dp[n + 1][m + 1][k + 1][2] = {0};
    for(int i = 0; i <= n; i++){
        for(int j= 0; j <= m; j++){
            for(int y = 0; y < 2; y++){
                dp[i][j][0][y] = 0;
            }
        }
    }
    for(int j = 0; j <= m; j++){
        for(int x = 0; x <= k; x++){
            for(int y = 0; y < 2; y++){
                if(x <= 1){
                    dp[0][j][x][y] = 0;
                }
                else {
                    dp[0][j][x][y] = LLONG_MIN;
                }
            }
        }
    }

    for(int i = 0; i <= n; i++){
        for(int x = 0; x <= k; x++){
            for(int y = 0; y < 2; y++){
                if(x <= 1){
                    dp[i][0][x][y] = 0;
                }
                else {
                    dp[i][0][x][y] = LLONG_MIN;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int x = 1; x <= k; x++){
                for(int y = 0; y < 2; y++){
                    if(y == 0){
                        lli op1, op2, op3;
                        if(s[i - 1] == t[j - 1]){
                            op1 = 1 + dp[i - 1][j - 1][x][1];
                        }
                        else {
                            op1 = 0;
                        }
                        op2 = dp[i][j - 1][x][0];
                        op3 = dp[i - 1][j][x][0];
                        dp[i][j][x][y] = max(op1, max(op2, op3));
                    }
                    else {  
                        lli op1, op2, op3, op4;
                        if(s[i - 1] == t[j - 1]){
                            op1 = 1 + dp[i - 1][j - 1][x][1];
                            op4 = 1 + dp[i - 1][j - 1][x - 1][1];
                        }
                        else {
                            op1 = 0;
                            op4 = 0;
                        }
                        op2 = dp[i][j - 1][x - 1][0];
                        op3 = dp[i - 1][j][x - 1][0];
                        dp[i][j][x][y] = max(op1, max(op2, max(op3, op4)));
                    }

                }
            }
        }
    }
    cout<<dp[n][m][k][0]<<endl;
    return 0;
}