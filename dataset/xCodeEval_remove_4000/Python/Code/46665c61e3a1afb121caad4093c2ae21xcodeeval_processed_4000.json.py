
import math
import heapq, bisect
import sys
from collections import deque, defaultdict
from fractions import Fraction
import sys
mod = 10 ** 9 + 7
mod1 = 998244353
sys.setrecursionlimit(300000)

import os
import sys
from io import BytesIO, IOBase
id7 = 8192
sys.setrecursionlimit(300000)
class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id7))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id7))
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



class TreeNode:
    def __init__(self, k, v):
        self.key = k
        self.value = v
        self.left = None
        self.right = None
        self.parent = None
        self.height = 1
        self.num_left = 1
        self.num_total = 1


class id8:

    def __init__(self):
        self._tree = None

    def add(self, k, v):
        if not self._tree:
            self._tree = TreeNode(k, v)
            return
        node = self._add(k, v)
        if node:
            self._rebalance(node)

    def _add(self, k, v):
        node = self._tree
        while node:
            if k < node.key:
                if node.left:
                    node = node.left
                else:
                    node.left = TreeNode(k, v)
                    node.left.parent = node
                    return node.left
            elif node.key < k:
                if node.right:
                    node = node.right
                else:
                    node.right = TreeNode(k, v)
                    node.right.parent = node
                    return node.right
            else:
                node.value = v
                return

    @staticmethod
    def get_height(x):
        return x.height if x else 0

    @staticmethod
    def id1(x):
        return x.num_total if x else 0

    def _rebalance(self, node):

        n = node
        while n:
            lh = self.get_height(n.left)
            rh = self.get_height(n.right)
            n.height = max(lh, rh) + 1
            balance_factor = lh - rh
            n.num_total = 1 + self.id1(n.left) + self.id1(n.right)
            n.num_left = 1 + self.id1(n.left)

            if balance_factor > 1:
                if self.get_height(n.left.left) < self.get_height(n.left.right):
                    self._rotate_left(n.left)
                self._rotate_right(n)
            elif balance_factor < -1:
                if self.get_height(n.right.right) < self.get_height(n.right.left):
                    self._rotate_right(n.right)
                self._rotate_left(n)
            else:
                n = n.parent

    def _remove_one(self, node):
        
        replacement = node.left or node.right
        if node.parent:
            if id8._is_left(node):
                node.parent.left = replacement
            else:
                node.parent.right = replacement
            replacement.parent = node.parent
            node.parent = None
        else:
            self._tree = replacement
            replacement.parent = None
        node.left = None
        node.right = None
        node.parent = None
        self._rebalance(replacement)

    def _remove_leaf(self, node):
        if node.parent:
            if id8._is_left(node):
                node.parent.left = None
            else:
                node.parent.right = None
            self._rebalance(node.parent)
        else:
            self._tree = None
        node.parent = None
        node.left = None
        node.right = None

    def remove(self, k):
        node = self._get_node(k)
        if not node:
            return
        if id8._is_leaf(node):
            self._remove_leaf(node)
            return
        if node.left and node.right:
            nxt = id8._get_next(node)
            node.key = nxt.key
            node.value = nxt.value
            if self._is_leaf(nxt):
                self._remove_leaf(nxt)
            else:
                self._remove_one(nxt)
            self._rebalance(node)
        else:
            self._remove_one(node)

    def get(self, k):
        node = self._get_node(k)
        return node.value if node else -1

    def _get_node(self, k):
        if not self._tree:
            return None
        node = self._tree
        while node:
            if k < node.key:
                node = node.left
            elif node.key < k:
                node = node.right
            else:
                return node
        return None

    def get_at(self, pos):
        x = pos + 1
        node = self._tree
        while node:
            if x < node.num_left:
                node = node.left
            elif node.num_left < x:
                x -= node.num_left
                node = node.right
            else:
                return (node.key, node.value)
        raise IndexError("Out of ranges")

    @staticmethod
    def _is_left(node):
        return node.parent.left and node.parent.left == node

    @staticmethod
    def _is_leaf(node):
        return node.left is None and node.right is None

    def _rotate_right(self, node):
        if not node.parent:
            self._tree = node.left
            node.left.parent = None
        elif id8._is_left(node):
            node.parent.left = node.left
            node.left.parent = node.parent
        else:
            node.parent.right = node.left
            node.left.parent = node.parent
        bk = node.left.right
        node.left.right = node
        node.parent = node.left
        node.left = bk
        if bk:
            bk.parent = node
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
        node.num_total = 1 + self.id1(node.left) + self.id1(node.right)
        node.num_left = 1 + self.id1(node.left)

    def _rotate_left(self, node):
        if not node.parent:
            self._tree = node.right
            node.right.parent = None
        elif id8._is_left(node):
            node.parent.left = node.right
            node.right.parent = node.parent
        else:
            node.parent.right = node.right
            node.right.parent = node.parent
        bk = node.right.left
        node.right.left = node
        node.parent = node.right
        node.right = bk
        if bk:
            bk.parent = node
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
        node.num_total = 1 + self.id1(node.left) + self.id1(node.right)
        node.num_left = 1 + self.id1(node.left)

    @staticmethod
    def _get_next(node):
        if not node.right:
            return node.parent
        n = node.right
        while n.left:
            n = n.left
        return n



