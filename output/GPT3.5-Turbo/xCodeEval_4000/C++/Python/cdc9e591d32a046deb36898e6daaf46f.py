import sys
from typing import List, Tuple, Dict, Set

def b303() -> None:
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

def b198() -> str:
    n, k = map(int, input().split())
    wall = [input() for _ in range(2)]

    tag = [[False] * n for _ in range(2)]
    for j in range(n):
        tag[0][j] = wall[0][j] == 'X'
        tag[1][j] = wall[1][j] == 'X'

    q = [(0, 0, 0)]
    n = len(wall[0])

    while q:
        w, j, t = q.pop(0)

        if n < j + 1 + k:
            return "YES"

        if not tag[w][j + 1]:
            tag[w][j + 1] = True
            q.append((w, j + 1, t + 1))

        if j > 0 and t + 1 < j and not tag[w][j - 1]:
            tag[w][j - 1] = True
            q.append((w, j - 1, t + 1))

        if not tag[1 - w][j + k]:
            tag[1 - w][j + k] = True
            q.append((1 - w, j + k, t + 1))

    return "NO"

def a442() -> int:
    xs = [input() for _ in range(4)]

    char_map = {}
    digit_map = {}
    for a in xs:
        char_map.setdefault(a[0], set()).add(a[1])
        digit_map.setdefault(a[1], set()).add(a[0])

    digit_own = sum(all(digit_map[ch] == 1 for ch in pr[1]) for pr in char_map.items())
    char_own = sum(all(char_map[ch] == 1 for ch in pr[1]) for pr in digit_map.items())

    return min(len(digit_map) - 1 + (digit_own < len(char_map) - 1),
               len(char_map) - 1 + (char_own < len(digit_map) - 1))

def a163() -> int:
    subj, targ = input().split()

    pos = {}
    for j, ch in enumerate(targ):
        pos.setdefault(ch, []).append(j)

    val = 0
    m = 1000000007

    soln = [0] * (len(targ) + 1)
    xsoln = [0] * (len(targ) + 1)

    for a in subj:
        soln, xsoln = xsoln, soln
        soln = [0] * (len(targ) + 1)

        for j in pos.get(a, []):
            soln[j + 1] = (1 + xsoln[j]) % m

        for j in range(1, len(soln)):
            soln[j] = (soln[j] + soln[j - 1]) % m

        val = (val + soln[-1]) % m

    return val

def main() -> None:
    print(a163())

if __name__ == "__main__":
    main()
