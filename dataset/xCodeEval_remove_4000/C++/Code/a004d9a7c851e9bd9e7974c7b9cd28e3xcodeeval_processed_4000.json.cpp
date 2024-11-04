


using namespace std;




































namespace IO
{
    const int BUFFER_SIZE = 1 << 15;
    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;
    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;
    char number_buffer[100];
    uint8_t lookup[100];
    void id4()
    {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
        if (input_len == 0)
            input_buffer[0] = EOF;
    }
    inline char next_char(bool advance = true)
    {
        if (input_pos >= input_len)
            id4();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template <typename T>
    inline void read_int(T &number)
    {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do
        {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template <typename T, typename... Args>
    inline void read_int(T &number, Args &... args)
    {
        read_int(number);
        read_int(args...);
    }

    void _flush_output()
    {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c)
    {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template <typename T>
    inline void write_int(T number, char after = '\0')
    {
        if (number < 0)
        {
            write_char('-');
            number = -number;
        }
        int length = 0;
        while (number >= 10)
        {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }
        if (number != 0 || length == 0)
            write_char(number + '0');
        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);
        if (after)
            write_char(after);
    }
    void IOinit()
    {
        

        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);
        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
} 


using namespace IO;


typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());




int dr[] = {0,1,-1,0,1,-1,1,-1};
int dc[] = {1,0,0,-1,1,-1,-1,1};
bool chk(int a, int b, int n, int m) {
        return 0 <= a && a < n && 0 <= b && b < m;
}

ll exp(ll n, ll m, ll md){
        ll a = 1;
        while (m > 0){
                if (m&1) a = (a * n%md) % md;
                m /= 2;
                n = (n*n) % md;
        }
        return a % md;
}

void disp(vi v){
        for(auto u:v)
                cout<<u<<" ";
        cout<<"\n";
}
void disp(vll v){
    for(auto u:v)
        cout<<u<<" ";
    cout<<endl;
}

int id3(int x){
        if(x < 0)
                return -1;
        int l = sqrt(x);
        for (int i = -2; i <= 2; ++i)
                if (l + i >= 0 && (l + i) * (l + i) == x)
                        return l;
        return -1;
}

const int id0 = 1e7;
vi lp;
vector<int> prr;
void prfac(int n = id0){
        assert(n <= id0);
        lp.assign(n+1, 0);
        int i;
        for (i = 2;i <= n;++i) {
                if (lp[i] == 0) {
                        lp[i] = i;
                        prr.push_back(i);
                }
                for (int u: prr) {
                        if(i * u > n || u > lp[i]) break;
                        lp[i * u] = u;
                }
        }
}


bool id1(ll n, ll a, ll d, int s){
        ll x = exp(a, d, n);
        if (x == 1 || x == n-1) return false;
        for(int r = 1;r < s;++r){
                x = x * x%n;
                x %= n;
                if(x == n-1) return false;
        }
        return true;
}
bool prime(ll n){
        if(n < 4) return n == 2 || n == 3;
        if (!(n&1)) return false;
        int s = 0;
        ll d = n-1;
        while(!(d&1)){
                d >>= 1;
                s++;
        }
        for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
                if(n == a) return true;
                if(id1(n, a, d, s)) return false;
        }
        return true;
}

ll id5(ll n, ll k)
{
    ll res = 1;

    

    if (k > n - k)
        k = n - k;

    

    

    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
            

            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
            static const uint64_t id2 = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + id2);
    }
};


inline void read(int &x)
{
    scanf("%d", &x);
}




const ll MAXn=1e5 + 33,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);




void go1() {
    ll a, b, c, d;
    in4(a, b, c, d);
    deque<ll> q;
    if((a > b and (c > 0 or d > 0)) or (d > c and (a > 0 or b > 0))) {
        cout << "NO" << ln;
        return;
    }
    if(a > b+1 or d > c+1) {
        cout << "NO" << ln;
        return;
    }
    if(a == b+1) {
        assert(c == 0 and d == 0);
        while(a > 0) {
            q.push_back(0);
            q.push_back(1);
            a--;b--;
        }
        q.pop_back();
        cout << "YES" << ln;
        while(!q.empty()) {
            cout <<q.front() << " ";
            q.pop_front();
        }
        return;
    }
    if(d== c+1) {
        assert(a == 0 and b == 0);
        while(d > 0) {
            q.push_back(3);
            q.push_back(2);
            d--;c--;
        }
        q.pop_back();
        cout << "YES" << ln;
        while(!q.empty()) {
            cout <<q.front() << " ";
            q.pop_front();
        }
        return;
    }
    assert(a <= b and d <= c);
    while(a > 0) {
        q.push_back(0);
        q.push_back(1);
        a--;b--;
    }
    while(d > 0) {
        q.push_back(2);
        q.push_back(3);
        d--;c--;
    }
    assert(a == 0 and d == 0);
    if(abs(b - c) > 1) {
        cout << "NO" << ln;
        return;
    }
    while(b > 0 and c > 0) {
        q.PB(2);
        q.PB(1);
        b--;
        c--;
    }
    if(c > 0) {
        q.PB(2);
        c--;
    } else if(b > 0) {
        q.push_front(1);
        b--;
    }
    assert(a == 0 and b == 0 and c == 0 and d == 0);
    cout << "YES" << ln;
    while(!q.empty()) {
        cout <<q.front() << " ";
        q.pop_front();
    }
}



int main(){
    fio;
    

    


    


    ll tt = 1;

    auto start  = std::chrono::high_resolution_clock::now();

    while(tt--){
        

        go1();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
    return 0;
}





















































































































































































































































































































