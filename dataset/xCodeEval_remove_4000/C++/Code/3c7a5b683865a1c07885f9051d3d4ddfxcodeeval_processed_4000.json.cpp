























using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ull> vull;
typedef vector<ll> vll;


typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector< vector<int> > vvi;
typedef vector<char> vc;

const int INF = 1e9;
const ll INFLL = 1e16;
const int MOD = 1000000007;
const int MAXN = 3e5;


const ld eps2 = 1e-9;
const int MOD2 = 998244353;
const int dosz = 5e5;
const int SZ = (1<<18);
const ld PI = atan2l(0, -1);


void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

        


       

       


}

void solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    cout << "YES" << endl;
    if(s=="aa"){
        if(t=="aa"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ab"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ac"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ba"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="bb"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="bc"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ca"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cb"){
            for(int i=0; i<n; i++){
                cout << "ca";
            } for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="cc"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        }
    } else if(s=="ab"){
        if(t=="aa"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ab"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ac"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="ba"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="bb"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="bc"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ca"){
            for(int i=0; i<n; i++){
                cout << "cb";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="cb"){
            for(int i=0; i<n; i++){
                cout << "b";
            } for(int i=0; i<n; i++){
                cout << "a";
            } for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cc"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        }
    } else if(s=="ac"){
        if(t=="aa"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ab"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="ac"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ba"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="bb"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="bc"){
            for(int i=0; i<n; i++){
                cout << "c";
            }
            for(int i=0; i<n; i++){
                cout << "ab";
            }
        } else if(t=="ca"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cb"){
            for(int i=0; i<n; i++){
                cout << "ca";
            } for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="cc"){
            for(int i=0; i<n; i++){
                cout << "cb";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        }
    } else if(s=="ba"){
        if(t=="aa"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ab"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ac"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ba"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="bb"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="bc"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ca"){
            for(int i=0; i<n; i++){
                cout << "a";
            }
            for(int i=0; i<n; i++){
                cout << "b";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cb"){
            for(int i=0; i<n; i++){
                cout << "a";
            }
            for(int i=0; i<n; i++){
                cout << "b";
            } for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cc"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        }
    } else if(s=="bb"){
        if(t=="aa"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ab"){
            for(int i=0; i<n; i++){
                cout << "bac";
            }
        } else if(t=="ac"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ba"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="bb"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="bc"){
            for(int i=0; i<n; i++){
                cout << "ba";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ca"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cb"){
            for(int i=0; i<n; i++){
                cout << "ab";
            } for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cc"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        }
    } else if(s=="bc"){
        if(t=="aa"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ab"){
            for(int i=0; i<n; i++){
                cout << "ba";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ac"){
            for(int i=0; i<n; i++){
                cout << "cb";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="ba"){
            for(int i=0; i<n; i++){
                cout << "a";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="bb"){
            for(int i=0; i<n; i++){
                cout << "ba";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="bc"){
            for(int i=0; i<n; i++){
                cout << "ba";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ca"){
            for(int i=0; i<n; i++){
                cout << 'c';
            }
            for(int i=0; i<n; i++){
                cout << "ba";
            }
        } else if(t=="cb"){
            for(int i=0; i<n; i++){
                cout << "b";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cc"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        }
    } else if(s=="ca"){
        if(t=="aa"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ab"){
            for(int i=0; i<n; i++){
                cout << "b";
            }for(int i=0; i<n; i++){
                cout << "a";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ac"){
            for(int i=0; i<n; i++){
                cout << "cb";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="ba"){
            for(int i=0; i<n; i++){
                cout << "a";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="bb"){
            for(int i=0; i<n; i++){
                cout << "ba";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="bc"){
            for(int i=0; i<n; i++){
                cout << "ba";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ca"){
            for(int i=0; i<n; i++){
                cout << 'c';
            }
            for(int i=0; i<n; i++){
                cout << "ba";
            }
        } else if(t=="cb"){
            for(int i=0; i<n; i++){
                cout << "b";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cc"){
            for(int i=0; i<n; i++){
                cout << "cb";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        }
    } else if(s=="cb"){
        if(t=="aa"){
            for(int i=0; i<n; i++){
                cout << "ab";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ab"){
            for(int i=0; i<n; i++){
                cout << "b";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
            for(int i=0; i<n; i++){
                cout << "a";
            }
        } else if(t=="ac"){
            for(int i=0; i<n; i++){
                cout << 'a';
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ba"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="bb"){
            for(int i=0; i<n; i++){
                cout << "ba";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="bc"){
            for(int i=0; i<n; i++){
                cout << "ba";
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="ca"){
            for(int i=0; i<n; i++){
                cout << "a";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cb"){
            for(int i=0; i<n; i++){
                cout << "b";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
            for(int i=0; i<n; i++){
                cout << 'c';
            }
        } else if(t=="cc"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        }
    } else if(s=="cc"){
        if(t=="aa"){
            for(int i=0; i<n; i++){
                cout << "ac";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ab"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="ac"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="ba"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="bb"){
            for(int i=0; i<n; i++){
                cout << "abc";
            }
        } else if(t=="bc"){
            for(int i=0; i<n; i++){
                cout << "ca";
            }
            for(int i=0; i<n; i++){
                cout << 'b';
            }
        } else if(t=="ca"){
            for(int i=0; i<n; i++){
                cout << "cb";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        } else if(t=="cb"){
            for(int i=0; i<n; i++){
                cout << "abc";
            }
        } else if(t=="cc"){
            for(int i=0; i<n; i++){
                cout << "bc";
            }
            for(int i=0; i<n; i++){
                cout << 'a';
            }
        }
    }

}

signed main() {
    fast_io();
    int q = 1;
    

    

    

    while(q--){
        solve();
    }
    return 0;
}
