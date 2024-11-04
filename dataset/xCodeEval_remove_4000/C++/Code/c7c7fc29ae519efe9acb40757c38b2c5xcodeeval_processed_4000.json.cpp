




















using namespace std;








typedef vector<int> vi;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef double db;

mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }

template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void resize_array(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void resize_array(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) resize_array(v, args...); }

template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }


ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


template<uint MD>
struct ModInt
{
    using M = ModInt;
    uint v;
    ModInt(ll _v = 0) { set_v(uint(_v % MD + MD)); }
    M &set_v(uint _v)
    {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M &r) const { return M().set_v(v + r.v); }
    M operator-(const M &r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M &r) const { return M().set_v(uint(ull(v) * r.v % MD)); }
    M operator/(const M &r) const { return *this * r.inv(); }
    M &operator+=(const M &r) { return *this = *this + r; }
    M &operator-=(const M &r) { return *this = *this - r; }
    M &operator*=(const M &r) { return *this = *this * r; }
    M &operator/=(const M &r) { return *this = *this / r; }
    bool operator==(const M &r) const { return v == r.v; }
    M pow(ll n) const
    {
        M x = *this, r = 1;
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream &operator<<(ostream &os, const M &r) { return os << r.v; }
};
constexpr unsigned int mod = 998244353;
using Mint = ModInt<mod>;


Mint primitive_root = 3;  




void ntt(vector<Mint> &a, int type) {
    static vector<int> id3;
    static Mint wn[18][1<<17+1];
    static Mint wn_inv[18][1<<17+1];
    if (id3.size() != a.size()) {
        

        int bit_num = 0;
        int size = 1;
        while (size < a.size()) {
            size <<= 1;
            bit_num++;
        }
        assert(a.size() == size);
        id3.resize(size);
        id3[0] = 0;
        for (int i = 1; i < id3.size(); ++i) {  

            id3[i] = (id3[i >> 1] >> 1) | ((i & 1) << (bit_num - 1));
        }
    }

    for (int i = 0; i < id3.size(); ++i) {
        

        if (i < id3[i])
            swap(a[i], a[id3[i]]);
    }

    

    int level=0;
    for (int mid = 1; mid < a.size(); mid <<= 1) {
        

        if (wn[level][1] == 0) {
            wn[level][0] = 1;
            wn_inv[level][0] = 1;
            wn[level][1] = primitive_root.pow((mod - 1) / (mid << 1));  

            wn_inv[level][1] = wn[level][1].inv();
            rep(x,2,mid) {
                wn[level][x] = wn[level][x-1] * wn[level][1];
                wn_inv[level][x] = wn[level][x].inv();
            }
        }
        
        Mint(*id0)[1<<17+1] = wn;
        if (type == -1)
            id0 = wn_inv;
            

        for (int len = mid << 1, pos = 0; pos < a.size(); pos += len) {
            

            


            for (int k = 0; k < mid; ++k) {

                

                Mint x = a[pos + k];            

                

                Mint y = id0[level][k] * a[pos + mid + k];  

                a[pos + k] = x + y;             

                a[pos + mid + k] = x - y;       

            }
        }
        level++;
    }

    if (type == 1)
        return;
    Mint sz_inv = Mint(a.size()).inv();
    for (int i = 0; i < a.size(); ++i) {
        

        a[i] *= sz_inv;
    }
}

vector<Mint> id2(const vector<Mint>& _a, const vector<Mint>& _b) {
    

    

    

    int n=_a.size()-1, m=_b.size()-1;

    int size = 1;
    while (size <= n + m) {
        size <<= 1;
    }
    vector<Mint> a(size, 0), b(size, 0);
    for(int i=0;i<_a.size();++i) a[i] = _a[i];
    for(int i=0;i<_b.size();++i) b[i] = _b[i];

    

    dbg(a);
    dbg(b)
    ntt(a, 1);
    ntt(b, 1);
    for (int i = 0; i < a.size(); ++i) a[i] = a[i] * b[i];
    ntt(a, -1);
    dbg(a);
    


    return a;
}

class Solution
{
private:
    static const int MAXN = 1e5+10;
    Mint factorial[MAXN];
public:
    Solution() {
        factorial[0] = 1;
        rep(i,1,MAXN) {
            factorial[i] = factorial[i-1]*i;
        }
    }
    

	

	

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

                
    

    

    

	

    

	

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

                
    

    

    

	

