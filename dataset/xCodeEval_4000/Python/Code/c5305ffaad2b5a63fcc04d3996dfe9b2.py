
from __future__ import division, print_function
import math
import os
import sys
from fractions import *
from sys import *
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



"""
def main():
    t = inpu()
    for _ in range(t):
        a,b,c = sep()
        l=[a,b,c]
        l.sort()
        if sum(l)%9==0 and l[0]>=sum(l)//9:
            print("YES")
        else:
            print("NO")
if __name__ == '__main__':
    main()

46417578 46590175 7599314
"""
"""
def main():
    t = inpu()
    for _ in range(t):
        s = inp()
        p=0
        cnt=len(s)
        q=0
        for i in range(cnt):
            if s[i] =="+":
                p+=1
            else:
                q+=1
            if q>p:
                cnt+=(i+1)
                q-=1
        print(cnt)
if __name__ == '__main__':
    main()
"""
"""
def main():
    t=inpu()
    for _ in range(t):
        n=inpu()
        i=1
        cnt=0
        i=1
        while(True):
            b = ((i*i)-1)/2
            if b>=n:
                break
            if b==int(b) and b>=1 and 1+b<=n:
                cnt+=1
            i+=2
        print(cnt)
if __name__ == '__main__':
    main()
"""
"""
def main():
    n = inpu()
    x=1
    while int(bin(x).replace("0b","")) <= n:
        x += 1
    print(x-1)
if __name__ == '__main__':
    main()
"""
"""
def main():
    a = [i for i, j in enumerate(input(), 1) if j == '1']
    m = int(input())
    q = [(-1, 0, 0, [])]
    p = 'NO'
    while q:
        x, y, z, t = q.pop()
        if z == m:
            p = 'YES\n' + ' '.join(map(str, t))
            break
        for i in a:
            if i != x and i > y:
                q.append((i, i - y, z + 1, t + [i]))
    print(p)
if __name__ == '__main__':
    main()
"""
"""
def main():
    t=inpu()
    for _ in range(t):
        n=inpu()
        arr=lis()
        i = k = 0
        while k < len(arr):
                k += 1
                j = arr.index(k)
                if j >= i:
                    arr.insert(i, arr.pop(j))
                    if i==j:
                        i=i+1
                    else:
                        i=j
        print(*arr)
if __name__ == '__main__':
    main()
"""
"""
def main():
    for _ in range(inpu()):
        n, m = sep()
        l = []
        sum = 0
        for i in range(n):
            l.append(list(sep()))
        for i in range(n):
            for j in range(m):
                a = list(sorted([l[i][j], l[n - i - 1][j], l[i][m - j - 1], l[n - i - 1][m - j - 1]]))
                
                sum += (a[3] + a[2] - a[1] - a[0])
                
        print(sum // 4)
        print(l)
if __name__ == '__main__':
    main()
"""


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


