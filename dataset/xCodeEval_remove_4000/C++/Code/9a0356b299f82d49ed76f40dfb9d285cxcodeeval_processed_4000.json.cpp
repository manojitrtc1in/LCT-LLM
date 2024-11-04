


using namespace std;














const long long M=1e9+7;
typedef long long ll;
typedef long long ll;
typedef pair<int, int> pii;
long long mul(long long x, long long y){ return ((x%M)*(y%M)%M); }
long long binpow(long long x, long long y){ long long z=1; while(y){ if(y&1LL) z=mul(z, x); x = mul(x, x); y >>= 1LL; } return z; }
long long inv(long long x){ return binpow(x, M - 2); }
long long divide(long long x, long long y){ return mul(x, inv(y)); }

int main(void){
    int n, num=0, ans=0; cin >> n;
    vector<int> l(n), r(n), cnt(n);
    for(int i=0; i<n; ++i){
        cin >> l[i] >> r[i];
    }   

    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(l[i]<r[j]&&l[j]<r[i]){
                ++num;
                ++cnt[i];
                ++cnt[j];
            }
        }
    }
    for(int i=0; i<n; ++i){
        if(cnt[i]==num)++ans;
    }
    cout << ans << ends;
    for(int i=0; i<n; ++i){
        if(cnt[i]==num) cout << i+1 << sp;
    }

}
