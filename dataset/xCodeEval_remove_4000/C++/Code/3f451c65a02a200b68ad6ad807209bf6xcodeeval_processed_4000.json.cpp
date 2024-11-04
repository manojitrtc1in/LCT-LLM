













using namespace std;

 


const int maxn = 111111;
 
int treeSize[maxn];     

int IDSection[maxn];    

int IDKey[maxn];        

int root[maxn];         

int goodCastle[maxn];   

int goodPath[maxn];     

vector <int> evilCastle[maxn];  

int n , m;
 
 
struct SubSegTree {
    int sz;
    int lch[maxn<<2];
    int rch[maxn<<2];
    int evilPath[maxn<<2];
    bool clear[maxn<<2];
 
    void build(int l,int r,int &rt) {
        rt = sz ++;
        evilPath[rt] = 0;
        if (l == r) {
            return ;
        }
        int mid = (l + r) >> 1;
        build(l , mid , lch[rt]);
        build(mid + 1 , r , rch[rt]);
    }
    void PushDown(int rt) {
        if (clear[rt]) {
            clear[ lch[rt] ] = true;
            clear[ rch[rt] ] = true;
            evilPath[ lch[rt] ] = 0;
            evilPath[ rch[rt] ] = 0;
            clear[rt] = false;
        }
    }
    void PushUp(int rt) {
        evilPath[rt] = evilPath[ lch[rt] ] + evilPath[ rch[rt] ];
    }
    void add(int pos,int l,int r,int rt) {
        if (l == r) {
            evilPath[rt] ++;
            return ;
        }
        PushDown(rt);
        int mid = (l + r) >> 1;
        if (pos <= mid) add(pos , l , mid , lch[rt]);
        else add(pos , mid + 1 , r , rch[rt]);
        PushUp(rt);
    }
    void death(int L,int R,int l,int r,int rt) {
        if (L <= l && r <= R) {
            clear[rt] = true;
            evilPath[rt] = 0;
            return ;
        }
        PushDown(rt);
        int mid = (l + r) >> 1;
        if (L <= mid) death(L , R , l , mid , lch[rt]);
        if (mid < R) death(L , R , mid + 1 , r , rch[rt]);
        PushUp(rt);
    }
    int query(int L,int R,int l,int r,int rt) {
        if (L <= l && r <= R) {
            return evilPath[rt];
        }
        PushDown(rt);
        int mid = (l + r) >> 1;
        int ret = 0;
        if (L <= mid) ret += query(L , R , l , mid , lch[rt]);
        if (mid < R) ret += query(L , R , mid + 1 , r , rch[rt]);
        return ret;
    }
}subTree;
 
struct Node {
    int sum , num , leftID , rightID;
    void reset(int a = 0, int b = 0,int c = 0, int d = 0) {
        sum = a;
        num = b;
        leftID = c;
        rightID = d;
    }
    bool operator < (const Node &cmp) {
        if (sum == cmp.sum) {
            return num < cmp.num;
        }
        return sum < cmp.sum;
    }
    void operator += (const Node &add) {
        this->sum += add.sum;
        this->num += add.num;
    }
};
struct SegTree {
    Node road[maxn<<2];
    bool clear[maxn<<2];
    int isLeaf[maxn<<2];
    void kill(int rt) {
        road[rt].sum = 0;
        if (isLeaf[rt] != -1) {
            int l = isLeaf[rt];
            if (road[rt].num == 1) {
                goodPath[l] = 0;
            } else {
                subTree.death(1 , treeSize[l] , 1 , treeSize[l] , root[l]);
            }
        }
    }
    void PushDown(int rt) {
        if (clear[rt]) {
            clear[rt<<1] = true;
            clear[rt<<1|1] = true;
            kill(rt << 1);
            kill(rt << 1 | 1);
            clear[rt] = 0;
        }
    }
    void PushUp(int rt) {
        road[rt].reset();
        road[rt] += road[rt<<1];
        road[rt] += road[rt<<1|1];
        road[rt].leftID = road[rt<<1].leftID;
        road[rt].rightID = road[rt<<1|1].rightID;
    }
    void build(int l,int r,int rt) {
        road[rt].reset(0 , r - l + 1 , goodCastle[l%m +1] , goodCastle[r]);
        clear[rt] = false;
        isLeaf[rt] = -1;
        if (l == r) {
            isLeaf[rt] = l;
            subTree.build(1 , treeSize[l] , root[l]);
            return ;
        }
        int mid = (l + r) >> 1;
        build(l , mid , rt << 1);
        build(mid+1 , r , rt << 1 | 1);
        PushUp(rt);
    }
 
