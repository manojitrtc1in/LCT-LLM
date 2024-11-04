import random
import sys
from typing import List, Tuple

def can(n: int, s: str) -> bool:
    if n == 1:
        return True
    x = n // 2
    y = (n + 1) // 2
    if not can(x, s) or not can(y, s):
        return False
    a = 0
    b = 0
    for i in range(len(s)):
        if s[i] == '0':
            a += 1
        else:
            b += 1
        if a == x or b == y:
            break
    if a != x and b != y:
        return False
    return True

def gen(l: int, r: int, s: str, it: int, id: List[int], mas: List[int], e: List[List[int]]) -> None:
    if l == r:
        return
    m = (l + r - 1) // 2
    gen(l, m, s, it, id, mas, e)
    gen(m + 1, r, s, it, id, mas, e)
    a = l
    b = m + 1
    c = l
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

def go(n: int, s: str) -> None:
    it = 0
    if not can(n, s) or it != len(s):
        return

    it = 0
    id = [i for i in range(n)]
    mas = [0] * n
    e = [[] for _ in range(n)]
    gen(0, n - 1, s, it, id, mas, e)
    assert it == len(s)
    p = [0] * n
    for i in range(n):
        p[id[i]] = i
    print(n)
    for i in p:
        print(i + 1, end=' ')
    print()
    sys.exit(0)

def solve() -> None:
    seg = [[0, 0] for _ in range(maxn)]
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
            go(n, s)

if __name__ == '__main__':
    solve()
