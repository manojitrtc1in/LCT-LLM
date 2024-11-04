import bisect
import copy
import decimal
import fractions
import heapq
import itertools
import math
import random
import sys
from collections import Counter, deque,defaultdict
from functools import lru_cache,reduce
from heapq import heappush,heappop,heapify,heappushpop,_heappop_max,_heapify_max
def _heappush_max(heap,item):
    heap.append(item)
    heapq._siftdown_max(heap, 0, len(heap)-1)
def _heappushpop_max(heap, item):
    if heap and item < heap[0]:
        item, heap[0] = heap[0], item
        heapq._siftup_max(heap, 0)
    return item
from math import gcd as GCD
read=sys.stdin.read
readline=sys.stdin.readline
readlines=sys.stdin.readlines

def Extended_Euclid(n,m):
    stack=[]
    while m:
        stack.append((n,m))
        n,m=m,n%m
    if n>=0:
        x,y=1,0
    else:
        x,y=-1,0
    for i in range(len(stack)-1,-1,-1):
        n,m=stack[i]
        x,y=y,x-(n//m)*y
    return x,y

class MOD:
    def __init__(self,mod):
        self.mod=mod
    
    def Pow(self,a,n):
        a%=self.mod
        if n>=0:
            return pow(a,n,self.mod)
        else:
            assert math.gcd(a,self.mod)==1
            x=Extended_Euclid(a,self.mod)[0]
            return pow(x,-n,self.mod)

    def Build_Fact(self,N):
        assert N>=0
        self.factorial=[1]
        for i in range(1,N+1):
            self.factorial.append((self.factorial[-1]*i)%self.mod)
        self.factorial_inv=[None]*(N+1)
        self.factorial_inv[-1]=self.Pow(self.factorial[-1],-1)
        for i in range(N-1,-1,-1):
            self.factorial_inv[i]=(self.factorial_inv[i+1]*(i+1))%self.mod
        return self.factorial_inv

    def Fact(self,N):
        return self.factorial[N]

    def Fact_Inv(self,N):
        return self.factorial_inv[N]

    def Comb(self,N,K):
        if K<0 or K>N:
            return 0
        s=self.factorial[N]
        s=(s*self.factorial_inv[K])%self.mod
        s=(s*self.factorial_inv[N-K])%self.mod
        return s
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

    def SS_BFS(self,s,bipartite_graph=False,linked_components=False,parents=False,unweighted_dist=False,weighted_dist=False):
        seen=[False]*self.V
        seen[s]=True
        if linked_components:
            lc=[s]
        if parents:
            ps=[None]*self.V
            ps[s]=s
        if unweighted_dist or bipartite_graph:
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
                    if unweighted_dist or bipartite_graph:
                        uwd[y]=uwd[x]+1
                    if weighted_dist:
                        wd[y]=wd[x]+d
        if bipartite_graph:
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
        if bipartite_graph:
            tpl+=(bg,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if unweighted_dist:
            tpl+=(uwd,)
        if weighted_dist:
            tpl+=(wd,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def AP_BFS(self,bipartite_graph=False,linked_components=False,parents=False):
        seen=[False]*self.V
        if bipartite_graph:
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
            if bipartite_graph:
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
                        if bipartite_graph:
                            bg[y]=(cnt,bg[x][1]^1)
                        if linked_components:
                            lc[-1].append(y)
                        if parents:
                            ps[y]=x
        if bipartite_graph:
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
        if bipartite_graph:
            tpl+=(bg,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def SS_DFS(self,s,bipartite_graph=False,cycle_detection=False,directed_acyclic=False,euler_tour=False,linked_components=False,parents=False,postorder=False,preorder=False,topological_sort=False,unweighted_dist=False,weighted_dist=False):
        seen=[False]*self.V
        finished=[False]*self.V
        if directed_acyclic or cycle_detection or topological_sort:
            dag=True
        if euler_tour:
            et=[]
        if linked_components:
            lc=[]
        if parents or cycle_detection:
            ps=[None]*self.V
            ps[s]=s
        if postorder or topological_sort:
            post=[]
        if preorder:
            pre=[]
        if unweighted_dist or bipartite_graph:
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
                if euler_tour:
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
                        if parents or cycle_detection:
                            ps[y]=x
                        if unweighted_dist or bipartite_graph:
                            uwd[y]=uwd[x]+1
                        if weighted_dist:
                            wd[y]=wd[x]+d
                    elif not finished[y]:
                        if (directed_acyclic or cycle_detection or topological_sort) and dag:
                            dag=False
                            if cycle_detection:
                                cd=(y,x)
            elif not finished[x]:
                finished[x]=True
                if euler_tour:
                    et.append(~x)
                if postorder or topological_sort:
                    post.append(x)
        if bipartite_graph:
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
        if bipartite_graph:
            tpl+=(bg,)
        if cycle_detection:
            if dag:
                cd=[]
            else:
                y,x=cd
                cd=self.Route_Restoration(y,x,ps)
            tpl+=(cd,)
        if directed_acyclic:
            tpl+=(dag,)
        if euler_tour:
            tpl+=(et,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if postorder:
            tpl+=(post,)
        if preorder:
            tpl+=(pre,)
        if topological_sort:
            if dag:
                tp_sort=post[::-1]
            else:
                tp_sort=[]
            tpl+=(tp_sort,)
        if unweighted_dist:
            tpl+=(uwd,)
        if weighted_dist:
            tpl+=(wd,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def AP_DFS(self,bipartite_graph=False,cycle_detection=False,directed_acyclic=False,euler_tour=False,linked_components=False,parents=False,postorder=False,preorder=False,topological_sort=False):
        seen=[False]*self.V
        finished=[False]*self.V
        if bipartite_graph:
            bg=[None]*self.V
            cnt=-1
        if directed_acyclic or cycle_detection or topological_sort:
            dag=True
        if euler_tour:
            et=[]
        if linked_components:
            lc=[]
        if parents or cycle_detection:
            ps=[None]*self.V
        if postorder or topological_sort:
            post=[]
        if preorder:
            pre=[]
        for s in range(self.V):
            if seen[s]:
                continue
            if bipartite_graph:
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
                    if euler_tour:
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
                            if bipartite_graph:
                                bg[y]=(cnt,bg[x][1]^1)
                            if parents or cycle_detection:
                                ps[y]=x
                        elif not finished[y]:
                            if directed_acyclic and dag:
                                dag=False
                                if cycle_detection:
                                    cd=(y,x)
                elif not finished[x]:
                    finished[x]=True
                    if euler_tour:
                        et.append(~x)
                    if postorder or topological_sort:
                        post.append(x)
        if bipartite_graph:
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
        if bipartite_graph:
            tpl+=(bg,)
        if cycle_detection:
            if dag:
                cd=[]
            else:
                y,x=cd
                cd=self.Route_Restoration(y,x,ps)
            tpl+=(cd,)
        if directed_acyclic:
            tpl+=(dag,)
        if euler_tour:
            tpl+=(et,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if postorder:
            tpl+=(post,)
        if preorder:
            tpl+=(pre,)
        if topological_sort:
            if dag:
                tp_sort=post[::-1]
            else:
                tp_sort=[]
            tpl+=(tp_sort,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def Tree_Diameter(self,weighted=False):
        def Farthest_Point(u):
            dist=self.SS_BFS(u,weighted_dist=True) if self.weighted else self.SS_BFS(u,unweighted_dist=True)
            fp=0
            for i in range(self.V):
                if dist[fp]<dist[i]:
                    fp=i
            return fp,dist[fp]
        u,d=Farthest_Point(0)
        v,d=Farthest_Point(u)
        return u,v,d

    def SCC(self):
        reverse_graph=[[] for i in range(self.V)]
        for tpl in self.edges:
            i,j=tpl[:2] if self.weighted else tpl
            reverse_graph[j].append(i)
        postorder=self.AP_DFS(postorder=True)
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

    def Build_LCA(self,s):
        self.euler_tour,self.parents,depth=self.SS_DFS(s,euler_tour=True,parents=True,unweighted_dist=True)
        self.dfs_in_index=[None]*self.V
        self.dfs_out_index=[None]*self.V
        for i,x in enumerate(self.euler_tour):
            if x>=0:
                self.dfs_in_index[x]=i
            else:
                self.dfs_out_index[~x]=i
        self.ST=Segment_Tree(2*self.V,lambda x,y:min(x,y),float('inf'))
        lst=[None]*2*self.V
        for i in range(2*self.V):
            if self.euler_tour[i]>=0:
                lst[i]=depth[self.euler_tour[i]]
            else:
                lst[i]=depth[self.parents[~self.euler_tour[i]]]
        self.ST.Build(lst)

    def LCA(self,a,b):
        m=min(self.dfs_in_index[a],self.dfs_in_index[b])
        M=max(self.dfs_in_index[a],self.dfs_in_index[b])
        x=self.euler_tour[self.ST.Fold_Index(m,M+1)]
        if x>=0:
            return x
        else:
            return self.parents[~x]

    def Dijkstra(self,s,route_restoration=False):
        dist=[float('inf')]*self.V
        dist[s]=0
        hq=[(0,s)]
        if route_restoration:
            parents=[None]*self.V
            parents[s]=s
        while hq:
            dx,x=heapq.heappop(hq)
            if dist[x]<dx:
                continue
            for y,dy in self.graph[x]:
                if dist[y]>dx+dy:
                    dist[y]=dx+dy
                    if route_restoration:
                        parents[y]=x
                    heapq.heappush(hq,(dist[y],y))
        if route_restoration:
            return dist,parents
        else:
            return dist

    def Bellman_Ford(self,s,route_restoration=False):
        dist=[float('inf')]*self.V
        dist[s]=0
        if route_restoration:
            parents=[s]*self.V
        for _ in range(self.V-1):
            for i,j,d in self.edges:
                if dist[j]>dist[i]+d:
                    dist[j]=dist[i]+d
                    if route_restoration:
                        parents[j]=i
                if not self.directed and dist[i]>dist[j]+d:
                    dist[i]=dist[j]+d
                    if route_restoration:
                        parents[i]=j
        negative_cycle=[]
        for i,j,d in self.edges:
            if dist[j]>dist[i]+d:
                negative_cycle.append(j)
            if not self.directed and dist[i]>dist[j]+d:
                negative_cycle.append(i)
        if negative_cycle:
            is_negative_cycle=[False]*self.V
            for i in negative_cycle:
                if is_negative_cycle[i]:
                    continue
                else:
                    queue=deque([i])
                    is_negative_cycle[i]=True
                    while queue:
                        x=queue.popleft()
                        for y,d in self.graph[x]:
                            if not is_negative_cycle[y]:
                                queue.append(y)
                                is_negative_cycle[y]=True
                                if route_restoration:
                                    parents[y]=x
            for i in range(self.V):
                if is_negative_cycle[i]:
                    dist[i]=-float('inf')
        if route_restoration:
            return dist,parents
        else:
            return dist

    def Warshall_Floyd(self,route_restoration=False):
        dist=[[float('inf')]*self.V for i in range(self.V)]
        for i in range(self.V):
            dist[i][i]=0
        if route_restoration:
            parents=[[j for j in range(self.V)] for i in range(self.V)]
        for i,j,d in self.edges:
            if dist[i][j]>d:
                dist[i][j]=d
                if route_restoration:
                    parents[i][j]=i
            if not self.directed and dist[j][i]>d:
                dist[j][i]=d
                if route_restoration:
                    parents[j][i]=j
        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    if dist[i][j]>dist[i][k]+dist[k][j]:
                        dist[i][j]=dist[i][k]+dist[k][j]
                        if route_restoration:
                            parents[i][j]=parents[k][j]
        for i in range(self.V):
            if dist[i][i]<0:
                for j in range(self.V):
                    if dist[i][j]!=float('inf'):
                        dist[i][j]=-float('inf')
        if route_restoration:
            return dist,parents
        else:
            return dist

    def Route_Restoration(self,s,g,parents):
        route=[g]
        while s!=g and parents[g]!=g:
            g=parents[g]
            route.append(g)
        route=route[::-1]
        return route

    def Kruskal(self):
        UF=UnionFind(self.V)
        sorted_edges=sorted(self.edges,key=lambda x:x[2])
        minimum_spnning_tree=[]
        for i,j,d in sorted_edges:
            if not UF.Same(i,j):
                UF.Union(i,j)
                minimum_spnning_tree.append((i,j,d))
        return minimum_spnning_tree

    def Ford_Fulkerson(self,s,t):
        max_flow=0
        residual_graph=[defaultdict(int) for i in range(self.V)]
        if self.weighted:
            for i,j,d in self.edges:
                if not d:
                    continue
                residual_graph[i][j]+=d
                if not self.directed:
                    residual_graph[j][i]+=d
        else:
            for i,j in self.edges:
                residual_graph[i][j]+=1
                if not self.directed:
                    residual_graph[j][i]+=1
        while True:
            parents=[None]*self.V
            parents[s]=s
            seen=[False]*self.V
            seen[s]=True
            queue=deque([s])
            while queue:
                x=queue.popleft()
                for y in residual_graph[x].keys():
                    if not seen[y]:
                        seen[y]=True
                        queue.append(y)
                        parents[y]=x
                        if y==t:
                            tt=t
                            while tt!=s:
                                residual_graph[parents[tt]][tt]-=1
                                residual_graph[tt][parents[tt]]+=1
                                if not residual_graph[parents[tt]][tt]:
                                    residual_graph[parents[tt]].pop(tt)
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

class Segment_Tree:
    def __init__(self,N,f,e,lst=None):
        self.f=f
        self.e=e
        self.N=N
        if lst==None:
            self.segment_tree=[self.e]*2*self.N
        else:
            assert len(lst)<=self.N
            self.segment_tree=[self.e]*self.N+[x for x in lst]+[self.e]*(N-len(lst))
            for i in range(self.N-1,0,-1):
                self.segment_tree[i]=self.f(self.segment_tree[i<<1],self.segment_tree[i<<1|1])

    def __getitem__(self,i):
        if type(i)==int:
            if -self.N<=i<0:
                return self.segment_tree[i+self.N*2]
            elif 0<=i<self.N:
                return self.segment_tree[i+self.N]
            else:
                raise IndexError('list index out of range')
        else:
            a,b,c=i.start,i.stop,i.step
            if a==None or a<-self.N:
                a=self.N
            elif self.N<=a:
                a=self.N*2
            elif a<0:
                a+=self.N*2
            else:
                a+=self.N
            if b==None or self.N<=b:
                b=self.N*2
            elif b<-self.N:
                b=self.N
            elif b<0:
                b+=self.N*2
            else:
                b+=self.N
            return self.segment_tree[slice(a,b,c)]
    
    def __setitem__(self,i,x):
        if -self.N<=i<0:
            i+=self.N*2
        elif 0<=i<self.N:
            i+=self.N
        else:
            raise IndexError('list index out of range')
        self.segment_tree[i]=x
        while i>1:
            i>>= 1
            self.segment_tree[i]=self.f(self.segment_tree[i<<1],self.segment_tree[i<<1|1])
    
    def Build(self,lst):
        for i,x in enumerate(lst,self.N):
            self.segment_tree[i]=x
        for i in range(self.N-1,0,-1):
            self.segment_tree[i]=self.f(self.segment_tree[i<<1],self.segment_tree[i<<1|1])

    def Fold(self,L=None,R=None):
        if L==None or L<-self.N:
            L=self.N
        elif self.N<=L:
            L=self.N*2
        elif L<0:
            L+=self.N*2
        else:
            L+=self.N
        if R==None or self.N<=R:
            R=self.N*2
        elif R<-self.N:
            R=self.N
        elif R<0:
            R+=self.N*2
        else:
            R+=self.N
        vL=self.e
        vR=self.e
        while L<R:
            if L&1:
                vL=self.f(vL,self.segment_tree[L])
                L+=1
            if R&1:
                R-=1
                vR=self.f(self.segment_tree[R],vR)
            L>>=1
            R>>=1
        return self.f(vL,vR)

    def Fold_Index(self,L=None,R=None):
        if L==None or L<-self.N:
            L=self.N
        elif self.N<=L:
            L=self.N*2
        elif L<0:
            L+=self.N*2
        else:
            L+=self.N
        if R==None or self.N<=R:
            R=self.N*2
        elif R<-self.N:
            R=self.N
        elif R<0:
            R+=self.N*2
        else:
            R+=self.N
        if L==R:
            return None
        x=self.Fold(L-self.N,R-self.N)
        while L<R:
            if L&1:
                if self.segment_tree[L]==x:
                    i=L
                    break
                L+=1
            if R&1:
                R-=1
                if self.segment_tree[R]==x:
                    i=R
                    break
            L>>=1
            R>>=1
        while i<self.N:
            if self.segment_tree[i]==self.segment_tree[i<<1]:
                i<<=1
            else:
                i<<=1
                i|=1
        i-=self.N
        return i

    def __str__(self):
        return '['+', '.join(map(str,self.segment_tree[self.N:]))+']'

N=int(readline())
mod=10**9+7
edges=[]
ans=0
for _ in range(N-1):
    x,y=map(int,readline().split())
    x-=1;y-=1
    edges.append((x,y))
G=Graph(N,edges=edges)
MD=MOD(mod=mod)
MD.Build_Fact(1000)

pow_lst=[1]
for _ in range(1000):
    pow_lst.append(pow_lst[-1]*500000004%mod)

@lru_cache(maxsize=None)
def f(a,b):
    if a:
        return (f(a-1,b)+pow_lst[b+a-1]*MD.Comb(b-2+a,a-1))%mod
    return 0
for z in range(N):
    parents,postorder,depth=G.SS_DFS(z,parents=True,postorder=True,unweighted_dist=True)
    children=[[r] for r in range(N)]
    for r in postorder:
        for x in G.graph[r]:
            if x==parents[r]:
                continue
            for y in children[x]:
                children[r].append(y)
        for x in children[r]:
            if r>x:
                ans+=1
        for x in G.graph[r]:
            if x==parents[r]:
                continue
            for y in G.graph[r]:
                if y==parents[r]:
                    continue
                if x!=y:
                    for xx in children[x]:
                        for yy in children[y]:
                            if xx<yy:
                                a,b=depth[xx]-depth[r],depth[yy]-depth[r]
                                ans+=f(a,b)
                                ans%=mod
ans*=MD.Pow(N,-1)
ans%=mod
print(ans)