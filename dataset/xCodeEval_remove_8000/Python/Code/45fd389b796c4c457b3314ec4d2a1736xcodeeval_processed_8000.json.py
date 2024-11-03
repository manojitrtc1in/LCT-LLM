


import math
import os

import sys

from decimal import *
from io import BytesIO, IOBase
import threading
from itertools import *
from collections import *
from array import *
import random
M = 10 ** 9 + 7
import heapq
import bisect
from functools import lru_cache
from queue import PriorityQueue
id24 = 8192
class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id24))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id24))
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




def id17(t):
    p = 0
    for i in t:
        if i == "(":
            p += 1
        else:
            p -= 1
        if p < 0:
            return False
    else:
        if p > 0:
            return False
        else:
            return True

def id25(arr, n, key):
    left = 0
    right = n - 1
    count = 0
    while (left <= right):
        mid = ((right + left) // 2)
        
        
        if (arr[mid] <= key):
            count = mid + 1
            left = mid + 1
        
        else:
            right = mid - 1
    return count



def binarySearch(arr, n, key):
    left = 0
    right = n - 1
    while (left <= right):
        mid = ((right + left) // 2)
        if arr[mid] == key:
            return mid
        if (arr[mid] <= key):
            left = mid + 1
        
        else:
            right = mid - 1
    return -1




def id20(arr,n,key):
    l,r=0,n-1
    while(l<=r):
        mid = (-l+r)//3 + l
        mid2 = mid + (-l+r)//3
        if arr[mid]==key:
            return mid
        if arr[mid2]==key:
            return mid2
        if arr[mid]>key:
            r=mid-1
        elif arr[mid2]<key:
            l=mid2+1
        else:
            l=mid+1
            r=mid2-1
    return -1

def reverse1(string):
    pp = ""
    for i in string[::-1]:
        pp += i
    if pp == string:
        return True
    return False

def reverse2(list1):
    l = []
    for i in list1[::-1]:
        l.append(i)
    if l == list1:
        return True
    return False

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




def roman_number(x):
    if x > 15999:
        return
    value = [5000, 4000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    symbol = ["F", "MF", "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
    roman = ""
    i = 0
    while x > 0:
        div = x // value[i]
        x = x % value[i]
        while div:
            roman += symbol[i]
            div -= 1
        i += 1
    return roman
def id8(s):
    for i in range(1, len(s)):
        if s[i - 1] > s[i]:
            return False
    return True


def id3(h, w):
    ct = 0
    for i in range(2, h + 1, 2):
        for j in range(2, w + 1, 2):
            ct += (h - i + 1) * (w - j + 1)
    return ct
def id27(h, w):
    return ((h * h) // 4) * ((w * w) // 4)

def binpow(a, b):
    if b == 0:
        return 1
    else:
        res = binpow(a, b // 2)
    if b % 2 != 0:
        return res * res * a
    else:
        return res * res





def id9(n):
    result = n
    i = 2
    while (i * i <= n):
        if (n % i == 0):
            while (n % i == 0):
                n //= i
            result -= result // i
        i += 1
    if (n > 1):
        result -= result // n
    return result


def id31(x,n,a):
    if x >= n and str(x).count("4") == str(x).count("7"):
        a.append(x)
    else:
        if x < 1e12:
            id31(x * 10 + 4,n,a)
            id31(x * 10 + 7,n,a)
    return a

def id28(x,l,r,a):
    if x>=l and x<=r:
        a.append(x)
    if x>r:
        a.append(x)
        return a
    if x < 1e10:
            id28(x * 10 + 4, l,r,a)
            id28(x * 10 + 7, l,r,a)
    return a

def id1(x, n, a):
    p = set(str(x))
    if len(p) <= 2:
        a.append(x)
    if x < n:
        id1(x + 1, n, a)
    return a



def interact(type, x):
    if type == "r":
        inp = input()
        return inp.strip()
    else:
        print(x, flush=True)

def id5(n):
    
    count = 0

    
    
    while (n >= 5):
        n //= 5
        count += n

    return count




def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]
        mergeSort(L)
        mergeSort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

def solven(p, l, a, b, n,res):  
    if p > n or l > 10:
        return
    if p > 0:
        res.add(p)
    solven(p * 10 + a, l + 1, a, b, n)
    solven(p * 10 + b, l + 1, a, b, n)


def id10(A, subset, index, d):
    print(*subset)
    s = sum(subset)
    d.append(s)
    for i in range(index, len(A)):
        subset.append(A[i])
        id10(A, subset, i + 1, d)
        subset.pop(-1)
    return d
def id21(arr, l, r, d, sum=0):
    if l > r:
        d.append(sum)
        return
    id21(arr, l + 1, r, d, sum + arr[l])
    
    id21(arr, l + 1, r, d, sum)
    return d

def id4(x):
    factors = []
    for i in range(1, x + 1):
        if x % i == 0:
            factors.append(i)
    return (factors)

def calc(X, d, ans, D):
    
    if len(X) == 0:
        return
    i = X.index(max(X))
    ans[D[max(X)]] = d
    Y = X[:i]
    Z = X[i + 1:]
    calc(Y, d + 1, ans, D)
    calc(Z, d + 1, ans, D)

def generate(st, s):
    if len(s) == 0:
        return
    if s not in st:
        st.add(s)
        for i in range(len(s)):
            t = list(s).copy()
            t.remove(s[i])
            t = ''.join(t)
            generate(st, t)
    return

def id11(A):
    l = [1]*len(A)
    for i in range(1,len(l)):
        for k in range(i):
            if A[k]<=A[i]:
                l[i]=max(l[i],l[k]+1)
    return max(l)

def findOR(nums, N):
    prefix_sum = 0
    result = 0
    for i in range(N):
        result |= nums[i]
        prefix_sum += nums[i]
        result |= prefix_sum
    return result
def OR(a, n):
    ans = a[0]
    for i in range(1, n):
        ans |= a[i]
        
    return ans
def toString(List):
    return ''.join(List)





def permute(a, l, r,p):
    if l == r:
        p.append(toString(a))
    else:
        for i in range(l, r + 1):
            a[l], a[i] = a[i], a[l]
            permute(a, l + 1, r,p)
            a[l], a[i] = a[i], a[l]  
def squareRoot(number, precision):
    start = 0
    end, ans = number, 1
    while (start <= end):
        mid = int((start + end) / 2)
        if (mid * mid == number):
            ans = mid
            break
        if (mid * mid < number):
            start = mid + 1
        else:
            end = mid - 1
    increment = 0.1
    for i in range(0, precision):
        while (ans * ans <= number):
            ans += increment
        ans = ans - increment
        increment = increment / 10
    return ans
def id6(l, w):
    squareSide = math.gcd(l, w)
    return int((l * w) / (squareSide * squareSide))




def id15(L, R):
    tmp = 0
    ans = 0
    n = int(math.log10(R) + 1)
    for i in range(0, n):
        
        tmp = tmp * 10 + 1
        for j in range(1, 10):

            if (L <= (tmp * j) and (tmp * j) <= R):
                
                
                ans += 1
    return ans

def id13(arr, low, high, x):
    
    if (arr[high] <= x):  
        return high
    if (arr[low] > x):  
        return low
    
    mid = (low + high) // 2
    if (arr[mid] <= x and arr[mid + 1] > x):
        return mid
    if (arr[mid] < x):
        return id13(arr, mid + 1, high, x)
    return id13(arr, low, mid - 1, x)
def Kclosest(arr, x, k, n,ans):
    
    l = id13(arr, 0, n - 1, x)
    r = l + 1
    count = 0
    if (arr[l] == x):
        l -= 1
    
    while (l >= 0 and r < n and count < k):
        if (x - arr[l] < arr[r] - x):
            ans.append(arr[l])
            l -= 1
        else:
            ans.append(arr[r])
            r += 1
        count += 1
    while (count < k and l >= 0):
        ans.append(arr[l])
        l -= 1
        count += 1
    while (count < k and r < n):
        ans.append(arr[r])
        r += 1
        count += 1
    return ans


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



def id22(x, n, a):
    if x > 0:
        a.append(x)
    if x > 10 ** 9:
        return a
    else:
        if x < 1e12:
            id22(x * 10 + 4, n, a)
            id22(x * 10 + 7, n, a)


def lcm(a, b):
    return (a * b) // math.gcd(a, b)


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



def buildPrefix(MAX,prefix):
    prime = [1] * (MAX + 1)
    p = 2
    while (p * p <= MAX):
        if (prime[p] == 1):
            i = p * 2
            while (i <= MAX):
                prime[i] = 0
                i += p
        p += 1
    for p in range(2, MAX + 1):
        prefix[p] = prefix[p - 1]
        if (prime[p] == 1):
            prefix[p] += 1
def query(L, R , prefix):
    return prefix[R] - prefix[L - 1]


def id2(a, size):
    id12 = a[0]
    curr_max = a[0]
    for i in range(1, size):
        curr_max = max(a[i], curr_max + a[i])
        id12 = max(id12, curr_max)
    return id12

def solvepp(n,k):
    if n==1 and k==1:
        return 0
    mid=(2**(n-1))//2
    if k<=mid:
        return solvepp(n-1,k)
    else:
        return solvepp(n-1,k-(mid))==0


def solvr(s,p):
    if len(s)==0:
        print(p,end=" ")
        return
    op1=p
    op2=p+s[0]
    s=s[1:]
    solvr(s,op1)
    solvr(s,op2)
    return

def id16(n,m,ans,l):
    if n==0 and m==0:
        print(ans)
        return
    if n!=0:
        op1=ans+"("
        id16(n-1,m,op1,l)
    if m>n:
        op2=ans+")"
        id16(n,m-1,op2,l)

def rse(arr, n):
    stack = []
    ans = []
    for i in range(n - 1, -1, -1):
        if len(stack) == 0:
            ans.append(n)
        else:
            while (len(stack) != 0):
                if stack[-1][0] >= arr[i]:
                    stack.pop()
                else:
                    break
            if len(stack) == 0:
                ans.append(n)
            else:
                ans.append(stack[-1][1])
        stack.append([arr[i], i])
    ans.reverse()
    return ans


def lse(arr, n):
    stack = []
    ans = []
    for i in range(n):
        if len(stack) == 0:
            ans.append(-1)
        else:
            while (len(stack) != 0):
                if stack[-1][0] >= arr[i]:
                    stack.pop()
                else:
                    break
            if len(stack) == 0:
                ans.append(-1)
            else:
                ans.append(stack[-1][1])
        stack.append([arr[i], i])
    return ans


def mah(arr):
    max1 = 0
    p = rse(arr, len(arr))
    q = lse(arr, len(arr))
    for i in range(len(arr)):
        a = (p[i] - q[i] - 1) * arr[i]
        max1 = max(a, max1)
    return max1

def lcs(s,r):
    rr=len(r)
    ss=len(s)
    l=[[0]*(rr+1) for i in range(ss+1)]
    for i in range(1,ss+1):
        for j in range(1,rr+1):
            if s[i-1]==r[j-1]:
                l[i][j]=l[i-1][j-1]+1
            else:
                l[i][j] =max(l[i-1][j],l[i][j-1])
    return l[ss][rr]


def id29(arr,sum,len):
    dp=[[False]*(sum+1) for i in range(len+1)]
    for i in range(len+1):
        dp[i][0]=True
    for i in range(1,len+1):
        for j in range(1,sum+1):
            
            if arr[i-1]>j:
                dp[i][j]=dp[i-1][j]
            else:
                dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]]
    return dp[len][sum]

def id19(cost,n,m):
    dp = [[0 for x in range(m)] for x in range(n)]
    for i in range(n):
        for j in range(m):
            if i==0 and j==0:
                dp[i][j]=cost[i][j]
            elif i==0 and j!=0:
                dp[i][j]=dp[i][j-1]+cost[i][j]
            elif j==0 and i!=0:
                dp[i][j]=dp[i-1][j]+cost[i][j]
            else:
                dp[i][j] = cost[i][j] + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
    return dp[n-1][m-1]

def coinchange(n,arr,len1):
    dp=[0]*(n+1)
    dp[0]=1
    for i in range(len1):
        for j in range(arr[i],n+1):
            dp[j]+=dp[j-arr[i]]
    return dp[n]

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
def id26(arr, n):
    msis = arr.copy()
    for i in range(1, n):
        for j in range(i):
            if (arr[i] > arr[j] and
                    msis[i] < msis[j] + arr[i]):
                msis[i] = msis[j] + arr[i]
    c = max(msis)
    p = 5
    return c



def id14(arr, target):
    lo = 0
    hi = len(arr) - 1
    while (lo <= hi):
        mid = (lo + hi) // 2
        
        if arr[mid] == target:
            if mid != len(arr) - 1:
                if arr[mid + 1] != target:
                    return mid
                else:
                    lo += 1
            else:
                return mid
            continue
        if arr[mid] > target:
            hi = mid - 1
        else:
            lo = mid + 1


def nge(arr, n):
    stack = []
    ans = []
    for i in range(n - 1, -1, -1):
        if len(stack) == 0:
            ans.append(-1)
        else:
            while (len(stack) > 0):
                if stack[-1][0] < arr[i]:
                    stack.pop()
                else:
                    break
            if len(stack) == 0:
                ans.append(-1)
            else:
                ans.append(stack[-1][1])
        stack.append([arr[i], i])
    ans.reverse()
    return ans

def nse(arr,n):
    stack=[]
    ans=[]
    for i in range(n-1,-1,-1):
        if len(stack)==0:
            ans.append(-1)
        else:
            while(len(stack)>0):
                if stack[-1][0] > arr[i]:
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

def alperm(nums, path, result):
    if not nums:
        result.add(tuple(path))
        return
    for i in range(0, len(nums)):
        alperm(nums[:i] + nums[i + 1:], path + [nums[i]], result)
    return result


def minsum(arr, n, m, res, l):
    if n == 1 and m == 1:
        res += arr[0][0]
        l.append(res)
    else:
        if n != 1:
            p = res + arr[n - 1][m - 1]
            minsum(arr, n - 1, m, p, l)
        if m != 1:
            p = res + arr[n - 1][m - 1]
            minsum(arr, n, m - 1, p, l)
    return min(l)



def id30(n):
    if (n == 0 or n == 1):
        return 1
    id30 = [0] * (n + 1)
    id30[0] = 1
    id30[1] = 1
    for i in range(2, n + 1):
        for j in range(i):
            id30[i] += id30[j] * id30[i - j - 1]
    return id30[n]





def id7(graph, start, end, path):
    path = path + [start]
    if start == end:
        return path
    if start not in graph:
        return None
    shortest = None
    for node in graph[start]:
        if node not in path:
            newpath = id7(graph, node, end, path)
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
    if n == 3:
        return True
    d = n - 1
    while (d % 2 == 0):
        d //= 2
    for i in range(5):
        if test(n, d) == False:
            return False
    return True





def muin(a, m):
    x, y, mo = 1, 0, m
    if m == 1:
        return 0
    while (m > 0):
        x, y = y, x - (a // m) * y
        a, m = m, a % m
    if x < 0:
        return mo + x
    else:
        return x


def good(l, c):
    ch = chr(c)
    if len(l) == 1:
        return (1 if ch != l[0] else 0)
    k = len(l) // 2
    lm = k - l[:k].count(ch) + good(l[k:], c + 1)
    rm = k - l[k:].count(ch) + good(l[:k], c + 1)
    return (min(lm, rm))


def facto(fact):
    fact[0], fact[1] = 1, 1
    for i in range(2, 10 ** 5 + 1):
        fact[i] = (fact[i - 1] * i) % M


def comb(n, r, fact):
    return (fact[n] * pow(fact[n - r] * fact[r], M - 2, M)) % M


def id23(n, b):
    if n == 0:
        return 0
    digits = []
    while n:
        digits.append((n % b))
        n //= b
    return sum(digits)

def id18(prime,maxn):
    prime[0],prime[1] = False,False
    for i in range(2,int(math.sqrt(maxn))+1):
        if prime[i]==True:
            for j in range(i*i,maxn+1,i):
                prime[j]=False

def sieve(spf):
    MAXN = 100001
    spf[1] = 1
    for i in range(2, MAXN):
        spf[i] = i
    for i in range(4, MAXN, 2):
        spf[i] = 2
    for i in range(3, math.ceil(math.sqrt(MAXN))):
        if (spf[i] == i):
            for j in range(i*i, MAXN, i):
                if (spf[j] == j):
                    spf[j] = i
def id32(x,spf):
    ret = list()
    while (x != 1):
        
        ret.append(spf[x])
        x = x // spf[x]
    return ret


def possible(c1,c2,c3,arr):
    for a in arr:
        flag = False
        for x1 in range(c1 + 1):
            for x2 in range(c2 + 1):
                r = a - x1 - 2 * x2
                if r < 0:
                    continue
                if r % 3 != 0:
                    continue
                x3 = r // 3
                if 0 <= x3 <= c3:
                    flag = True
        if not flag:
            return False
    return True


def main():
    tt = 1
    tt = inpu()
    
    
    for _ in range(tt):
        n=inpu()
        arr=lis()
        ans = float("inf")
        max1 = max(arr)
        for i in range(4):
            for j in range(4):
                k=(max1-i-j*2+2)//3
                if possible(i,j,k,arr):
                    ans = min(ans,i+j+k)
        print(ans)

if __name__ == '__main__':
    
    
    main()
