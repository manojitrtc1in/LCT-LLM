














using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;








int gcd(int x, int y){
    if (y == 0){
        return x;
    } else {
        return gcd(y, x % y);
    }
}

int quickPower(int a, int b)

{
    int ans = 1, base = a;

    while(b > 0)

        {
        if(b & 1)

            ans *= base;


            base *= base;

            b >>= 1;

        }
    return ans;
}
bool cmp(ld x,ld y){
    if (abs(x-y)<=1e-9)
        return true;
    return false;
}

ld Power(ld base,int exponent){
    ld sum=1;
    ld curr=base;
    int n;
    if(exponent>0)
        n=exponent;
    else if(exponent<0){
        if(base==0)
            exit(EXIT_FAILURE);
        n=-exponent;
    }
    else if(exponent==0){
        return 1;
    }
    while(n !=0){
        if((n&1)==1)
            sum*=curr;
        curr*=curr;
        n>>=1;
    }
    return (exponent>0)?sum : (ld ( 1)/ sum);
}



map<ll, int>cnt;
bool check(ll res){
    if (cnt.count(res) && cnt[res] > 0){
        cnt[res]--;
        return true;
    }
    if (res <= 1)
        return false;
    return check(res / 2) && check((res + 1) / 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<int>a(n);
        cnt.clear();
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            cnt[a[i]]++;
        }
        cout << ((check(sum))?"YES":"NO") << endl;
    }
    return 0;
}