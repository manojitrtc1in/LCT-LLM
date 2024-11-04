









 






  







 

 






using namespace std;

const int MaxN = 500005;

template <class T>
class BlockAllocator
{
private:
    static const int BlockL = 10000;

    union TItem
    {
        char rt[sizeof(T)];
        TItem *next;
    };

    TItem *pool, *tail;
    TItem *unused;
public:
    BlockAllocator()
    {
        pool = NULL;
        unused = NULL;
    }

    T *allocate()
    {
        TItem *p;
        if (unused)
        {
            p = unused;
            unused = unused->next;
        }
        else
        {
            if (pool == NULL)
                pool = new TItem[BlockL], tail = pool;
            p = tail++;
            if (tail == pool + BlockL)
                pool = NULL;
        }
        return (T*)p;
    }
    void deallocate(T *pt)
    {
        TItem *p = (TItem*)pt;
        p->next = unused, unused = p;
    }
};

struct edgeWeight;
struct path_message;
struct lcc_circle;
struct lcc_edge;
struct lcc_message;
struct lcc_node;

struct edgeWeight
{
    int wA, wB;

    edgeWeight(){}
    edgeWeight(const int &_wA, const int &_wB)
        : wA(_wA), wB(_wB){}

    friend inline bool operator==(const edgeWeight &lhs, const edgeWeight &rhs)
    {
        return lhs.wA == rhs.wA && lhs.wB == rhs.wB;
    }
    friend inline bool operator!=(const edgeWeight &lhs, const edgeWeight &rhs)
    {
        return lhs.wA != rhs.wA || lhs.wB != rhs.wB;
    }
};

struct path_message
{
    int minLA;
    int minWB;

    path_message(){}
    path_message(const edgeWeight &ew)
        : minLA(ew.wA), minWB(ew.wB){}
    path_message(const int &_minLA, const int &_minWB)
        : minLA(_minLA), minWB(_minWB){}

    void setEmpty()
    {
        minLA = 0;
        minWB = INF;
    }
    void setInvalid()
    {
        minLA = -1;
        minWB = -1;
    }
    bool valid() const
    {
        return minLA != -1;
    }
    void setMultiple()
    {
        minWB = -1;
    }

    friend inline path_message operator+(const path_message &lhs, const path_message &rhs)
    {
        if (lhs.minLA < rhs.minLA)
            return lhs;
        else if (rhs.minLA < lhs.minLA)
            return rhs;
        else
            return path_message(lhs.minLA, -1);
    }
    friend inline path_message operator*(const path_message &lhs, const path_message &rhs)
    {
        return path_message(lhs.minLA + rhs.minLA, min(lhs.minWB, rhs.minWB));
    }
};

struct lcc_circle
{
    lcc_node *pA, *pB;
    lcc_node *pEx;
    lcc_edge *missingE;
    bool equalL;
};
struct lcc_edge
{
    edgeWeight ew;
    lcc_circle *cir;

    inline lcc_circle *getCir()
    {
        return this ? this->cir : NULL;
    }
};
struct lcc_message
{
    path_message pathMsg;
    lcc_edge *firstE, *lastE;
    bool hasCir;
    bool id5;

    void rev()
    {
        swap(firstE, lastE);
    }
    void coverCir(lcc_circle *cir, bool isSingle)
    {
        hasCir = !isSingle && cir != NULL;
        id5 = false;
        if (cir && firstE->getCir() != cir && lastE->getCir() != cir)
        {
            if (cir->equalL)
                id5 = true;
        }
    }
    void addWB(int delta, bool isSingle)
    {
        if (!isSingle)
            pathMsg.minWB += delta;
    }

    friend inline lcc_message operator+(const lcc_message &lhs, const lcc_message &rhs)
    {
        lcc_message res;

        assert(lhs.lastE == rhs.firstE);
        lcc_edge *e = lhs.lastE;

        res.pathMsg = lhs.pathMsg * path_message(e->ew) * rhs.pathMsg;
        res.id5 = lhs.id5 || rhs.id5;
        if (e->cir && lhs.firstE->getCir() != e->cir && rhs.lastE->getCir() != e->cir)
        {
            if (e->cir->equalL)
                res.id5 = true;
        }
        res.firstE = lhs.firstE, res.lastE = rhs.lastE;
        res.hasCir = lhs.hasCir || e->cir || rhs.hasCir;
        return res;
    }
};
struct lcc_node
{
    lcc_node *fa, *lc, *rc;
    lcc_edge *prevE, *nextE;

    lcc_message msg;

    bool hasRev;
    bool id6;
    lcc_circle *coveredCir;
    int id8;

    bool isRoot()
    {
        return !fa || (fa->lc != this && fa->rc != this);
    }

