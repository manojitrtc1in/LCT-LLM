import sys
import math
import random
from collections import defaultdict

MOD = int(1e9 + 7)

def main():
    test = 1
    while test > 0:
        solve()
        test -= 1

def solve():
    s = input().strip()
    t = input().strip()
    n = len(s)
    m = len(t)
    pre = [0] * m
    suf = [0] * m

    j = 0
    for i in range(m):
        while s[j] != t[i]:
            j += 1
        pre[i] = j
        j += 1

    j = n - 1
    for i in range(m - 1, -1, -1):
        while s[j] != t[i]:
            j -= 1
        suf[i] = j
        j -= 1

    ans = max(suf[0], n - 1 - pre[m - 1])
    for i in range(m - 1):
        ans = max(ans, suf[i + 1] - 1 - pre[i])

    print(ans)

class Node:
    def __init__(self):
        self.connect = []
        self.comp = -1

    def gsize(self):
        return len(self.connect)

def nC2(n):
    return add((n * (n + 1)) // 2, 0)

def maxRight(x, a):
    l = -1
    r = len(a)

    while r - l > 1:
        m = l + (r - l) // 2
        if a[m] <= x:
            l = m
        else:
            r = m
    return l + 1

def minLeft(x, a):
    l = -1
    r = len(a)

    while r - l > 1:
        m = l + (r - l) // 2
        if a[m] < x:
            l = m
        else:
            r = m
    return r + 1

def lowerBound(key, a):
    s = 0
    e = len(a) - 1
    if e == -1:
        return 0
    ans = -1
    while s <= e:
        m = s + (e - s) // 2
        if a[m] >= key:
            ans = m
            e = m - 1
        else:
            s = m + 1
    return ans if ans != -1 else s

def upperBound(key, a):
    s = 0
    e = len(a) - 1
    if e == -1:
        return 0
    ans = -1
    while s <= e:
        m = s + (e - s) // 2
        if a[m] > key:
            ans = m
            e = m - 1
        else:
            s = m + 1
    return ans if ans != -1 else s

def c2(n):
    if n % 2 == 0:
        return mul(n // 2, n - 1)
    else:
        return mul(n, (n - 1) // 2)

def mul(a, b):
    return (a % MOD) * (b % MOD) % MOD

def add(a, b):
    return (a % MOD + b % MOD) % MOD

def sub(a, b):
    return (a % MOD - b % MOD) % MOD

def primeFactors(n):
    arr = []
    if n % 2 == 0:
        arr.append(2)
    while n % 2 == 0:
        n //= 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        flag = 0
        while n % i == 0:
            n //= i
            flag = 1
        if flag == 1:
            arr.append(i)
    if n > 2:
        arr.append(n)
    return arr

class Pair:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.len = y - x + 1

    def __lt__(self, other):
        if self.x == other.x:
            return self.y < other.y
        return self.x > other.x

class TPair:
    def __init__(self, l, r, index):
        self.l = l
        self.r = r
        self.index = index

    def __lt__(self, other):
        if self.l == other.l:
            return self.r < other.r
        return self.l > other.l

facts = []
factInvs = []

def exp(base, e):
    if e == 0:
        return 1
    half = exp(base, e // 2)
    if e % 2 == 0:
        return mul(half, half)
    return mul(half, mul(half, base))

def modInv(x):
    return exp(x, MOD - 2)

def precomp():
    global facts, factInvs
    facts = [0] * 1_000_000
    factInvs = [0] * 1_000_000
    factInvs[0] = facts[0] = 1
    for i in range(1, len(facts)):
        facts[i] = mul(facts[i - 1], i)
    factInvs[len(facts) - 1] = modInv(facts[len(facts) - 1])
    for i in range(len(facts) - 2, -1, -1):
        factInvs[i] = mul(factInvs[i + 1], i + 1)

def nCk(n, k):
    return mul(facts[n], mul(factInvs[k], factInvs[n - k]))

def maxSubArraySum(a):
    if len(a) == 0:
        return 0
    max_so_far = a[0]
    curr_max = a[0]
    for i in range(1, len(a)):
        curr_max = max(a[i], curr_max + a[i])
        max_so_far = max(max_so_far, curr_max)
    return max_so_far

def ruffleSort(a):
    n = len(a)
    for i in range(n):
        oi = random.randint(0, n - 1)
        a[oi], a[i] = a[i], a[oi]
    a.sort()

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m

    L = [0] * n1
    R = [0] * n2

    for i in range(n1):
        L[i] = arr[l + i]
    for j in range(n2):
        R[j] = arr[m + 1 + j]

    i = 0
    j = 0
    k = l
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def sort(arr, l, r):
    if l < r:
        m = (l + r) // 2
        sort(arr, l, m)
        sort(arr, m + 1, r)
        merge(arr, l, m, r)

def countSetBits(n):
    if n == 0:
        return 0
    return 1 + countSetBits(n & (n - 1))

def factorial(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    if n == 3:
        return 6
    return n * factorial(n - 1)

def gcd(A, B):
    if B == 0:
        return A
    return gcd(B, A % B)

def fastExpo(x, n):
    if n == 0:
        return 1
    if n % 2 == 0:
        return fastExpo((x * x) % MOD, n // 2) % MOD
    return (x % MOD) * fastExpo((x * x) % MOD, (n - 1) // 2) % MOD

def isPrime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(5, int(math.sqrt(n)) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False
    return True

def reverse(arr, l, r):
    arr[l:r] = reversed(arr[l:r])

def print1d(arr):
    print(arr)

def print2d(arr):
    for a in arr:
        print(a)

def findPrimes(n):
    isPrime = [True] * (n + 1)
    a = []
    result = []
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, int(math.sqrt(n)) + 1):
        if isPrime[i]:
            for j in range(i * i, n + 1, i):
                isPrime[j] = False
    for i in range(n + 1):
        if isPrime[i]:
            a.append(i)
    result = list(a)
    return result

def indiFactors(n):
    A = [[] for _ in range(n + 1)]
    sieve = [0] * (n + 1)
    for i in range(2, n + 1):
        if sieve[i] == 0:
            for j in range(i, n + 1, i):
                if sieve[j] == 0:
                    A[j].append(i)
    return A

def segmentedSieve(l, r):
    segSieve = [True] * (r - l + 1)
    prePrimes = findPrimes(int(math.sqrt(r)))
    for p in prePrimes:
        low = (l // p) * p
        if low < l:
            low += p
        if low == p:
            low += p
        for j in range(low, r + 1, p):
            segSieve[j - l] = False
    if l == 1:
        segSieve[0] = False
    return segSieve

def countCoprimes(n):
    prime_factors = []
    x = n
    flag = 0
    while x % 2 == 0:
        if flag == 0:
            prime_factors.append(2)
        flag = 1
        x //= 2
    for i in range(3, int(math.sqrt(x)) + 1, 2):
        flag = 0
        while x % i == 0:
            if flag == 0:
                prime_factors.append(i)
            flag = 1
            x //= i
    if x > 2:
        prime_factors.append(x)
    ans = float(n)
    for p in prime_factors:
        ans *= (1.0 - 1.0 / p)
    return int(ans)

modulo = int(1e9 + 7)

def modinv(x):
    return modpow(x, modulo - 2)

def modpow(a, b):
    if b == 0:
        return 1
    x = modpow(a, b // 2)
    x = (x * x) % modulo
    if b % 2 == 1:
        return (x * a) % modulo
    return x

class FastReader:
    def __init__(self):
        self.br = sys.stdin
        self.st = None

    def next(self):
        while self.st is None or not self.st:
            self.st = self.br.readline().strip().split()
        return self.st.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLong(self):
        return int(self.next())

    def nextLine(self):
        return self.br.readline().strip()

if __name__ == "__main__":
    main()
