
using namespace std;
using ll = long long;
using ull = unsigned long long;






template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433;

template <class T> vector<T> id0(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto id0(size_t N,T... t){return vector<decltype(id0(t...))>(N,id0(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}

template<class Operator> class id2 {
    Operator Op;                                         

	using typeNode = decltype(Op.unitNode);              

	using typeLazy = decltype(Op.unitLazy);              

	size_t length;                                       

	size_t height;                                       

	vector<typeNode> node;                               

	vector<typeLazy> lazy;                               

	vector<int> width;                                   

public:

	

	id2(const size_t num) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		width.resize(2 * length, 0);
		for (int i = 0; i < num; ++i) node[i + length] = Op.unitNode;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

	

	id2(const size_t num, const typeNode init) {
		for (length = 1,height = 0; length < num; length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		for (int i = 0; i < num; ++i) node[i + length] = init;
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}

	

	id2(const vector<typeNode>& vec) {
		for (length = 1,height = 0; length < vec.size(); length *= 2, height++);
		node.resize(2 * length, Op.unitNode);
		lazy.resize(2 * length, Op.unitLazy);
		for (int i = 0; i < vec.size(); ++i) node[i + length] = vec[i];
		for (int i = length - 1; i >= 0; --i) node[i] = Op.funcNode(node[(i<<1)+0],node[(i<<1)+1]);
		width.resize(2 * length, 0);
		for(int i = length; i < 2*length; ++i) for(int j = i, k = 1; j && !width[j] ; j >>= 1,k <<= 1) width[j] = k;
	}


	void propagate(int k) {
		if(lazy[k] == Op.unitLazy) return;
		node[k] = Op.funcMerge(node[k],lazy[k],width[k]);
		if(k < length) lazy[2*k+0] = Op.funcLazy(lazy[2*k+0],lazy[k]);
		if(k < length) lazy[2*k+1] = Op.funcLazy(lazy[2*k+1],lazy[k]);
		lazy[k] = Op.unitLazy;
    }


	

    void update(int a, int b, typeLazy x) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) lazy[l] = Op.funcLazy(lazy[l],x), propagate(l),l++;
			if(r&1) --r,lazy[r] = Op.funcLazy(lazy[r],x), propagate(r);
		}
		l = a + length, r = b + length - 1;
		while ((l>>=1),(r>>=1),l) {
			if(lazy[l] == Op.unitLazy) node[l] = Op.funcNode(Op.funcMerge(node[(l<<1)+0],lazy[(l<<1)+0],width[(l<<1)+0]),Op.funcMerge(node[(l<<1)+1],lazy[(l<<1)+1],width[(l<<1)+1]));
			if(lazy[r] == Op.unitLazy) node[r] = Op.funcNode(Op.funcMerge(node[(r<<1)+0],lazy[(r<<1)+0],width[(r<<1)+0]),Op.funcMerge(node[(r<<1)+1],lazy[(r<<1)+1],width[(r<<1)+1]));
		}
    }

	

	typeNode get(int a, int b) {
		int l = a + length, r = b + length - 1;
		for (int i = height; 0 < i; --i) propagate(l >> i), propagate(r >> i);
		typeNode vl = Op.unitNode, vr = Op.unitNode;
		for(r++; l < r; l >>=1, r >>=1) {
			if(l&1) vl = Op.funcNode(vl,Op.funcMerge(node[l],lazy[l],width[l])),l++;
			if(r&1) r--,vr = Op.funcNode(Op.funcMerge(node[r],lazy[r],width[r]),vr);
		}
		return Op.funcNode(vl,vr);
	}

	void print(){
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		cout << "vector" << endl;
		cout << "{ " << get(0,1);
		for(int i = 1; i < length; ++i) cout << ", " << get(i,i+1);
		cout << " }" << endl;
	}

};



template<class typeNode, class typeLazy> struct nodeSumLazyAdd {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return l+r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return l+r*len;}
    

};



