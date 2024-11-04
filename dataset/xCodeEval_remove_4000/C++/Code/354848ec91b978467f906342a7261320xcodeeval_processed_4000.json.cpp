










using namespace std;
 








 
namespace solve {
 
class SuffixTree {
public:
    

    

    

    

    typedef unsigned char Alpha; static const int NAlpha = 256;
    static inline bool IsTerminatingAlpha(Alpha a) { return a < 32; }
    typedef size_t Index;   

    typedef unsigned long long Count;   

    typedef std::pair<const Alpha*, const Alpha*> StrPair;
    static const int ListToArrayParam;
 
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

        union { Leaf *head; Leaf **edges; };
        Node *suffix;
        Node() { suffix = NULL; head = NULL; }
    };
 
    Index nNodes, id3;
    Node *nodes; Leaf *leafs, *poolend;
    Node *root;
    Alpha *stringBuffer;    

    std::vector<Leaf**> edgeArrays;
    std::vector<std::pair<Alpha*,Alpha*> > addedStrings;    

    

    std::vector<const Node*> nodeSequence, nodeParent, leafParent;
    std::vector<const Leaf*> leafSequence;
    

    std::vector<Index> nodeDepth, leafDepth;
 
    std::vector<std::vector<Index> > numDescendantLeafs;    

    
    

    

public:
    SuffixTree(Index n);    

    ~SuffixTree();
 
private:
    bool isLeaf(const Leaf *p) const { return leafs <= p; }
    bool isListStyle(const Node *p) const { return !p->head || ((Leaf*)nodes <= p->head && p->head < poolend); }
 
    Leaf **listToArray(Node *node);
    Leaf **getEdgeRef(Node *node, Alpha a);
    Leaf *getEdge(const Node *node, Alpha a) const;
    void addEdge(Node *node, Alpha a, Leaf *edge);
 
    static const Alpha *findStringEnd(const Alpha *str) { while(!IsTerminatingAlpha(*str)) ++ str; return str; }
 
    void addStringMain(const Alpha *str);
public:
    

    

    void addString(const Alpha *begin, const Alpha *end, Alpha id1);
    

    void addString(const Alpha *str);
 
    

    

public:
    void inorderTraversal();
    

