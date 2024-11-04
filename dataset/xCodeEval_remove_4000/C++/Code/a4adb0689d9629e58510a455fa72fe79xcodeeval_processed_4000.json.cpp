

using namespace std;


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


















int id3(ll l, ll r, ll target, int siz) {
    ll m = l + (r - l) / 2LL;
    if (m > target)
        return id3(l, m - 1, target, siz - 1);
    else if (m < target)
        return id3(m + 1, r, target, siz - 1);
    else
        return siz;
}

int id1(int a[], int n) {
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
    return s.first < t.first;
}
bool compar2(pair<int, int>s, pair<int, int>t) {
    return s.first > t.first;
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

bool id0(string t, string s[], int n) {
    for (int i = 0; i < n; i++) {
        if (t.find(s[i]) != string::npos)return false;
    }
    return true;
}
const int MAX = 3 * 1e5 + 100;




int n;
int counter=0;
int cnt[27];
string s;
bool valid(){
    return (counter==26);
}
void fill(){
    for(int i=0;i<n;i++){
        if(s[i]=='?')s[i]='A';
    }
}
int id2(int n){
    int ret=0;
    while(n>0){
        ret+=n%10;
        n/=10;
    }
    return ret;
}
int main() {
    int n,s;cin>>n>>s;
    int ans=0;bool flag=0;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        if(x<s && y){ans=max(ans,100-y);flag=1;}
        else if(x<=s && y==0){flag=1;}
    }
    if(flag)cout<<ans;
    else cout<<-1;
}
