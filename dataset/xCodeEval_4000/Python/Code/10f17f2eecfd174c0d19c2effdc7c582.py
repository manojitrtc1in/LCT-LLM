def divisors(M):
    d=[]
    i=1
    while M>=i**2:
        if M%i==0:
            d.append(i)
            if i**2!=M:
                d.append(M//i)
        i=i+1
    return d

def popcount(x):
    x = x - ((x >> 1) & 0x55555555)
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f
    x = x + (x >> 8)
    x = x + (x >> 16)
    return x & 0x0000007f

def eratosthenes(n):
    res=[0 for i in range(n+1)]
    prime=set([])
    for i in range(2,n+1):
        if not res[i]:
            prime.add(i)
            for j in range(1,n//i+1):
                res[i*j]=1
    return prime

def factorization(n):
    res=[]
    for p in prime:
        if n%p==0:
            while n%p==0:
                n//=p
            res.append(p)
    if n!=1:
        res.append(n)
    return res

def euler_phi(n):
    res = n
    for x in range(2,n+1):
        if x ** 2 > n:
            break
        if n%x==0:
            res = res//x * (x-1)
            while n%x==0:
                n //= x
    if n!=1:
        res = res//n * (n-1)
    return res

def ind(b,n):
    res=0
    while n%b==0:
        res+=1
        n//=b
    return res

def isPrimeMR(n):
    d = n - 1
    d = d // (d & -d)
    L = [2, 3, 5, 7, 11, 13, 17]
    for a in L:
        t = d
        y = pow(a, t, n)
        if y == 1: continue
        while y != n - 1:
            y = (y * y) % n
            if y == 1 or t == n - 1: return 0
            t <<= 1
    return 1
def findFactorRho(n):
    from math import gcd
    m = 1 << n.bit_length() // 8
    for c in range(1, 99):
        f = lambda x: (x * x + c) % n
        y, r, q, g = 2, 1, 1, 1
        while g == 1:
            x = y
            for i in range(r):
                y = f(y)
            k = 0
            while k < r and g == 1:
                ys = y
                for i in range(min(m, r - k)):
                    y = f(y)
                    q = q * abs(x - y) % n
                g = gcd(q, n)
                k += m
            r <<= 1
        if g == n:
            g = 1
            while g == 1:
                ys = f(ys)
                g = gcd(abs(x - ys), n)
        if g < n:
            if isPrimeMR(g): return g
            elif isPrimeMR(n // g): return n // g
            return findFactorRho(g)
def primeFactor(n):
    i = 2
    ret = {}
    rhoFlg = 0
    while i*i <= n:
        k = 0
        while n % i == 0:
            n //= i
            k += 1
        if k: ret[i] = k
        i += 1 + i % 2
        if i == 101 and n >= 2 ** 20:
            while n > 1:
                if isPrimeMR(n):
                    ret[n], n = 1, 1
                else:
                    rhoFlg = 1
                    j = findFactorRho(n)
                    k = 0
                    while n % j == 0:
                        n //= j
                        k += 1
                    ret[j] = k

    if n > 1: ret[n] = 1
    if rhoFlg: ret = {x: ret[x] for x in sorted(ret)}
    return ret

def divisors(n):
    res = [1]
    prime = primeFactor(n)
    for p in prime:
        newres = []
        for d in res:
            for j in range(prime[p]+1):
                newres.append(d*p**j)
        res = newres
    res.sort()
    return res

def floor_sum(n: int, m: int, a: int, b: int) -> int:
    ans = 0

    if a >= m:
        ans += (n - 1) * n * (a // m) // 2
        a %= m

    if b >= m:
        ans += n * (b // m)
        b %= m

    y_max = (a * n + b) // m
    x_max = y_max * m - b

    if y_max == 0:
        return ans

    ans += (n - (x_max + a - 1) // a) * y_max
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a)

    return ans

def xorfactorial(num):
    if num==0:
        return 0
    elif num==1:
        return 1
    elif num==2:
        return 3
    elif num==3:
        return 0
    else:
        x=baseorder(num)
        return (2**x)*((num-2**x+1)%2)+function(num-2**x)

def xorconv(n,X,Y):
    if n==0:
        res=[(X[0]*Y[0])%mod]
        return res
    x=[X[i]+X[i+2**(n-1)] for i in range(2**(n-1))]
    y=[Y[i]+Y[i+2**(n-1)] for i in range(2**(n-1))]
    z=[X[i]-X[i+2**(n-1)] for i in range(2**(n-1))]
    w=[Y[i]-Y[i+2**(n-1)] for i in range(2**(n-1))]
    res1=xorconv(n-1,x,y)
    res2=xorconv(n-1,z,w)
    former=[(res1[i]+res2[i])*inv for i in range(2**(n-1))]
    latter=[(res1[i]-res2[i])*inv for i in range(2**(n-1))]
    former=list(map(lambda x:x%mod,former))
    latter=list(map(lambda x:x%mod,latter))
    return former+latter

def merge_sort(A,B):
    pos_A,pos_B = 0,0
    n,m = len(A),len(B)
    res = []
    while pos_A < n and pos_B < m:
        a,b = A[pos_A],B[pos_B]
        if a < b:
            res.append(a)
            pos_A += 1
        else:
            res.append(b)
            pos_B += 1
    res += A[pos_A:]
    res += B[pos_B:]
    return res

class UnionFindVerSize():
    def __init__(self, N):
        self._parent = [n for n in range(0, N)]
        self._size = [1] * N
        self.group = N

    def find_root(self, x):
        if self._parent[x] == x: return x
        self._parent[x] = self.find_root(self._parent[x])
        stack = [x]
        while self._parent[stack[-1]]!=stack[-1]:
            stack.append(self._parent[stack[-1]])
        for v in stack:
            self._parent[v] = stack[-1]
        return self._parent[x]

    def unite(self, x, y):
        gx = self.find_root(x)
        gy = self.find_root(y)
        if gx == gy: return

        self.group -= 1

        if self._size[gx] < self._size[gy]:
            self._parent[gx] = gy
            self._size[gy] += self._size[gx]
        else:
            self._parent[gy] = gx
            self._size[gx] += self._size[gy]

    def get_size(self, x):
        return self._size[self.find_root(x)]

    def is_same_group(self, x, y):
        return self.find_root(x) == self.find_root(y)

class WeightedUnionFind():
    def __init__(self,N):
        self.parent = [i for i in range(N)]
        self.size = [1 for i in range(N)]
        self.val = [0 for i in range(N)]
        self.flag = True
        self.edge = [[] for i in range(N)]

    def dfs(self,v,pv):
        stack = [(v,pv)]
        new_parent = self.parent[pv]
        while stack:
            v,pv = stack.pop()
            self.parent[v] = new_parent
            for nv,w in self.edge[v]:
                if nv!=pv:
                    self.val[nv] = self.val[v] + w
                    stack.append((nv,v))

    def unite(self,x,y,w):
        if not self.flag:
            return
        if self.parent[x]==self.parent[y]:
            self.flag = (self.val[x] - self.val[y] == w)
            return

        if self.size[self.parent[x]]>self.size[self.parent[y]]:
            self.edge[x].append((y,-w))
            self.edge[y].append((x,w))
            self.size[x] += self.size[y]
            self.val[y] = self.val[x] - w
            self.dfs(y,x)
        else:
            self.edge[x].append((y,-w))
            self.edge[y].append((x,w))
            self.size[y] += self.size[x]
            self.val[x] = self.val[y] + w
            self.dfs(x,y)

class Dijkstra():
    class Edge():
        def __init__(self, _to, _cost):
            self.to = _to
            self.cost = _cost

    def __init__(self, V):
        self.G = [[] for i in range(V)]
        self._E = 0
        self._V = V

    @property
    def E(self):
        return self._E

    @property
    def V(self):
        return self._V

    def add_edge(self, _from, _to, _cost):
        self.G[_from].append(self.Edge(_to, _cost))
        self._E += 1

    def shortest_path(self, s):
        import heapq
        inf = float("inf")
        que = []
        d = [inf] * self.V
        d[s] = 0
        heapq.heappush(que, (0, s))

        while len(que) != 0:
            cost, v = heapq.heappop(que)
            if d[v] < cost: continue

            for i in range(len(self.G[v])):
                e = self.G[v][i]
                if d[e.to] > d[v] + e.cost:
                    d[e.to] = d[v] + e.cost
                    heapq.heappush(que, (d[e.to], e.to))
        return d



def Z_algorithm(s):
    N = len(s)
    Z_alg = [0]*N

    Z_alg[0] = N
    i = 1
    j = 0
    while i < N:
        while i+j < N and s[j] == s[i+j]:
            j += 1
        Z_alg[i] = j
        if j == 0:
            i += 1
            continue
        k = 1
        while i+k < N and k + Z_alg[k]<j:
            Z_alg[i+k] = Z_alg[k]
            k += 1
        i += k
        j -= k
    return Z_alg

class BIT():
    def __init__(self,n):
        self.BIT=[0]*(n+1)
        self.num=n

    def query(self,idx):
        res_sum = 0
        while idx > 0:
            res_sum += self.BIT[idx]
            idx -= idx&(-idx)
        return res_sum

    
    def update(self,idx,x):
        while idx <= self.num:
            self.BIT[idx] += x
            idx += idx&(-idx)
        return

class dancinglink():
    def __init__(self,n,debug=False):
        self.n = n
        self.debug = debug
        self._left = [i-1 for i in range(n)]
        self._right = [i+1 for i in range(n)]
        self.exist = [True for i in range(n)]

    def pop(self,k):
        if self.debug:
            assert self.exist[k]
        L = self._left[k]
        R = self._right[k]
        if L!=-1:
            if R!=self.n:
                self._right[L],self._left[R] = R,L
            else:
                self._right[L] = self.n
        elif R!=self.n:
            self._left[R] = -1
        self.exist[k] = False

    def left(self,idx,k=1):
        if self.debug:
            assert self.exist[idx]
        res = idx
        while k:
            res = self._left[res]
            if res==-1:
                break
            k -= 1
        return res

    def right(self,idx,k=1):
        if self.debug:
            assert self.exist[idx]
        res = idx
        while k:
            res = self._right[res]
            if res==self.n:
                break
            k -= 1
        return res

class SparseTable():
    def __init__(self,A,merge_func,ide_ele):
        N=len(A)
        n=N.bit_length()
        self.table=[[ide_ele for i in range(n)] for i in range(N)]
        self.merge_func=merge_func

        for i in range(N):
            self.table[i][0]=A[i]

        for j in range(1,n):
            for i in range(0,N-2**j+1):
                f=self.table[i][j-1]
                s=self.table[i+2**(j-1)][j-1]
                self.table[i][j]=self.merge_func(f,s)

    def query(self,s,t):
        b=t-s+1
        m=b.bit_length()-1
        return self.merge_func(self.table[s][m],self.table[t-2**m+1][m])

class BinaryTrie:
    class node:
        def __init__(self,val):
            self.left = None
            self.right = None
            self.max = val

    def __init__(self):
        self.root = self.node(-10**15)

    def append(self,key,val):
        pos = self.root
        for i in range(29,-1,-1):
            pos.max = max(pos.max,val)
            if key>>i & 1:
                if pos.right is None:
                    pos.right = self.node(val)
                    pos = pos.right
                else:
                    pos = pos.right
            else:
                if pos.left is None:
                    pos.left = self.node(val)
                    pos = pos.left
                else:
                    pos = pos.left
        pos.max = max(pos.max,val)

    def search(self,M,xor):
        res = -10**15
        pos = self.root
        for i in range(29,-1,-1):
            if pos is None:
                break

            if M>>i & 1:
                if xor>>i & 1:
                    if pos.right:
                        res = max(res,pos.right.max)
                    pos = pos.left
                else:
                    if pos.left:
                        res = max(res,pos.left.max)
                    pos = pos.right
            else:
                if xor>>i & 1:
                    pos = pos.right
                else:
                    pos = pos.left

        if pos:
            res = max(res,pos.max)
        return res

def solveequation(edge,ans,n,m):
    
    x=[0]*m
    used=[False]*n
    for v in range(n):
        if used[v]:
            continue
        y = dfs(v)
        if y!=0:
            return False
    return x

    def dfs(v):
        used[v]=True
        r=ans[v]
        for to,dire,id in edge[v]:
            if used[to]:
                continue
            y=dfs(to)
            if dire==-1:
                x[id]=y
            else:
                x[id]=-y
            r+=y
        return r

class Matrix():
    mod=10**9+7

    def set_mod(m):
        Matrix.mod=m

    def __init__(self,L):
        self.row=len(L)
        self.column=len(L[0])
        self._matrix=L
        for i in range(self.row):
            for j in range(self.column):
                self._matrix[i][j]%=Matrix.mod

    def __getitem__(self,item):
        if type(item)==int:
            raise IndexError("you must specific row and column")
        elif len(item)!=2:
            raise IndexError("you must specific row and column")

        i,j=item
        return self._matrix[i][j]

    def __setitem__(self,item,val):
        if type(item)==int:
            raise IndexError("you must specific row and column")
        elif len(item)!=2:
            raise IndexError("you must specific row and column")

        i,j=item
        self._matrix[i][j]=val

    def __add__(self,other):
        if (self.row,self.column)!=(other.row,other.column):
            raise SizeError("sizes of matrixes are different")

        res=[[0 for j in range(self.column)] for i in range(self.row)]
        for i in range(self.row):
            for j in range(self.column):
                res[i][j]=self._matrix[i][j]+other._matrix[i][j]
                res[i][j]%=Matrix.mod
        return Matrix(res)

    def __sub__(self,other):
        if (self.row,self.column)!=(other.row,other.column):
            raise SizeError("sizes of matrixes are different")

        res=[[0 for j in range(self.column)] for i in range(self.row)]
        for i in range(self.row):
            for j in range(self.column):
                res[i][j]=self._matrix[i][j]-other._matrix[i][j]
                res[i][j]%=Matrix.mod
        return Matrix(res)

    def __mul__(self,other):
        if type(other)!=int:
            if self.column!=other.row:
                raise SizeError("sizes of matrixes are different")

            res=[[0 for j in range(other.column)] for i in range(self.row)]
            for i in range(self.row):
                for j in range(other.column):
                    temp=0
                    for k in range(self.column):
                        temp+=self._matrix[i][k]*other._matrix[k][j]
                    res[i][j]=temp%Matrix.mod
            return Matrix(res)
        else:
            n=other
            res=[[(n*self._matrix[i][j])%Matrix.mod for j in range(self.column)] for i in range(self.row)]
            return Matrix(res)

    def __pow__(self,m):
        if self.column!=self.row:
            raise MatrixPowError("the size of row must be the same as that of column")

        n=self.row
        res=Matrix([[int(i==j) for i in range(n)] for j in range(n)])
        while m:
            if m%2==1:
                res=res*self
            self=self*self
            m//=2
        return res

    def __str__(self):
        res=[]
        for i in range(self.row):
            for j in range(self.column):
                res.append(str(self._matrix[i][j]))
                res.append(" ")
            res.append("\n")
        res=res[:len(res)-1]
        return "".join(res)

class SegmentTree:
    def __init__(self, init_val, segfunc, ide_ele):
        n = len(init_val)
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num
        for i in range(n):
            self.tree[self.num + i] = init_val[i]
        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])

    def update(self, k, x):
        k += self.num
        self.tree[k] = x
        while k > 1:
            self.tree[k >> 1] = self.segfunc(self.tree[k], self.tree[k ^ 1])
            k >>= 1

    def query(self, l, r):
        res = self.ide_ele

        l += self.num
        r += self.num
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                res = self.segfunc(res, self.tree[r - 1])
            l >>= 1
            r >>= 1
        return res

    def bisect_l(self,l,r,x):
        l += self.num
        r += self.num
        Lmin = -1
        Rmin = -1
        while l<r:
            if l & 1:
                if self.tree[l] <= x and Lmin==-1:
                    Lmin = l
                l += 1
            if r & 1:
                if self.tree[r-1] <=x:
                    Rmin = r-1
            l >>= 1
            r >>= 1

        if Lmin != -1:
            pos = Lmin
            while pos<self.num:
                if self.tree[2 * pos] <=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            return pos-self.num
        elif Rmin != -1:
            pos = Rmin
            while pos<self.num:
                if self.tree[2 * pos] <=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            return pos-self.num
        else:
            return -1

class DualSegmentTree:
    def __init__(self, n, segfunc, ide_ele):
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num

    def update(self,l,r,x):
        l += self.num
        r += self.num
        while l < r:
            if l & 1:
                self.tree[l] = self.segfunc(self.tree[l],x)
                l += 1
            if r & 1:
                self.tree[r-1] = self.segfunc(self.tree[r-1],x)
            l >>= 1
            r >>= 1

    def __getitem__(self,idx):
        idx += self.num
        res = self.ide_ele
        while idx:
            res = self.segfunc(res,self.tree[idx])
            idx>>=1
        return res

class LazySegmentTree():
    __slots__ = ["merge","merge_unit","operate","merge_operate","operate_unit","n","data","lazy"]
    def __init__(self,n,init,merge,merge_unit,operate,merge_operate,operate_unit):
        self.merge=merge
        self.merge_unit=merge_unit
        self.operate=operate
        self.merge_operate=merge_operate
        self.operate_unit=operate_unit

        self.n=(n-1).bit_length()
        self.data=[merge_unit for i in range(1<<(self.n+1))]
        self.lazy=[operate_unit for i in range(1<<(self.n+1))]
        if init:
            for i in range(n):
                self.data[2**self.n+i]=init[i]
            for i in range(2**self.n-1,0,-1):
                self.data[i]=self.merge(self.data[2*i],self.data[2*i+1])

    def propagate(self,v):
        ope = self.lazy[v]
        if ope == self.operate_unit:
            return
        self.lazy[v]=self.operate_unit
        self.data[(v<<1)]=self.operate(self.data[(v<<1)],ope)
        self.data[(v<<1)+1]=self.operate(self.data[(v<<1)+1],ope)
        self.lazy[v<<1]=self.merge_operate(self.lazy[(v<<1)],ope)
        self.lazy[(v<<1)+1]=self.merge_operate(self.lazy[(v<<1)+1],ope)

    def propagate_above(self,i):
        m=i.bit_length()-1
        for bit in range(m,0,-1):
            v=i>>bit
            self.propagate(v)

    def remerge_above(self,i):
        while i:
            c = self.merge(self.data[i],self.data[i^1])
            i>>=1
            self.data[i]=self.operate(c,self.lazy[i])

    def update(self,l,r,x):
        l+=1<<self.n
        r+=1<<self.n
        l0=l//(l&-l)
        r0=r//(r&-r)-1
        self.propagate_above(l0)
        self.propagate_above(r0)
        while l<r:
            if l&1:
                self.data[l]=self.operate(self.data[l],x)
                self.lazy[l]=self.merge_operate(self.lazy[l],x)
                l+=1
            if r&1:
                self.data[r-1]=self.operate(self.data[r-1],x)
                self.lazy[r-1]=self.merge_operate(self.lazy[r-1],x)
            l>>=1
            r>>=1
        self.remerge_above(l0)
        self.remerge_above(r0)

    def query(self,l,r):
        l+=1<<self.n
        r+=1<<self.n
        l0=l//(l&-l)
        r0=r//(r&-r)-1
        self.propagate_above(l0)
        self.propagate_above(r0)
        res=self.merge_unit
        while l<r:
            if l&1:
                res=self.merge(res,self.data[l])
                l+=1
            if r&1:
                res=self.merge(res,self.data[r-1])
            l>>=1
            r>>=1
        return res

    def bisect_l(self,l,r,x):
        l += 1<<self.n
        r += 1<<self.n
        l0=l//(l&-l)
        r0=r//(r&-r)-1
        self.propagate_above(l0)
        self.propagate_above(r0)
        Lmin = -1
        Rmin = -1
        while l<r:
            if l & 1:
                if self.data[l][0] <= x and Lmin==-1:
                    Lmin = l
                l += 1
            if r & 1:
                if self.data[r-1][0] <=x:
                    Rmin = r-1
            l >>= 1
            r >>= 1

        res = -1
        if Lmin != -1:
            pos = Lmin
            while pos<self.num:
                self.propagate(pos)
                if self.data[2 * pos][0] <=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            res =  pos-self.num
        if Rmin != -1:
            pos = Rmin
            while pos<self.num:
                self.propagate(pos)
                if self.data[2 * pos][0] <=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            if res==-1:
                res = pos-self.num
            else:
                res = min(res,pos-self.num)

        return res

def floor_sum(n: int, m: int, a: int, b: int) -> int:
    ans = 0

    if a >= m:
        ans += (n - 1) * n * (a // m) // 2
        a %= m

    if b >= m:
        ans += n * (b // m)
        b %= m

    y_max = (a * n + b) // m
    x_max = y_max * m - b

    if y_max == 0:
        return ans

    ans += (n - (x_max + a - 1) // a) * y_max
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a)

    return ans

def _inv_gcd(a,b):
    a %= b
    if a == 0:
        return (b, 0)

    
    
    
    
    s = b
    t = a
    m0 = 0
    m1 = 1

    while t:
        u = s // t
        s -= t * u
        m0 -= m1 * u  

        
        
        
        

        s, t = t, s
        m0, m1 = m1, m0

    
    
    if m0 < 0:
        m0 += b // s

    return (s, m0)

def crt(r,m):
    assert len(r) == len(m)

    n = len(r)

    
    r0 = 0
    m0 = 1
    for i in range(n):
        assert 1 <= m[i]
        r1 = r[i] % m[i]
        m1 = m[i]
        if m0 < m1:
            r0, r1 = r1, r0
            m0, m1 = m1, m0
        if m0 % m1 == 0:
            if r0 % m1 != r1:
                return (0, 0)
            continue

        

        
        g, im = _inv_gcd(m0, m1)

        u1 = m1 // g
        
        if (r1 - r0) % g:
            return (0, 0)

        
        x = (r1 - r0) // g % u1 * im % u1

        r0 += x * m0
        m0 *= u1  
        if r0 < 0:
            r0 += m0

    return (r0, m0)

import sys,random,bisect
from collections import deque,defaultdict
from heapq import heapify,heappop,heappush
from itertools import permutations
from math import log,gcd

input = lambda :sys.stdin.readline().rstrip()
mi = lambda :map(int,input().split())
li = lambda :list(mi())

n,m = mi()
dic = {}
odd = 0
even = 0
for _ in range(m):
    query = input().split()
    if len(query)==2:
        k = int(query[1])
        if k%2 and odd:
            print("YES")
        elif not k%2 and even:
            print("YES")
        else:
            print("NO")
    else:
        u,v = map(int,query[1:3])
        if query[0]=="+":
            if (min(u,v),max(u,v)) not in dic:
                dic[min(u,v),max(u,v)] = [None,None]
            dic[min(u,v),max(u,v)][int(u<v)] = query[-1]

            U,V = min(u,v),max(u,v)
            if dic[U,V][0] and dic[U,V][1]:
                odd += 1
            if dic[U,V][0] and dic[U,V][1] and dic[U,V][0]==dic[U,V][1]:
                even += 1
        else:
            U,V = min(u,v),max(u,v)
            if dic[U,V][0] and dic[U,V][1]:
                odd -= 1
            if dic[U,V][0] and dic[U,V][1] and dic[U,V][0]==dic[U,V][1]:
                even -= 1
            dic[min(u,v),max(u,v)][int(u<v)] = None
