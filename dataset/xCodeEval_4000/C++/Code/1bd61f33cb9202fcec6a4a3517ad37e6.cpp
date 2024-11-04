#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>




using namespace std;

#define IN
#define OUT 
#define MAX_N 2000



int N, S;


typedef struct{
    int num;
    int pos;
} input_t;


input_t carray[MAX_N+1]; 

enum {
    PATH_TYPE_DIRECT, 
    PATH_TYPE_CIRCULAR, 
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



void show_groupDistFrom(int g);



int cir_dist_in_group(int from, int to)
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



int line_dist_in_group(int from, int to)
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
    if (type == PATH_TYPE_DIRECT)
    {
        return carray[to].pos - carray[from].pos;
    }
    else
    if (type == PATH_TYPE_CIRCULAR)
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

void build_group_dist_table(int gId)
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
        vector<path_t> minPathlist;
        

        
        for (e=gStart; e<=gEnd ; e++)
        {
            if (s==e)
                continue;
            path_t path1, path2;
            path1.end = e;
            path2.end = e;
                
            vector<subpath_t> & subpathlist1 = path1.subpathlist;
            vector<subpath_t> & subpathlist2 = path2.subpathlist;
            
            subpath_t subpath;
            int pairDist1 = 0;
            int pairDist2 = 0;
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
                        pairDist1 += cir_dist_in_group(s, re); 

                        subpath.subend = re;
                        subpath.type = PATH_TYPE_CIRCULAR;
                        subpathlist1.push_back(subpath);
                    }
                    pairDist1 += cir_dist_in_group(re, e); 

                    subpath.subend = e;
                    subpath.type = PATH_TYPE_CIRCULAR;
                    subpathlist1.push_back(subpath);
                }
                else
                {
                    

                    if (s != re)
                    {
                        pairDist1 += line_dist_in_group(s, re);
                        subpath.subend = re;
                        subpath.type = PATH_TYPE_DIRECT;
                        subpathlist1.push_back(subpath);
                    }
                    pairDist1 += line_dist_in_group(re, e);
                    subpath.subend = e;
                    subpath.type = PATH_TYPE_DIRECT;
                    subpathlist1.push_back(subpath);
                }
                

                {
                    if (s != le)
                    {
                        pairDist2 += line_dist_in_group(s, le); 

                        subpath.subend = le;
                        subpath.type = PATH_TYPE_DIRECT;
                        subpathlist2.push_back(subpath);
                    }
                    pairDist2 += cir_dist_in_group(le, e); 

                    subpath.subend = e;
                    subpath.type = PATH_TYPE_CIRCULAR;
                    subpathlist2.push_back(subpath);
                }
            }
            else 

            {
                if (le < e)
                {
                    if (s != le)
                    {
                        pairDist1 += cir_dist_in_group(s, le); 

                        subpath.subend = le;
                        subpath.type = PATH_TYPE_CIRCULAR;
                        subpathlist1.push_back(subpath);
                    }
                    pairDist1 += cir_dist_in_group(le, e); 

                    subpath.subend = e;
                    subpath.type = PATH_TYPE_CIRCULAR;
                    subpathlist1.push_back(subpath);
                }
                else
                {
                    

                    if (s != le)
                    {
                        pairDist1 += line_dist_in_group(s, le);
                        subpath.subend = le;
                        subpath.type = PATH_TYPE_DIRECT;
                        subpathlist1.push_back(subpath);
                    }
                    pairDist1 += line_dist_in_group(le, e);
                    subpath.subend = e;
                    subpath.type = PATH_TYPE_DIRECT;
                    subpathlist1.push_back(subpath);
                
                }
                

                {
                    if (s != re)
                    {
                        pairDist2 += line_dist_in_group(s, re); 

                        subpath.subend = re;
                        subpath.type = PATH_TYPE_DIRECT;
                        subpathlist2.push_back(subpath);
                    }
                    pairDist2 += cir_dist_in_group(re, e); 

                    subpath.subend = e;
                    subpath.type = PATH_TYPE_CIRCULAR;
                    subpathlist2.push_back(subpath);
                }
            }
            if (pairDist1<=minDist)
            {
                if (pairDist1<minDist)
                {
                    groupDistFrom[s].pathlist.clear();
                }
                groupDistFrom[s].pathlist.push_back(path1);
                groupDistFrom[s].distance = minDist = pairDist1;
            }
            if (pairDist2<=minDist)
            {
                if (pairDist2<minDist)
                {
                    groupDistFrom[s].pathlist.clear();
                }
                groupDistFrom[s].pathlist.push_back(path2);
                groupDistFrom[s].distance = minDist = pairDist2;
            }
        }
    }