class id0:
    def __init__(self, data, default=0, func=lambda a, b: max(a, b)):
        
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def id4(self, idx):
        self[idx] = self._default

    def id6(self, idx):
        return self.data[idx + self._size]

    def id3(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def id11(self):
        return self._len

    def query(self, start, stop):
        if start == stop:
            return self.id6(start)
        stop += 1
        start += self._size
        stop += self._size

        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res

    def id2(self):
        return "SegmentTree({0})".format(self.data)



class SegmentTree:
    def __init__(self, data, default=0, func=lambda a, b: a + b):
        
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def id4(self, idx):
        self[idx] = self._default

    def id6(self, idx):
        return self.data[idx + self._size]

    def id3(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def id11(self):
        return self._len

    def query(self, start, stop):
        if start == stop:
            return self.id6(start)
        stop += 1
        start += self._size
        stop += self._size

        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res

    def id2(self):
        return "SegmentTree({0})".format(self.data)



class Factorial:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorials = [1, 1]
        self.invModulos = [0, 1]
        self.invFactorial_ = [1, 1]

    def calc(self, n):
        if n <= -1:
            print("Invalid argument to calculate n!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.factorials):
            return self.factorials[n]
        nextArr = [0] * (n + 1 - len(self.factorials))
        initialI = len(self.factorials)
        prev = self.factorials[-1]
        m = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = prev * i % m
        self.factorials += nextArr
        return self.factorials[n]

    def inv(self, n):
        if n <= -1:
            print("Invalid argument to calculate n^(-1)")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        p = self.MOD
        pi = n % p
        if pi < len(self.invModulos):
            return self.invModulos[pi]
        nextArr = [0] * (n + 1 - len(self.invModulos))
        initialI = len(self.invModulos)
        for i in range(initialI, min(p, n + 1)):
            next = -self.invModulos[p % i] * (p // i) % p
            self.invModulos.append(next)
        return self.invModulos[pi]

    def id10(self, n):
        if n <= -1:
            print("Invalid argument to calculate (n^(-1))!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.invFactorial_):
            return self.invFactorial_[n]
        self.inv(n)  
        nextArr = [0] * (n + 1 - len(self.invFactorial_))
        initialI = len(self.invFactorial_)
        prev = self.invFactorial_[-1]
        p = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = (prev * self.invModulos[i % p]) % p
        self.invFactorial_ += nextArr
        return self.invFactorial_[n]


class Combination:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorial = Factorial(MOD)

    def ncr(self, n, k):
        if k < 0 or n < k:
            return 0
        k = min(k, n - k)
        f = self.factorial
        return f.calc(n) * f.id10(max(n - k, k)) * f.id10(min(k, n - k)) % self.MOD



def powm(a, n, m):
    if a == 1 or n == 0:
        return 1
    if n % 2 == 0:
        s = powm(a, n // 2, m)
        return s * s % m
    else:
        return a * powm(a, n - 1, m) % m



def sort_list(list1, list2):
    id5 = zip(list2, list1)

    z = [x for _, x in sorted(id5)]

    return z



def product(l):
    por = 1
    for i in range(len(l)):
        por *= l[i]
    return por



def id9(arr, n, key):
    left = 0
    right = n - 1

    count = 0

    while (left <= right):
        mid = int((right + left) / 2)

        
        
        if (arr[mid] < key):
            count = mid + 1
            left = mid + 1

        
        else:
            right = mid - 1

    return count



def countdig(n):
    c = 0
    while (n > 0):
        n //= 10
        c += 1
    return c
def binary(x, length):
    y = bin(x)[2:]
    return y if len(y) >= length else "0" * (length - len(y)) + y

def countGreater(arr, n, k):
    l = 0
    r = n - 1

    
    
    leftGreater = n

    
    while (l <= r):
        m = int(l + (r - l) / 2)
        if (arr[m] >= k):
            leftGreater = m
            r = m - 1

        
        
        else:
            l = m + 1

    
    
    return (n - leftGreater)

for ik in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    if n==1:
        print('T')
        continue
    l=[l[i]*(-1) for i in range(n)]
    heapq.heapify(l)
    f=0
    g=0
    while(True):
        if len(l)==0:
            print("HL")
            break
        f=-heapq.heappop(l)
        f-=1
        if g!=0:
            heapq.heappush(l,-g)
        if len(l)==0:
            print("T")
            break
        g = -heapq.heappop(l)
        g -= 1
        if f!=0:
            heapq.heappush(l,-f)