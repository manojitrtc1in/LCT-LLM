import sys
import math
from collections import deque

class Node:
    def __init__(self):
        self.lp = None
        self.rp = None
        self.sum = 0
        self.minVal = 0
        self.s = 0
        self.free = 0

    def update(self, tl, tr):
        assert self.lp or self.rp
        if not self.lp:
            self.sum = self.rp.sum
            self.minVal = self.rp.minVal
            self.s = self.rp.s
            self.free = self.rp.free
            self.free += tl
            return
        if not self.rp:
            self.sum = self.lp.sum
            self.minVal = self.lp.minVal
            self.s = self.lp.s
            self.free = self.lp.free
            self.sum += self.lp.s * tr
            self.minVal = min(self.minVal, self.sum)
            return
        self.sum = self.lp.sum + self.rp.free * self.lp.s + self.rp.sum
        self.minVal = min(self.lp.minVal, self.lp.sum + self.rp.free * self.lp.s + self.rp.minVal)
        self.s = self.rp.s
        self.free = self.lp.free

nodes = [Node() for _ in range(101010 * 32)]
lastn = 0
root = None

def update(cur, l, r, pos, val):
    global lastn
    if cur is None:
        cur = nodes[lastn]
        lastn += 1
    if l == r:
        cur.s = val
        cur.free = 0
        cur.minVal = min(0, cur.s)
        cur.sum = val
    else:
        m = (l + r) // 2
        if pos <= m:
            update(cur.lp, l, m, pos, val)
        else:
            update(cur.rp, m + 1, r, pos, val)
        cur.update(m - l + 1, r - m)

def delete(cur, l, r, pos):
    if l == r:
        cur = None
    else:
        m = (l + r) // 2
        if pos <= m:
            delete(cur.lp, l, m, pos)
        else:
            delete(cur.rp, m + 1, r, pos)
        if cur.lp is None and cur.rp is None:
            cur = None
            return
        cur.update(m - l + 1, r - m)

ans = 1e20

def getAns(cur, l, r, x, y, v, s):
    global ans
    if y < l:
        return
    if x > r:
        return

    if cur is None or l == r:
        if cur:
            s = cur.s
        tot = s * (y - x + 1)
        if tot + v > 0:
            v += tot
            return
        ans = x + v / -s
        v = 0
        return

    m = (l + r) // 2
    if x <= l and r <= y:
        minVal = cur.minVal + cur.free * s
        if minVal + v > 0:
            v += cur.sum + cur.free * s
            s = cur.s
            return
        else:
            getAns(cur.lp, l, m, x, m, v, s)
            if v == 0:
                return
            getAns(cur.rp, m + 1, r, m + 1, y, v, s)
            return

    if x <= m:
        getAns(cur.lp, l, m, x, min(y, m), v, s)
        if v == 0:
            return
    getAns(cur.rp, m + 1, r, max(x, m + 1), y, v, s)

def readInt():
    return int(sys.stdin.readline().strip())

def solve():
    global root, ans
    q = readInt()
    for _ in range(q):
        t = readInt()
        if t == 1:
            w = readInt()
            s = readInt()
            update(root, 0, INF, w, s)
        elif t == 2:
            w = readInt()
            delete(root, 0, INF, w)
        else:
            l = readInt()
            r = readInt()
            v = readInt()
            ans = 1e20
            if v == 0:
                ans = l
            if l < r and v:
                s = 0
                getAns(root, 0, INF, l, r - 1, v, s)
            if v:
                print(-1)
            else:
                print(f"{ans:.8f}")

INF = 1011111111

if __name__ == "__main__":
    solve()
