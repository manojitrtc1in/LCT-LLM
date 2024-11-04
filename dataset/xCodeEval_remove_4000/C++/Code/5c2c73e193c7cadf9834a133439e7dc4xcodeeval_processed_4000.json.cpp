using namespace std;






























typedef long long ll;
typedef long double ld;







template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void __print(int x) { cerr << x; }

void __print(long x) { cerr << x; }

void __print(long long x) { cerr << x; }

void __print(unsigned x) { cerr << x; }

void __print(unsigned long x) { cerr << x; }

void __print(unsigned long long x) { cerr << x; }

void __print(float x) { cerr << x; }

void __print(double x) { cerr << x; }

void __print(long double x) { cerr << x; }

void __print(char x) { cerr << '\'' << x << '\''; }

void __print(const char *x) { cerr << '\"' << x << '\"'; }

void __print(const string &x) { cerr << '\"' << x << '\"'; }

void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << '}';
}

template<typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
}

void _print() { cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}




template<class T>
void re(T &x) { cin >> x; }

template<class T>
void read(vector<T> &a) { for (auto &x : a) re(x); }












bool Prime(string t) {
    int x = (t[0] - '0') * 10 + t[1] - '0';
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int changchar(char s) {
    if (s == '0') {
        return 0;
    }
    if (s == '1') {
        return 1;
    }
    if (s == '2') {
        return 2;
    }
    if (s == '3') {
        return 3;
    }
    if (s == '4') {
        return 4;
    }
    if (s == '5') {
        return 5;
    }
    if (s == '6') {
        return 6;
    }
    if (s == '7') {
        return 7;
    }
    if (s == '8') {
        return 8;
    }
    if (s == '9') {
        return 9;
    }
    return 0;
}

bool isPalindrome(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            return 0;
        }
    }
    return 1;
}



const long long inf = 1e18;


struct segment {
    int a, id;
};
struct segment2 {
    int s, e;
};

bool operator<(segment a, segment b) {
    return a.a > b.a;
}



typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<vi> vivi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
























double upp(double x , int n){
    double xx = x;
    id6(i , n - 1){
        xx *= x;
    }
    return xx;
}

double takeOne(double a){
    string s = to_string(a);
    int index = 0;
    id6(i , sz(s)){
        if(s[i] == '.'){
            index = i + 2;
            break;
        }
    }
    if(s[index] < '4'){
        string ans = "";
        id6(j , index){
            ans += s[j];
        }
        double anss = stod(ans);
        return anss;
    }
    FORd(i , index , sz(s)){
        if(s[i] >= '5'){
            if(s[i - 1] != '9'){
                s[i - 1]++;
            }
        }
    }
    string ans1 = "";
    id6(i , index){
        ans1 += s[i];
    }
    double ans = stod(ans1);
    return ans;
}

double takeTwo(double a){
    string s = to_string(a);
    int index = 0;
    id6(i , sz(s)){
        if(s[i] == '.'){
            index = i + 2;
            index++;
            break;
        }
    }
    if(s[index] < '4'){
        string ans = "";
        id6(j , index){
            ans += s[j];
        }
        double anss = stod(ans);
        return anss;
    }
    FORd(i , index , sz(s)){
        if(s[i] >= '5'){
            if(s[i - 1] != '9'){
                s[i - 1]++;
            }
        }
    }
    string ans1 = "";
    id6(i , index){
        ans1 += s[i];
    }
    double ans = stod(ans1);
    return ans;
}

