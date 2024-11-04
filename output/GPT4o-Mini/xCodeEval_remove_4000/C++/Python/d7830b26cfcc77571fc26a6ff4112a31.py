from collections import defaultdict
import sys
import math
import random

def get_parent(node):
    if parent[node] != node:
        parent[node] = get_parent(parent[node])
    return parent[node]

def union_node(node1, node2):
    if get_parent(node1) != get_parent(node2):
        parent[get_parent(node1)] = get_parent(node2)

def id11(lim):
    pwr2[0] = 1
    for i in range(lim):
        pwr2[i + 1] = pwr2[i] << 1

def id0(pos, val):
    return val | pwr2[pos]

def id1(pos, val):
    return (val & pwr2[pos]) > 0

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def id7(b, e, node):
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

def id10(b, e, node):
    if b == e:
        segTree[node] = b
        return
    mid = (b + e) // 2
    id10(b, mid, node * 2)
    id10(mid + 1, e, 1 + (node * 2))
    if segTreeData[segTree[node * 2]] > segTreeData[segTree[1 + (node * 2)]]:
        segTree[node] = segTree[1 + (node * 2)]
    else:
        segTree[node] = segTree[2 * node]

def id3(b, e, node, pos, val):
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

def get_max(qStart, qEnd, sStart, sEnd, node):
    if qEnd < sStart or qStart > sEnd:
        return -1
    if sStart >= qStart and sEnd <= qEnd:
        return segTree[node]
    sMid = (sStart + sEnd) // 2
    r1 = get_max(qStart, qEnd, sStart, sMid, 2 * node)
    r2 = get_max(qStart, qEnd, sMid + 1, sEnd, 1 + (2 * node))
    if r1 < 0:
        return r2
    if r2 < 0 or segTreeData[r1] > segTreeData[r2]:
        return r1
    return r2

def id5(qStart, qEnd, sStart, sEnd, node):
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

def id8(b, e, node):
    if b == e:
        sumSegTree[node] = sumSegTreeData[b]
        return
    mid = (b + e) // 2
    id8(b, mid, node * 2)
    id8(mid + 1, e, 1 + node * 2)
    sumSegTree[node] = sumSegTree[node * 2] + sumSegTree[1 + (node * 2)]

def id9(b, e, node, pos, val):
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

def id6(b, e, node, qStart, qEnd):
    if qStart > e or qEnd < b:
        return 0
    if b >= qStart and e <= qEnd:
        return sumSegTree[node]
    mid = (b + e) // 2
    return id6(b, mid, node * 2, qStart, qEnd) + id6(mid + 1, e, 1 + 2 * node, qStart, qEnd)

def id2(a, b):
    c = a // gcd(a, b)
    return b * c

def get_len(num):
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

def main():
    global parent, pwr2, segTree, segTreeData, sumSegTree, sumSegTreeData
    test_cases = 1
    pwr2 = [0] * 100
    parent = list(range(1010))
    segTree = [0] * 600005
    segTreeData = [0] * 100005
    sumSegTree = [0] * 600005
    sumSegTreeData = [0] * 100005

    id11(100)

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
            print(remaining // n + bamboo[n - 1])
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
