from collections import deque
from typing import List, Tuple
import sys
import math

eol = '\n'

def read_int() -> int:
    return int(sys.stdin.readline().strip())

def read_ints() -> List[int]:
    return list(map(int, sys.stdin.readline().strip().split()))

def ceil_div(x: int, y: int) -> int:
    assert y != 0
    if y < 0:
        x, y = -x, -y
    return x // y if x < 0 else (x + y - 1) // y

def main():
    n, k = read_ints()
    c = []
    pf = []
    
    for _ in range(n):
        v = read_int()
        if v < 0:
            c.append(-v)
        else:
            pf.append(v)

    pf.sort(reverse=True)
    ini = 0
    base = 0
    for e in pf:
        base += ini
        ini += e

    c.sort(reverse=True)

    if k == 0:
        for e in reversed(c):
            base += ini
            ini -= e
        print(base)
        return

    cs = [0] * (len(c) + 1)
    for i in range(len(c)):
        cs[i + 1] = cs[i] + (i // (k + 1) * c[i])

    sf = [0] * (len(c) + 1)
    sf2 = sf[:]
    for i in range(len(c) - 1, -1, -1):
        sf[i] = sf[i + 1] + c[i]
        sf2[i] = sf2[i + 1] + c[i] * i

    sf.reverse()

    ans = -int(1e18)
    for j in range(len(c) + 1):
        if j * (k + 1) < len(c):
            continue
        cd = ceil_div(len(c) - j, k)
        tp = j - cd
        now = ini * j
        now -= sf2[len(c) - tp] + sf[tp] * (cd - (len(c) - tp))
        now -= cs[len(c) - tp]
        ans = max(ans, now)

    ans += base
    print(ans)

def case_number() -> int:
    return 1

def iterate_main():
    for counter in range(1, case_number() + 1):
        try:
            main()
        except Exception:
            pass

if __name__ == "__main__":
    sys.stdin = open(0)  # Redirect input
    iterate_main()
