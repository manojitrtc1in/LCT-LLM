import math
import random
from typing import List, Tuple, Dict, Any

class adjList:
    def __init__(self):
        self.nodes = []

class sum:
    def __init__(self, first: int, second: int):
        self.first = first
        self.second = second

class updat:
    def __init__(self, first: sum, second: int):
        self.first = first
        self.second = second

N: int
counts1: List[Dict[int, int]] = [{} for _ in range(30)]
counts2: List[Dict[int, int]] = [{} for _ in range(30)]
pwr2: List[int] = [0] * 100
parent: List[int] = [0] * 1010

def getParent(node: int) -> int:
    if parent[node] != node:
        parent[node] = getParent(parent[node])
    return parent[node]

def unionNode(node1: int, node2: int) -> None:
    if getParent(node1) != getParent(node2):
        parent[parent[node1]] = parent[node2]

def id11(lim: int) -> None:
    pwr2[0] = 1
    for i in range(lim):
        pwr2[i + 1] = pwr2[i] << 1

def id0(pos: int, val: int) -> int:
    return val | pwr2[pos]

def id1(pos: int, val: int) -> bool:
    return (val & pwr2[pos]) > 0

def gcd(a: int, b: int) -> int:
    c = b % a
    while c > 0:
        b = a
        a = c
        c = b % a
    return a

s: str
target: int
sticker: int
segTree: List[int] = [0] * 600005
segTreeData: List[int] = [0] * 100005
sumSegTree: List[int] = [0] * 600005
sumSegTreeData: List[int] = [0] * 100005
minStart: List[int] = [0] * 2
minEnd: List[int] = [0] * 2

def id7(b: int, e: int, node: int) -> None:
    if b == e:
        segTree[node] = b
        return
    mid = (b + e) // 2
    id7(b, mid, node * 2)
    id7(mid + 1, e, 1 + (node * 2))
    if segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + (node * 2)]]:
        segTree[node] = segTree[node * 2]
    else:
        segTree[node] = segTree[1 + (2 * node)]

def id10(b: int, e: int, node: int) -> None:
    if b == e:
        segTree[node] = b
        return
    mid = (b + e) // 2
    id10(b, mid, node * 2)
    id10(mid + 1, e, 1 + (node * 2))
    if segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + (node * 2)]]:
        segTree[node] = segTree[1 + (node * 2)]
    else:
        segTree[node] = segTree[(2 * node)]

def id3(b: int, e: int, node: int, pos: int, val: int) -> None:
    if b > pos or e < pos:
        return
    if b == e:
        segTreeData[pos] = val
        return
    mid = (b + e) // 2
    id3(b, mid, node * 2, pos, val)
    id3(mid + 1, e, 1 + node * 2, pos, val)
    if segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + node * 2]]:
        segTree[node] = segTree[1 + 2 * node]
    else:
        segTree[node] = segTree[2 * node]

def getMax(qStart: int, qEnd: int, sStart: int, sEnd: int, node: int) -> int:
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

def id5(qStart: int, qEnd: int, sStart: int, sEnd: int, node: int) -> int:
    if qEnd < sStart or qStart > sEnd:
        return -1
    if sStart >= qStart and sEnd <= qEnd:
        return segTree[node]
    sMid = (sStart + sEnd) // 2
    r1 = id5(qStart, qEnd, sStart, sMid, 2 * node)
    r2 = id5(qStart, qEnd, sMid + 1, sEnd, 1 + (2 * node))
    if r2 < 0:
        return r1
    if r1 < 0 or segTreeData[r1] > segTreeData[r2]:
        return r2
    return r1

def id8(b: int, e: int, node: int) -> None:
    if b == e:
        sumSegTree[node] = sumSegTreeData[b]
        return
    mid = (b + e) // 2
    id8(b, mid, node * 2)
    id8(mid + 1, e, 1 + node * 2)
    sumSegTree[node] = sumSegTree[node * 2] + sumSegTree[1 + (node * 2)]

def id9(b: int, e: int, node: int, pos: int, val: int) -> None:
    if pos < b or pos > e:
        return
    if b == e:
        sumSegTree[node] = val
        sumSegTreeData[pos] = val
        return
    mid = (b + e) // 2
    id9(b, mid, 2 * node, pos, val)
    id9(mid + 1, e, 1 + 2 * node, pos, val)
    sumSegTree[node] = sumSegTree[node * 2] + sumSegTree[1 + (node * 2)]

def id6(b: int, e: int, node: int, qStart: int, qEnd: int) -> int:
    if qStart > e or qEnd < b:
        return 0
    if b >= qStart and e <= qEnd:
        return sumSegTree[node]
    mid = (b + e) // 2
    return id6(b, mid, node * 2, qStart, qEnd) + id6(mid + 1, e, 1 + 2 * node, qStart, qEnd)

def id2(a: int, b: int) -> int:
    c = a // gcd(a, b)
    return b * c

pow10: List[int] = [0] * 18
pow2: List[int] = [0] * 18

def getlen(num: int) -> int:
    len = 1
    while num > 9:
        num //= 10
        len += 1
    return len

def test(a: int) -> None:
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
    print()

class base:
    def f(self, lable: str = "bd") -> None:
        print(lable + ":base")

class derived(base):
    def f(self, lable: str = "dd") -> None:
        print(lable + ":derived")

def id4(tree: List[adjList], node: int) -> None:
    ancestor: List[int] = [i for i in range(100)]
    for i in range(1, node):
        node1 = random.randint(0, 100)
        node2 = random.randint(0, 100)
        par1 = node1
        par2 = node2
        while ancestor[par1] != par1:
            par1 = ancestor[par1]

def main() -> int:
    test_cases = 1
    pow2[0] = 1
    for i in range(1, 18):
        pow2[i] = pow2[i - 1] * 2

    print("{:.10f}".format(0))

    for T in range(test_cases):
        s = ""
        m1 = ""
        m2 = ""
        k = 0
        n = 0
        m = 0
        p = 0
        test_cases = 1
        pow2[0] = 1
        for i in range(1, 18):
            pow2[i] = pow2[i - 1] * 2

        print("{:.10f}".format(0))

        for T in range(test_cases):
            s = ""
            m1 = ""
            m2 = ""
            k = 0
            n = 0
            m = 0
            p = 0

            n, k = map(int, input().split())
            bamboo = list(map(int, input().split()))
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
                return 0

            candidatePoints = set()

            for i in range(n):
                bambooSum[i] += k
                lim = 1 + math.isqrt(bamboo[i] + 1)
                for j in range(1, lim):
                    r1 = bamboo[i] // j
                    r2 = j
                    if r1 < maxval:
                        if r1 * j == bamboo[i]:
                            candidatePoints.add(r1)
                        else:
                            candidatePoints.add(r1 + 1)

            lim = math.isqrt(bamboo[n - 1])
            if lim > maxval:
                lim = maxval
            for i in range(1, lim):
                candidatePoints.add(i)

            for cp in reversed(sorted(candidatePoints)):
                total = 0
                d1 = 0
                flag = 1
                for i in range(n):
                    d1 = (bamboo[i] + cp - 1) // cp
                    total += (d1 * cp)
                    if total > bambooSum[i]:
                        flag = 0
                        break

                if flag:
                    dv = 0
                    for i in range(n):
                        dv += (bamboo[i] + cp - 1) // cp
                    print(cp + (bambooSum[n - 1] - total) // dv)
                    return 0

            print(1)

    return 0

if __name__ == "__main__":
    main()
