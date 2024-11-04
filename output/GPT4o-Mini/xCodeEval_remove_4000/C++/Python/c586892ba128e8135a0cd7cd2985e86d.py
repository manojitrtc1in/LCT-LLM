from math import cos, pi, gcd
from collections import defaultdict
import sys

sys.setrecursionlimit(1500)

mInv = [0] * 41
fact = [0] * 41
factInv = [0] * 41
N, M = 0, 0
levels = [0] * 15
nextPoint = [0] * 15
firstDigit = [0] * 15
inTree = [False] * 123466
visited = [False] * 123466
tree = defaultdict(list)
startPoints = []

def id4(n):
    if n == 1:
        return 1
    if mInv[n] > 0:
        return mInv[n]
    m = (-1 * mdlo) // n
    m += mdlo
    m *= id4(mdlo % n)
    mInv[n] = m % mdlo
    return mInv[n]

par = [0] * 45

def getAncestor(val):
    if par[val] != val:
        par[val] = getAncestor(par[val])
    return par[val]

def unify(a, b):
    para = getAncestor(a)
    parb = getAncestor(b)
    if para == parb:
        return False
    if para < parb:
        par[parb] = para
    else:
        par[para] = parb
    return True

def id1(max):
    sieve = [255] * ((max // 8) + 1)
    primes = []
    for x in range(2, max + 1):
        if sieve[x // 8] & (0x01 << (x % 8)):
            primes.append(x)
            for j in range(2 * x, max + 1, x):
                sieve[j // 8] &= ~(0x01 << (j % 8))
    return primes

dp = [[0] * 22 for _ in range(22)]

def getdp(N, K):
    if dp[N][K] == 0:
        if K == 1:
            dp[N][K] = N
            return dp[N][K]
        v1 = getdp(N, K - 1)
        v2 = getdp(N - 1, K - 1)
        dp[N][K] = (v1 * v2) // (v1 - v2)
    return dp[N][K]

def isPrime(N):
    if N == 1:
        return False
    if N < 4:
        return True
    for i in range(2, int(N**0.5) + 1):
        if N % i == 0:
            return False
    return True

def gcd(a, b):
    if a > b:
        a, b = b, a
    if a == 0:
        return b
    c = b % a
    while c > 0:
        b = a
        a = c
        c = b % a
    return a

def id5(a, b):
    c = a // gcd(a, b)
    return b * c

class TreeInfo:
    def __init__(self):
        self.depth = 0
        self.id6 = 0
        self.startPointOflongestpath = 0
        self.id3 = 1234567
        self.included = False

def dfs(startPoint):
    tInfo = TreeInfo()
    maxDepth = 0
    id7 = 0
    id3 = 1234567
    id9 = 1234567
    id6 = 0
    id10 = 1234567
    status = inTree[startPoint]
    visited[startPoint] = True
    for neighbor in tree[startPoint]:
        if not visited[neighbor]:
            childInfo = dfs(neighbor)
            if childInfo.included:
                status = True
                if maxDepth < childInfo.depth or (maxDepth == childInfo.depth and id3 > childInfo.id3):
                    id7 = maxDepth
                    id9 = id3
                    id3 = childInfo.id3
                    maxDepth = childInfo.depth
                elif id7 < childInfo.depth or (id7 == childInfo.depth and id9 > childInfo.id3):
                    id7 = childInfo.depth
                    id9 = childInfo.id3
                if childInfo.id6 > id6 or (childInfo.id6 == id6 and id10 < childInfo.startPointOflongestpath):
                    id6 = childInfo.id6
                    id10 = childInfo.startPointOflongestpath
    tInfo.included = status
    if maxDepth == 0:
        tInfo.id3 = startPoint
        tInfo.depth = 1
        tInfo.id6 = 1
        tInfo.startPointOflongestpath = startPoint
        return tInfo
    if maxDepth + id7 + 1 > id6 or (maxDepth + id7 + 1 == id6 and id10 > min(id3, id9)):
        id10 = min(id3, id9)
        id6 = maxDepth + id7 + 1
    if id7 == maxDepth and id9 < id3:
        id3 = id9
    tInfo.id3 = id3
    tInfo.depth = maxDepth + 1
    tInfo.id6 = id6
    tInfo.startPointOflongestpath = id10
    inTree[startPoint] = status
    return tInfo

def getVal(num):
    ans = 1
    for i in range(1, num):
        ans += (num // gcd(num, i))
    return ans

def buildDp():
    for i in range(1, 22):
        for j in range(1, i + 1):
            dp[i][j] = getdp(i, j)
            print(dp[i][j], end=" ")
        print()

def maxDist(t, v, r):
    dist = t * v
    C = t * v / r
    id0 = cos((pi + C) / 2) - cos((pi - C) / 2)
    id8 = cos((3 * pi + C) / 2) - cos((3 * pi - C) / 2)
    return dist + r * max(id0, id8)

def id2(C):
    maxVal = -1
    maxAngle = 0
    minVal = 1
    minAngle = 0
    for th in range(0, 3601, 1):
        angle = ((th + C) * pi) / 180.0
        val = cos(angle) - cos((th * pi) / 180.0)
        if val > maxVal:
            maxVal = val
            maxAngle = th
        if val < minVal:
            minVal = val
            minAngle = th
    print(f"max {maxVal} angle {maxAngle}")
    print(f"min {minVal} angle {minAngle}")

def main():
    test_cases = 1
    C, D, A, L, R, rep, round = 0, 0, 0, 0, 0, 0, 0
    rem, ans, num = 0, 0, 0
    minerr = 0.00000001
    r, v = 0, 0
    test_cases, r, v = map(float, input().split())
    print(f"{r:.15f}")

    for T in range(int(test_cases)):
        st, en = map(float, input().split())
        dist = en - st
        low = (dist - 2 * r) / v
        high = (dist + 2 * r) / v
        while low + minerr < high and low + low * minerr < high:
            mid = (low + high) / 2
            if maxDist(mid, v, r) > dist:
                high = mid
            else:
                low = mid
        print(f"{(low + high) / 2:.6f}")

if __name__ == "__main__":
    main()
