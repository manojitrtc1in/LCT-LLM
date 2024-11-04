import sys
from collections import defaultdict

N1 = int(1e5)
B = int(1e5)
N = int(3e8)

lp = [0] * (N1 + 1)
prime = []

def seive():
    for i in range(2, N1 + 1):
        if lp[i] == 0:
            lp[i] = i
            prime.append(i)
        for j in prime:
            if j > lp[i] or i * j > N1:
                break
            lp[i * j] = j

csum = [0] * (N1 + 1)
for i in range(1, N1 + 1):
    csum[i] = csum[i - 1] + i

def calsum(l, r):
    if l > r:
        return 0
    if l == 0:
        return csum[r]
    return csum[r] - csum[l - 1]

def inrange(l, r):
    if l > r:
        return 0

    isp = [1] * (r - l + 1)
    for i in prime:
        if i * i > r:
            break
        st = (l // i) * i
        if st < l:
            st += i
        if st == i:
            st += i
        for cur in range(st, r + 1, i):
            isp[cur - l] = 0

    ans = 0
    for i in range(r - l + 1):
        if isp[i] and (l + i) % 4 == 1:
            ans += 1
    if 2 >= l and 2 <= r:
        ans += 1
    return ans

def main():
    global l, r
    seive()
    l, r = map(int, sys.stdin.readline().split())

    l = max(l, 2)
    if l > r:
        print(0)
        return

    b1 = l // B
