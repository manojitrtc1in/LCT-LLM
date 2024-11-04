








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
string id3 = "FILE.IN";
string id7 = "FILE.OUT";



i64 n; string s1, s2;





void Input() {
	cin >> n >> s1 >> s2;
}

void Solve() {
	i64 id5 = 0, id2 = 0;
	i64 id10 = 0, id4 = 0;
	i64 id6 = 0, id0 = 0;
	i64 id11 = 0, id8 = 0;
	for (i64 i=0; i<n*2; i++) {
		string d12 = "", d21 = "";
		d12 += s1[i]; d12 += s2[i];
		d21 += s2[i]; d21 += s1[i];
		id5 += (d12 == "11"); id2 += (d21 == "11");
		id10 += (d12 == "10"); id4 += (d21 == "10");
		id6 += (d12 == "01"); id0 += (d21 == "01");
		id11 += (d12 == "00"); id8 += (d21 == "00");
	}
	i64 turn = 1, id1 = 0, id9 = 0;
	while (id5 > 0 || id10 > 0 || id6 > 0 || id11 > 0) {
		if (turn == 1) {
			if (id5) {id5--; id2--; id1++;}
			else if (id10) {id10--; id0--; id1++;}
			else if (id6) {id6--; id4--;}
			else {id11--; id8--;}
		}
		else if (turn == 2) {
			if (id2) {id2--; id5--; id9++;}
			else if (id4) {id4--; id6--; id9++;}
			else if (id0) {id0--; id10--;}
			else {id8--; id11--;}
		}
		turn = 3 - turn;
	}
	if (id1 > id9) cout << "First";
	else if (id1 < id9) cout << "Second";
	else cout << "Draw";
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
	char* infile = new char[id3.size()+1];
	char* outfile = new char[id7.size()+1];
	strcpy(infile, id3.c_str());
	strcpy(outfile, id7.c_str());
	
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