    void updateLeaf(int rt,int l) {
        int a = goodPath[l];
        int b = subTree.query(1 , treeSize[l] , 1 , treeSize[l] , root[l]);
        if (a <= b) {
            road[rt].reset(a , 1 , goodCastle[l % m + 1], goodCastle[l]);
        } else {
            road[rt].reset(b , treeSize[l] , evilCastle[l][2] , evilCastle[l][ treeSize[l] ]);
        }
    }
    void add(int pos,int pos2,int l,int r,int rt) {
        if (l == r) {
            if (pos2 == -1) {
                goodPath[l] ++;
            } else {
                subTree.add(pos2 , 1 , treeSize[l] , root[l]);
            }
            updateLeaf(rt , l);
            return ;
        }
        PushDown(rt);
        int mid = (l + r) >> 1;
        if (pos <= mid) add(pos , pos2 , lson);
        else add(pos , pos2 , rson);
        PushUp(rt);
    }
    void death(int L,int R,int l,int r,int rt,int LL = -1,int RR = -1) {
        if (L <= l && r <= R) {
            if (LL == -1) {
                clear[rt] = true;
                kill(rt);
            } else {
                subTree.death(LL , RR , 1 , treeSize[l] , root[l]);
                updateLeaf(rt , l);
            }
            return ;
        }
        PushDown(rt);
        int mid = (l + r) >> 1;
        if (L <= mid) death(L , R , lson , LL , RR);
        if (mid < R) death(L , R , rson , LL , RR);
        PushUp(rt);
    }
    Node query(int L,int R,int l,int r,int rt) {
        if (L <= l && r <= R) {
            return road[rt];
        }
        PushDown(rt);
        int mid = (l + r) >> 1;
        if (R <= mid) return query(L , R , lson);
        else if (mid < L) return query(L , R , rson);
        else {
            Node ll = query(L , R , lson);
            Node rr = query(L , R , rson);
            Node ret;
            ret.reset(ll.sum + rr.sum , ll.num + rr.num , ll.leftID , rr.rightID);
            return ret;
        }
    }
}tree;
 
struct ShortPath{
    struct EdgeNode {
        int dis , v , next , num;
    };
    vector <EdgeNode> edge[9];
    int bestSum , bestNum;
    int bestPath[9];
    int bestNode[9];
    int bestDeep;
 
    int path[9];
    int node[9];
    int s , t;
    bool vis[9];
 
    void calcPos(int S,int &SectionS , int &KeyS) {
        if (S == 0) {
            SectionS = IDSection[s];
            KeyS = IDKey[s];
        } else if (S == 1) {
            SectionS = IDSection[s];
            KeyS = 1;
        } else if (S == 2) {
            SectionS = IDSection[s] % m + 1;
            KeyS = 1;
        } else if (S == 3) {
            SectionS = IDSection[t];
            KeyS = 1;
        } else if (S == 4) {
            SectionS = IDSection[t] % m + 1;
            KeyS = 1;
        } else {
            SectionS = IDSection[t];
            KeyS = IDKey[t];
        }
    }
 
