









using namespace std;







int N, S;


typedef struct{
    int num;
    int pos;
} input_t;


input_t carray[MAX_N+1]; 

enum {
    id11, 
    id8, 
    PATH_TYPE_ANY,
};

typedef struct{
    int subend;
    int type; 

}subpath_t;

typedef struct{
    int end;
    vector<subpath_t> subpathlist;
    

} path_t;

typedef struct _group_dist_table_entry
{
    int distance; 

    vector<path_t> pathlist; 

} group_dist_table_entry;



group_dist_table_entry groupDistFrom[MAX_N+1]; 

typedef struct{
    int dist;
    int prvGrEnd;
    int grStart;
} GrLinkDist;


GrLinkDist distSumTo[MAX_N+1]; 


class group_info
{
public:
    int startInSorted;
    int endInSorted;
};
 
group_info GI[MAX_N+1];
int grCnt;



void id5(int g);



int id15(int from, int to)
{
    int t;
    if (from>to)
    {
        t = from;
        from = to;
        to = t;
    }
    return N+carray[from].pos-carray[to].pos;
}



int id13(int from, int to)
{
    int t;
    if (from>to)
    {
        t = from;
        from = to;
        to = t;
    }
    return carray[to].pos-carray[from].pos;
}

int get_move(int from, int to, int type)
{
    int pos0, pos1;
    int ld, cd;
    if (type == id11)
    {
        return carray[to].pos - carray[from].pos;
    }
    else
    if (type == id8)
    {
        if (carray[from].pos < carray[to].pos)
        {
            return (N+carray[from].pos- carray[to].pos)*(-1);
        }
        return (N+carray[to].pos- carray[from].pos);
    }
    
    pos0 = carray[from].pos;
    pos1 = carray[to].pos;
    if (pos0 < pos1)
    {
        cd = N+pos0-pos1;
        ld = pos1 - pos0;
        if (ld <= cd)
            return ld;
        else
            return cd*(-1);
    }
    cd = N+pos1-pos0;
    ld = pos0 - pos1;
    if (ld <= cd)
        return ld*(-1);
    else
        return cd;
}

