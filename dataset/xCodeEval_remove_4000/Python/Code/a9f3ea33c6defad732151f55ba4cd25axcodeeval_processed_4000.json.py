import sys
readline=sys.stdin.readline
import heapq
from collections import defaultdict,deque

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

    def id1(self,s,id9=False,linked_components=False,parents=False,id20=False,weighted_dist=False):
        seen=[False]*self.V
        seen[s]=True
        if linked_components:
            lc=[s]
        if parents:
            ps=[None]*self.V
            ps[s]=s
        if id20 or id9:
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
                    if id20 or id9:
                        uwd[y]=uwd[x]+1
                    if weighted_dist:
                        wd[y]=wd[x]+d
        if id9:
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
        if id9:
            tpl+=(bg,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if id20:
            tpl+=(uwd,)
        if weighted_dist:
            tpl+=(wd,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def id21(self,id9=False,linked_components=False,parents=False):
        seen=[False]*self.V
        if id9:
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
            if id9:
                cnt+=1
                bg[s]=(cnt,0)
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
                        if id9:
                            bg[y]=(cnt,bg[x][1]^1)
                        if linked_components:
                            lc[-1].append(y)
                        if parents:
                            ps[y]=x
        if id9:
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
        if id9:
            tpl+=(bg,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def id5(self,s,id9=False,cycle_detection=False,id3=False,id11=False,linked_components=False,parents=False,postorder=False,preorder=False,id15=False,id4=False,id20=False,weighted_dist=False):
        seen=[False]*self.V
        finished=[False]*self.V
        if id3 or cycle_detection or id4:
            dag=True
        if id11:
            et=[]
        if linked_components:
            lc=[]
        if parents or cycle_detection or id15:
            ps=[None]*self.V
            ps[s]=s
        if postorder or id4:
            post=[]
        if preorder:
            pre=[]
        if id15:
            ss=[1]*self.V
        if id20 or id9:
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
                if id11:
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
                        if parents or cycle_detection or id15:
                            ps[y]=x
                        if id20 or id9:
                            uwd[y]=uwd[x]+1
                        if weighted_dist:
                            wd[y]=wd[x]+d
                    elif not finished[y]:
                        if (id3 or cycle_detection or id4) and dag:
                            dag=False
                            if cycle_detection:
                                cd=(y,x)
            elif not finished[x]:
                finished[x]=True
                if id11:
                    et.append(~x)
                if postorder or id4:
                    post.append(x)
                if id15:
                    for y in self.graph[x]:
                        if y==ps[x]:
                            continue
                        ss[x]+=ss[y]
        if id9:
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
        if id9:
            tpl+=(bg,)
        if cycle_detection:
            if dag:
                cd=[]
            else:
                y,x=cd
                cd=self.id17(y,x,ps)
            tpl+=(cd,)
        if id3:
            tpl+=(dag,)
        if id11:
            tpl+=(et,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if postorder:
            tpl+=(post,)
        if preorder:
            tpl+=(pre,)
        if id15:
            tpl+=(ss,)
        if id4:
            if dag:
                tp_sort=post[::-1]
            else:
                tp_sort=[]
            tpl+=(tp_sort,)
        if id20:
            tpl+=(uwd,)
        if weighted_dist:
            tpl+=(wd,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def id14(self,id9=False,cycle_detection=False,id3=False,id11=False,linked_components=False,parents=False,postorder=False,preorder=False,id4=False):
        seen=[False]*self.V
        finished=[False]*self.V
        if id9:
            bg=[None]*self.V
            cnt=-1
        if id3 or cycle_detection or id4:
            dag=True
        if id11:
            et=[]
        if linked_components:
            lc=[]
        if parents or cycle_detection:
            ps=[None]*self.V
        if postorder or id4:
            post=[]
        if preorder:
            pre=[]
        for s in range(self.V):
            if seen[s]:
                continue
            if id9:
                cnt+=1
                bg[s]=(cnt,0)
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
                    if id11:
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
                            if id9:
                                bg[y]=(cnt,bg[x][1]^1)
                            if parents or cycle_detection:
                                ps[y]=x
                        elif not finished[y]:
                            if id3 and dag:
                                dag=False
                                if cycle_detection:
                                    cd=(y,x)
                elif not finished[x]:
                    finished[x]=True
                    if id11:
                        et.append(~x)
                    if postorder or id4:
                        post.append(x)
        if id9:
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
        if id9:
            tpl+=(bg,)
        if cycle_detection:
            if dag:
                cd=[]
            else:
                y,x=cd
                cd=self.id17(y,x,ps)
            tpl+=(cd,)
        if id3:
            tpl+=(dag,)
        if id11:
            tpl+=(et,)
        if linked_components:
            tpl+=(lc,)
        if parents:
            tpl+=(ps,)
        if postorder:
            tpl+=(post,)
        if preorder:
            tpl+=(pre,)
        if id4:
            if dag:
                tp_sort=post[::-1]
            else:
                tp_sort=[]
            tpl+=(tp_sort,)
        if len(tpl)==1:
            tpl=tpl[0]
        return tpl

    def id8(self,weighted=False):
        def id12(u):
            dist=self.id1(u,weighted_dist=True) if weighted else self.id1(u,id20=True)
            fp=0
            for i in range(self.V):
                if dist[fp]<dist[i]:
                    fp=i
            return fp,dist[fp]
        u,d=id12(0)
        v,d=id12(u)
        return u,v,d

    def SCC(self):
        reverse_graph=[[] for i in range(self.V)]
        for tpl in self.edges:
            i,j=tpl[:2] if self.weighted else tpl
            reverse_graph[j].append(i)
        postorder=self.id14(postorder=True)
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

    def id6(self,s):
        self.id11,self.parents,depth=self.id5(s,id11=True,parents=True,id20=True)
        self.dfs_in_index=[None]*self.V
        self.dfs_out_index=[None]*self.V
        for i,x in enumerate(self.id11):
            if x>=0:
                self.dfs_in_index[x]=i
            else:
                self.dfs_out_index[~x]=i
        self.ST=Segment_Tree(2*self.V,lambda x,y:min(x,y),float('inf'))
        lst=[None]*2*self.V
        for i in range(2*self.V):
            if self.id11[i]>=0:
                lst[i]=depth[self.id11[i]]
            else:
                lst[i]=depth[self.parents[~self.id11[i]]]
        self.ST.Build(lst)

    def LCA(self,a,b):
        m=min(self.dfs_in_index[a],self.dfs_in_index[b])
        M=max(self.dfs_in_index[a],self.dfs_in_index[b])
        x=self.id11[self.ST.Fold_Index(m,M+1)]
        if x>=0:
            return x
        else:
            return self.parents[~x]

    def Dijkstra(self,s,id10=False):
        dist=[float('inf')]*self.V
        dist[s]=0
        hq=[(0,s)]
        if id10:
            parents=[None]*self.V
            parents[s]=s
        while hq:
            dx,x=heapq.heappop(hq)
            if dist[x]<dx:
                continue
            for y,dy in self.graph[x]:
                if dist[y]>dx+dy:
                    dist[y]=dx+dy
                    if id10:
                        parents[y]=x
                    heapq.heappush(hq,(dist[y],y))
        if id10:
            return dist,parents
        else:
            return dist

    def id19(self,s,id10=False):
        dist=[float('inf')]*self.V
        dist[s]=0
        if id10:
            parents=[s]*self.V
        for _ in range(self.V-1):
            for i,j,d in self.edges:
                if dist[j]>dist[i]+d:
                    dist[j]=dist[i]+d
                    if id10:
                        parents[j]=i
                if not self.directed and dist[i]>dist[j]+d:
                    dist[i]=dist[j]+d
                    if id10:
                        parents[i]=j
        negative_cycle=[]
        for i,j,d in self.edges:
            if dist[j]>dist[i]+d:
                negative_cycle.append(j)
            if not self.directed and dist[i]>dist[j]+d:
                negative_cycle.append(i)
        if negative_cycle:
            id7=[False]*self.V
            for i in negative_cycle:
                if id7[i]:
                    continue
                else:
                    queue=deque([i])
                    id7[i]=True
                    while queue:
                        x=queue.popleft()
                        for y,d in self.graph[x]:
                            if not id7[y]:
                                queue.append(y)
                                id7[y]=True
                                if id10:
                                    parents[y]=x
            for i in range(self.V):
                if id7[i]:
                    dist[i]=-float('inf')
        if id10:
            return dist,parents
        else:
            return dist

    def id13(self,id10=False):
        dist=[[float('inf')]*self.V for i in range(self.V)]
        for i in range(self.V):
            dist[i][i]=0
        if id10:
            parents=[[j for j in range(self.V)] for i in range(self.V)]
        for i,j,d in self.edges:
            if dist[i][j]>d:
                dist[i][j]=d
                if id10:
                    parents[i][j]=i
            if not self.directed and dist[j][i]>d:
                dist[j][i]=d
                if id10:
                    parents[j][i]=j
        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    if dist[i][j]>dist[i][k]+dist[k][j]:
                        dist[i][j]=dist[i][k]+dist[k][j]
                        if id10:
                            parents[i][j]=parents[k][j]
        for i in range(self.V):
            if dist[i][i]<0:
                for j in range(self.V):
                    if dist[i][j]!=float('inf'):
                        dist[i][j]=-float('inf')
        if id10:
            return dist,parents
        else:
            return dist

    def id17(self,s,g,parents):
        route=[g]
        while s!=g and parents[g]!=g:
            g=parents[g]
            route.append(g)
        route=route[::-1]
        return route

    def id18(self):
        UF=UnionFind(self.V)
        sorted_edges=sorted(self.edges,key=lambda x:x[2])
        id0=[]
        for i,j,d in sorted_edges:
            if not UF.Same(i,j):
                UF.Union(i,j)
                id0.append((i,j,d))
        return id0

    def id2(self,s,t):
        max_flow=0
        id16=[defaultdict(int) for i in range(self.V)]
        if self.weighted:
            for i,j,d in self.edges:
                if not d:
                    continue
                id16[i][j]+=d
                if not self.directed:
                    id16[j][i]+=d
        else:
            for i,j in self.edges:
                id16[i][j]+=1
                if not self.directed:
                    id16[j][i]+=1
        while True:
            parents=[None]*self.V
            parents[s]=s
            seen=[False]*self.V
            seen[s]=True
            queue=deque([s])
            while queue:
                x=queue.popleft()
                for y in id16[x].keys():
                    if not seen[y]:
                        seen[y]=True
                        queue.append(y)
                        parents[y]=x
                        if y==t:
                            tt=t
                            while tt!=s:
                                id16[parents[tt]][tt]-=1
                                id16[tt][parents[tt]]+=1
                                if not id16[parents[tt]][tt]:
                                    id16[parents[tt]].pop(tt)
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

T=int(readline())
ans_lst=[]
for t in range(T):
    readline()
    N,K=map(int,readline().split())
    edges=[]
    cnt=[0]*N
    for _ in range(N-1):
        a,b=map(int,readline().split())
        a-=1;b-=1
        edges.append((a,b))
        cnt[a]+=1;cnt[b]+=1
    G=Graph(N+1,edges=edges)
    queue=deque([])
    dp=[1<<30]*N
    for i in range(N):
        if cnt[i]<=1:
            queue.append(i)
            dp[i]=0
    while queue:
        x=queue.popleft()
        if dp[x]:
            lst=[]
            for y in G.graph[x]:
                if cnt[y]:
                    lst.append(1<<30)
                else:
                    lst.append(dp[y])
            lst.sort()
            dp[x]=lst[-2]+1
        for y in G.graph[x]:
            if cnt[y]:
                cnt[x]-=1
                cnt[y]-=1
            if cnt[y]==1:
                queue.append(y)
    ans=0
    for i in range(N):
        if dp[i]>=K:
            ans+=1
    ans_lst.append(ans)
print(*ans_lst,sep="\n")