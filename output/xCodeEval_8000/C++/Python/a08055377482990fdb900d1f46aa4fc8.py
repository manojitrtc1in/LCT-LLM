import sys
from collections import deque

MAGIC = 20000000

t, la, ma, at, to = 0, 0, 0, 0, {}
p = [0] * 1000005
pp = [([], 0)] * 1000005
s = set()
m = [{} for _ in range(300)]
x = [[0] * 289 for _ in range(289)]
xx = [""] * 289
vv = []
q = deque()

def go(aa, bb, cc):
    q.append((aa, (bb, cc)))
    s.add(tuple(aa))
    while q:
        a, (b, c) = q.popleft()
        it = m[at].setdefault(b, sys.maxsize)
        it = min(it, c)
        if c >= 10:
            continue
        c += 1
        for i in range(len(a) - 1):
            if a[i] != a[i + 1]:
                a[i] -= 1
                if tuple(a) not in s:
                    q.append((a.copy(), (b // (a[i] + 1) * a[i], c)))
                    s.add(tuple(a))
                a[i] += 1
        if a:
            if a[-1] == 2:
                a.pop()
                if tuple(a) not in s:
                    q.append((a.copy(), (b // 2, c)))
                    s.add(tuple(a))
                a.append(2)
            else:
                a[-1] -= 1
                if tuple(a) not in s:
                    q.append((a.copy(), (b // (a[-1] + 1) * a[-1], c)))
                    s.add(tuple(a))
                a[-1] += 1
        for i in range(len(a)):
            if i == 0 or a[i] != a[i - 1]:
                b //= a[i]
                a[i] += 1
                b *= a[i]
                if b <= MAGIC and tuple(a) not in s:
                    q.append((a.copy(), (b, c)))
                    s.add(tuple(a))
                b //= a[i]
                a[i] -= 1
                b *= a[i]
        a.append(2)
        if b * 2 <= MAGIC and tuple(a) not in s:
            q.append((a.copy(), (b * 2, c)))
            s.add(tuple(a))
    s.clear()

def main():
    for i in range(2, 1000005):
        if not p[i]:
            p[i] = i
            if i <= 1000005 // i:
                for j in range(i * i, 1000005, i):
                    if not p[j]:
                        p[j] = i
    for i in range(1, 1000001):
        pp[i] = ([], i)
        la = -1
        ta = i
        while ta != 1:
            if p[ta] == la:
                pp[i][0][-1] += 1
            else:
                pp[i][0].append(2)
            la = p[ta]
            ta //= p[ta]
        pp[i][0].sort(reverse=True)
    pp = sorted(pp[1:])
    for i in range(1, 1000001):
        if i == 1 or pp[i][0] != pp[i - 1][0]:
            vv.append(pp[i][0])
