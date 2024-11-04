#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
const long long N = 100000+5, M = 100000;
struct segm
{
    long long x1, y1, x2, y2;
};
struct coord
{
    long long x, y;
};
segm sg[N];
long long direction[N];
long long tx, ty;
long long sx[N];
long long sy[N];
bool cmpx(const long long &left,const long long &right)
{
    if(sg[left].x1 < sg[right].x1)
    return true;
    if(sg[left].x1 > sg[right].x1)
    return false;
    return (sg[left].y1 < sg[right].y1);
}
bool cmpy(const long long &left,const long long &right)
{
    if(sg[left].y1 < sg[right].y1)
    return true;
    if(sg[left].y1 > sg[right].y1)
    return false;
    return (sg[left].x1 < sg[right].x1);
}
long long t[4*N];

long long top;
coord po[4*N];
long long re[2*N];
long long d1[4*N];

long long get(long long x, long long y, long long di)
{
    long long res = 0;long long s, f, md;
    if(di%2!=0)
    {
        if(di==1)
        {
            s = 1; f = ty;
            while(s <= f)
            {
                md = (s+f)/2;
                if(sg[ sy[md] ].y1 < y)
                {
                    s = md+1;
                }
                else
                if(sg[ sy[md] ].y1 > y)
                {
                    f = md-1;
                }
                else
                {
                    if(sg[ sy[md] ].x2 < x)
                    {
                        s = md+1;
                    }
                    else
                    {
                        res = sy[md];
                        f = md-1;
                    }
                }
            }
        }
        else
        {
            s = 1; f = ty;
            while(s <= f)
            {
                md = (s+f)/2;
                if(sg[ sy[md] ].y1 < y)
                {
                    s = md+1;
                }
                else
                if(sg[ sy[md] ].y1 > y)
                {
                    f = md-1;
                }
                else
                {
                    if(sg[ sy[md] ].x1 > x)
                    {
                        f = md-1;
                    }
                    else
                    {
                        res = sy[md];
                        s = md+1;
                    }
                }
            }
        }
    }
    else
    {
        if(di==2)
        {
            s = 1; f = tx;
            while(s <= f)
            {
                md = (s+f)/2;
                if(sg[ sx[md] ].x1 < x)
                {
                    s = md+1;
                }
                else
                if(sg[ sx[md] ].x1 > x)
                {
                    f = md-1;
                }
                else
                {
                    if(sg[ sx[md] ].y2 < y)
                    {
                        s = md+1;
                    }
                    else
                    {
                        res = sx[md];
                        f = md-1;
                    }
                }
            }
        }
        else
        {
            s = 1; f = tx;
            while(s <= f)
            {
                md = (s+f)/2;
                if(sg[ sx[md] ].x1 < x)
                {
                    s = md+1;
                }
                else
                if(sg[ sx[md] ].x1 > x)
                {
                    f = md-1;
                }
                else
                {
                    if(sg[ sx[md] ].y1 > y)
                    {
                        f = md-1;
                    }
                    else
                    {
                        res = sx[md];
                        s = md+1;
                    }
                }
            }
        }
    }
    return res;
}
coord a[N];
char ch[N][5];
long long ti[N];

long long in[2*N];

long long top1, T, te, n, b, i;

