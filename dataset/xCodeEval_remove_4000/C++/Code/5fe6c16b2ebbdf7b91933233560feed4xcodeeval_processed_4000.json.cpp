
























































































































































































































































































































































































































































































using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
template<typename IT>
ostream &print(IT b, IT e, string sep = " ", ostream &stream = cout){
    for(IT it = b; it != e; ++it){
        stream << *it;
        if(it+1 != e) stream << sep;
    } 
    return stream;
}
template<typename IT> istream &read(IT b, IT e, istream &stream = cin){
    for(IT it = b; it != e; ++it)
        stream >> *it; 
    return stream;
}
template<typename T> ostream &operator<<(ostream &stream, vector<T> &t){
    return print(all(t)," ",stream);
}
template<typename T> ostream &operator<<(ostream &stream, vector<T> &&t){
    return print(all(t)," ",stream);
}
template<typename T> istream &operator>>(istream &stream, vector<T> &t){
    return read(all(t),stream);
}
template<typename F, typename S> ostream &operator<<(ostream &stream, const pair<F,S> t){
    return stream << t.first << ' ' << t.second;
}
template<typename F, typename S> istream &operator>>(istream &stream, pair<F,S> &t){
    return stream >> t.first >> t.second;
}
template <typename T> 
void print(T x, string end = "\n"){
    cout << x << end;
}
template <typename t> 
void print(vector<t> arr,string sep=" "){
    if(arr.empty()){
        return;
    }
    print(arr.begin(),arr.end(),sep);
    cout << '\n';
}
template <typename T> 
void print(vector<vector<T> > arr){
    for(int i = 0; i < sz(arr); ++i){
        cout << "[" << arr[i] << "]";
        if(i+1 < sz(arr))
            cout << ", ";
    }
    cout << '\n';
}
template<typename T>
T _();
const ll MOD = 1e9+7;
template<typename T>
vector<T> operator+(const vector<T> &lhs, const vector<T> &rhs){
    vector<T> ans(lhs);
    assert(ans.size() == rhs.size());
    for(int i = 0; i < rhs.size(); ++i)
        ans[i] += rhs[i];
    return ans;
}
template<typename T>
vector<T> operator+=(vector<T> &lhs, const vector<T> &rhs){
    return lhs = lhs+rhs;
    

    

    

    

    

}
template<typename T>
vector<T> operator-(const vector<T> lhs, const vector<T> rhs){
    vector<T> ans(all(lhs));
    assert(ans.size() == rhs.size());
    for(int i = 0; i < rhs.size(); ++i)
        ans[i] -= rhs[i];
    return ans;
}
template<typename T>
vector<T> operator-=(vector<T> &lhs, const vector<T> &rhs){
    return lhs = lhs-rhs;
    

    

    

    

    

}
template<typename T>
vector<T> append(vector<T> &lhs, const vector<T> rhs){
    lhs.insert(lhs.end(),all(rhs));
    return lhs;
    

    

    

    

    

}
template<typename T>
T max(const vector<T> arr){
    assert(!arr.empty());
    T ans = arr[0];
    for(auto &cur : arr)
        ans = max(ans,cur);
    return ans;
}
template<typename T>
T max(const set<T> s){
    assert(!s.empty());
    return *--s.end();
}
template<typename T, typename G>
vector<T> set_max(vector<T> &base, const vector<G> &comp){
    assert(base.size() == comp.size());
    for(int i = 0; i < (int)comp.size(); ++i)
        base[i] = max(base[i],comp[i]);
    return base;
}

namespace Suffix{


	int AN;
	int A[3 * MAXN + 100];
	int cnt[MAXN + 1]; 