    int chooseNext(int s,int dir) {
        if (dir == -1) s -= 1;
        if (s == 0) s = m;
 
        int good = goodPath[s];
        int evil = subTree.query(1 , treeSize[s] , 1 , treeSize[s] , root[s]);
 
        if (dir == -1) {
            if (evil < good || (evil == good && evilCastle[s][ treeSize[s] ]< goodCastle[s])) {
                return evilCastle[s][ treeSize[s] ];
            } else {
                return goodCastle[s];
            }
        } else {
            if (evil < good || (evil == good && evilCastle[s][1] < goodCastle[s % m + 1])) {
                return evilCastle[s][1];
            } else {
                return goodCastle[s % m + 1];
            }
        }
    }
 
    void makeEdge(int S,int T) {
        EdgeNode e;
        e.v = T;
        int SectionS , SectionT , KeyS , KeyT;
        calcPos(S , SectionS , KeyS);
        calcPos(T , SectionT , KeyT);
        if (SectionS == SectionT && KeyS == KeyT) {
            e.next = -1;
            e.num = 0;
            e.dis = 0;
        } else if (S == 0 || T == 5) { 

            if (SectionS == SectionT) {
                if (KeyS > KeyT) {
                    e.dis = subTree.query(KeyT , KeyS - 1 , 1 , treeSize[SectionT] , root[SectionT]);
                    e.num = KeyS - KeyT;
                    e.next = evilCastle[SectionS][KeyS - 1];
                } else {
                    e.dis = subTree.query(KeyS , KeyT - 1 , 1 , treeSize[SectionS] , root[SectionS]);
                    e.num = KeyT - KeyS;
                    e.next = evilCastle[SectionS][KeyS + 1];
                }
            } else {
                if (SectionS % m + 1 == SectionT) {
                    e.dis = subTree.query(KeyS , treeSize[SectionS] , 1 , treeSize[SectionS] , root[SectionS]);
                    e.num = treeSize[SectionS] - KeyS + 1;
                    e.next = evilCastle[SectionS][KeyS + 1];
                } else {
                    e.dis = subTree.query(KeyT , treeSize[SectionT] , 1 , treeSize[SectionT] , root[SectionT]);
                    e.num = treeSize[SectionT] - KeyT + 1;
                    e.next = evilCastle[SectionT][ treeSize[SectionT] ];
                }
            }
        } else {
            if (S + T == 3 || S + T == 7) {

                if (SectionS % m + 1 ==  SectionT) {
                    Node a = tree.query(SectionS , SectionS , 1 , m , 1);
                    e.dis = a.sum;
                    e.num = a.num;
                    e.next = a.leftID;
                } else {
                    Node a = tree.query(SectionT , SectionT , 1 , m , 1);
                    e.dis = a.sum;
                    e.num = a.num;
                    e.next = a.rightID;
                }
            } else if (S == 2) {

                if (SectionS < SectionT) {
                    Node a = tree.query(SectionS , SectionT - 1 , 1 , m , 1);
                    e.dis = a.sum;
                    e.num = a.num;
                    e.next = a.leftID;
                } else {
                    Node b = tree.query(SectionS , m , 1 , m , 1);
                    if (SectionT != 1) {
                        Node c = tree.query(1 , SectionT - 1 , 1 , m , 1);
                        b += c;
                        b.rightID = c.rightID;
                    }
                    e.dis = b.sum;
                    e.num = b.num;
                    e.next = b.leftID;
                }
            } else {

                if (SectionS > SectionT) {
                    Node a = tree.query(SectionT , SectionS - 1 , 1 , m , 1);
                    e.dis = a.sum;
                    e.num = a.num;
                    e.next = a.rightID;
                } else {
                    Node b = tree.query(SectionT , m , 1 , m , 1);
                    if (SectionS != 1) {
                        Node c = tree.query(1 , SectionS - 1 , 1 , m , 1);
                        b += c;
                        b.rightID = c.rightID;
                    }
                    e.dis = b.sum;
                    e.num = b.num;
                    e.next = b.rightID;
                }
            }
        }
        edge[S].push_back(e);
    }
 
 
    void copy(int sum,int num,int deep) {
        bestSum = sum;
        bestNum = num;
        bestDeep = deep;
        for (int i = 0 ; i < deep ; i ++) {
            bestNode[i] = node[i];
            bestPath[i] = path[i];
        }
    }
    void dfs(int deep,int u,int sum,int num) {
        if (u == 5) {
            if (sum < bestSum || bestSum == -1) {
                copy(sum , num , deep);
            } else if (sum == bestSum && num < bestNum) {
                copy(sum , num , deep);
            } else if (sum == bestSum && num == bestNum) {
                bool cp = true;
                int i = 0 , j = 0;
                while (i < deep && j < bestDeep) {
                    while (node[i] == -1) i ++;
                    while (bestNode[j] == -1) j ++;
                    if (node[i] != bestNode[j]) {
                        cp = node[i] < bestNode[j];
                        break;
                    }
                    i ++ , j ++;
                }
                if (cp) copy(sum , num , deep);
            }
            return ;
        }
        for (int i = 0 ; i < edge[u].size() ; i ++) {
            int v = edge[u][i].v;
            if (vis[v]) continue;
            vis[v] = true;
            path[deep] = u;
            node[deep] = edge[u][i].next;
            dfs(deep + 1 , v , sum + edge[u][i].dis , num + edge[u][i].num);
            vis[v] = false;
        }
    }
 
