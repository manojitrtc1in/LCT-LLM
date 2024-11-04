import sys
from math import gcd,sqrt,ceil,log2
from collections import defaultdict,Counter,deque
from bisect import bisect_left,bisect_right
import math
sys.setrecursionlimit(2*10**5+10)
import heapq
from itertools import permutations







import os
import sys
from io import BytesIO, IOBase

BUFSIZE = 8192

aa='abcdefghijklmnopqrstuvwxyz'
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


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")




def get_sum(bit,i):
    s = 0

    i+=1
    while i>0:
        s+=bit[i]
        i-=i&(-i)

    return s

def update(bit,n,i,v):
    i+=1

    while i<=n:
        bit[i]+=v
        i+=i&(-i)


def modInverse(b,m):
    g = math.gcd(b, m)
    if (g != 1):
        return -1
    else:
        return pow(b, m - 2, m)

def primeFactors(n):

    sa = []
    
    while n % 2 == 0:
        sa.append(2)
        n = n // 2


    for i in range(3,int(math.sqrt(n))+1,2):


        while n % i== 0:
            sa.append(i)
            n = n // i

    
    if n > 2:
        sa.append(n)
    return sa


def seive(n):

    pri = [True]*(n+1)
    p = 2
    while p*p<=n:

        if pri[p] == True:

            for i in range(p*p,n+1,p):
                pri[i] = False

        p+=1

    return pri

def check_prim(n):

    if n<0:
        return False
    for i in range(2,int(sqrt(n))+1):
        if n%i == 0:
            return False

    return True


def getZarr(string, z):
    n = len(string)

    
    
    l, r, k = 0, 0, 0
    for i in range(1, n):

        
        
        if i > r:
            l, r = i, i

            
            
            
            
            
            while r < n and string[r - l] == string[r]:
                r += 1
            z[i] = r - l
            r -= 1
        else:

            
            
            k = i - l

            
            
            
            
            if z[k] < r - i + 1:
                z[i] = z[k]

                
            
            else:

                
                l = i
                while r < n and string[r - l] == string[r]:
                    r += 1
                z[i] = r - l
                r -= 1

def search(text, pattern):

    
    concat = pattern + "$" + text
    l = len(concat)


    z = [0] * l
    getZarr(concat, z)

    ha = []
    for i in range(l):


        if z[i] == len(pattern):
            ha.append(i - len(pattern) - 1)


    return ha









































































def mergeIntervals(arr):

    
    
    arr.sort(key = lambda x: x[0])

    
    m = []
    s = -10000
    max = -100000
    for i in range(len(arr)):
        a = arr[i]
        if a[0] > max:
            if i != 0:
                m.append([s,max])
            max = a[1]
            s = a[0]
        else:
            if a[1] >= max:
                max = a[1]

    
    
    
    

    if max != -100000 and [s, max] not in m:
        m.append([s, max])
    return m