void id9(int gId)
{
    int s, e;
    int gStart = GI[gId].startInSorted;
    int gEnd = GI[gId].endInSorted;
    if (gStart==gEnd)
    {
        path_t path;
        e = s = gStart;
        path.end = e;
        groupDistFrom[s].pathlist.push_back(path);
        groupDistFrom[s].distance = 0;
        return;
    }
    int contRange = carray[gEnd].pos-carray[gStart].pos;
    for (s=gStart; s<=gEnd ; s++)
    {
        int minDist=INT_MAX;
        int minEnd;
        vector<path_t> id2;
        

        
        for (e=gStart; e<=gEnd ; e++)
        {
            if (s==e)
                continue;
            path_t path1, path2;
            path1.end = e;
            path2.end = e;
                
            vector<subpath_t> & id7 = path1.subpathlist;
            vector<subpath_t> & id12 = path2.subpathlist;
            
            subpath_t subpath;
            int id10 = 0;
            int id6 = 0;
            int re, le ; 

            if (e< gEnd)
                re = e+1;
            else
                re = gStart;
            if (e> gStart)
                le = e-1;
            else
                le = gEnd;
            
            if (s < e)
            {
                

                if (re > e)
                {
                    if (s != re)
                    {
                        id10 += id15(s, re); 

                        subpath.subend = re;
                        subpath.type = id8;
                        id7.push_back(subpath);
                    }
                    id10 += id15(re, e); 

                    subpath.subend = e;
                    subpath.type = id8;
                    id7.push_back(subpath);
                }
                else
                {
                    

                    if (s != re)
                    {
                        id10 += id13(s, re);
                        subpath.subend = re;
                        subpath.type = id11;
                        id7.push_back(subpath);
                    }
                    id10 += id13(re, e);
                    subpath.subend = e;
                    subpath.type = id11;
                    id7.push_back(subpath);
                }
                

                {
                    if (s != le)
                    {
                        id6 += id13(s, le); 

                        subpath.subend = le;
                        subpath.type = id11;
                        id12.push_back(subpath);
                    }
                    id6 += id15(le, e); 

                    subpath.subend = e;
                    subpath.type = id8;
                    id12.push_back(subpath);
                }
            }
            else 

            {
                if (le < e)
                {
                    if (s != le)
                    {
                        id10 += id15(s, le); 

                        subpath.subend = le;
                        subpath.type = id8;
                        id7.push_back(subpath);
                    }
                    id10 += id15(le, e); 

                    subpath.subend = e;
                    subpath.type = id8;
                    id7.push_back(subpath);
                }
                else
                {
                    

                    if (s != le)
                    {
                        id10 += id13(s, le);
                        subpath.subend = le;
                        subpath.type = id11;
                        id7.push_back(subpath);
                    }
                    id10 += id13(le, e);
                    subpath.subend = e;
                    subpath.type = id11;
                    id7.push_back(subpath);
                
                }
                

                {
                    if (s != re)
                    {
                        id6 += id13(s, re); 

                        subpath.subend = re;
                        subpath.type = id11;
                        id12.push_back(subpath);
                    }
                    id6 += id15(re, e); 

                    subpath.subend = e;
                    subpath.type = id8;
                    id12.push_back(subpath);
                }
            }
            if (id10<=minDist)
            {
                if (id10<minDist)
                {
                    groupDistFrom[s].pathlist.clear();
                }
                groupDistFrom[s].pathlist.push_back(path1);
                groupDistFrom[s].distance = minDist = id10;
            }
            if (id6<=minDist)
            {
                if (id6<minDist)
                {
                    groupDistFrom[s].pathlist.clear();
                }
                groupDistFrom[s].pathlist.push_back(path2);
                groupDistFrom[s].distance = minDist = id6;
            }
        }
    }

                
     
        int sPos = carray[s].pos;
        

        int d1 = contRange + min(carray[s].pos-carray[gStart].pos, carray[gEnd].pos-carray[s].pos);
        
        

        int d2 ;
        if (s==gEnd)
        {
            end_t eEntry;
            d2 = N+carray[s-1].pos - sPos;
            if (d1<=d2)
            {
                groupDistFrom[s].distance = d1;
                eEntry.type=0;
                eEntry.end=gStart;
                groupDistFrom[s].endlist.push_back(eEntry);
            }
            if (d1>=d2)
            {
                groupDistFrom[s].distance = d2;
                eEntry.type=1;
                eEntry.end=s-1;
                groupDistFrom[s].endlist.push_back(eEntry);
            }
        }
        else
        if (s==gStart)
        {
            end_t eEntry;
            d2 = N+carray[s].pos - carray[s+1].pos;
            if (d1<=d2)
            {
                groupDistFrom[s].distance = d1;
                eEntry.type=0;
                eEntry.end=gEnd;
                groupDistFrom[s].endlist.push_back(eEntry);
            }
            if (d1>=d2)
            {
                groupDistFrom[s].distance = d2;
                eEntry.type=1;
                eEntry.end=s+1;
                groupDistFrom[s].endlist.push_back(eEntry);
            }
        }
        else
        {
            vector<end_t> id4, id0;
            end_t eEntry;
            int rightDist;
            int leftDist;
            rightDist = carray[gEnd].pos - carray[s].pos;
            leftDist = carray[s].pos - carray[gStart].pos;
            if (rightDist >= leftDist)
            {
                d1 += leftDist;
                eEntry.type=0;
                eEntry.end=gEnd;
                id4.push_back(eEntry);
            }
            if (rightDist <= leftDist)
            {
                d1 += rightDist;
                eEntry.type=0;
                eEntry.end=gStart;
                id4.push_back(eEntry);
            }
            
            
            rightDist = carray[s+1].pos - carray[s].pos;
            leftDist = carray[s].pos - carray[s-1].pos;
            if (rightDist >= leftDist)
            {
                d2 = N+carray[s].pos - carray[s+1].pos;
                eEntry.type=1;
                eEntry.end=s+1;
                id0.push_back(eEntry);
            }
            if (rightDist <= leftDist)
            {
                d2 = N+carray[s-1].pos - sPos;
                eEntry.type=1;
                eEntry.end=s-1;
                id0.push_back(eEntry);
            }
            if (d1<=d2)
            {
                groupDistFrom[s].distance = d1;
                groupDistFrom[s].endlist.insert(groupDistFrom[s].endlist.end(), id4.begin(), id4.end()); 
            }
            if (d1>=d2)
            {
                groupDistFrom[s].distance = d2;
                groupDistFrom[s].endlist.insert(groupDistFrom[s].endlist.end(), id0.begin(), id0.end()); 
            }
        }
    }

    id5(gId);
}
        
        