    void missionOfDeath(int S,int T) {
        int SectionS , SectionT , KeyS , KeyT;
        calcPos(S , SectionS , KeyS);
        calcPos(T , SectionT , KeyT);
        if (SectionS == SectionT && KeyS == KeyT) {
            return ;
        } else if (S == 0 || T == 5) {
            if (SectionS == SectionT) {
                if (KeyS > KeyT) {
                    tree.death(SectionT , SectionT , 1 , m , 1 , KeyT , KeyS - 1);
                } else {
                    tree.death(SectionS , SectionS , 1 , m , 1 , KeyS , KeyT - 1);
                }
            } else {
                if (SectionS % m + 1 == SectionT) {
                    tree.death(SectionS , SectionS , 1 , m , 1 , KeyS , treeSize[SectionS]);
                } else {
                    tree.death(SectionT , SectionT , 1 , m , 1 , KeyT , treeSize[SectionT]);
                }
            }
        } else {
            if (S + T == 3 || S + T == 7) {

                if (SectionS % m + 1 ==  SectionT) {
                    tree.death(SectionS , SectionS , 1 , m , 1);
                } else {
                    tree.death(SectionT , SectionT , 1 , m , 1);
                }
            } else if (S == 2) {

                if (SectionS < SectionT) {
                    tree.death(SectionS , SectionT - 1 , 1 , m , 1);
                } else {
                    tree.death(SectionS , m , 1 , m , 1);
                    if (SectionT != 1) tree.death(1 , SectionT - 1 , 1 , m , 1);
                }
            } else {

                if (SectionS > SectionT) {
                    tree.death(SectionT , SectionS - 1 , 1 , m , 1);
                } else {
                    tree.death(SectionT , m , 1 , m , 1);
                    if (SectionS != 1) tree.death(1 , SectionS - 1 , 1 , m , 1);
                }
            }
        }
    }
 
 
    void debugEdge() {
        for (int i = 0 ; i < 6 ; i ++) {
            printf("%d:" , i);
            for (int j = 0 ; j < edge[i].size() ; j ++) {
                printf("{%d %d %d %d}",edge[i][j].v , edge[i][j].next , edge[i][j].dis , edge[i][j].num);
            }
            puts("");
        }
    }
 
