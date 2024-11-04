


import collections
import heapq
import re
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os


def vsInput():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


BUFSIZE = 8192


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
def input(): return sys.stdin.readline().rstrip("\r\n")






def value(): return tuple(map(int, input().split()))
def inlt(): return [int(i) for i in input().split()]
def inp(): return int(input())
def insr(): return input()
def stlt(): return [i for i in input().split()]







def printprimesSieve(n):
    prime = [True for i in range(n+1)]
    p = 2
    l = []
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    for p in range(2, n+1):
        if prime[p]:
            l.append(p)
            
        else:
            continue
    return l


def isPrime(n):
    prime_flag = 0

    if n > 1:
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                prime_flag = 1
                break
        if prime_flag == 0:
            return True
        else:
            return False
    else:
        return False


def gcdofarray(a):
    x = 0
    for p in a:
        x = math.gcd(x, p)
    return x


def printDivisors(n):
    i = 1
    ans = []
    while i <= math.sqrt(n):
        if (n % i == 0):
            if (n / i == i):
                ans.append(i)
            else:
                ans.append(i)
                ans.append(n // i)
        i = i + 1
    ans.sort()
    return ans


def binaryToDecimal(n):
    return int(n, 2)


def countTriplets(a, n):
    s = set()
    for i in range(n):
        s.add(a[i])
    count = 0
    for i in range(n):
        for j in range(i + 1, n, 1):
            xr = a[i] ^ a[j]
            if xr in s and xr != a[i] and xr != a[j]:
                count += 1
    return int(count // 3)


def countOdd(L, R):
    N = (R - L) // 2
    if (R % 2 != 0 or L % 2 != 0):
        N += 1
    return N


def isPalindrome(s):
    return s == s[::-1]


def sufsum(test_list):
    test_list.reverse()
    n = len(test_list)
    for i in range(1, n):
        test_list[i] = test_list[i] + test_list[i - 1]
    return test_list


def prsum(a):
    for i in range(1, len(a)):
        a[i] += a[i - 1]
    return a


def badachotabadachota(nums):
    nums.sort()
    i = 0
    j = len(nums) - 1
    ans = []
    cc = 0
    while len(ans) != len(nums):
        if cc % 2 == 0:
            ans.append(nums[j])
            j -= 1
        else:
            ans.append(nums[i])
            i += 1
        cc += 1
    return ans


def chotabadachotabada(nums):
    nums.sort()
    i = 0
    j = len(nums) - 1
    ans = []
    cc = 0
    while len(ans) != len(nums):
        if cc % 2 == 1:
            ans.append(nums[j])
            j -= 1
        else:
            ans.append(nums[i])
            i += 1
        cc += 1
    return ans


def primeFactors(n):
    ans = []
    while n % 2 == 0:
        ans.append(2)
        n = n // 2

    for i in range(3, int(math.sqrt(n))+1, 2):
        while n % i == 0:
            ans.append(i)
            n = n / i
    if n > 2:
        ans.append(n)
    return ans


def closestMultiple(n, x):
    if x > n:
        return x
    z = (int)(x / 2)
    n = n + z
    n = n - (n % x)
    return n


def getPairsCount(arr, n, sum):
    m = [0] * 1000
    for i in range(0, n):
        m[arr[i]] += 1
    twice_count = 0
    for i in range(0, n):
        twice_count += m[int(sum - arr[i])]
        if (int(sum - arr[i]) == arr[i]):
            twice_count -= 1
    return int(twice_count / 2)


def remove_consec_duplicates(test_list):
    res = [i[0] for i in itertools.groupby(test_list)]
    return res


def BigPower(a, b, mod):
    if b == 0:
        return 1
    ans = BigPower(a, b//2, mod)
    ans *= ans
    ans %= mod
    if b % 2:
        ans *= a
    return ans % mod


def nextPowerOf2(n):
    count = 0
    if (n and not(n & (n - 1))):
        return n
    while(n != 0):
        n >>= 1
        count += 1
    return 1 << count









def multiply(x, res, res_size):

    carry = 0  

    
    
    i = 0
    while i < res_size:
        prod = res[i] * x + carry
        res[i] = prod % 10  
        
        
        carry = prod//10  
        i = i + 1

    
    while (carry):
        res[res_size] = carry % 10
        
        
        carry = carry // 10
        res_size = res_size + 1

    return res_size


def Kadane(a, size):

    max_so_far = -1e18 - 1
    max_ending_here = 0

    for i in range(0, size):
        max_ending_here = max_ending_here + a[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here

        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far


def highestPowerof2(n):
    res = 0
    for i in range(n, 0, -1):
        if ((i & (i - 1)) == 0):
            res = i
            break
    return res


def lower_bound(numbers, length, searchnum):
    answer = -1
    start = 0
    end = length - 1

    while start <= end:
        middle = (start + end)//2
        if numbers[middle] == searchnum:
            answer = middle
            end = middle - 1
        elif numbers[middle] > searchnum:
            end = middle - 1
        else:
            start = middle + 1
    return answer


def MEX(nList, start):
    nList = set(nList)
    mex = start
    while mex in nList:
        mex += 1
    return mex


def MinValue(N, X):
    N = list(N)
    ln = len(N)
    position = ln + 1
    
    
    

    
    
    
    
    

    
    
    
    
    for i in range(ln - 1, -1, -1):
        if ((ord(N[i]) - ord('0')) > X):
            position = i

    
    c = chr(X + ord('0'))

    str = N.insert(position, c)

    
    return ''.join(N)


def findClosest(arr, n, target):
    if (target <= arr[0]):
        return arr[0]
    if (target >= arr[n - 1]):
        return arr[n - 1]
    i = 0
    j = n
    mid = 0
    while (i < j):
        mid = (i + j) // 2
        if (arr[mid] == target):
            return arr[mid]
        if (target < arr[mid]):
            if (mid > 0 and target > arr[mid - 1]):
                return getClosest(arr[mid - 1], arr[mid], target)
            j = mid
        else:
            if (mid < n - 1 and target < arr[mid + 1]):
                return getClosest(arr[mid], arr[mid + 1], target)
            i = mid + 1
    return arr[mid]


def getClosest(val1, val2, target):

    if (target - val1 >= val2 - target):
        return val2
    else:
        return val1





class Graph:
    def __init__(self, edges, n):
        self.adjList = [[] for _ in range(n)]
        for (src, dest) in edges:
            self.adjList[src].append(dest)
            self.adjList[dest].append(src)


def BFS(graph, v, discovered):
    q = collections.deque()
    discovered[v] = True
    q.append(v)
    ans = []
    while q:
        v = q.popleft()
        ans.append(v)
        
        for u in graph.adjList[v]:
            if not discovered[u]:
                discovered[u] = True
                q.append(u)
        return ans





def getsumFT(BITTree, i):
    s = 0  

    
    i = i+1

    
    while i > 0:

        
        s += BITTree[i]

        
        i -= i & (-i)
    return s






def updatebit(BITTree, n, i, v):

    
    i += 1

    
    while i <= n:

        
        BITTree[i] += v

        
        i += i & (-i)




def construct(arr, n):

    
    BITTree = [0]*(n+1)

    
    for i in range(n):
        updatebit(BITTree, n, i, arr[i])

    
    
    
    return BITTree








def getMid(s, e):
    return s + (e - s) // 2


""" A recursive function to get the sum of values
    in the given range of the array. The following
    are parameters for this function.

    st --> Pointer to segment tree
    si --> Index of current node in the segment tree.
        Initially 0 is passed as root is always at index 0
    ss & se --> Starting and ending indexes of the segment
                represented by current node, i.e., st[si]
    qs & qe --> Starting and ending indexes of query range """


def getSumUtil(st, ss, se, qs, qe, si):

    
    
    if (qs <= ss and qe >= se):
        return st[si]

    
    
    if (se < qs or ss > qe):
        return 0

    
    
    mid = getMid(ss, se)

    return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) + getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2)


""" A recursive function to update the nodes
which have the given index in their range.
The following are parameters st, si, ss and se
are same as getSumUtil()
i --> index of the element to be updated.
    This index is in the input array.
diff --> Value to be added to all nodes
which have i in range """


def updateValueUtil(st, ss, se, i, diff, si):

    
    
    if (i < ss or i > se):
        return

    
    
    st[si] = st[si] + diff

    if (se != ss):

        mid = getMid(ss, se)
        updateValueUtil(st, ss, mid, i,
                        diff, 2 * si + 1)
        updateValueUtil(st, mid + 1, se, i,
                        diff, 2 * si + 2)






def updateValue(arr, st, n, i, new_val):

    
    if (i < 0 or i > n - 1):

        print("Invalid Input", end="")
        return

    
    
    diff = new_val - arr[i]

    
    arr[i] = new_val

    
    updateValueUtil(st, 0, n - 1, i, diff, 0)






def getSumST(st, n, qs, qe):

    
    if (qs < 0 or qe > n - 1 or qs > qe):

        print("Invalid Input", end="")
        return -1

    return getSumUtil(st, 0, n - 1, qs, qe, 0)






def constructSTUtil(arr, ss, se, st, si):

    
    
    
    if (ss == se):

        st[si] = arr[ss]
        return arr[ss]

    
    
    
    mid = getMid(ss, se)

    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) + \
        constructSTUtil(arr, mid + 1, se, st, si * 2 + 2)

    return st[si]


""" Function to construct segment tree
from given array. This function allocates memory
for segment tree and calls constructSTUtil() to
fill the allocated memory """


def constructST(arr, n):

    

    
    x = (int)(math.ceil(math.log2(n)))

    
    max_size = 2 * (int)(2**x) - 1

    
    st = [0] * max_size

    
    constructSTUtil(arr, 0, n - 1, st, 0)

    
    return st






alphabets = list("abcdefghijklmnopqrstuvwxyz")
MOD = int(1e9 + 7)
INF = int(1e18)






for _ in range(inp()):
    n = inp()
    a = inlt()
    d = collections.Counter(a)
    buu = 1
    for i in d:
        if d[i] < 2:
            buu = 0
            break
    if buu == 0:
        print(-1)
        continue
    else:
        ans = []
        index = {}
        for i in range(n):
            if a[i] not in index:
                index[a[i]] = i
        
        for i in range(n):
            if i == n - 1 or a[i] != a[i + 1]:
                ans.append(index[a[i]] + 1)
            else:
                ans.append(i + 2)
        print(*ans)