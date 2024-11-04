import sys
from collections import defaultdict
from itertools import accumulate

def can(n):
    global it
    if n == 1:
        return True
    x = n // 2
    y = (n + 1) // 2
    if not can(x) or not can(y):
        return False
    a = b = 0
    while it < len(s):
        if s[it] == '0':
            a += 1
        else:
            b += 1
        it += 1
        if a == x or b == y:
            break
    return a == x or b == y

def gen(l, r):
    global it
    if l == r:
        return
    m = (l + r - 1) // 2
    gen(l, m)
    gen(m + 1, r)
    a, b, c = l, m + 1, l
    while a <= m and b <= r:
        if s[it] == '0':
            mas[c] = id[a]
            a += 1
        else:
            mas[c] = id[b]
            b += 1
        c += 1
        it += 1
    while a <= m:
        mas[c] = id[a]
        a += 1
        c += 1
    while b <= r:
        mas[c] = id[b]
        b += 1
        c += 1
    for i in range(l, r + 1):
        id[i] = mas[i]
        if i > l:
            e[id[i - 1]].append(id[i])

def go(n):
    global it
    it = 0
    if not can(n) or it != len(s):
        return

    it = 0
    id[:] = range(n)
    gen(0, n - 1)
    assert it == len(s)
    p = [0] * n
    for i in range(n):
        p[id[i]] = i
    print(n)
    print(' '.join(str(i + 1) for i in p))
    sys.exit(0)

maxn = 1003
e = defaultdict(list)
id = [0] * maxn
mas = [0] * maxn
deg = [0] * maxn
seg = [[0, 0] for _ in range(maxn)]

def solve():
    global s
    for i in range(2, maxn):
        x = (i + 1) // 2
        y = i - x
        for t in range(2):
            seg[i][t] = seg[x][t] + seg[y][t]
        seg[i][0] += x
        seg[i][1] += y
    s = input().strip()
    counter = [0, 0]
    for c in s:
        counter[int(c)] += 1
    for n in range(maxn - 1, 0, -1):
        if seg[n][0] >= counter[0] and seg[n][1] >= counter[1]:
            go(n)

if __name__ == "__main__":
    input = sys.stdin.read
    it = 0
    solve()