    void calcNodeDepth();
 
    

public:
    void calcNumDescendantLeafs();
    void countCommonSubstrings(Count cnts[]) const; 

};
 

    for(Leaf *c *e
    isListStyle(n) ? (*e
    isListStyle(n) ? (e
    if(c Leaf *e = *e


 
 
const int SuffixTree::ListToArrayParam = (int)std::pow(NAlpha*1., 0.4); 

 
SuffixTree::SuffixTree(Index n) : nNodes(0), id3(0) {
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
    for(size_t i = 0; i < edgeArrays.size(); i ++) free(edgeArrays[i]);
    free(stringBuffer);
}
 
SuffixTree::Leaf **SuffixTree::listToArray(Node *node) {
    Leaf **edges = static_cast<Leaf**>(std::malloc(NAlpha * sizeof(Leaf*)));
    memset(edges, 0, sizeof(Leaf*) * NAlpha);
    FOR_EACH_EDGES_V(leaf, node)
        edges[*leaf->begin] = leaf;
    edgeArrays.push_back(edges);
    return edges;
}
 
SuffixTree::Leaf **SuffixTree::getEdgeRef(Node *node, Alpha a) {
    if(!isListStyle(node)) return &node->edges[a];
    Leaf **ref; int len = 0;
    for(ref = &node->head; *ref != NULL; ref = &(*ref)->next, ++ len) {
        if(len >= ListToArrayParam)
            return &(node->edges = listToArray(node))[a];
        if(*(*ref)->begin == a)
            return ref;
    }
    return ref;
}
SuffixTree::Leaf *SuffixTree::getEdge(const Node *node, Alpha a) const {
    if(!isListStyle(node)) return node->edges[a];
    for(Leaf *leaf = node->head; leaf != NULL; leaf = leaf->next)
        if(*leaf->begin == a) return leaf;
    return NULL;
}
void SuffixTree::addEdge(Node *node, Alpha a, Leaf *edge) {
    if(!isListStyle(node)) {
        node->edges[a] = edge;
    }else {
        Leaf *head = node->head;
        node->head = edge;
        edge->next = head;
    }
}
 


void SuffixTree::addStringMain(const Alpha *str) {
    Node *active = root; const Alpha *activePos; Index activeLen = 0;
    const Alpha *currentPos = str, *proceeded = str;
    Index id2 = id3;
    do {
        Alpha currentAlpha = *currentPos; Node *prevNode = NULL;
        while(proceeded <= currentPos) {
            if(activeLen == 0) activePos = currentPos;
            Leaf **id0 = getEdgeRef(active, *activePos);
            Leaf *activeEdge = *id0;
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
                    *id0 = splitNode = new(&nodes[nNodes ++]) Node();
                    splitNode->begin = activeEdge->begin;
                    splitNode->end = activeEdge->begin = splitPos;
                    addEdge(splitNode, *splitPos, activeEdge);
                    splitNode->next = nextLeaf;
                }
            }
            addEdge(splitNode, currentAlpha, new(&leafs[id3 ++]) Leaf(currentPos));
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
    for(Index i = id2; i < id3; i ++)
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
 
 
void SuffixTree::inorderTraversal() {
    leafSequence.assign(id3, NULL);
    leafParent.assign(id3, NULL);
    nodeSequence.assign(nNodes, NULL);
    nodeParent.assign(nNodes, NULL);
 
    Index leafCount = 0, nodeCount = 0;
    std::vector<const Node*> stk; stk.reserve(nNodes);
    stk.push_back(root);
    while(!stk.empty()) {
        const Node *node = stk.back(); stk.pop_back();
        nodeSequence[nodeCount ++] = node;
        FOR_EACH_EDGES_C(edge, node) {
            if(isLeaf(edge)) {
                leafSequence[leafCount ++] = edge;
                leafParent[edge - leafs] = node;
            }else {
                const Node *child = static_cast<const Node*>(edge);
                nodeParent[child - nodes] = node;
                stk.push_back(child);
            }
        }
    }
    assert(leafCount == id3 && nodeCount == nNodes);
}
 
void SuffixTree::calcNodeDepth() {
    assert(!nodeSequence.empty());
    leafDepth.assign(id3, -1);
    nodeDepth.assign(nNodes, -1);
 
    nodeDepth[root - nodes] = 0;
    for(Index ii = 0; ii < nNodes; ++ ii) {
        const Node *node = nodeSequence[ii];
        int depth = nodeDepth[node - nodes];
        FOR_EACH_EDGES_C(edge, node) {
            if(isLeaf(edge)) {
                leafDepth[edge - leafs] = depth + edge->length();
            }else {
                const Node *child = static_cast<const Node*>(edge);
                nodeDepth[child - nodes] = depth + edge->length();
            }
        }
    }
}
 
void SuffixTree::calcNumDescendantLeafs() {
    assert(!nodeSequence.empty());
    size_t K = addedStrings.size();
    numDescendantLeafs.assign(K, std::vector<Index>(nNodes, 0));
    if(nNodes == 0) return;
 
    for(Index i = 0; i < id3; i ++) {
        const Leaf *leaf = leafSequence[i];
        const Node *parent = leafParent[leaf - leafs];
        Alpha id1 = *(leaf->end - 1);
        ++ numDescendantLeafs[id1][parent - nodes];
    }
    for(Index ii = nNodes - 1; ii > 0; -- ii) {
        const Node *node = nodeSequence[ii];
        const Node *parent = nodeParent[node - nodes];
        for(size_t k = 0; k < K; k ++)
            numDescendantLeafs[k][parent - nodes] += numDescendantLeafs[k][node - nodes];
    }
}
 
void SuffixTree::countCommonSubstrings(Count cnts[]) const {
    assert(!nodeDepth.empty() && !numDescendantLeafs.empty());
    size_t K = addedStrings.size();
    assert(K > 0);
    Index minn = std::numeric_limits<Index>::max();
    for(size_t k = 0; k < K; k ++)
        minn = std::min(minn, (Index)(addedStrings[k].second - addedStrings[k].first));
    for(Index i = 0; i <= minn; i ++)
        cnts[i] = 0;
    

    {   Count cnt = 1;
        for(size_t k = 0; k < K; k ++)
            cnt *= numDescendantLeafs[k][0];
        cnts[0] += cnt;
        if(0 < minn) cnts[1] -= cnt;
    }
    

    for(Index i = 1; i < nNodes; i ++) {
        Index depth = nodeDepth[i], edgeLen = nodes[i].length();
        Index lenLower = depth - (edgeLen - 1), lenUpper = depth;
        Count cnt = 1;
        for(size_t k = 0; k < K; k ++)
            cnt *= numDescendantLeafs[k][i];
        if(cnt == 0) continue;
        assert(lenLower <= minn);
        cnts[lenLower] += cnt;
        if(lenUpper < minn) cnts[lenUpper+1] -= cnt;
    }
    for(Index ix = 0; ix < id3; ix ++) {
        Index i = leafSequence[ix] - leafs;
        Index depth = leafDepth[i], edgeLen = leafs[i].length();
        if(edgeLen == 0) continue;  

        Index lenLower = depth - (edgeLen - 1), lenUpper = depth - 1;
        Alpha id1 = leafs[i].id1();
        Count cnt = 1;
        for(size_t k = 0; k < K; k ++)
            cnt *= k == id1 ? 1 : 0;
        if(cnt == 0) continue;
        assert(lenLower <= minn);
        cnts[lenLower] += cnt;
        if(lenUpper < minn) cnts[lenUpper+1] -= cnt;
    }
    for(Index i = 1; i <= minn; i ++)   

        cnts[i] += cnts[i-1];
}
 
 
}
 
 
int main() {
    using namespace solve;
    typedef SuffixTree::Alpha Alpha;
    int T=1;
    for(int ii = 0; ii < T; ii ++) {
        static char S1[310001], S2[310001], S3[310001];
        scanf("%s", S1);
        scanf("%s", S2);
        scanf("%s", S3);
        int n1 = strlen(S1), n2 = strlen(S2), n3 = strlen(S3);
        SuffixTree st(n1 + n2 + n3+ 3);
        st.addString((Alpha*)S1, (Alpha*)S1 + n1, 0);
        st.addString((Alpha*)S2, (Alpha*)S2 + n2, 1);
        st.addString((Alpha*)S3, (Alpha*)S3 + n3, 2);
        st.inorderTraversal();
        st.calcNodeDepth();
        st.calcNumDescendantLeafs();
        static SuffixTree::Count cnts[310001];
        st.countCommonSubstrings(cnts);
        int minn = std::min(n1, n2);
        minn=std::min(minn, n3);
        int L=minn;
        for(int i = 1; i <= L; i ++) {
            if(i != 1) putchar(' ');
            long long ans = minn < i ? 0 : cnts[i];
            cout<<ans%1000000007LL;
        }
        puts("");
    }
    return 0;
}