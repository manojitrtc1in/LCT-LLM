
import math
import random
import heapq,bisect
import sys
from collections import deque, defaultdict
from fractions import Fraction
from itertools import permutations
from collections import defaultdict
mod = 10 ** 9 + 7
mod1 = 998244353
import sys


import os
import sys
from io import BytesIO, IOBase

id15 = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id15))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id15))
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



class SegmentTree:
    def __init__(self, data, default=-3*10**9, func=lambda a, b: max(a,b)):
        
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def id10(self, idx):
        self[idx] = self._default

    def id13(self, idx):
        return self.data[idx + self._size]

    def id9(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def id23(self):
        return self._len

    def query(self, start, stop):
        if start == stop:
            return self.id13(start)
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

    def id7(self):
        return "SegmentTree({0})".format(self.data)



class SortedList:
    def __init__(self, iterable=[], _load=200):
        
        values = sorted(iterable)
        self._len = _len = len(values)
        self._load = _load
        self._lists = _lists = [values[i:i + _load] for i in range(0, _len, _load)]
        self.id18 = [len(_list) for _list in _lists]
        self._mins = [_list[0] for _list in _lists]
        self.id17 = []
        self._rebuild = True

    def id0(self):
        
        self.id17[:] = self.id18
        id17 = self.id17
        for i in range(len(id17)):
            if i | i + 1 < len(id17):
                id17[i | i + 1] += id17[i]
        self._rebuild = False

    def id1(self, index, value):
        
        if not self._rebuild:
            id17 = self.id17
            while index < len(id17):
                id17[index] += value
                index |= index + 1

    def id4(self, end):
        
        if self._rebuild:
            self.id0()

        id17 = self.id17
        x = 0
        while end:
            x += id17[end - 1]
            end &= end - 1
        return x

    def id3(self, k):
        
        id18 = self.id18
        if k < id18[0]:
            return 0, k
        if k >= self._len - id18[-1]:
            return len(id18) - 1, k + id18[-1] - self._len
        if self._rebuild:
            self.id0()

        id17 = self.id17
        idx = -1
        for d in reversed(range(len(id17).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(id17) and k >= id17[right_idx]:
                idx = right_idx
                k -= id17[idx]
        return idx + 1, k

    def _delete(self, pos, idx):
        
        _lists = self._lists
        _mins = self._mins
        id18 = self.id18

        self._len -= 1
        self.id1(pos, -1)
        del _lists[pos][idx]
        id18[pos] -= 1

        if id18[pos]:
            _mins[pos] = _lists[pos][0]
        else:
            del _lists[pos]
            del id18[pos]
            del _mins[pos]
            self._rebuild = True

    def _loc_left(self, value):
        
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
        
        _load = self._load
        _lists = self._lists
        _mins = self._mins
        id18 = self.id18

        self._len += 1
        if _lists:
            pos, idx = self._loc_right(value)
            self.id1(pos, 1)
            _list = _lists[pos]
            _list.insert(idx, value)
            id18[pos] += 1
            _mins[pos] = _list[0]
            if _load + _load < len(_list):
                _lists.insert(pos + 1, _list[_load:])
                id18.insert(pos + 1, len(_list) - _load)
                _mins.insert(pos + 1, _list[_load])
                id18[pos] = _load
                del _list[_load:]
                self._rebuild = True
        else:
            _lists.append([value])
            _mins.append(value)
            id18.append(1)
            self._rebuild = True

    def discard(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_right(value)
            if idx and _lists[pos][idx - 1] == value:
                self._delete(pos, idx - 1)

    def remove(self, value):
        
        _len = self._len
        self.discard(value)
        if _len == self._len:
            raise ValueError('{0!r} not in list'.format(value))

    def pop(self, index=-1):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        value = self._lists[pos][idx]
        self._delete(pos, idx)
        return value

    def id2(self, value):
        
        pos, idx = self._loc_left(value)
        return self.id4(pos) + idx

    def id12(self, value):
        
        pos, idx = self._loc_right(value)
        return self.id4(pos) + idx

    def count(self, value):
        
        return self.id12(value) - self.id2(value)

    def id23(self):
        
        return self._len

    def id13(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        return self._lists[pos][idx]

    def id10(self, index):
        
        pos, idx = self.id3(self._len + index if index < 0 else index)
        self._delete(pos, idx)

    def id8(self, value):
        
        _lists = self._lists
        if _lists:
            pos, idx = self._loc_left(value)
            return idx < len(_lists[pos]) and _lists[pos][idx] == value
        return False

    def id22(self):
        
        return (value for _list in self._lists for value in _list)

    def id16(self):
        
        return (value for _list in reversed(self._lists) for value in reversed(_list))

    def id7(self):
        
        return 'SortedList({0})'.format(list(self))

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

    def id20(self, n):
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
        return f.calc(n) * f.id20(max(n - k, k)) * f.id20(min(k, n - k)) % self.MOD



def powm(a, n, m):
    if a == 1 or n == 0:
        return 1
    if n % 2 == 0:
        s = powm(a, n // 2, m)
        return s * s % m
    else:
        return a * powm(a, n - 1, m) % m



def sort_list(list1, list2):
    id11 = zip(list2, list1)

    z = [x for _, x in sorted(id11)]

    return z



def product(l):
    por = 1
    for i in range(len(l)):
        por *= l[i]
    return por



def id19(arr, n, key):
    left = 0
    right = n - 1

    count = 0

    while (left <= right):
        mid = int((right + left) / 2)

        
        
        if (arr[mid] <= key):
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

class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEndOfWord = False
class Trie:
    def __init__(self):
        self.root = self.getNode()
    def getNode(self):
        return TrieNode()
    def id6(self, ch):
        return ord(ch) - ord('a')
    def insert(self, key):
        id21 = self.root
        length = len(key)
        for level in range(length):
            index = self.id6(key[level])
            if not id21.children[index]:
                id21.children[index] = self.getNode()
            id21 = id21.children[index]
        id21.isEndOfWord = True
    def search(self, key):
        id21 = self.root
        length = len(key)
        for level in range(length):
            index = self.id6(key[level])
            if not id21.children[index]:
                return False
            id21 = id21.children[index]
        return id21 != None and id21.isEndOfWord

class Node:
    def __init__(self, data):
        self.data = data
        self.count=0
        self.left = None  
        self.right = None  
class BinaryTrie:
    def __init__(self):
        self.root = Node(0)
    def insert(self, id14):
        self.temp = self.root
        for i in range(31, -1, -1):
            val = id14 & (1 << i)
            if val:
                if not self.temp.right:
                    self.temp.right = Node(0)
                self.temp = self.temp.right
                self.temp.count+=1
            if not val:
                if not self.temp.left:
                    self.temp.left = Node(0)
                self.temp = self.temp.left
                self.temp.count += 1
        self.temp.data = id14
    def query(self, xor):
        self.temp = self.root
        for i in range(31, -1, -1):
            val = xor & (1 << i)
            if not val:
                if self.temp.left and self.temp.left.count>0:
                    self.temp = self.temp.left
                elif self.temp.right:
                    self.temp = self.temp.right
            else:
                if self.temp.right and self.temp.right.count>0:
                    self.temp = self.temp.right
                elif self.temp.left:
                    self.temp = self.temp.left
            self.temp.count-=1
        return xor ^ self.temp.data

for ik in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a=[a[i]+1 for i in range(n)]
    b=[b[i]+1 for i in range(n)]
    a[0]=0
    na=a+[]
    nb=b+[]
    oa=a+[]
    ob=b+[]
    for i in range(n):
        nb[i]-=i
        a[i]-=i
    for i in range(n-1,-1,-1):
        b[i]-=n-1-i
        na[i]-=n-1-i
    def find1(j,time):
        min_a=mina[j]-time+j
        min_b=minb[j]-(n-j)-time
        return max(0,min_a,min_b)
    def find(j,time):
        min_a=nmina[j]-(n-j)-time
        min_b=id5[j]-time+j
        return max(0,min_a,min_b)
    mina=[-20**9]*n
    minb=[-20**9]*n
    nmina=[-20**9]*n
    id5=[-20**9]*n
    for i in range(n-1,-1,-1):
        if i==n-1:
            mina[i]=a[i]
            minb[i]=b[i]
        else:
            mina[i]=max(a[i],mina[i+1])
            minb[i]=max(b[i],minb[i+1])
        if i==n-1:
            nmina[i]=na[i]
            id5[i]=nb[i]
        else:
            nmina[i]=max(na[i],nmina[i+1])
            id5[i]=max(nb[i],id5[i+1])
    ans=10**10
    time=0
    for i in range(n):
        up=20**9
        down=20**9
        if i%2==0:
            time=max(time,oa[i])
            up=time+find1(i,time)
            time+=1
            time=max(time,ob[i])
        else:
            time=max(time,ob[i])
            down=time+find(i,time)
            time+=1
            time=max(time,oa[i])
        time+=1
        up+=(n-i)*2-1
        down+=(n-i)*2-1
        ans=min(ans,up,down)
    ans=min(ans,time)
    print(ans)