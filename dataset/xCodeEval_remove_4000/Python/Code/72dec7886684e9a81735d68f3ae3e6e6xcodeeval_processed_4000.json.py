import bisect
import copy
import decimal
import fractions
import heapq
import itertools
import math
import random
import sys
from collections import Counter,deque,defaultdict
from functools import lru_cache,reduce
from heapq import heappush,heappop,heapify,heappushpop,_heappop_max,_heapify_max
def id11(heap,item):
    heap.append(item)
    heapq._siftdown_max(heap, 0, len(heap)-1)
def id17(heap, item):
    if heap and item < heap[0]:
        item, heap[0] = heap[0], item
        heapq._siftup_max(heap, 0)
    return item
from math import gcd as GCD, modf
read=sys.stdin.read
readline=sys.stdin.readline
readlines=sys.stdin.readlines

class Prime:
    def __init__(self,N):
        self.smallest_prime_factor=[None]*(N+1)
        for i in range(2,N+1,2):
            self.smallest_prime_factor[i]=2
        n=int(N**.5)+1
        for p in range(3,n,2):
            if self.smallest_prime_factor[p]==None:
                self.smallest_prime_factor[p]=p
                for i in range(p**2,N+1,2*p):
                    if self.smallest_prime_factor[i]==None:
                        self.smallest_prime_factor[i]=p
        for p in range(n,N+1):
            if self.smallest_prime_factor[p]==None:
                self.smallest_prime_factor[p]=p
        self.primes=[p for p in range(N+1) if p==self.smallest_prime_factor[p]]

    def Factorize(self,N):
        assert N>=1
        factorize=defaultdict(int)
        if N<=len(self.smallest_prime_factor)-1:
            while N!=1:
                factorize[self.smallest_prime_factor[N]]+=1
                N//=self.smallest_prime_factor[N]
        else:
            for p in self.primes:
                while N%p==0:
                    N//=p
                    factorize[p]+=1
                if N<p*p:
                    if N!=1:
                        factorize[N]+=1
                    break
                if N<=len(self.smallest_prime_factor)-1:
                    while N!=1:
                        factorize[self.smallest_prime_factor[N]]+=1
                        N//=self.smallest_prime_factor[N]
                    break
            else:
                if N!=1:
                    factorize[N]+=1
        return factorize

    def id8(self,N):
        assert N>0
        id0=[1]
        for p,e in self.Factorize(N).items():
            A=[1]
            for _ in range(e):
                A.append(A[-1]*p)
            id0=[i*j for i in id0 for j in A]

