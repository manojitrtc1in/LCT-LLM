import math

mdlo = 1000000007
maxERR = 0.00000064
maxBits = 40
pi = 3.1415926535897932384626433832795
INF = 999999999999

mInv = [0] * 41
fact = [0] * 41
factInv = [0] * 41
N, M = 0, 0

edge = []
adjList = []
levels = [0] * 15
nextPoint = [0] * 15
firstDigit = [0] * 15
inTree = [False] * 123466
visited = [False] * 123466

class treeInfo:
    def __init__(self):
        self.depth = 0
        self.longestPath = 0
        self.startPointOflongestpath = 0
        self.deepestNode = 0
        self.included = False

tree = [[] for _ in range(123466)]
startPoints = []

graph = [[] for _ in range(15)]

def getmoduloInv(n):
    if n == 1:
        return 1
    if mInv[n] > 0:
        return mInv[n]
    m = (-1 * mdlo) // n
    m += mdlo
    m *= getmoduloInv(mdlo % n)
    mInv[n] = (m % mdlo)
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

primes = []
def get_primes(max):
    sieve = [True] * ((max // 8) + 1)
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
    for i in range(2, int(math.sqrt(N)) + 1):
        if N % i == 0:
            return False
    return True

def gcd(a, b):
    c = 0
    if a > b:
        c = a
        a = b
        b = c
    if a == 0:
        return b
    c = b % a
    while c > 0:
        b = a
        a = c
        c = b % a
    return a

def getLcm(a, b):
    c = a // gcd(a, b)
    return b * c

def dfs(startPoint):
    tInfo = treeInfo()
    maxDepth = 0
    maxDepth2 = 0
    deepestNode = 1234567
    deepestNode2 = 1234567
    longestPath = 0
    longestPathStart = 1234567
    status = inTree[startPoint]
    visited[startPoint] = True
    for i in range(len(tree[startPoint])):
        if not visited[tree[startPoint][i]]:
            childInfo = dfs(tree[startPoint][i])
            if childInfo.included:
                status = True
                if maxDepth < childInfo.depth or (maxDepth == childInfo.depth and deepestNode > childInfo.deepestNode):
                    maxDepth2 = maxDepth
                    deepestNode2 = deepestNode
                    deepestNode = childInfo.deepestNode
                    maxDepth = childInfo.depth
                elif maxDepth2 < childInfo.depth or (maxDepth2 == childInfo.depth and deepestNode2 > childInfo.deepestNode):
                    maxDepth2 = childInfo.depth
                    deepestNode2 = childInfo.deepestNode
                if childInfo.longestPath > longestPath or (childInfo.longestPath == longestPath and longestPathStart < childInfo.startPointOflongestpath):
                    longestPath = childInfo.longestPath
                    longestPathStart = childInfo.startPointOflongestpath
    tInfo.included = status
    if maxDepth == 0:
        tInfo.deepestNode = startPoint
        tInfo.depth = 1
        tInfo.longestPath = 1
        tInfo.startPointOflongestpath = startPoint
        return tInfo
    if maxDepth + maxDepth2 + 1 > longestPath or (maxDepth + maxDepth2 + 1 == longestPath and longestPathStart > min(deepestNode, deepestNode2)):
        longestPathStart = min(deepestNode, deepestNode2)
        longestPath = maxDepth + maxDepth2 + 1
    if maxDepth2 == maxDepth and deepestNode2 < deepestNode:
        deepestNode = deepestNode2
    tInfo.deepestNode = deepestNode
    tInfo.depth = maxDepth + 1
    tInfo.longestPath = longestPath
    tInfo.startPointOflongestpath = longestPathStart
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
    rotateDist1 = math.cos((pi + C) / 2) - math.cos((pi - C) / 2)
    rotateDist2 = math.cos((3 * pi + C) / 2) - math.cos((3 * pi - C) / 2)
    return dist + r * max(rotateDist1, rotateDist2)

def printMaxMin(C):
    maxVal = -1
    maxAngle = 0
    minVal = 1
    minAngle = 0
    for th in range(0, 3601):
        angle = ((th + C) * pi) / 180.0
        val = math.cos(angle) - math.cos((th * pi) / 180.0)
        if val > maxVal:
            maxVal = val
            maxAngle = th
        if val < minVal:
            minVal = val
            minAngle = th
    print("max", maxVal, "angle", maxAngle)
    print("min", minVal, "angle", minAngle)

test_cases = 1
C, D, A, L, R, rep, round, rem, ans, num = 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
st, en, minerr = 0.0, 0.0, 0.00000001
r, v = 0.0, 0.0

test_cases, r, v = map(float, input().split())
for T in range(int(test_cases)):
    st, en = map(float, input().split())
    dist = en - st
    low = (dist - 2 * r) / v
    high = (dist + 2 * r) / v
    mid = 0.0
    while low + minerr < high and low + low * minerr < high:
        mid = (low + high) / 2
        if maxDist(mid, v, r) > dist:
            high = mid
        else:
            low = mid
    print("{:.15f}".format((low + high) / 2))
