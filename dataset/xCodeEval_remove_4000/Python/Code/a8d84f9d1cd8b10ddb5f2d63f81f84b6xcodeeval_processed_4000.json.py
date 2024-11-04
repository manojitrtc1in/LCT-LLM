

import math
import os
import sys

from sys import *
from decimal import *
from io import BytesIO, IOBase
from itertools import *
from collections import *
from array import *
import random
M = 10 ** 9 + 7
import heapq
import bisect

from functools import lru_cache
from queue import PriorityQueue
sys.setrecursionlimit(2*(10**5))

id5 = 8192
class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id5))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id5))
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


def binarySearch(arr, n, key):
    left = 0
    right = n - 1
    while (left <= right):
        mid = ((right + left) // 2)
        if arr[mid]==key:
            return mid
        if (arr[mid] <= key):
            left = mid + 1
        
        else:
            right = mid - 1
    return -1

def id0(n):
    n = str(n)
    s1 = 0
    for i in n:
        s1 += int(i)
    return s1
def perfect_square(n):
    s = math.sqrt(n)
    if s == int(s):
        return True
    return False


def id3(x,n,a):
    if x >0:
        a.append(x)
    if x>10**9:
        return a
    else:
        if x < 1e12:
            id3(x * 10 + 4,n,a)
            id3(x * 10 + 7,n,a)
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





def rse(arr,n):
    stack=[]
    ans=[]
    for i in range(n-1,-1,-1):
        if len(stack)==0:
            ans.append(n)
        else:
            while(len(stack)!=0):
                if stack[-1][0]>=arr[i]:
                    stack.pop()
                else:
                    break
            if len(stack)==0:
                ans.append(n)
            else:
                ans.append(stack[-1][1])
        stack.append([arr[i],i])
    ans.reverse()
    return ans

def lse(arr,n):
    stack=[]
    ans=[]
    for i in range(n):
        if len(stack)==0:
            ans.append(-1)
        else:
            while(len(stack)!=0):
                if stack[-1][0]>=arr[i]:
                    stack.pop()
                else:
                    break
            if len(stack)==0:
                ans.append(-1)
            else:
                ans.append(stack[-1][1])
        stack.append([arr[i],i])
    return ans

def mah(arr):
    max1=0
    p=rse(arr,len(arr))
    q=lse(arr,len(arr))
    for i in range(len(arr)):
        a=(p[i]-q[i]-1)*arr[i]
        max1=max(a,max1)
    return max1





def id6(arr, n):
    msis=arr.copy()
    for i in range(1, n):
        for j in range(i):
            if (arr[i] > arr[j] and
                    msis[i] < msis[j] + arr[i]):
                msis[i] = msis[j] + arr[i]
    c=max(msis)
    p=5
    return c

def id2(arr,target):
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
def nge(arr,n):
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

def alperm(nums, path,result):
    if not nums:
        result.add(tuple(path))
        return
    for i in range(0,len(nums)):
        alperm(nums[:i] + nums[i + 1:], path + [nums[i]],result)
    return result

def minsum(arr,n,m,res,l):
    if n==1 and m==1:
        res+=arr[0][0]
        l.append(res)
    else:
        if n!=1:
                p=res+arr[n-1][m-1]
                minsum(arr,n-1,m,p,l)
        if m!=1:
                p=res+arr[n-1][m-1]
                minsum(arr,n,m-1,p,l)
    return min(l)





def id1(graph, start, end, path):
    path = path + [start]
    if start == end:
        return path
    if start not in graph:
        return None
    shortest = None
    for node in graph[start]:
        if node not in path:
            newpath = id1(graph, node, end, path)
            if newpath:
                if not shortest or len(newpath) < len(shortest):
                    shortest = newpath
    return shortest


def test(n, d):
    a = random.randint(1, n - 2)
    p = pow(a, d, n)
    if p == 1 or p == n - 1:
        return True
    while (d != n - 1):
        d *= 2
        p = pow(p, 2, n)
        if p == n - 1:
            return True
    return False
def isprime(n):
    if n == 1:
        return False
    if n == 2:
        return True
    if n==3:
        return True
    d = n - 1
    while (d % 2 == 0):
        d //= 2
    for i in range(5):
        if test(n, d) == False:
            return False
    return True







def muin(a,m):
    x,y,mo = 1,0,m
    if m==1:
        return 0
    while(m>0):
        x,y = y,x-(a//m)*y
        a,m=m,a%m
    if x<0:
        return mo+x
    else:
        return x
def good(l,c):
    ch=chr(c)
    if len(l)==1:
        return(1 if ch!=l[0] else 0)
    k=len(l)//2
    lm=k-l[:k].count(ch)+good(l[k:],c+1)
    rm=k-l[k:].count(ch)+good(l[:k],c+1)
    return(min(lm,rm))
def facto(fact):
    fact[0],fact[1] = 1,1
    for i in range(2,10**6+1):
        fact[i] = (fact[i-1]*i)%M
def comb(n,r,fact):
    return (fact[n]*pow(fact[n-r]*fact[r],M-2,M))%M

def id4(n, b):
    if n == 0:
        return 0
    digits = []
    while n:
        digits.append((n % b))
        n //= b
    return sum(digits)


def dfs(curr,visited,d):
    visited[curr]=True
    for i in d[curr]:
        if not visited[i]:
            dfs(i,visited,d)
p=[1]
for i in range(3,2*(10**5)+5):
    p.append((p[-1]*i)%(10**9+7))
def main():
    t = 1
    t = inpu()
    for tc in range(1, t + 1):
        n = inpu()
        s = p[2*n-2]
        
        print(s)
if __name__ == '__main__':
    main()
