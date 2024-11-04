

import math
import os
import sys

from sys import *
from decimal import *
from io import BytesIO, IOBase
from itertools import accumulate,combinations,permutations,combinations_with_replacement,product
from collections import *


M = 10 ** 9 + 7
import heapq


if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip


id0 = 8192
class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id0))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id0))
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


def inp(): return sys.stdin.readline().rstrip("\r\n")  


def out(var): sys.stdout.write(str(var))  


def lis(): return list(map(int, inp().split()))


def stringlis(): return list(map(str, inp().split()))


def sep(): return map(int, inp().split())


def strsep(): return map(str, inp().split())


def fsep(): return map(float, inp().split())


def inpu(): return int(inp())





def dfs(root,nodeVal,nodeConnection,visited):
    leftVal = nodeVal[root][0]
    rightVal = nodeVal[root][1]
    solution = []
    if nodeConnection[root]:
        visited.add(root)
        for i in nodeConnection[root]:
            if i not in visited:
                solution.append(dfs(i,nodeVal,nodeConnection,visited))
        
        leftMax = 0
        rightMax = 0
        for i in solution:
            l, r = i
            leftMax += max(abs(leftVal - l[0]) + l[1], abs(leftVal - r[0]) + r[1])
            rightMax += max(abs(rightVal - l[0]) + l[1], abs(rightVal - r[0]) + r[1])
        
        return ((leftVal, leftMax), (rightVal, rightMax))
    else:
        
        return ((leftVal, 0), (rightVal, 0))

def id1(x,n,a):
    if x >0:
        a.append(x)
    if x>10**9:
        return a
    else:
        if x < 1e12:
            id1(x * 10 + 4,n,a)
            id1(x * 10 + 7,n,a)
def lcm(a,b):
    return (a*b)//math.gcd(a,b)

def query1(l, r):
    if l >= r:
        return -1
    print('?', l + 1, r + 1)
    sys.stdout.flush()
    return int(input()) - 1
def answer(p):
    print('!', p + 1)
    sys.stdout.flush()
    exit()










class Graph(object):
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.V = vertices

    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def connectedComponents(self):
        unvisited = set(range(self.V))
        queue = deque()

        count = 0
        while len(unvisited) > 0:
            count += 1
            v = next(iter(unvisited))
            unvisited.remove(v)
            queue.append(v)
            while len(queue) > 0:
                v = queue.popleft()
                for w in self.graph[v]:
                    if w in unvisited:
                        unvisited.remove(w)
                        queue.append(w)
        return count
def id2(arr, n):
    msis=arr.copy()
    for i in range(1, n):
        for j in range(i):
            if (arr[i] > arr[j] and
                    msis[i] < msis[j] + arr[i]):
                msis[i] = msis[j] + arr[i]
    c=max(msis)
    p=5
    return c

def id3(arr,target):
    lo=0
    hi=len(arr)-1
    while(lo<=hi):
        mid=(lo+hi)//2
        
        if arr[mid]==target:
            if mid!=len(arr)-1:
                if arr[mid+1]!=target:
                    return mid
                else:
                    lo+=1
            else:
                return mid
            continue
        if arr[mid]>target:
            hi=mid-1
        else:
            lo=mid+1
def ngr(arr,n):
    stack=[]
    ans=[]
    for i in range(n-1,-1,-1):
        if len(stack)==0:
            ans.append(-1)
        else:
            while(len(stack)>0):
                if stack[-1][0]<arr[i]:
                    stack.pop()
                else:
                    break
            if len(stack)==0:
                ans.append(-1)
            else:
                ans.append(stack[-1][1])
        stack.append([arr[i],i])
    ans.reverse()
    return ans
def alperm(nums,ans,c,n):
    if len(ans)==len(nums):
        ans.append(c)
        return
    if n<=0:
        return
    op=c+[nums[n-1]]
    alperm(nums,ans,op,n-1)
    alperm(nums,ans,c,n-1)
def main():
    
    d = {}
    for i in range(97, 123):
        d[chr(i)] = i - 96
    
    n, q = map(int, input().split())
    s = input()
    ans = []
    for i in s:
        ans.append(d[i])
    ans = list(accumulate(ans))
    
    for _ in range(q):
        l, r = map(int, input().split())
        if l <= 1:
            print(ans[r - 1])
        else:
            print(ans[r - 1] - ans[l - 2])
if __name__ == '__main__':
    main()
