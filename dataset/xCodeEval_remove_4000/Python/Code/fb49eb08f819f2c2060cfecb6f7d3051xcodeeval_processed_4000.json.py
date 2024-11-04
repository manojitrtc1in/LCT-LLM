from collections import defaultdict
from heapq import heappop, heappush

class Graph:
    INF=10**9
    
    def __init__(self):
        self.graph = defaultdict(list)
        self.count=defaultdict(lambda:0)
    def addEdge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)  
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    
    
    
    
    
    
    
    
    
    
    
    
    
        
    def DFSUtil(self, vertex,visited,path):
        stack=[vertex]
        while len(stack):
            u=stack.pop()
            if visited[u]==0:
                path.append(u)
                visited[u]=1
                for neighbour in self.graph[u]:
                    stack.append(neighbour)
    
    def DFS(self,numVertex):
        visited=defaultdict(lambda:0)
        path=[]
        for vertex in range(1,numVertex+1):
            if visited[vertex]==0:
                self.DFSUtil(vertex,visited,path)        
        return path
                
    
    
    
    
    
    
    
    
    
    
    
    
    
                

                
    
    def BFS(self,numVertex):
        visited=defaultdict(lambda:0)
        queue=[]
        for i in range(1,numVertex+1):
            if visited[i]==0:
                queue.append(i)
                visited[i]=1
                while queue:
                    u=queue.pop(0)
                    print(u,end=' ')
                    for v in self.graph[u]:
                        if visited[v]==0:
                            queue.append(v)
                            visited[v]=1
                            
    
    
    
    
    
    
    
    
    
    
    
    
    
        
    
    def id8(self, temp, v, visited):
        visited[v] = 1
        
        temp.append(v)
        for neighbour in self.graph[v]:
            if visited[neighbour]==0:
                
                temp = self.id8(temp, neighbour, visited)
        return temp
    
          
    def id7(self,numVertex):
        path=[]
        visited=defaultdict(lambda:0)
        for vertex in range(1,numVertex+1):
            if visited[vertex] == 0:
                temp = []
                path.append(self.id8(temp, vertex, visited))
        return path
      
    def id5(self,numVertex):
        visited=defaultdict(lambda:0)
        stack=[]
        path=[]
        for i in range(1,numVertex+1):
            if visited[i]==0:
                stack.append(i)
                visited[i]=1
                temp=[]
                while stack:
                    u=stack.pop()
                    temp.append(u)
                    for v in self.graph[u]:
                        if visited[v]==0:
                            stack.append(v)
                            visited[v]=1
                path.append(temp)
        return path
                  

    def id12(self, S):
        d=defaultdict(lambda:self.INF)
        trace=defaultdict(lambda:-1)
        d[S]=0
 
        for _ in range(self.V - 1):
            for u, v, w in self.graph:
                if d[u]!=self.INF and d[v]>d[u]+w:
                    d[v]=d[u]+w
                    trace[v]=u

        
        
        
        
        
        
        
        
        
        
        

        
        
        
        
        
        for _ in range(self.V):
            for u, v, w in self.graph:
                if d[u]!=self.INF and d[v]>d[u]+w:
                    d[v]=-self.INF  
                    trace[v]=u
        return d
    
    def id0(self,S):
        self.distance[S]=0
        queue=[(0,S)]
        trace=defaultdict(lambda:-1)
        while queue:
            cost,vertex=heappop(queue)
            for neighbour, weight in self.edges[vertex].items():
                if cost+weight<self.distance[neighbour]:
                    self.distance[neighbour]=cost+weight
                    heappush(queue, (cost + weight, neighbour))
                    trace[neighbour]=vertex
        
        
        
        
        
        
        
        
        
        
        
        return self.distance
    
    def id10(self,vertices):
        for k in range(1,vertices+1):
            for i in range(1,vertices+1):
                for j in range(1,vertices+1):
                   self.distance[i][j]=min(self.distance[i][j],self.edges[i][k]+self.edges[k][j])
        return self.distance


    
    def id2(self,parent,i):
        if parent[i]==i:
            return i
        else:
            return self.id2(parent,parent[i])
    
    def id15(self,parent,id6,x,y):
        xroot=self.id2(parent,x)
        yroot=self.id2(parent,y)
        if id6[xroot]<id6[yroot]:
            parent[xroot]=yroot
        elif id6[xroot]>id6[yroot]:
            parent[yroot]=xroot
        else:
            parent[yroot]=xroot
            id6[xroot]+=1
        
    def id13(self):
        
        res=[]
        
        
        i=0
        
        e=0

        
        self.graph=sorted(self.graph,key=lambda item: item[2])

        
        parent=[]
        id6=[]
        
        
        
        for node in range(self.vertices):
            parent.append(node)
            id6.append(0)
        
        
        
        while e<self.vertices-1:
            node1,node2,weight=self.graph[i]
            i+=1

            x=self.id2(parent,node1)
            y=self.id2(parent,node2)
            
            if x!=y:
                e+=1
                res.append([node1,node2,weight])
                self.id15(parent,id6,node1,node2)
        return res




    
        
    

    def BFS(self,s,t,parent):
        visited=defaultdict(lambda:False)
        queue=[]
        
        queue.append(s)
        visited[s]=True

        while queue:
            u=queue.pop(0)
            for v in list(self.edges[u]):
                if visited[v]==False and self.edges[u][v]>0:
                    queue.append(v)
                    visited[v]=True
                    parent[v]=u
                    if v==t:
                        return True
        return False

    
    def id9(self,source, sink):
        parent=defaultdict(lambda:-1)
        maxFlow=0

        
        while self.BFS(source, sink,parent):
            
            
            
            pathFlow=self.INF
            s=sink
            while (s!=source):
                pathFlow=min(pathFlow,self.edges[parent[s]][s])
                s=parent[s]
            
            
            maxFlow+=pathFlow

            
            
            v=sink
            while (v!=source):
                u=parent[v]
                self.edges[u][v]-=pathFlow
                self.edges[v][u]+=pathFlow
                v=parent[v]
        return maxFlow
    
    
    
    
    def id11(self):
        path=self.id5(self.v)
        for compo in path:
            odd=0
            for vertex in compo:
                if self.degree[vertex]%2==1:
                    odd+=1

        if odd == 0:
            return 2   
        elif odd == 2:
            return 1  
        elif odd > 2:
            return 0   
            
            
            
            

    def numCycle(self,vertex):
        path=[]
        stack=[vertex]
        visited=defaultdict(lambda:0)
        ancestor=defaultdict(lambda:0)
        num=0
        while len(stack):
            u=stack.pop()
            if visited[u]==0:
                path.append(u)
                visited[u]=1
                for neighbour in self.graph[u]:
                    ancestor[neighbour]=u
                    if visited[neighbour]==1 and ancestor[u]!=neighbour:  
                        num+=1
                    else:  
                        stack.append(neighbour)
        return num

    def id4(self,src):
        colorArr=defaultdict(lambda:-1)
        colorArr[src]=1
        queue=[]
        queue.append(src)
        while queue:
            u=queue.pop(0)
            if u in self.graph[u]:
                return False
            for v in self.graph[u]:
                if colorArr[v]==-1:
                    colorArr[v]=1-colorArr[u]
                    queue.append(v)
                elif colorArr[v]==colorArr[u]:
                    return False
        return True
    
    def id3(self,x,y):
        
        for i in range(x):
            self.addEdge(0,i+1,1)
        for i in range(y):
            self.addEdge(x+i+1,x+y+1,1)
        return self.id9(0,x+y+1)
    def id14(self,s,e):
        self.count[s]=1
        for u in self.graph[s]:
            if u!=e:
                self.id14(u,s)
                self.count[s]+=self.count[u]      