	int SA[MAXN + 1];

	
	void id2(int* A, int AN, int* R, int RN, int* D) {
		memset(cnt, 0, sizeof(int) * (AN + 1));
		int* C = cnt + 1;
		for(int i = 0; i < RN; i++) ++C[A[R[i]]];
		for(int i = -1, v = 0; i <= AN && v < RN; v += C[i++]) swap(v, C[i]);
		for(int i = 0; i < RN; i++) D[C[A[R[i]]]++] = R[i];
	}

	
	void suffix_array(int* A, int AN) {
		

		if(!AN) {
			SA[0] = 0;
		} else if(AN == 1) {
			SA[0] = 1; SA[1] = 0;
			return;
		}

		

		int RN = 0;
		int* SUBA = A + AN + 2;
		int* R = SUBA + AN + 2;
		for(int i = 1; i < AN; i += 3) SUBA[RN++] = i;
		for(int i = 2; i < AN; i += 3) SUBA[RN++] = i;
		A[AN + 1] = A[AN] = -1;
		id2(A + 2, AN - 2, SUBA, RN, R);
		id2(A + 1, AN - 1, R, RN, SUBA);
		id2(A + 0, AN - 0, SUBA, RN, R);

		

		

		int resfix, resmul, v;
		if(AN % 3 == 1) {
			resfix = 1; resmul = RN >> 1;
		} else {
			resfix = 2; resmul = (RN + 1) >> 1;
		}
		for(int i = v = 0; i < RN; i++) {
			v += i && (A[R[i - 1] + 0] != A[R[i] + 0] ||
					A[R[i - 1] + 1] != A[R[i] + 1] ||
					A[R[i - 1] + 2] != A[R[i] + 2]);
			SUBA[R[i] / 3 + (R[i] % 3 == resfix) * resmul] = v;
		}

		

		

		if(v + 1 != RN) {
			suffix_array(SUBA, RN);
			SA[0] = AN;
			for(int i = 1; i <= RN; i++) {
				SA[i] = SA[i] < resmul ? 3 * SA[i] + (resfix==1?2:1) :
					3 * (SA[i] - resmul) + resfix;
			}
		} else {
			SA[0] = AN;
			memcpy(SA + 1, R, sizeof(int) * RN);
		}

		

		int NMN = RN;
		for(int i = RN = 0; i <= NMN; i++) {
			if(SA[i] % 3 == 1) {
				SUBA[RN++] = SA[i] - 1;
			}
		}
		id2(A, AN, SUBA, RN, R);

		

		for(int i = 0; i <= NMN; i++) {
			SUBA[SA[i]] = i;
		}

		

		int ii = RN - 1;
		int jj = NMN;
		int pos;
		for(pos = AN; ii >= 0; pos--) {
			int i = R[ii];
			int j = SA[jj];
			int v = A[i] - A[j];
			if(!v) {
				if(j % 3 == 1) {
					v = SUBA[i + 1] - SUBA[j + 1];
				} else {
					v = A[i + 1] - A[j + 1];
					if(!v) v = SUBA[i + 2] - SUBA[j + 2];
				}
			}
			SA[pos] = v < 0 ? SA[jj--] : R[ii--];
		}
	}

	char s[MAXN + 1];

	
	void prep_string() {
		int v = AN = 0;
		memset(cnt, 0, 256 * sizeof(int));
		for(char* ss = s; *ss; ++ss, ++AN) cnt[*ss]++;
		for(int i = 0; i < AN; i++) cnt[s[i]]++;
		for(int i = 0; i < 256; i++) cnt[i] = cnt[i] ? v++ : -1;
		for(int i = 0; i < AN; i++) A[i] = cnt[s[i]];
	}

	
	int REVSA[MAXN + 1];
	void id1() {
		for(int i = 0; i < AN; i++) {
			REVSA[SA[i]] = i;
		}
	}

	
	int LCP[MAXN + 1];
	void id0() {
		int len = 0;
		for(int i = 0; i < AN; i++, len = max(0, len - 1)) {
			int s = REVSA[i];
			int j = SA[s - 1];
			for(; i + len < AN && j + len < AN && A[i + len] == A[j + len]; len++);
			LCP[s] = len;
		}
	}
	vi get_sa(string _s){
		strcpy(s,_s.c_str());
		int AN = strlen(s);

		prep_string();
		suffix_array(A, AN);
		id1();
		vi ans(AN);
		for(int i = 1; i <= AN; ++i)
			ans[i-1] = SA[i];
		return ans;
	}
}
void _(){
	string s;
	cin >> s;
	int n = s.size();
	{
		vpii bracket;
		for(int i = 0; i < n; ++i){
			if(bracket.empty() || s[i] == '(')
				bracket.pb({i,s[i]==')'});
			else{
				if(bracket.back().second == 0)
					bracket.pop_back();
				else
					bracket.pb({i,1});
			}
		}
		int req = 0;
		for(int i = 0; i < sz(bracket); ++i)
			if(bracket[i].second == 1)
				req = max(req,bracket[i].first);
		

		s = s.substr(req)+s.substr(0,req);
		

	}
	vi banned(n+1);
	{
		vpii bracket;
		vpii add;
		for(int i = 0; i < n; ++i){
			if(bracket.empty() || s[i] == '(')
				bracket.pb({i,s[i]==')'});
			else{
				if(bracket.back().second == 0){
					banned[bracket.back().first+1] += 1;
					banned[i+1] -= 1;
					bracket.pop_back();
				}
				else
					bracket.pb({i,1});
			}
		}
		for(int i = 1; i < n; ++i)
			banned[i] += banned[i-1];

	}
	s = s+s;
	

	auto sa = Suffix::get_sa(s);
	

	

	for(int x : sa){
		if(x < n && !banned[x]){
			s = s.substr(x,n);
			break;
		}
	}
	int a = count(all(s),'(');
	int b = count(all(s),')');
	

	

	

	if(a > b)
		s += string(a-b,')');
	else
		s = string(b-a,'(')+s;
	print(s);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(15);
    _();
}
