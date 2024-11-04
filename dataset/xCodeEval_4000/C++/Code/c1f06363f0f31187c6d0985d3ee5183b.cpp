#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define left son[0]
#define right son[1]

struct Seg
{
       int fx, fy, tx, ty, number;
       Seg () {}
       Seg (int _fx, int _fy, int _tx, int _ty, int _number) : 
           fx(_fx), fy(_fy), tx(_tx), ty(_ty), number(_number) {}
}      a[200050], h[200050], v[200050], hh[200050], vv[200050], doing[200050];

struct ST
{
       int size;
       pair <int, int> p;
       ST *father, *son[2];
       ST () {}
       ST (ST *F, int S, pair <int, int> P)
       {
          father = F;
          size = S;
          p = P;
          left = right = 0;
          return;
       }
}      *rt, stree[10000050];

struct Tedge
{
       int to, flag, next;
}      edge[1000050], mem[1000050];

struct Tree1
{
       int f, down;
}      tree1[10000050];

int now, sf, nx, ny, nnx, nny, group, vs, first[1000050], last[1000050], up[1000050], scale[1000050];
int x[1000050], y[1000050], xx[1000050], yy[1000050], father[200050];
int belong[200050], need[1000050], delta[1000050];
bool firsttime, vis[1000050];
vector <int> tree[4000050];
long long result;

int Rand()
{
    return (rand() << 15) | rand();
}

void Addedge(int x, int y, int flag)
{
     edge[++now].to = y;
     edge[now].flag = flag;
     edge[now].next = first[x];
     first[x] = now;
     
     return;
}

void Addedges(int x, int y, int flag)
{
     mem[++sf].to = y;
     mem[sf].flag = flag;
     mem[sf].next = last[x];
     last[x] = sf;
     
     return;
}

int  Halfx(int ask)
{
int  low, mid, high;
     
     low = 0;
     high = nx + 1;
     while (low + 1 < high)
     {
           mid = (low + high) >> 1;
           if  (xx[mid] <= ask)
           {
               low = mid;
           }   else
           {
               high = mid;
           }
     }
     
     return low;
}

int  Halfy(int ask)
{
int  low, mid, high;
     
     low = 0;
     high = ny + 1;
     while (low + 1 < high)
     {
           mid = (low + high) >> 1;
           if  (yy[mid] <= ask)
           {
               low = mid;
           }   else
           {
               high = mid;
           }
     }
     
     return low;
}

int  Father(int current)
{
     if  (father[current] != current)
     {
         father[current] = Father(father[current]);
     }
     
     return father[current];
}

void Down1(int root)
{
     if  (tree1[root].down != 0)
     {
         if  (tree1[root].f == 0)
         {
             tree1[root].down = 0;
             return;
         }
         father[Father(tree1[root].f)] = Father(tree1[root].down);
         if  (tree1[root << 1].down != 0)
         {
             if  (tree1[root << 1].f != 0)
             {
                 father[Father(tree1[root << 1].down)] = Father(tree1[root].down);
             }
         }
         if  (tree1[(root << 1) | 1].down != 0)
         {
             if  (tree1[(root << 1) | 1].f != 0)
             {
                 father[Father(tree1[(root << 1) | 1].down)] = Father(tree1[root].down);
             }
         }
         tree1[root << 1].down = tree1[root].down;
         tree1[(root << 1) | 1].down = tree1[root].down;
         tree1[root].down = 0;
     }
     
     return;
}

void Force1(int root, int nowleft, int nowright, int askleft, int askright, int news)
{
int  mid = (nowleft + nowright) >> 1;
     
     Down1(root);
     if  (nowright < askleft || askright < nowleft)
     {
         return;
     }
     if  (askleft <= nowleft && nowright <= askright)
     {
         tree1[root].f = news;
         return;
     }
     Force1(root << 1, nowleft, mid, askleft, askright, news);
     Force1((root << 1) | 1, mid + 1, nowright, askleft, askright, news);
     tree1[root].f = max(tree1[root << 1].f, tree1[(root << 1) | 1].f);
     
     return;
}

void Update1(int root, int nowleft, int nowright, int askleft, int askright, int news)
{
int  mid = (nowleft + nowright) >> 1;
     
     Down1(root);
     if  (nowright < askleft || askright < nowleft)
     {
         return;
     }
     if  (askleft <= nowleft && nowright <= askright)
     {
         if  (tree1[root].f != 0)
         {
             tree1[root].down = news;
             Down1(root);
         }
         return;
     }
     Update1(root << 1, nowleft, mid, askleft, askright, news);
     Update1((root << 1) | 1, mid + 1, nowright, askleft, askright, news);
     tree1[root].f = max(tree1[root << 1].f, tree1[(root << 1) | 1].f);
     
     return;
}

