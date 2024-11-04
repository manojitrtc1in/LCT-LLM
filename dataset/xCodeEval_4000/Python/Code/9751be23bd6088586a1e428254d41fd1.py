
 



 

 



 
from functools import cmp_to_key 
from collections import deque, Counter
from heapq import heappush, heappop
from math import log, ceil
 



 
import sys
import os
from io import BytesIO, IOBase
 
BUFSIZE = 8192
 
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
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
 
if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

"""
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
"""
def inp():
    return sys.stdin.readline().rstrip("\r\n")  
    
def ii():
    return int(inp())
 
def si():
    return str(inp())
 
def li(lag = 0):
    l = list(map(int, inp().split()))
    if lag != 0:
        for i in range(len(l)):
            l[i] += lag
    return l
    
def mi(lag = 0):
    matrix = list()
    for i in range(n):
        matrix.append(li(lag))
    return matrix
 
def lsi(): 
    return list(map(str, inp().split()))
 
def print_list(lista, space = " "):
    print(space.join(map(str, lista)))
 



 
def bisect_left(a, x):
    """i tale che a[i] >= x e a[i-1] < x"""
    left = 0
    right = len(a)
    while left < right:
        mid = (left+right)//2
        if a[mid] < x: 
            left = mid+1
        else: 
            right = mid
    return left
 
def bisect_right(a, x):
    """i tale che a[i] > x e a[i-1] <= x"""
    left = 0
    right = len(a)
    while left < right:
        mid = (left+right)//2
        if a[mid] > x: 
            right = mid
        else: 
            left = mid+1
    return left
 
def bisect_elements(a, x):
    """elementi pari a x nell'árray sortato"""
    return bisect_right(a, x) - bisect_left(a, x)
 



 
MOD = 10**9 + 7
maxN = 5
FACT = [0] * maxN
INV_FACT = [0] * maxN
 
def add(x, y):
    return (x+y) % MOD
   
def multiply(x, y):
    return (x*y) % MOD
 
