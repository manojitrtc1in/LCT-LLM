import sys
from heapq import heappush, heappop 
from bisect import bisect_left as bi_l, bisect_right as bi_r
from collections import deque, Counter, defaultdict
import itertools 
import string 
import math 
from operator import xor, or_
from functools import lru_cache, reduce
sys.setrecursionlimit(10**7)
inf = float('inf')
MOD = 10**9+7



using_numpy = 1













class Algebra:
  class Modular(int):
    def __init__(self, n, mod=MOD):
      self.value = n
      self.mod = mod

    def __str__(self): return f'{self.value}'

    def __add__(self, other): 
      return self.__class__((self.value + other.value) % self.mod)
    def __sub__(self, x): return self.__class__((self.value - x.value) % self.mod)
    def __mul__(self, x): return self.__class__((self.value * x.value) % self.mod)
    def __pow__(self, x): return self.__class__(pow(self.value, x.value, self.mod))

    def __lt__(self, x): return self.value < x.value
    def __le__(self, x): return self.value <= x.value
    def __eq__(self, x): return self.value == x.value 
    def __ne__(self, x): return self.value != x.value
    def __gt__(self, x): return self.value > x.value
    def __ge__(self, x): return self.value >= x.value
  

  
  class SemiGroup:
    pass 
  class Monoid:
    pass
  class Group:
    pass 
  class SemiRing:
    pass
  class Ring:
    pass


  @staticmethod
  def identity(n):
    if using_numpy:
      return np.identity(n, dtype=np.int64)
    else:
      a = [[0]*n for _ in range(n)]
      for i in range(n): a[i][i] = 1
      return a

  @staticmethod
  def dot(a, b):
    if using_numpy:
      return np.dot(a, b)
    else:
      h, w, l = len(a), len(b[0]), len(b)
      assert len(a[0]) == l
      c = [[0]*w for _ in range(h)]
      for i in range(h):
        for j in range(w):
          for k in range(l):
            c[i][j] += a[i][k]*b[k][j]
      return c 
    
  @classmethod
  def matrix_pow(cls, a, n, mod=10**9+7):
    m = len(a)
    b = cls.identity(m)
    while n:
      if n&1: b = cls.dot(b, a)
      n >>= 1; a = cls.dot(a, a)
      if using_numpy:
        a %= mod; b %= mod
      else:
        for i in range(m):
          for j in range(m):
            a[i][j] %= mod
            b[i][j] %= mod
    return b

  @staticmethod
  def bitwise_dot(a, b):
    if using_numpy:
      return np.bitwise_xor.reduce(a[:,None,:] & b.T[None,:,:], axis=-1)
    else:
      h, w, l = len(a), len(b[0]), len(b)
      assert len(a[0]) == l
      c = [[0]*w for _ in range(h)]
      for i in range(h):
        for j in range(w):
          for k in range(l):
            c[i][j] ^= a[i][k]&b[k][j]
      return c 

  @classmethod
  def bitwise_mat_pow(cls, a, n):
    if n==0: return np.eye(len(a), dtype=np.uint32)*((1<<32)-1)
    res = cls.bitwise_mat_pow(a, n//2)
    res = cls.bitwise_dot(res, res)
    return cls.bitwise_dot(res, a) if n&1 else res

  class Kitamasa:
    pass


mint = Algebra.Modular


class NumberTheory:
  class PrimeNumbers: 
    def __init__(self, n=2*10**6):
      self.is_prime, self.prime_nums = self.find(n)
    
    def __call__(self, n): return self.is_prime[n]
    def __iter__(self): return iter(self.prime_nums)
    def __getitem__(self, key): return self.prime_nums[key]

    @staticmethod
    def find(n): 
      if using_numpy:
        is_prime = np.ones(n+1, dtype=np.bool); is_prime[:2] = 0
        for i in range(2, int(n**.5)+1):
          if is_prime[i]: is_prime[i*2::i] = 0
        prime_nums = np.flatnonzero(is_prime)
      else:
        is_prime = [True]*(n+1); is_prime[0] = is_prime[1] = 0
        for i in range(2, int(n**.5)+1):
          if not is_prime[i]: continue
          for j in range(i*2, n+1, i): is_prime[j] = 0
        prime_nums = [i for i in range(2, n+1) if is_prime[i]]
      return is_prime, prime_nums 

    @lru_cache(maxsize=None)
    def factorize(self, n):
      res = defaultdict(int)
      if n < 2: return res
      for p in self:
        if p*p > n: break
        while n%p == 0: res[p] += 1; n //= p
        if n == 1: return res
      res[n] = 1; return res

    def factorize_factorial(self, n):
      res = defaultdict(int)
      for i in range(2, n+1):
        for p, c in self.factorize(i).items(): res[p] += c
      return res
  
  @classmethod
  @lru_cache(maxsize=None)
  def gcd(cls, a, b): return cls.gcd(b, a%b) if b else abs(a)
  @classmethod
  def lcm(cls, a, b): return abs(a // cls.gcd(a, b) * b)

  @staticmethod
  def find_divisors(n):
    divisors = []
    for i in range(1, int(n**.5)+1):
      if n%i: continue
      divisors.append(i)
      j = n // i
      if j != i: divisors.append(j)
    return sorted(divisors)

  @staticmethod
  def base_convert(n, b):
    if not n: return [0]
    res = []
    while n:
      n, r = divmod(n, b)
      if r < 0: n += 1; r -= b
      res.append(r)
    return res



class Combinatorics:
  @classmethod
  @lru_cache(maxsize=None)
  def choose(cls, n, r, mod=None):
    if r > n or r < 0: return 0
    if r == 0: return 1
    res = cls.choose(n-1,r,mod) + cls.choose(n-1,r-1,mod)
    if mod: res %= mod
    return res 

  class CombinationsMod:
    def __init__(self, n=2*10**6, mod=MOD):
      self.__mod = mod
      self.__generate_fac_ifac(n)

    def __call__(self, n, r): return self.__choose(n, r)

    def __choose(self, n, r):
      p = self.__mod
      return self.__fac[n] * self.__ifac[r] % p * self.__ifac[n-r] % p

    def __cumprod(self, a):
      p = self.__mod
      l = len(a); sql = int(np.sqrt(l)+1)
      a = np.resize(a, sql**2).reshape(sql, sql)
      for i in range(sql-1): a[:, i+1] *= a[:, i]; a[:, i+1] %= p
      for i in range(sql-1): a[i+1] *= a[i, -1]; a[i+1] %= p
      return np.ravel(a)[:l]  

    def __generate_fac_ifac(self, n):
      p = self.__mod
      if using_numpy:
        fac = np.arange(n+1); fac[0] = 1; fac = self.__cumprod(fac)
        ifac = np.arange(n+1, 0, -1); ifac[0] = pow(int(fac[-1]), p-2, p)
        ifac = self.__cumprod(ifac)[n::-1]
      else:
        fac = [None]*(n+1); fac[0] = 1
        for i in range(n): fac[i+1] = fac[i]*(i+1)%p
        ifac = [None]*(n+1); ifac[n] = pow(fac[n], p-2, p)
        for i in range(n, 0, -1): ifac[i-1] = ifac[i]*i%p
      self.__fac, self.__ifac = fac, ifac 
    
    def make_nchoose_table(self, n):
      p = self.__mod
      r = len(self.__fac)-1
      if using_numpy:
        n_choose = np.arange(n+1, n-r, -1); n_choose[0] = 1
        n_choose = self.__cumprod(n_choose)*self.__ifac%p
      else:
        n_choose = [None]*(r+1); n_choose[0] = 1
        for i in range(r): n_choose[i+1] = n_choose[i]*(n-i)%p
        for i in range(1,r+1): n_choose[i] = n_choose[i]*self.__ifac[i]%p
      return n_choose

  @classmethod
  def permutations(cls, a, r=None, i=0):
    a = list(a); n = len(a)
    if r is None: r = n
    res = []
    if r > n or i > r: return res
    if i == r: return [tuple(a[:r])]
    for j in range(i, n): a[i],a[j] = a[j],a[i]; res += cls.permutations(a, r, i+1)
    return res
  
  @staticmethod 
  def combinations(a, r):
    a = tuple(a)
    n = len(a)
    if r > n: return
    indices = list(range(r))
    yield a[:r]
    while True:
      for i in range(r-1, -1, -1):
        if indices[i] != i+n-r: break
      else: return
      indices[i] += 1
      for j in range(i+1, r): indices[j] = indices[j-1]+1
      yield tuple(a[i] for i in indices)



class DP:
  @staticmethod 
  def LIS(a):
    res = [inf] * len(a)
    for x in a: res[bi_l(res, x)] = x
    return res


class String:
  @staticmethod
  def z_algorithm(s):
    n = len(s)
    a = [0] * n; a[0] = n
    l = r = -1
    for i in range(1, n):
      if r >= i: a[i] = min(a[i-l], r-i)
      while i + a[i] < n and s[i+a[i]] == s[a[i]]: a[i] += 1
      if i+a[i] >= r: l, r = i, i+a[i]
    return a


class GeometryTopology:
  class Graph:
    class __Edge:
      def __init__(self, weight=1, capacity=1, **args):
        self.weight = weight
        self.capacity = capacity
    
    class __Node:
      def __init__(self, **args):
        pass

    def __init__(self, n=0):
      self.__N = n
      self.__nodes = [None] * n
      self.__edges = [{} for _ in range(n)]

    def add_node(self, v, **args):
      self.__nodes[v] = self.__Node(**args)

    def add_edge(self, u, v, **args):
      
      self.__edges[u][v] = self.__Edge(**args)

    def get_size(self): return self.__N

    def bfs(self, src=0):
      assert 0 <= src < self.__N
      self.__depth = self.__lv = lv = [None]*self.__N; lv[src] = 0 
      self.__dist = dist = [inf]*self.__N; dist[src] = 0
      self.__parent = par = [None]*self.__N; par[src] = src
      q = deque([src])
      while q:
        u = q.popleft()
        for v, e in self.__edges[u].items():
          if e.capacity == 0 or lv[v] is not None: continue
          lv[v] = lv[u] + 1
          dist[v] = dist[u] + e.weight 
          par[v] = u
          q.append(v)
      return lv 
 
    def dinic(self, src, sink):
      def flow_to_sink(u, flow_in):
        if u == sink: return flow_in
        flow = 0
        for v, e in self.__edges[u].items():
          if e.capacity == 0 or self.__lv[v] <= self.__lv[u]: continue 
          f = flow_to_sink(v, min(flow_in, e.capacity))
          if not f: continue
          self.__edges[u][v].capacity -= f
          if u in self.__edges[v]: self.__edges[v][u].capacity += f
          else: self.add_edge(v, u, capacity=f)
          flow_in -= f
          flow += f
        return flow

      flow = 0
      while True:
        self.bfs(src)
        if self.__lv[sink] is None: return flow
        flow += flow_to_sink(src, inf)
      
    def ford_fulkerson(self):
      pass

    def push_relabel(self):
      pass

    def floyd_warshall(self):
      n = self.__N
      d = [[inf]*n for _ in range(n)]
      for u in range(n):
        d[u][u] = 0
        for v, e in self.__edges[u].items(): d[u][v] = e.weight
      for w in range(n):
        for u in range(n):
          for v in range(n):
            d[u][v] = min(d[u][v], d[u][w]+d[w][v])
      return d
    
    def dijkstra(self, src, paths_cnt=False, mod=None):
      dist = [inf] * self.__N; dist[src] = 0
      visited = [False] * self.__N
      paths = [0] * self.__N; paths[src] = 1
      q = [(0, src)]
      while q:
        d, u = heappop(q)
        if visited[u]: continue
        visited[u] = True
        for v, e in self.__edges[u].items():
          dv = d + e.weight
          if dv > dist[v]: continue
          elif dv == dist[v]:
            paths[v] += paths[u]
            if mod: paths[v] %= mod
            continue 
          paths[v], dist[v] = paths[u], dv
          heappush(q, (dv, v))
      if paths_cnt: return dist, paths 
      else: return dist

    def astar(self, src, tgt, heuristic_func):
      cost = [inf] * self.__N
      q = [(heuristic_func(src, tgt), 0, src)]
      while q:
        _, c, u = heappop(q)
        if u == tgt: return c
        if cost[u] != inf: continue 
        cost[u] = c
        for v, e in self.__edges[u].items():
          if cost[v] != inf: continue
          h = heuristic_func(v, tgt)
          nc = c + e.weight
          heappush(q, (h+nc, nc, v))        
      return inf
    
    
    def find_ancestors(self): 
      self.__ancestors = ancestors = [self.__parent]
      for _ in range(max(self.__depth).bit_length()):
        ancestors.append([ancestors[-1][u] for u in ancestors[-1]])


    def find_dist(self, u, v):
      return self.__dist[u]+self.__dist[v]-2*self.__dist[self.__find_lca(u, v)]

    
    def __find_lca(self, u, v):
      du, dv = self.__depth[u], self.__depth[v]
      if du > dv:
        u, v = v, u 
        du, dv = dv, du 
      
      d = dv - du
      for i in range(d.bit_length()): 
        if d>>i&1: v = self.__ancestors[i][v]
      if v == u: return v

      for i in range(du.bit_length()-1, -1, -1): 
        nu, nv = self.__ancestors[i][u], self.__ancestors[i][v]
        if nu == nv: continue 
        u, v = nu, nv 
      
      return self.__ancestors[0][u]
  
  @staticmethod
  def triangle_area(p0, p1, p2, signed=False):
    x1, y1, x2, y2 = p1[0]-p0[0], p1[1]-p0[1], p2[0]-p0[0], p2[1]-p0[1]
    return (x1*y2 - x2*y1)/2 if signed else abs(x1*y2 - x2*y1)/2 
  
  @classmethod
  def intersect(cls, seg1, seg2):
    (p1, p2), (p3, p4) = seg1, seg2
    t1 = cls.triangle_area(p1, p2, p3, signed=True)
    t2 = cls.triangle_area(p1, p2, p4, signed=True)
    t3 = cls.triangle_area(p3, p4, p1, signed=True)
    t4 = cls.triangle_area(p3, p4, p2, signed=True)
    return (t1*t2<0) & (t3*t4<0)
  
  class UnionFind: 
    def __init__(self, n=10**6):
      self.parent = list(range(n))
      self.rank = [0] * n 
      self.size = [1] * n 

    def find(self, u):
      if self.parent[u] == u: return u
      self.parent[u] = self.find(self.parent[u])
      return self.parent[u]

    def unite(self, u, v):
      u, v = self.find(u), self.find(v)
      if u == v: return 
      if self.rank[u] < self.rank[v]: u,v = v,u
      self.parent[v] = u 
      self.size[u] += self.size[v]
      self.rank[u] = max(self.rank[u], self.rank[v]+1)
      
def cumxor(a): return reduce(xor, a, 0)
def cumor(a): return reduce(or_, a, 0)

def bit_count(n):
  cnt = 0
  while n: cnt += n&1; n >>= 1 
  return cnt


class AtCoder:
  class ABC001:
    @staticmethod
    def a():
      h1, h2 = map(int, sys.stdin.read().split()); print(h1-h2)
    
    @staticmethod 
    def d():
      def to_minuites(x):
        q, r = divmod(x, 100)
        return 60*q + r

      def to_hmform(x):
        q, r = divmod(x, 60)
        return 100*q + r

      n = int(sys.stdin.readline().rstrip())
      term = [0] * 2001
      for _ in range(n):
        s, e = map(to_minuites, map(int, sys.stdin.readline().rstrip().split('-')))
        s = s//5 * 5 
        e = (e+4)//5 * 5
        term[s] += 1
        term[e+1] -= 1
      for i in range(2000):
        term[i+1] += term[i]
      
      res = []
      raining = False
      for i in range(2001):
        if term[i]:
          if not raining: 
            s = i
            raining = True
        elif raining:
          res.append((s, i-1))
          raining = False
      for s, e in res:
        print(f'{to_hmform(s):04}-{to_hmform(e):04}')
          
      

      
  class ABC002:
    @staticmethod
    def a():
      print(max(map(int, sys.stdin.readline().split())))

    @staticmethod 
    def b():
      vowels = set('aeiou')
      print(''.join([c for c in sys.stdin.readline().rstrip() if c not in vowels]))
    
    @staticmethod 
    def c():
      print(GeometryTopology.triangle_area(*map(int, sys.stdin.readline().split())))

    @staticmethod 
    def d():
      n, m = map(int, sys.stdin.readline().split())
      edges = set((x-1, y-1) for x, y in zip(*[map(int, sys.stdin.read().split())]*2))
      print(max(len(s) for i in range(1, 1<<n) for s in [[j for j in range(n) if i>>j&1]] if all((x, y) in edges for x, y in itertools.combinations(s, 2))))

    @staticmethod
    def d_2():
      n, m = map(int, sys.stdin.readline().split())
      relations = [1<<i for i in range(n)]
      for x, y in zip(*[map(int, sys.stdin.read().split())]*2):
        relations[x] |= 1<<(y-1); relations[y] |= 1<<(x-1)
      res = 0
      for i in range(1<<n):
        s, cnt = (1<<n)-1, 0
        for j in range(n):
          if i>>j & 1: t &= relations[j] | 1<<j; cnt += 1
        if s&i == i: res = max(res, cnt)
      print(res)

  class ABC003:
    @staticmethod
    def a():
      print((int(sys.stdin.readline().rstrip())+1)*5000)
    @staticmethod
    def b():
      atcoder = set('atcoder')
      s, t = sys.stdin.read().split()
      print(all(s[i]==t[i] or s[i]=='@' and t[i] in atcoder or t[i]=='@' and s[i] in atcoder for i in range(len(s))) and 'You can win' or 'You will lose')

    @staticmethod
    def c():
      n, k, *r = map(int, sys.stdin.read().split()); print(reduce(lambda x, y: (x+y)/2, sorted(r)[-k:], 0))

  class ABC004:
    @staticmethod
    def a():
      print(int(sys.stdin.readline().rstrip())*2)
    @staticmethod
    def b():
      for l in [sys.stdin.readline().rstrip() for _ in range(4)][::-1]: print(l[::-1])
    @staticmethod
    def c():
      n = int(sys.stdin.readline().rstrip())%30
      res = list(range(1, 7))
      for i in range(n): i %= 5; res[i], res[i+1] = res[i+1], res[i]
      print(*res, sep='')



  class ABC005:
    @staticmethod
    def a():
      x, y = map(int, sys.stdin.readline().split())
      print(y//x)
    @staticmethod
    def b():
      n, *t = map(int, sys.stdin.read().split())
      print(min(t))
    @staticmethod
    def c():
      t = int(sys.stdin.readline().rstrip())
      n = int(sys.stdin.readline().rstrip())
      a = [int(x) for x in sys.stdin.readline().split()]
      m = int(sys.stdin.readline().rstrip())
      b = [int(x) for x in sys.stdin.readline().split()]
      i = 0
      for p in b:
        if i == n: print('no'); return 
        while p-a[i] > t:
          i += 1
          if i == n: print('no'); return 
        if a[i] > p: print('no'); return 
        i += 1
      print('yes')
    @staticmethod
    def d():
      n = int(sys.stdin.readline().rstrip())
      d = np.array([sys.stdin.readline().split() for _ in range(n)], np.int64)
      s = d.cumsum(axis=0).cumsum(axis=1)
      s = np.pad(s, 1)
      max_del = np.zeros((n+1, n+1), dtype=np.int64)
      for y in range(1, n+1):
        for x in range(1, n+1):
          max_del[y, x] = np.amax(s[y:n+1, x:n+1] - s[0:n-y+1, x:n+1] - s[y:n+1, 0:n-x+1] + s[0:n-y+1, 0:n-x+1])
      res = np.arange(n**2+1)[:, None]
      i = np.arange(1, n+1)
      res = max_del[i, np.minimum(res//i, n)].max(axis=1)
      q = int(sys.stdin.readline().rstrip())
      p = np.array(sys.stdin.read().split(), dtype=np.int64)
      print(*res[p], sep='\n')


  class ABC006:
    @staticmethod
    def a():
      n = sys.stdin.readline().rstrip()
      if '3' in n: print('YES')
      elif int(n)%3 == 0: print('YES')
      else: print('NO')

    @staticmethod
    def b():
      mod = 10007
      a = np.eye(N=3, k=-1, dtype=np.int64); a[0] = 1
      n = int(sys.stdin.readline().rstrip())
      a = Algebra.matrix_pow(a, n-1, mod)
      print(a[2][0])


    @staticmethod
    def c():
      n, m = map(int, sys.stdin.readline().split())
      cnt = [0, 0, 0]
      if m == 1: cnt = [-1, -1, -1]
      else:
        if m & 1: m -= 3; cnt[1] += 1; n -= 1
        cnt[2] = m//2 - n 
        cnt[0] = n - cnt[2]
      if cnt[0]<0 or cnt[1]<0 or cnt[2]<0: print(-1, -1, -1)
      else: print(*cnt, sep=' ')

    @staticmethod
    def d():
      n, *c = map(int, sys.stdin.read().split())
      lis = [inf]*n 
      for x in c: lis[bi_l(lis, x)] = x 
      print(n - bi_l(lis, inf))

  class ABC007:
    @staticmethod
    def a():
      n = int(sys.stdin.readline().rstrip())
      print(n-1)
    @staticmethod
    def b():
      s = sys.stdin.readline().rstrip()
      if s == 'a': print(-1)
      else: print('a')
    @staticmethod
    def c():
      r, c = map(int, sys.stdin.readline().split())
      sy, sx = map(int, sys.stdin.readline().split())
      gy, gx = map(int, sys.stdin.readline().split())
      sy -= 1; sx -=1; gy -= 1; gx -= 1
      maze = [sys.stdin.readline().rstrip() for _ in range(r)]
      queue = deque([(sy, sx)])
      dist = np.full((r, c), np.inf); dist[sy, sx] = 0
      while queue:
        y, x = queue.popleft()
        for i, j in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
          i += y; j += x
          if maze[i][j] == '
          dist[i, j] = dist[y, x] + 1
          queue.append((i, j))
      print(int(dist[gy, gx]))
    @staticmethod
    def d():
      ng = set([4, 9])
      def count(d):
        return d if d<=4 else d-1
      def f(n):
        x = [int(d) for d in str(n)]
        flg = True
        dp = 0
        for d in x:
          dp = dp*8 + flg*count(d)
          if d in ng: flg = False
        return n-(dp+flg)
      a, b = map(int, sys.stdin.readline().split())
      print(f(b) - f(a-1))
          
  class ABC008:
    @staticmethod
    def a():
      s, t = map(int, sys.stdin.readline().split())
      print(t-s+1)
    @staticmethod
    def b():
      n, *s = sys.stdin.read().split()
      res = defaultdict(int)
      for name in s: res[name] += 1
      print(sorted(res.items(), key=lambda x: x[1])[-1][0])
    @staticmethod
    def c():
      n, *a = map(int, sys.stdin.read().split())
      a = np.array(a)
      c = n - np.count_nonzero(a[:, None]%a, axis=1)
      print(np.sum((c+1)//2/c))

    @staticmethod 
    def d():
      w, h, n, *xy = map(int, sys.stdin.read().split())
      *xy, = zip(*([iter(xy)]*2))

      @lru_cache(maxsize=None)
      def count(x1, y1, x2, y2):
        res = 0
        for x, y in xy:
          if not (x1 <= x <= x2 and y1 <= y <= y2): continue
          cnt = (x2-x1) + (y2-y1) + 1
          cnt += count(x1, y1, x-1, y-1)
          cnt += count(x1, y+1, x-1, y2)
          cnt += count(x+1, y1, x2, y-1)
          cnt += count(x+1, y+1, x2, y2)
          res = max(res, cnt)
        return res 
      print(count(1, 1, w, h))




  class ABC172:
    @staticmethod
    def a():
      a = int(sys.stdin.readline().rstrip()); print(a*(1+a+a**2))
    
    @staticmethod
    def b():
      s, t = sys.stdin.read().split(); print(sum(s[i]!=t[i] for i in range(len(s))))
    
    @staticmethod
    def c():
      n, m, k = map(int, sys.stdin.readline().split())
      a = [0] + [int(x) for x in sys.stdin.readline().split()]
      b = [int(x) for x in sys.stdin.readline().split()]
      *sa, = itertools.accumulate(a)
      *sb, = itertools.accumulate(b)
      res = 0
      for i in range(n+1):
        r = k - sa[i]
        if r < 0: break 
        res = max(res, i+bi_r(sb, r))
      print(res)

    @staticmethod 
    def d():
      n = int(sys.stdin.readline().rstrip())
      f = np.zeros(n+1, dtype=np.int64)
      for i in range(1, n+1):
        f[i::i] += 1
      print((np.arange(1, n+1)*f[1:]).sum())


  class ABC173:
    @staticmethod
    def a():
      n = int(sys.stdin.readline().rstrip())
      charge = (n+999)//1000 * 1000 - n
      print(charge)
    
    @staticmethod
    def b():
      n, *s = sys.stdin.read().split() 
      c = Counter(s)
      for v in 'AC, WA, TLE, RE'.split(', '):
        print(f'{v} x {c[v]}')
    

    @staticmethod
    def c():
      h, w, k = map(int, sys.stdin.readline().split())
      c = [sys.stdin.readline().rstrip() for _ in range(h)]
      tot = 0
      for i in range(1<<h):
        for j in range(1<<w):
          cnt = 0
          for y in range(h):
            for x in range(w):
              if i>>y & 1 or j>>x & 1:
                continue 
              cnt += c[y][x] ==  '#'
          tot += cnt == k
      print(tot)

    @staticmethod
    def d():
      n, *a = map(int, sys.stdin.read().split())
      a.sort(reverse=True)
      res = a[0] + sum(a[1:1+(n-2)//2])*2 + a[1+(n-2)//2]*(n & 1)
      print(res)
    
    @staticmethod
    def e():
      MOD = 10**9+7
      n, k, *a = map(int, sys.stdin.read().split())
      minus = [x for x in a if x < 0]
      plus = [x for x in a if x > 0]
      if len(plus) + len(minus)//2*2 >= k: 
        *minus, = map(abs, minus)
        minus.sort(reverse=True)
        plus.sort(reverse=True)
        cand = []
        if len(minus)&1: minus = minus[:-1]
        for i in range(0, len(minus)-1, 2):
          cand.append(minus[i]*minus[i+1]%MOD)
        if k & 1:
          res = plus[0]
          plus = plus[1:]
        else:
          res = 1
        if len(plus)&1: plus = plus[:-1]
        for i in range(0, len(plus)-1, 2):
          cand.append(plus[i]*plus[i+1]%MOD)
        cand.sort(reverse=True)
        for x in cand[:k//2]:
          res *= x
          res %= MOD 
        print(res)
      elif 0 in a:
        print(0)
      else:
        cand = sorted(map(abs, a))
        res = 1
        for i in range(k):
          res *= cand[i]
          res %= MOD
        res = MOD - res
        print(res)
        pass
 

  class ABC174:
    @staticmethod
    def a():
      print('Yes' if int(sys.stdin.readline().rstrip())>=30 else 'No')




  class ABC178:
    @staticmethod 
    def a(): pass 
    
    @staticmethod 
    def b(): pass 

    @staticmethod 
    def c(): pass 

    @staticmethod 
    def d():
      s = int(sys.stdin.readline().rstrip())
      if s == 0: print(1); return
      elif s == 1: print(0); return
      c = np.eye(3, k=-1, dtype=np.int64)
      c[0, 0] = c[0, 2] = 1 
      a = np.array([0, 0, 1])
      print(Algebra.dot(Algebra.matrix_pow(c, s-2), a)[0])

  class ABC179:
    @staticmethod 
    def a():
      s = sys.stdin.readline().rstrip()
      print(s+'s' if s[-1]!='s' else s+'es')

    @staticmethod 
    def b():
      n, *d = map(int, sys.stdin.read().split())
      d = np.array(d).reshape(n, 2).T
      d = np.equal(d[0], d[1]).astype(int)
      dd = d.copy()
      dd[1:] += d[:-1]
      dd[:-1] += d[1:]
      print('Yes' if (dd>=3).any() else 'No')
      


    @staticmethod 
    def c():
      n = int(sys.stdin.readline().rstrip())
      print(sum(len(NumberTheory.find_divisors(i)) for i in range(1, n)))

    @staticmethod 
    def d():
      mod = 998244353
      n, k, *lr = map(int, sys.stdin.read().split())
      l, r = np.array(lr).reshape(k, -1).T
      @njit((i8, i8[:], i8[:]), cache=True)
      def solve(n, l, r):
        res = np.zeros(n*2, dtype=np.int64); res[0], res[1] = 1, -1
        for i in range(n-1):
          res[i+1] = (res[i+1]+res[i]) % mod
          res[i+l] = (res[i+l]+res[i]) % mod
          res[i+r+1] = (res[i+r+1]-res[i]) % mod
        print(res[n-1])
      solve(n, l, r)
    
    @staticmethod 
    def e():
      n, x, m = map(int, sys.stdin.readline().split())
      res = [-1 for _ in range(m)]
      s = 0
      loop = np.zeros(m, dtype=np.int64)
      for i in range(m+1):
        if i==n: print(s); return 
        if res[x] != -1:
          l, loop = i-res[x], loop[res[x]:i]
          q, r = divmod(n-i, l)
          print(s+q*loop.sum()+loop[:r].sum()); return
        res[x], loop[i] = i, x
        s += x; x = x**2 % m 


  class ABC180:
    @staticmethod 
    def a():
      n, a, b = map(int, sys.stdin.readline().split())
      print(n-a+b)
      
    @staticmethod 
    def b():
      n, *x = map(int, sys.stdin.read().split())
      x = np.absolute(np.array(x))
      print(x.sum())
      print(np.sqrt((x**2).sum()))
      print(x.max())

    @staticmethod 
    def c():
      n = int(sys.stdin.readline().rstrip())
      div = NumberTheory.find_divisors(n)
      print(*div, sep='\n')

    @staticmethod 
    def d():
      x, y, a, b = map(int, sys.stdin.readline().split())
      cnt = 0
      while x*a <= x+b:
        x *= a 
        if x >= y:
          print(cnt); return 
        cnt += 1
      cnt += (y-x-1) // b 
      print(cnt) 

    @staticmethod
    def e():
      n, *xyz = map(int, sys.stdin.read().split())
      
      xyz = list(zip(*[iter(xyz)] * 3))
      dist = [[0] * n for _ in range(n)]
      for i in range(n):
        a, b, c = xyz[i]
        for j in range(n):
          p, q, r = xyz[j]
          dist[i][j] = abs(p-a) + abs(q-b) + max(0, r-c) 

      dp = [[inf] * n for _ in range(1<<n)]
      dp[0][0] = 0 
      for s in range(1<<n):
        for i in range(n):
          t = s|(1<<i)
          for j in range(n):
            dp[t][i] = min(dp[t][i], dp[s][j]+dist[j][i])
      print(dp[-1][0])
      
          

    @staticmethod 
    def f(): 
      n, m, l = map(int, sys.stdin.readline().split())
      c = Combinatorics.CombinationsMod(n, MOD)
      path = np.zeros(n+1, dtype=np.int64); path[1] = path[2] = 1
      for i in range(3, n+1): path[i] = path[i-1]*i%MOD
      cycle = np.zeros(n+1, dtype=np.int64); cycle[1:] = path[:-1]
      dp = np.zeros((n+1, m+1), dtype=np.int64)
      def f(l):
        dp[:,:] = 0; dp[0,0] = 1
        for i in range(n):
          for j in range(m+1):
            k = np.arange(1, min(l, n-i, m-j+1)+1)
            dp[i+k, j+k-1] += dp[i, j]*c(n-i-1, k-1)%MOD*path[k]%MOD 
            dp[i+k, j+k-1] %= MOD 
            k = np.arange(2, min(l, n-i, m-j)+1)
            dp[i+k, j+k] += dp[i, j]*c(n-i-1, k-1)%MOD*cycle[k]%MOD 
            dp[i+k, j+k] %= MOD 
        return dp[n, m]

      print((f(l)-f(l-1))%MOD)

    @staticmethod 
    def f_2(): 
      n, m, l = map(int, sys.stdin.readline().split())
      c = Combinatorics.CombinationsMod(n, MOD)
      path = [0] * (n+1); path[1] = path[2] = 1
      for i in range(3, n+1): path[i] = path[i-1]*i%MOD 
      cycle = [0] + path[:-1]
      def f(l):
        dp = [[0]*(m+1) for _ in range(n+1)]; dp[0][0] = 1
        for i in range(n):
          for j in range(m+1):
            for k in range(1, min(l, n-i, m-j+1)+1):
              dp[i+k][j+k-1] += dp[i][j]*c(n-i-1, k-1)%MOD*path[k]%MOD 
              dp[i+k][j+k-1] %= MOD 
            for k in range(1, min(l, n-i, m-j)+1):
              dp[i+k][j+k] += dp[i][j]*c(n-i-1, k-1)%MOD*cycle[k]%MOD 
              dp[i+k][j+k] %= MOD

        return dp[n][m]
      
      print((f(l)-f(l-1))%MOD)
  
      

  class ACL001:
    @staticmethod 
    def a():
      n, *xy = map(int, sys.stdin.read().split())
      *xy, = zip(*[iter(xy)]*2)
      print(xy)
      pass

  

  class TDPC:
    @staticmethod
    def t():
      pass




  class MSolutions2020:
    @staticmethod
    def a():
      x = int(sys.stdin.readline().rstrip())
      x -= 400
      print(8-x//200)
    
    @staticmethod
    def b():
      r, g, b, k = map(int, sys.stdin.read().split())
      while k and g <= r:
        g *= 2
        k -= 1
      while k and b <= g:
        b *= 2
        k -= 1
      print('Yes' if r < g < b else 'No')
    
    @staticmethod
    def c():
      n, k, *a = map(int, sys.stdin.read().split())
      for i in range(k, n):
        print('Yes' if a[i] > a[i-k] else 'No')
    
    @staticmethod
    def d():
      n, *a = map(int, sys.stdin.read().split())
      a += [-1]
      m = 1000
      s = 0
      for i in range(n):
        if a[i+1] == a[i]: continue 
        elif a[i+1] > a[i]:
          cnt = m//a[i]
          m -= a[i]*cnt 
          s += cnt 
        else:
          m += a[i]*s
          s = 0
      print(m)



class Codeforces:
  class cr676div2:
    @staticmethod 
    def a():
      t = int(sys.stdin.readline().rstrip())
      for _ in range(t):
        a, b = map(int, sys.stdin.readline().split())
        print(a^b)

    @staticmethod 
    def b(): pass 


    @staticmethod 
    def c():
      pass 

class ProjectEuler:
  @staticmethod
  def p1():
    def f(n, x):
      return (x + n//x*x) * (n//x) // 2
    n = 1000
    ans = f(n-1, 3)+f(n-1, 5)-f(n-1, 15)
    print(ans)

  @staticmethod
  def p2():
    fib = [1, 2]
    while fib[-1] < 4*10**6:
      fib.append(fib[-1]+fib[-2])
    print(sum(fib[1:-1:3]))

  @staticmethod
  def p3():
    pn = NumberTheory.PrimeNumbers()
    res = pn.factorize(600851475143)
    print(max(res.keys()))

  @staticmethod
  def p4():
    def is_palindrome(n):
      n = str(n)
      return n == n[::-1]
    cand = []
    for a in range(100, 1000):
      for b in range(a, 1000):
        n = a*b 
        if is_palindrome(n): cand.append(n)
    print(max(cand))

  @staticmethod
  def p5():
    pn = NumberTheory.PrimeNumbers()
    res = defaultdict(int)
    for i in range(1, 21):
      for p, c in pn.factorize(i).items():
        res[p] = max(res[p], c)
    ans = 1
    for p, c in res.items(): ans *= pow(p, c)
    print(ans)

  @staticmethod
  def p6():
    a = np.arange(101)
    b = np.cumsum(a**2)
    a = a.cumsum()
    print(a[100]**2 - b[100])

  @staticmethod
  def p7():
    nt = NumberTheory.PrimeNumbers()
    print(sorted(nt)[10000])
  @staticmethod
  def p8():
    n = '7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450'
    n = [int(d) for d in list(n)]
    res = 0
    for i in range(988):
      x = 1
      for j in range(13):
        x *= n[i+j]
      res = max(res, x)
    print(res)
  @staticmethod
  def p9():
    for a in range(1, 997):
      for b in range(a, 998-a):
        c = 1000 - a - b
        if a**2 + b**2 == c**2:
          print(a*b*c)
          return
  @staticmethod
  def p10():
    pn = NumberTheory.PrimeNumbers(2*10**6+1)
    print(sum(pn))
  @staticmethod
  def p11():
    grid = '08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48'
    print(grid)
  
  pass 

class Yukicoder:
  def __init__(self):
    pass

  def __call__(self):
    print(1)


if __name__ == '__main__':
  
  Codeforces.cr676div2.a()
