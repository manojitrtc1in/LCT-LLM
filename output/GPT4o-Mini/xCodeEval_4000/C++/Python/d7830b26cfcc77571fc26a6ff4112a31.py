import sys
import math
from collections import defaultdict

PI = 3.1415926535897932384626433832795
mdlo = 1000000007
N = 0
maxBits = 40
counts1 = [defaultdict(int) for _ in range(30)]
counts2 = [defaultdict(int) for _ in range(30)]
pwr2 = [0] * 100
parent = [0] * 1010

def getParent(node):
    if parent[node] != node:
        parent[node] = getParent(parent[node])
    return parent[node]

def unionNode(node1, node2):
    if getParent(node1) != getParent(node2):
        parent[parent[node1]] = parent[node2]

def buildpwr2(lim):
    pwr2[0] = 1
    for i in range(lim):
        pwr2[i + 1] = pwr2[i] << 1

def onNthbit(pos, val):
    return val | pwr2[pos]

def isNthbitOn(pos, val):
    return (val & pwr2[pos]) > 0

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def buildSegmentTree(b, e, node):
    if b == e:
        segTree[node] = b
        return
    mid = (b + e) // 2
    buildSegmentTree(b, mid, node * 2)
    buildSegmentTree(mid + 1, e, 1 + (node * 2))
    if segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + (node * 2)]]:
        segTree[node] = segTree[node * 2]
    else:
        segTree[node] = segTree[1 + (2 * node)]

def buildMinSegmentTree(b, e, node):
    if b == e:
        segTree[node] = b
        return
    mid = (b + e) // 2
    buildMinSegmentTree(b, mid, node * 2)
    buildMinSegmentTree(mid + 1, e, 1 + (node * 2))
    if segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + (node * 2)]]:
        segTree[node] = segTree[1 + (node * 2)]
    else:
        segTree[node] = segTree[2 * node]

def updateMinSegmentTree(b, e, node, pos, val):
    if b > pos or e < pos:
        return
    if b == e:
        segTreeData[pos] = val
        return
    mid = (b + e) // 2
    updateMinSegmentTree(b, mid, node * 2, pos, val)
    updateMinSegmentTree(mid + 1, e, 1 + node * 2, pos, val)
    if segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + node * 2]]:
        segTree[node] = segTree[1 + 2 * node]
    else:
        segTree[node] = segTree[2 * node]

def getMax(qStart, qEnd, sStart, sEnd, node):
    if qEnd < sStart or qStart > sEnd:
        return -1
    if sStart >= qStart and sEnd <= qEnd:
        return segTree[node]
    sMid = (sStart + sEnd) // 2
    r1 = getMax(qStart, qEnd, sStart, sMid, 2 * node)
    r2 = getMax(qStart, qEnd, sMid + 1, sEnd, 1 + (2 * node))
    if r1 < 0:
        return r2
    if r2 < 0 or segTreeData[r1] > segTreeData[r2]:
        return r1
    return r2

def getMinFromSegTree(qStart, qEnd, sStart, sEnd, node):
    if qEnd < sStart or qStart > sEnd:
        return -1
    if sStart >= qStart and sEnd <= qEnd:
        return segTree[node]
    sMid = (sStart + sEnd) // 2
    r1 = getMinFromSegTree(qStart, qEnd, sStart, sMid, 2 * node)
    r2 = getMinFromSegTree(qStart, qEnd, sMid + 1, sEnd, 1 + (2 * node))
    if r2 < 0:
        return r1
    if r1 < 0 or segTreeData[r1] > segTreeData[r2]:
        return r2
    return r1

def buildSumSegmentTree(b, e, node):
    if b == e:
        sumSegTree[node] = sumSegTreeData[b]
        return
    mid = (b + e) // 2
    buildSumSegmentTree(b, mid, node * 2)
    buildSumSegmentTree(mid + 1, e, 1 + node * 2)
    sumSegTree[node] = sumSegTree[node * 2] + sumSegTree[1 + (node * 2)]

def updateSumSegmentTree(b, e, node, pos, val):
    if pos < b or pos > e:
        return
    if b == e:
        sumSegTree[node] = val
        sumSegTreeData[pos] = val
        return
    mid = (b + e) // 2
    updateSumSegmentTree(b, mid, 2 * node, pos, val)
    updateSumSegmentTree(mid + 1, e, 1 + 2 * node, pos, val)
    sumSegTree[node] = sumSegTree[node * 2] + sumSegTree[1 + (node * 2)]

def getSumFromSegTree(b, e, node, qStart, qEnd):
    if qStart > e or qEnd < b:
        return 0
    if b >= qStart and e <= qEnd:
        return sumSegTree[node]
    mid = (b + e) // 2
    return getSumFromSegTree(b, mid, node * 2, qStart, qEnd) + getSumFromSegTree(mid + 1, e, 1 + 2 * node, qStart, qEnd)

def getLcm(a, b):
    return a // gcd(a, b) * b

def getlen(num):
    length = 1
    while num > 9:
        num //= 10
        length += 1
    return length

def test(a):
    if a == 1:
        print(1)
    elif a == 2:
        print(2)
    elif a == 3:
        print(3)
    elif a == 4:
        print(4)
    elif a == 5:
        print(5)
    else:
        print(0)

def buildRandomTree(tree, node):
    ancestor = list(range(100))
    for i in range(1, node):
        node1 = random.randint(0, 99)
        node2 = random.randint(0, 99)
        par1 = node1
        par2 = node2
        while ancestor[par1] != par1:
            par1 = ancestor[par1]

def main():
    global segTree, segTreeData, sumSegTree, sumSegTreeData
    segTree = [0] * 600005
    segTreeData = [0] * 100005
    sumSegTree = [0] * 600005
    sumSegTreeData = [0] * 100005

    test_cases = 1
    pow2[0] = 1
    for i in range(1, 18):
        pow2[i] = pow2[i - 1] * 2

    print(f"{0:.10f}")

    for T in range(test_cases):
        n, k = map(int, input().split())
        bamboo = [int(input()) for _ in range(n)]
        bamboo.sort()
        bambooSum = [0] * 111
        bambooSum[0] = bamboo[0]
        maxval = 0
        for i in range(1, n):
            bambooSum[i] = bamboo[i] + bambooSum[i - 1]
            m = i * bamboo[i] - bambooSum[i - 1]
            if m > k and maxval == 0:
                maxval = bamboo[i]

        if maxval == 0:
            remaining = k + bambooSum[n - 1] - (n * bamboo[n - 1])
            print((remaining // n) + bamboo[n - 1])
            return

        candidatePoints = set()

        for i in range(n):
            bambooSum[i] += k
            lim = 1 + int(math.sqrt(bamboo[i] + 1))
            for j in range(1, lim):
                r1 = bamboo[i] // j
                r2 = j
                if r1 < maxval:
                    if r1 * j == bamboo[i]:
                        candidatePoints.add(r1)
                    else:
                        candidatePoints.add(r1 + 1)

        lim = int(math.sqrt(bamboo[n - 1]))
        if lim > maxval:
            lim = maxval
        for i in range(1, lim):
            candidatePoints.add(i)

        for cp in sorted(candidatePoints, reverse=True):
            total = 0
            flag = 1
            for i in range(n):
                d1 = (bamboo[i] + cp - 1) // cp
                total += (d1 * cp)
                if total > bambooSum[i]:
                    flag = 0
                    break
            if flag:
                dv = sum((bamboo[i] + cp - 1) // cp for i in range(n))
                print(cp + (bambooSum[n - 1] - total) // dv)
                return
        print(1)

if __name__ == "__main__":
    main()