    void rotate()
    {
        lcc_node *x = this, *y = x->fa, *z = y->fa;
        lcc_node *b = x == y->lc ? x->rc : x->lc;
        x->fa = z, y->fa = x;
        if (b)
            b->fa = y;
        if (z)
        {
            if (z->lc == y)
                z->lc = x;
            else if (z->rc == y)
                z->rc = x;
        }
        if (y->lc == x)
            x->rc = y, y->lc = b;
        else
            x->lc = y, y->rc = b;
        y->update();
    }

    void allFaTagDown()
    {
        int anc_n = 0;
        static lcc_node *anc[MaxN];
        anc[anc_n++] = this;
        for (int i = 0; !anc[i]->isRoot(); i++)
            anc[anc_n++] = anc[i]->fa;
        for (int i = anc_n - 1; i >= 0; i--)
            anc[i]->tag_down();
    }
    void splay()
    {
        allFaTagDown();
        while (!this->isRoot())
        {
            if (!fa->isRoot())
            {
                if ((fa->lc == this) == (fa->fa->lc == fa))
                    fa->rotate();
                else
                    this->rotate();
            }
            this->rotate();
        }
        this->update();
    }
    void splay_until(lcc_node *target)
    {
        allFaTagDown();
        while (this->fa != target)
        {
            if (fa->fa != target)
            {
                if ((fa->lc == this) == (fa->fa->lc == fa))
                    fa->rotate();
                else
                    this->rotate();
            }
            this->rotate();
        }
        this->update();
    }

    int getLcTotL()
    {
        if (!prevE)
            return 0;
        int totL = prevE->ew.wA;
        if (lc)
            totL += lc->msg.pathMsg.minLA + msg.firstE->ew.wA;
        return totL;
    }
    int getRcTotL()
    {
        if (!nextE)
            return 0;
        int totL = nextE->ew.wA;
        if (rc)
            totL += rc->msg.pathMsg.minLA + msg.lastE->ew.wA;
        return totL;
    }

    void access()
    {
        for (lcc_node *p = this, *q = NULL; p; q = p, p = p->fa)
        {
            p->splay();
            if (p->prevE && p->prevE->cir)
            {
                bool isTogether = false;

                lcc_circle *cir = p->prevE->cir;
                if (cir->pEx && !cir->pEx->isRoot())
                    cir->pEx = p;

                cir->pB->splay(), cir->pA->splay();
                if (cir->pB->isRoot())
                {
                    if (cir->pB->fa != cir->pA)
                    {
                        swap(cir->pA, cir->pB);
                        if (cir->pEx)
                            cir->pEx->tag_rev();
                    }
                }
                else
                {
                    isTogether = true;
                    cir->pB->splay_until(cir->pA);
                    if (cir->pA->lc == cir->pB)
                    {
                        cir->pB->rotate();
                        swap(cir->pA, cir->pB);
                        if (cir->pEx)
                            cir->pEx->tag_rev();
                    }
                    cir->pA->rc = NULL, cir->pA->nextE = NULL;
                }
                cir->pB->rc = cir->pEx, cir->pB->nextE = cir->pEx ? cir->pEx->msg.firstE : cir->missingE;
                if (cir->pEx)
                    cir->pEx->fa = cir->pB;

                p->splay();

                if (p->getLcTotL() > p->getRcTotL())
                    p->tag_rev(), p->tag_down();
                cir->pB = p;
                cir->pEx = p->rc, cir->missingE = p->rc ? NULL : p->nextE;
                cir->equalL = p->getLcTotL() == p->getRcTotL();
                if (cir->pEx)
                    cir->pEx->fa = NULL;

                p->rc = q, p->nextE = q ? q->msg.firstE : NULL;
                p->update();

                if (isTogether)
                {
                    cir->pA->rc = p, cir->pA->nextE = p->msg.firstE;
                    p->splay();
                }
            }
            else
            {
                p->rc = q, p->nextE = q ? q->msg.firstE : NULL;
                p->update();
            }
        }

        this->splay();
    }

    void makeRoot()
    {
        this->access();
        this->tag_rev(), this->tag_down();
    }
    lcc_node *findRoot()
    {
        lcc_node *p = this;
        p->access();
        while (p->tag_down(), p->lc)
            p = p->lc;
        p->splay();
        return p;
    }

