










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



i64 k, n, id; string s, a, b;



i64 contains(string st, char ch) {
	for (i64 i=0; i<st.size(); i++) {
		if (st[i] != ch) continue;
		return i;
	}
	return -1;
}

void Input() {
	cin >> k >> s >> a >> b;
	n = s.size();
}

void Solve() {
	string Template = ""; vb taken(k, false);
	for (i64 i=0; i<k; i++) Template += "0";
	bool top = false, bot = false;
	for (id=0; id<n; id++) {
		if (a[id] == b[id]) {
			if (Template[s[id]-'a'] != '0') {
				if (Template[s[id]-'a'] != a[id]) {cout << "NO\n"; return;}
				continue;
			}
			if (taken[a[id]-'a']) {cout << "NO\n"; return;}
			taken[a[id]-'a'] = true;
			Template[s[id]-'a'] = a[id]; continue;
		}
		if (Template[s[id]-'a'] != '0') {
			if (Template[s[id]-'a'] < a[id]) {cout << "NO\n"; return;}
			if (Template[s[id]-'a'] > b[id]) {cout << "NO\n"; return;}
			if (Template[s[id]-'a'] > a[id] && Template[s[id]-'a'] < b[id]) {
				i64 z = 0; while (z < k && taken[z]) z++;
				for (i64 zz=0; zz<k; zz++) {
					if (Template[zz] != '0') continue;
					Template[zz] = char(97+z); z++;
					while (z < k && taken[z]) z++;
				}
				cout << "YES\n" << Template << endl; return;
			}
			if (Template[s[id]-'a'] == a[id]) {top = true; break;}
			if (Template[s[id]-'a'] == b[id]) {bot = true; break;}
		}
		set<char> Set;
		for (char c=a[id]; c<=b[id]; c++) {
			if (taken[c-'a']) continue;
			Set.insert(c);
		}
		if (Set.empty()) {cout << "NO\n"; return;}
		if (Set.upper_bound(a[id]) != Set.end() && *Set.upper_bound(a[id]) != b[id]) {
			char qq = *Set.upper_bound(a[id]); Template[s[id]-'a'] = qq; taken[qq-'a'] = true;
			i64 z = 0; while (z < k && taken[z]) z++;
			for (i64 zz=0; zz<k; zz++) {
				if (Template[zz] != '0') continue;
				Template[zz] = char(97+z); z++;
				while (z < k && taken[z]) z++;
			}
			cout << "YES\n" << Template << endl; return;
		}
		if (Set.find(a[id]) != Set.end()) top = true;
		if (Set.find(b[id]) != Set.end()) bot = true;
		break;
	}
	if (top) {
		i64 id2 = id + 1;
		string Template2 = Template;
		Template2[s[id2-1]-'a'] = a[id2-1];
		vb taken2 = taken; taken2[a[id2-1]-'a'] = true;
		bool valid = true;
		for (; id2<n; id2++) {
			if (Template2[s[id2]-'a'] != '0') {
				if (Template2[s[id2]-'a'] < a[id2]) {valid = false; break;}
				if (Template2[s[id2]-'a'] > a[id2]) {
					i64 z = 0; while (z < k && taken2[z]) z++;
					for (i64 zz=0; zz<k; zz++) {
						if (Template2[zz] != '0') continue;
						Template2[zz] = char(97+z); z++;
						while (z < k && taken2[z]) z++;
					}
					cout << "YES\n" << Template2 << endl; return;
				}
				continue;
			}
			set<char> Set;
			for (char c=a[id2]; c<=char(97+k-1); c++) {
				if (taken2[c-'a']) continue;
				Set.insert(c);
			}
			if (Set.empty()) {valid = false; break;}
			if (Set.upper_bound(a[id2]) != Set.end()) {
				char qq = *Set.upper_bound(a[id2]);
				Template2[s[id2]-'a'] = qq; taken2[qq-'a'] = true;
				i64 z = 0; while (z < k && taken2[z]) z++;
				for (i64 zz=0; zz<k; zz++) {
					if (Template2[zz] != '0') continue;
					Template2[zz] = char(97+z); z++;
					while (z < k && taken2[z]) z++;
				}
				cout << "YES\n" << Template2 << endl; return;
			}
			char qq = *Set.begin();
			Template2[s[id2]-'a'] = qq; taken2[qq-'a'] = true;
		}
		if (valid) {
			i64 z = 0; while (z < k && taken2[z]) z++;
			for (i64 zz=0; zz<k; zz++) {
				if (Template2[zz] != '0') continue;
				Template2[zz] = char(97+z); z++;
				while (z < k && taken2[z]) z++;
			}
			cout << "YES\n" << Template2 << endl; return;
		}
	}
	if (bot) {
		i64 id2 = id + 1;
		string Template2 = Template;
		Template2[s[id2-1]-'a'] = b[id2-1];
		vb taken2 = taken; taken2[b[id2-1]-'a'] = true;
		bool valid = true;
		for (; id2<n; id2++) {
			if (Template2[s[id2]-'a'] != '0') {
				if (Template2[s[id2]-'a'] > b[id2]) {valid = false; break;}
				if (Template2[s[id2]-'a'] < b[id2]) {
					i64 z = 0; while (z < k && taken2[z]) z++;
					for (i64 zz=0; zz<k; zz++) {
						if (Template2[zz] != '0') continue;
						Template2[zz] = char(97+z); z++;
						while (z < k && taken2[z]) z++;
					}
					cout << "YES\n" << Template2 << endl; return;
				}
				continue;
			}
			set<char> Set;
			for (char c='a'; c<=b[id2]; c++) {
				if (taken2[c-'a']) continue;
				Set.insert(c);
			}
			if (Set.empty()) {valid = false; break;}
			if (*Set.begin() != b[id2]) {
				char qq = *Set.begin();
				Template2[s[id2]-'a'] = qq; taken2[qq-'a'] = true;
				i64 z = 0; while (z < k && taken2[z]) z++;
				for (i64 zz=0; zz<k; zz++) {
					if (Template2[zz] != '0') continue;
					Template2[zz] = char(97+z); z++;
					while (z < k && taken2[z]) z++;
				}
				cout << "YES\n" << Template2 << endl; return;
			}
			char qq = *Set.rbegin();
			Template2[s[id2]-'a'] = qq; taken2[qq-'a'] = true;
		}
		if (valid) {
			i64 z = 0; while (z < k && taken2[z]) z++;
			for (i64 zz=0; zz<k; zz++) {
				if (Template2[zz] != '0') continue;
				Template2[zz] = char(97+z); z++;
				while (z < k && taken2[z]) z++;
			}
			cout << "YES\n" << Template2 << endl; return;
		}
	}
	if (!top && !bot) {
		i64 z = 0; while (z < k && taken[z]) z++;
		for (i64 zz=0; zz<k; zz++) {
			if (Template[zz] != '0') continue;
			Template[zz] = char(97+z); z++;
			while (z < k && taken[z]) z++;
		}
		cout << "YES\n" << Template << endl; return;
	}
	cout << "NO\n";
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