template<class typeNode, class typeLazy> struct nodeMinLazyAdd {
	typeNode unitNode = 1234567890;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
	typeLazy funcLazy(typeLazy l,typeLazy r){return l+r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return l+r;}
    

	

};



template<class typeNode, class typeLazy> struct nodeModSumLazyModAdd {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return (l+r)%MOD;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return (l+r)%MOD;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return (l+(r*len)%MOD)%MOD;}
	

    

};



template<class typeNode, class typeLazy> struct nodeMaxLazyUpdate {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return max(l,r);}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=0?r*len:l;}
    

    

};



template<class typeNode, class typeLazy> struct nodeMinLazyUpdate {
	typeNode unitNode = 12345678910;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return min(l,r);}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=0?r*len:l;}
	

    

};



template<class typeNode, class typeLazy> struct nodeGCDLazyUpdate {
	typeNode unitNode = 0;
	typeLazy unitLazy = 0;
	typeNode funcNode(typeNode l,typeNode r){return ((r == 0) ? l : funcNode(r, l % r));}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=0?r:l;}
    

    

};



template<class typeNode, class typeLazy> struct nodeSumLazyUpdate {
	typeNode unitNode = 0;
	typeLazy unitLazy = -2000;
	typeNode funcNode(typeNode l,typeNode r){return l+r;}
	typeLazy funcLazy(typeLazy l,typeLazy r){return r;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=-2000?r*len:l;}
	

    

};




template<class typeNode, class typeLazy> struct nodeSetLazyInsert {
	typeNode unitNode = typeNode();
	typeLazy unitLazy = typeLazy();
	typeNode funcNode(typeNode l,typeNode& r){for(auto& i:r) l.insert(i);return l;}
	typeLazy funcLazy(typeLazy l,typeLazy& r){for(auto& i:r) l.insert(i);return l;}
	typeNode funcMerge(typeNode l,typeLazy r,int len){return r!=typeLazy()?r:l;}
};




template<class T> vector<int> Zarts(const vector<T> & ar, int cnt = 0) {
    vector<int> res;
    map<T, int> mp;
    for (auto &e : ar) mp[e] = 0;
    for (auto &e : mp) e.second = cnt++;
    for (auto &e : ar) res.push_back(mp[e]);
    return res;
}





int main() {
	SPEED
	int N; cin >> N;
	vector<ll> L1(N),R1(N),L2(N),R2(N);
	PQR<pair<ll,pair<int,int>>> pq1,pq2;
	for(int i = 0; i < N; ++i){
		cin >> L1[i] >> R1[i] >> L2[i] >> R2[i];
		pq1.push({L1[i],{0,i}}); 
		pq1.push({R1[i],{1,i}});
		pq2.push({L2[i],{0,i}});
		pq2.push({R2[i],{1,i}});
	}
	set<int> st;
	multiset<ll> stL,stR;
	while(pq1.size()){
		auto p = pq1.top();
		int lr = p.second.first;
		int i = p.second.second;
		pq1.pop();
		if(lr==0){
			st.insert(i);
			stL.insert(L2[i]);
			stR.insert(R2[i]);
		}
		else{
			if(st.size()){
				ll id1 = *stL.rbegin();
				ll miniR = *stR.begin();
				corner(id1>miniR,"NO");
			}
			st.erase(i);
			stL.erase(stL.find(L2[i]));
			stR.erase(stR.find(R2[i]));
		}
	}
	while(pq2.size()){
		auto p = pq2.top();
		int lr = p.second.first;
		int i = p.second.second;
		pq2.pop();
		if(lr==0){
			st.insert(i);
			stL.insert(L1[i]);
			stR.insert(R1[i]);
		}
		else{
			if(st.size()){
				ll id1 = *stL.rbegin();
				ll miniR = *stR.begin();
				corner(id1>miniR,"NO");
			}
			st.erase(i);
			stL.erase(stL.find(L1[i]));
			stR.erase(stR.find(R1[i]));
		}
	}
	cout << "YES" << endl;
 	return 0;
}