def power(x, y):
    if y == 0:
        return 1
    elif y % 2:
        return multiply(x, power(x, y-1))
    else:
        a = power(x, y//2)
        return multiply(a, a)
 
def inverse(x):
    return power(x, MOD-2)
   
def divide(x, y):
    return multiply(x, inverse(y))
 
def allFactorials():
    FACT[0] = 1
    for i in range(1, maxN):
        FACT[i] = multiply(i, FACT[i-1])
 
def inverseFactorials():
    n = len(INV_FACT)
    INV_FACT[n-1] = inverse(FACT[n-1])
    for i in range(n-2, -1, -1):
        INV_FACT[i] = multiply(INV_FACT[i+1], i+1)
 
def coeffBinom(n, k):
    if n < k:
        return 0
    return multiply(FACT[n], multiply(INV_FACT[k], INV_FACT[n-k]))
 



 

def create_graph(n, m, undirected = 1, unweighted = 1):
    graph = [[] for i in range(n)]
    if unweighted:
        for i in range(m):
            [x, y] = li(lag = -1)
            graph[x].append(y)
            if undirected:
                graph[y].append(x)
    else:
        for i in range(m):
            [x, y, w] = li(lag = -1)
            w += 1
            graph[x].append([y,w])
            if undirected:
                graph[y].append([x,w])
    return graph
 
def create_tree(n, unweighted = 1):
    children = [[] for i in range(n)]
    if unweighted:
        for i in range(n-1):
            [x, y] = li(lag = -1)
            children[x].append(y)
            children[y].append(x)
    else:
        for i in range(n-1):
            [x, y, w] = li(lag = -1)
            w += 1
            children[x].append([y, w])
            children[y].append([x, w])
    return children
   
def dist(tree, n, A, B = -1):
    s = [[A, 0]]
    massimo, massimo_nodo = 0, 0
    distanza = -1
    v = [-1] * n
    while s:
        el, dis = s.pop() 
        if dis > massimo:
            massimo = dis
            massimo_nodo = el
        if el == B:
            distanza = dis
        for child in tree[el]:
            if v[child] == -1:
                v[child] = 1
                s.append([child, dis+1])
    return massimo, massimo_nodo, distanza
 
def diameter(tree):
    _, foglia, _ = dist(tree, n, 0)
    diam, _, _ = dist(tree, n, foglia)
    return diam
   
def dfs(graph, n, A):
    v = [-1] * n
    s = [[A, 0]]
    v[A] = 0
    while s:
        el, dis = s.pop()
        for child in graph[el]:
            if v[child] == -1:
                v[child] = dis + 1
                s.append([child, dis + 1])
    return v 
 
def bfs(graph, n, A):
    v = [-1] * n
    s = deque()
    s.append([A, 0])
    v[A] = 0
    while s:
        el, dis = s.popleft()
        for child in graph[el]:
            if v[child] == -1:
                v[child] = dis + 1
                s.append([child, dis + 1])
    return v 
 

def parents_children_root_unrooted_tree(tree, n, root = 0):
    q = deque()
    visited = [0] * n
    parent = [-1] * n
    children = [[] for i in range(n)]
    q.append(root)
    while q:
        all_done = 1
        visited[q[0]] = 1
        for child in tree[q[0]]:
            if not visited[child]:
                all_done = 0
                q.appendleft(child)
        if all_done:
            for child in tree[q[0]]:   
                if parent[child] == -1:
                    parent[q[0]] = child
                    children[child].append(q[0])
            q.popleft()
    return parent, children
 

def all_longest_path_passing_from_node(parent, children, n):
    q = deque()
    visited = [len(children[i]) for i in range(n)]
    downwards = [[0,0] for i in range(n)]
    upward = [1] * n
    longest_path = [1] * n
    for i in range(n):
        if not visited[i]:
            q.append(i)
            downwards[i] = [1,0]
    while q:
        node = q.popleft()
        if parent[node] != -1:
            visited[parent[node]] -= 1
            if not visited[parent[node]]:
                q.append(parent[node])
        else:
            root = node
        for child in children[node]:   
            downwards[node] = sorted([downwards[node][0], downwards[node][1], downwards[child][0] + 1], reverse = True)[0:2]
    s = [node]
    while s:
        node = s.pop()
        if parent[node] != -1:
            if downwards[parent[node]][0] == downwards[node][0] + 1:
                upward[node] = 1 + max(upward[parent[node]], downwards[parent[node]][1])
            else:
                upward[node] = 1 + max(upward[parent[node]], downwards[parent[node]][0])
        longest_path[node] = downwards[node][0] + downwards[node][1] + upward[node] - min([downwards[node][0], downwards[node][1], upward[node]]) - 1
        for child in children[node]:
            s.append(child)
    return longest_path
 




 





class SegmentTreeMin:
    def __init__(self, arr):
        self.low, self.high = 0, len(arr)-1
        self.sz = pow(2, int(ceil(log(len(arr), 2))))
        self.dat = [float('inf')] * (2 * self.sz - 1)
        self.arr = arr
        self.build_help(self.low, self.high, 0)
    
    def build_help(self, low, high, pos):
        if low == high:
            self.dat[pos] = self.arr[low]
            return
        mid = (low + high) // 2
        self.build_help(low, mid, 2*pos+1)
        self.build_help(mid+1, high, 2*pos+2)
        self.dat[pos] = min(self.dat[2*pos+1], self.dat[2*pos+2])
    
    def update(self, idx, val):
        self.update_help(idx, self.low, self.high, 0, val)

    def update_help(self, idx, low, high, pos, val):
        if idx < low or idx > high:
            return
        if low == high:
            self.dat[pos] = val
            return
        mid = (low + high) // 2
        self.update_help(idx, low, mid, 2*pos+1, val)
        self.update_help(idx, mid+1, high, 2*pos+2, val)
        self.dat[pos] = min(self.dat[2*pos+1], self.dat[2*pos+2])
    
    def query(self, qlow, qhigh):
        return self.query_help(qlow, qhigh, self.low, self.high, 0)
            
    def query_help(self, qlow, qhigh, low, high, pos):
        if qlow <= low and qhigh >= high: 
            return self.dat[pos]
        if qlow > high or qhigh < low: 
            return float('inf')
        mid = (low + high) // 2
        
        return min(self.query_help(qlow, qhigh, low, mid, 2*pos+1), self.query_help(qlow, qhigh, mid+1, high, 2*pos+2))


class SegmentTree:
    def __init__(self, arr):
        self.low, self.high = 0, len(arr)-1
        self.sz = pow(2, int(ceil(log(len(arr), 2))))
        self.datm = [float('inf')] * (2 * self.sz - 1)
        self.datM = [float('inf')] * (2 * self.sz - 1)
        self.arr = arr
        self.build_help(self.low, self.high, 0)
    
    def build_help(self, low, high, pos):
        if low == high:
            self.datm[pos] = self.arr[low]
            self.datM[pos] = self.arr[low]
            return
        mid = (low + high) // 2
        self.build_help(low, mid, 2*pos+1)
        self.build_help(mid+1, high, 2*pos+2)
        self.datM[pos] = max(self.datM[2*pos+1], self.datM[2*pos+2])
        self.datm[pos] = min(self.datm[2*pos+1], self.datm[2*pos+2])
    
    def querymin(self, qlow, qhigh):
        return self.query_help_min(qlow, qhigh, self.low, self.high, 0)

    def querymax(self, qlow, qhigh):
        return self.query_help_max(qlow, qhigh, self.low, self.high, 0)
            
    def query_help_min(self, qlow, qhigh, low, high, pos):
        if qlow <= low and qhigh >= high: 
            return self.datm[pos]
        if qlow > high or qhigh < low: 
            return float('inf')
        mid = (low + high) // 2
        
        return min(self.query_help_min(qlow, qhigh, low, mid, 2*pos+1), self.query_help_min(qlow, qhigh, mid+1, high, 2*pos+2))

    def query_help_max(self, qlow, qhigh, low, high, pos):
        if qlow <= low and qhigh >= high: 
            return self.datM[pos]
        if qlow > high or qhigh < low: 
            return -float('inf')
        mid = (low + high) // 2
        
        return max(self.query_help_max(qlow, qhigh, low, mid, 2*pos+1), self.query_help_max(qlow, qhigh, mid+1, high, 2*pos+2))


for test in range(ii()):
    n,m = li()
    s = si()
    mal, mil, pre = [0] * (n+1), [0] * (n+1), [0] * (n+1)
    for i in range(n):
        pre[i+1] = pre[i] + (1 if s[i] == '+' else -1)
    for i in range(1, n+1):
        mil[i] = min(mil[i-1], pre[i])
        mal[i] = max(mal[i-1], pre[i])
    pos = [None] * (2*n + 1)
    for i in range(n+1):
        pos[pre[i] + n] = i
    for q in range(m):
        l, r = li(-1)
        cur = pre[l]
        mi, ma = mil[l], mal[l]
        if r != n-1:
            left = -n
            right = pre[r+2]
            while left < right:
                mid = (left + right) // 2
                if pos[mid+n] is None or pos[mid + n] < r + 2:
                    left = mid + 1
                else:
                    right = mid
            vmi = left
            left = pre[r+2]
            right = n
            while left < right:
                mid = (left + right + 1) // 2
                if pos[mid+n] is None or pos[mid + n] < r + 2:
                    right = mid - 1
                else:
                    left = mid
            vma = left 
            
            cont = pre[r+1] - pre[l]
            vmi -= cont
            vma -= cont
            mi = min(mi, vmi)
            ma = max(ma, vma)
        print(ma - mi + 1)