int  Ask1(int root, int nowleft, int nowright, int askleft, int askright)
{
int  mid = (nowleft + nowright) >> 1;
     
     Down1(root);
     if  (nowright < askleft || askright < nowleft)
     {
         return 0;
     }
     if  (askleft <= nowleft && nowright <= askright)
     {
         return Father(tree1[root].f);
     }
     
     return max(Ask1(root << 1, nowleft, mid, askleft, askright), 
                Ask1((root << 1) | 1, mid + 1, nowright, askleft, askright));
}

int  X(int ask)
{
int  low, mid, high;
     
     low = 0;
     high = nnx + 1;
     while (low + 1 < high)
     {
           mid = (low + high) >> 1;
           if  (x[mid] <= ask)
           {
               low = mid;
           }   else
           {
               high = mid;
           }
     }
     
     return low;
}

int  Y(int ask)
{
int  low, mid, high;
     
     low = 0;
     high = nny + 1;
     while (low + 1 < high)
     {
           mid = (low + high) >> 1;
           if  (y[mid] <= ask)
           {
               low = mid;
           }   else
           {
               high = mid;
           }
     }
     
     return low;
}




void UST(ST *current)
{
     current -> size = 1;
     if  (current -> left)
     {
         current -> size += current -> left -> size;
     }
     if  (current -> right)
     {
         current -> size += current -> right -> size;
     }
     
     return;
}

void Rotate(ST *current, int flag)
{
     current -> father -> son[flag ^ 1] = current -> son[flag];
     if  (current -> son[flag])
     {
         current -> son[flag] -> father = current -> father;
     }
     current -> son[flag] = current -> father;
     if  (current -> father -> father)
     {
         current -> father -> father -> 
         son[current -> father -> father -> left != current -> father] = current;
     }
     current -> father = current -> father -> father;
     current -> son[flag] -> father = current;
     UST(current -> son[flag]);
     
     return;
}

void Splay(ST *current, ST *target)
{
     while (current -> father != target)
     {
           if  (current -> father -> father == target)
           {
               Rotate(current, current -> father -> right != current);
           }   else
           if  (current -> father -> father -> left == current -> father &&
               current -> father -> left == current)
           {
               Rotate(current -> father, 1);
               Rotate(current, 1);
           }   else
           if  (current -> father -> father -> right == current -> father &&
               current -> father -> right == current)
           {
               Rotate(current -> father, 0);
               Rotate(current, 0);
           }   else
           {
               Rotate(current, current -> father -> right != current);
               Rotate(current, current -> father -> right != current);
           }
     }
     UST(current);
     if  (!target)
     {
         rt = current;
     }
     
     return;
}

void Find(int ask, ST *target)
{
ST   *current = rt;
     
     while (current)
     {
           if  (current -> left)
           {
               if  (ask == current -> left -> size + 1)
               {
                   break;
               }
           }   else
           if  (ask == 1)
           {
               break;
           }
           if  (current -> left && ask < current -> left -> size + 1)
           {
               current = current -> left;
           }   else
           {
               ask--;
               if  (current -> left)
               {
                   ask -= current -> left -> size;
               }
               current = current -> right;
           }
     }
     Splay(current, target);
     
     return;
     
     return;
}

void Insert(pair <int, int> ask)
{
ST   *current = rt;
     
     while (current)
     {
           if  (ask < current -> p)
           {
               if  (current -> left)
               {
                   current = current -> left;
               }   else
               {
                   stree[++vs] = ST(current, 1, ask);
                   current -> left = &stree[vs];
                   Splay(current -> left, 0);
                   return;
               }
           }   else
           {
               if  (current -> right)
               {
                   current = current -> right;
               }   else
               {
                   stree[++vs] = ST(current, 1, ask);
                   current -> right = &stree[vs];
                   Splay(current -> right, 0);
                   return;
               }
           }
     }
     
     return;
}

int  Findkth(pair <int, int> ask)
{
ST   *current = rt, *best = rt;
     
     while (current)
     {
           if  (ask <= current -> p)
           {
               best = current;
               current = current -> left;
           }   else
           {
               current = current -> right;
           }
     }
     Splay(best, 0);
     if  (rt -> left)
     {
         return rt -> left -> size + 1;
     }
     return 1;
}




int  Up(int current)
{
     if  (up[current] != current)
     {
         up[current] = Up(up[current]);
     }
     
     return up[current];
}

