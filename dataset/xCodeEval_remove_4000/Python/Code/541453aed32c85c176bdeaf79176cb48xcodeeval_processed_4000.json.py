
from __future__ import division, print_function
import math
import os
import sys
from fractions import *
from sys import *
from decimal import *
from io import BytesIO, IOBase
from itertools import *
from collections import *


M = 10 ** 9 + 7


if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip




id12 = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id12))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id12))
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




def id9(t):
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



def id15(arr, n, key):
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


def mex(list1):
    
    p = max(list1) + 1
    for i in range(len(list1)):
        if list1[i] != i:
            p = i
            break
    return p


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


def id5(s):
    for i in range(1, len(s)):
        if s[i - 1] > s[i]:
            return False
    return True




def id2(h, w):
    ct = 0
    for i in range(2, h + 1, 2):
        for j in range(2, w + 1, 2):
            ct += (h - i + 1) * (w - j + 1)
    return ct


def id13(h, w):
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



def id10(a, b, m):
    a %= m
    res = 1
    while (b > 0):
        if (b & 1):
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res



def id6(n):
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



def prime(x):
    if x == 1:
        return False
    else:
        for i in range(2, int(math.sqrt(x)) + 1):
            
            if (x % i == 0):
                return False
        else:
            return True

def id16(x,n,a):
    if x >= n and str(x).count("4") == str(x).count("7"):
        a.append(x)
    else:
        if x < 1e12:
            id16(x * 10 + 4,n,a)
            id16(x * 10 + 7,n,a)
    return a

def id14(x,l,r,a):
    if x>=l and x<=r:
        a.append(x)
    if x>r:
        a.append(x)
        return a
    if x < 1e10:
            id14(x * 10 + 4, l,r,a)
            id14(x * 10 + 7, l,r,a)
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



def id4(n):
    
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



res = set()


def solven(p, l, a, b, n):  
    if p > n or l > 10:
        return
    if p > 0:
        res.add(p)
    solven(p * 10 + a, l + 1, a, b, n)
    solven(p * 10 + b, l + 1, a, b, n)













def id7(A, subset, index, d):
    print(*subset)
    s = sum(subset)
    d.append(s)
    for i in range(index, len(A)):
        
        subset.append(A[i])

        
        id7(A, subset, i + 1, d)

        
        
        subset.pop(-1)
    return d


def id11(arr, l, r, d, sum=0):
    if l > r:
        d.append(sum)
        return
    id11(arr, l + 1, r, d, sum + arr[l])

    
    id11(arr, l + 1, r, d, sum)
    return d


def id3(x):
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




def factorization(n, l):
    c = n
    if prime(n) == True:
        l.append(n)
        return l
    for i in range(2, c):
        if n == 1:
            break
        while n % i == 0:
            l.append(i)
            n = n // i
    return l





def good(b):
    l = []
    i = 0
    while (len(b) != 0):
        if b[i] < b[len(b) - 1 - i]:
            l.append(b[i])
            b.remove(b[i])
        else:
            l.append(b[len(b) - 1 - i])
            b.remove(b[len(b) - 1 - i])
    if l == sorted(l):
        
        return True
    return False




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


def id8(A):
    l = [1]*len(A)
    sub=[]
    for i in range(1,len(l)):
        for k in range(i):
            if A[k]<A[i]:
                sub.append(l[k])
        l[i]=1+max(sub,default=0)
    return max(l,default=0)












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













def main():
    n = inpu()
    arr = lis()
    ans = [[0]*n for i in range(n)]
    flag = 0
    for i in range(n):
        x, y = i, i
        
        ans[x][y] = arr[i]
        for j in range(arr[i] - 1):
            f1 = 0
            if (y > 0 and ans[x][y - 1] == 0):
        
                f1 = 1
                x, y = x, y - 1

            elif (x < (n - 1) and ans[x + 1][y] == 0):
        
                f1 = 1
                x, y = x + 1, y

            if (f1 == 0):
                flag = 1
                break
            ans[x][y] = arr[i]
        if (flag == 1):
            break

    if (flag == 1):
        print(-1)

    else:
        for i in range(n):
            for j in range(i+1):
                print(ans[i][j],end=" ")
            print()
if __name__ == '__main__':
    main()
