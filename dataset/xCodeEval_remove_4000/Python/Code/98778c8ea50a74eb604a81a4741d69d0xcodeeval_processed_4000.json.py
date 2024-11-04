from queue import PriorityQueue
from collections import deque,OrderedDict,defaultdict,Counter
from heapq import heappop, heappush, heapify
import sys
import time
import os
from io import BytesIO, IOBase
import math
from random import randint
from itertools import compress


MOD=10**9+7
id21 = 8192
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id21))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id21))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
def print(*args, **kwargs):
    
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()
 
 
if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
def inputf(): 
    return sys.stdin.readline().rstrip("\r\n")  
 

 
def id18(): 
    return list(map(int, inputf().split()))
 
 
def get_string(): 
    return list(map(str, inputf().split()))





global maximum
 
 
def _lis(arr, n):
 
    global maximum
 
    if n == 1:
        return 1
 
    id8 = 1
 
    
    for i in range(1, n):
        res = _lis(arr, i)
        if arr[i-1] < arr[n-1] and res+1 > id8:
            id8 = res + 1

    maximum = max(maximum, id8)
 
    return id8
 
 
def LIS(arr):
 
    global maximum
 
    n = len(arr)

    maximum = 1
 

    _lis(arr, n)
 
    return maximum
 

def binary_search(data, elem):
    
    low = 0
    high = len(data) - 1
    while low <= high:
      
        middle = (low + high)//2
        if data[middle] == elem:
            return middle
            
        elif data[middle] > elem:

            high = middle - 1
        else:
            low = middle + 1

    return middle   

def upper_bound(my_list, key):
    large = len(my_list) -1
    small = 0

    while (small <= large):
        mid = (small + large) // 2
        if my_list[mid] < key:  
            small = mid + 1
        elif my_list[mid] > key:  
            large = mid - 1
        else:
            return mid
    if my_list[mid]>key:
        return mid
    else:
        return mid+1   
    



def lower_bound(my_list, key):
    large = len(my_list) -1
    small = 0

    while (small <= large):
        mid = (small + large) // 2
        if my_list[mid] < key:
            small = mid + 1
        elif my_list[mid] > key:
            large = mid - 1
        else:
            return mid
    if my_list[mid]<key:
        return mid
    else:
        return mid-1




