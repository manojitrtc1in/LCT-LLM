
 




 


using namespace std;

 









typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

 

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s); }

 

auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();



 






 
void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
string id0 = "FILE.IN";
string id1 = "FILE.OUT";

 

i64 n, m, s, u, v, w, l; vector<vector<pii>> adj;
map<pii, i64> Map; vector<ppi> Edge;

 

 
 
void Input() {
    cin >> n >> m >> s; adj.rsz(n); Edge.rsz(m);
    for (i64 i=0; i<m; i++) {
        cin >> u >> v >> w; u--; v--;
        if (u > v) swap(u, v);
        adj[u].pub(mp(v,w)); adj[v].pub(mp(u,w));
        Map[mp(u,v)] = i; Map[mp(v,u)] = i;
        Edge[i] = mp(mp(u, v), w);
    }
    cin >> l; s--;
}
 
void Solve() {
    vi Dist(n, LINF); Dist[s] = 0;
    priority_queue<pii> Q; vb vis(n, false);
    Q.push(mp(-Dist[s], s));
    i64 ans = 0;
    while (!Q.empty()) {
        pii Data = Q.top(); Q.pop();
        i64 z = Data.se, d = -Data.fi;
        if (vis[z]) continue; vis[z] = true;
        if (d == l) ans++;
        for (auto T: adj[z]) {
            i64 t = T.fi, p = T.se;
            if (d + p >= Dist[t]) continue;
            Dist[t] = d + p;
            Q.push(mp(-Dist[t], t));
        }
    }
    for (i64 id=0; id<m; id++) {
        u = Edge[id].fi.fi;
        v = Edge[id].fi.se;
        w = Edge[id].se;
        i64 fromU = l - Dist[u];
        i64 fromV = l - Dist[v];
        if (fromU + fromV < w) {
            if ((fromU <= 0 || fromU >= w) && (fromV <= 0 || fromV >= w)) ans += (2 - 2);
            else if ((fromU <= 0 || fromU >= w) || (fromV <= 0 || fromV >= w)) ans += (2 - 1);
            else ans += 2;
        }
        else if (fromU + fromV == w && fromU > 0 && fromU < w) ans++;
    }
    cout << ans;
}

 

int main(int argc, char* argv[]) {
    ControlIO(argc, argv);
 
    
        ios_base::sync_with_stdio(0); cin.tie(NULL);
    
        ios_base::sync_with_stdio(0);
    
    
    
        Input(); TimerStart();
        Solve(); TimerStop();
    
        int T; cin >> T; TimerStart();
        while(T--) {Input(); Solve();}
        TimerStop();
    
 
    return 0;
}

 

void ControlIO(int argc, char* argv[]) {
    char* infile = new char[id0.size()+1];
    char* outfile = new char[id1.size()+1];
    strcpy(infile, id0.c_str());
    strcpy(outfile, id1.c_str());
    
        time_t t = time(0);
        tm* now = localtime(&t);
        cout << "Source code by 
        cout << "Current time: ";
        cout << (now->tm_year + 1900) << '-' 
             << ((now->tm_mon < 9) ? "0" : "") << (now->tm_mon + 1) << '-'
             << ((now->tm_mday < 10) ? "0" : "") <<  now->tm_mday << " | "
             << ((now->tm_hour < 10) ? "0" : "") <<  now->tm_hour << ":"
             << ((now->tm_min < 10) ? "0" : "") <<  now->tm_min << ":"
             << ((now->tm_sec < 10) ? "0" : "") <<  now->tm_sec
             << "\n\n";
        
        
            cout << "OI-Mode: ON\n";
            cout << "Input file: " << infile << endl;
            cout << "Output file: " << outfile << endl;
            cout << "\n";
        
            cout << "OI-Mode: OFF\n";
            cout << "Input file: NULL\n";
            cout << "Output file: NULL\n";
            cout << "\n";
        
        
        
            cout << "MultiTest-Mode: ON\n";
        
            cout << "MultiTest-Mode: OFF\n";
        
        
        
            cout << "Interactive-Mode: ON\n\n";
        
            cout << "Interactive-Mode: OFF\n\n";
        
        
        if (argc > 1) assert(freopen(argv[1], "r", stdin));
        if (argc > 2) assert(freopen(argv[2], "w", stdout));
    
        freopen(infile, "r", stdin);
        freopen(outfile, "w", stdout);
    
}
 
void TimerStart() {
    
        TimeStart = chrono::steady_clock::now();
    
}
 
void TimerStop() {
    
        TimeEnd = chrono::steady_clock::now();
        auto ElapsedTime = TimeEnd - TimeStart;
        cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
    
}
 
void Exit() {
    TimerStop(); exit(0);
}

 