#if 0
                
     
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
            vector<end_t> endlist1, endlist2;
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
                endlist1.push_back(eEntry);
            }
            if (rightDist <= leftDist)
            {
                d1 += rightDist;
                eEntry.type=0;
                eEntry.end=gStart;
                endlist1.push_back(eEntry);
            }
            
            
            rightDist = carray[s+1].pos - carray[s].pos;
            leftDist = carray[s].pos - carray[s-1].pos;
            if (rightDist >= leftDist)
            {
                d2 = N+carray[s].pos - carray[s+1].pos;
                eEntry.type=1;
                eEntry.end=s+1;
                endlist2.push_back(eEntry);
            }
            if (rightDist <= leftDist)
            {
                d2 = N+carray[s-1].pos - sPos;
                eEntry.type=1;
                eEntry.end=s-1;
                endlist2.push_back(eEntry);
            }
            if (d1<=d2)
            {
                groupDistFrom[s].distance = d1;
                groupDistFrom[s].endlist.insert(groupDistFrom[s].endlist.end(), endlist1.begin(), endlist1.end()); 
            }
            if (d1>=d2)
            {
                groupDistFrom[s].distance = d2;
                groupDistFrom[s].endlist.insert(groupDistFrom[s].endlist.end(), endlist2.begin(), endlist2.end()); 
            }
        }
    }
#endif    
    show_groupDistFrom(gId);
}
        
        


void show_carray(const char *exp)
{
#ifdef DEBUG
    int i;
    cout << "[" << exp << "]" << " carray >>=============" << endl;
    for (i=1 ; i<= N; i++)
    { 
        printf("[%d] num %d pos %d\n", i, carray[i].num, carray[i].pos);
    }
    cout << "[" << exp << "]" << " carray <<=============" << endl;
#endif
}


void show_groupDistFrom(int g)
{
#ifdef DEBUG
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
#endif    
}

int minPathEnd;
int minSum = INT_MAX;        
            
void find_solution()
{
    int g;
    for (g=0; g< grCnt; g++ )
    {
        build_group_dist_table(g);
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
                                minPathEnd = (*it).end;
                            }
                        }
#ifdef DEBUG                        
                        printf("-> %d -> %d -> %d: dist %d\n", si, di, (*it).end, nsum);
#endif                        
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
#ifdef DEBUG        
        printf("[%d]%d->[%d]%d : dist %d\n", from, carray[from].pos, to, carray[to].pos, move);
#endif        
        if (move>=0)
            printf("+");
        printf("%d\n", move);
        visitFlag[to] = 1;
        return;
    }
    if (from == to)
    {
#ifdef DEBUG           
        printf("[%d]%d->[%d]%d : dist %d\n", from, carray[from].pos, to, carray[to].pos, 0);
#endif          
        printf("+0\n");
        visitFlag[to] = 1;
        return;
    }
   
    int inc=1;
    if (carray[from].pos < carray[to].pos && type == PATH_TYPE_CIRCULAR)
    {
        inc = -1;
    }
    else
    if (carray[from].pos > carray[to].pos && type == PATH_TYPE_DIRECT)
    {
        inc = -1;
    }
    int i=from, pi;
    for (pi= i; i!=to ; )
    {
        int type;
        do 
        {
            type = PATH_TYPE_DIRECT;
            i+=inc;
            if (i > GI[grId].endInSorted)
            {
                i = GI[grId].startInSorted;
                type = PATH_TYPE_CIRCULAR;
            }
            else
            if (i < GI[grId].startInSorted)
            {
                i = GI[grId].endInSorted;
                type = PATH_TYPE_CIRCULAR;
            }
        }  while (visitFlag[i]==1);
        int move = get_move(pi, i, type);
#ifdef DEBUG   
        printf("[%d]%d->[%d]%d : dist %d\n", pi, carray[pi].pos, i, carray[i].pos, move);
#endif
        if (move>=0)
            printf("+");
        printf("%d\n", move);
        visitFlag[i] = 1;
        pi = i;    
    }
}

void print_path()
{
    int grStart, grEnd = minPathEnd;
    int grId = grCnt-1;
    for (  ; grEnd>0 ; grEnd = distSumTo[grEnd].prvGrEnd, grId--)
    {
        GroupPath_T grPath;
        grPath.grStart = distSumTo[grEnd].grStart;
        grPath.grEnd = grEnd;
        grPath.grId = grId;
        pathStack.push(grPath);
    }
    int prevGrEnd = 0;
    while (pathStack.size()>0)
    {
        GroupPath_T grPath = pathStack.top();
        grStart = grPath.grStart;
        grEnd = grPath.grEnd;
        grId = grPath.grId;
        pathStack.pop();
        print_move(prevGrEnd, grStart, PATH_TYPE_DIRECT, false, -1);
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
        prevGrEnd = grEnd;
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
    show_carray("ORG");
    sort(&carray[1], &carray[N+1], cmp); 
    show_carray("SORTED");
    

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
#ifdef DEBUG    
    cout << "minSum = " << minSum << endl;
    cout << "minPathEnd = " << minPathEnd << endl;
#endif
    printf("%d\n", minSum);
    print_path();
    return 0;
}
