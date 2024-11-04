from __future__ import division, print_function

class buildSegmentTree:
    ''' Constructor to create a segment tree with the passed array '''
    def __init__(self, arr):
        self.length = len(arr)
        self.tree = [0]*(4*self.length+1)
        self.lazy = [0] * (4 * self.length + 1)
        self.start = 0
        self.end = self.length-1
        self.mid = int((self.start + self.end)/2)
        self.data = arr
        def build(self, arr, tree, start, end, mid, treeNode):
            
            if(start==end):
                tree[treeNode] = arr[start]
                return;

            build(self, arr, tree, start, mid, int((start+mid)/2), 2*treeNode)
            build(self, arr, tree, mid+1, end, int((end + mid+1) / 2), 2*treeNode + 1)
            tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1]

        
        build(self, arr, self.tree, self.start, self.end, self.mid, 1)

    
    def print_tree(self):
        print(self.tree)

    
    def query(self, start, end):
        return self._query(start, end, self.start, self.end, 1)

    
    def _query(self, qs, qe, s, e, treeIndex):
        if (self.lazy[treeIndex] != 0):
            self.tree[treeIndex] += (e - s + 1)*self.lazy[treeIndex]
            if (s != e):
                self.lazy[2 * treeIndex] += self.lazy[treeIndex]
                self.lazy[2 * treeIndex + 1] += self.lazy[treeIndex]
            self.lazy[treeIndex] = 0

        
        if(qe<s or e<qs):
            return 0
        
        elif(s>=qs and e<=qe):
            return self.tree[treeIndex]
        
        else:
            mid = int((s+e)/2)
            leftAns = self._query(qs, qe, s, mid, 2*treeIndex)
            rightAns = self._query(qs, qe, mid + 1, e, 2*treeIndex + 1)

            return leftAns + rightAns

    
    def update(self, index, element):
        val = element - self.data[index]
        return self._update(index, val, self.start, self.end, 1)

    
    def _update(self, ind, val, s, e, treeIndex):
        if(ind<s or ind>e):
            return
        if(ind==s and s==e):
            self.tree[treeIndex] += val
            return
        self.tree[treeIndex] += val
        mid = int((s+e)/2)
        self._update(ind, val, s, mid, 2*treeIndex)
        self._update(ind, val, mid + 1, e, 2*treeIndex + 1)
        return

    
    def updateRange(self, start, end, val):
        return self._updateRange(start, end, self.start, self.end, 1, val)

    
    def _updateRange(self, qs, qe, s, e, treeIndex, val):
        if(self.lazy[treeIndex]!=0):
            self.tree[treeIndex] += (e - s + 1)*self.lazy[treeIndex]
            if(s != e):
                self.lazy[2*treeIndex] += self.lazy[treeIndex]
                self.lazy[2 * treeIndex + 1] += self.lazy[treeIndex]
            self.lazy[treeIndex] = 0

        
        if(qe<s or e<qs):
            return

        
        elif (s >= qs and e <= qe):
            self.tree[treeIndex] += (e - s + 1)*val
            if(s!=e):
                self.lazy[2*treeIndex] += val
                self.lazy[2*treeIndex + 1] += val

            return

        
        else:
            mid = int((s + e) / 2)
            self._updateRange(qs, qe, s, mid, 2*treeIndex, val)
            self._updateRange(qs, qe, mid + 1, e, 2*treeIndex + 1, val)
            self.tree[treeIndex] = self.tree[2*treeIndex] + self.tree[2*treeIndex+1]


class NumArray(object):
    def __init__(self, nums):
        self.l = len(nums)
        self.tree = [0] * self.l + nums
        for i in range(self.l - 1, 0, -1):
            self.tree[i] = self.tree[i << 1] + self.tree[i << 1 | 1]

    def update(self, i, val):
        n = self.l + i
        self.tree[n] = val
        while n > 1:
            self.tree[n >> 1] = self.tree[n] + self.tree[n ^ 1]
            n >>= 1

    def sumRange(self, i, j):
        m = self.l + i
        n = self.l + j
        res = 0
        while m <= n:
            if m & 1:
                res += self.tree[m]
                m += 1
            m >>= 1
            if n & 1 == 0:
                res += self.tree[n]
                n -= 1
            n >>= 1
        return res

