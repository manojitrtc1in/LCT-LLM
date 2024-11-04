from typing import List
import sys
import math

def main():
    n, k = map(int, sys.stdin.readline().split())
    c, pf = [], []
    
    for _ in range(n):
        v = int(sys.stdin.readline())
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
        cs[i + 1] = cs[i] + (i // (k + 1)) * c[i]

    sf = [0] * (len(c) + 1)
    sf2 = [0] * (len(c) + 1)
    
    for i in range(len(c) - 1, -1, -1):
        sf[i] = sf[i + 1] + c[i]
        sf2[i] = sf2[i + 1] + c[i] * i

    ans = -1e18
    for j in range(len(c) + 1):
        if j * (k + 1) < len(c):
            continue
        cd = math.ceil((len(c) - j) / k)
        tp = j - cd
        now = ini * j
        now -= sf2[len(c) - tp] + sf[tp] * (cd - (len(c) - tp))
        now -= cs[len(c) - tp]
        ans = max(ans, now)

    ans += base
    print(ans)

if __name__ == "__main__":
    main()