long long f;
long long ab(long long x)
{
    if(x < 0)
    return -x;
    return x;
}
bool cmp1(const long long &l, const long long &r)
{
    return (po[l].x < po[r].x);
}
bool cmp2(const long long &l, const long long &r)
{
    return (po[l].y < po[r].y);
}
void update(long long v, long long tl, long long tr, long long l, long long r, long long co)
{
    long long tm;
    if(tl==l && tr==r)
    {
        t[v] = co;
        return;
    }
    if(t[v]!=-1)
    {
        t[2*v] = t[v];
        t[2*v+1] = t[v];
        t[v] = -1;
    }
    tm = (tl+tr)/2;
    if(r <= tm)
        update(2*v, tl , tm, l, r, co);
    else
    if(l > tm)
        update(2*v+1, tm+1, tr, l, r, co);
    else
    {
        update(2*v, tl, tm, l, tm, co);
        update(2*v+1, tm+1, tr, tm+1, r, co);
    }

}
long long getans(long long v, long long tl, long long tr, long long pos)
{
    long long tm;
    if(tl==tr)
    return t[v];
    if(t[v]!=-1)
    {
        t[2*v] = t[v];
        t[2*v+1] = t[v];
        t[v] = -1;
    }
    tm = (tl+tr)/2;
    if(pos <= tm)
        return getans(2*v, tl, tm, pos);
    return getans(2*v+1, tm+1, tr, pos);
}
void build()
{
    for(i = 1; i <= 4*(M+1); ++ i)
    {
        t[i] = 0;
    }
    top1 = 0;
    for(i = 1; i <= top; ++ i)
    {
        if(d1[i]==1)
        {
        ++ top1;
        in[ top1 ] = i;
        }
    }
    sort(in+1, in+top1+1, cmp1);
    f = top1;
    for(i = tx; i >= 1; -- i)
    {
        update(1, 0, M, sg[ sx[i] ].y1, sg[ sx[i] ].y2, sx[i]);
        if(sg[ sx[i] ].x1!=sg[ sx[i-1] ].x1)
        {
            while(f > 0)
            {
                if(po[ in[f] ].x > sg[ sx[i-1] ].x1)
                {
                    if(po[ in[f] ].x <= sg[ sx[i] ].x1)
                    {
                        re[ in[f] ] = getans(1, 0, M, po[ in[f] ].y);
                    }
                    --f;
                }
                else
                break;
            }
        }
    }
    

    for(i = 1; i <= 4*(M+1); ++ i)
    {
        t[i] = 0;
    }
    top1 = 0;
    for(i = 1; i <= top; ++ i)
    {
        if(d1[i]==3)
        {
        ++ top1;
        in[ top1 ] = i;
        }
    }
    sort(in+1, in+top1+1, cmp1);
    f = 1;
    for(i = 1; i <= tx; ++ i)
    {
        update(1, 0, M, sg[ sx[i] ].y1, sg[ sx[i] ].y2, sx[i]);
        if(sg[ sx[i] ].x1!=sg[ sx[i+1] ].x1)
        {
            while(f <= top1)
            {
                if(po[ in[f] ].x < sg[ sx[i+1] ].x1)
                {
                    if(po[ in[f] ].x >= sg[ sx[i] ].x1)
                    {
                        re[ in[f] ] = getans(1, 0, M, po[ in[f] ].y);
                    }
                    ++f;
                }
                else
                break;
            }
        }
    }
    

    for(i = 1; i <= 4*(M+1); ++ i)
    {
        t[i] = 0;
    }
    top1 = 0;
    for(i = 1; i <= top; ++ i)
    {
        if(d1[i]==4)
        {
        ++ top1;
        in[ top1 ] = i;
        }
    }
    sort(in+1, in+top1+1, cmp2);
    f = 1;
    for(i = 1; i <= ty; ++ i)
    {
        update(1, 0, M, sg[ sy[i] ].x1, sg[ sy[i] ].x2, sy[i]);
        if(sg[ sy[i] ].y1!=sg[ sy[i+1] ].y1)
        {
            while(f <= top1)
            {
                if(po[ in[f] ].y < sg[ sy[i+1] ].y1)
                {
                    if(po[ in[f] ].y >= sg[ sy[i] ].y1)
                    {
                        re[ in[f] ] = getans(1, 0, M, po[ in[f] ].x);
                    }
                    ++f;
                }
                else
                break;
            }
        }
    }
    

    for(i = 1; i <= 4*(M+1); ++ i)
    {
        t[i] = 0;
    }
    top1 = 0;
    for(i = 1; i <= top; ++ i)
    {
        if(d1[i]==2)
        {
        ++ top1;
        in[ top1 ] = i;
        }
    }
    sort(in+1, in+top1+1, cmp2);
    f = top1;
    for(i = ty; i >= 1; -- i)
    {
        update(1, 0, M, sg[ sy[i] ].x1, sg[ sy[i] ].x2, sy[i]);
        if(sg[ sy[i] ].y1!=sg[ sy[i-1] ].y1)
        {
            while(f > 0)
            {
                if(po[ in[f] ].y > sg[ sy[i-1] ].y1)
                {
                    if(po[ in[f] ].y <= sg[ sy[i] ].y1)
                    {
                        re[ in[f] ] = getans(1, 0, M, po[ in[f] ].x);
                    }
                    --f;
                }
                else
                break;
            }
        }
    }
}
long long dx[10] = {0, 1, 0, -1, 0};
long long dy[10] = {0, 0, 1, 0, -1};
long long top2;
coord graph[4*N];
void buildgraph()
{
    long long res1;
    for(i = 1; i <= top; ++ i)
    {
        if(i <= n)
        {
            res1 = get(po[i].x+dx[d1[i]], po[i].y+dy[d1[i]], d1[i]);
        }
        else
        {
            res1 = get(po[i].x, po[i].y, d1[i]);
        }
        if(res1!=0)
        {
            if(re[i]==0)
            {
                re[i] = res1;
            }
            else
            {
                if(d1[i]==1)
                {
                    if(sg[ res1 ].x1 < sg[ re[i] ].x1)
                    re[i] = res1;
                }
                if(d1[i]==2)
                {
                    if(sg[ res1 ].y1 < sg[ re[i] ].y1)
                    re[i] = res1;
                }
                if(d1[i]==3)
                {
                    if(sg[ res1 ].x2 > sg[ re[i] ].x2)
                    re[i] = res1;
                }
                if(d1[i]==4)
                {
                    if(sg[ res1 ].y2 > sg[ re[i] ].y2)
                    re[i] = res1;
                }
            }
        }
    }
    top2 = top;
    for(i = 1; i <= top2; ++ i)
    {
        if(re[i]!=0)
        {
            if(d1[ re[i] ]%2==d1[i]%2)
            {
                if(d1[i]%2==1)
                {
                    if(po[i].x <= po[ re[i] ].x)
                        d1[i] = 1;
                    else
                    d1[i] = 3;
                }
                else
                {
                    if(po[i].y <= po[ re[i] ].y)
                        d1[i] = 2;
                    else
                    d1[i] = 4;
                }
                graph[i].x = re[i];
                if(d1[re[i]]%2==1)
                    graph[i].y = ab(po[i].x-po[ re[i] ].x);
                else
                    graph[i].y = ab(po[i].y-po[ re[i] ].y);
            }
            else
            {
                ++ top;
                graph[ i ].x = top;
                graph[ top ].x = re[i];
                d1[ top ] = d1[ re[i] ];
                if(d1[ i ]%2==1)
                {
                    graph[i].y = ab(po[i].x-po[ re[i] ].x);
                    graph[top].y = ab(po[i].y-po[ re[i] ].y);
                    po[ top ].x = po[ re[i] ].x;
                    po[top].y = po[ i ].y;
                }
                else
                {
                    graph[i].y = ab(po[i].y-po[ re[i] ].y);
                    graph[ top ].y = ab(po[i].x-po[ re[i] ].x);
                    po[ top ].y = po[ re[i] ].y;
                    po[ top ].x = po[ i ].x;
                }
            }
        }
        else
        {
            if(d1[i]==1)
            {
                if(po[i].x!=b)
                {
                    ++ top;
                    graph[i].x = top;
                    graph[i].y = b-po[i].x;
                    po[top].x = b;
                    po[top].y = po[i].y;
                }
            }
            if(d1[i]==2)
            {
                if(po[i].y!=b)
                {
                    ++ top;
                    graph[i].x = top;
                    graph[i].y = b-po[i].y;
                    po[top].x = po[i].x;
                    po[top].y = b;
                }
            }
            if(d1[i]==3)
            {
                if(po[i].x!=0)
                {
                    ++ top;
                    graph[i].x = top;
                    graph[i].y = po[i].x;
                    po[top].x = 0;
                    po[top].y = po[i].y;
                }
            }
            if(d1[i]==4)
            {
                if(po[i].y!=0)
                {
                    ++ top;
                    graph[i].x = top;
                    graph[i].y = po[i].y;
                    po[top].x = po[i].x;
                    po[top].y = 0;
                }
            }
        }
    }
}
void read()
{
    cin>>n>>b;
    for(i = 1; i <= n; ++ i)
    {
        cin>>sg[i].x1>>sg[i].y1>>sg[i].x2>>sg[i].y2;
    }
    cin>>T;
    for(i = 1; i <= T; ++ i)
    {
        cin>>a[i].x>>a[i].y>>ch[i]>>ti[i];
    }

    
}
long long cs, cf, L;
long long ro[4*N];
long long cyer[4*N], qcy;
long long cr, roo, ver, mar[4*N];
long long top3, st[4*N];
coord p[4*N][20];
long long cy[4*N];
long long qc[4*N];
coord * dp[4*N];
void dfs(long long v)
{
    while(1)
    {
        ++ top3;
        st[ top3 ] = v;

        mar[v] = cr;
        if(graph[v].x==0)
        break;
        if(mar[ graph[v].x ]!=0)
        {
            if(mar[ graph[v].x ]==cr)
            {
                cs = graph[v].x;
                break;
            }
            else
                break;
        }
        v = graph[v].x;
    }
}
void markn(long long v)
{
    long long i;
    while(1)
    {
        -- top3;
        for(i = 0; i <= L; ++ i)
        {
            p[ v ][ i ].x = v;
            p[ v ][ i ].y = 0;
        }
        mar[v] = -mar[v];
        cy[v] = qc[cr];
        ++ qc[cr];
        if(mar[ graph[v].x ] < 0)
        {
            break;
        }
        v = graph[v].x;
    }
}
void makedp(long long v)
{
    long long i;
    while(1)
    {
        dp[cr][ cy[v] ].x = v;
        dp[cr][ cy[v]+qc[cr] ].x = v;
        v = graph[v].x;
        if(cy[v]==0)
        break;
    }
    dp[cr][ 0 ].y = 0;
    for(i = 1; i < 2*qc[cr]; ++ i)
    {
        dp[cr][i].y = dp[cr][i-1].y+graph[ dp[cr][i-1].x ].y;
    }
    cyer[cr] = dp[cr][ qc[cr] ].y;
}
void rootn()
{
    long long v, j, i;
    for(i = top3; i >= 1; -- i)
    {
        v = st[i];

        if(graph[v].x!=0)
            p[v][0].x = graph[v].x;
        else
            p[v][0].x = v;

        p[v][0].y = graph[v].y;
        for(j = 1; j <= L; ++ j)
        {
            p[v][j].x = p[ p[v][j-1].x ][ j-1 ].x;
            p[v][j].y = p[ p[v][j-1].x ][ j-1 ].y+p[v][j-1].y;
        }
    }
}
long long t1;
long long rex[N], rey[N];
void solution()
{
    long long v, j, as = 1;
    L = 0;
    while( as < top)
    {
        as = as*2;
        ++ L;
    }
    for(i = 1; i <= top; ++ i)
    {
        if(mar[i]==0)
        {
            top3 = 0;
            cs = 0;
            ++ cr;
            dfs(i);
            if(cs!=0)
            {
                qc[cr] = 0;
                qcy = cr;
                markn(cs);
                dp[ cr ] = new coord[ 2*qc[cr] ];
                makedp( cs );
            }
            rootn();
        }
    }
    for(i = n+1; i <= n+T; ++ i)
    {
        t1 = ti[i-n];
        if(p[i][L].y >= t1)
        {
            v = i;
            for(j = L; j >= 0; -- j)
            {
                if(p[v][j].y <= t1)
                {
                    t1 = t1-p[v][j].y;
                    v = p[v][j].x;
                }
            }
            if(t1!=0)
            {
                if(d1[v]==1)
                {
                    rex[i-n] = po[v].x+t1; rey[i-n] = po[v].y;


                }
                if(d1[v]==2)
                {
                    rex[i-n] = po[v].x; rey[i-n] = po[v].y+t1;


                }
                if(d1[v]==3)
                {
                    rex[i-n] = po[v].x-t1; rey[i-n] = po[v].y;


                }
                if(d1[v]==4)
                {
                    rex[i-n] = po[v].x; rey[i-n] = po[v].y-t1;


                }
            }
            else
            {
                rex[i-n] = po[v].x; rey[i-n] = po[v].y;


            }
        }
        else
        {
            if(mar[ p[i][L].x ] < 0)
            {
                t1 = t1-p[i][L].y;
                cr = ab( mar[ p[i][L].x ] );
                v = cy[ p[i][L].x ];
                

                t1 = t1%cyer[ cr ];
                long long s, f, md, re;
                s = v; f = 2*qc[cr]-1;
                re = v;
                while(s <= f)
                {
                    md = (s+f)/2;
                    if(dp[cr][md].y-dp[cr][v].y <= t1)
                    {
                        s = md+1;
                        re = md;
                    }
                    else
                    {
                        f = md-1;
                    }
                }
                t1 = t1-(dp[cr][re].y-dp[cr][v].y);
                v = dp[cr][re].x;
                if(t1==0)
                {
                    rex[i-n] = po[v].x; rey[i-n] = po[v].y;


                }
                else
                {
                    if(d1[v]==1)
                    {
                        rex[i-n] = po[v].x+t1; rey[i-n] = po[v].y;


                    }
                    if(d1[v]==2)
                    {
                        rex[i-n] = po[v].x; rey[i-n] = po[v].y+t1;


                    }
                    if(d1[v]==3)
                    {
                        rex[i-n] = po[v].x-t1; rey[i-n] = po[v].y;


                    }
                    if(d1[v]==4)
                    {
                        rex[i-n] = po[v].x; rey[i-n] = po[v].y-t1;


                    }
                }
            }
            else
            {
                rex[i-n] = po[p[i][L].x].x; rey[i-n] = po[p[i][L].x].y;


            }
        }
    }
    for(i = 1; i <= T; ++ i)
    {
        cout<<rex[i]<<" "<<rey[i]<<endl;
    }

 
}