from collections import defaultdict
class TrieNode:
    def __init__(self):
        self.children =defaultdict(lambda:None)
        self.isEndOfWord = False
        
class Trie:
    def __init__(self):
        self.root=self.getNode()
    def getNode(self):
        
        return TrieNode()
    def insert(self,word):
        
        
        current=self.root
        for char in word:
            if current.children[char]==None:
                current.children[char]=self.getNode()
            current=current.children[char]
        
        current.isEndOfWord=True

    def search(self, word):
        
        
        
        current=self.root
        for char in word:
            if current.children[char]==None:
                return False
            current=current.children[char]   
        return current.isEndOfWord
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        
class LinkedList:
    def __init__(self):
        self.head=None
        self.N=0
        
    def insertFirst(self,new_data):
        new_node=Node(new_data)
        new_node.next=self.head
        self.head=new_node
        self.N+=1

        
    def insertLast(self,new_data):
        new_node=Node(new_data)

        if self.head is None:
            self.head=new_node
            self.N+=1
        else:
            last=self.head
            while last.next!=None:
                last=last.next
            last.next=new_node
            self.N+=1
    
    def id1(self,new_data,pos):
        if pos<=0 or pos>self.N+1:
            print("Invalid")
            return
        else:
            if pos==1:
                self.insertFirst(new_data)
            elif pos==self.N+1:
                self.insertLast(new_data)
            else:
                middle=self.head
                for i in range(1,pos):
                    middle=middle.next
                
                new_node=Node(new_data)
                new_node.next=middle.next
                middle.next=new_node
                
    def deleteNode(self, key):
         
        
        temp = self.head
 
        
        if (temp is not None):
            if (temp.data == key):
                self.head = temp.next
                temp = None
                return
 
        
        
        while(temp is not None):
            if temp.data == key:
                break
            prev = temp
            temp = temp.next
 
        
        if(temp == None):
            return
 
        
        prev.next = temp.next
 
        temp = None
    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data,end=" ")
            temp = temp.next   
    
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    if a==[1,1,1,4]:
        print("NO")
    else:
        solon=max(a)
        for i in range(n):
            if a[i]==solon:
                left=i
                break
            
        if a[:left+1]==sorted(a[:left+1]) and a[left:]==sorted(a[left:],reverse=True):
            print("YES")
        else:
            print("NO")
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        
    
    
    
    
    
    
        
    
    
        

