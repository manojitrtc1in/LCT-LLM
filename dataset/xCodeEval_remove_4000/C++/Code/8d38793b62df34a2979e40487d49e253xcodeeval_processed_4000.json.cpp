








using namespace std;

const long double EPS = 1e-9;
const long double PI = 3.141592653589793238462643383279502884197;
const int MOD = 666013;
const int NMax = 350000;
int N, C, D;
int id12;
long long ans = 0LL;
struct Punct;
long long diferente[NMax], diferentePartiale[NMax];
long long sqr(const long long &x);
long long id16(const Punct &A, const Punct &B, const Punct &C);
long long Dist2(const Punct &A, const Punct &B);
long double GetAngle(const Punct &A);
int id9(const Punct &A);
long long id6(const Punct &A, const Punct &B);

struct Punct
{
    int x, y;
    Punct()
    {
        this->x = 0;
        this->y = 0;
    }
    Punct (const int x, const int y)
    {
        this->x = x;
        this->y = y;
    }

    inline bool operator<(const Punct &other) const
    {













        long long s = id6(*this, other);
        if (s == 0)
            return Dist2(Punct(0, 0), *this) < Dist2(Punct(0, 0), other);
        return s == -1;
    }
};
Punct a[NMax];
enum InsertType
{
    InsertCoord, InsertCntStrict, InsertCntNestrict, InsertIndexNestrict
};
enum QueryType
{
    QueryCoord, QueryCntStrict, QueryCntNestrict, QueryIndexNestrict
};
struct HashNode
{
    int x, y, id8;
    long long cntStrict, id3;
    HashNode()
    {
        x = y = id8 = 0;
        cntStrict = id3 = 0LL;
    }
    HashNode(const int &x, const int &y, const int &id8, const long long &cntStrict, const long long &id3)
    {
        this->x = x;
        this->y = y;
        this->id8 = id8;
        this->cntStrict = cntStrict;
        this->id3 = id3;
    }
};
vector <HashNode> H[MOD];

struct CntEvidence
{
    int x, y;
    long long cnt;
    CntEvidence()
    {
        x = y = 0;
        cnt = 0LL;
    }
    CntEvidence(const int &x, const int &y, const long long &cnt)
    {
        this->x = x;
        this->y = y;
        this->cnt = cnt;
    }
    inline bool operator<(const CntEvidence &other) const
    {













        long long s = id6(Punct(this->x, this->y), Punct(other.x, other.y));
        if (s == 0)
            return Dist2(Punct(0, 0), Punct(this->x, this->y)) < Dist2(Punct(0, 0), Punct(other.x, other.y));
        return s == -1;
    }
};
CntEvidence maiMiciStrictVector[NMax];
CntEvidence maiMiciStrictVectorSumePartiale[NMax];
CntEvidence maiMiciSauEgaleVector[NMax];
CntEvidence maiMiciSauEgaleVectorSumePartiale[NMax];
int id15;
int id10;


