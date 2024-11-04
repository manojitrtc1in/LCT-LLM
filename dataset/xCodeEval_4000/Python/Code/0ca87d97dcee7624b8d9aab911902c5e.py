import sys
input = lambda: sys.stdin.readline().rstrip()
import math
from heapq import heapify, heappush, heappop
from bisect import bisect_right, bisect_left
from itertools import *
from collections import *
import random
inf = float('inf')
def error(*args, sep=' ', end='\n'):
  print(*args, sep=sep, end=end, file=sys.stderr)


"Use HashSet and HashDict only if elements are int."
class HashSet(set):

  def __init__(self, *args):
    self._xor1 = random.randrange(10**16, 10**18)
    self._xor2 = random.randrange(10**16, 10**18)
    self._xor3 = random.randrange(10**16, 10**18)
    self._rad  = random.randrange(10**3 , 10**18)
    if args:
      super().__init__(map(lambda x: self._hash(x), *args))

  def _hash(self, x):
    x = x ^ self._xor1 ^ self._xor2 ^ self._xor3
    x += self._rad
    return x
  
  def _rehash(self, x):
    x -= self._rad
    x = x ^ self._xor1 ^ self._xor2 ^ self._xor3
    return x
  
  def add(self, x):
    super().add(self._hash(x))

  def discard(self, x):
    super().discard(self._hash(x))

  def remove(self, x):
    super().remove(self._hash(x))

  def __contains__(self, item):
    return super().__contains__(self._hash(item))

  def __iter__(self):
    return (self._rehash(i) for i in super().__iter__())

  def __str__(self):
    return '{' + ', '.join(sorted([str(i) for i in self.__iter__()])) + '}'

"Do not use 'ele in HashDict.keys()'. Use 'ele in HashDict'."
class HashDict():
  
  def __init__(self, *args, func=int, c=False):
    self._xor1 = random.randrange(10**10, 10**18)
    self._xor2 = random.randrange(10**10, 10**18)
    self._xor3 = random.randrange(10**10, 10**18)
    self._rad = random.randrange(10**3 , 10**18)
    if c:
      if args:
        self._dat = Counter(map(lambda x: self._hash(x), *args))
      else:
        self._dat = Counter()
    else:
      self._dat = defaultdict(func)
    self._keys = HashSet()
    self._func = func

  def _hash(self, x):
    x = x ^ self._xor1 ^ self._xor2 ^ self._xor3
    x += self._rad
    return x

  def _rehash(self, x):
    x -= self._rad
    x = x ^ self._xor1 ^ self._xor2 ^ self._xor3
    return x
  
  def __setitem__(self, key, value):
    self._dat.__setitem__(self._hash(key), value)
    self._keys.add(self._hash(key))

  def __getitem__(self, item):
    return self._dat.__getitem__(self._hash(item))

  def __delitem__(self, item):
    self._dat.__delitem__(self._hash(item))
    self._keys.discard(self._hash(item))

  def __contains__(self, item):
    return (self._hash(item)) in self._keys

  def __len__(self):
    return len(self._dat)

  def keys(self):
    yield (self._rehash(i) for i in self._keys)

  def values(self):
    return self._dat.values()

  def items(self):
    return ((self._rehash(k), v) for k,v in self._dat.items())

  def __str__(self):
    li = [f'{k}: {v}' for k,v in self.items()]
    return '{' + ', '.join(li) + '}'