long long X;
long long u, v;
long long mark[2000][2000];
void testgen()
{
}
long long res1[N];
int pr;
void checker();



int main()
{
    long long tst = 0, check = 0, inp = 0;
    srand(time(NULL));
    ios_base::sync_with_stdio(false);

    if(inp)
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    sg[0].x1 = -1;sg[0].y1 = -1;sg[0].x2 = 0;sg[0].y2 = -1;
    if(tst)
    {
        testgen();
    }
    else
    {
        read();
    }
    sg[n+1].x1 = M+1;sg[n+1].y1 = M+1;sg[n+1].x2 = M+1;sg[n+1].y2 = M+1;
    for(i = 1; i <= n; ++ i)
    {
        ++ top;
        po[top].x = sg[i].x2;
        po[top].y = sg[i].y2;
        if(sg[i].x1==sg[i].x2)
        {
            ++ tx;
            sx[ tx ] = i;

            if(sg[i].y1 < sg[i].y2)
                d1[top] = 2;
            else
            {
                d1[top] = 4;
                swap(sg[i].y1, sg[i].y2);
            }
        }
        else
        {
            ++ ty;
            sy[ ty ] = i;

            if(sg[i].x1 < sg[i].x2)
                d1[top] = 1;
            else
            {
                d1[top] = 3;
                swap(sg[i].x1, sg[i].x2);
            }
        }
    }
    sort(sx+1, sx+tx+1, cmpx);
    sort(sy+1, sy+ty+1, cmpy);


    sx[tx+1] = n+1;
    sy[ty+1] = n+1;

    for(i = 1; i <= T; ++ i)
    {
        ++ top;
        po[top].x = a[i].x;
        po[top].y = a[i].y;

        if(ch[i][0]=='R')
            d1[top] = 1;
        if(ch[i][0]=='U')
            d1[top] = 2;
        if(ch[i][0]=='L')
            d1[top] = 3;
        if(ch[i][0]=='D')
            d1[top] = 4;
    }
    build();
    buildgraph();
    solution();
    if(check)
    checker();
    return 0;
}
void checker()
{
    long long j, de, d0, nx, ny;
    X = b;
    for(i = 1; i <= n; ++ i)
    {
        for(u = sg[i].x1; u <= sg[i].x2; ++ u)
        {
            for(v = sg[i].y1; v <= sg[i].y2; ++ v)
            {
                mark[u][v] = i;
            }
        }
    }
    i = n+T;
    

    

        u = po[i].x;v = po[i].y;
        if(ch[i-n][0]=='R')
        d0 = 1;
        if(ch[i-n][0]=='U')
        d0 = 2;
        if(ch[i-n][0]=='L')
        d0 = 3;
        if(ch[i-n][0]=='D')
        d0 = 4;
        for(j = 1; j <= ti[i-n]; ++ j)
        {
            if(mark[u][v]!=0)
            {
                d0 = d1[ mark[u][v] ];
            }
            nx = u+dx[ d0 ];
            ny = v+dy[ d0 ];
            if(nx <= X && nx >= 0 && ny <= X && ny >= 0)
            {
                u = nx;
                v = ny;
            }
            if(u!=rex[j]||v!=rey[j])
            {
                cout<<"WA\n"<<" "<<j<<"|"<<u<<" "<<v<<"["<<rex[j]<<" "<<rey[j]<<endl;
            }
        }
       
   


   

    
}