int gcd(int x, int y)
{
    int r;
    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void Insert(const int &x, const int &y, InsertType type, long long param = 0)
{
    int codh = (abs(x) + abs(y)) % MOD;

    if (type == InsertCoord)
    {
        for (vector <HashNode> :: iterator it = H[codh].begin(); it != H[codh].end(); ++ it)
        {
            if (it->x == x && it->y == y)
                return ;
        }
        H[codh].push_back(HashNode(x, y, 0, 0, 0));
        return ;
    }
    else if (type == InsertCntStrict)
    {
        for (vector <HashNode> :: iterator it = H[codh].begin(); it != H[codh].end(); ++ it)
        {
            if (it->x == x && it->y == y)
            {
                it->cntStrict = param;
                return ;
            }
        }
        H[codh].push_back(HashNode(x, y, 0, param, 0));
        return ;
    }
    else if (type == InsertCntNestrict)
    {
        for (vector <HashNode> :: iterator it = H[codh].begin(); it != H[codh].end(); ++ it)
        {
            if (it->x == x && it->y == y)
            {
                it->id3 = param;
                return ;
            }
        }
        H[codh].push_back(HashNode(x, y, 0, 0, param));
        return ;
    }
    else if (type == InsertIndexNestrict)
    {
        for (vector <HashNode> :: iterator it = H[codh].begin(); it != H[codh].end(); ++ it)
        {
            if (it->x == x && it->y == y)
            {
                it->id8 = param;
                return ;
            }
        }
        H[codh].push_back(HashNode(x, y, param, 0, 0));
        return ;
    }
}

void id14(int x, int y)
{
    int st = 1, dr = id12;
    int ret = 0;
    while (st <= dr)
    {
        int mij = (st+dr) / 2;
        

        

        if (id6(a[mij], Punct(x, y)) < 0)
        {
            ret = mij;
            st = mij + 1;
        }
        else
            dr = mij - 1;
    }
    Insert(x, y, InsertCntStrict, ret);
    maiMiciStrictVector[++id15] = CntEvidence(x, y, ret);
}

void id18(int x, int y)
{
    int st = 1, dr = id12;
    int ret = 0;
    while (st <= dr)
    {
        int mij = (st+dr) / 2;
        

        

        if (id6(a[mij], Punct(x, y)) <= 0)
        {
            ret = mij;
            st = mij + 1;
        }
        else
            dr = mij - 1;
    }
    Insert(x, y, InsertCntNestrict, ret);
    maiMiciSauEgaleVector[++id10] = CntEvidence(x, y, ret);
}

long long QueryHash(int x, int y, QueryType type)
{
    x = -x;
    y = -y;
    if (y == 0)
    {
        if (x < 0)
            x = -1;
        else if (x > 0)
            x = 1;
    }
    else if (x == 0)
    {
        if (y < 0)
            y = -1;
        else if (y > 0)
            y = 1;
    }
    else
    {
        int semnx = 1;
        int semny = 1;
        if (x < 0)
        {
            x = -x;
            semnx = -1;
        }
        if (y < 0)
        {
            y = -y;
            semny = -1;
        }
        int id2 = gcd(x, y);
        x = x / id2;
        y = y / id2;
        x = x * semnx;
        y = y * semny;
    }
    int codh = (abs(x) + abs(y)) % MOD;
    for (vector <HashNode> :: iterator it = H[codh].begin(); it != H[codh].end(); ++ it)
    {
        if (it -> x == x && it -> y == y)
        {
            if (type == QueryCntStrict)
                return it->cntStrict;
            if (type == QueryCntNestrict)
                return it->id3;
            if (type == QueryIndexNestrict)
                return it->id8;
        }
    }
    return -1;

}

void Solve()
{
    int loc;

    loc = 0;
    for (int i = 1; i <= N; ++ i)
    {
        if (a[i].y > 0 || (a[i].y == 0 && a[i].x > 0))
        {
            ++loc;
            swap(a[i], a[loc]);
        }
    }
    sort(a+1, a+loc+1);
    sort(a+loc+1, a+N+1);

    id12 = -1;
    id15 = 0;
    id10 = 0;
    int specialIndex = -1;
    for (int i = 1; i <= N; ++ i)
    {
        if (GetAngle(a[i]) >= PI)
        {
            if (a[i].y == 0)
            {
                Insert(1, 0, InsertCoord);
                id14(1, 0);
                id18(1, 0);
                continue;
            }
            if (a[i].x == 0)
            {
                Insert(0, 1, InsertCoord);
                id14(0, 1);
                id18(0, 1);
                continue;
            }
            int x, y;
            x = -a[i].x;
            y = -a[i].y;
            int semnx = 1, semny = 1;
            if (x < 0)
            {
                x = -x;
                semnx = -1;
            }
            if (y < 0)
            {
                y = -y;
                semny = -1;
            }
            int id2 = gcd(x, y);
            x = x / id2;
            y = y / id2;
            x = x * semnx;
            y = y * semny;
            Insert(x, y, InsertCoord);
            id14(x, y);
            id18(x, y);
        }
        else
        {
            id12 = i;
        }
    }

    bool id1 = false;
    specialIndex = id10;

    for (int i = 1; i <= N; ++ i)
    {
        if (a[i].y == 0 && a[i].x > 0)
        {
            id1 = true;
            Insert(-1, 0, InsertCoord);
            id14(-1, 0);
            id18(-1, 0);
        }
    }

    loc = 0;
    for (int i = 1; i <= id15; ++ i)
    {
        if (maiMiciStrictVector[i].y > 0 || (maiMiciStrictVector[i].y == 0 && maiMiciStrictVector[i].x > 0))
        {
            ++loc;
            swap(maiMiciStrictVector[i], maiMiciStrictVector[loc]);
        }
    }
    sort(maiMiciStrictVector+1, maiMiciStrictVector+loc+1);
    sort(maiMiciStrictVector+loc+1, maiMiciStrictVector+id15+1);

    

    for (int i = 1; i <= id15; ++ i)
    {
        maiMiciStrictVectorSumePartiale[i].x = maiMiciStrictVector[i].x;
        maiMiciStrictVectorSumePartiale[i].y = maiMiciStrictVector[i].y;
        maiMiciStrictVectorSumePartiale[i].cnt = ( (i > 1) ? (maiMiciStrictVectorSumePartiale[i-1].cnt) : (0)) + maiMiciStrictVector[i].cnt;
    }

    loc = 0;
    for (int i = 1; i <= id10; ++ i)
    {
        if (maiMiciSauEgaleVector[i].y > 0 || (maiMiciSauEgaleVector[i].y == 0 && maiMiciSauEgaleVector[i].x > 0))
        {
            ++loc;
            swap(maiMiciSauEgaleVector[i], maiMiciSauEgaleVector[loc]);
        }
    }
    sort(maiMiciSauEgaleVector+1, maiMiciSauEgaleVector+loc+1);
    sort(maiMiciSauEgaleVector+loc+1, maiMiciSauEgaleVector+id10+1);

    

    for (int i = 1; i <= id10; ++ i)
    {
        maiMiciSauEgaleVectorSumePartiale[i].x = maiMiciSauEgaleVector[i].x;
        maiMiciSauEgaleVectorSumePartiale[i].y = maiMiciSauEgaleVector[i].y;
        maiMiciSauEgaleVectorSumePartiale[i].cnt = ( (i > 1) ? (maiMiciSauEgaleVectorSumePartiale[i-1].cnt) : (0)) + maiMiciSauEgaleVector[i].cnt;
    }

    for (int i = 1; i <= id10; ++ i)
    {
        int index = i;
        int x = maiMiciSauEgaleVectorSumePartiale[i].x;
        int y = maiMiciSauEgaleVectorSumePartiale[i].y;
        Insert(x, y, InsertIndexNestrict, index);
    }

    for (int i = 1; i <= id10; ++ i)
        diferente[i] = max(0LL, maiMiciSauEgaleVector[i].cnt - maiMiciStrictVector[i].cnt);
    for (int i = 1; i <= id10; ++ i)
        diferentePartiale[i] = diferentePartiale[i-1] + diferente[i];

    if (id12 != -1 && id10 != 0 && id15 != 0)
    {
        for (int i = id12 + 1; i <= N; ++ i)
        {
            if (a[i].y == 0 && a[i].x < 0)
            {
                int index;
                if (id1)
                {
                    index = specialIndex;
                }
                else
                    index = id10;
                if (index <= 0)
                    continue;

                long long total = maiMiciSauEgaleVectorSumePartiale[index].cnt;

                long long total2;

                int id17 = QueryHash(a[i].x, a[i].y, QueryIndexNestrict);
                if (id17 == -1)
                    continue;

                total2 = maiMiciSauEgaleVectorSumePartiale[id17].cnt + 1LL * (index - id17) * maiMiciSauEgaleVector[id17].cnt;
                

                long long inPlus = diferentePartiale[index];
                if (id1)
                    inPlus = inPlus - diferentePartiale[id17];

                ans += max(0LL, total - total2 - inPlus);
            }
            else
            {
                int index;
                index = id10;
                if (index <= 0)
                    continue;

                

                long long total = maiMiciSauEgaleVectorSumePartiale[index].cnt;

                long long total2;

                int id17 = QueryHash(a[i].x, a[i].y, QueryIndexNestrict);
                if (id17 == -1)
                    continue;

                total2 = maiMiciSauEgaleVectorSumePartiale[id17].cnt + 1LL * (index - id17) * maiMiciSauEgaleVector[id17].cnt;
                

                long long inPlus = diferentePartiale[index];
                inPlus = inPlus - diferentePartiale[id17];

                ans += max(0LL, total - total2 - inPlus);
            }
        }
    }
}

void id11()
{
    int id7, cnt;
    long long total;

    id7 = 0;
    total = 0LL;
    for (int i = 1; i <= N; ++ i)
    {
        int x = a[i].x, y = a[i].y;
        if (y > 0 || (y == 0 && x > 0))
            ++id7;
    }

    for (int i = 1; i <= N; ++ i)
    {
        if (a[i].y < 0)
        {
            int x = -a[i].x;
            int y = -a[i].y;
            int st = 1, dr = id7;
            int val = 0;
            while (st <= dr)
            {
                int mij = (st+dr) / 2;
                if (id16(Punct(0, 0), Punct(x, y), a[mij]) <= 0)
                {
                    val = mij;
                    st = mij + 1;
                }
                else
                    dr = mij - 1;
            }
            total += max(0, id7 - val);
        }
    }
    cnt = 0;
    for (int i = 1; i <= N; ++ i)
        if (a[i].y == 0 && a[i].x > 0)
            ++ cnt;


    ans = ans - 1LL * total * cnt;
}


int main()
{
    
    ifstream cin("data.in");
    

    
    std::ios_base::sync_with_stdio(false);
    

    cin >> N >> C >> D;
    for (int i = 1; i <= N; ++ i)
    {
        int x, y;
        cin >> x >> y;
        a[i] = Punct(x - C, y - D);
    }

    Solve();

    id11();

    for (int i = 0; i < MOD; ++ i)
        H[i].clear();
    for (int i = 1; i <= N; ++ i)
    {
        a[i].x = -a[i].x;
        a[i].y = -a[i].y;
    }
    Solve();

    id11();

    cout << ans << "\n";


    return 0;
}

long long sqr(const long long &x)
{
    return x * x;
}

long long id16(const Punct &A, const Punct &B, const Punct &C)
{
    return 1LL * (A.x - C.x) * (B.y - C.y) - 1LL * (A.y - C.y) * (B.x - C.x);
}

long long Dist2(const Punct &A, const Punct &B)
{
    return sqr(A.x - B.x) + sqr(A.y - B.y);
}

int id9(const Punct &A)
{
    if (A.x > 0 && A.y > 0)
        return 1;
    if (A.x < 0 && A.y > 0)
        return 2;
    if (A.x < 0 && A.y < 0)
        return 3;
    

    return 4;
}

long double GetAngle(const Punct &A)
{
    long double ret = atan2(A.y, A.x);
    if (A.y < 0)
        ret = ret + PI * 2.0;
    return ret;
}

long long id6(const Punct &A, const Punct &B)
{
    
    long long ret = id16(Punct(0, 0), A, B);
    if (ret > 0)
        return -1;
    if (ret < 0)
        return 1;

    if(A.y == 0 && B.y == 0)
    {
        if ((A.x > 0 && B.x > 0) || (A.x < 0 && B.x < 0))
            return 0;
        if (A.x > 0 && B.x < 0)
            return -1;
        return 1;
    }

    if (A.x == 0 && B.x == 0)
    {
        if ((A.y > 0 && B.y > 0) || (A.y < 0 && B.y < 0))
            return 0;
        if (A.y > 0 && B.y < 0)
            return -1;
        return 1;
    }

    int id0, id5, id13, id4;
    id0 = id5 = id13 = id4 = 1;
    if (A.x < 0) id0 = -1;
    if (B.x < 0) id5 = -1;
    if (A.y < 0) id13 = -1;
    if (B.y < 0) id4 = -1;

    if (id0 == id5 && id13 == id4)
        return 0;
    if (id13 == 1)
        return -1;
    return 1;
}