def main():
    
    import sys, re, math
    from collections import deque, defaultdict, Counter, OrderedDict
    from bisect import bisect, bisect_left
    from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, floor
    from heapq import heappush, heappop, heapify, nlargest, nsmallest
    from fractions import Fraction
    from decimal import Decimal
    def STR():
        return list(input())

    def INT():
        return int(input())

    def MAP():
        return map(int, input().split())

    def LIST():
        return list(map(int, input().split()))

    def list2d(a, b, c):
        return [[c] * b for i in range(a)]

    def sortListWithIndex(listOfTuples, idx):
        return (sorted(listOfTuples, key=lambda x: x[idx]))

    def sortDictWithVal(passedDic):
        temp = sorted(passedDic.items(), key=lambda kv: (kv[1], kv[0]))
        toret = {}
        for tup in temp:
            toret[tup[0]] = tup[1]
        return toret

    def sortDictWithKey(passedDic):
        return dict(OrderedDict(sorted(passedDic.items())))

    
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
            self.a = [a[size * i // bucket_size: size * (i + 1) // bucket_size] for i in range(bucket_size)]

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
            return "{" + s[1: len(s) - 1] + "}"

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

    t = INT()

    while (t != 0):
        n,m,k = MAP()

        a = LIST()

        
        a.sort(reverse=True)
        A = a.copy()
        possR = True
        rowsleft = n
        if(n%2==1):
            if(a[0]<3*m):
                possR = False
            else:
                rowsleft -= 3
                a[0]-=3*m
        if(possR!=False):
            for el in a:
                if(rowsleft<=0):
                    possR = True
                    break
                foo = el//m
                if(foo==1):
                    
                    continue
                rowsleft -= foo
        if(possR==True and rowsleft<=0):
            print("Yes")
            
        else:
            

            possC = True
            colsleft = m
            if (m % 2 == 1):
                if (A[0] < 3 * n):
                    possC = False
                else:
                    colsleft -= 3
                    A[0] -= 3 * n
            if(possC!=False):
                for el in A:
                    if (colsleft <= 0):
                        possC = True
                        break
                    foo = el // n
                    if (foo == 1):
                        
                        continue
                    colsleft -= foo
            if(colsleft<=0 and possC==True):
                print("Yes")
            else:
                print("No")




        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

        t -= 1
'''
1
()?(?)
'''









py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip

    range = xrange

import os, sys
from io import IOBase, BytesIO

BUFSIZE = 8192


class FastIO(BytesIO):
    newlines = 0

    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0, 2), super(FastIO, self).write(s))[0])
        return s

    def read(self):
        while self._fill(): pass
        return super(FastIO, self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill();
            self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s: self.buffer.write(s.encode('ascii'))
            self.read = lambda: self.buffer.read().decode('ascii')
            self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')


import sys


class ostream:
    def __lshift__(self, a):
        sys.stdout.write(str(a))
        return self


cout = ostream()
endl = '\n'



def readnumbers(zero=0):
    conv = ord if py2 else lambda x: x
    A = [];
    numb = zero;
    sign = 1;
    i = 0;
    s = sys.stdin.buffer.read()
    try:
        while True:
            if s[i] >= b'0'[0]:
                numb = 10 * numb + conv(s[i]) - 48
            elif s[i] == b'-'[0]:
                sign = -1
            elif s[i] != b'\r'[0]:
                A.append(sign * numb)
                numb = zero;
                sign = 1
            i += 1
    except:
        pass
    if s and s[-1] >= b'0'[0]:
        A.append(sign * numb)
    return A


if __name__ == "__main__":
    main()