void Clear(int root, int nowleft, int nowright)
{
int  mid = (nowleft + nowright) >> 1;
     
     tree[root].clear();
     if  (nowleft == nowright)
     {
         return;
     }
     Clear(root << 1, nowleft, mid);
     Clear((root << 1) | 1, mid + 1, nowright);
     
     return;
}

void Force(int root, int nowleft, int nowright, int askleft, int askright, int news)
{
int  mid = (nowleft + nowright) >> 1;
     
     if  (nowright < askleft || askright < nowleft)
     {
         return;
     }
     tree[root].push_back(news);
     if  (askleft <= nowleft && nowright <= askright)
     {
         return;
     }
     Force(root << 1, nowleft, mid, askleft, askright, news);
     Force((root << 1) | 1, mid + 1, nowright, askleft, askright, news);
     
     return;
}

void Update(int root, int nowleft, int nowright, int askleft, int askright)
{
int  mid = (nowleft + nowright) >> 1, one, two, next, temp, i, rank, ss;
ST   *die;
     
     if  (nowright < askleft || askright < nowleft)
     {
         return;
     }
     if  (askleft <= nowleft && nowright <= askright)
     {
         temp = tree[root].size();
         if  (temp == 0)
         {
             return;
         }
         
         for (ss = i = 0; i < temp; i++)
         {
             next = Up(tree[root][i]);
             if  (!vis[next])
             {
                 vis[next] = true;
                 need[++ss] = next;
                 delta[ss] = Findkth(make_pair(next, nowright + 1)) -
                             Findkth(make_pair(next, nowleft));
             }
         }
         
         for (i = 1; i <= ss; i++)
         {
             vis[need[i]] = false;
             next = Up(need[i]);
             result += delta[i];
             if  (firsttime)
             {
                 result--;
                 group = next;
                 firsttime = false;
                 continue;
             }
             if  (group == next)
             {
                 continue;
             }
             result--;
             if  (scale[group] < scale[next])
             {
                 swap(group, next);
             }
             scale[group] += scale[next];
             up[next] = group;
             while (true)
             {
                   rank = Findkth(make_pair(next, -999999999));
                   die = rt;
                   if  (die -> p.first != next)
                   {
                       break;
                   }
                   Find(rank - 1, 0);
                   Find(rank + 1, rt);
                   rt -> right -> left = 0;
                   UST(rt -> right);
                   UST(rt);
                   Insert(make_pair(group, die -> p.second));
             }
         }
         tree[root].clear();
         tree[root].push_back(group);
         return;
     }
     Update(root << 1, nowleft, mid, askleft, askright);
     Update((root << 1) | 1, mid + 1, nowright, askleft, askright);
     
     return;
}

long long Solve(int total)
{
int  nh, nv, i, j, ts, temp, pointer, next, flag, l, r, a, b, p, q, ad, one, two, rank;
long long all;
map <pair <int, int>, bool>::iterator it;
     
     nh = nv = nnx = nny = all = result = 0;
     for (i = 1; i <= total; i++)
     {
         x[++nnx] = doing[i].fx;
         x[++nnx] = doing[i].tx;
         y[++nny] = doing[i].fy;
         y[++nny] = doing[i].ty;
         if  (doing[i].fx != doing[i].tx)
         {
             hh[++nh] = doing[i];
         }   else
         {
             vv[++nv] = doing[i];
         }
         all += doing[i].tx - doing[i].fx +
                doing[i].ty - doing[i].fy;
     }
     
     for (i = 1; i <= nh; i++)
     {
         up[i] = i;
         scale[i] = 1;
     }
     
     sort(x + 1, x + nnx + 1);
     
     for (i = j = 1; i < nnx; i++)
     if  (x[i + 1] != x[j])
     {
         x[++j] = x[i + 1];
     }
     nnx = j;
     
     sort(y + 1, y + nny + 1);
     
     for (i = j = 1; i < nny; i++)
     if  (y[i + 1] != y[j])
     {
         y[++j] = y[i + 1];
     }
     nny = j;
     
     memset(last, 0, 4 * nnx + 4);
     sf = 0;
     
     for (i = 1; i <= nh; i++)
     {
         Addedges(X(hh[i].fx), i, 0);
         Addedges(X(hh[i].tx), i, 2);
     }
     for (i = 1; i <= nv; i++)
     {
         Addedges(X(vv[i].fx), i, 1);
     }
     
     Clear(1, 1, nny);
     
     vs = 0;
     stree[++vs] = ST(0, 2, make_pair(-999999999, -999999999));
     rt = &stree[vs];
     stree[++vs] = ST(rt, 1, make_pair(999999999, 999999999));
     rt -> right = &stree[vs];
     
     for (i = 1; i <= nnx; i++)
     {
         for (pointer = last[i]; pointer; pointer = mem[pointer].next)
         {
             next = mem[pointer].to;
             flag = mem[pointer].flag;
             if  (flag != 0)
             {
                 continue;
             }
             ad = Y(hh[next].fy);
             Force(1, 1, nny, ad, ad, next);
             Insert(make_pair(next, ad));
         }
         for (pointer = last[i]; pointer; pointer = mem[pointer].next)
         {
             next = mem[pointer].to;
             flag = mem[pointer].flag;
             if  (flag != 1)
             {
                 continue;
             }
             firsttime = true;
             Update(1, 1, nny, Y(vv[next].fy), Y(vv[next].ty));
         }
         for (pointer = last[i]; pointer; pointer = mem[pointer].next)
         {
             next = mem[pointer].to;
             flag = mem[pointer].flag;
             if  (flag != 2)
             {
                 continue;
             }
             rank = Findkth(make_pair(Up(next), Y(hh[next].fy)));
             Find(rank - 1, 0);
             Find(rank + 1, rt);
             rt -> right -> left = 0;
             UST(rt -> right);
             UST(rt);
         }
     }
     
     return all - result;
}

