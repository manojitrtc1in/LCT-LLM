import sys
from collections import defaultdict

def count_bits(x):
    return bin(x).count('1')

def work(N, L, s):
    can = [~0] * (1 << L)

    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            same = 0
            for k in range(L):
                if s[i][k] == s[j][k]:
                    same |= 1 << k
            can[same] &= ~(1 << i)

    for mask in range((1 << L) - 1, -1, -1):
        for p in range(L):
            if mask & (1 << p):
                can[mask ^ (1 << p)] &= can[mask]

    ret = 0
    cnt = [0] * 25
    for mask in range((1 << L) - 1, -1, -1):
        l = count_bits(mask)
        for p in range(L):
            if mask & (1 << p):
                r = can[mask ^ (1 << p)] ^ can[mask]
                cnt[l] += count_bits(r)

    for i in range(1, L + 1):
        t = cnt[i] * i
        c = 1
        for j in range(1, i):
            c *= (L - j + 1)
            c /= j
        ret += t / c / (L - i + 1)

    return ret / N

def main():
    for line in sys.stdin:
        N = int(line.strip())
        s = [input().strip() for _ in range(N)]
        L = len(s[0])
        ans = work(N, L, s)
        print(f"{ans:.12f}")

if __name__ == "__main__":
    main()
