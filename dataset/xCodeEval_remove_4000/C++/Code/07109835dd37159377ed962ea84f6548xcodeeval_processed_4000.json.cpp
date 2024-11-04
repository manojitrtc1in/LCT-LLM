






using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef map<int, int> mii;
typedef set<int> si;
typedef queue<int> qi;
typedef tuple<int, int, int> tiii; 

typedef vector<tiii> vtiii;
int T, N, K, M, S; 




void print(int a, int b) {
    cout << a << " " << b << endl;
}

template <typename T>
void print(const T& a) {
    cout << a << endl;
}
void print(pii a) {
    cout << a.first << " " << a.second << endl;
}

void print(vi& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}




































































































































int Q;
void Solve() {
    cin >> N >> Q;
    vll v(N);
    int isOdd = 0;
    int isEven = 0;
    ll sum = 0;
    rep(i,0,N-1) {
        cin >> v[i];
        sum += v[i];
        isOdd += (v[i]%2 == 1 ? 1 : 0);
        isEven += (v[i]%2 == 0 ? 1 : 0);
    }

    while(Q--) {
        bool type; int value;
        cin >> type >> value;

        if(type) {
            sum += value*isOdd;
            if(value%2==1) {
                isEven += isOdd;
                isOdd = 0;    
            }
        }
        else {
            sum += value*isEven;
            if(value%2==1) {
                isOdd += isEven;
                isEven = 0;
            }
        }
        cout << sum << endl;
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) Solve();
}