class SortedList:
    def __init__(self, iterable=[], _load=200):
        """Initialize sorted list instance."""
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self._list_lens = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self._fen_tree = []
        self._rebuild = True

    def _fen_build(self):
        """Build a fenwick tree instance."""
        self._fen_tree[:] = self._list_lens
        _fen_tree = self._fen_tree
        for i in range(len(_fen_tree)):
            if i | i + 1 < len(_fen_tree):
                _fen_tree[i | i + 1] += _fen_tree[i]
        self._rebuild = False

    def _fen_update(self, index, value):
        """Update `fen_tree[index] += value`."""
        if not self._rebuild:
            _fen_tree = self._fen_tree
            while index < len(_fen_tree):
                _fen_tree[index] += value
                index |= index + 1

    def _fen_query(self, end):
        """Return `sum(_fen_tree[:end])`."""
        if self._rebuild:
            self._fen_build()

        _fen_tree = self._fen_tree
        x = 0
        while end:
            x += _fen_tree[end - 1]
            end &= end - 1
        return x

    def _fen_findkth(self, k):
        """Return a pair of (the largest `idx` such that `sum(_fen_tree[:idx]) <= k`, `k - sum(_fen_tree[:idx])`)."""
        _list_lens = self._list_lens
        if k < _list_lens[0]:
            return 0, k
        if k >= self._len - _list_lens[-1]:
            return len(_list_lens) - 1, k + _list_lens[-1] - self._len
        if self._rebuild:
            self._fen_build()

        _fen_tree = self._fen_tree
        idx = -1
        for d in reversed(range(len(_fen_tree).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(_fen_tree) and k >= _fen_tree[right_idx]:
                idx = right_idx
                k -= _fen_tree[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        """Delete value at the given `(pos, idx)`."""
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens

        self._len -= 1
        self._fen_update(pos, -1)
        del _lists[pos][idx]
        _list_lens[pos] -= 1

        if _list_lens[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del _list_lens[pos]
            del _mins[pos]
            self._rebuild = True

    def _loc_left(self, value):
        """Return an index pair that corresponds to the first position of `value` in the sorted list."""
        if not self._len:
            return 0, 0

        _lists = self._lists
        _mins = self._mins

        lo, pos = -1, len(_lists) - 1
        while lo + 1 < pos:
            mi = (lo + pos) >> 1
            if value <= _mins[mi]:
                pos = mi
            else:
                lo = mi

        if pos and value <= _lists[pos - 1][-1]:
            pos -= 1

        _list = _lists[pos]
        lo, idx = -1, len(_list)
        while lo + 1 < idx:
            mi = (lo + idx) >> 1
            if value <= _list[mi]:
                idx = mi
            else:
                lo = mi

        return pos, idx

    def _loc_right(self, value):
        """Return an index pair that corresponds to the last position of `value` in the sorted list."""
        if not self._len:
            return 0, 0

        _lists = self._lists
        _mins = self._mins

        pos, hi = 0, len(_lists)
        while pos + 1 < hi:
            mi = (pos + hi) >> 1
            if value < _mins[mi]:
                hi = mi
            else:
                pos = mi

        _list = _lists[pos]
        lo, idx = -1, len(_list)
        while lo + 1 < idx:
            mi = (lo + idx) >> 1
            if value < _list[mi]:
                idx = mi
            else:
                lo = mi

        return pos, idx

    def add(self, value):
        """Add `value` to sorted list."""
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        _list_lens = self._list_lens

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self._fen_update(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            _list_lens[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                _list_lens.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                _list_lens[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            _list_lens.append(1)
            self._rebuild = True

    def discard(self, value):
        """Remove `value` from sorted list if it is a member."""
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_right(value)
            if idx and _lists[pos][idx - 1] == value:
                self._delete(pos, idx - 1)

    def remove(self, value):
        """Remove `value` from sorted list; `value` must be a member."""
        _len = self._len
        self.discard(value)
        if _len == self._len:
            raise ValueError('{0!r} not in list'.format(value))

    def pop(self, index=-1):
        """Remove and return value at `index` in sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def bisect_left(self, value):
        """Return the first index to insert `value` in the sorted list."""
        pos, idx = self._loc_left(value)
        return self._fen_query(pos) + idx

    def bisect_right(self, value):
        """Return the last index to insert `value` in the sorted list."""
        pos, idx = self._loc_right(value)
        return self._fen_query(pos) + idx

    def count(self, value):
        """Return number of occurrences of `value` in the sorted list."""
        return self.bisect_right(value) - self.bisect_left(value)

    def __len__(self):
        """Return the size of the sorted list."""
        return self._len

    def __getitem__(self, index):
        """Lookup value at `index` in sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def __delitem__(self, index):
        """Remove value at `index` from sorted list."""
        pos, idx = self._fen_findkth(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def __contains__(self, value):
        """Return true if `value` is an element of the sorted list."""
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def __iter__(self):
        """Return an iterator over the sorted list."""
        return (value for _list in self._lists for value in _list)

    def __reversed__(self):
        """Return a reverse iterator over the sorted list."""
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def __repr__(self):
        """Return string representation of sorted list."""
        return 'SortedList({0})'.format(list(self))

def ncr(n, r, p):

    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p


def sol(n):

    seti = set()
    for i in range(1,int(sqrt(n))+1):
        if n%i == 0:
            seti.add(n//i)
            seti.add(i)


    return seti
def lcm(a,b):

    return (a*b)//gcd(a,b)










































def moore_voting(l):

    count1 = 0
    count2 = 0
    first = 10**18
    second = 10**18
    n = len(l)
    for i in range(n):

        if l[i] == first:
            count1+=1
        elif l[i] == second:
            count2+=1

        elif count1 == 0:
            count1+=1
            first = l[i]

        elif count2 == 0:
            count2+=1
            second = l[i]
        else:
            count1-=1
            count2-=1

    for i in range(n):
        if l[i] == first:
            count1+=1
        elif l[i] == second:
            count2+=1
    if count1>n//3:
        return first
    if count2>n//3:
        return second

    return -1





def find_parent(u,parent):

    if u!=parent[u]:
        parent[u] = find_parent(parent[u],parent)

    return parent[u]






def dis_union(n):


    par = [i for i in range(n+1)]
    rank = [1]*(n+1)
    k = int(input())
    for i in range(k):
        a,b = map(int,input().split())
        z1,z2 = find_parent(a,par),find_parent(b,par)
        if z1!=z2:
            par[z1] = z2
            rank[z2]+=rank[z1]


def dijkstra(n,tot,hash):


    hea = [[0,n]]
    dis = [10**18]*(tot+1)
    dis[n] = 0
    boo = defaultdict(bool)
    check = defaultdict(int)
    while hea:
        a,b = heapq.heappop(hea)

        if boo[b]:
            continue

        boo[b] = True

        for i,w in hash[b]:
            if b == 1:
              c = 0
              if (1,i,w) in nodes:
                 c = nodes[(1,i,w)]
                 del nodes[(1,i,w)]

              if dis[b]+w<dis[i]:
                dis[i] = dis[b]+w

                check[i] = c

              elif dis[b]+w == dis[i] and c == 0:
                  dis[i] = dis[b]+w
                  check[i] = c

            else:

                if dis[b]+w<=dis[i]:
                    dis[i] = dis[b]+w
                    check[i] = check[b]



            heapq.heappush(hea,[dis[i],i])

    return check

def power(x,y,p):

    res = 1
    x = x%p
    if x == 0:
        return 0

    while y>0:

        if (y&1) == 1:
            res*=x

        x = x*x
        y = y>>1

    return res













































t = int(input())
for _ in range(t):

    n,m = map(int,input().split())
    l = []
    for i in range(n):
        s = list(input())
        l.append(s)
    ans = []
    for x in range(n):
        for y in range(m):

            if x+1<n and y+1<m:
                cnt = 0
                i,j = x,y
                a,b,c,d = l[i][j],l[i+1][j],l[i][j+1],l[i+1][j+1]
                k = [a,b,c,d]
                co = [(i,j),(i+1,j),(i,j+1),(i+1,j+1)]

                if k.count('1') == 3:

                    for i in co:
                        a,b = i

                        if l[a][b] == '1':
                            l[a][b] = '0'
                            ans.append((a+1,b+1))

                elif k.count('1') == 2:
                    flag = 0
                    flag1 = 0
                    for i in co:
                        a,b = i

                        if l[a][b] == '1' and flag == 0:
                            l[a][b] = '0'
                            ans.append((a+1,b+1))
                            flag = 1
                        elif l[a][b] == '0' and flag1<2:
                            l[a][b] = '1'
                            ans.append((a+1,b+1))
                            flag1+=1

                    for i in co:
                        a,b = i
                        if l[a][b] == '1':
                            l[a][b] = '0'
                            ans.append((a+1,b+1))
                elif k.count('1') == 1:
                    flag = 0

                    for i in co:
                        a,b = i

                        if l[a][b] == '1':
                            l[a][b] = '0'
                            ans.append((a+1,b+1))
                        elif l[a][b] == '0' and flag < 2:
                            l[a][b] = '1'
                            ans.append((a+1,b+1))
                            flag+=1
                    flag = 0
                    flag1 = 0
                    for i in co:
                        a,b = i

                        if l[a][b] == '1' and flag == 0:
                            l[a][b] = '0'
                            ans.append((a+1,b+1))
                            flag = 1
                        elif l[a][b] == '0' and flag1<2:
                            l[a][b] = '1'
                            ans.append((a+1,b+1))
                            flag1+=1
                    for i in co:
                        a,b = i
                        if l[a][b] == '1':
                            l[a][b] = '0'
                            ans.append((a+1,b+1))

                elif k.count('1') == 4:

                    flag = 0

                    for i in co:
                       a,b = i

                       if l[a][b] == '1' and flag <= 2:
                          l[a][b] = '0'
                          flag+=1
                          ans.append((a+1,b+1))

                    flag = 0

                    for i in co:
                        a,b = i

                        if l[a][b] == '1':
                            l[a][b] = '0'
                            ans.append((a+1,b+1))
                        elif l[a][b] == '0' and flag < 2:
                            l[a][b] = '1'
                            ans.append((a+1,b+1))
                            flag+=1
                    flag = 0

                    flag1 = 0
                    for i in co:
                        a,b = i

                        if l[a][b] == '1' and flag == 0:
                            l[a][b] = '0'
                            ans.append((a+1,b+1))
                            flag = 1
                        elif l[a][b] == '0' and flag1<2:
                            l[a][b] = '1'
                            ans.append((a+1,b+1))
                            flag1+=1


                    for i in co:
                        a,b = i
                        if l[a][b] == '1':
                            l[a][b] = '0'
                            ans.append((a+1,b+1))

    print(len(ans)//3)
    for i in range(0,len(ans),3):
        a,b,c = ans[i],ans[i+1],ans[i+2]
        print(*a,*b,*c)





