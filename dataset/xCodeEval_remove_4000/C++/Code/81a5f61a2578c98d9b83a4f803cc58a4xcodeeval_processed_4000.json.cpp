































































































































using namespace std;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool sorta(const pii &a, const pii &b) { return (a.second < b.second); }
bool sortd(const pii &a, const pii &b) { return (a.second > b.second); }
string id7(int n) {
    string s = "" ;
    int i = 0;
    while (n > 0) {
        s = to_string(n % 2) + s;
        n = n / 2;
        i++;
    }
    return s;
}
ll id3(string n) {
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
bool id1(int n) {
    if (n == 0) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool id5(ll x) {
    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
ll id6(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll id2(ll x, ll y, ll p) {
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


ll id0(ll x)
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

bool ps(int n,int a,int b){

    if(b==1){
        return true;

    }
    if(a==1){
        return (n-1)%b == 0;
    }

    ll num=1;
    while(num<=n){
        if((n-num)%b ==0 ){
            return true;
        }
        num*=a;
    }

    return false;



}


int main() {
    Meyank Garg id4;
    ll t;
    cin >> t;
    while (t--) {
        int n,a,b;
        cin>>n>>a>>b;
        if(ps(n,a,b)){
            py;
        }else{
            pn;
        }

    }
    return 0;
}