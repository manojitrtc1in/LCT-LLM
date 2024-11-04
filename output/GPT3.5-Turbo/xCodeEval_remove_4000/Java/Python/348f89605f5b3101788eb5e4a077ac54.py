import heapq

mod = 1000000007
mod2 = 998244353

class FastReader:
    def __init__(self):
        self.br = iter(input().split())
    
    def next(self):
        return next(self.br)
    
    def nextInt(self):
        return int(next(self.br))
    
    def nextLong(self):
        return int(next(self.br))
    
    def nextDouble(self):
        return float(next(self.br))
    
    def nextLine(self):
        return input()

def main():
    n = inp.nextInt()
    k = inp.nextInt()
    a = [0] * n
    input(a, n)
    a.sort(reverse=True)
    pq = []
    for _ in range(k+1):
        heapq.heappush(pq, 0)
    gg = 0
    for i in range(n):
        cur = heapq.heappop(pq)
        gg += cur
        cur += a[i]
        heapq.heappush(pq, cur)
    print(gg)

def sort(a):
    a.sort()

def id1(a):
    import random
    random.shuffle(a)
    a.sort()

def input(a, n):
    for i in range(n):
        a[i] = inp.nextLong()

def fact_init(n):
    fact = [0] * (n+1)
    invFact = [0] * (n+1)
    fact[0] = 1
    for i in range(1, n+1):
        fact[i] = mul(i, fact[i-1])
    invFact[n] = power(fact[n], mod-2)
    for i in range(n-1, -1, -1):
        invFact[i] = mul(invFact[i+1], i+1)
    return fact, invFact

def nCr(n, r, fact, invFact):
    if n < r or r < 0:
        return 0
    return mul(fact[n], mul(invFact[r], invFact[n-r]))

def add(a, b):
    return (a + b) % mod

def mul(a, b):
    return (a * b) % mod

def power(x, y):
    gg = 1
    while y > 0:
        if y % 2 == 1:
            gg = mul(gg, x)
        x = mul(x, x)
        y //= 2
    return gg

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def print_arr(a):
    for i in range(len(a)):
        print(a[i], end=" ")

inp = FastReader()
main()
