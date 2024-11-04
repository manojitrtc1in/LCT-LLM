import sys
from collections import deque
from itertools import accumulate
from math import comb

def read():
    return int(sys.stdin.readline().strip())

def readvi(n):
    return [read() for _ in range(n)]

def exp_poly_sum_limit(a, f):
    assert a != 1
    k = len(f) - 1
    if a == 0:
        return f[0]
    else:
        g = [0] * (k + 1)
        r = 1
        for i in range(k + 1):
            g[i] = f[i] * r
            r *= a
        c = 0
        w = 0
        r = 1
        for i in range(k + 1):
            w += comb(k + 1, i) * r
            r *= -a
            c += g[k - i] * w
        c /= (1 - a) ** (k + 1)
        return c

def exp_gen_coeff_sum(a, f):
    ans = 0
    w = 1 / (1 - a)
    cur = 1
    for k in range(len(f)):
        cur *= w
        ans += comb(k, cur * f[k])
    return ans

def getsz(x):
    return len(x) + len(x[0])

def convolute2d(x, y):
    n1, m1 = len(x), len(x[0])
    n2, m2 = len(y), len(y[0])
    n, m = n1 + n2 - 1, m1 + m2 - 1
    p = [0] * (n * m)
    q = [0] * (n * m)
    for i in range(n1):
        for j in range(m1):
            p[i * m + j] = x[i][j]
    for i in range(n2):
        for j in range(m2):
            q[i * m + j] = y[i][j]
    # In-place FFT-like multiplication would go here
    # Placeholder for the actual multiplication
    return [[0] * m for _ in range(n)]

def slv():
    n, k = map(int, sys.stdin.readline().strip().split())
    ls = readvi(n)
    tot = sum(ls)
    buf = [[] for _ in range(n)]
    
    for idx in range(n):
        s = (ls[idx] - 1) // k + 1
        f = [[0] * 2 for _ in range(s)]
        for num in range(s):
            w = (ls[idx] - k * num) / tot
            if num:
                f[num][0] = w ** (num - 1) / (num - 1)
            f[num][1] = w ** num / num
        buf[idx] = f

    pq = deque(sorted((getsz(buf[i]), i) for i in range(n)))
    
    for _ in range(n - 1):
        i = pq.popleft()[1]
        j = pq.popleft()[1]
        buf[i] = convolute2d(buf[i], buf[j])
        buf[j] = []
        pq.append((getsz(buf[i]), i))
    
    ans = buf[pq[0][1]]
    sum_val = 0
    for num in range(1, len(ans)):
        f = [0] * (num + 1)
        assert len(ans[num]) == n + 1
        for i in range(n + 1):
            if i + num - n >= 0:
                f[i + num - n] = ans[num][i]
            else:
                assert ans[num][i] == 0
        w = (tot - num * k) / tot
        val = exp_gen_coeff_sum(w, f)
        if num % 2 == 0:
            val = -val
        sum_val += val
    
    print(sum_val)

if __name__ == "__main__":
    sys.stdin = open(0)
    slv()
