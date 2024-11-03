































































































































using namespace std;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool sorta(const pii &a, const pii &b) { return (a.second < b.second); }
bool sortd(const pii &a, const pii &b) { return (a.second > b.second); }
string id8(int n) {
    string s = "" ;
    int i = 0;
    while (n > 0) {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll id4(string n) {
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
bool id2(int n) {
    if (n == 0) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool id6(ll x) {
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
ll id7(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll id3(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}


ll id1(ll x)
{
    ll left = 0, right = 2000000123;
    while (right > left)
    {
        ll mid = (left + right) / 2;

        if (mid * mid > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}

int id0(vector<vector<ll>>&v,int i,int j){
    int count=0;
    for(int k=0;k<5;k++){
        if(v[i][k]<v[j][k]){
            count++;
        }
    }

    if(count>=3){
        return i;
    }
    return j;
}

int ps(vector<vector<ll>>&v,int n){

    int j=1;

    for(int i=2;i<=n;i++){
        j=id0(v,i,j);


    }

    for(int i=1;i<=n;i++){
        int temp=id0(v,i,j);
        if(temp!=j){
            return -1;
        }
    }

    return j;

}


int main() {
    Meyank Garg id5;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<vector<ll>>v(n+1,vector<ll>(6));
        for(int i=1;i<=n;i++){

            for(int j=0;j<5;j++){
                cin>>v[i][j];
            }

        }
        cout<<ps(v,n)<<endl;


    }
    return 0;
}