def id14(n):
    
    sieve = bytearray([True]) * (n//2)
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = bytearray((n-i*i-1)//(2*i)+1)
    return [2,*compress(range(3,n,2), sieve[1:])]

def id2(n):
    
    sieve = bytearray([True]) * (n//2+1)
    for i in range(1,int(n**0.5)//2+1):
        if sieve[i]:
            sieve[2*i*(i+1)::2*i+1] = bytearray((n//2-2*i*(i+1))//(2*i+1)+1)
    return [2,*compress(range(3,n,2), sieve[1:])]

def roman_number(x):
    if x > 15999:
        return
    value = [5000, 4000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    symbol = ["F", "MF", "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    roman = ""
    i = 0
    while x > 0:
        div = x // value[i]
        x = x % value[i]
        while div:
            roman += symbol[i]
            div -= 1
        i += 1
    return roman

def id5(a,size):
     
    id11 = a[0]   
    id7 = 0
     
    for i in range(0, size):
        id7 = id7 + a[i]
        if id7 < 0:
            id7 = 0

        elif (id11 < id7):   
            id11 = id7
             
    return id11

    


def lcm(x, y):

   if x > y:
       greater = x
   else:
       greater = y

   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1

   return lcm

def primeFactors(n):
    a=[]
    while n % 2 == 0:
        a.append(2)
        n = n / 2
         
    for i in range(3,int(math.sqrt(n))+1,2):
         
        while n % i== 0:
            a.append(i)
            n = n / i
             
    if n > 2:
        a.append(n)
         

def findClosest(arr, n, target):
 
    if (target <= arr[0]):
        return arr[0]
    if (target >= arr[n - 1]):
        return arr[n - 1]
 
    i = 0; j = n; mid = 0
    while (i < j):
        mid = (i + j) // 2
 
        if (arr[mid] == target):
            return arr[mid]
 
        if (target < arr[mid]) :
 
            if (mid > 0 and target > arr[mid - 1]):
                return getClosest(arr[mid - 1], arr[mid], target)
 
            j = mid
         
        else :
            if (mid < n - 1 and target < arr[mid + 1]):
                return getClosest(arr[mid], arr[mid + 1], target)
                 
            i = mid + 1
         
    return arr[mid]
 

def getClosest(val1, val2, target):
 
    if (target - val1 >= val2 - target):
        return val2
    else:
        return val1

import random
 
def id4(n):
    
    if n!=int(n):
        return False
    n=int(n)
    if n==0 or n==1 or n==4 or n==6 or n==8 or n==9:
        return False
 
    if n==2 or n==3 or n==5 or n==7:
        return True
    s = 0
    d = n-1
    while d%2==0:
        d>>=1
        s+=1
    assert(2**s * d == n-1)
 
    def id1(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True  
 
    for i in range(8):
        a = random.randrange(2, n)
        if id1(a):
            return False
 
    return True  

def LCS(s1 , s2):
    m, n = len(s1), len(s2)
    prev, cur = [0]*(n+1), [0]*(n+1)
    for i in range(1, m+1):
        for j in range(1, n+1):
            if s1[i-1] == s2[j-1]:
                cur[j] = 1 + prev[j-1]
            else:
                if cur[j-1] > prev[j]:
                    cur[j] = cur[j-1]
                else:
                    cur[j] = prev[j]
        cur, prev = prev, cur
    return prev[n]

fib_matrix = [[1,1],
              [1,0]]

def matrix_square(A, mod):
    return mat_mult(A,A,mod)


def mat_mult(A,B, mod):
  if mod is not None:
    return [[(A[0][0]*B[0][0] + A[0][1]*B[1][0])%mod, (A[0][0]*B[0][1] + A[0][1]*B[1][1])%mod],
            [(A[1][0]*B[0][0] + A[1][1]*B[1][0])%mod, (A[1][0]*B[0][1] + A[1][1]*B[1][1])%mod]]


def matrix_pow(M, power, mod):
    if power <= 0:
      return M

    powers =  list(reversed([True if i=="1" else False for i in bin(power)[2:]])) 

    matrices = [None for _ in powers]
    matrices[0] = M

    for i in range(1,len(powers)):
        matrices[i] = matrix_square(matrices[i-1], mod)


    result = None

    for matrix, power in zip(matrices, powers):
        if power:
            if result is None:
                result = matrix
            else:
                result = mat_mult(result, matrix, mod)

    return result



def multiply(T, M):
     
    a = (T[0][0] * M[0][0] + T[0][1] *
         M[1][0] + T[0][2] * M[2][0])            
    b = (T[0][0] * M[0][1] + T[0][1] *
         M[1][1] + T[0][2] * M[2][1])
    c = (T[0][0] * M[0][2] + T[0][1] *
         M[1][2] + T[0][2] * M[2][2])
    d = (T[1][0] * M[0][0] + T[1][1] *
         M[1][0] + T[1][2] * M[2][0])
    e = (T[1][0] * M[0][1] + T[1][1] *
         M[1][1] + T[1][2] * M[2][1])
    f = (T[1][0] * M[0][2] + T[1][1] *
         M[1][2] + T[1][2] * M[2][2])
    g = (T[2][0] * M[0][0] + T[2][1] *
         M[1][0] + T[2][2] * M[2][0])
    h = (T[2][0] * M[0][1] + T[2][1] *
         M[1][1] + T[2][2] * M[2][1])
    i = (T[2][0] * M[0][2] + T[2][1] *
         M[1][2] + T[2][2] * M[2][2])
             
    T[0][0] = a
    T[0][1] = b
    T[0][2] = c
    T[1][0] = d
    T[1][1] = e
    T[1][2] = f
    T[2][0] = g
    T[2][1] = h
    T[2][2] = i
 

def power(T, n):
 
    if (n == 0 or n == 1):
        return;
    M = [[ 1, 1, 1 ],
                [ 1, 0, 0 ],
                [ 0, 1, 0 ]]
 
    power(T, n // 2)
 
    multiply(T, T)
 
    if (n % 2):
        multiply(T, M)
 
def tribonacci(n):
     
    T = [[ 1, 1, 1 ],
        [1, 0, 0 ],
        [0, 1, 0 ]]
 
    if (n == 0 or n == 1):
        return 0
    else:
        power(T, n - 2)

    return T[0][0]






 



from types import GeneratorType
 
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    if not stack:
                        break
                    stack.pop()
                    to = stack[-1].send(to)
            return  to
 
    return wrappedfunc



def memoize(func):
    
    memos = {}
    def wrapper(x):
        if x not in memos:
            memos[x] = func(x)
        return memos[x]
    return wrapper
 
n,m=list(map(int,input().split()))
a=list(map(int,input().split()))
a.insert(0,10**10)
a.append(10**10)

ans=0
for i in range(1,n+1):
    if a[i]!=a[i-1]:
        k=i
    else:
        k=1
    g=n-i+1
    ans=ans+k*g

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
                            
    
    
    
    
    
    
    
    
    
    
    
    
    
        
    
    def id15(self, temp, v, visited):
        visited[v] = 1
        
        temp.append(v)
        for neighbour in self.graph[v]:
            if visited[neighbour]==0:
                
                temp = self.id15(temp, neighbour, visited)
        return temp
    
          
    def id13(self,numVertex):
        path=[]
        visited=defaultdict(lambda:0)
        for vertex in range(1,numVertex+1):
            if visited[vertex] == 0:
                temp = []
                path.append(self.id15(temp, vertex, visited))
        return path
      
    def id10(self,numVertex):
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
                  

    def id20(self, S):
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
    
    def id17(self,vertices):
        for k in range(1,vertices+1):
            for i in range(1,vertices+1):
                for j in range(1,vertices+1):
                   self.distance[i][j]=min(self.distance[i][j],self.edges[i][k]+self.edges[k][j])
        return self.distance


    
    def id3(self,parent,i):
        if parent[i]==i:
            return i
        else:
            return self.id3(parent,parent[i])
    
    def id24(self,parent,id12,x,y):
        xroot=self.id3(parent,x)
        yroot=self.id3(parent,y)
        if id12[xroot]<id12[yroot]:
            parent[xroot]=yroot
        elif id12[xroot]>id12[yroot]:
            parent[yroot]=xroot
        else:
            parent[yroot]=xroot
            id12[xroot]+=1
        
    def id22(self):
        
        res=[]
        
        
        i=0
        
        e=0

        
        self.graph=sorted(self.graph,key=lambda item: item[2])

        
        parent=[]
        id12=[]
        
        
        
        for node in range(self.vertices):
            parent.append(node)
            id12.append(0)
        
        
        
        while e<self.vertices-1:
            node1,node2,weight=self.graph[i]
            i+=1

            x=self.id3(parent,node1)
            y=self.id3(parent,node2)
            
            if x!=y:
                e+=1
                res.append([node1,node2,weight])
                self.id24(parent,id12,node1,node2)
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

    
    def id16(self,source, sink):
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
    
    
    
    
    def id19(self):
        path=self.id10(self.v)
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

    def id9(self,src):
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
    
    def id6(self,x,y):
        
        for i in range(x):
            self.addEdge(0,i+1,1)
        for i in range(y):
            self.addEdge(x+i+1,x+y+1,1)
        return self.id16(0,x+y+1)
    def id23(self,s,e):
        self.count[s]=1
        for u in self.graph[s]:
            if u!=e:
                self.id23(u,s)
                self.count[s]+=self.count[u]      

class SegmentTree:
    def __init__(self,mang,n):
        self.a=mang
        self.N=n
        self.tree=[0]*(4*self.N)
        self.INF_MIN=-10**9
    
    def showTree(self):
        print(self.tree)
    
    def buildTree(self,id,l,r):  
        
        

        if l==r:
            self.tree[id]=self.a[l];
            return
        m=(l+r)//2;
        self.buildTree(id*2,l,m)
        self.buildTree(id*2+1,m+1,r)
        
        self.tree[id]=max(self.tree[id*2],self.tree[id*2+1])
    
    def updateTree(self, id, l, r, u, v, val):  
        if u>r or v<l:
            return 
        if l==r:
            self.tree[id]+=val
            return
        m=(l+r)//2
        self.updateTree(id*2,l,m,u,v,val)
        self.updateTree(id*2+1,m+1,r,u,v,val)
        self.tree[id]=max(self.tree[id*2],self.tree[id*2+1])
        
    
    
    
    
    
    
    
    
    

    
    
    
    def getValue(self,id,l,r,u,v):   
        if u>r or v<l:
        
            return self.INF_MIN
        if l==r:
            return self.tree[id]
        m=(l+r)//2
        return max(self.getValue(id*2,l,m,u,v),self.getValue(id*2+1,m+1,r,u,v))
class SegmentTree:
    def __init__(self,mang,n):
        self.a=mang
        self.N=n
        self.tree=[0]*(4*self.N)
        self.INF_MIN=-10**9
    
    def showTree(self):
        print(self.tree)
    
    def buildTree(self,id,l,r):  
        
        

        if l==r:
            self.tree[id]=self.a[l];
            return
        m=(l+r)//2;
        self.buildTree(id*2,l,m)
        self.buildTree(id*2+1,m+1,r)
        
        self.tree[id]=max(self.tree[id*2],self.tree[id*2+1])
    
    def updateTree(self, id, l, r, u, v, val):  
        if u>r or v<l:
            return 
        if l==r:
            self.tree[id]+=val
            return
        m=(l+r)//2
        self.updateTree(id*2,l,m,u,v,val)
        self.updateTree(id*2+1,m+1,r,u,v,val)
        self.tree[id]=max(self.tree[id*2],self.tree[id*2+1])
        
    
    
    
    
    
    
    
    
    

    
    
    
    def getValue(self,id,l,r,u,v):   
        if u>r or v<l:
        
            return self.INF_MIN
        if l==r:
            return self.tree[id]
        m=(l+r)//2
        return max(self.getValue(id*2,l,m,u,v),self.getValue(id*2+1,m+1,r,u,v))
for i in range(m):
    toado,x=list(map(int,input().split()))
    if (a[toado]!=a[toado-1] and a[toado-1]==x):

        ans=ans-(toado*(n-toado+1));
        ans=ans+(n-toado+1);

    elif (a[toado]==a[toado-1] and a[toado-1]!=x):

        ans=ans+(toado*(n-toado+1));
        ans=ans-(n-toado+1);

    if (a[toado]!=a[toado+1] and a[toado+1]==x):

        ans=ans-((toado+1)*(n-toado));
        ans=ans+(n-toado);

    elif (a[toado]==a[toado+1] and a[toado+1]!=x):

        ans=ans+((toado+1)*(n-toado));
        ans=ans-(n-toado);

    a[toado]=x;
    print(ans)