    void tag_rev()
    {
        hasRev = !hasRev;
        msg.rev();
    }
    void tag_coverCir(lcc_circle *cir)
    {
        id6 = true;
        coveredCir = cir;
        msg.coverCir(cir, !lc && !rc);
    }
    void tag_addWB(int delta)
    {
        id8 += delta;
        msg.addWB(delta, !lc && !rc);
    }
    void tag_down()
    {
        if (hasRev)
        {
            swap(lc, rc);
            swap(prevE, nextE);

            if (lc)
                lc->tag_rev();
            if (rc)
                rc->tag_rev();

            hasRev = false;
        }
        if (id6)
        {
            if (lc)
            {
                prevE->cir = coveredCir;
                lc->tag_coverCir(coveredCir);
            }
            if (rc)
            {
                nextE->cir = coveredCir;
                rc->tag_coverCir(coveredCir);
            }

            id6 = false;
        }
        if (id8 != 0)
        {
            if (lc)
            {
                prevE->ew.wB += id8;
                lc->tag_addWB(id8);
            }
            if (rc)
            {
                nextE->ew.wB += id8;
                rc->tag_addWB(id8);
            }

            id8 = 0;
        }
    }
    void update()
    {
        msg.pathMsg.setEmpty();
        msg.firstE = prevE, msg.lastE = nextE;
        msg.hasCir = false;
        msg.id5 = false;

        if (lc)
            msg = lc->msg + msg;
        if (rc)
            msg = msg + rc->msg;
    }
};

int n;
lcc_node lccVer[MaxN + 1];
BlockAllocator<lcc_edge> id7;
BlockAllocator<lcc_circle> id0;

void id4()
{
    for (int v = 1; v <= 250000; v++)
    {
        lcc_node *x = lccVer + v;
        x->fa = x->lc = x->rc = NULL;
        x->prevE = x->nextE = NULL;
        x->hasRev = false;
        x->id6 = false;
        x->id8 = 0;
        x->update();
    }
}

bool id3(int v, int u, int wA, int wB)
{
    if (v == u)
        return false;

    edgeWeight ew(wA, wB);

    lcc_node *x = lccVer + v, *y = lccVer + u;
    x->makeRoot(), y->makeRoot();

    if (x->fa)
    {
        x->access();
        if (x->msg.hasCir)
            return false;

        lcc_circle *cir = id0.allocate();
        lcc_edge *e = id7.allocate();
        e->ew = ew, e->cir = cir;
        cir->pA = y, cir->pB = x, cir->pEx = NULL;
        cir->missingE = e;
        x->tag_coverCir(cir);

        x->access();
    }
    else
    {
        lcc_edge *e = id7.allocate();
        e->ew = ew, e->cir = NULL;
        x->fa = y, x->prevE = e, x->update();
    }
    return true;
}
bool id9(int v, int u, int wA, int wB)
{
    if (v == u)
        return false;

    edgeWeight ew(wA, wB);

    lcc_node *x = lccVer + v, *y = lccVer + u;
    if (x->findRoot() != y->findRoot())
        return false;

    y->makeRoot(), x->access();
    y->splay_until(x);

    lcc_circle *cir = x->prevE->cir;
    if (cir && cir->pA == y && !cir->pEx && cir->missingE->ew == ew)
    {
        lcc_edge *e = cir->missingE;
        x->tag_coverCir(NULL);
        id0.deallocate(cir);
        id7.deallocate(e);
        return true;
    }
    if (!y->rc && x->prevE->ew == ew)
    {
        lcc_edge *e = x->prevE;
        id7.deallocate(e);

        if (cir)
        {
            if (cir->pEx)
            {
                cir->pEx->tag_rev();

                cir->pEx->fa = y, y->rc = cir->pEx;
                y->nextE = cir->pEx->msg.firstE;
                x->prevE = cir->pEx->msg.lastE;
            }
            else
                y->nextE = x->prevE = cir->missingE;

            y->update(), x->update();
            x->tag_coverCir(NULL);

            id0.deallocate(cir);
        }
        else
        {
            y->fa = NULL, y->nextE = NULL, y->update();
            x->lc = NULL, x->prevE = NULL, x->update();
        }

        return true;
    }
    return false;
}
bool id2(int qv, int qu, int delta)
{
    lcc_node *x = lccVer + qv, *y = lccVer + qu;
    if (x->findRoot() != y->findRoot())
        return false;

    x->makeRoot(), y->access();
    if (y->msg.id5)
        return false;
    y->tag_addWB(delta);
    return true;
}
path_message id1(int qv, int qu)
{
    path_message res;
    lcc_node *x = lccVer + qv, *y = lccVer + qu;
    if (x->findRoot() != y->findRoot())
    {
        res.setInvalid();
        return res;
    }

    x->makeRoot(), y->access();
    res = y->msg.pathMsg;
    if (y->msg.id5)
        res.setMultiple();
    return res;
}

int m, res;
int a[500005], b[500005];

signed main() {
    
    


    

    


    scanf("%lld %lld", &n, &m);
    for1(i,1,m) scanf("%lld %lld", &a[i], &b[i]);

    id4();
    int j = 1;
    for1(i,1,m) {
        while (j <= m && id3(a[j], b[j], 0, 0)) j++;
        res += j - i;
        id9(a[i], b[i], 0, 0);
    }

    printf("%lld", res);
    
}