int main()
{
int nh, nv, n, i, j, fx, fy, tx, ty, total, pointer, next, flag, temp;
long long answer;
    




    
    srand((unsigned) time (0));
    
    nx = ny = nh = nv = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &fx, &fy, &tx, &ty);
        xx[++nx] = fx;
        xx[++nx] = tx;
        yy[++ny] = fy;
        yy[++ny] = ty;
        a[i] = Seg(fx, fy, tx, ty, i);
        if  (fx != tx)
        {
            h[++nh] = Seg(fx, fy, tx, ty, i);
        }   else
        {
            v[++nv] = Seg(fx, fy, tx, ty, i);
        }
    }
    
    sort(xx + 1, xx + nx + 1);
    for (i = j = 1; i < nx; i++)
    if  (xx[i + 1] != xx[j])
    {
        xx[++j] = xx[i + 1];
    }
    nx = j;
    
    sort(yy + 1, yy + ny + 1);
    for (i = j = 1; i < ny; i++)
    if  (yy[i + 1] != yy[j])
    {
        yy[++j] = yy[i + 1];
    }
    ny = j;
    
    memset(first, 0, sizeof(first));
    now = 0;
    for (i = 1; i <= nh; i++)
    {
        Addedge(Halfx(h[i].fx), h[i].number, 0);
        Addedge(Halfx(h[i].tx), h[i].number, 2);
    }
    for (i = 1; i <= nv; i++)
    {
        Addedge(Halfx(v[i].fx), v[i].number, 1);
    }
    
    for (i = 1; i <= n; i++)
    {
        father[i] = i;
    }
    memset(tree1, 0, sizeof(tree1));
    for (i = 1; i <= nx; i++)
    {
        for (pointer = first[i]; pointer; pointer = edge[pointer].next)
        {
            next = edge[pointer].to;
            flag = edge[pointer].flag;
            if  (flag != 0)
            {
                continue;
            }
            temp = Halfy(a[next].fy);
            Force1(1, 1, ny, temp, temp, next);
        }
        
        for (pointer = first[i]; pointer; pointer = edge[pointer].next)
        {
            next = edge[pointer].to;
            flag = edge[pointer].flag;
            if  (flag != 1)
            {
                continue;
            }
            Update1(1, 1, ny, Halfy(a[next].fy), Halfy(a[next].ty), next);
        }
        
        for (pointer = first[i]; pointer; pointer = edge[pointer].next)
        {
            next = edge[pointer].to;
            flag = edge[pointer].flag;
            if  (flag != 2)
            {
                continue;
            }
            temp = Halfy(a[next].fy);
            belong[next] = Ask1(1, 1, ny, temp, temp);
            Force1(1, 1, ny, temp, temp, 0);
        }
    }
    for (i = 1; i <= nv; i++)
    {
        belong[v[i].number] = Father(v[i].number);
    }
    for (i = 1; i <= n; i++)
    {
        belong[i] = Father(belong[i]);
    }
    
    memset(first, 0, sizeof(first));
    now = 0;
    for (i = 1; i <= n; i++)
    {
        Addedge(belong[i], i, 0);
    }
    answer = 0;
    for (i = 1; i <= n; i++)
    {
        total = 0;
        for (pointer = first[i]; pointer; pointer = edge[pointer].next)
        {
            next = edge[pointer].to;
            doing[++total] = a[next];
        }
        if  (total == 0)
        {
            continue;
        }
        answer = max(answer, Solve(total));
    }
    
    printf("%I64d\n", answer);
    
    return 0;
}