void id1(const char *exp)
{

    int i;
    cout << "[" << exp << "]" << " carray >>=============" << endl;
    for (i=1 ; i<= N; i++)
    { 
        printf("[%d] num %d pos %d\n", i, carray[i].num, carray[i].pos);
    }
    cout << "[" << exp << "]" << " carray <<=============" << endl;

}


void id5(int g)
{

    int s;
    int gStart = GI[g].startInSorted;
    int gEnd = GI[g].endInSorted;
    cout << "group [" << g << "] >>=============" << endl;
    for (s=gStart; s<=gEnd ; s++)
    {
        printf("groupDistFrom[%d] dist %d \n", s, groupDistFrom[s].distance);
        

        vector<path_t>::iterator it;
        for (it=groupDistFrom[s].pathlist.begin(); it!=groupDistFrom[s].pathlist.end();
                it++)
        {
            printf("\t end %d : ", (*it).end);
            vector<subpath_t>::iterator iit;
            for (iit=(*it).subpathlist.begin(); iit!=(*it).subpathlist.end();
                    iit++)
            {
                printf(" -> %d(%d)", (*iit).subend, (*iit).type);
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "group dist" << g << "<<=============" << endl;

}

int id3;
int minSum = INT_MAX;        
            
void find_solution()
{
    int g;
    for (g=0; g< grCnt; g++ )
    {
        id9(g);
    }
    
    carray[0].pos = S;
    distSumTo[0].dist = 0;
    int si, di, gi, ngi;
 
    
    for (si=1; si <= N; si++)
    {
        distSumTo[si].dist=INT_MAX;
    }
    
    for (gi=0; gi < grCnt; gi++)
    {
        ngi=gi+1;
        for (si = GI[gi].startInSorted; si<= GI[gi].endInSorted ;  si++)
        {
            if (distSumTo[si].dist == INT_MAX)
                continue;
            for (di = GI[ngi].startInSorted; di<= GI[ngi].endInSorted ;  di++)
            {
 
                int nsum = distSumTo[si].dist+abs(get_move(si, di, PATH_TYPE_ANY))+ groupDistFrom[di].distance;
                
                vector<path_t>::iterator it;
                for (it=groupDistFrom[di].pathlist.begin(); it != groupDistFrom[di].pathlist.end(); it++)
                {
                   
                    if (nsum< distSumTo[(*it).end].dist)
                    {
                        distSumTo[(*it).end].dist = nsum;
                        distSumTo[(*it).end].grStart = di;
                        distSumTo[(*it).end].prvGrEnd = si;
                        if (ngi==(grCnt-1))
                        {
                            if (minSum > nsum)
                            {
                                minSum= nsum;
                                id3 = (*it).end;
                            }
                        }

                        printf("-> %d -> %d -> %d: dist %d\n", si, di, (*it).end, nsum);

                    }
                }
            }
        }
    }


}

bool cmp(input_t a, input_t b)
{
    if (a.num < b.num)
        return true;
    if (a.num > b.num)
        return false;
    if (a.pos < b.pos)
        return true;
    if (a.pos > b.pos)
        return false;
    return false; 

}

typedef struct 
{
    int grId;
    int grStart;
    int grEnd;
} GroupPath_T;

stack<GroupPath_T> pathStack;
int visitFlag[MAX_N+1] = { 0 };  
void print_move(int from, int to, int type, bool groupLocal, int grId)
{
    if (!groupLocal)
    {
        int move = get_move(from, to, PATH_TYPE_ANY);

        printf("[%d]%d->[%d]%d : dist %d\n", from, carray[from].pos, to, carray[to].pos, move);

        if (move>=0)
            printf("+");
        printf("%d\n", move);
        visitFlag[to] = 1;
        return;
    }
    if (from == to)
    {

        printf("[%d]%d->[%d]%d : dist %d\n", from, carray[from].pos, to, carray[to].pos, 0);

        printf("+0\n");
        visitFlag[to] = 1;
        return;
    }
   
    int inc=1;
    if (carray[from].pos < carray[to].pos && type == id8)
    {
        inc = -1;
    }
    else
    if (carray[from].pos > carray[to].pos && type == id11)
    {
        inc = -1;
    }
    int i=from, pi;
    for (pi= i; i!=to ; )
    {
        int type;
        do 
        {
            type = id11;
            i+=inc;
            if (i > GI[grId].endInSorted)
            {
                i = GI[grId].startInSorted;
                type = id8;
            }
            else
            if (i < GI[grId].startInSorted)
            {
                i = GI[grId].endInSorted;
                type = id8;
            }
        }  while (visitFlag[i]==1);
        int move = get_move(pi, i, type);

        printf("[%d]%d->[%d]%d : dist %d\n", pi, carray[pi].pos, i, carray[i].pos, move);

        if (move>=0)
            printf("+");
        printf("%d\n", move);
        visitFlag[i] = 1;
        pi = i;    
    }
}

void print_path()
{
    int grStart, grEnd = id3;
    int grId = grCnt-1;
    for (  ; grEnd>0 ; grEnd = distSumTo[grEnd].prvGrEnd, grId--)
    {
        GroupPath_T grPath;
        grPath.grStart = distSumTo[grEnd].grStart;
        grPath.grEnd = grEnd;
        grPath.grId = grId;
        pathStack.push(grPath);
    }
    int id14 = 0;
    while (pathStack.size()>0)
    {
        GroupPath_T grPath = pathStack.top();
        grStart = grPath.grStart;
        grEnd = grPath.grEnd;
        grId = grPath.grId;
        pathStack.pop();
        print_move(id14, grStart, id11, false, -1);
        vector<path_t>::iterator it ;
    
        bool pathFound = false;
        for (it = groupDistFrom[grStart].pathlist.begin(); it != groupDistFrom[grStart].pathlist.end();it++)
        {
            if ((*it).end == grEnd)
            {
                pathFound = true;
                
                break;
            }
        }
        if (!pathFound)
        {
            cout << "Error!: not found Group Path!" << endl;
            continue;
        }
        int from = grStart, to;
        vector<subpath_t>::iterator iit ;
        for (iit=(*it).subpathlist.begin(); iit!=(*it).subpathlist.end();
                iit++)
        {
            to = (*iit).subend;
            print_move(from, to, (*iit).type, true, grId);
            from = (*iit).subend;
        } 
        id14 = grEnd;
    }
            
}

int main(int argc, char **argv)
{
    int i;
    
  

    cin >> N >> S;
    for (i=1 ; i<= N; i++)
    {
        input_t in;
        cin >> in.num;
        in.pos = i;
        carray[i] = in;
    }
    id1("ORG");
    sort(&carray[1], &carray[N+1], cmp); 
    id1("SORTED");
    

    grCnt = 0;
    carray[0].num = INT_MIN;
    GI[grCnt++].startInSorted = 0;
    
    int prevNum = carray[0].num;
    for (i=1; i<=N ; i++)
    {
        if (carray[i].num > prevNum)
        {
            GI[grCnt-1].endInSorted = i-1;
            GI[grCnt++].startInSorted = i;
            prevNum = carray[i].num;
        }
    }
    GI[grCnt-1].endInSorted = i-1;
    
    find_solution();

    cout << "minSum = " << minSum << endl;
    cout << "id3 = " << id3 << endl;

    printf("%d\n", minSum);
    print_path();
    return 0;
}
