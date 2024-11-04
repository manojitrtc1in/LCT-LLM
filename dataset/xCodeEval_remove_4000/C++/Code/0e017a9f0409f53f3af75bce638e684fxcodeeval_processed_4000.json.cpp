






















 
 
 
 

using namespace std; 









 
 

using namespace std;
 
using ll = long long;
using db = double;
using str = string;
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<ll>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
 


tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
tcT> using PR = pair<T,T>;






 


















 


 

 








 
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} 

ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll id3(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll id1(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
 
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool id0(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool id2(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
 
inline int two(int n) { return 1 << n; } 
inline int test(int n, int b) { return (n>>b)&1; } 
inline void set_bit(int & n, int b) { n |= two(b); } 
inline void unset_bit(int & n, int b) { n &= ~two(b); } 
inline int last_bit(int n) { return n & (-n); } 
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; } 
 
template<class T> void chmax(T & a, const T & b) { a = max(a, b); } 
template<class T> void chmin(T & a, const T & b) { a = min(a, b); } 
 
const int MOD = 1e9+7;
const int MX = 2e5+5;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};   

tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }
tcT> void remDup(vector<T>& v) { 

    sort(all(v)); v.erase(unique(all(v)),end(v)); }


 
inline namespace FileIO {
    void setIn(str s) {freopen(s.c_str(),"r",stdin);}
    void setOut(str s) {freopen(s.c_str(),"w",stdout);}
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out");    

    }
}







ll mod = 1e9 + 7; 


 int main()
{
    setIO();
    Code By Sudhir
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
   
int pass ;
cin>>pass;
while(pass--)
   {

 int n; cin>>n;
    vi arr; int s;
    
    for(int i=0; i<n; i++)
    {
        cin>>s;
        arr.push_back(s);
    }
    
    
    cout<<arr[0]<<endl;
}
}













 














 


   
   


        


 






 




























        
 




 

 int board[2],player;

void resetGame() {
    for (int i = 0; i < 9; i++) {
        board[i] = 0;
    }
}
void refreshPage() {
    for (int i = 0; i < 100; i++) {
        cout << "\n";
    }
}
 
  
 
int checkWinner() {
    if ((board[0] != 0) && (board[1] != 0) && (board[2] != 0) && (board[3] != 0) && (board[4] != 0) && (board[5] != 0) && (board[6] != 0) && (board[7] != 0) && (board[8] != 0)) {
        return 10;
    }
    if ((board[0] == board[1]) && (board[1] == board[2]) && (board[0] != 0)) {
        return board[0];
    }
    if ((board[3] == board[4]) && (board[4] == board[5]) && (board[3] != 0)) {
        return board[3];
    }
    if ((board[6] == board[7]) && (board[7] == board[8]) && (board[6] != 0)) {
        return board[6];
    }
    if ((board[0] == board[3]) && (board[3] == board[6]) && (board[0] != 0)) {
        return board[0];
    }
    if ((board[1] == board[4]) && (board[4] == board[7]) && (board[1] != 0)) {
        return board[1];
    }
    if ((board[2] == board[5]) && (board[5] == board[8]) && (board[2] != 0)) {
        return board[2];
    }
    if ((board[0] == board[4]) && (board[4] == board[8]) && (board[0] != 0)) {
        return board[0];
    }
    if ((board[2] == board[4]) && (board[4] == board[6]) && (board[2] != 0)) {
        return board[2];
    }
    return 0;
}
 
