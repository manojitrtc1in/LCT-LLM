#include <bits/stdc++.h>

using namespace std;

#define mem(n,i)    memset(n,i,sizeof (n));
typedef long long ll;
typedef pair<int, int> pii;










     bool prime(int n) {
    if (n <= 1) return false;
    if (n == 2)return true;
    for (int x = 2; x * x <= n; x++) {
        if (n % x == 0) return false;
    }
    return true;
}










struct node {
    int value;
    node * right;
    node * left;
};


















int searh(ll l, ll r, ll target, int siz) {
    ll m = l + (r - l) / 2LL;
    if (m > target)
        return searh(l, m - 1, target, siz - 1);
    else if (m < target)
        return searh(m + 1, r, target, siz - 1);
    else
        return siz;
}

int findGCD(int a[], int n) {
    int res = a[0];
    for (int i = 1; i < n; i++) {
        res = __gcd(res, a[i]);
    }
    return res;
}

bool palindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] == s[s.length() - 1 - i])continue;
        else return false;
    }
    return true;
}


bool compar1(pair<int, int>s, pair<int, int>t) {
    if(s.first>t.first)return true;
    if(s.first==t.first && s.second<t.second)return true;
    else return false;
}

bool compar2(int s, int t) {
    if(s%2 && t%2==0 && s<t)return true;
    if(s%2==0 && t%2 && s<t)return true;
    else return false;
}

int dot(pii a, pii b) {
    return a.first * b.first + a.second + b.second;
}

pii mackvec(int x, int y, pii t) {
    pii ret;
    ret.first = t.first - x;
    ret.second = t.second - y;
    return ret;
}

bool isIn(vector<pii>v, pii t) {
    for (auto c : v) {
        if (c.first == t.first && c.second == t.second)return true;
    }
    return false;
}

bool istwinempty(string t, string s[], int n) {
    for (int i = 0; i < n; i++) {
        if (t.find(s[i]) != string::npos)return false;
    }
    return true;
}




int n;
int counter = 0;
int cnt[27];
string s;

bool valid() {
    return (counter == 26);
}

void fill() {
    for (int i = 0; i < n; i++) {
        if (s[i] == '?')s[i] = 'A';
    }
}

int retdigit(int n) {
    int ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

bool check(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == -1)continue;
        else return false;
    }
    return true;
}
const int INF=1e9+7;
const long long INFL=1e18+1e6;
const int MAX = 1e5 + 100;

int main() {
    int n;cin>>n;
    string a,b;cin>>a>>b;
    ll one=0,zero=0,k=0,l=0;
    for(int i=0;i<n;i++){
        if(b[i]=='0' && a[i]=='0')zero++;
        if(b[i]=='0' && a[i]=='1')one++;
        if(b[i]=='1' && a[i]=='0')k++;
        if(b[i]=='1' && a[i]=='1')l++;
    }
    ll ans=zero*one+zero*l+one*k;
    cout<<ans;
}
