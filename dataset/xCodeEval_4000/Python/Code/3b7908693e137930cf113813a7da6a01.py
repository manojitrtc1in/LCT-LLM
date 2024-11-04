
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


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
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




def regularbracket(t):
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



def binarySearchCount(arr, n, key):
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


def sumofdigits(n):
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


def soretd(s):
    for i in range(1, len(s)):
        if s[i - 1] > s[i]:
            return False
    return True




def countRhombi(h, w):
    ct = 0
    for i in range(2, h + 1, 2):
        for j in range(2, w + 1, 2):
            ct += (h - i + 1) * (w - j + 1)
    return ct


def countrhombi2(h, w):
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



def binpowmodulus(a, b, m):
    a %= m
    res = 1
    while (b > 0):
        if (b & 1):
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res



def coprime_to_n(n):
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


def luckynumwithequalnumberoffourandseven(x, n, a):
    if x >= n and str(x).count("4") == str(x).count("7"):
        a.append(x)
    else:
        if x < 1e12:
            luckynumwithequalnumberoffourandseven(x * 10 + 4, n, a)
            luckynumwithequalnumberoffourandseven(x * 10 + 7, n, a)
    return a


def luckynuber(x, n, a):
    p = set(str(x))
    if len(p) <= 2:
        a.append(x)
    if x < n:
        luckynuber(x + 1, n, a)
    return a




def interact(type, x):
    if type == "r":
        inp = input()
        return inp.strip()
    else:
        print(x, flush=True)



def findTrailingZeros(n):
    
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



"""
n = int(input())
for a in range(0, 10):
    for b in range(0, a):
        solve(0, 0)
print(len(res))
"""









def subsetsUtil(A, subset, index, d):
    print(*subset)
    s = sum(subset)
    d.append(s)
    for i in range(index, len(A)):
        
        subset.append(A[i])

        
        subsetsUtil(A, subset, i + 1, d)

        
        
        subset.pop(-1)
    return d


def subsetSums(arr, l, r, d, sum=0):
    if l > r:
        d.append(sum)
        return
    subsetSums(arr, l + 1, r, d, sum + arr[l])

    
    subsetSums(arr, l + 1, r, d, sum)
    return d


def print_factors(x):
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


def largestincreasingsubsequence(A):
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
"""
def main():
    n = inpu()
    arr = lis()
    l=[]
    p=[]
    q=[]
    for i in range(len(arr)):
        q.append([arr[i],i+1])
    
    q.sort()
    
    for i in range(0,n,2):
        l.append(q[i][1])
    for i in range(1,n,2):
        p.append(q[i][1])
    print(len(l))
    print(*l)
    print(len(p))
    print(*p)
if __name__ == '__main__':
    main()
"""
"""
def main():
    n=inpu()
    arr = lis()
    a=0
    b=sum(arr)
    cnt=0
    for i in range(len(arr)):
        a+=arr[i]
        b-=arr[i]
        
        if a==b:
            cnt+=1
    if a!=0:
        print(cnt)
    else:
        print(cnt-1)
if __name__ == '__main__':
    main()
"""
"""
def main():
    n = inpu()
    arr = lis()
    print(max(((sum(arr) - 1) // (n - 1)) + 1, max(arr)))
if __name__ == '__main__':
    main()
"""
"""
def main():
    n = int(input())
    val = [0] * (n + 1)
    add = [0] * (n + 1)
    ptr = 1
    sum = 0
    res = [0] * n
    for i in range(n):
        l = lis()
        if l[0] == 1:
            a, x = l[1:]
            add[a - 1] += x
            sum += a * x
        elif l[0] == 2:
            k = l[1]
            val[ptr] = k
            sum += k
            ptr += 1
        else:
            ptr -= 1
            sum -= val[ptr]
            sum -= add[ptr]
            add[ptr - 1] += add[ptr]
            add[ptr] = 0
        res[i] = sum / ptr
    print('\n'.join(str(x) for x in res))
if __name__ == '__main__':
    main()
"""
"""
def main():
    n,k=sep()
    arr=lis()
    arr = sorted(arr)
    l = 0
    s = 0
    ans = 1
    best = arr[0]
    for i in range(1, n):
        s += (i - l) * (arr[i] - arr[i - 1])
        while s > k:
            s -= arr[i] - arr[l]
            l += 1
        if i - l + 1 > ans:
            ans = i - l + 1
            best = arr[i]
    print(ans, best)
if __name__ == '__main__':
    main()
"""
"""
def main():
    t = inpu()
    for _ in range(t):
        n = inpu()
        arr = lis()
        mergeSort(arr)
        while arr:
            print(arr)
            print(arr.pop(len(arr) // 2),end=" ")
        print()
if __name__ == '__main__':
    main()
"""
"""
import math
def main():
    n = int(input())
    a = 0
    s = []
    p = 1
    for i in range(n):
        if math.gcd(i, n) == 1:
            a += 1
            s += [i]
            p *= i
            p %= n
    if p != 1:
        a -= 1
        s.remove(p)
    print(a)
    print(*s)
if __name__ == '__main__':
    main()
"""
"""
def main():
    t = inpu()
    for _ in range(t):
        n = inpu()
        arr = lis()
        arr.sort()
        
        c = n//2
        for i in range(n):
            if i%2==0:
                c+=i
            else:
                c-=i
            print(arr[c],end=" ")
        print()
if __name__ == '__main__':
    main()
"""
"""
def main():
    n,d = sep()
    arr = lis()
    arr+=[1e16]
    a = i = j = 0
    while i < n - 1:
        while arr[j] - arr[i] <= d:j += 1
        a += (j - i - 1) * (j - i - 2) // 2
        i += 1
    print(a)
if __name__ == '__main__':
    main()
"""
"""
def main():
    t = inpu()
    for _ in range(t):
        a,k = sep()
        i=0
        while(i<k-1):
            b = str(a)
            if "0" in b:
                break
            a+=(int(max(b))*(int(min(b))))
            i+=1
        print(a)
if __name__ == '__main__':
    main()
"""
def main():
    t = inpu()
    for _ in range(t):
        n = inpu()
        s=inp()
        cnt=s.count("1")
        if s[0] == '0' or s[-1] == '0' or cnt & 1:
            print("NO")
            continue
        u, v = [')'] * n, [')'] * n
        h = 1
        for i in range(len(s)):
            if s[i] == '1':
                if cnt > 0:
                    u[i] = v[i] = '('
                    cnt -= 2
            else:
                if h:
                    u[i] = '('
                else:
                    v[i] = '('
                h ^= 1
        print("YES")
        print("".join(u))
        print("".join(v))
if __name__ == '__main__':
    main()
