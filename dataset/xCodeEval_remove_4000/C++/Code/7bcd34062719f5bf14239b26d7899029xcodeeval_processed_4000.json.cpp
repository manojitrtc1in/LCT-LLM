































using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

class SuffixTree {
	struct Leaf;
public:
	static const int TerminatingAlphas = 200000;
	typedef unsigned int Alpha; static const int NAlpha = TerminatingAlphas + 256;
	typedef map<Alpha,Leaf*> EdgeMap;
	static inline bool IsTerminatingAlpha(Alpha a) { return a < TerminatingAlphas; }
	typedef size_t Index;	

	typedef unsigned long long Count;	

	typedef unsigned Bitset;
	typedef std::pair<const Alpha*, const Alpha*> StrPair;
	static const int ListToMapParam;

private:
	struct Leaf {
		const Alpha *begin, *end;
		Leaf *next;
		Leaf() { }
		Leaf(const Alpha *b): begin(b), next(NULL), end(NULL) { }
		Alpha id1() const { return *(end-1); }
		Index length() const { return end - begin; }	

	};
	struct Node : Leaf {	

		union { Leaf *head; EdgeMap *edgeMap; };
		Node *suffix;
		Node() { suffix = NULL; head = NULL; }
	};
	struct EdgeIterator {
		bool type;
		Leaf *listIt;
		EdgeMap::iterator mapIt, mapEnd;
		friend SuffixTree;

		operator bool() const {
			return !type ? listIt != NULL : mapIt != mapEnd;
		}
		EdgeIterator &operator++() {
			if(!type)
				listIt = listIt->next;
			else
				++ mapIt;
			return *this;
		}
		Leaf *operator*() const {
			if(!type)
				return listIt;
			else
				return mapIt->second;
		}

	private:
		EdgeIterator(): type(false), listIt(), mapIt(), mapEnd() { }
	};

	EdgeIterator getEdgeIterator(Node *p) const {
		EdgeIterator it;
		if(isListStyle(p)) {
			it.type = false;
			it.listIt = p->head;
		}else {
			it.type = true;
			it.mapIt = p->edgeMap->begin();
			it.mapEnd = p->edgeMap->end();
		}
		return it;
	}

	Index nNodes, id6;
	Node *nodes; Leaf *leafs, *poolend;
	Node *root;
	Alpha *stringBuffer;	

	vector<EdgeMap*> edgeMaps;
	std::vector<std::pair<Alpha*,Alpha*> > addedStrings;	

	

	std::vector<const Node*> nodeSequence, nodeParent, leafParent;
	std::vector<const Leaf*> leafSequence;
	std::vector<Index> leafIndex;
	

	std::vector<Index> nodeLeftPos, nodeRightPos;
	

	std::vector<Index> nodeDepth, leafDepth;
	

	std::vector<Index> stringCount;
	
	

	

public:
	SuffixTree(Index n);	

	~SuffixTree();

private:
	bool isLeaf(const Leaf *p) const { return leafs <= p; }
	bool isListStyle(const Node *p) const { return !p->head || ((Leaf*)nodes <= p->head && p->head < poolend); }

	EdgeMap *listToMap(Node *node);
	Leaf **getEdgeRef(Node *node, Alpha a);
	Leaf *getEdge(const Node *node, Alpha a) const;
	void addEdge(Node *node, Alpha a, Leaf *edge);

	static const Alpha *findStringEnd(const Alpha *str) { while(!IsTerminatingAlpha(*str)) ++ str; return str; }

	void addStringMain(const Alpha *str);
public:
	

	

	void addString(const Alpha *begin, const Alpha *end, Alpha id1);
	

	void addString(const Alpha *str);
	

	

	StrPair getString(int i = 0) const { return addedStrings.at(i); }

	

	

public:
	void preorderTraversal();
	

	void calcNodeInterval();
	

	void calcNodeDepth();
private:
	Index getSubstringLength(const Leaf *leaf) const;	

	const Alpha *getSubstringBegin(const Leaf *leaf) const;	