"""
def main():
    n = inp()
    st = set()
    generate(st,n)
    l=[]
    print(st)
    for i in st:
        i = list(i)
        for j in (i):
            if j == "0":
                i.remove(j)
            else:
                break
        ans = ""
        for pp in i:
            ans += pp
        print(ans + "---------------")
        if len(ans)>0:
            if prime(int(ans))==True and reverse1(ans)==True:
                print(ans)
                l.append(int(ans))
    l = set(l)
    l=list(l)
    print(l)
    i=0
    while(i<len(l)):
        if l[i]==0:
            l.remove(l[i])
        else:
            i+=1
    if len(l)==0:
        print(-1)
    else:
        l.sort()
        for i in l:
            print(i,end=" ")
if __name__ == '__main__':
    main()
"""
"""
def main():
    t = int(input())
    for _ in range(t):
            a, b = sep()
            s=list(inp())
            flag = 1

            for i in range(len(s)):
                if s[i] == "0":
                    if s[len(s) - 1 - i] == "1":
                        flag = 0
                        break
                    else:
                        s[len(s) - 1 - i] = "0"
                elif s[i] == "1":
                    if s[len(s) - 1 - i] == "0":
                        flag = 0
                        break
                    else:
                        s[len(s) - 1 - i] = "1"

            if flag == 0:
                print(-1)
                continue

            for ss in s:
                if ss == "0":
                    a -= 1
                elif ss == "1":
                    b -= 1

            if a < 0 or b < 0:
                print(-1)
                continue

            if s[len(s) // 2] == "?":
                if a % 2 == 1:
                    s[len(s) // 2] = "0"
                    a -= 1
                elif b % 2 == 1:
                    s[len(s) // 2] = "1"
                    b -= 1

            if a % 2 == 1 or b % 2 == 1:
                print(-1)
                continue

            for i in range(len(s)):
                if s[i] == "?":
                    if a > 0:
                        s[i] = "0"
                        s[len(s) - 1 - i] = "0"
                        a -= 2
                    else:
                        s[i] = "1"
                        s[len(s)- 1 - i] = "1"

            print("".join(s))
if __name__ == '__main__':
    main()
"""
"""
def main():
    t = inpu()
    for _ in range(t):
        n = inpu()
        l=[]
        for i in range(n):
            arr = list(input())
            l.append(arr)
        ans=[]
        for i in range(n):
            for j in range(n):
                if l[i][j]=="*":
                    ans.append([i,j])
        
        if ans[0][0]==ans[1][0]:
            if ans[0][0]==0:
                
                l[1][ans[0][1]]="*"
                l[1][ans[1][1]]="*"
            else:
                l[0][ans[0][1]] = "*"
                l[0][ans[1][1]] = "*"
        elif ans[0][1]==ans[1][1]:
            if ans[0][1]==0:
                l[ans[0][0]][1]="*"
                l[ans[1][0]][1]="*"
            else:
                l[ans[0][0]][0] = "*"
                l[ans[1][0]][0] = "*"
        else:
            l[ans[0][0]][ans[1][1]]="*"
            l[ans[1][0]][ans[0][1]]="*"
        
        for i in range(n):
            for j in range(n):
                print(l[i][j],end="")
            print()
if __name__ == '__main__':
    main()
"""
"""
def main():
    t=inpu()
    for _ in range(t):
        n=inpu()
        arr=lis()
        arr.sort()
        n+=2
        s1 = sum(arr[:n-2])
        if s1==arr[n-2]:
            print(*arr[:n-2])
        elif s1==arr[n-1]:
            print(*arr[:n-2])
        else:
            for i in range(len(arr)-2):
                c=s1
                c-=arr[i]
                d=c
                c+=arr[n-2]
                if c==arr[n-1]:
                    arr.remove(arr[i])
                    arr.remove(arr[len(arr)-1])
                    print(*arr)
                    break
            else:
                print(-1)
if __name__ == '__main__':
    main()
"""
"""
def main():
    t=inpu()
    for _ in range(t):
        n = inpu()
        a = lis()
        mod = 1000000007
        x = a[0]
        for i in range(1, n):
            x &= a[i]
        
        cnt = a.count(x)
        if cnt < 2:
            print(0)
        else:
            first = (cnt * (cnt - 1))
            second = math.factorial(n - 2)
            print((first * second) % mod)
if __name__ == '__main__':
    main()
"""
"""
def main():
    t = inpu()
    for _ in range(t):
        n=inpu()
        arr=lis()
        l=[]
        ans=[]
        if arr[0]!=min(arr):
            ans.append(min(arr))
        else:
            ans.append(arr[1])
        for i in range(1,n):
            l.append(arr[i]+arr[i-1])
        
        for i in range(n-1):
            ans.append(l[i]-ans[i])
        print(*ans)
if __name__ == '__main__':
    main()
"""


def main():
    t = int(input())
    for tests in range(t):
        n, l, r, s = map(int, input().split())

        x = r - l + 1

        if x * (x + 1) // 2 <= s <= (n + n - x + 1) * x // 2:
            True
        else:
            print(-1)
            continue

        ANS = list(range(1, x + 1))
        ANS.reverse()
        SUM = x * (x + 1) // 2
        rest = s - SUM
        MAX = n

        i = 0
        while rest:
            k = min(MAX, ANS[i] + rest)
            rest -= k - ANS[i]
            ANS[i] = k
            i += 1
            MAX -= 1

        

        ANS2 = [-1] * n
        USE = [0] * (n + 3)
        USE[0] = 1

        j = 0

        for i in range(l - 1, r):
            ANS2[i] = ANS[j]
            j += 1
            USE[ANS2[i]] = 1

        j = 0

        for i in range(n):
            while USE[j] == 1:
                j += 1
            if ANS2[i] == -1:
                ANS2[i] = j
                j += 1
        print(*ANS2)
if __name__ == '__main__':
    main()

"""
def main():
    mxn = 2 * (10 ** 5) + 10
    mod = 10 ** 9 + 7
    dp = [1] * mxn
    for i in range(10, mxn):
        dp[i] = (dp[i - 9] + dp[i - 10]) % mod
    for test in range(int(input())):
        n, k = sep()
        ans = 0
        while n:
            ans = (ans + dp[k + n % 10]) % mod
            n //= 10
        print(ans)
if __name__ == '__main__':
    main()
"""
