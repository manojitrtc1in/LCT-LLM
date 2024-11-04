









































using namespace std;

char string_in_buffer[(int)3e6];


void fast_scan(int &x) { scanf("%d", &x); }
void fast_scan(long long &x) { scanf("%lld", &x); }
void fast_scan(unsigned long long &x) { scanf("%llu", &x); }
void fast_scan(double &x) { scanf("%lf", &x); }
void fast_scan(long double &x) { scanf("%Lf", &x); }
void fast_scan(char &x) { 
	scanf("%c", &x); 
	if (x == '\n') {
		fast_scan(x);
	}
}
void fast_scan(string &x) {
	scanf("%s", string_in_buffer);
	x = string(string_in_buffer);
}

template<class TFirst, class TSecond>
void fast_scan(pair<TFirst, TSecond> &p) {
	fast_scan(p.first);
	fast_scan(p.second);
}

template <class T>
void fast_scan(vector<T> &v) {
	for (auto &x : v) fast_scan(x);
}

void fast_print(const int &x) { printf("%d", x); }
void fast_print(const long long &x) { printf("%lld", x); }
void fast_print(const unsigned long long &x) { printf("%llu", x); }
void fast_print(const double &x) { printf("%.15lf", x); }
void fast_print(const long double &x) { printf("%.15Lf", x); }
void fast_print(const char &x) { printf("%c", x); };
void fast_print(const string &x) { printf("%s", x.c_str());}

template<class TFirst, class TSecond>
void fast_print(const pair<TFirst, TSecond> &p) {
	fast_print(p.first);
	fast_print(' ');
	fast_print(p.second);
}

template <class T>
void fast_print(const vector<T> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print(" ");
		fast_print(v[i]);
	}
}

template <class T>
void fast_print(const vector<vector<T>> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print("\n");
		fast_print(v[i]);
	}
}



using namespace std;


namespace smart_io {
	string print_start = "";
	string sep = " ";
	bool first_print = false;

	void id1() {
		fast_print(print_start);
		print_start = "\n";
		first_print = true;
	}
} 



template <class T>
ostream &operator,(ostream &os, const T &object) {
	if (!smart_io::first_print) {
		fast_print(smart_io::sep);
	} else {
		smart_io::first_print = false;
	}
	fast_print(object);
	return os;
}

template <class T>
istream &operator,(istream &is, T &object) {
	fast_scan(object);
	return is;
}



namespace typedefs {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int, int> pii;
}

namespace numbers_operation {
	template<class T>
	T floor_mod(T a, T b) {
		if (a % b == 0) return 0;
		if (a >= 0 && b >= 0) return a % b;
		if (a <= 0 && b <= 0) return a % b;
		return abs(b) - (abs(a) % abs(b));
	}
}

using namespace numbers_operation;
using namespace typedefs;


smart_io::id1(); \
cout,






const int MOD = 1e9 + 7;
const ll MOD2 = 1000000103;



struct Info {
	int from, to;
	int left, right;

	Info() {}

	Info(int _from, int _to, int _left, int _right) {
		from = _from;
		to = _to;
		left = _left;
		right = _right;
	}
};

string s;

vector<Info> vertices;
int nodesCount = 0;

struct Node {
	int id = 0;
	int prev_len = 0;
	int left, right;
	int ends = 0;
	ll ends_dp = 0;
	Node *prev = NULL;

	map<char, Node*> childs;
	
	string full_path() {
		if (prev == NULL) return "";
		return prev->full_path() + get_cur();
	}

	Node(int _left, int _right, int _prev_len, Node *_prev) {
		id = nodesCount++;
		left = _left;
		right = _right;
		prev_len = _prev_len;
		prev = _prev;
	}

	Node *add(int _left, int _right) {
		

		

		

		

		

		return (childs[s[_left]] = new Node(_left, _right, _right - _left + prev_len, this));
		

	}

	Node *cut_add(int _left, int _right, int eqs) {
		char c = s[_left];
		if (childs.find(c) == childs.end()) {
			return add(_left, _right);
		}

		Node *pref = childs[c];
		

		Node *sub = new Node(pref->left, pref->left + eqs, prev_len + eqs, this);
		pref->left = pref->left + eqs;
		childs[c] = sub;
		sub->childs[s[pref->left]] = pref;
		return sub->add(_left + eqs, _right);
	}

	string get_cur() {
		string cur = "";
		for (int i = left; i < right; i++) {
			cur += s[i];
		}
		return cur;
	}

	void print_tree(string tabs) {
		print tabs, get_cur(), "->";
		for (auto p : childs) {
			p.second->print_tree(tabs + '\t');
		}
	}

	void print_info() {
		for (auto p : childs) {
			if (p.first == '$') continue;
			vertices.emplace_back(id, p.second->id, p.second->left, p.second->right);
		}
		for (auto p : childs) {
			if (p.first == '$') continue;
			p.second->print_info();
		}
	}

	void zip() {
		for (auto p : childs) {
			p.second->zip();
		}
		if ((len(childs) == 1) && prev) {
			auto p = *childs.begin();
			left = p.second->left - (right - left);
			right = p.second->right;
			childs = p.second->childs;
		}
	}

	void calc_end() {
		ends_dp = ends;
		for (auto p : childs) {
			p.second->calc_end();
			ends_dp += p.second->ends_dp;
		}
	}

	ll rehren() {
		ll rez = (ll)ends_dp * (ll)prev_len;
		for (auto p : childs) {
			rez = max(rez, p.second->rehren());
		}
		return rez;
	}
};

Node *root = new Node(-1, -1, 0, NULL);