    void calcShortPath(int _s,int _t) {
        s = _s , t = _t;
        if (s == t) {
            puts("0");
        } else {
            

            for (int i = 0 ; i < 6 ; i ++) {
                edge[i].clear();
            }
            

            makeEdge(0 , 1);
            makeEdge(0 , 2);
            makeEdge(1 , 2);
            makeEdge(1 , 4);
            makeEdge(2 , 1);
            makeEdge(2 , 3);
            makeEdge(3 , 4);
            makeEdge(4 , 3);
            makeEdge(3 , 5);
            makeEdge(4 , 5);
            if (IDSection[s] == IDSection[t]) {
                makeEdge(0 , 5);
                EdgeNode e;
                e.dis = e.num = 0;
                e.next = -1;
                e.v = 3;
                edge[1].push_back(e);
                e.v = 4;
                edge[2].push_back(e);
            }
 

            printf("? %d %d\n",s,t);
            debugEdge();

 
            bestSum = -1;
            memset(vis , false , sizeof(vis));
            dfs(0 , 0 , 0 , 0);
            printf("%d\n",bestSum);
 
            bestPath[bestDeep] = 5;
            for (int i = 0 ; i < bestDeep ; i ++) {
                missionOfDeath(bestPath[i] , bestPath[i+1]);
            }
 

            puts("bestPath:");
            for (int i = 0 ; i < bestDeep ; i ++) {
                printf("%d " , bestPath[i]);
            }
            puts("\n");

        }
    }
}G;
 
 
void debug() {
    puts("goodCastle:");
    for (int i = 1 ; i <= m ; i ++) {
        printf("%d%c",goodCastle[i] , i == m ? '\n' : ' ');
    }
    puts("evilPath:");
    for (int i = 1 ; i <= m ; i ++) {
        for (int j = 1 ; j < evilCastle[i].size() ; j ++) {
            printf("%d%c",evilCastle[i][j] , j + 1 == evilCastle[i].size() ? '\n' : ' ');
        }
    }
    puts("Section & Key:");
    for (int i = 1 ; i <= n ; i ++) {
        printf("%d %d\n",IDSection[i] , IDKey[i]);
    }
    puts("root & treeSize:");
    for (int i = 1 ; i <= m ; i ++) {
        printf("%d %d\n",root[i] , treeSize[i]);
    }
}
 
void Initialize() {
    scanf("%d%d",&n,&m);
    for (int i = 1 ; i <= m ; i ++) {
        scanf("%d",&goodCastle[i]);
    }
    for (int i = 1 ; i <= m ; i ++) {
        scanf("%d",&treeSize[i]);
        evilCastle[i].push_back(-1);
        for (int j = 1 ; j <= treeSize[i] ; j ++) {
            int node;
            scanf("%d",&node);
            evilCastle[i].push_back(node);
            if (j == treeSize[i]) continue;
            IDSection[node] = i;
            IDKey[node] = j;
        }
        treeSize[i] --;
    }
 
    tree.build(1 , m , 1);
 
 

    debug();

 
}
 
void id0(int s,int t) {
    if (IDKey[s] == 1 && IDKey[t] == 1) {
        int pos;
        if (IDSection[s] % m + 1 == IDSection[t]) {
            pos = IDSection[s];
        } else {
            pos = IDSection[t];
        }
        tree.add(pos , -1 , 1 , m , 1);
    } else {
        int pos , pos2;
        if (IDSection[s] == IDSection[t]) {
            pos = IDSection[s];
            pos2 = min(IDKey[s] , IDKey[t]);
        } else {
            if (IDKey[t] == 1) {
                pos = IDSection[s];
                pos2 = IDKey[s];
            } else {
                pos = IDSection[t];
                pos2 = IDKey[t];
            }
        }
        tree.add(pos , pos2 , 1 , m , 1);
    }
}
 
 
void Query() {
    int Q;
    scanf("%d",&Q);
    while (Q --) {
        char op;
        int s , t;
        scanf("%*c%c %d %d",&op,&s,&t);
 
        if (op == '+') id0(s , t);
        else G.calcShortPath(s , t);
    }
}
int main() {


    Initialize();
    Query();
    return 0;
}