void KCT(){
    vector<vector<double>> ans;
    vector<double> aa;
    double Qc = 20  , Yq = 1.2 , L = 8 , Fu = 34 , F = 21 , E = 21000 , Fv = 0.58 , id17 = 400 , Yc = 0.9
            , id18 = 1.05 , Ys = 78.5;
    Fv *= F;
    double Q = Yq * Qc ;
    double Mmax = ( Q * L * L) / 8; Mmax = takeTwo(Mmax);
    double Qmax = (Q * L) / 2; Qmax = takeTwo(Qmax);
    L *= 100;
    Mmax *= 100;
    double Hmin = 5 /24 * F / E * id17 * L / Yq;   

    double Wyc = Mmax / (Yc * F); Wyc = takeTwo(Wyc);
    double Hkt = 1.2 * sqrt((Wyc / 0.6)); Hkt = takeTwo(Hkt);  

    int H = Hkt;
    if(round(Hkt) < Hkt){
        H++;
    }
    bool id16 = 0;
    int id10 , Tw;
    double Hw , Hf , Tf ;
    while(!id16){
        double TwTest = 3 / 2 * Qmax / ( H * Yc * Fv); 

        double findTw = max(H / 5.5 * sqrt((F /  E)) , H  / 3.2  * sqrt((F / E))); 

        findTw = takeTwo(findTw);
        findTw *= 10;
        findTw = round(findTw);
        Tw = findTw ;
        if(Tw % 2 == 1){
            Tw++;
        }
        

        Tf = Tw + 2;
        Hw = H - 2 * (Tf / 10);
        Hf = H - (Tf / 10);
        double Bf = (Mmax * H) / (Yc * F * 2) ;
        Bf -= (((double)Tw / 10) * Hw * Hw * Hw) / 12;
        Bf *= 2 / ((Tf / 10) * Hf * Hf);
        Bf = takeTwo(Bf);
        double id5 = sqrt((E / F)) * (Tf / 10);
        id5 = takeTwo(id5);
        int s = H / 5;
        int e = H / 2;
        if(Bf <= id5 && Bf >= s && Bf <= e){
            Bf = round(Bf);
            id10 = Bf;
            id16 = 1;
        }else{
            H++;
        }
    }
    if(id10 % 2 == 1){
        id10++;
    }
    

    

    

    Hw = takeTwo(Hw) ; Hf = takeTwo(Hf); Tf = takeTwo(Tf);
    id10 = 22;
    double A = ((double)Tw / 10) * Hw + 2 * (Tf / 10) * id10; A = takeTwo(A);
    double Ix = (((double)Tw / 10) * Hw * Hw * Hw ) / 12;   

    Ix += 2 * ((id10 * (upp(Tf / 10 , 3))) / 12)  + 2 * ((Tf / 10) * id10 * (upp(Hf , 2) / 4));
    Ix = takeTwo(Ix);
    double Wx = Ix / (H / 2);  Wx = takeTwo(Wx);  

    double Sx = ((double)Tw / 10) * (Hw / 2) * (Hw / 4) + (Tf / 10) * id10 * (Hf / 2); Sx = takeTwo(Sx);  

    double Sxf = (Tf / 10) * id10 * Hf / 2;  Sxf = takeTwo(Sxf);
    double Gcd = Ys * A * 0.0001 * 1;  Gcd = takeTwo(Gcd); 

    double Gd = id18 * Gcd;
    debug(Gd)
    Gd = takeTwo(Gd);
    double id15 = Qc + Gcd;  id15 = takeTwo(id15);
    double id9 = Q + Gd; id9 = takeTwo(id9);
    

    L /= 100;
    double id1 = id9 * upp(L , 2) / 8; id1 = takeTwo(id1);
    double id8 = (id9 * L) / 2;  id8 = takeTwo(id8);
    double id0 = (id9 * L / 2) - id9 * (L / 4);  id0 = takeTwo(id0);
    double id4 = id9 * L / 2 * L / 4 - (id9 / 2) * upp((L / 4) , 2); id4 = takeTwo(id4);

    debug(id0)
    debug(id4)
    bool ok = 1;
    double id2 = Yc * F; id2 = takeTwo(id2);
    double id13 = id1 * 100 / Wx;  id13 = takeTwo(id13);
    double ToMax = id8 * Sx / (Ix * ((double)Tw / 10)); ToMax = takeTwo(ToMax);
    double id3 = id4 * 100 * Hw / (Wx * H); id3 = takeTwo(id3);
    double To1 = id0 * Sxf / (Ix  * ((double) Tw / 10)); To1 = takeTwo(To1);
    double id12 = sqrt(upp(id3 , 2) + 3 * upp(To1 , 2));
    debug(id12)
    id12 = takeTwo(id12);
    

    L *= 100;
    

    double id7 = 0.01302083 * ((id15 / 100) * upp(L , 3)) / (E * Ix);
    id7 *= id17;
    

    _print(Hw , Hf , A , Ix, Wx , Sx , Sxf , Gcd , Gd , id9 , id15 , id1 ,
           id8 , id13 , ToMax , id3 , To1 , id12 , id7);
    double Bof = (id10 - (double)Tw / 10) / 2.0 ;




}


void id11(int n)
{
    

    int binaryNum[32];

    

    int i = 0;
    while (n > 0) {

        

        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    

    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}



int64 Solve(int64 x, int64 n) {
    int64 answer = 0;
    vector<int> id14(62, 0);
    int last = 0;
    for (int i = 0; i < 62; i += 1) {
        id14[i] = last;
        last += (x & (1LL << i)) == 0;


    }
    trav(i , id14){
        cout << i << " ";
    }
    cout << '\n';
    bool terminated = false;
    for (int p = 61; p >= 0; p -= 1) {
        bool has_x = !!((1LL << p) & x);
        bool has_n = !!((1LL << p) & n);
        if(has_x){
            cout << "has_x true" << " tai p : " <<p << '\n' ;
        }
        if(has_n){
            cout << "    has_n true" << " tai p : " <<p << '\n' ;
        }
        if (has_x and has_n) {
            continue;
        }

        if (has_x and not has_n) {
            cout << "da stop "  << p << '\n';
            terminated = true;
            break;
        }

        if (not has_n) {
            continue;
        }

        answer += (1LL << id14[p]);
    }
    cout << answer << '\n';
    answer += terminated ^ 1;
    cout << "ans sau: "<<answer << '\n';
    return answer;
}


void solve(){
   int n;
   cin >> n;
   int index = 0;
   id6(i , 30){
       if((1LL << i) & n){
           index = i;
       }
   }
   cout << (1LL << index) - 1 << '\n';
}






int main() {

    
















    int t;
    cin >> t;
    FOR(i , 1 , t + 1){
        solve();
    }


























    return 0;
}