class SegmentTree:
  '''SegmentTree
  abstract.
  n, op, default, V
  '''

  def __init__(self, n, op=lambda x,y: x+y, default=0, V=[]):
    "Make a new Segment Tree. / 0 <= n <= 10**8. / O(N)" 
    
    self._n       = n
    self._log     = (n-1).bit_length()
    self._size    = 1 << self._log
    self._op      = op
    self._default = default
    self._dat     = [self._default] * (2*self._size)
    if V:
      for i in range(self._n):
        self._dat[self._size+i] = V[i]
      for i in range(self._size-1, 0, -1):
        self._update(i)

  def _update(self, k: int):
    '''Update a[k]. / O(1)'''
    self._dat[k] = self._op(self._dat[2*k], self._dat[2*k+1])

  def set(self, p: int, x):
    '''Change a[p] into x. / O(logN)'''
    assert 0 <= p <= self._n, f'p={p}, _n={self._n} <- must be 0 <= p <= self._n'
    p += self._size
    self._dat[p] = x
    for i in range(self._log):
      p >>= 1
      self._update(p)

  def get(self, p: int):
    '''Return a[p]. / O(1)'''
    assert 0 <= p < self._n, f'p={p}, _n={self._n} <- must be 0 <= p <= self._n'
    return self._dat[p+self._size]

  def __getitem__(self, p: int):
    return self.get(p)

  def prod(self, l: int, r: int):
    '''Return op([l, r)). / 0 <= l <= r <= n / O(logN)'''
    assert 0 <= l <= r <= self._n, f'l={l},r={r} <- must be 0 <= l <= r <= self._n'
    l += self._size
    r += self._size
    lres, rres = self._default, self._default
    while l < r:
      if l & 1:
        lres = self._op(lres, self._dat[l])
        l += 1
      if r & 1:
        r -= 1
        rres = self._op(self._dat[r], rres)
      l >>= 1
      r >>= 1
    return self._op(lres, rres)

  def all_prod(self):
    '''Return op([0, n)). / O(1)'''
    return self._dat[1]

  def max_right(self, l: int, f=lambda lr: lr):
    '''Find the largest index R: f([l, R)) == True. / O(logN)'''
    
    if l == self._n:
      return self._n 
    l += self._size
    tmp = self._default
    while True:
      while l & 1 == 0:
        l >>= 1
      if not f(self._op(tmp, self._dat[l])):
        while l < self._size:
          l <<= 1
          if f(self._op(tmp, self._dat[l])):
            tmp = self._op(tmp, self._dat[l])
            l += 1
        return l - self._size
      tmp = self._op(tmp, self._dat[l])
      l += 1
      if l & -l == l:
        break
    return self._n

  def min_left(self, r: int, f=lambda lr: lr):
    '''Find the smallest index L: f([L, r)) == True. / O(logN)'''
    assert 0 <= r <= self._n 
    assert f(self._default)
    if r == 0:
      return 0 
    r += self._size
    tmp = self._default
    while True:
      r -= 1
      while r > 1 and r & 1:
        r >>= 1
      if not f(self._op(self._dat[r], tmp)):
        while r < self._size:
          r = 2*r + 1
          if f(self._op(self._dat[r], tmp)):
            tmp = self._op(self.dat[r], tmp)
            r -= 1
        return r + 1 - self._size
      tmp = self._op(self._dat[r], tmp)
      if r & -r == r:
        break 
    return 0

  def __str__(self):
    ret = [self._dat[i] for i in range(1<<self._log, 1<<self._log+1)]
    return '[' + ', '.join(map(str, ret)) + ']'

  def show(self):
    ret = []
    for i in range(self._log+1):
      tmp = [' ']
      for j in range(2**i):
        tmp.append(self._dat[2**i+j])
      ret.append(' '.join(map(str, tmp)))
    print('<SegmentTree> [\n' + '\n'.join(map(str, ret)) + '\n]')





import math
from bisect import bisect_left, bisect_right
from typing import Generic, Iterable, Iterator, TypeVar, Union, List
T = TypeVar('T')

