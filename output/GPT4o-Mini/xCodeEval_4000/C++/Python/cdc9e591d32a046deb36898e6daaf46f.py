import sys
import itertools
import math
from collections import deque, defaultdict

DOUBLE_INF = float('inf')
DOUBLE_NAN = float('nan')

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
        return (xsolve(1 - w, j + jump_size, t + 1, jump_size, wall, cache) or
                xsolve(w, j + 1, t + 1, jump_size, wall, cache) or
                (j > 0 and xsolve(w, j - 1, t + 1, jump_size, wall, cache)))

def b198():
    n, k = map(int, input().split())
    wall = [input().strip() for _ in range(2)]

    cache = set()
    INF = float('inf')

    cache.add((0, 0, INF))
    cache.add((1, n, INF))

    flag = xsolve(1, k, 1, k, wall, cache) or xsolve(0, 1, 1, k, wall, cache)

    return "YES" if flag else "NO"

def a442():
    xs = input().strip().split()
    char_map = defaultdict(set)
    digit_map = defaultdict(set)

    for a in xs:
        char_map[a[0]].add(a[1])
        digit_map[a[1]].add(a[0])

    digit_own = sum(1 for pr in char_map.items() if all(digit_map[ch] for ch in pr[1]))
    char_own = sum(1 for pr in digit_map.items() if all(char_map[ch] for ch in pr[1]))

    return min(digit_map.size() - 1 + (digit_own < len(char_map) and len(char_map) - digit_own - 1),
               len(char_map) - 1 + (char_own < len(digit_map) and len(digit_map) - char_own - 1))

def a163():
    subj = input().strip()
    targ = input().strip()

    pos = defaultdict(list)
    for j, ch in enumerate(targ):
        pos[ch].append(j)

    val = 0
    soln = [0] * (len(targ) + 1)
    xsoln = [0] * (len(targ) + 1)
    m = 1000000007

    for a in subj:
        soln, xsoln = xsoln, soln
        soln = [0] * len(soln)

        for j in pos[a]:
            soln[j + 1] = (1 + xsoln[j]) % m

        for i in range(1, len(soln)):
            soln[i] = (soln[i] + soln[i - 1]) % m

        val = (val + soln[-1]) % m

    return val

def main():
    print(a163())

if __name__ == "__main__":
    main()