    void Solve()
	{
        int n;
        while(cin>>n) {
            vi tmp(n);
            rep(i,0,n) cin>>tmp[i];
            vi stair;
            for(int i=0;i<n;i+=tmp[i]) {
                for(int j=i;j<i+tmp[i];j++) {
                    if (tmp[j] != tmp[i]) {
                        stair.push_back(-1);
                        break;
                    }
                }
                if(stair.size() > 0 && stair.back()==-1) break;
                stair.push_back(tmp[i]);
            }
            if(stair.back()==-1) {
                cout<<0<<endl;
            } else {
                

                struct Node {
                    Node() {
                        a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
                    }
                    Mint* operator[](int idx) {
                        return a[idx];
                    }
                    void bzero() {
                        a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
                    }
                    Mint a[2][2];
                };
                vector<Node > dp[2];
                dp[0].resize(stair.size());
                dp[1].resize(stair.size());
                

                rep(stair_id, 0, stair.size()) {
                    if(stair[stair_id] == 1) {
                        dp[0][stair_id*1+0][1][1] = 1;
                    } else if(stair[stair_id] > 1) {
                        dp[0][stair_id*1+0][0][0] = 2;
                    }
                }
                int pre=0, cur=1;
                for (int id1 = 1; id1 < stair.size(); id1 <<= 1) {
                    rep(i,0,dp[cur].size()) {
                        dp[cur][i].bzero();
                    }
                    for(int i=0;i<dp[pre].size();i+=(id1*2)) {
                        if (i+id1<dp[pre].size()) {
                            vector<Mint> a[2];
                            a[0].resize(id1, 0);
                            a[1].resize(id1, 0);
                            rep(tlr,0,2) {
                                rep(j,i,min(i+id1, (int)dp[pre].size())) {
                                    a[0][j-i] += dp[pre][j][0][tlr];
                                    a[1][j-i] += dp[pre][j][1][tlr];
                                }
                            }
                            vector<Mint> b[2];
                            b[0].resize(id1, 0);
                            b[1].resize(id1, 0);
                            rep(trl,0,2) {
                                rep(j,i+id1,min(i+2*id1, (int)dp[pre].size())) {
                                    b[0][j-i-id1] += dp[pre][j][trl][0];
                                    b[1][j-i-id1] += dp[pre][j][trl][1];
                                }
                            }
                            vector<Mint> ans(id1 << 1);
                            rep(tll,0,2) {
                                rep(trr,0,2) {
                                    ans = id2(a[tll], b[trr]);
                                    rep(j,i,min(i+2*id1-1, (int)dp[pre].size())) {
                                        dp[cur][j][tll][trr] += ans[j-i];
                                        

                                        

                                        

                                    }
                                }
                            }

                            rep(tll,0,2) {
                                rep(tlr,0,2) {
                                    rep(trl,0,2) {
                                        rep(trr,0,2) {
                                            fill(a[0].begin(), a[0].end(), 0);
                                            fill(b[0].begin(), b[0].end(), 0);
                                            rep(j,i,min(i+id1, (int)dp[pre].size())) {
                                                a[0][j-i] = dp[pre][j][tll][tlr];
                                            }
                                            rep(j,i+id1,min(i+2*id1, (int)dp[pre].size())) {
                                                b[0][j-i-id1] = dp[pre][j][trl][trr];
                                            }
                                            ans = id2(a[0], b[0]);
                                            Mint coeff = 1;
                                            if (tlr == 1 && trl == 1) coeff = 2;
                                            if (tlr == 0 && trl == 0) coeff = 499122177;

                                            rep(j,i+1,min(i+2*id1, (int)dp[pre].size())) {
                                                if (id1 == 1)
                                                    dp[cur][j][0][0] += (ans[j-i-1]*coeff);
                                                else
                                                    dp[cur][j][tll][trr] += (ans[j-i-1]*coeff);
                                                

                                                

                                                

                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            rep(j,i,dp[pre].size()) {
                                dp[cur][j] = dp[pre][j];
                            }
                        }
                    }

                    swap(pre, cur);
                }

                Mint ans = 0;
                int id1 = stair.size();
                for(int i=0;i<stair.size();++i) {
                    if(i&1) {
                        rep(tl,0,2){
                            rep(tr,0,2){
                                ans -= (dp[pre][i][tl][tr]* factorial[id1 - i]);
                                

                            }
                        }
                    } else {
                        rep(tl,0,2){
                            rep(tr,0,2){
                                ans += (dp[pre][i][tl][tr]* factorial[id1 - i]);
                                

                            }
                        }
                    }
                }
                
                cout << ans.v << endl;
            }
        }
	}

private:
};












int main()
{
	

	

	ios::sync_with_stdio(false);
	cin.tie(0);

    

	Solution sln;
    

    sln.Solve();

	return 0;
}