class SortedSet(Generic[T]):
  BUCKET_RATIO = 50
  REBUILD_RATIO = 170

  def _build(self, a=None) -> None:
    "Evenly divide a into buckets."
    if a is None: a = list(self)
    size = self.size = len(a)
    bucket_size = int(math.ceil(math.sqrt(size / self.BUCKET_RATIO)))
    self.a = [a[size * i // bucket_size : size * (i + 1) // bucket_size] for i in range(bucket_size)]
    
  def __init__(self, a: Iterable[T] = []) -> None:
    "Make a new SortedSet from iterable. / O(N) if sorted and unique / O(N log N)"
    a = list(a)
    if not all(a[i] < a[i + 1] for i in range(len(a) - 1)):
      a = sorted(set(a))
    self._build(a)

  def __iter__(self) -> Iterator[T]:
    for i in self.a:
      for j in i: yield j

  def __reversed__(self) -> Iterator[T]:
    for i in reversed(self.a):
      for j in reversed(i): yield j
    
  def __len__(self) -> int:
    return self.size
    
  def __repr__(self) -> str:
    return "SortedSet" + str(self.a)
    
  def __str__(self) -> str:
    s = str(list(self))
    return "{" + s[1 : len(s) - 1] + "}"

  def _find_bucket(self, x: T) -> List[T]:
    "Find the bucket which should contain x. self must not be empty."
    for a in self.a:
      if x <= a[-1]: return a
    return a

  def __contains__(self, x: T) -> bool:
    if self.size == 0: return False
    a = self._find_bucket(x)
    i = bisect_left(a, x)
    return i != len(a) and a[i] == x

  def add(self, x: T) -> bool:
    "Add an element and return True if added. / O(√N)"
    if self.size == 0:
      self.a = [[x]]
      self.size = 1
      return True
    a = self._find_bucket(x)
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x: return False
    a.insert(i, x)
    self.size += 1
    if len(a) > len(self.a) * self.REBUILD_RATIO:
      self._build()
    return True

  def discard(self, x: T) -> bool:
    "Remove an element and return True if removed. / O(√N)"
    if self.size == 0: return False
    a = self._find_bucket(x)
    i = bisect_left(a, x)
    if i == len(a) or a[i] != x: return False
    a.pop(i)
    self.size -= 1
    if len(a) == 0: self._build()
    return True
    
  def lt(self, x: T) -> Union[T, None]:
    "Find the largest element < x, or None if it doesn't exist."
    for a in reversed(self.a):
      if a[0] < x:
        return a[bisect_left(a, x) - 1]

  def le(self, x: T) -> Union[T, None]:
    "Find the largest element <= x, or None if it doesn't exist."
    for a in reversed(self.a):
      if a[0] <= x:
        return a[bisect_right(a, x) - 1]

  def gt(self, x: T) -> Union[T, None]:
    "Find the smallest element > x, or None if it doesn't exist."
    for a in self.a:
      if a[-1] > x:
        return a[bisect_right(a, x)]

  def ge(self, x: T) -> Union[T, None]:
    "Find the smallest element >= x, or None if it doesn't exist."
    for a in self.a:
      if a[-1] >= x:
        return a[bisect_left(a, x)]
    
  def __getitem__(self, x: int) -> T:
    "Return the x-th element, or IndexError if it doesn't exist."
    if x < 0: x += self.size
    if x < 0: raise IndexError
    for a in self.a:
      if x < len(a): return a[x]
      x -= len(a)
    raise IndexError
    
  def index(self, x: T) -> int:
    "Count the number of elements < x."
    ans = 0
    for a in self.a:
      if a[-1] >= x:
        return ans + bisect_left(a, x)
      ans += len(a)
    return ans

  def index_right(self, x: T) -> int:
    "Count the number of elements <= x."
    ans = 0
    for a in self.a:
      if a[-1] > x:
        return ans + bisect_right(a, x)
      ans += len(a)
    return ans

  def pop(self, k=-1):
    x = self.__getitem__(k)
    self.discard(x)
    return x

  def popleft(self):
    return self.pop(0)

import math
from bisect import bisect_left, bisect_right, insort
from typing import Generic, Iterable, Iterator, TypeVar, Union, List
T = TypeVar('T')

class SortedMultiset(Generic[T]):
  BUCKET_RATIO = 50
  REBUILD_RATIO = 170

  def _build(self, a=None) -> None:
    "Evenly divide `a` into buckets."
    if a is None: a = list(self)
    size = self.size = len(a)
    bucket_size = int(math.ceil(math.sqrt(size / self.BUCKET_RATIO)))
    self.a = [a[size * i // bucket_size : size * (i + 1) // bucket_size] for i in range(bucket_size)]
    
  def __init__(self, a: Iterable[T] = []) -> None:
    "Make a new SortedMultiset from iterable. / O(N) if sorted / O(N log N)"
    a = list(a)
    if not all(a[i] <= a[i + 1] for i in range(len(a) - 1)):
      a = sorted(a)
    self._build(a)

  def __iter__(self) -> Iterator[T]:
    for i in self.a:
      for j in i: yield j

  def __reversed__(self) -> Iterator[T]:
    for i in reversed(self.a):
      for j in reversed(i): yield j
    
  def __len__(self) -> int:
    return self.size
    
  def __repr__(self) -> str:
    return "SortedMultiset" + str(self.a)
    
  def __str__(self) -> str:
    s = str(list(self))
    return "{" + s[1 : len(s) - 1] + "}"

  def __bool__(self) -> int: 
    return self._size

  def _find_bucket(self, x: T) -> List[T]:
    "Find the bucket which should contain x. self must not be empty."
    for a in self.a:
      if x <= a[-1]: return a
    return a

  def __contains__(self, x: T) -> bool:
    if self.size == 0: return False
    a = self._find_bucket(x)
    i = bisect_left(a, x)
    return i != len(a) and a[i] == x

  def count(self, x: T) -> int:
    "Count the number of x."
    return self.index_right(x) - self.index(x)

  def add(self, x: T) -> None:
    "Add an element. / O(√N)"
    if self.size == 0:
      self.a = [[x]]
      self.size = 1
      return
    a = self._find_bucket(x)
    insort(a, x)
    self.size += 1
    if len(a) > len(self.a) * self.REBUILD_RATIO:
      self._build()

  def discard(self, x: T) -> bool:
    "Remove an element and return True if removed. / O(√N)"
    if self.size == 0: return False
    a = self._find_bucket(x)
    i = bisect_left(a, x)
    if i == len(a) or a[i] != x: return False
    a.pop(i)
    self.size -= 1
    if len(a) == 0: self._build()
    return True

  def lt(self, x: T) -> Union[T, None]:
    "Find the largest element < x, or None if it doesn't exist."
    for a in reversed(self.a):
      if a[0] < x:
        return a[bisect_left(a, x) - 1]

  def le(self, x: T) -> Union[T, None]:
    "Find the largest element <= x, or None if it doesn't exist."
    for a in reversed(self.a):
      if a[0] <= x:
        return a[bisect_right(a, x) - 1]

  def gt(self, x: T) -> Union[T, None]:
    "Find the smallest element > x, or None if it doesn't exist."
    for a in self.a:
      if a[-1] > x:
        return a[bisect_right(a, x)]

  def ge(self, x: T) -> Union[T, None]:
    "Find the smallest element >= x, or None if it doesn't exist."
    for a in self.a:
      if a[-1] >= x:
        return a[bisect_left(a, x)]
    
  def __getitem__(self, x: int) -> T:
    "Return the x-th element, or IndexError if it doesn't exist."
    if x < 0: x += self.size
    if x < 0: raise IndexError
    for a in self.a:
      if x < len(a): return a[x]
      x -= len(a)
    raise IndexError

  def index(self, x: T) -> int:
    "Count the number of elements < x."
    ans = 0
    for a in self.a:
      if a[-1] >= x:
        return ans + bisect_left(a, x)
      ans += len(a)
    return ans

  def index_right(self, x: T) -> int:
    "Count the number of elements <= x."
    ans = 0
    for a in self.a:
      if a[-1] > x:
        return ans + bisect_right(a, x)
      ans += len(a)
    return ans

  def pop(self, k=-1):
    x = self.__getitem__(k)
    self.discard(x)
    return x

  def popleft(self):
    return self.pop(0)



def main():
  n = int(input())
  A = list(map(int, input().split()))
  V = [(i, A[i]) for i in range(n) if A[i] - i - 1 < 0]
  ss = SortedMultiset(V)
  ans = 0
  for l in range(n):
    while True:
      ge = ss.ge((l, -inf))
      if ge is None:
        ans += n - l
        break
      indx, val = ge
      if val - indx + l <= 0:
        ans += indx - l
        break
      else:
        ss.discard(ge)
  return ans

print('\n'.join(str(main()) for _ in range(int(input()))))