void machineInput() {
    int input = 9;
    cout << "My turn. Thinking...\n";
    if ((board[0] == board[1]) && (board[0] == player) && (board[2] == 0)) {
        input = 2;
    }
    if ((board[1] == board[2]) && (board[1] == player) && (board[0] == 0)) {
        input = 0;
    }
    if ((board[0] == board[2]) && (board[0] == player) && (board[1] == 0)) {
        input = 1;
    }
    if ((board[3] == board[4]) && (board[3] == player) && (board[5] == 0)) {
        input = 5;
    }
    if ((board[4] == board[5]) && (board[4] == player) && (board[3] == 0)) {
        input = 3;
    }
    if ((board[3] == board[5]) && (board[3] == player) && (board[4] == 0)) {
        input = 4;
    }
    if ((board[6] == board[7]) && (board[6] == player) && (board[8] == 0)) {
        input = 8;
    }
    if ((board[7] == board[8]) && (board[7] == player) && (board[6] == 0)) {
        input = 6;
    }
    if ((board[6] == board[8]) && (board[6] == player) && (board[7] == 0)) {
        input = 7;
    }
    if ((board[0] == board[3]) && (board[0] == player) && (board[6] == 0)) {
        input = 6;
    }
    if ((board[3] == board[6]) && (board[3] == player) && (board[0] == 0)) {
        input = 0;
    }
    if ((board[0] == board[6]) && (board[0] == player) && (board[3] == 0)) {
        input = 3;
    }
    if ((board[1] == board[4]) && (board[1] == player) && (board[7] == 0)) {
        input = 7;
    }
    if ((board[4] == board[7]) && (board[4] == player) && (board[1] == 0)) {
        input = 1;
    }
    if ((board[1] == board[7]) && (board[1] == player) && (board[4] == 0)) {
        input = 4;
    }
    if ((board[2] == board[5]) && (board[2] == player) && (board[8] == 0)) {
        input = 8;
    }
    if ((board[5] == board[8]) && (board[5] == player) && (board[2] == 0)) {
        input = 2;
    }
    if ((board[2] == board[8]) && (board[2] == player) && (board[5] == 0)) {
        input = 5;
    }
    if ((board[0] == board[4]) && (board[0] == player) && (board[8] == 0)) {
        input = 8;
    }
    if ((board[4] == board[8]) && (board[4] == player) && (board[0] == 0)) {
        input = 0;
    }
    if ((board[0] == board[8]) && (board[0] == player) && (board[4] == 0)) {
        input = 4;
    }
    if ((board[2] == board[4]) && (board[2] == player) && (board[6] == 0)) {
        input = 6;
    }
    if ((board[4] == board[6]) && (board[4] == player) && (board[2] == 0)) {
        input = 2;
    }
    if ((board[2] == board[6]) && (board[2] == player) && (board[4] == 0)) {
        input = 4;
    }
    if (input == 9) {
        cout << "No solution, randomly filling in...\n";
        int i;
        while (input != 9) {
            i = rand() % 9;
            if (board[i] == 0) {
                input = i;
            }
        }
    }
    if (player == 1) {
        board[input] = 2;
    }
    else {
        board[input] = 1;
    }
    cout << "Placed on address " << input << "\n";
   
}
 
void playerInput() {
    int input;
ask:
    input = 0;
    cout << "Your turn. Enter a number.\n";
    cin >> input;
    if (input > 9) {
        cout << "The number you entered is too big.\n";
        goto ask;
    }
    else if (input < 1) {
        cout << "The number you entered is too small.\n";
        goto ask;
    }
    else if (board[input - 1] != 0) {
        cout << "The number you entered has already filled in.\n";
        goto ask;
    }
    else {
        board[input - 1] = player;
    }
}
void printBoard() {
    char displayBoard[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    for (int i = 0; i < 9; i++) {
        switch (board[i]) {
        case 0:
            displayBoard[i] = ' ';
            break;
        case 1:
            displayBoard[i] = 'O';
            break;
        case 2:
            displayBoard[i] = 'X';
            break;
        };
    }
    cout << "Game Board          Key Map\n";
    cout << "*************       *************\n";
    cout << "* " << displayBoard[0] << " * " << displayBoard[1] << " * " << displayBoard[2] << " *       * 1 * 2 * 3 *\n";
    cout << "*************       *************\n";
    cout << "* " << displayBoard[3] << " * " << displayBoard[4] << " * " << displayBoard[5] << " *       * 4 * 5 * 6 *\n";
    cout << "*************       *************\n";
    cout << "* " << displayBoard[6] << " * " << displayBoard[7] << " * " << displayBoard[8] << " *       * 7 * 8 * 9 *\n";
    cout << "*************       *************\n";
}






   


