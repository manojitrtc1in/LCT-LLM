from collections import deque
import sys
import math
from functools import reduce
from itertools import accumulate
from random import randint

input = sys.stdin.read
def read():
    return int(input())

def readvi(n, off=0):
    return [read() + off for _ in range(n)]

def readpi(off=0):
    a, b = map(int, input().split())
    return (a + off, b + off)

def print_tuple(t):
    print("{" + ",".join(map(str, t)) + "}")

def print_vector(v):
    print("{" + ",".join(map(str, v)) + "}")

def yes(ex=True):
    print("YES")
    if ex: exit(0)

def no(ex=True):
    print("NO")
    if ex: exit(0)

def possible(ex=True):
    print("POSSIBLE")
    if ex: exit(0)

def impossible(ex=True):
    print("IMPOSSIBLE")
    if ex: exit(0)

def sq(t):
    return t * t

def initfact(vmax=2**21 + 10):
    fact = [1] * vmax
    for i in range(1, vmax):
        fact[i] = fact[i - 1] * i
    finv = [0] * vmax
    finv[vmax - 1] = pow(fact[vmax - 1], -1, 998244353)
    for i in range(vmax - 2, -1, -1):
        finv[i] = finv[i + 1] * (i + 1) % 998244353
    invs = [finv[i] * fact[i - 1] % 998244353 for i in range(1, vmax)]
    return fact, finv, invs

def choose(n, k, fact, finv):
    return fact[n] * finv[n - k] * finv[k] % 998244353

def binom(a, b, fact, finv):
    return fact[a + b] * finv[a] * finv[b] % 998244353

def id6(a, f, fact):
    ans = 0
    w = pow(1 - a, -1, 998244353)
    cur = 1
    for k in range(len(f)):
        cur = cur * w % 998244353
        ans = (ans + fact[k] * cur * f[k]) % 998244353
    return ans

def slv():
    n, k = map(int, input().split())
    ls = readvi(n)
    tot = sum(ls)
    buf = [[] for _ in range(n)]
    
    for idx in range(n):
        s = (ls[idx] - 1) // k + 1
        f = [[0] * 2 for _ in range(s)]
        for num in range(s):
            w = (ls[idx] - k * num) * pow(tot, -1, 998244353) % 998244353
            if num:
                f[num][0] = w ** (num - 1) * pow(num - 1, -1, 998244353) % 998244353
            f[num][1] = w ** num * pow(num, -1, 998244353) % 998244353
        buf[idx] = f

    pq = deque(sorted((len(buf[i]), i) for i in range(n)))
    
    while len(pq) > 1:
        i = pq.popleft()[1]
        j = pq.popleft()[1]
        buf[i] = id0(buf[i], buf[j])
        buf[j] = []
        pq.append((len(buf[i]), i))

    ans = buf[pq[0][1]]
    sum_val = 0
    for num in range(1, len(ans)):
        f = [0] * (num + 1)
        for i in range(n + 1):
            if i + num - n >= 0:
                f[i + num - n] = ans[num][i]
            else:
                assert ans[num][i] == 0
        w = (tot - num * k) * pow(tot, -1, 998244353) % 998244353
        val = id6(w, f, fact)
        if num % 2 == 0:
            val = -val
        sum_val = (sum_val + val) % 998244353

    print(sum_val)

if __name__ == "__main__":
    fact, finv, invs = initfact()
    slv()