	Index nodeIntervalLength(const Node *node) const;	


private:
	struct Position {
		const Leaf *leaf;
		const Alpha *pos;
		Position(const Leaf *l, const Alpha *p): leaf(l), pos(p) { }
	};
	inline Position initialPosition() const { return Position(root, NULL); }
	void matchAlpha(Position &p, Alpha a) const;
	void matchString(Position &p, const Alpha *begin, const Alpha *end) const;

public:

	void getPoints(vector<pair<pii,int> > &points);
	pair<pii,int> getIntervalAndDepth(const Alpha *begin, const Alpha *end) const;



	

	

private:
	static void outAlpha(std::ostream &o, Alpha a);
	void outLeafName(std::ostream &o, const Leaf *leaf) const;
	void outRec(std::ostream &o, const Node *node, bool visSuffix) const;

public:
	void debugOutDotGraph(std::ostream &o, bool visSuffix = true) const;
	void debugOutDotGraphE() const;

private:
	std::string debugGetPathString(const Leaf *leaf, bool id3 = true) const;
};


	for(EdgeIterator e
	if(c Leaf *e = *e




const int SuffixTree::ListToMapParam = min(50, (int)std::pow(NAlpha*1., 0.4));

SuffixTree::SuffixTree(Index n) : nNodes(0), id6(0) {
	assert(n > 0);
	size_t poolSize = sizeof(Node) * n + sizeof(Leaf) * n;
	char *pool = static_cast<char*>(std::malloc(poolSize));
	nodes = reinterpret_cast<Node*>(pool);
	leafs = reinterpret_cast<Leaf*>(pool + n * sizeof(Node));
	poolend = reinterpret_cast<Leaf*>(pool + poolSize);
	stringBuffer = static_cast<Alpha*>(std::malloc(n * sizeof(Alpha)));

	root = new(&nodes[nNodes ++]) Node();
	root->begin = root->end = NULL;
}
SuffixTree::~SuffixTree() {
	free(nodes);
	for(size_t i = 0; i < edgeMaps.size(); ++ i)
		delete edgeMaps[i];
	free(stringBuffer);
}

SuffixTree::EdgeMap *SuffixTree::listToMap(Node *node) {
	EdgeMap *edgeMap = new EdgeMap;
	FOR_EACH_EDGES_V(leaf, node)
		(*edgeMap)[*leaf->begin] = leaf;
	edgeMaps.push_back(edgeMap);
	return edgeMap;
}

SuffixTree::Leaf **SuffixTree::getEdgeRef(Node *node, Alpha a) {
	if(!isListStyle(node)) {
		return &(*node->edgeMap)[a];
	}
	Leaf **ref; int len = 0;
	for(ref = &node->head; *ref != NULL; ref = &(*ref)->next, ++ len) {
		if(len >= ListToMapParam)
			return &(*(node->edgeMap = listToMap(node)))[a];
		if(*(*ref)->begin == a)
			return ref;
	}
	return ref;
}
SuffixTree::Leaf *SuffixTree::getEdge(const Node *node, Alpha a) const {
	if(!isListStyle(node)) {
		EdgeMap::iterator it = node->edgeMap->find(a);
		return it == node->edgeMap->end() ? NULL : it->second;
	}
	for(Leaf *leaf = node->head; leaf != NULL; leaf = leaf->next)
		if(*leaf->begin == a) return leaf;
	return NULL;
}
void SuffixTree::addEdge(Node *node, Alpha a, Leaf *edge) {
	if(!isListStyle(node)) {
		(*node->edgeMap)[a] = edge;
	}else {
		Leaf *head = node->head;
		node->head = edge;
		edge->next = head;
	}
}



void SuffixTree::addStringMain(const Alpha *str) {
	Node *active = root; const Alpha *activePos = 0; Index activeLen = 0;
	const Alpha *currentPos = str, *proceeded = str;
	Index id5 = id6;
	do {
		Alpha currentAlpha = *currentPos; Node *prevNode = NULL;
		while(proceeded <= currentPos) {
			if(activeLen == 0) activePos = currentPos;
			Leaf **activeEdgeRef = getEdgeRef(active, *activePos);
			Leaf *activeEdge = *activeEdgeRef;
			Node *splitNode = active;
			if(activeEdge) {
				if(!isLeaf(activeEdge) && activeLen >= activeEdge->length()) {
					active = (Node*)activeEdge;
					activePos += ((Node*)activeEdge)->length();
					activeLen -= ((Node*)activeEdge)->length();
					continue;
				}else if(*(activeEdge->begin + activeLen) == currentAlpha) {
					activeLen ++;
					if(prevNode) prevNode->suffix = active;
					break;
				}else {
					const Alpha *splitPos = activeEdge->begin + activeLen;
					Leaf *nextLeaf = activeEdge->next;
					*activeEdgeRef = splitNode = new(&nodes[nNodes ++]) Node();
					splitNode->begin = activeEdge->begin;
					splitNode->end = activeEdge->begin = splitPos;
					addEdge(splitNode, *splitPos, activeEdge);
					splitNode->next = nextLeaf;
				}
			}
			addEdge(splitNode, currentAlpha, new(&leafs[id6 ++]) Leaf(currentPos));
			if(prevNode) prevNode->suffix = splitNode;
			prevNode = splitNode;
			proceeded ++;
			if(active == root && activeLen > 0) {
				activeLen --;
				activePos = proceeded;
			}else
				active = active->suffix ? active->suffix : root;
		}
	}while(!IsTerminatingAlpha(*(currentPos ++)));
	assert(currentPos == proceeded);
	for(Index i = id5; i < id6; i ++)
		leafs[i].end = currentPos;
}

void SuffixTree::addString(const Alpha *begin, const Alpha *end, Alpha id1) {
	Index len = end - begin;
	Alpha *copied = addedStrings.empty() ? stringBuffer : addedStrings.back().second + 1;
	std::memcpy(copied, begin, len * sizeof(Alpha));
	copied[len] = id1;
	addedStrings.push_back(std::make_pair(copied, copied + len));
	addStringMain(copied);
}

void SuffixTree::addString(const Alpha *str) {
	const Alpha *endp = findStringEnd(str);
	return addString(str, endp, *endp);
}

void SuffixTree::preorderTraversal() {
	leafSequence.assign(id6, NULL);
	leafParent.assign(id6, NULL);
	leafIndex.assign(id6, Index(-1));
	nodeSequence.assign(nNodes, NULL);
	nodeParent.assign(nNodes, NULL);

	Index leafCount = 0, nodeCount = 0;
	std::vector<const Node*> stk; stk.reserve(nNodes);
	stk.push_back(root);
	while(!stk.empty()) {
		const Node *node = stk.back(); stk.pop_back();
		nodeSequence[nodeCount ++] = node;
		id4(edge, node) {
			if(isLeaf(edge)) {
				leafIndex[edge - leafs] = leafCount;
				leafSequence[leafCount ++] = edge;
				leafParent[edge - leafs] = node;
			}else {
				const Node *child = static_cast<const Node*>(edge);
				nodeParent[child - nodes] = node;
				stk.push_back(child);
			}
		}
	}
	assert(leafCount == id6 && nodeCount == nNodes);
}

void SuffixTree::calcNodeDepth() {
	assert(!nodeSequence.empty());
	leafDepth.assign(id6, -1);
	nodeDepth.assign(nNodes, -1);

	nodeDepth[root - nodes] = 0;
	for(Index ii = 0; ii < nNodes; ++ ii) {
		const Node *node = nodeSequence[ii];
		int depth = nodeDepth[node - nodes];
		id4(edge, node) {
			if(isLeaf(edge)) {
				leafDepth[edge - leafs] = depth + edge->length();
			}else {
				const Node *child = static_cast<const Node*>(edge);
				nodeDepth[child - nodes] = depth + edge->length();
			}
		}
	}
}

SuffixTree::Index SuffixTree::getSubstringLength(const Leaf *leaf) const {
	if(isLeaf(leaf))
		return leafDepth[leaf - leafs] - 1;	

	else
		return nodeDepth[static_cast<const Node*>(leaf) - nodes];
}

const SuffixTree::Alpha *SuffixTree::getSubstringBegin(const Leaf *leaf) const {
	return leaf->end - (isLeaf(leaf) ? 1 : 0) - getSubstringLength(leaf);
}

void SuffixTree::calcNodeInterval() {
	assert(!nodeSequence.empty());
	nodeLeftPos.assign(nNodes, -1);
	nodeRightPos.assign(nNodes, -1);

	for(Index i = 0; i < id6; i ++) {
		const Leaf *leaf = leafSequence[i];
		const Node *parent = leafParent[leaf - leafs];
		Index &pLeft = nodeLeftPos[parent - nodes], &pRight = nodeRightPos[parent - nodes];
		if(pLeft == -1 || i < pLeft) pLeft = i;
		if(pRight == -1 || pRight < i + 1) pRight = i + 1;
	}
	if(nNodes > 0) for(Index ii = nNodes - 1; ii > 0; -- ii) {
		const Node *node = nodeSequence[ii];
		const Node *parent = nodeParent[node - nodes];
		Index &pLeft = nodeLeftPos[parent - nodes], &pRight = nodeRightPos[parent - nodes];
		Index cLeft = nodeLeftPos[node - nodes], cRight = nodeRightPos[node - nodes];
		if(pLeft == -1 || cLeft < pLeft) pLeft = cLeft;
		if(pRight == -1 || pRight < cRight) pRight = cRight;
	}
}


void SuffixTree::matchAlpha(Position &p, Alpha a) const {
	if(!p.leaf) return;
	if(p.leaf->end == p.pos) {
		const Leaf *edge = getEdge(static_cast<const Node*>(p.leaf), a);
		p.leaf = edge;
		if(edge) p.pos = edge->begin + 1;
	}else {
		if(*p.pos == a) ++ p.pos;
		else p.leaf = NULL;
	}
}

void SuffixTree::matchString(Position &p, const Alpha *begin, const Alpha *end) const {
	while(begin < end) matchAlpha(p, *(begin ++));
}

void SuffixTree::getPoints(vector<pair<pii,int> > &points) {
	points.clear();
	for(Index ix = 0; ix < id6; ix ++) {
		Index i = leafSequence[ix] - leafs;
		Index depth = leafDepth[i], edgeLen = leafs[i].length();
		Alpha alpha = leafs[i].id1();
		points.push_back(mp(mp(ix, alpha), depth - 1));
	}
}

pair<pii,int> SuffixTree::getIntervalAndDepth(const Alpha *begin, const Alpha *end) const {
	Position p = initialPosition();
	matchString(p, begin, end);
	const Leaf *leaf = p.leaf;
	int left, right, depth;
	if(leaf == NULL) {
		left = right = depth = 0;
	}else if(isLeaf(leaf)) {
		left = leafIndex[leaf - leafs], right = left + 1;
		depth = leafDepth[leaf - leafs] - (leaf->end - p.pos);
	}else {
		const Node *node = static_cast<const Node*>(leaf);
		left = nodeLeftPos[node - nodes], right = nodeRightPos[node - nodes];
		depth = nodeDepth[node - nodes] - (node->end - p.pos);
	}
	return mp(mp(left, right), depth);
}

struct FenwickTree {
	typedef long long T;
	vector<T> v;
	void init(int n) { v.assign(n, 0); }
	void add(int i, T x) {
		for(; i < (int)v.size(); i |= i+1) v[i] += x;
	}
	T sum(int i) const {	

		T r = 0;
		for(-- i; i >= 0; i = (i & (i+1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) const {	

		return sum(right) - sum(left);
	}
};


void id0(vector<pair<pii,int> > points, vector<pair<pii,pii> > queries, vector<long long> &ans) {
	int n = points.size(), m = queries.size();
	vector<int> positions;
	rep(i, n) positions.pb(points[i].first.second);
	sort(all(positions));
	positions.erase(unique(all(positions)), positions.end());
	int p = positions.size();
	FenwickTree t; t.init(p);
	sort(all(points)); sort(all(queries));
	int left = 0;
	rep(i, m) {
		int x = queries[i].first.first;
		while(left < n && points[left].first.first < x) {
			int j = lower_bound(all(positions), points[left].first.second) - positions.begin();
			t.add(j, points[left].second);
			left ++;
		}
		int y = lower_bound(all(positions), queries[i].first.second) - positions.begin();
		ans[queries[i].second.first] += t.sum(y) * queries[i].second.second;
	}
}


void SuffixTree::outAlpha(std::ostream &o, Alpha a) {
	if(IsTerminatingAlpha(a)) {
		o << '$';
		if(a != 0) o << static_cast<unsigned>(a);
	}else {
		o << static_cast<char>(a - TerminatingAlphas);
	}
}
void SuffixTree::outLeafName(std::ostream &o, const Leaf *leaf) const {
	if(isLeaf(leaf))
		o << '"'  << leafIndex[leaf - leafs] << '"';
	else
		o << '"' << 'n' << nodeLeftPos[static_cast<const Node*>(leaf) - nodes] << '"';
}
void SuffixTree::outRec(std::ostream &o, const Node *node, bool visSuffix) const {
	if(visSuffix && node->suffix != NULL) {
		outLeafName(o, node); o << " -> "; outLeafName(o, node->suffix); o << ' ';
		o << "[style=dotted, constraint=false]" << ";\n";
	}
	id4(edge, node) {
		outLeafName(o, node); o << " -> "; outLeafName(o, edge); o << ' ';
		o << "[label=<";
		for(const Alpha *p = edge->begin; p < edge->end; ++ p) {
			outAlpha(o, *p);
		}
		o << ">];\n";
		if(!isLeaf(edge))
			outRec(o, (Node*)edge, visSuffix);
	}
}

void SuffixTree::debugOutDotGraph(std::ostream &o, bool visSuffix) const {
	o << "digraph {\n";
	o << "style = dot;\n";
	o << "node";

	outRec(o, root, visSuffix);
	o << "}" << std::endl;
}

void SuffixTree::debugOutDotGraphE() const {
	debugOutDotGraph(std::cerr, false);
}

std::string SuffixTree::debugGetPathString(const Leaf *leaf, bool id3) const {
	std::vector<Alpha> alphas;
	const Node *node;
	if(isLeaf(leaf)) {
		if(id3)
			alphas.push_back(leaf->id1());
		for(const Alpha *p = leaf->end-2; p != leaf->begin-1; -- p)
			alphas.push_back(*p);
		node = leafParent[leaf - leafs];
	}else {
		node = static_cast<const Node*>(leaf);
	}
	while(node != root) {
		for(const Alpha *p = node->end-1; p != node->begin-1; -- p)
			alphas.push_back(*p);
		node = nodeParent[node - nodes];
	}
	std::stringstream ss;
	for(std::vector<Alpha>::const_reverse_iterator it = alphas.rbegin(); it != alphas.rend(); ++ it)
		outAlpha(ss, *it);
	return ss.str();
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	vector<string> Ss(n);
	int lensum = 0;
	rep(i, n) {
		cin >> Ss[i];
		lensum += Ss[i].size() + 1;
	}
	SuffixTree st(lensum);
	vector<SuffixTree::Alpha> buf(200001);
	rep(i, n) {
		int n = Ss[i].size();
		rep(j, n)
			buf[j] = SuffixTree::TerminatingAlphas + Ss[i][j];
		buf[n] = i;
		st.addString(&buf[0]);
	}
	st.preorderTraversal();
	st.calcNodeDepth();
	st.calcNodeInterval();
	vector<pair<pii,int> > points;
	st.getPoints(points);

	vector<pair<pii,int> > points2(points.size());
	rep(i, points.size())
		points2[i] = mp(points[i].first, 1);

	vector<pair<pii,int> > id2(n);
	rep(i, n) {
		int n = Ss[i].size();
		rep(j, n)
			buf[j] = SuffixTree::TerminatingAlphas + Ss[i][j];
		buf[n] = i;
		id2[i] = st.getIntervalAndDepth(&buf[0], &buf[0] + Ss[i].size());
	}

	vector<pair<pii,pii> > queries, queries2;
	rep(i, q) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k), -- l, -- k;

		pair<pii,int> p = id2[k];
		int left = p.first.first, right = p.first.second;
		int d = p.second;

		queries2.push_back(mp(mp(right, r), mp(i, +1)));
		queries2.push_back(mp(mp(left, r), mp(i, -1)));
		queries2.push_back(mp(mp(right, l), mp(i, -1)));
		queries2.push_back(mp(mp(left, l), mp(i, +1)));
	}




	vector<ll> ans(q, 0);


	id0(points2, queries2, ans);

	rep(i, q)
		printf("%I64d\n", ans[i]);

	return 0;
}
