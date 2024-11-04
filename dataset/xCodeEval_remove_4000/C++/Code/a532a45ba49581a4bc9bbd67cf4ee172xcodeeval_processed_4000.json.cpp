








using namespace std;

const int NMax = 210;
const int INF = 2000000000;
const int id6 = NMax * NMax;
int N, M, Q;
int dx[10], dy[10];
int G[id6];
char aux[210][210];
int grad[NMax * NMax];
int nviz;
int viz[NMax * NMax], cntviz;
int viz2[NMax * NMax];
queue <int> coada;

struct ListNode
{
    bool isCycle;
    bool hasNextComputed;
    int numar;
    int x, y, nodeNumber;
    ListNode *next[10];
    ListNode *urm;
    ListNode *pred;
};

ListNode *id0;
int id4;
ListNode *Lant[NMax * NMax];

bool Interior(int x, int y)
{
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

int id3(int x, int y)
{
    return M * (x - 1) + y;
}

void id5(int node, int &x, int &y)
{
    y = node % M;
    if (y == 0)
        y = M;
    x = node / M;
    if (y != M)
        x ++;
}

int id7;
int id1;
int maskOfCycleContainingTheNode[NMax * NMax];
int ciclulLui[NMax * NMax];
int amMasca[NMax * NMax];
ListNode *PointerToCycleWhichHasMask[NMax * NMax];
ListNode *PointerToNodeWhichIsNotInCycle[NMax * NMax];

void DFS2(int node)
{
    if(viz[node] == nviz)
    {
        viz[node] = -nviz;
        ciclulLui[node] = id7;
        coada.push(node);
        int x, y;
        id5(node, x, y);
        id1 = id1 | (1 << (aux[x][y] - '0'));
        DFS2(G[node]);
    }
}

void DFS(int node)
{
    if (viz[node] == 0)
    {
        viz[node] = nviz;
        DFS(G[node]);
    }
    else if (viz[node] == nviz)
    {
        ++id7;
        id1 = 0;
        DFS2(node);
        while (!coada.empty())
        {
            int x = coada.front();
            coada.pop();
            maskOfCycleContainingTheNode[x] = id1;
            amMasca[id1] = 1;
        }
    }
}

int viz3[NMax * NMax];
int vizCicli[NMax * NMax];

void DFS3(int node, int father)
{
    if (father != -1 && viz3[father])
        return ;
    if (father != -1)
        viz3[father] = 1;

    if (maskOfCycleContainingTheNode[node] != 0)
    {
        

        int nowMask = maskOfCycleContainingTheNode[node];
        vizCicli[ nowMask ] = 1;
        PointerToNodeWhichIsNotInCycle[father] -> urm = PointerToCycleWhichHasMask[ nowMask ];
        return ;
    }
    else if (father != -1)
    {
        PointerToNodeWhichIsNotInCycle[father] -> urm = PointerToNodeWhichIsNotInCycle[node];
        DFS3(G[node], node);
    }
    else
    {
        DFS3(G[node], node);
    }

}


void DFS_DP(ListNode *p)
{
    if (p -> isCycle == true)
    {
        p -> hasNextComputed = true;
        return ;
    }
    if (p -> hasNextComputed == true)
        return ;

    DFS_DP(p -> urm);

    for (int i = 0; i <= 9; ++ i)
        p->next[i] = p->urm->next[i];

    if (p -> urm -> isCycle == true)
    {
        for (int i = 0; i <= 9; ++ i)
            if (p->urm->next[i] == NULL)
                p->next[i] = NULL;
            else
                p->next[i]= p->urm;
        return ;
    }
    int id2 = p -> urm -> numar;
    p->next[id2] = p->urm;
}


void Precalc()
{
    id0 = new ListNode();
    id0 -> hasNextComputed = false;
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
        {
            int now = id3(i, j);
            int cifra = aux[i][j] - '0';
            int nexti, nextj;
            nexti = i + dx[cifra];
            nextj = j + dy[cifra];
            int nxt;
            if (Interior(nexti, nextj))
            {
                nxt = id3(nexti, nextj);
            }
            else
                nxt = now;
            G[now] = nxt;







































        }
    for (int i = 1; i <= N * M; ++ i)
        ++grad[ G[i] ];
    for (int i = 1; i <= N * M; ++ i)
    {
        if (grad[i] == 0)
        {
            ++nviz;
            DFS(i);
        }
    }
    for (int i = 1; i <= N * M; ++ i)
        if (viz[i] == 0)
        {
            ++nviz;
            DFS(i);
        }
    for (int i = 1; i <= 1023; ++ i)
    {
        PointerToCycleWhichHasMask[i] = new ListNode();
        PointerToCycleWhichHasMask[i] -> isCycle = true;
        PointerToCycleWhichHasMask[i] -> numar = i;
        PointerToCycleWhichHasMask[i] -> urm = NULL;
        PointerToCycleWhichHasMask[i] -> pred = NULL;
        PointerToCycleWhichHasMask[i] -> hasNextComputed = false;
        for (int k = 0; k < 10; ++ k)
            if (i & (1 << k))
                PointerToCycleWhichHasMask[i] -> next[k] = id0;
            else
                PointerToCycleWhichHasMask[i] -> next[k] = NULL;
    }


    for (int i = 1; i <= N * M; ++ i)
    {
        if (maskOfCycleContainingTheNode[i] == 0) 

        {
            int x, y;
            id5(i, x, y);
            PointerToNodeWhichIsNotInCycle[i] = new ListNode();
            PointerToNodeWhichIsNotInCycle[i] -> isCycle = false;
            PointerToNodeWhichIsNotInCycle[i] -> numar = (int)(aux[x][y] - '0');
            PointerToNodeWhichIsNotInCycle[i] -> hasNextComputed = false;
            for (int j = 0; j <= 9; ++ j)
                PointerToNodeWhichIsNotInCycle[i] -> next[j] = NULL;
            PointerToNodeWhichIsNotInCycle[i] -> urm = false;
            PointerToNodeWhichIsNotInCycle[i] -> pred = false;
            PointerToNodeWhichIsNotInCycle[i] -> x = x;
            PointerToNodeWhichIsNotInCycle[i] -> x = y;
            PointerToNodeWhichIsNotInCycle[i] -> nodeNumber = i;
        }
        else
        {
            PointerToNodeWhichIsNotInCycle[i] = NULL;
        }
    }
  

    for (int i = 1; i <= N; ++ i)
    {
        for (int j = 1; j <= M; ++ j)
        {
            int now = id3(i, j);
            int cifra = aux[i][j] - '0';
            int nexti, nextj;
            nexti = i + dx[cifra];
            nextj = j + dy[cifra];
            int nxt = id3(nexti, nextj);






















            if (maskOfCycleContainingTheNode[now] != 0)
                continue;
            if (!Interior(nexti, nextj))
                continue;















            if (maskOfCycleContainingTheNode[nxt] != 0)
            {
                int mask = maskOfCycleContainingTheNode[nxt];
                vizCicli[mask] = 1;
                PointerToNodeWhichIsNotInCycle[now] -> urm = PointerToCycleWhichHasMask[mask];
                PointerToCycleWhichHasMask[mask] -> pred = PointerToNodeWhichIsNotInCycle[now];
            }
            else
            {
                PointerToNodeWhichIsNotInCycle[now] -> urm = PointerToNodeWhichIsNotInCycle[nxt];
                PointerToNodeWhichIsNotInCycle[nxt] -> pred = PointerToNodeWhichIsNotInCycle[now];
            }
        }
    }
   





















































    for (int i = 1; i <= 1023; ++ i)
        if (amMasca[i])
            Lant[++id4] = PointerToCycleWhichHasMask[i];

    for (int i = 1; i <= N * M; ++ i)
        if (PointerToNodeWhichIsNotInCycle[i] != NULL && PointerToNodeWhichIsNotInCycle[i] -> pred == NULL)
            Lant[++id4] = PointerToNodeWhichIsNotInCycle[i];


















    for (int i = 1; i <= id4; ++ i)
    {
        DFS_DP(Lant[i]);
    }
}

int biti[1000010];

bool OK(char *s, int index)
{
    int n = strlen(s + 1);
    biti[n + 1] = 0;
    for (int i = n; i >= 1; -- i)
    {
        biti[i] = biti[i + 1] | (1 << (s[i] - '0'));
    }
    ListNode *p;
    for (int i = 1; i <= id4; ++ i)
    {
        p = Lant[i];
        int j = 1;
        if (p->isCycle)
        {
            int nowMask = p->numar;
            if ((biti[1] & nowMask) == biti[1])
                return true;
        }
        else
        {

            p = Lant[i];
            int cifra = s[1] - '0';
            if (p->numar == cifra)
                ;
            else
                p = p->next[cifra];
            if (p == NULL)
                continue;
            while (true)
            {
                

                if (p == NULL)
                {
                    break;
                }
                if (j == n)
                    return true;
                if (p -> isCycle)
                {
                    int nowMask = p->numar;
                    if ((biti[j+1] & nowMask) == biti[j+1])
                        return true;
                    break;
                }
                int cifra = s[j+1] - '0';
                p = p->next[cifra];
                ++j;

            }
        }

    }

    return false;
}

bool gata;
pii debugsteps[5];
int ndebug;
int vizmat[210][210], nvizmat;

void DFS4(int x, int y, char ch)
{
    if (gata)
    {
        return;
    }
    if (vizmat[x][y] == nvizmat)
    {
        if (ndebug == 3)
            cout <<"ciclu3\n";
        return ;
    }
    int xx, yy, cifra = aux[x][y] - '0';
    xx = x + dx[cifra];
    yy = y + dy[cifra];
    if (!Interior(xx, yy))
    {
        if (ndebug == 3)
        {
            cout << x << " " << y << "\n";
            cout << aux[x][y] << "\n";
            cout <<"N3\n";
        }
        return ;
    }
    vizmat[x][y] = nvizmat;
    if (ch == '8' && aux[x][y] == ch)
    {
        debugsteps[++ndebug] = mp(x, y);
        DFS4(xx, yy, '4');
    }
    else if (ch == '4' && aux[x][y] == ch)
    {
        debugsteps[++ndebug] = mp(x, y);
        DFS4(xx, yy, '1');
    }
    else if (ch == '1' && aux[x][y] == ch)
    {
        debugsteps[++ndebug] = mp(x, y);
        for (int i = 1; i <= ndebug; ++ i)
            cout << debugsteps[i].first << " " << debugsteps[i].second << "\n";
        cout << "\n";
        DFS4(xx, yy, '5');
    }
    else if (ch == '5' && aux[x][y] == ch)
        gata = true;

    else
        DFS4(xx, yy, ch);

}

int main()
{
    
    ifstream cin("data.in");
    

    
    std::ios_base::sync_with_stdio(false);
    

    cin >> N >> M >> Q;

    for (int i = 1; i <= N; ++ i)
    {
        cin >> (aux[i]+1);
    }
    for (int i = 0; i <= 9; ++ i)
        cin >> dx[i] >> dy[i];

    Precalc();
























































































































    char query[1000010];
    for (int i = 1; i <= Q; ++ i)
    {
        cin >> (query + 1);




















































































        if (OK(query, i))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
