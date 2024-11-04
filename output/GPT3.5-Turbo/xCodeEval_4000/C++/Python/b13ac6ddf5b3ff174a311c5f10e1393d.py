import sys

def work():
    can = [-1] * (1 << L)
    
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
        l = bin(mask).count('1')
        for p in range(L):
            if mask & (1 << p):
                r = can[mask ^ (1 << p)] ^ can[mask]
                cnt[l] += bin(r).count('1')
    
    for i in range(1, L + 1):
        t = cnt[i] * i
        c = 1
        for j in range(1, i):
            c *= L - j + 1
            c //= j
        ret += t / c / (L - i + 1)
    
    return ret / N

for line in sys.stdin:
    N = int(line.strip())
    s = []
    for _ in range(N):
        s.append(input().strip())
    L = len(s[0])
    ans = work()
    print("{:.12f}".format(ans))