signed main(signed argc, char *argv[]) {
	int n;
	scan n;
	scan s;
	string forb;
	scan forb;
	reverse(s.begin(), s.end());
	reverse(forb.begin(), forb.end());
	vector<int> hash(len(s));
	hash[0] = s[0] - 'a';
	for (int i = 1; i < len(s); i++) {
		hash[i] = (hash[i - 1] * 31 + (s[i] - 'a')) % MOD;
	}

	vector<ll> powers{1};
	for (int i = 0; i < len(s); i++) {
		powers.pb((powers.back() * 31) % MOD);
	}

	vector<int> hash2(len(s));
	hash2[0] = s[0] - 'a';
	for (int i = 1; i < len(s); i++) {
		hash2[i] = (hash2[i - 1] * 37 + (s[i] - 'a')) % MOD2;
	}

	vector<ll> powers2{1};
	for (int i = 0; i < len(s); i++) {
		powers2.pb((powers2.back() * 37) % MOD2);
	}

	auto get_hash = [&hash, &powers](int l, int r) {
		if (l == r) return 0LL;
		ll rez = hash[r - 1];
		if (l > 0) {
			rez = floor_mod(rez - ((hash[l - 1] * powers[r - l]) % MOD), MOD);
		}
		return rez;
	};

	auto id0 = [&hash2, &powers2](int l, int r) {
		if (l == r) return 0LL;
		ll rez = hash2[r - 1];
		if (l > 0) {
			rez = floor_mod(rez - ((hash2[l - 1] * powers2[r - l]) % MOD2), MOD2);
		}
		return rez;
	};

	auto check_equal = [&get_hash, &id0](int fl, int fr, int sl, int sr){
		return get_hash(fl, fr) == get_hash(sl, sr) && id0(fl, fr) == id0(sl, sr);
	};


	auto lcp = [&get_hash](int pr_first, int pr_second) {
		int left = 0;
		int right = min(len(s) - pr_first, len(s) - pr_second);

		if (get_hash(pr_first, pr_first + min(len(s) - pr_first, len(s) - pr_second))
			== get_hash(pr_second, pr_second + min(len(s) - pr_first, len(s) - pr_second))) {
			return right;
		}

		while (right - left > 1) {
			int mid = (left + right) / 2;
			if (get_hash(pr_first, pr_first + mid) != get_hash(pr_second, pr_second + mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		return right - 1;
	};

	s += '$';

	vector<int> prefix;
	for (int i = 0; i < len(s); i++) {
		prefix.pb(i);
	}

	auto get_prefix = [](int pr) {
		string rez = "";
		for (int i = pr; i < len(s); i++) {
			rez += s[i];
		}
		return rez;
	};
	sort(prefix.begin(), prefix.end(), [](int a, int b){
		return s[a] < s[b];
	});

	vector<int> group(len(s));
	group[prefix[0]] = 0;
	for (int i = 1; i < len(s); i++) {
		if (s[prefix[i]] == s[prefix[i - 1]]) {
			group[prefix[i]] = group[prefix[i - 1]];
		} else {
			group[prefix[i]] = group[prefix[i - 1]] + 1;
		}
	}

	for (int i = 0; i < len(s); i++) {
		

	}

	auto cmp = [&group](int pr_first, int pr_second, int elen){
		if (group[pr_first] < group[pr_second]) return true;
		if (group[pr_second] < group[pr_first]) return false;
		int sub_first = (pr_first + elen) % len(group);
		int sub_second = (pr_second + elen) % len(group);
		return group[sub_first] < group[sub_second];
	};


	for (int l = 1; l <= len(s) * 3; l *= 2) {
		vector<int> np(len(prefix));
		for (int i = 0; i < len(prefix); i++) {
			np[i] = floor_mod(prefix[i] - l, len(s));
		}

		vector<int> count(len(prefix), 0);
		for (int i = 0; i < len(prefix); i++) {
			count[group[prefix[i]]]++;
		}
		for (int i = 1; i < len(prefix); i++) {
			count[i] += count[i - 1];
		}

		for (int i = len(np) - 1; i > -1; i--) {
			prefix[--count[group[np[i]]]] = np[i];
		}

		vector<int> _new_group(len(s));
		_new_group[prefix[0]] = 0;
		for (int i = 1; i < len(s); i++) {
			if (!cmp(prefix[i], prefix[i - 1], l)
				&& !cmp(prefix[i - 1], prefix[i], l)) {
				_new_group[prefix[i]] = _new_group[prefix[i - 1]];
			} else {
				_new_group[prefix[i]] = _new_group[prefix[i - 1]] + 1;
			}
		}

		group = _new_group;
	}


	sort(prefix.begin(), prefix.end(), [&group](int a, int b) {
		return group[a] < group[b];
	});

	s.pop_back();

	prefix = vector<int>(prefix.begin() + 1, prefix.end());

	vector<int> fil;
	for (int p : prefix) {
		if (forb[p] == '1') continue;
		fil.pb(p);
	}
	prefix = fil;
	if (!prefix.empty()) {
		Node *cur = root->add(prefix[0], len(s));
		cur->ends++;
		for (int i = 1; i < len(prefix); i++) {
			int dcp = lcp(prefix[i], prefix[i - 1]);
			if (dcp == len(s) - prefix[i]) {
				assert(false);
				cur->ends++;
				continue;
			}
			while (dcp < cur->prev_len) {
				cur = cur->prev;
			}
			int eqs = dcp - cur->prev_len;
			cur = cur->cut_add(prefix[i] + cur->prev_len, len(s), eqs);
			cur->ends++;
		}

	}
	

	root->calc_end();
	print root->rehren();
}