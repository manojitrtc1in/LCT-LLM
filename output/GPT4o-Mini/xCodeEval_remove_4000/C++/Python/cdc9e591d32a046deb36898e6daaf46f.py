from collections import deque, defaultdict
from itertools import accumulate
import sys
import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def b303():
    n, m, x, y, a, b = map(int, input().split())
    g = gcd(a, b)
    a //= g
    b //= g

    k = min(m // b, n // a)
    width = k * a
    height = k * b

    x1 = max(x - (width + 1) // 2, 0)
    x2 = min(x1 + width, n)
    x1 = x2 - width

    y1 = max(y - (height + 1) // 2, 0)
    y2 = min(y1 + height, m)
    y1 = y2 - height

    soln = [x1, y1, x2, y2]
    print(*soln)

def xsolve(w, j, t, jump_size, wall, cache):
    n = len(wall[0])
    if j >= n:
        return True
    elif j < t or wall[w][j] != '-':
        return False
    else:
        tpl = (w, j, t)

        if tpl in cache:
            return False

        cache.add(tpl)

        if (xsolve(1 - w, j + jump_size, t + 1, jump_size, wall, cache) or
            xsolve(w, j + 1, t + 1, jump_size, wall, cache) or
            (j > 0 and xsolve(w, j - 1, t + 1, jump_size, wall, cache))):
            return True

        return False

def b198():
    n, k = map(int, input().split())
    wall = [input().strip() for _ in range(2)]

    cache = set()
    INF = float('inf')

    cache.add((0, 0, INF))
    cache.add((1, n, INF))

    flag = (xsolve(1, k, 1, k, wall, cache) or
            xsolve(0, 1, 1, k, wall, cache))

    return "YES" if flag else "NO"

def a442():
    xs = [input().strip() for _ in range(int(input()))]

    char_map = defaultdict(set)
    digit_map = defaultdict(set)
    for a in xs:
        char_map[a[0]].add(a[1])
        digit_map[a[1]].add(a[0])

    id17 = sum(1 for pr in char_map.items() if all(len(digit_map[ch]) == 1 for ch in pr[1]))
    id19 = sum(1 for pr in digit_map.items() if all(len(char_map[ch]) == 1 for ch in pr[1]))

    return min(digit_map.__len__() - 1 + (id17 < char_map.__len__() and char_map.__len__() - id17 - 1 or 0),
               char_map.__len__() - 1 + (id19 < digit_map.__len__() and digit_map.__len__() - id19 - 1 or 0))

def a163():
    subj = input().strip()
    targ = input().strip()

    pos = defaultdict(list)
    for j, char in enumerate(targ):
        pos[char].append(j)

    val = 0
    soln = [0] * (len(targ) + 1)
    id12 = [0] * (len(targ) + 1)
    m = 1000000007

    for a in subj:
        soln, id12 = id12, soln
        soln = [0] * (len(targ) + 1)

        for j in pos[a]:
            soln[j + 1] = (1 + id12[j]) % m

        soln = list(accumulate(soln, lambda x, y: (x + y) % m))
        val = (val + soln[-1]) % m

    return val

if __name__ == "__main__":
    print(a163())
