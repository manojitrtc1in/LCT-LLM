#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<ctype.h>
#include<string>
#include<cstring> 

#include<bits/stdc++.h>

using namespace std;

#define fo(i, n)   for (int i = 0; i < n; i++)
#define Fo(i, k, n)   for (int i = k; k < n ? i < n : i > n; k < n ? i+=1 : i-=1)
#define ll long long
#define inf    1e18
#define setbits(x)  __builtin_popcountll(x) 

#define zrobits(x)  __builtin_ctzll(x) 

#define pb     push_back
#define eb     emplace_back
#define F      first
#define S      second
#define all(X) x.begin(), x.end()
#define tr(it, a)  for (auto it = a.begin(); it != a.end(); it++) 



typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int mod = 1e9 + 7;
const long long MAX_SIZE = 1000001;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};



















struct Node{
    int val;
    vector<Node*> children;

    Node(int x) {
        val = x;
    }
};

struct info{
    int i;
    int j;
    vector<int> path;
};

struct greaters {
    bool operator()(const long& a, const long& b) const {
        return a > b;
    }
};

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        

          return hash1;
    }
};

void input(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
}

void inputChar(char *a, int n) {
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
}

void inputStr(string *s, int n) {
    fo(i, n) {
        cin >> s[i];
    }
}

void inputStrMat(string **s, int m, int n) {
    fo(i, m) {
        fo(j , n) {
            cin >> s[i][j];
        }
    }
}

void inputCharMat(char **a, int m, int n) {
    fo(i, m) {
        fo(j, n) {
            cin >> a[i][j];
        }
    }
}

void inputMat(int **a, int m, int n) {
    fo(i, m) {
        fo(j, n) {
            cin >> a[i][j];
        }
    }
}

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}




int getX(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                x ^= a[j];
            }
        }
        

        if (x == a[i]) return x;
    }
    return 0;
}


int problemB(int *a, int n, int k) {
    int cnt = 0;
    if (k == 1) return (n - 1) / 2;
    else {
        for (int i = 1; i < n - 1; i++) cnt += (a[i] > a[i - 1] + a[i + 1]) ? 1 : 0;
    }
    return cnt;
}


string problemC(int *a,  int n) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]]++;
    vector<int> pos, neg, arr;
    

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if(a[i] > 0) pos.push_back(a[i]);
            else if (a[i] < 0) neg.push_back(a[i]);
        } else {
            if (arr.size() < 2) arr.push_back(a[i]);
        }
    }
    if (pos.size() > 2 || neg.size() > 2) return "no";
    for (int i : pos) arr.push_back(i);
    for (int i : neg) arr.push_back(i);
    int l = arr.size();
    for (int i = 0; i < l - 2; i++) {
        for (int j = i + 1; j < l - 1; j++) {
            for (int k = j + 1;  k < l; k++) {
                int val = arr[i] + arr[j] + arr[k];
                if (!mp.count(val)) return "no";
            }
        }
    }
    return "yes";
}






void d() {
    int n;
    cin >> n;
    vector<string> s(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        mp[s[i]] = 1;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        bool flag = 0;
        for (int j = 0; j< s[i].length(); j++) {
            string pref = s[i].substr(0, j + 1);
            string suf = s[i].substr(j + 1, s[i].length() - j - 1);
            if (mp.count(pref) && mp.count(suf)) flag = 1;
        }
        cout << flag;
    }
    cout << endl;
}


void e() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++ ) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            

            int r = i, c = j;
            int prevC = c;
            int sum = a[r][c];
            c = n - r - 1;
            r = prevC;
            sum += a[r][c]; 

            prevC = c;
            c = n - r - 1;
            r = prevC;
            sum += a[r][c]; 

            prevC = c;
            c = n - r - 1;
            r = prevC;
            sum += a[r][c]; 

            ans += min(sum, 4 - sum);
        }
    }
    cout << ans << endl;
}


void f() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<ll, ll>> p;
    for (int i = 0; i < n; i++) {
        if (a[i] < i + 1) p.push_back({a[i], i + 1});
    }
    int len = p.size();
    

    

    

    

    int cnt = 0;
    for (int i = 0; i < len; i++) {
        ll num = p[i].second;
        

        for (int j = 0; j < len; j++) {
            if (j != i) {
                

                if (p[j].first > num) cnt++;
            }
        }
    }
    cout << cnt << endl;
}


void g() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll> (2, 0));
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i - 1] - k;
        dp[i][1] = dp[i - 1][1] + floor(a[i - 1] / 2);
    }
    cout << "show dp" << endl;
    for(vector<ll> v : dp) {
        for (ll i : v) cout << i << " ";
        cout << endl;
    }
    int ans = max(dp[n][0], dp[n][1]);
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--) {
        d();
    }
}