class Graph:
    def __init__(self,V,edges=False,graph=False,directed=False,weighted=False):
        self.V=V
        self.directed=directed
        self.weighted=weighted
        if not graph:
            self.edges=edges
            self.graph=[[] for i in range(self.V)]
            if weighted:
                for i,j,d in self.edges:
                    self.graph[i].append((j,d))
                    if not self.directed:
                        self.graph[j].append((i,d))
            else:
                for i,j in self.edges:
                    self.graph[i].append(j)
                    if not self.directed:
                        self.graph[j].append(i)
        else:
            self.graph=graph
            self.edges=[]
            for i in range(self.V):
                if self.weighted:
                    for j,d in self.graph[i]:
                        if self.directed or not self.directed and i<=j:
                            self.edges.append((i,j,d))
                else:
                    for j in self.graph[i]:
                        if self.directed or not self.directed and i<=j:
                            self.edges.append((i,j))

    def id2(self,s,id12=False,linked_components=False,parents=False,id24=False,weighted_dist=False):
        seen=[False]*self.V
        seen[s]=True
        if linked_components:
            lc=[s]
        if parents:
            ps=[None]*self.V
            ps[s]=s
        if id24 or id12:
            uwd=[float('inf')]*self.V
            uwd[s]=0
        if weighted_dist:
            wd=[float('inf')]*self.V
            wd[s]=0
        queue=deque([s])
        while queue:
            x=queue.popleft()
            for y in self.graph[x]:
                if self.weighted:
                    y,d=y
                if not seen[y]:
                    seen[y]=True
                    queue.append(y)
                    if linked_components:
                        lc.append(y)
                    if parents:
                        ps[y]=x
                    if id24 or id12:
                        uwd[y]=uwd[x]+1
                    if weighted_dist:
                        wd[y]=wd[x]+d
        if id12:
            bg=[[],[]]
            for tpl in self.edges:
                i,j=tpl[:2] if self.weighted else tpl
                if type(uwd[i])==float or type(uwd[j])==float:
                    continue
                if not uwd[i]%2^uwd[j]%2:
                    bg=False
                    break
            else:
                for x in range(self.V):
                    if type(uwd[x])==float:
                        continue
                    bg[uwd[x]%2].append(x)
        tpl=()
        if id12:
            tpl+=(bg,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if id24:
            tpl+=(uwd,)
        if weighted_dist:
            tpl+=(wd,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def id25(self,id12=False,linked_components=False,parents=False):
        seen=[False]*self.V
        if id12:
            bg=[None]*self.V
            cnt=-1
        if linked_components:
            lc=[]
        if parents:
            ps=[None]*self.V
        for s in range(self.V):
            if seen[s]:
                continue
            seen[s]=True
            if id12:
                cnt+=1
                bg[s]=(cnt,s&2)
            if linked_components:
                lc.append([s])
            if parents:
                ps[s]=s
            queue=deque([s])
            while queue:
                x=queue.popleft()
                for y in self.graph[x]:
                    if self.weighted:
                        y,d=y
                    if not seen[y]:
                        seen[y]=True
                        queue.append(y)
                        if id12:
                            bg[y]=(cnt,bg[x][1]^1)
                        if linked_components:
                            lc[-1].append(y)
                        if parents:
                            ps[y]=x
        if id12:
            bg_=bg
            bg=[[[],[]] for i in range(cnt+1)]
            for tpl in self.edges:
                i,j=tpl[:2] if self.weighted else tpl
                if not bg_[i][1]^bg_[j][1]:
                    bg[bg_[i][0]]=False
            for x in range(self.V):
                if bg[bg_[x][0]]:
                    bg[bg_[x][0]][bg_[x][1]].append(x)
        tpl=()
        if id12:
            tpl+=(bg,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def id6(self,s,id12=False,cycle_detection=False,id4=False,id14=False,linked_components=False,parents=False,postorder=False,preorder=False,id19=False,id5=False,id24=False,weighted_dist=False):
        seen=[False]*self.V
        finished=[False]*self.V
        if id4 or cycle_detection or id5:
            dag=True
        if id14:
            et=[]
        if linked_components:
            lc=[]
        if parents or cycle_detection or id19:
            ps=[None]*self.V
            ps[s]=s
        if postorder or id5:
            post=[]
        if preorder:
            pre=[]
        if id19:
            ss=[1]*self.V
        if id24 or id12:
            uwd=[float('inf')]*self.V
            uwd[s]=0
        if weighted_dist:
            wd=[float('inf')]*self.V
            wd[s]=0
        stack=[(s,0)] if self.weighted else [s]
        while stack:
            if self.weighted:
                x,d=stack.pop()
            else:
                x=stack.pop()
            if not seen[x]:
                seen[x]=True
                stack.append((x,d) if self.weighted else x)
                if id14:
                    et.append(x)
                if linked_components:
                    lc.append(x)
                if preorder:
                    pre.append(x)
                for y in self.graph[x]:
                    if self.weighted:
                        y,d=y
                    if not seen[y]:
                        stack.append((y,d) if self.weighted else y)
                        if parents or cycle_detection or id19:
                            ps[y]=x
                        if id24 or id12:
                            uwd[y]=uwd[x]+1
                        if weighted_dist:
                            wd[y]=wd[x]+d
                    elif not finished[y]:
                        if (id4 or cycle_detection or id5) and dag:
                            dag=False
                            if cycle_detection:
                                cd=(y,x)
            elif not finished[x]:
                finished[x]=True
                if id14:
                    et.append(~x)
                if postorder or id5:
                    post.append(x)
                if id19:
                    for y in self.graph[x]:
                        if y==ps[x]:
                            continue
                        ss[x]+=ss[y]
        if id12:
            bg=[[],[]]
            for tpl in self.edges:
                i,j=tpl[:2] if self.weighted else tpl
                if type(uwd[i])==float or type(uwd[j])==float:
                    continue
                if not uwd[i]%2^uwd[j]%2:
                    bg=False
                    break
            else:
                for x in range(self.V):
                    if type(uwd[x])==float:
                        continue
                    bg[uwd[x]%2].append(x)
        tpl=()
        if id12:
            tpl+=(bg,)
        if cycle_detection:
            if dag:
                cd=[]
            else:
                y,x=cd
                cd=self.id21(y,x,ps)
            tpl+=(cd,)
        if id4:
            tpl+=(dag,)
        if id14:
            tpl+=(et,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if postorder:
            tpl+=(post,)
        if preorder:
            tpl+=(pre,)
        if id19:
            tpl+=(ss,)
        if id5:
            if dag:
                tp_sort=post[::-1]
            else:
                tp_sort=[]
            tpl+=(tp_sort,)
        if id24:
            tpl+=(uwd,)
        if weighted_dist:
            tpl+=(wd,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def id18(self,id12=False,cycle_detection=False,id4=False,id14=False,linked_components=False,parents=False,postorder=False,preorder=False,id5=False):
        seen=[False]*self.V
        finished=[False]*self.V
        if id12:
            bg=[None]*self.V
            cnt=-1
        if id4 or cycle_detection or id5:
            dag=True
        if id14:
            et=[]
        if linked_components:
            lc=[]
        if parents or cycle_detection:
            ps=[None]*self.V
        if postorder or id5:
            post=[]
        if preorder:
            pre=[]
        for s in range(self.V):
            if seen[s]:
                continue
            if id12:
                cnt+=1
                bg[s]=(cnt,s&2)
            if linked_components:
                lc.append([])
            if parents:
                ps[s]=s
            stack=[(s,0)] if self.weighted else [s]
            while stack:
                if self.weighted:
                    x,d=stack.pop()
                else:
                    x=stack.pop()
                if not seen[x]:
                    seen[x]=True
                    stack.append((x,d) if self.weighted else x)
                    if id14:
                        et.append(x)
                    if linked_components:
                        lc[-1].append(x)
                    if preorder:
                        pre.append(x)
                    for y in self.graph[x]:
                        if self.weighted:
                            y,d=y
                        if not seen[y]:
                            stack.append((y,d) if self.weighted else y)
                            if id12:
                                bg[y]=(cnt,bg[x][1]^1)
                            if parents or cycle_detection:
                                ps[y]=x
                        elif not finished[y]:
                            if id4 and dag:
                                dag=False
                                if cycle_detection:
                                    cd=(y,x)
                elif not finished[x]:
                    finished[x]=True
                    if id14:
                        et.append(~x)
                    if postorder or id5:
                        post.append(x)
        if id12:
            bg_=bg
            bg=[[[],[]] for i in range(cnt+1)]
            for tpl in self.edges:
                i,j=tpl[:2] if self.weighted else tpl
                if not bg_[i][1]^bg_[j][1]:
                    bg[bg_[i][0]]=False
            for x in range(self.V):
                if bg[bg_[x][0]]:
                    bg[bg_[x][0]][bg_[x][1]].append(x)
        tpl=()
        if id12:
            tpl+=(bg,)
        if cycle_detection:
            if dag:
                cd=[]
            else:
                y,x=cd
                cd=self.id21(y,x,ps)
            tpl+=(cd,)
        if id4:
            tpl+=(dag,)
        if id14:
            tpl+=(et,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if postorder:
            tpl+=(post,)
        if preorder:
            tpl+=(pre,)
        if id5:
            if dag:
                tp_sort=post[::-1]
            else:
                tp_sort=[]
            tpl+=(tp_sort,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def id10(self,weighted=False):
        def id15(u):
            dist=self.id2(u,weighted_dist=True) if weighted else self.id2(u,id24=True)
            fp=0
            for i in range(self.V):
                if dist[fp]<dist[i]:
                    fp=i
            return fp,dist[fp]
        u,d=id15(0)
        v,d=id15(u)
        return u,v,d

    def SCC(self):
        reverse_graph=[[] for i in range(self.V)]
        for tpl in self.edges:
            i,j=tpl[:2] if self.weighted else tpl
            reverse_graph[j].append(i)
        postorder=self.id18(postorder=True)
        scc=[]
        seen=[False]*self.V
        for s in postorder[::-1]:
            if seen[s]:
                continue
            queue=deque([s])
            seen[s]=True
            lst=[]
            while queue:
                x=queue.popleft()
                lst.append(x)
                for y in reverse_graph[x]:
                    if self.weighted:
                        y=y[0]
                    if not seen[y]:
                        seen[y]=True
                        queue.append(y)
            scc.append(lst)
        return scc

    def id7(self,s):
        self.id14,self.parents,depth=self.id6(s,id14=True,parents=True,id24=True)
        self.dfs_in_index=[None]*self.V
        self.dfs_out_index=[None]*self.V
        for i,x in enumerate(self.id14):
            if x>=0:
                self.dfs_in_index[x]=i
            else:
                self.dfs_out_index[~x]=i
        self.ST=Segment_Tree(2*self.V,lambda x,y:min(x,y),float('inf'))
        lst=[None]*2*self.V
        for i in range(2*self.V):
            if self.id14[i]>=0:
                lst[i]=depth[self.id14[i]]
            else:
                lst[i]=depth[self.parents[~self.id14[i]]]
        self.ST.Build(lst)

    def LCA(self,a,b):
        m=min(self.dfs_in_index[a],self.dfs_in_index[b])
        M=max(self.dfs_in_index[a],self.dfs_in_index[b])
        x=self.id14[self.ST.Fold_Index(m,M+1)]
        if x>=0:
            return x
        else:
            return self.parents[~x]

    def Dijkstra(self,s,id13=False):
        dist=[float('inf')]*self.V
        dist[s]=0
        hq=[(0,s)]
        if id13:
            parents=[None]*self.V
            parents[s]=s
        while hq:
            dx,x=heapq.heappop(hq)
            if dist[x]<dx:
                continue
            for y,dy in self.graph[x]:
                if dist[y]>dx+dy:
                    dist[y]=dx+dy
                    if id13:
                        parents[y]=x
                    heapq.heappush(hq,(dist[y],y))
        if id13:
            return dist,parents
        else:
            return dist

    def id23(self,s,id13=False):
        dist=[float('inf')]*self.V
        dist[s]=0
        if id13:
            parents=[s]*self.V
        for _ in range(self.V-1):
            for i,j,d in self.edges:
                if dist[j]>dist[i]+d:
                    dist[j]=dist[i]+d
                    if id13:
                        parents[j]=i
                if not self.directed and dist[i]>dist[j]+d:
                    dist[i]=dist[j]+d
                    if id13:
                        parents[i]=j
        negative_cycle=[]
        for i,j,d in self.edges:
            if dist[j]>dist[i]+d:
                negative_cycle.append(j)
            if not self.directed and dist[i]>dist[j]+d:
                negative_cycle.append(i)
        if negative_cycle:
            id9=[False]*self.V
            for i in negative_cycle:
                if id9[i]:
                    continue
                else:
                    queue=deque([i])
                    id9[i]=True
                    while queue:
                        x=queue.popleft()
                        for y,d in self.graph[x]:
                            if not id9[y]:
                                queue.append(y)
                                id9[y]=True
                                if id13:
                                    parents[y]=x
            for i in range(self.V):
                if id9[i]:
                    dist[i]=-float('inf')
        if id13:
            return dist,parents
        else:
            return dist

    def id16(self,id13=False):
        dist=[[float('inf')]*self.V for i in range(self.V)]
        for i in range(self.V):
            dist[i][i]=0
        if id13:
            parents=[[j for j in range(self.V)] for i in range(self.V)]
        for i,j,d in self.edges:
            if dist[i][j]>d:
                dist[i][j]=d
                if id13:
                    parents[i][j]=i
            if not self.directed and dist[j][i]>d:
                dist[j][i]=d
                if id13:
                    parents[j][i]=j
        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    if dist[i][j]>dist[i][k]+dist[k][j]:
                        dist[i][j]=dist[i][k]+dist[k][j]
                        if id13:
                            parents[i][j]=parents[k][j]
        for i in range(self.V):
            if dist[i][i]<0:
                for j in range(self.V):
                    if dist[i][j]!=float('inf'):
                        dist[i][j]=-float('inf')
        if id13:
            return dist,parents
        else:
            return dist

    def id21(self,s,g,parents):
        route=[g]
        while s!=g and parents[g]!=g:
            g=parents[g]
            route.append(g)
        route=route[::-1]
        return route

    def id22(self):
        UF=UnionFind(self.V)
        sorted_edges=sorted(self.edges,key=lambda x:x[2])
        id1=[]
        for i,j,d in sorted_edges:
            if not UF.Same(i,j):
                UF.Union(i,j)
                id1.append((i,j,d))
        return id1

    def id3(self,s,t):
        max_flow=0
        id20=[defaultdict(int) for i in range(self.V)]
        if self.weighted:
            for i,j,d in self.edges:
                if not d:
                    continue
                id20[i][j]+=d
                if not self.directed:
                    id20[j][i]+=d
        else:
            for i,j in self.edges:
                id20[i][j]+=1
                if not self.directed:
                    id20[j][i]+=1
        while True:
            parents=[None]*self.V
            parents[s]=s
            seen=[False]*self.V
            seen[s]=True
            queue=deque([s])
            while queue:
                x=queue.popleft()
                for y in id20[x].keys():
                    if not seen[y]:
                        seen[y]=True
                        queue.append(y)
                        parents[y]=x
                        if y==t:
                            tt=t
                            while tt!=s:
                                id20[parents[tt]][tt]-=1
                                id20[tt][parents[tt]]+=1
                                if not id20[parents[tt]][tt]:
                                    id20[parents[tt]].pop(tt)
                                tt=parents[tt]
                            max_flow+=1
                            break
                else:
                    continue
                break
            else:
                break
        return max_flow

    def BFS(self,s):
        seen=[False]*self.V
        seen[s]=True
        queue=deque([s])

        while queue:
            x=queue.popleft()
            for y in self.graph[x]:
                if self.weighted:
                    y,d=y
                if not seen[y]:
                    seen[y]=True
                    queue.append(y)
                    
        return 

    def DFS(self,s):
        seen=[False]*self.V
        finished=[False]*self.V
        stack=[(s,0)] if self.weighted else [s]

        while stack:
            if self.weighted:
                x,d=stack.pop()
            else:
                x=stack.pop()
            if not seen[x]:
                seen[x]=True
                stack.append((x,d) if self.weighted else x)

                for y in self.graph[x]:
                    if self.weighted:
                        y,d=y
                    if not seen[y]:
                        stack.append((y,d) if self.weighted else y)
            elif not finished[x]:
                finished[x]=True
                
        return 

def id8(N):
    id0=[]
    for i in range(1,N+1):
        if i**2>=N:
            break
        elif N%i==0:
            id0.append(i)
    if i**2==N:
        id0+=[i]+[N//i for i in id0[::-1]]
    else:
        id0+=[N//i for i in id0[::-1]]
    return id0

t=int(readline())
for _ in range(t):
    N=int(readline())
    d_lst=id8(N-1)
    ans_lst=[0]*N
    mod=998244353
    edges=[]
    for _ in range(N-1):
        a,b=map(int,readline().split())
        a-=1;b-=1
        edges.append((a,b))
    G=Graph(N,edges=edges)
    parents,postorder=G.id6(0,parents=True,postorder=True)
    for d in d_lst:
        if d==1:
            continue
        lst=[0]*N
        for x in postorder[:-1]:
            if lst[x]%d==0:
                lst[parents[x]]+=1
            elif (lst[x]+1)%d==0:
                lst[x]+=1
            else:
                break
        else:
            g=0
            for c in lst:
                g=GCD(g,c)
            if g==d:
                ans_lst[d-1]+=1
                
    ans_lst[0]=(pow(2,N-1,mod)-sum(ans_lst))%mod
    print(*ans_lst)
